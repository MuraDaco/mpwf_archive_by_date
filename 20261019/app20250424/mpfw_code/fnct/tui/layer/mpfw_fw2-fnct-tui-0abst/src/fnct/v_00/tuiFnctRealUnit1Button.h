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
 * tuiFnctRealUnit1Button.h
 *
 *  Created on: Jan, 31st 2025 (Fri)
 *      Author: Marco Dau
 */
 
#ifndef TUI_FNCT_REAL_UNIT_1_BUTTON_H
#define TUI_FNCT_REAL_UNIT_1_BUTTON_H


#include "tuiFnctAbstUnit0.h"

#include "dtyIntfcAbstractUnitGraphic.h"
#include "dtyTypesDefs.h"
using namespace dtyTypesDefs_t; 

class tuiFnctRealUnit1Button_t :    public tuiFnctAbstUnit0_t {

// ****************************************************
// section start **** CONSTRUCTOR *****

    public:
    tuiFnctRealUnit1Button_t       (const char* p_strName  ,func_t p_func   );
    tuiFnctRealUnit1Button_t       (const char* p_strName  ,tuiFnctAbstUnit0_t* p_pFuncOwner ,tuiUnitFunc_t p_func   );

    // section end   **** CONSTRUCTOR *****
    // ****************************************************
    // --------------------------
// ****************************************************
// section start **** PROCESS MANAGEMENT *****

    protected:
        bool init   	            (dtyIntfcAbstractUnitGraphic_t* p_this) override;

    // section end   **** PROCESS MANAGEMENT *****
    // ****************************************************
    // --------------------------
// ****************************************************
// section start **** DISPLAY *****

    protected:
        void clear                  (dtyIntfcAbstractUnitGraphic_t* p_this) override;
        void display                (dtyIntfcAbstractUnitGraphic_t* p_this) override;
        void display                (dtyIntfcAbstractUnitGraphic_t* p_this, bool p_recursively) override;

    // section end   **** DISPLAY *****
    // ****************************************************
    // --------------------------
// ****************************************************
// section start **** STATE MANAGEMENT *****

    protected:
        bool select     	        (dtyIntfcAbstractUnitGraphic_t* p_this) override;
        bool deSelect   	        (dtyIntfcAbstractUnitGraphic_t* p_this) override;
        void eventOn    	        (dtyIntfcAbstractUnitGraphic_t* p_this) override;
        bool selectByMouse 	        (dtyIntfcAbstractUnitGraphic_t* p_this) override;

    // section end   **** STATE MANAGEMENT *****
    // ****************************************************
    // --------------------------
// ****************************************************
// section start **** SPECIFIC DATA *****

    private:

    func_t g_func_no_par;
    tuiFnctAbstUnit0_t* g_pFuncOwner;
    tuiUnitFunc_t g_func_par;

    // section end   **** SPECIFIC DATA *****
    // ****************************************************
    // --------------------------



};


#endif 	// TUI_FNCT_REAL_UNIT_1_BUTTON_H
