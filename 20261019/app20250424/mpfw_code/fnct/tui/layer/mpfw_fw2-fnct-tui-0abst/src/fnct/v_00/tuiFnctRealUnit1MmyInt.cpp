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
 * tuiFnctRealUnit1MmyInt.h
 *
 *  Created on: Dec, 26th 2024 (Thu)
 *      Author: Marco Dau
 */
 

#include "tuiFnctRealUnit1MmyInt.h"

// #include <iostream>
// #include <stdexcept>
// 
// ****************************************************
// section start **** CONSTRUCTOR *****

    tuiFnctRealUnit1MmyInt_t::tuiFnctRealUnit1MmyInt_t      (dtyUnit1MmyInt32_t* p_pdtyUnit1MmyInt32   )   :
        tuiFnctAbstUnit0_t           (nullptr)
        ,g_pdtyUnit1MmyInt32             {p_pdtyUnit1MmyInt32}
        ,g_dbgSelect                {false}
    {}

    tuiFnctRealUnit1MmyInt_t::tuiFnctRealUnit1MmyInt_t      (const char* p_strName  ,dtyUnit1MmyInt32_t* p_pdtyUnit1MmyInt32   )   :
        tuiFnctAbstUnit0_t           (p_strName)
        ,g_pdtyUnit1MmyInt32             {p_pdtyUnit1MmyInt32}
        ,g_dbgSelect                {false}
    {}

    // section end   **** CONSTRUCTOR *****
    // ****************************************************
    // --------------------------
// ****************************************************
// section start **** PROCESS MANAGEMENT *****

    bool tuiFnctRealUnit1MmyInt_t::init   	            ([[maybe_unused]] dtyIntfcAbstractUnitGraphic_t* p_this)  {
        p_this->setEventStatus(false);
        return true;
    }

    bool tuiFnctRealUnit1MmyInt_t::initChildren          ([[maybe_unused]] dtyIntfcAbstractUnitGraphic_t* p_this)  {
        return true;
    }

    bool tuiFnctRealUnit1MmyInt_t::loop   	            ([[maybe_unused]] dtyIntfcAbstractUnitGraphic_t* p_this)  {
        return true;
    }

    bool tuiFnctRealUnit1MmyInt_t::loopChildren          ([[maybe_unused]] dtyIntfcAbstractUnitGraphic_t* p_this)  {
        return true;
    }

    void tuiFnctRealUnit1MmyInt_t::end                   ([[maybe_unused]] dtyIntfcAbstractUnitGraphic_t* p_this)  {

    }

    void tuiFnctRealUnit1MmyInt_t::endChildren           ([[maybe_unused]] dtyIntfcAbstractUnitGraphic_t* p_this)  {

    }

    // section end   **** PROCESS MANAGEMENT *****
    // ****************************************************
    // --------------------------
// ****************************************************
// section start **** DISPLAY *****

    void tuiFnctRealUnit1MmyInt_t::clear     	        (dtyIntfcAbstractUnitGraphic_t* p_this)  {
        p_this->frameClear();
    }

    void tuiFnctRealUnit1MmyInt_t::display     	    (dtyIntfcAbstractUnitGraphic_t* p_this)  {
        g_pdtyUnit1MmyInt32->vSelected();
        p_this->nameOnly(g_dbgSelect, g_pdtyUnit1MmyInt32->g_pStringValue);
    }

    void tuiFnctRealUnit1MmyInt_t::display     	    (dtyIntfcAbstractUnitGraphic_t* p_this, [[maybe_unused]] bool p_recursively)  {
        display(p_this);
    }

    void tuiFnctRealUnit1MmyInt_t::displayChildren    ([[maybe_unused]] dtyIntfcAbstractUnitGraphic_t* p_this, [[maybe_unused]] bool p_recursively)  {
    }

    void tuiFnctRealUnit1MmyInt_t::refreshChildren    ([[maybe_unused]] dtyIntfcAbstractUnitGraphic_t* p_this)  {
    }


    // section end   **** DISPLAY *****
    // ****************************************************
    // --------------------------
// ****************************************************
// section start **** STATE MANAGEMENT *****

    void tuiFnctRealUnit1MmyInt_t::selectStateSet       (bool p_selectState)  {
        g_dbgSelect = p_selectState;
    }

    bool tuiFnctRealUnit1MmyInt_t::select     	        (dtyIntfcAbstractUnitGraphic_t* p_this)  {
        // p_this->frameNnameTest(tuiState_t::select, g_strName, g_pdtyUnit1MmyInt32->g_pStringValue);
        g_pdtyUnit1MmyInt32->vSelected();
        p_this->nameOnly(tuiState_t::select, g_pdtyUnit1MmyInt32->g_pStringValue);
        return true;
    }

    bool tuiFnctRealUnit1MmyInt_t::deSelect   	        ([[maybe_unused]] dtyIntfcAbstractUnitGraphic_t* p_this)  {
        // p_this->frameNnameTest(tuiState_t::deselect, g_strName, g_pdtyUnit1MmyInt32->g_pStringValue);
        g_pdtyUnit1MmyInt32->vSelected();
        p_this->nameOnly(tuiState_t::deselect, g_pdtyUnit1MmyInt32->g_pStringValue);
        return true;
    }

    void tuiFnctRealUnit1MmyInt_t::eventOn    	        ([[maybe_unused]] dtyIntfcAbstractUnitGraphic_t* p_this)  {
        // p_this->frameNnameTest(tuiState_t::eventOn, g_strName, g_pdtyUnit1MmyInt32->g_pStringValue);
//                            try { 
//                                throw 10; 
//                            } catch (int i) {
//                                std::cout << " the integer exception was caught, with value: " << i << '\n';
//                                std::exit(i);
//                            }

    }

    bool tuiFnctRealUnit1MmyInt_t::selectByMouse         ([[maybe_unused]] dtyIntfcAbstractUnitGraphic_t* p_this)  {
//                            try { 
//                                throw 11; 
//                            } catch (int i) {
//                                std::cout << " the integer exception was caught, with value: " << i << '\n';
//                                std::exit(i);
//                            }
        //p_this->deselectBackNeventOn();
        p_this->deselectBackNselect();
        p_this->parentDeselectBackNeventOn();
        return true;
    }

    bool tuiFnctRealUnit1MmyInt_t::clickingChild         ([[maybe_unused]] dtyIntfcAbstractUnitGraphic_t* p_this) {
        return false;
    }

    // section end   **** STATE MANAGEMENT *****
    // ****************************************************
    // --------------------------
// ****************************************************
// section start **** CONTAINER *****

    //public:
    void tuiFnctRealUnit1MmyInt_t::setValData        (uint32_t p_value)  {
        g_pdtyUnit1MmyInt32->vSetDbg(static_cast<int32_t>(p_value));
    }
    void tuiFnctRealUnit1MmyInt_t::setPtrData        (void* p_value)  {
        g_pdtyUnit1MmyInt32->set_pValue(static_cast<int32_t*>(p_value));
    }

    // section end   **** CONTAINER *****
    // ****************************************************
    // --------------------------
// ****************************************************
// section start **** DEBUG FUNCTIONS *****

    void tuiFnctRealUnit1MmyInt_t::dbgSet                (int32_t p_value)   {
        g_pdtyUnit1MmyInt32->vSetDbg(p_value);
    }

    void tuiFnctRealUnit1MmyInt_t::dbgSetMode            (bool p_select)   {
        g_dbgSelect = p_select;
    }

    void tuiFnctRealUnit1MmyInt_t::dbgRefreshValue       (dtyIntfcAbstractUnitGraphic_t* p_this)      {
        // p_this->frameNnameTest(g_strName, g_pdtyUnit1MmyInt32->g_pStringValue);
        g_pdtyUnit1MmyInt32->vSelected();
        p_this->nameOnly(g_pdtyUnit1MmyInt32->g_pStringValue);
    }

    // section end   **** DEBUG FUNCTIONS *****
    // ****************************************************
    // --------------------------
