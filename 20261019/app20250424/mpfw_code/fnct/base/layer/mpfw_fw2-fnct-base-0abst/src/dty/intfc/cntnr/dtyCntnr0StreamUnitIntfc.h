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
 * dtyCntnr0StreamUnitIntfc.h
 *
 *  Created on: Mar, 24th 2025 (Mon)
 *      Author: Marco Dau
 */
 
#ifndef DTY_CNTR_0_STREAM_UNIT_INTFC_H
#define DTY_CNTR_0_STREAM_UNIT_INTFC_H

#include "dtyTypesDefs.h"
using namespace dtyTypesDefs_t; 

class dtyCntnr0StreamUnitIntfc_t   {
// ****************************************************
// section start **** CONSTRUCTOR *****
    public:
        // dtyCntnr0StreamUnitIntfc_t   (dtyIntfcAbstractUnitGraphic_t** p_array);

    // section end   **** CONSTRUCTOR ***** 
    // ****************************************************
    // --------------------------
// ****************************************************
// section start **** STRUCT & DATA STREAM MANAGEMENT: READ/WRITE *****

    // sub-section ** READ **
        public:
            virtual void        init                                (void)                  {};

            virtual uint32_t    getBlockHeaderIdPrev                (uint32_t p_idHeader)   = 0;
            virtual uint32_t    getBlockHeaderIdNext                (uint32_t p_idHeader)   = 0;
            virtual uint32_t    getBlockHeaderIdLast                (void)                  = 0;
            virtual bool        chkBlockHeaderId                    (uint32_t p_idHeader)   = 0;

            virtual uint32_t    getBlockDataId                      (uint32_t p_idHeader)   = 0;
            virtual uint16_t    getBlockDataSize                    (uint32_t p_idHeader)   = 0;
            virtual kMarker_t   getBlockDataMarker                  ([[maybe_unused]] uint32_t p_idHeader)   {return kMarker_t::defaultX;};
            virtual char*       getBlockDataPtrAsciiDataBuffer      ([[maybe_unused]] uint32_t p_idHeader)   {return nullptr;};
            virtual uint32_t    getBlockDataValueDataBuffer         ([[maybe_unused]] uint32_t p_idHeader)   {return 0;};

            virtual void*       getPtrData                          ([[maybe_unused]] uint32_t p_idHeader)   {return nullptr;};
            virtual void*       getPtrDataInfo                      ([[maybe_unused]] uint32_t p_idHeader)   {return nullptr;};

    // sub-section ** WRITE **
        public:
            virtual void        add             ([[maybe_unused]] void* p_pBufIn, [[maybe_unused]] uint32_t p_bufInSize)                                            {};
            virtual void        add             ([[maybe_unused]] void* p_pBufIn, [[maybe_unused]] uint32_t p_bufInSize, [[maybe_unused]] void* p_infoDataBlock)    {};
            virtual void        add             ([[maybe_unused]] uint8_t* p_pBufIn, [[maybe_unused]] uint16_t p_bufInSize)                                             {};
            virtual void        add             ([[maybe_unused]] uint8_t* p_pBufIn, [[maybe_unused]] uint16_t p_bufInSize, [[maybe_unused]] kMarker_t p_marker, [[maybe_unused]] kDataType_t p_dataType) {};

        private:
            virtual uint32_t    getWriteHeaderIdNext            ([[maybe_unused]] uint32_t p_idHeader) {return 0;};

    // section end   **** STRUCT & DATA STREAM MANAGEMENT: READ/WRITE ***** 
    // ****************************************************
    // --------------------------

};

#endif 	// DTY_CNTR_0_STREAM_UNIT_INTFC_H
