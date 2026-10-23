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
 * tuiFnctRealUnit2Cntnr.h
 *
 *  Created on: Jan, 31st 2025 (Fri)
 *      Author: Marco Dau
 */
 
#ifndef TUI_FNCT_REAL_UNIT_2_CNTNR_H
#define TUI_FNCT_REAL_UNIT_2_CNTNR_H

#include "tuiFnctAbstUnit1Cntnr.h"


class tuiFnctRealUnit2Cntnr_t :    public tuiFnctAbstUnit1Cntnr_t
{

public:
    tuiFnctRealUnit2Cntnr_t       (const char* p_strName  ,dtyCntnr0BaseUnit_t* p_pCntnr = nullptr  );

protected:
   
    // --------------------- Process section - START
    bool loop                    (dtyIntfcAbstractUnitGraphic_t* p_this) override;
    bool loopChildren            (dtyIntfcAbstractUnitGraphic_t* p_this) override;
    // --------------------- Process section - START

    // --------------------- Display section - START
    void clear                  (dtyIntfcAbstractUnitGraphic_t* p_this) override;
    void display                (dtyIntfcAbstractUnitGraphic_t* p_this) override;
    void display                (dtyIntfcAbstractUnitGraphic_t* p_this, bool p_recursively) override;
    // --------------------- Display section - END

    // --------------------- State management section - START
    bool select                  (dtyIntfcAbstractUnitGraphic_t* p_this) override;
    bool deSelect                (dtyIntfcAbstractUnitGraphic_t* p_this) override;
    void eventOn                 (dtyIntfcAbstractUnitGraphic_t* p_this) override;
    // --------------------- State management section - END

    // --------------------- KEY Events handler section - START
	// ..................... KEY Events handler: functions
    void vEventHndlKey_home     (dtyIntfcAbstractUnitGraphic_t* p_this)  override;
    // --------------------- KEY Events handler section - END

};


#endif 	// TUI_FNCT_REAL_UNIT_2_CNTNR_H
