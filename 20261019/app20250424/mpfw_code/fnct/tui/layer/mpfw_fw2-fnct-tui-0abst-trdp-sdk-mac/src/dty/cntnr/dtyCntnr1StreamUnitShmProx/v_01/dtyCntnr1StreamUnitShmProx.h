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
 * dtyCntnr1StreamUnitShmProx.h
 *
 *  Created on: Mar, 26th 2025 (Wed)
 *      Author: Marco Dau
 */
 
#ifndef DTY_CNTR_1_STREAM_UNIT_SHM_PROX_H
#define DTY_CNTR_1_STREAM_UNIT_SHM_PROX_H

#include "dtyCntnr0StreamUnitIntfc.h"
#include "hw0macData.h"
using namespace hw0macData_ns;

class dtyCntnr1StreamUnitShmProx_t: public dtyCntnr0StreamUnitIntfc_t  {
// ****************************************************
// section start **** CONSTRUCTOR *****
    public:
        dtyCntnr1StreamUnitShmProx_t   (void* p_pBufIn, uint32_t p_bufInSize);

    // section end   **** CONSTRUCTOR ***** 
    // ****************************************************
    // --------------------------
// ****************************************************
// section start **** STRUCT & DATA STREAM MANAGEMENT: READ/WRITE *****

    // sub-section ** READ **
    private:
        void        init                            (void)                override;

        uint32_t    getBlockHeaderIdPrev            (uint32_t p_idHeader) override;
        uint32_t    getBlockHeaderIdNext            (uint32_t p_idHeader) override;
        uint32_t    getBlockHeaderIdLast            (void)                override;
        bool        chkBlockHeaderId                (uint32_t p_idHeader) override;

        uint32_t    getBlockDataId                  (uint32_t p_idHeader) override;
        uint16_t    getBlockDataSize                (uint32_t p_idHeader) override;
        uint32_t    getBlockDataValueDataBuffer     (uint32_t p_idHeader) override;

        void*       getPtrData                      (uint32_t p_idHeader) override;

    // sub-section ** WRITE **
    public:


    private:

        shm_process_struct_t*    g_pBuf;
        pProx_Func_t             g_getProxBuf;
        uint32_t                 g_bufSize;
        // char       g_dataString[100];

        // uint32_t g_writeHeaderIdCurrent;
        // uint32_t g_writeDataIdCurrent;


    // section end   **** STRUCT & DATA STREAM MANAGEMENT: READ/WRITE ***** 
    // ****************************************************
    // --------------------------

};


#endif 	// DTY_CNTR_1_STREAM_UNIT_SHM_PROX_H
