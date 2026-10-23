//  *******************************************************************************
//  
//  mpfw / fw2 - Multi Platform FirmWare FrameWork
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
 * dtyCntnr1StreamUnitShmProx.cpp
 *
 *  Created on: Mar, 26th 2025 (Wed)
 *      Author: Marco Dau
 */

// debug 
#include "dtyCntnr1StreamUnitShmProx.h"

// ****************************************************
// section start **** CONSTRUCTOR *****

    #define DB_HEADER_UNDEFINED         0xFFFFFFFF

    dtyCntnr1StreamUnitShmProx_t::dtyCntnr1StreamUnitShmProx_t   (void* p_pBufIn, uint32_t p_bufInSize) :
         g_getProxBuf                   {reinterpret_cast<pProx_Func_t>(p_pBufIn)           }
        ,g_bufSize                      {p_bufInSize        }
        // ,g_writeHeaderIdCurrent         {0                  }
        // ,g_writeDataIdCurrent           {p_bufInSize        }
    {}

    // section end   **** CONSTRUCTOR ***** 
    // ****************************************************
    // --------------------------
// ****************************************************
// section start **** STRUCT & DATA STREAM MANAGEMENT: READ/WRITE *****

    void    dtyCntnr1StreamUnitShmProx_t::init                (void)    {
        g_pBuf = g_getProxBuf();
    }

    // READ section
    // private:
    // uint32_t    getBlockHeaderIdPrev        (uint32_t p_idHeader);
    uint32_t dtyCntnr1StreamUnitShmProx_t::getBlockHeaderIdPrev    (uint32_t p_idHeader)  {                            
        return (0 < p_idHeader) ? (p_idHeader - 1) : 0;
    }

    // uint32_t    getBlockHeaderIdNext        (uint32_t p_idHeader);
    uint32_t dtyCntnr1StreamUnitShmProx_t::getBlockHeaderIdNext    (uint32_t p_idHeader)  {         
        return ((p_idHeader + 1) < g_bufSize) ? (p_idHeader + 1) : p_idHeader;
    }

    // uint32_t    getBlockDataId                  (uint32_t p_idHeader);
    uint32_t dtyCntnr1StreamUnitShmProx_t::getBlockDataId  (uint32_t p_idHeader) {                           
        return p_idHeader;
    }


    // uint16_t    getBlockDataSize                (uint32_t p_idHeader);
    uint16_t dtyCntnr1StreamUnitShmProx_t::getBlockDataSize   ([[maybe_unused]] uint32_t p_idHeader) {                              
        return 1;
    }

    uint32_t   dtyCntnr1StreamUnitShmProx_t::getBlockDataValueDataBuffer           (uint32_t p_idHeader)     {
        g_pBuf = g_getProxBuf();
        return g_pBuf[p_idHeader].pid;
    }

    void*      dtyCntnr1StreamUnitShmProx_t::getPtrData                      (uint32_t p_idHeader)  {
        g_pBuf = g_getProxBuf();
        return &(g_pBuf[p_idHeader].pid);
    }

    bool    dtyCntnr1StreamUnitShmProx_t::chkBlockHeaderId                     (uint32_t p_idHeader)   {
        return (g_bufSize != p_idHeader);
    }

    uint32_t    dtyCntnr1StreamUnitShmProx_t::getBlockHeaderIdLast        (void)  {
        return g_bufSize-1;
    }


    // WRITE section

    // public:
    // void        add             (uint8_t* p_pBufIn, uint16_t p_bufInSize)                                             ;
        //    void dtyCntnr1StreamUnitShmProx_t::add         (uint8_t* p_pBufIn, uint16_t p_bufInSize)   {
        //        add(p_pBufIn, p_bufInSize, kMarker_t::defaultX, kDataType_t::binary);
        //    }
        //
        //    // void        add             (uint8_t* p_pBufIn, uint16_t p_bufInSize, kMarker_t p_marker, kDataType_t p_dataType) ;
        //    void dtyCntnr1StreamUnitShmProx_t::add         (uint8_t* p_pBufIn, uint16_t p_bufInSize, kMarker_t p_marker, kDataType_t p_dataType)   {
        //
        //        uint8_t* l_pBuf = g_pBuf + g_writeHeaderIdCurrent;
        //        uint16_t l_bufInSize = kDataType_t::ascii == p_dataType ? p_bufInSize : (p_bufInSize << 1);
        //        l_pBuf[HEADER_MARKER_POS]           = p_marker;
        //        l_pBuf[HEADER_MARKER_POS+1]         = p_marker;
        //        l_pBuf[HEADER_DATA_LENGTH_POS]      = l_bufInSize>>8;
        //        l_pBuf[HEADER_DATA_LENGTH_POS+1]    = static_cast<uint8_t> (l_bufInSize);
        //        l_pBuf[HEADER_INFO_POS]             = 0;
        //        l_pBuf[HEADER_INFO_POS+1]           = 0;
        //        g_writeDataIdCurrent                -= l_bufInSize;
        //        l_pBuf[HEADER_DATA_BEGIN_POS  ]     = g_writeDataIdCurrent>>24;
        //        l_pBuf[HEADER_DATA_BEGIN_POS+1]     = g_writeDataIdCurrent>>16;
        //        l_pBuf[HEADER_DATA_BEGIN_POS+2]     = g_writeDataIdCurrent>>8;
        //        l_pBuf[HEADER_DATA_BEGIN_POS+3]     = g_writeDataIdCurrent;
        //
        //        uint8_t* l_pBufInfo = &l_pBuf[DATA_BLOCK_INFO_POS+1];
        //
        //        // update header block id/pointer
        //        g_writeHeaderIdCurrent = getWriteHeaderIdNext(g_writeHeaderIdCurrent);
        //
        //        // data block
        //
        //        // set buffer pointer
        //        l_pBuf = g_pBuf + g_writeDataIdCurrent;
        //        uint16_t l_cnt = 0;
        //        bool l_binaryData = false;
        //        while(l_cnt < p_bufInSize)    {
        //
        //            switch (p_dataType) {
        //                case kDataType_t::binary:
        //                    l_pBuf[0] = (*p_pBufIn >> 4) & 0x0F; l_pBuf[0] += (l_pBuf[0] < 0x0A ? 0x30 : 0x37);
        //                    l_pBuf[1] = (*p_pBufIn     ) & 0x0F; l_pBuf[1] += (l_pBuf[1] < 0x0A ? 0x30 : 0x37);
        //                    if(!l_binaryData) {
        //                        l_binaryData = ((*p_pBufIn < 0x20) || (0x7e < *p_pBufIn));
        //                        *l_pBufInfo = 1;
        //                    }
        //                    l_pBuf += 2;
        //                    break;
        //                case kDataType_t::ascii:
        //                    *l_pBuf = *p_pBufIn;
        //                    l_pBuf++;
        //                    break;
        //            }
        //
        //            l_cnt++;
        //            p_pBufIn++;
        //        }
        //
        //    }


    // section end   **** STRUCT & DATA STREAM MANAGEMENT: READ/WRITE ***** 
    // ****************************************************
    // --------------------------
