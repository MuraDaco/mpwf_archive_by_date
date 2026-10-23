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
 * dtyCntnr1StreamUnitStringV1.h
 *
 *  Created on: Mar, 24th 2025 (Mon)
 *      Author: Marco Dau
 */
 
#ifndef DTY_CNTR_1_STREAM_UNIT_XXX_H
#define DTY_CNTR_1_STREAM_UNIT_XXX_H

#include "dtyCntnr0StreamUnitIntfc.h"

#include "dtyString.h"

class dtyCntnr1StreamUnitStringV1_t: public dtyCntnr0StreamUnitIntfc_t  {
// ****************************************************
// section start **** CONSTRUCTOR *****
    public:
        dtyCntnr1StreamUnitStringV1_t   (void* p_pBufIn, uint32_t p_bufInSize);
        dtyCntnr1StreamUnitStringV1_t   (void* p_pBufIn, uint32_t p_bufInSize, dtyBuffer_t* p_pArrayBufIn, uint16_t p_arrayBufInSize   );
    // section end   **** CONSTRUCTOR ***** 
    // ****************************************************
    // --------------------------
// ****************************************************
// section start **** STRUCT & DATA STREAM MANAGEMENT: READ/WRITE *****

    // sub-section ** READ **
    private:
        uint32_t    getBlockHeaderIdPrev            (uint32_t p_idHeader) override;
        uint32_t    getBlockHeaderIdNext            (uint32_t p_idHeader) override;
        uint32_t    getBlockHeaderIdLast            (void)                override;
        bool        chkBlockHeaderId                (uint32_t p_idHeader) override;

        uint32_t    getBlockDataId                  (uint32_t p_idHeader) override;
        uint16_t    getBlockDataSize                (uint32_t p_idHeader) override;
        kMarker_t   getBlockDataMarker              (uint32_t p_idHeader) override;
        char*       getBlockDataPtrAsciiDataBuffer  (uint32_t p_idHeader) override;

        void*       getPtrData                      (uint32_t p_idHeader)   override;
        void*       getPtrDataInfo                  (uint32_t p_idHeader)   override;


    // sub-section ** WRITE **
    public:
        // void        add                             (void* p_pBufIn, uint32_t p_bufInSize)                          override ;
        // void        add                             (void* p_pBufIn, uint32_t p_bufInSize, void* p_infoDataBlock)   override ;
        void        add             (uint8_t* p_pBufIn, uint16_t p_bufInSize)                                             override;
        void        add             (uint8_t* p_pBufIn, uint16_t p_bufInSize, kMarker_t p_marker, kDataType_t p_dataType) override;


    private:
        uint32_t    getWriteHeaderIdNext            (uint32_t p_idHeader)   override;

        uint8_t*    g_pBuf;
        uint32_t    g_bufSize;
        // char       g_dataString[100];

        uint32_t g_writeHeaderIdCurrent;
        uint32_t g_writeDataIdCurrent;

        dtyString_t                     g_loopPString;
        dtyStringInfo_t                 g_loopPStringInfo;
        // kMarker_t   g_loopMarker;       // it can be defined as static; it is a temporary variable


    // section end   **** STRUCT & DATA STREAM MANAGEMENT: READ/WRITE ***** 
    // ****************************************************
    // --------------------------

};


#endif 	// DTY_CNTR_1_STREAM_UNIT_XXX_H
