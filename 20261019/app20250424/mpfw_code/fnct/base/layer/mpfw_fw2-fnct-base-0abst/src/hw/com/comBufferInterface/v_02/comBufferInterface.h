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
 * comBufferInterface.h
 *
 *  Created on: Feb, 11 2026 (Wed)
 *      Author: Marco Dau
 */

#ifndef     COM_BUFFER_INTERFACE_H
#define     COM_BUFFER_INTERFACE_H

#include <cstddef>
#include <cstdint>

#include "sysError.h"

#define COM_BUFFER_MAX_SIZE 99
namespace fw2 { namespace fnct { namespace base	{



class comBufferInterface_t {

    public:

        // high level
            virtual int16_t     send                        (uint8_t* p_buffPtr)    = 0;
            virtual uint8_t*    rxBuff_getPtr               (void)                  = 0;
            virtual uint8_t*    rxBuff_getPtrCleaned        (void)                  = 0;
            virtual uint8_t     rxBuff_getLenghtCleaned     (void)                  = 0;
            virtual uint8_t     rx_packetCheck              (void)                  = 0;

        // general
            virtual bool        initBuffer                          (uint8_t* p_buffPtr, size_t p_buffSize)     = 0;
            virtual uint16_t    getBufferLength                     (void)                                      = 0;
            virtual uint16_t    getBufferLengthCleaned              (void)                                      = 0;
            virtual uint8_t     getBufferFirstDirtyBytes            (void)                                      = 0;
            virtual void        setBufferStatusFree                 (void)                                      = 0;
            virtual bool        getBufferStatusFree                 (void)                                      = 0;

        // receiver
            virtual void        rx_interrupt_buffer_management      (void)                                      = 0;
            virtual bool        rx_packetReceived                   (uint8_t* p_buffPtr, size_t p_buffSize)     = 0;
            virtual bool        rx_chkError                         (void)                                      = 0;

        // transmitter
            virtual void        tx_interrupt_buffer_management      (void)                                      = 0;
            virtual bool        tx_stringSent                       (char* p_string)                            = 0;
            virtual int16_t     tx_packetSent                       (uint8_t* p_buffPtr, size_t p_buffSize)     = 0;
            virtual bool        tx_chkError                         (void)                                      = 0;

        // general error
            virtual kSysError_t getError                            (void)                                      = 0;
            virtual kSysError_t getError                            (encSysErrorGroup_t p_groupError)           = 0;
            virtual char        getErrorDetails                     (encSysErrorGroup_t p_groupError)           = 0;




};

} } }   // fw2::fnct::base

#endif  //  COM_BUFFER_INTERFACE_H