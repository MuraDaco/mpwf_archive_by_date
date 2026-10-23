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
 * tuiFnctRealUnit1FormattedString.h
 *
 *  Created on: Feb,  1st 2025 (Sat)
 *      Author: Marco Dau
 */
 

#include "tuiFnctRealUnit1FormattedString.h"

tuiFnctRealUnit1FormattedString_t::tuiFnctRealUnit1FormattedString_t      (const char* p_strName   ,dtyString_t* p_pString   )   :
    tuiFnctAbstUnit0_t       (p_strName)
    ,g_pString               {p_pString}
{}

// --------------------- Process section - START

bool tuiFnctRealUnit1FormattedString_t::init   	            ([[maybe_unused]] dtyIntfcAbstractUnitGraphic_t* p_this)  {
    uint16_t l_h;
    l_h =   g_pString->getBuffSize() / p_this->getDimW();
    l_h += (g_pString->getBuffSize() % p_this->getDimW()) ? 1 : 0;
    p_this->setDimH(l_h);
    p_this->updBoundY();

    p_this->setEventStatus(false);
    return true;
}


// --------------------- Process section - END


// --------------------- Display section - START

void tuiFnctRealUnit1FormattedString_t::clear     	        (dtyIntfcAbstractUnitGraphic_t* p_this)  {
    p_this->frameClear();
}

void tuiFnctRealUnit1FormattedString_t::display     	    (dtyIntfcAbstractUnitGraphic_t* p_this)  {
    p_this->stringPrint2(0, false, g_pString->getBuffPtr(), g_pString->getBuffSize());

}

void tuiFnctRealUnit1FormattedString_t::display     	    (dtyIntfcAbstractUnitGraphic_t* p_this, [[maybe_unused]] bool p_recursively)  {
    display(p_this);
}



// --------------------- Display section - END


// --------------------- State management section - START

bool tuiFnctRealUnit1FormattedString_t::select     	        (dtyIntfcAbstractUnitGraphic_t* p_this)  {
    return p_this->stringPrint2(tuiState_t::select, 0, true, g_pString->getBuffPtr(), g_pString->getBuffSize());
}

bool tuiFnctRealUnit1FormattedString_t::deSelect   	        ([[maybe_unused]] dtyIntfcAbstractUnitGraphic_t* p_this)  {
    return p_this->stringPrint2(tuiState_t::deselect, 0, false, g_pString->getBuffPtr(), g_pString->getBuffSize());
}

void tuiFnctRealUnit1FormattedString_t::eventOn    	        ([[maybe_unused]] dtyIntfcAbstractUnitGraphic_t* p_this)  {
}

bool tuiFnctRealUnit1FormattedString_t::selectByMouse        ([[maybe_unused]] dtyIntfcAbstractUnitGraphic_t* p_this)  {
        p_this->deselectBackNselect();
        p_this->parentDeselectBackNeventOn();
    return true;
}

// --------------------- State management section - END

// --------------------- Events handler section - START

void tuiFnctRealUnit1FormattedString_t::vEventHndlKey_home	(dtyIntfcAbstractUnitGraphic_t* p_this)  {
    p_this->parentDeselectBackNeventOn();

}

// --------------------- Events handler section - START
