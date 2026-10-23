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
 * comProtocolInterface.h
 *
 *  Created on: Feb, 11 2026 (Wed)
 *      Author: Marco Dau
 */

#ifndef     COM_PROTOCOL_INTERFACE_H
#define     COM_PROTOCOL_INTERFACE_H

#include <cstddef>
#include <cstdint>

namespace fw2 { namespace fnct { namespace base	{



class comProtocolInterface_t {

    public:

        virtual void        init                    (void)                                      = 0;
        virtual void        reset                   (uint8_t* p_buffPtr, size_t p_buffSize)     = 0;
        virtual void        reset                   (void)                                      = 0;
        virtual int32_t     checkBuffer             (uint8_t* p_buffPtr, size_t p_buffSize)     = 0;
        virtual uint16_t    get_length              (void)                                      = 0;
        virtual uint16_t    get_lengthCleaned       (void)                                      = 0;
        virtual uint8_t     get_firstDirtyBytes     (void)                                      = 0;
        virtual void        set_length              (uint16_t p_length)                         = 0;
        virtual void        set_ending_character    (uint8_t p_ending_char)                     = 0;
        virtual uint8_t     getData                 (void)                                      = 0;
        virtual void        setData                 (uint8_t p_value)                           = 0;
        virtual int16_t     update                  (void)                                      = 0;
        virtual size_t      getBuff                 (uint8_t** p_pbuffPtr)                      = 0;
        virtual kSysError_t getError                (void)                                      = 0;
        virtual char        getErrorDetails         (void)                                      = 0;



    protected:
        uint8_t*    g_buffPtr;
        size_t      g_buffSize;
        uint16_t    g_length;
        uint8_t     g_txFirstDirtyByteCounter;
        uint8_t     g_rxFirstDirtyByteCounter;
        uint8_t     g_ending_char;
        uint16_t    g_dataCounter;

    

};

} } }   // fw2::fnct::base

#endif  //  COM_PROTOCOL_INTERFACE_H