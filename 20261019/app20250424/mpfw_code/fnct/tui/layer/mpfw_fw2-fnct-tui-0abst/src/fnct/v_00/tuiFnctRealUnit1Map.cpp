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
 * tuiFnctRealUnit1Map.cpp
 *
 *  Created on: Nov, 8th 2024
 *      Author: Marco Dau
 */
 

#include "tuiFnctRealUnit1Map.h"


tuiFnctRealUnit1Map_t::tuiFnctRealUnit1Map_t      (const char* p_strName   ,dtyIntfcAbstractUnitGraphic_t** p_childrenSet     )   :
     tuiFnctAbstUnit1Map_t      (p_strName, p_childrenSet)
{}

// --------------------- Process section - START

bool tuiFnctRealUnit1Map_t::loop   	            ([[maybe_unused]] dtyIntfcAbstractUnitGraphic_t* p_this)  {
    loopChildren(p_this);

    return true;
}

bool tuiFnctRealUnit1Map_t::loopChildren           ([[maybe_unused]] dtyIntfcAbstractUnitGraphic_t* p_this)  {
    for(uint8_t l_id=0; l_id<g_childrenNum; l_id++) g_childrenSet[l_id]->loop();

    return true;
}

void tuiFnctRealUnit1Map_t::end       	            ([[maybe_unused]] dtyIntfcAbstractUnitGraphic_t* p_this)  {

}

void tuiFnctRealUnit1Map_t::endChildren            ([[maybe_unused]] dtyIntfcAbstractUnitGraphic_t* p_this)  {

}

// --------------------- Process section - END


// --------------------- Display section - START

void tuiFnctRealUnit1Map_t::clear     	        (dtyIntfcAbstractUnitGraphic_t* p_this)  {
    p_this->frameClear();
}

// void tuiFnctRealUnit1Map_t::display     	    (dtyIntfcAbstractUnitGraphic_t* p_this)  {
//     p_this->frameNnameTest(g_strName);
// }
// 
// void tuiFnctRealUnit1Map_t::display     	    (dtyIntfcAbstractUnitGraphic_t* p_this, bool p_recursively)  {
//     display(p_this);
//     if(p_recursively) displayChildren(p_this, p_recursively);
// }



// --------------------- Display section - END


// --------------------- State management section - START

bool tuiFnctRealUnit1Map_t::select     	        (dtyIntfcAbstractUnitGraphic_t* p_this)  {
    return p_this->frameNnameTest(tuiState_t::select, g_strName);
}

bool tuiFnctRealUnit1Map_t::deSelect   	        (dtyIntfcAbstractUnitGraphic_t* p_this)  {
    return p_this->frameNnameTest(tuiState_t::deselect, g_strName);
}

void tuiFnctRealUnit1Map_t::eventOn    	        ([[maybe_unused]] dtyIntfcAbstractUnitGraphic_t* p_this)  {
    p_this->frameNnameTest(tuiState_t::eventOn, g_strName);
}



// --------------------- State management section - END

// --------------------- Events handler section - START

void tuiFnctRealUnit1Map_t::vEventHndlKey_left	([[maybe_unused]] dtyIntfcAbstractUnitGraphic_t* p_this)  {
}

void tuiFnctRealUnit1Map_t::vEventHndlKey_right	([[maybe_unused]] dtyIntfcAbstractUnitGraphic_t* p_this)  {
}

void tuiFnctRealUnit1Map_t::vEventHndlKey_home	(dtyIntfcAbstractUnitGraphic_t* p_this)  {
    p_this->parentDeselectBackNeventOn();

}

// --------------------- Events handler section - START
