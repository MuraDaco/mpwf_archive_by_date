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
 * tuiFnctRealUnit1Debug.h
 *
 *  Created on: Jan, 31st 2025 (Fri)
 *      Author: Marco Dau
 */
 

#include "tuiFnctRealUnit1Debug.h"


tuiFnctRealUnit1Debug_t::tuiFnctRealUnit1Debug_t      (const char* p_strName   ,dtyUnit1MmyInt32_t* p_pDtyStatus   )   :
    tuiFnctAbstUnit0_t       (p_strName)
    ,g_pDtyStatus           {p_pDtyStatus}
{}

// --------------------- Process section - START
    #define UNUSED(X) (void)X      // To avoid gcc/g++ warnings

    bool tuiFnctRealUnit1Debug_t::init   	            ([[maybe_unused]] dtyIntfcAbstractUnitGraphic_t* p_this)  {
        UNUSED(g_pDtyStatus);
        return true;
    }
    
    // bool tuiFnctRealUnit1Debug_t::initChildren           ([[maybe_unused]] dtyIntfcAbstractUnitGraphic_t* p_this)  {
    //     return true;
    // }
    // 
    // bool tuiFnctRealUnit1Debug_t::loop   	            ([[maybe_unused]] dtyIntfcAbstractUnitGraphic_t* p_this)  {
    //     return true;
    // }
    // 
    // bool tuiFnctRealUnit1Debug_t::loopChildren           ([[maybe_unused]] dtyIntfcAbstractUnitGraphic_t* p_this)  {
    //     return true;
    // }
    // 
    // void tuiFnctRealUnit1Debug_t::end       	            ([[maybe_unused]] dtyIntfcAbstractUnitGraphic_t* p_this)  {
    // 
    // }
    // 
    // void tuiFnctRealUnit1Debug_t::endChildren            ([[maybe_unused]] dtyIntfcAbstractUnitGraphic_t* p_this)  {
    // 
    // }

// --------------------- Process section - END


// --------------------- Display section - START

void tuiFnctRealUnit1Debug_t::clear     	        (dtyIntfcAbstractUnitGraphic_t* p_this)  {
    p_this->frameClear();
}

void tuiFnctRealUnit1Debug_t::display     	    (dtyIntfcAbstractUnitGraphic_t* p_this)  {
    p_this->frameNnameTest(g_strName);
}

void tuiFnctRealUnit1Debug_t::display     	    (dtyIntfcAbstractUnitGraphic_t* p_this, [[maybe_unused]] bool p_recursively)  {
    display(p_this);
}

// void tuiFnctRealUnit1Debug_t::displayChildren    ([[maybe_unused]] dtyIntfcAbstractUnitGraphic_t* p_this, [[maybe_unused]] bool p_recursively)  {
// }
// 
// void tuiFnctRealUnit1Debug_t::refreshChildren    ([[maybe_unused]] dtyIntfcAbstractUnitGraphic_t* p_this)  {
// }


// --------------------- Display section - END


// --------------------- State management section - START

bool tuiFnctRealUnit1Debug_t::select     	        (dtyIntfcAbstractUnitGraphic_t* p_this)  {
    return p_this->frameNnameTest(tuiState_t::select, g_strName);
}

bool tuiFnctRealUnit1Debug_t::deSelect   	        (dtyIntfcAbstractUnitGraphic_t* p_this)  {
    return p_this->frameNnameTest(tuiState_t::deselect, g_strName);
}

void tuiFnctRealUnit1Debug_t::eventOn    	        (dtyIntfcAbstractUnitGraphic_t* p_this)  {
    p_this->frameNnameTest(tuiState_t::eventOn, g_strName);
}

bool tuiFnctRealUnit1Debug_t::selectByMouse          (dtyIntfcAbstractUnitGraphic_t* p_this)  {
    p_this->deselectBackNeventOn();
    return true;
}

// bool tuiFnctRealUnit1Debug_t::clickingChild          ([[maybe_unused]] dtyIntfcAbstractUnitGraphic_t* p_this) {
//     return false;
// }


// --------------------- State management section - END

// --------------------- Events handler section - START

// void tuiFnctRealUnit1Debug_t::vEventHndlKey_down	([[maybe_unused]] dtyIntfcAbstractUnitGraphic_t* p_this)  {
// }
// 
// void tuiFnctRealUnit1Debug_t::vEventHndlKey_up	([[maybe_unused]] dtyIntfcAbstractUnitGraphic_t* p_this)  {
// }
// 
// void tuiFnctRealUnit1Debug_t::vEventHndlKey_left	([[maybe_unused]] dtyIntfcAbstractUnitGraphic_t* p_this)  {
// }
// 
// void tuiFnctRealUnit1Debug_t::vEventHndlKey_right	([[maybe_unused]] dtyIntfcAbstractUnitGraphic_t* p_this)  {
// }
// 
// void tuiFnctRealUnit1Debug_t::vEventHndlKey_enter	([[maybe_unused]] dtyIntfcAbstractUnitGraphic_t* p_this)  {
// }

void tuiFnctRealUnit1Debug_t::vEventHndlKey_home	(dtyIntfcAbstractUnitGraphic_t* p_this)  {
    p_this->parentDeselectBackNeventOn();

}

// --------------------- Events handler section - START
