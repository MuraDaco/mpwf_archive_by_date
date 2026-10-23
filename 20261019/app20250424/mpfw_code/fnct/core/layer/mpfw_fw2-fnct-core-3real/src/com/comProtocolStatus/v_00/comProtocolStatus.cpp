//  *******************************************************************************
//  
//  mpfw / fw2 - Multi Platform FirmWare FrameWork 
//      library that contains the essential code that is used in every application
//  Copyright (C) (2023) Marco Dau
//  
//  This program is free software: you can redistribute it and/or modify
//  it under the terms of the GNU Affero General Public License as published
//  by the Free Software Foundation, either version 3 of the License, or
//  (at your option) any later version.
//  
//  This program is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//  GNU Affero General Public License for more details.
//  
//  You should have received a copy of the GNU Affero General Public License
//  along with this program.  If not, see <https://www.gnu.org/licenses/>.
//  
//  You can contact me by the following email address
//  marco <d o t> ing <d o t> dau <a t> gmail <d o t> com
//  
//  *******************************************************************************
/*
 * comProtocolStatus.cpp
 *
 *  Created on: Feb, 1st 2026 (Sun)
 *      Author: Marco Dau
 */

#include "comProtocolStatus.h"

#include "comProtocolStatus_dbgSetup.h"

#define FIRST_DIRTY_BYTE_NUM    30
#define DIRTY_BYTE              0xAA

namespace fw2 { namespace fnct { namespace core	{


    comProtocolStatus_t::comProtocolStatus_t (void)  :
         g_state                        {k_state_t::waiting_header}
        ,g_error                        {kSysError_t::none}
    {}


    void comProtocolStatus_t::init      (void)  {

    }

    void comProtocolStatus_t::reset     (void)      {
        g_length        = 0;
        g_txFirstDirtyByteCounter = g_rxFirstDirtyByteCounter = 0;
        g_ending_char   = 0;
        g_dataCounter   = 0;
        g_state         = k_state_t::waiting_header;
        g_error         = kSysError_t::none;
        
    }

    void comProtocolStatus_t::reset     (uint8_t* p_buffPtr, size_t p_buffSize)   {
        // reset buffer pointer & size
        g_buffPtr   = p_buffPtr;
        g_buffSize  = p_buffSize;

        reset();
    }

    int32_t comProtocolStatus_t::checkBuffer     (uint8_t* p_buffPtr, size_t p_buffSize)   {
        int32_t l_result;
        reset(p_buffPtr, p_buffSize);

        // check tx packet format 
        do {
            l_result = update();
        } while (0 == l_result);

        return l_result;
    }

    uint16_t comProtocolStatus_t::get_length     (void)   {
        return g_length;
    }

    uint16_t comProtocolStatus_t::get_lengthCleaned       (void)        {
        return (g_length) ? (g_length - g_rxFirstDirtyByteCounter) : 0;
    }

    uint8_t comProtocolStatus_t::get_firstDirtyBytes     (void)     {
        return g_rxFirstDirtyByteCounter;
    }


    void comProtocolStatus_t::set_length          (uint16_t p_length)     {
        g_length = p_length;
        if(g_buffSize >= g_length)
            // set the next state to ... 
       	    g_state = k_state_t::waiting_packet_end_by_length;
        else
        	// end loop with error: lengh too large
            g_error = length_overflow;    
    }

    void comProtocolStatus_t::set_ending_character   (uint8_t p_ending_char)     {
        g_ending_char = p_ending_char;
        g_state = k_state_t::waiting_packet_end_by_ending_char;
    }

    uint8_t comProtocolStatus_t::getData          (void)     {
        return *g_buffPtr;
    }

    void comProtocolStatus_t::setData          (uint8_t p_value)     {
        *g_buffPtr = p_value;
    }

    int16_t comProtocolStatus_t::update          (void)     {
        if(
                (k_state_t::end     != g_state)
            &&  (kSysError_t::none  == g_error)
            &&  (g_buffSize         > g_dataCounter)
        )   {
            // start the update procedure of the state
            uint8_t l_byteData = *g_buffPtr;
            // if(k_state_t::waiting_header == g_state)    {
                if(g_txFirstDirtyByteCounter)   {
                    g_txFirstDirtyByteCounter--;
                    l_byteData = DIRTY_BYTE;
                } else {
                    g_dataCounter++;
                    g_buffPtr++;
                }
            // }

       		switch (g_state) {
       			case k_state_t::waiting_header:
       				if(k_header_term_t::start == l_byteData) {
                        // set the next state
       					g_state = k_state_t::waiting_coding;
       				} else {
                        if(FIRST_DIRTY_BYTE_NUM <= g_rxFirstDirtyByteCounter) {
          	    			// end loop with error
       			    		g_error = first_byte;
                            g_error_details = l_byteData;
                        } else {
                            g_rxFirstDirtyByteCounter++;
                        }
       				}
       				break;
       			case k_state_t::waiting_coding:
       				if(
       					(k_header_term_t::data_type_binary  == l_byteData) ||
       					(k_header_term_t::data_type_text    == l_byteData)
       				) {
                        // set the next state
       					g_state = k_state_t::waiting_length_info;
       				} else {
        					// end loop with error
       					g_error = coding;
       				}
       				break;
       			case k_state_t::waiting_length_info:
       				if(k_header_term_t::ending_char_setting == l_byteData) {
                        // packet will finish when ending char is received, but before ...
                        // the ending char has to be set therefore ...
                        // set the next state to ... 
       					g_state = k_state_t::waiting_ending_char_to_set;
       				} else {
                        // packet will finish when <length> bytes are received, but before ...
                        // the <length> has to be set, 
                        // now the hundreds figure of length has been received
       					uint8_t l_packet_length_100 = (l_byteData - 0x30);
       					if(10 > l_packet_length_100) {
       						g_length = l_packet_length_100*100;
                            // set the next state to ... 
       						g_state = k_state_t::waiting_length_010_figure;
       					} else {
             				// end loop with error
       					    g_error = length;
       					}
       				}
       				break;
       			case k_state_t::waiting_length_010_figure:  {
                    uint8_t l_packet_length_010 = (l_byteData - 0x30);
       				if (10 > l_packet_length_010) {
       					g_length += l_packet_length_010*10;
                        // set the next state to ... 
       					g_state = k_state_t::waiting_length_001_figure;
       				} else {
      					// end loop with error
   					    g_error = length;
       				}
       				break;
                }
       			case waiting_length_001_figure: {
       				uint8_t l_packet_length_001 = (l_byteData - 0x30);
       				if (10 > l_packet_length_001) {
       					g_length += l_packet_length_001*10 + g_dataCounter;

                        if(g_buffSize >= g_length)
                            // set the next state to ... 
       					    g_state = k_state_t::waiting_packet_end_by_length;
                        else
          					// end loop with error: lengh too large
                            g_error = length_overflow;    
       				} else {
      					// end loop with error
   					    g_error = length;
       				}
       				break;
                       
                }
       			case k_state_t::waiting_packet_end_by_length:   
                    // the length depends on "terminating char"
                    if (g_length == g_dataCounter)
                    {
                        // packet has been fully received, therefore ...

               		    // end loop
                        g_state = k_state_t::end;
                    }
       				break;
       			case k_state_t::waiting_ending_char_to_set:
           			g_state = k_state_t::waiting_packet_end_by_ending_char;
                    g_ending_char = l_byteData;
       				break;
       			case k_state_t::waiting_packet_end_by_ending_char:
                    // the length depends on "terminating char"
                    if (g_ending_char == l_byteData)
                    {
                        // packet has been fully received, therefore ...

                        // set the length
                        g_length = g_dataCounter;

               		    // end loop
                       	g_state = k_state_t::end;
                    }
       				break;
       			default:
       				break;
            }

        }

        // start the check procedure of the status to set the result to return
        int16_t l_result = 0;

        if(k_state_t::end     == g_state)   {
            l_result = g_length;
        } else {
            if(g_buffSize   <= g_dataCounter) {
                g_error = no_ending_char;
                #include "comProtocolStatus_dbgToken_2.h"
            }
            if(kSysError_t::none    != g_error)   {
                l_result = -g_error;
            }
        }


        return l_result;
    }

    size_t  comProtocolStatus_t::getBuff         (uint8_t** p_pBuffPtr)     {
        *p_pBuffPtr   = g_buffPtr;
        return g_buffSize;
    }


    kSysError_t comProtocolStatus_t::getError       (void)      {
        return g_error;
    }

    char comProtocolStatus_t::getErrorDetails       (void)      {
        return g_error_details;
    }


} } }   // fw2::fnct::core
