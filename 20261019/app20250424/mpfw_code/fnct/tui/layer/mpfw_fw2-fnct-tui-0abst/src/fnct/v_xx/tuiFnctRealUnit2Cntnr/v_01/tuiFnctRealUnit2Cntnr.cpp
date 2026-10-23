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
 * tuiFnctRealUnit2Cntnr.cpp
 *
 *  Created on: Jan, 31st 2025 (Fri)
 *      Author: Marco Dau
 */
 

#include "tuiFnctRealUnit2Cntnr.h"


tuiFnctRealUnit2Cntnr_t::tuiFnctRealUnit2Cntnr_t      (const char* p_strName   ,dtyCntnr0BaseUnit_t* p_pCntnr     )   :
     tuiFnctAbstUnit1Cntnr_t         (p_strName, p_pCntnr)
{}

// --------------------- Process section - START

bool tuiFnctRealUnit2Cntnr_t::loop   	            ([[maybe_unused]] dtyIntfcAbstractUnitGraphic_t* p_this)  {
    loopChildren(p_this);

    return true;
}

bool tuiFnctRealUnit2Cntnr_t::loopChildren           ([[maybe_unused]] dtyIntfcAbstractUnitGraphic_t* p_this)  {
    g_pCntnr->loop( );

    return true;
}


// --------------------- Process section - END


// --------------------- Display section - START

void tuiFnctRealUnit2Cntnr_t::clear     	        (dtyIntfcAbstractUnitGraphic_t* p_this)  {
    p_this->frameClear();
}

void tuiFnctRealUnit2Cntnr_t::display     	    (dtyIntfcAbstractUnitGraphic_t* p_this)  {
    p_this->frameNnameTest(g_strName);
}

void tuiFnctRealUnit2Cntnr_t::display     	    (dtyIntfcAbstractUnitGraphic_t* p_this, bool p_recursively)  {
    display(p_this);
    if(p_recursively) displayChildren(p_this, p_recursively);
}



// --------------------- Display section - END


// --------------------- State management section - START

bool tuiFnctRealUnit2Cntnr_t::select     	        (dtyIntfcAbstractUnitGraphic_t* p_this)  {
    return p_this->frameNnameTest(tuiState_t::select, g_strName);
}

bool tuiFnctRealUnit2Cntnr_t::deSelect   	        (dtyIntfcAbstractUnitGraphic_t* p_this)  {
    return p_this->frameNnameTest(tuiState_t::deselect, g_strName);
}

void tuiFnctRealUnit2Cntnr_t::eventOn    	        ([[maybe_unused]] dtyIntfcAbstractUnitGraphic_t* p_this)  {
    p_this->frameNnameTest(tuiState_t::eventOn, g_strName);
}



// --------------------- State management section - END

// --------------------- Events handler section - START

void tuiFnctRealUnit2Cntnr_t::vEventHndlKey_home	(dtyIntfcAbstractUnitGraphic_t* p_this)  {
    p_this->parentDeselectBackNeventOn();

}

// --------------------- Events handler section - START
