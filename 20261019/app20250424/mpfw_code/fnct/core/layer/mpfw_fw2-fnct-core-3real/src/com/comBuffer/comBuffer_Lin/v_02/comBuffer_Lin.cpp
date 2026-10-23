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

#include "comBuffer_Lin.h"

namespace fw2 { namespace fnct { namespace core	{

    // **************************
    // constructor
    comBuffer_Lin_t::comBuffer_Lin_t (hwComChIntfc_t* p_channel, comProtocolInterface_t* p_proto)  :
         g_channel          {p_channel}
        ,g_proto            {p_proto}
        ,g_state            {k_state_t::free}
        ,g_error            {kSysError_t::none}
        ,g_debug            {0}
    {}

    // **************************
    // high level


        int16_t comBuffer_Lin_t::send           (uint8_t* p_buffPtr)	{
            return tx_packetSent           (p_buffPtr, COM_BUFFER_MAX_SIZE);
        }

        uint8_t*    comBuffer_Lin_t::rxBuff_getPtr       (void)       {
            return g_rxBuff;
        }

        uint8_t*    comBuffer_Lin_t::rxBuff_getPtrCleaned        (void)  {
            return  g_rxBuff + getBufferFirstDirtyBytes();
        }

        uint8_t     comBuffer_Lin_t::rxBuff_getLenghtCleaned     (void)  {
            return  getBufferLengthCleaned();
        }

        uint8_t     comBuffer_Lin_t::rx_packetCheck   (void)      {
            return rx_packetReceived(g_rxBuff, COM_BUFFER_MAX_SIZE) ? getBufferLength() : 0;
        }

    // **************************
    // general

        bool    comBuffer_Lin_t::initBuffer               (uint8_t* p_buffPtr, size_t p_buffSize)  {
            return g_proto->checkBuffer(p_buffPtr, p_buffSize) > 0;
        }

        uint16_t    comBuffer_Lin_t::getBufferLength          (void)  {
            return g_proto->get_length();
        }

        uint16_t comBuffer_Lin_t::getBufferLengthCleaned              (void)      {
            return g_proto->get_lengthCleaned();
        }

        uint8_t comBuffer_Lin_t::getBufferFirstDirtyBytes            (void)       {
            return  g_proto->get_firstDirtyBytes();
        }

        void        comBuffer_Lin_t::setBufferStatusFree      (void)  {
            g_state = k_state_t::free;
        }

        bool        comBuffer_Lin_t::getBufferStatusFree      (void)  {
            return (k_state_t::free == g_state);
        }


    // **************************
    // receiver

        bool comBuffer_Lin_t::rx_packetReceived  (uint8_t* p_buffPtr, size_t p_buffSize)  {
            bool l_result = false;
            switch (g_state)    {
                case k_state_t::free:
                    g_proto->reset(p_buffPtr, p_buffSize);
                    g_state = k_state_t::rx_waiting_packet;
                    // 1. set  rx-enable pin
                    // 2. enable rx interrupt
                    g_channel->rx_eventBegin();
                    break;
                case k_state_t::rx_completed:
                    l_result = true;
                    break;
                default:
                    break;
            }

            return l_result;
        }

        void comBuffer_Lin_t::rx_interrupt_buffer_management(void)	{

            switch (g_state)    {
                int32_t l_length;
                uint8_t c;
                case k_state_t::rx_waiting_packet:
                	if(!g_stateLock.test_and_set(std::memory_order_acquire))    {
                        // the g_state parameter is locked
                        g_state = k_state_t::rx_running;
                        // release g_state parameter
                        g_stateLock.clear(std::memory_order_release);

                    } else {
                        // there is a conflict line
                        g_state = k_state_t::rx_error;
                        g_error = rx_conflict_line;
                        break;
                    }
                case k_state_t::rx_running:
                    // check "overrun error"
                    if(g_channel->rx_chkError_overrun())    {
                        g_state = k_state_t::rx_error;
                        g_error = rx_overrun;
                    } else {
                		c = g_channel->rx_eventReceiveData();

                        g_proto->setData(c);
                        l_length = g_proto->update();
                        if(l_length > 0) {
                            g_state = k_state_t::rx_completed;
                        }
                        if(l_length < 0) {
                            g_state = k_state_t::rx_error;
                            g_error = rx_protocol_error;
                        }
                    }
                    if(k_state_t::rx_running != g_state)
                            g_channel->rx_eventEnd();
                    break;
                default:
                    break;
            }


        }

        bool comBuffer_Lin_t::rx_chkError              (void)  {
            return k_state_t::rx_error == g_state;
        }

    // **************************
    // transmitter

        bool comBuffer_Lin_t::tx_stringSent           (char* p_string)	{
            int16_t l_buffSize = 0;
            // check a) end character & b) no-ascii characters
            for(uint16_t pos = 0; pos < COM_BUFFER_MAX_SIZE; pos++) {

                // a) check end character
                if(0 == p_string[pos]) {
                    l_buffSize = pos+1;
                    break;
                }

                // b) check no-ascii characters
                if(
                        (0x20 > p_string[pos])
                    ||  (0x7E < p_string[pos]) 
                ) {
                    g_error = tx_bad_string;
                    break;
                }
            }

            if(l_buffSize)  {
                tx_packetSent(reinterpret_cast<uint8_t*>(p_string), l_buffSize);
            } else {
                g_error = (kSysError_t::none == g_error) ? tx_overflow_string : kSysError_t::none;
            }

            return (0 < l_buffSize);
        }

        int16_t comBuffer_Lin_t::tx_packetSent           (uint8_t* p_buffPtr, size_t p_buffSize)	{
            int16_t l_buffLength = 0;
            switch (g_state)    {
                case k_state_t::rx_waiting_packet:
                	if(!g_stateLock.test_and_set(std::memory_order_acquire))    {
                        // the g_state parameter is locked

                        g_state = k_state_t::free;
                        // release g_state parameter
                        g_stateLock.clear(std::memory_order_release);
                    } else {
                        // the rx interrupt routine has locked the resource, therefore ...

                        // do nothing to avoid a conflict line
                        g_state = k_state_t::tx_error;
                        g_error = tx_avoid_conflict_line;
                        break;
                    }
                case k_state_t::free:
                    l_buffLength = g_proto->checkBuffer(p_buffPtr, p_buffSize);
                    if( l_buffLength > 0)    {
                        g_proto->reset(p_buffPtr, p_buffSize);

                        // update the state
                        g_state = k_state_t::tx_init;

                        // case "virtual"
                        //      . do nothing
                        // case "real"
                        //      1. enable tx interrupt
                        //      2. set tx-enable pin (automatically clear rx-enable pin)
                        g_channel->tx_eventBegin();

                    } else {
                        // tx error management
                        g_state = k_state_t::tx_error;
                        g_error = tx_protocol_error;
                    }
                    break;
                default:
                    break;
            }
            return l_buffLength;
        }

        void comBuffer_Lin_t::tx_interrupt_buffer_management(void)	{
            switch (g_state)    {
                int32_t l_length;
                uint8_t c;
                case k_state_t::tx_init:
                    // tx interrupt raised because the first byte has to be sent 
                    // 1. update buffer state
                    g_state = k_state_t::tx_running;
                    // enable channel
                    //  2.a. "virtual" case                     -> set [writerPid] parameter
                    //  2.b. "real" case (rs485 half-duplex)    -> set tx-enable pin
                    g_channel->tx_eventFirstData();
                    // continue to perform "tx_running" state too
                case k_state_t::tx_running:
                    g_debug++;
                    // tx interrupt raised because one byte has to be sent 
            		c = g_proto->getData();
            		g_channel->tx_eventSendData(c);
                    l_length = g_proto->update();
                    // check last byte or error state
                    if(l_length > 0) {
                        // last byte has just been sent, 
                        // 1. update the state
                        g_state = k_state_t::tx_waiting_last_byte_send;
                        // 2. the tx interrupt has to be configured to raise when the last byte is phisically and completely sent
                        g_channel->tx_eventLastData();
                    }
                    if(l_length < 0) {
                        // an error occur in parsing packet
                        // disable tx interrupt; clr enable_tx pin / set enable_rx pin
                        g_channel->tx_eventEnd();
                        g_state = k_state_t::tx_error;
                    }
                    break;
                case k_state_t::tx_waiting_last_byte_send:
                    // last byte is phisically and completely sent, therefore ...
                    // disable tx interrupt; clr enable_tx pin / set enable_rx pin
                    g_channel->tx_eventEnd();
                    g_state = k_state_t::free;
                    break;
                default:
                    break;
            }

        }

        bool comBuffer_Lin_t::tx_chkError              (void)  {
            return k_state_t::tx_error == g_state;
        }


    // **************************
    // error
        kSysError_t comBuffer_Lin_t::getError                 (void)  {
            return g_error;
        }

        kSysError_t comBuffer_Lin_t::getError                 (encSysErrorGroup_t p_groupError)  {
            kSysError_t l_return = kSysError_t::none;
            switch  (p_groupError)  {
                case encSysErrorGroup_t::comProtocolStatus:
                    l_return = g_proto->getError();
                    break;
                case encSysErrorGroup_t::comBuffer_Lin:
                    l_return = g_error;
                    break;
                default:
                    break;
            }
            return l_return;
        }

        char comBuffer_Lin_t::getErrorDetails                 (encSysErrorGroup_t p_groupError)  {
            char l_return = '-';
            switch  (p_groupError)  {
                case encSysErrorGroup_t::comProtocolStatus:
                    l_return = g_proto->getErrorDetails();
                    break;
                default:
                    break;
            }
            return l_return;
        }


} } }   // fw2::fnct::core
