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
 
#ifndef TUI_FNCT_REAL_UNIT_1_FORMATTED_STRING_H
#define TUI_FNCT_REAL_UNIT_1_FORMATTED_STRING_H

#include "tuiFnctAbstUnit0.h"

#include "dtyTypesDefs.h"
using namespace dtyTypesDefs_t; 

#include "dtyString.h"

#include "dtyIntfcAbstractUnitGraphic.h"


class tuiFnctRealUnit1FormattedString_t :    public tuiFnctAbstUnit0_t
{

public:
    tuiFnctRealUnit1FormattedString_t       (const char* p_strName  ,dtyString_t* p_pString = nullptr   );

protected:
   
    // --------------------- Process section - START
    bool init   	            (dtyIntfcAbstractUnitGraphic_t* p_this) override;
    // --------------------- Process section - START

    // --------------------- Display section - START
    void clear                  (dtyIntfcAbstractUnitGraphic_t* p_this) override;
    void display                (dtyIntfcAbstractUnitGraphic_t* p_this) override;
    void display                (dtyIntfcAbstractUnitGraphic_t* p_this, bool p_recursively) override;
    // --------------------- Display section - END

    // --------------------- State management section - START
    bool select     	        (dtyIntfcAbstractUnitGraphic_t* p_this) override;
    bool deSelect   	        (dtyIntfcAbstractUnitGraphic_t* p_this) override;
    void eventOn    	        (dtyIntfcAbstractUnitGraphic_t* p_this) override;
    bool selectByMouse 	        (dtyIntfcAbstractUnitGraphic_t* p_this) override;
    // --------------------- State management section - END

    // --------------------- Events handler section - START
	// ..................... Events handler: functions
    void vEventHndlKey_home	    (dtyIntfcAbstractUnitGraphic_t* p_this)  override;
    // --------------------- Events handler section - END

private:

    // --------------------- Generic  Data section - START
    // const char* g_strName;
    // --------------------- Generic  Data section - END

    // --------------------- Specific Data section - START
    dtyString_t* g_pString;
    // --------------------- Specific Data section - END

};


#endif 	// TUI_FNCT_REAL_UNIT_1_FORMATTED_STRING_H
