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
 * dtyIntfcUiCntnrFnct.h
 *
 *  Created on: Jan, 28th 2025 (Tue)
 *      Author: Marco Dau
 */
 
#ifndef DTY_INTFC_UI_CNTNR_FNCT_H
#define DTY_INTFC_UI_CNTNR_FNCT_H

#include "dtyString.h"

#include "dtyTypesDefs.h"
using namespace dtyTypesDefs_t; 

class dtyIntfcAbstractUnitGraphic_t;

class dtyIntfcUiCntnrFnct_t {

public:

// ****************************************************
// section start **** CHILDREN MANAGEMENT *****

    // to be implemented whether the class has children
    virtual void updCoordNboundsChilds          (void) {};

    // section end   **** CHILDREN MANAGEMENT *****
    // ****************************************************
    // --------------------------
// ****************************************************
// section start **** STREAM CONTAINER DATA BLOCK MANAGEMENT *****

    virtual void cntnrInit           ([[maybe_unused]] dtyString_t* p_pString, [[maybe_unused]] dtyStringInfo_t* p_pStringInfo) {};
    virtual void setValData          ([[maybe_unused]] uint32_t p_pData)    {};
    virtual void setValDataInfo      ([[maybe_unused]] uint32_t p_pDataInfo)    {};
    virtual void setPtrData          ([[maybe_unused]] void* p_pData)    {};
    virtual void setPtrDataInfo      ([[maybe_unused]] void* p_pDataInfo)    {};
    virtual void cntnrUpdParams      ([[maybe_unused]] dtyIntfcAbstractUnitGraphic_t* p_this) {};

    // section end   **** STREAM CONTAINER DATA BLOCK MANAGEMENT *****
    // ****************************************************
    // --------------------------



};

#endif 	// DTY_INTFC_UI_CNTNR_FNCT_H
