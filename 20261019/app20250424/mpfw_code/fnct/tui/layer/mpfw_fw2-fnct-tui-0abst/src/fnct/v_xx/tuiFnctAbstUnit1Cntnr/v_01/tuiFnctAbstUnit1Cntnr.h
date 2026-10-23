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
 * tuiFnctAbstUnit1Cntnr.h
 *
 *  Created on: Jan, 31st 2025 (Fri)
 *      Author: Marco Dau
 */
 
#ifndef TUI_FNCT_ABST_UNIT_1_CNTNR_H
#define TUI_FNCT_ABST_UNIT_1_CNTNR_H


#include "tuiFnctAbstUnit0.h"
#include "dtyCntnr0BaseUnit.h"

#include "dtyIntfcAbstractUnitGraphic.h"

class tuiFnctAbstUnit1Cntnr_t :    public tuiFnctAbstUnit0_t 
{

protected:
    tuiFnctAbstUnit1Cntnr_t      (const char* p_strName, dtyCntnr0BaseUnit_t* p_pCntnr     );

    // --------------------- Process section - START
    bool init                   (dtyIntfcAbstractUnitGraphic_t* p_this) override;
    bool initChildren           (dtyIntfcAbstractUnitGraphic_t* p_this) override;
    // --------------------- Process section - END

    // --------------------- Container section - START
    void updCoordNboundsChilds      (void) override;

    dtyCntnr0BaseUnit_t* g_pCntnr;
    // --------------------- Container section - END

    // --------------------- Display section - START
    void displayChildren        (dtyIntfcAbstractUnitGraphic_t* p_this, bool p_recursively) override;
    void refreshChildren        (dtyIntfcAbstractUnitGraphic_t* p_this) override;
    // --------------------- Display section - END

    // --------------------- State management section - START
    bool selectByMouse 	        (dtyIntfcAbstractUnitGraphic_t* p_this) override;
    bool clickingChild          (dtyIntfcAbstractUnitGraphic_t* p_this) override;
    // --------------------- State management section - END

    // --------------------- KEY Events handler section - START
	// ..................... KEY Events handler: functions
    void vEventHndlKey_down         (dtyIntfcAbstractUnitGraphic_t* p_this)  override;
    void vEventHndlKey_up           (dtyIntfcAbstractUnitGraphic_t* p_this)  override;
    void vEventHndlKey_enter        (dtyIntfcAbstractUnitGraphic_t* p_this)  override;
    // --------------------- KEY Events handler section - END

    // --------------------- MOUSE Events handler section - START
	// ..................... MOUSE Events handler: functions
    void vEventHndlMouse_rollUp         (dtyIntfcAbstractUnitGraphic_t* p_this)  override;
    void vEventHndlMouse_rollDown       (dtyIntfcAbstractUnitGraphic_t* p_this)  override;
    // --------------------- MOUSE Events handler section - END

};


#endif 	// TUI_FNCT_ABST_UNIT_1_CNTNR_H
