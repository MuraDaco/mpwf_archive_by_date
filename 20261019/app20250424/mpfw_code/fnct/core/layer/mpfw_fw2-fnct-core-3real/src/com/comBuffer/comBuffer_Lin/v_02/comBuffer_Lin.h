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
 * comBuffer_Lin.h
 *
 *  Created on: Aug, 31st 2026 (Mon)
 *      Author: Marco Dau
 */

#ifndef     COM_BUFFER_LIN_H
#define     COM_BUFFER_LIN_H

#include <cstddef>
#include <cstdint>
#include <atomic>

#include "sysError.h"
#include "comBufferInterface.h"
#include "hwComChIntfc.h"
using namespace fw2::fnct::base::hw;
#include "comProtocolInterface.h"
using namespace fw2::fnct::base;


namespace fw2 { namespace fnct { namespace core	{
    

class comBuffer_Lin_t: public comBufferInterface_t {

    public:
        // constructor
        comBuffer_Lin_t (hwComChIntfc_t* p_channel, comProtocolInterface_t* p_proto);

        // high level
            int16_t     send                                (uint8_t* p_buffPtr)                        override;
            uint8_t*    rxBuff_getPtr                       (void)                                      override;
            uint8_t*    rxBuff_getPtrCleaned                (void)                                      override;
            uint8_t     rxBuff_getLenghtCleaned             (void)                                      override;
            uint8_t     rx_packetCheck                      (void)                                      override;


        // general
            bool        initBuffer                          (uint8_t* p_buffPtr, size_t p_buffSize)     override;
            uint16_t    getBufferLength                     (void)                                      override;
            uint16_t    getBufferLengthCleaned              (void)                                      override;
            uint8_t     getBufferFirstDirtyBytes            (void)                                      override;
            void        setBufferStatusFree                 (void)                                      override;
            bool        getBufferStatusFree                 (void)                                      override;

        // receiver
            void        rx_interrupt_buffer_management      (void)                                      override;
            bool        rx_packetReceived                   (uint8_t* p_buffPtr, size_t p_buffSize)     override;
            bool        rx_chkError                         (void)                                      override;

        // transmitter
            void        tx_interrupt_buffer_management      (void)                                      override;
            bool        tx_stringSent                       (char* p_string)                            override;
            int16_t     tx_packetSent                       (uint8_t* p_buffPtr, size_t p_buffSize)     override;
            bool        tx_chkError                         (void)                                      override;

        // general error
            kSysError_t getError                            (void)                                      override;
            kSysError_t getError                            (encSysErrorGroup_t p_groupError)           override;
            char        getErrorDetails                     (encSysErrorGroup_t p_groupError)           override;


    private:

        enum k_state_t: uint8_t  {

             free     
            ,tx_init   
            ,tx_running        
            ,tx_waiting_last_byte_send   
            ,tx_completed
            ,tx_error
            ,rx_waiting_packet
            ,rx_running
            ,rx_completed
            ,rx_error

        };

        INIT_ERROR_CODE_GROUP(comBuffer_Lin);
        MAKE_ERROR_CODE(tx_avoid_conflict_line  , 1 );
        MAKE_ERROR_CODE(tx_protocol_error       , 2 );
        MAKE_ERROR_CODE(rx_conflict_line        , 3 );
        MAKE_ERROR_CODE(rx_protocol_error       , 4 );
        MAKE_ERROR_CODE(rx_overrun              , 5 );
        MAKE_ERROR_CODE(tx_bad_string           , 6 );
        MAKE_ERROR_CODE(tx_overflow_string      , 7 );
        
        std::atomic_flag        g_stateLock;
        hwComChIntfc_t*         g_channel;
        comProtocolInterface_t* g_proto;

        k_state_t               g_state;
        kSysError_t             g_error;

        uint8_t     g_debug;

        uint8_t g_rxBuff[COM_BUFFER_MAX_SIZE];

};

} } }   // fw2::fnct::core

#endif  //  COM_BUFFER_LIN_H