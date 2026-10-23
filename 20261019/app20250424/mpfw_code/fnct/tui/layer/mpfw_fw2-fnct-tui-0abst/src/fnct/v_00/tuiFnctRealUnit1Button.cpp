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
 * tuiFnctRealUnit1Button.cpp
 *
 *  Created on: Jan, 31st 2025 (Fri)
 *      Author: Marco Dau
 */
 

#include "tuiFnctRealUnit1Button.h"



// ****************************************************
// section start **** CONSTRUCTOR *****

    tuiFnctRealUnit1Button_t::tuiFnctRealUnit1Button_t      (const char* p_strName  ,func_t p_func   )   :
         tuiFnctAbstUnit0_t     (p_strName)
        ,g_func_no_par          {p_func}
        ,g_pFuncOwner           {nullptr}
        ,g_func_par             {nullptr}
    {}

    tuiFnctRealUnit1Button_t::tuiFnctRealUnit1Button_t  (const char* p_strName  ,tuiFnctAbstUnit0_t* p_pFuncOwner ,tuiUnitFunc_t p_func   ) :
         tuiFnctAbstUnit0_t     (p_strName)
        ,g_func_no_par          {nullptr}
        ,g_pFuncOwner           {p_pFuncOwner}
        ,g_func_par             {p_func}
    {}

    // section end   **** CONSTRUCTOR *****
    // ****************************************************
    // --------------------------
// ****************************************************
// section start **** PROCESS MANAGEMENT *****

    bool tuiFnctRealUnit1Button_t::init   	            (dtyIntfcAbstractUnitGraphic_t* p_this)  {
        p_this->setEventStatus(false);
        return true;
    }
    
    // section end   **** PROCESS MANAGEMENT *****
    // ****************************************************
    // --------------------------
// ****************************************************
// section start **** DISPLAY *****

    void tuiFnctRealUnit1Button_t::clear     	        (dtyIntfcAbstractUnitGraphic_t* p_this)  {
        p_this->frameClear();
    }

    void tuiFnctRealUnit1Button_t::display     	    (dtyIntfcAbstractUnitGraphic_t* p_this)  {
        p_this->nameOnly(g_strName);
    }

    void tuiFnctRealUnit1Button_t::display     	    (dtyIntfcAbstractUnitGraphic_t* p_this, [[maybe_unused]] bool p_recursively)  {
        display(p_this);
    }

    // section end   **** DISPLAY *****
    // ****************************************************
    // --------------------------
// ****************************************************
// section start **** STATE MANAGEMENT *****

    // protected:
    bool tuiFnctRealUnit1Button_t::select     	        (dtyIntfcAbstractUnitGraphic_t* p_this)  {
        p_this->nameOnly(tuiState_t::select, g_strName);
        return true;
    }

    bool tuiFnctRealUnit1Button_t::deSelect   	        ([[maybe_unused]] dtyIntfcAbstractUnitGraphic_t* p_this)  {
        p_this->nameOnly(tuiState_t::deselect, g_strName);
        return true;
    }

    void tuiFnctRealUnit1Button_t::eventOn    	        ([[maybe_unused]] dtyIntfcAbstractUnitGraphic_t* p_this)  {
        if(g_func_no_par) g_func_no_par();
        if(g_pFuncOwner) if(g_func_par) g_func_par(g_pFuncOwner);
    }

    bool tuiFnctRealUnit1Button_t::selectByMouse          ([[maybe_unused]] dtyIntfcAbstractUnitGraphic_t* p_this)  {
        //p_this->deselectBackNeventOn();
        p_this->deselectBackNselect();
        p_this->parentDeselectBackNeventOn();
        eventOn(p_this);

        return true;
    }

    // section end   **** STATE MANAGEMENT *****
    // ****************************************************
    // --------------------------

// ****************************************************

