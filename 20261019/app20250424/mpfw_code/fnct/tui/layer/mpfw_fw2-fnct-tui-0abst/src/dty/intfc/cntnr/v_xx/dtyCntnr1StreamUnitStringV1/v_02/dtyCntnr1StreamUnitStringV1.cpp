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
 * dtyCntnr1StreamUnitStringV1.cpp
 *
 *  Created on: Mar, 24th 2025 (Mon)
 *      Author: Marco Dau
 */

// debug 
#include "dtyCntnr1StreamUnitStringV1.h"


// ****************************************************
// section start **** CONSTRUCTOR *****

    #define DB_HEADER_UNDEFINED         0xFFFFFFFF

    dtyCntnr1StreamUnitStringV1_t::dtyCntnr1StreamUnitStringV1_t   (void* p_pBufIn, uint32_t p_bufInSize) :
         g_pBuf                         {static_cast<uint8_t*>(p_pBufIn)           }
        ,g_bufSize                      {p_bufInSize        }
        ,g_writeHeaderIdCurrent         {0                  }
        ,g_writeDataIdCurrent           {p_bufInSize        }
    {}

    dtyCntnr1StreamUnitStringV1_t::dtyCntnr1StreamUnitStringV1_t   (void* p_pBufIn, uint32_t p_bufInSize, dtyBuffer_t* p_pArrayBufIn, uint16_t p_arrayBufInSize   ) :
         g_pBuf                         {static_cast<uint8_t*>(p_pBufIn)           }
        ,g_bufSize                      {p_bufInSize        }
        ,g_writeHeaderIdCurrent         {0                  }
        ,g_writeDataIdCurrent           {p_bufInSize        }
    {
        uint8_t l_max = p_arrayBufInSize / sizeof(dtyBuffer_t);
        kMarker_t l_marker = kMarker_t::defaultX;
        for(uint8_t l_id=0; l_id < l_max; l_id++)   {
            switch (l_id)   {
                case 0:
                    l_marker = kMarker_t::defaultX;
                    break;
                case 1:
                    l_marker = kMarker_t::deviceRx;
                    break;
                case 2:
                    l_marker = kMarker_t::deviceTx;
                    break;
            };
            add(p_pArrayBufIn[l_id].pBuf, p_pArrayBufIn[l_id].size, l_marker, kDataType_t::binary);
        }
    }

    // section end   **** CONSTRUCTOR ***** 
    // ****************************************************
    // --------------------------
// ****************************************************
// section start **** STRUCT & DATA STREAM MANAGEMENT: READ/WRITE *****

    #define MARKER_START_POS        0   // 2-byte
    #define DATA_LENGTH_POS         2   // 2-byte
    #define DATA_BLOCK_INFO_POS     4   // 2-byte
    #define DATA_BLOCK_END_POS      6   // 4-byte
    #define DATA_START_POS          6
    #define DATA_END___POS          DATA_LENGTH_POS + 1

    #define HEADER_MARKER_POS           0
    #define HEADER_DATA_LENGTH_POS      2
    #define HEADER_INFO_POS             4
    #define HEADER_DATA_BEGIN_POS       6
    #define HEADER_SIZE                 10


    // READ section
    // private:
    // uint32_t    getBlockHeaderIdPrev        (uint32_t p_idHeader);
    uint32_t dtyCntnr1StreamUnitStringV1_t::getBlockHeaderIdPrev    (uint32_t p_idHeader)  {                            
        return (HEADER_SIZE < p_idHeader) ? (p_idHeader - HEADER_SIZE) : 0;
    }

    // uint32_t    getBlockHeaderIdNext        (uint32_t p_idHeader);
    uint32_t dtyCntnr1StreamUnitStringV1_t::getBlockHeaderIdNext    (uint32_t p_idHeader)  {         
        return ((p_idHeader + HEADER_SIZE) < g_writeHeaderIdCurrent) ? p_idHeader + HEADER_SIZE : p_idHeader;
    }

    // uint32_t    getBlockDataId                  (uint32_t p_idHeader);
    uint32_t dtyCntnr1StreamUnitStringV1_t::getBlockDataId  (uint32_t p_idHeader) {                           
        uint32_t l_byteHH = (g_pBuf[p_idHeader+HEADER_DATA_BEGIN_POS  ] << 24) & 0xFF000000;
        uint32_t l_byteH_ = (g_pBuf[p_idHeader+HEADER_DATA_BEGIN_POS+1] << 16) & 0x00FF0000;
        uint32_t l_byteL_ = (g_pBuf[p_idHeader+HEADER_DATA_BEGIN_POS+2] <<  8) & 0x0000FF00;
        uint32_t l_byteLL = (g_pBuf[p_idHeader+HEADER_DATA_BEGIN_POS+3]      ) & 0x000000FF;
        return (l_byteHH + l_byteH_ + l_byteL_ + l_byteLL);
    }


    // uint16_t    getBlockDataSize                (uint32_t p_idHeader);
    uint16_t dtyCntnr1StreamUnitStringV1_t::getBlockDataSize   (uint32_t p_idHeader) {                              
        uint16_t l_byteH = (g_pBuf[p_idHeader+HEADER_DATA_LENGTH_POS  ] <<  8) & 0xFF00;
        uint16_t l_byteL = (g_pBuf[p_idHeader+HEADER_DATA_LENGTH_POS+1]      ) & 0x00FF;
        return (l_byteH + l_byteL);
    }

    // kMarker_t   getBlockDataMarker              (uint32_t p_idHeader);
    kMarker_t dtyCntnr1StreamUnitStringV1_t::getBlockDataMarker  (uint32_t p_idHeader) {                 
        uint16_t l_byteH = (g_pBuf[p_idHeader+HEADER_MARKER_POS  ] <<  8) & 0xFF00;
        uint16_t l_byteL = (g_pBuf[p_idHeader+HEADER_MARKER_POS+1]      ) & 0x00FF;
        return static_cast<kMarker_t> (l_byteH + l_byteL);
    }

    char*   dtyCntnr1StreamUnitStringV1_t::getBlockDataPtrAsciiDataBuffer           ([[maybe_unused]] uint32_t p_idHeader)     {
        return reinterpret_cast<char*>(&g_pBuf[getBlockDataId    (p_idHeader)]);
    }

    bool    dtyCntnr1StreamUnitStringV1_t::chkBlockHeaderId                     (uint32_t p_idHeader)   {
        return (g_writeHeaderIdCurrent != p_idHeader);
    }

    uint32_t    dtyCntnr1StreamUnitStringV1_t::getBlockHeaderIdLast        (void)  {
        return getBlockHeaderIdPrev(g_writeHeaderIdCurrent);
    }


    void*       dtyCntnr1StreamUnitStringV1_t::getPtrData                   (uint32_t p_idHeader)    {
        // g_loopPString.setString(getBlockDataPtrAsciiDataBuffer  (p_idHeader));
        // g_loopPString.setLength(getBlockDataSize                (p_idHeader)+1);
        g_loopPString.setPtrBufferTo(    getBlockDataPtrAsciiDataBuffer  (p_idHeader)
                                        ,getBlockDataSize                (p_idHeader)
                                    );
        return &g_loopPString;
    }

    void*       dtyCntnr1StreamUnitStringV1_t::getPtrDataInfo               (uint32_t p_idHeader)    {
        g_loopPStringInfo.g_marker  = getBlockDataMarker(p_idHeader);
        return &g_loopPStringInfo;
    }


    // WRITE section

    // public:
        // void        add             (uint8_t* p_pBufIn, uint16_t p_bufInSize)                                             ;
        void dtyCntnr1StreamUnitStringV1_t::add         (uint8_t* p_pBufIn, uint16_t p_bufInSize)   {
            add(p_pBufIn, p_bufInSize, kMarker_t::defaultX, kDataType_t::binary);
        }
        
        // void        add             (uint8_t* p_pBufIn, uint16_t p_bufInSize, kMarker_t p_marker, kDataType_t p_dataType) ;
        void dtyCntnr1StreamUnitStringV1_t::add         (uint8_t* p_pBufIn, uint16_t p_bufInSize, kMarker_t p_marker, kDataType_t p_dataType)   {
        
            if(0 == p_bufInSize) return;
            
            uint8_t* l_pBuf = g_pBuf + g_writeHeaderIdCurrent;
            uint16_t l_bufInSize = (kDataType_t::ascii == p_dataType) ? p_bufInSize : (p_bufInSize << 1);
            l_pBuf[HEADER_MARKER_POS]           = p_marker;
            l_pBuf[HEADER_MARKER_POS+1]         = p_marker;
            l_pBuf[HEADER_DATA_LENGTH_POS]      = l_bufInSize>>8;
            l_pBuf[HEADER_DATA_LENGTH_POS+1]    = static_cast<uint8_t> (l_bufInSize);
            l_pBuf[HEADER_INFO_POS]             = 0;
            l_pBuf[HEADER_INFO_POS+1]           = 0;
            g_writeDataIdCurrent                -= l_bufInSize;
            l_pBuf[HEADER_DATA_BEGIN_POS  ]     = g_writeDataIdCurrent>>24;
            l_pBuf[HEADER_DATA_BEGIN_POS+1]     = g_writeDataIdCurrent>>16;
            l_pBuf[HEADER_DATA_BEGIN_POS+2]     = g_writeDataIdCurrent>>8;
            l_pBuf[HEADER_DATA_BEGIN_POS+3]     = g_writeDataIdCurrent;
        
            uint8_t* l_pBufInfo = &l_pBuf[DATA_BLOCK_INFO_POS+1];
        
            // update header block id/pointer
            g_writeHeaderIdCurrent = getWriteHeaderIdNext(g_writeHeaderIdCurrent);
        
            // data block
        
            // set buffer pointer
            l_pBuf = g_pBuf + g_writeDataIdCurrent;
            uint16_t l_cnt = 0;
            bool l_binaryData = false;
            while(l_cnt < p_bufInSize)    {
        
                switch (p_dataType) {
                    case kDataType_t::binary:
                        l_pBuf[0] = (*p_pBufIn >> 4) & 0x0F; l_pBuf[0] += (l_pBuf[0] < 0x0A ? 0x30 : 0x37);
                        l_pBuf[1] = (*p_pBufIn     ) & 0x0F; l_pBuf[1] += (l_pBuf[1] < 0x0A ? 0x30 : 0x37);
                        if(!l_binaryData) {
                            l_binaryData = ((*p_pBufIn < 0x20) || (0x7e < *p_pBufIn));
                            *l_pBufInfo = 1;
                        }
                        l_pBuf += 2;
                        break;
                    case kDataType_t::ascii:
                        *l_pBuf = *p_pBufIn;
                        l_pBuf++;
                        break;
                }
        
                l_cnt++;
                p_pBufIn++;
            }
        
        }

    //private:
    // uint32_t    getWriteHeaderIdNext            (uint32_t p_idHeader);
    uint32_t dtyCntnr1StreamUnitStringV1_t::getWriteHeaderIdNext    (uint32_t p_idHeader)  {         

        return ((p_idHeader + HEADER_SIZE) < g_bufSize) ? p_idHeader + HEADER_SIZE : p_idHeader;
    }



    // section end   **** STRUCT & DATA STREAM MANAGEMENT: READ/WRITE ***** 
    // ****************************************************
    // --------------------------
