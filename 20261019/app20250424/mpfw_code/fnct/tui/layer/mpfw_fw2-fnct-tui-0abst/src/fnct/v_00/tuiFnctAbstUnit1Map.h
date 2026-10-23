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
 * tuiFnctAbstUnit1Map.h
 *
 *  Created on: Oct, 27th 2024
 *      Author: Marco Dau
 */
 
#ifndef TUI_FNCT_ABST_UNIT_1_MAP_H
#define TUI_FNCT_ABST_UNIT_1_MAP_H

#include "tuiFnctAbstUnit0.h"

#include "dtyIntfcAbstractUnitGraphic.h"

class tuiFnctAbstUnit1Map_t :    public tuiFnctAbstUnit0_t   {

protected:

    tuiFnctAbstUnit1Map_t      (const char* p_strName, dtyIntfcAbstractUnitGraphic_t** p_childrenSet);

    // --------------------- Element pointers section - START
    // pointer to the list of uiBase objects belonging to one
    // or more objects of the current class
    dtyIntfcAbstractUnitGraphic_t**  g_childrenSet;
    uint8_t g_childCurrentId;
    uint8_t g_childrenNum;
    bool g_bChildrenSetEmpty;
    // --------------------- Element pointers section - END


protected:
   
    // --------------------- Process section - START
    bool init                   (dtyIntfcAbstractUnitGraphic_t* p_this) override;
    bool initChildren           (dtyIntfcAbstractUnitGraphic_t* p_this) override;
    // bool loop                    (dtyIntfcAbstractUnitGraphic_t* p_this) override;
    // bool loopChildren            (dtyIntfcAbstractUnitGraphic_t* p_this) override;
    // void end                     (dtyIntfcAbstractUnitGraphic_t* p_this) override;
    // void endChildren             (dtyIntfcAbstractUnitGraphic_t* p_this) override;
    // --------------------- Process section - START

    // --------------------- Display section - START
    // void clear                  (dtyIntfcAbstractUnitGraphic_t* p_this) override;
    void display                (dtyIntfcAbstractUnitGraphic_t* p_this) override;
    void display                (dtyIntfcAbstractUnitGraphic_t* p_this, bool p_recursively) override;
    void displayChildren        (dtyIntfcAbstractUnitGraphic_t* p_this, bool p_recursively) override;
    void refreshChildren        (dtyIntfcAbstractUnitGraphic_t* p_this) override;
    // --------------------- Display section - END

    // --------------------- State management section - START
    // bool select                  (dtyIntfcAbstractUnitGraphic_t* p_this) override;
    // bool deSelect                (dtyIntfcAbstractUnitGraphic_t* p_this) override;
    // void eventOn                 (dtyIntfcAbstractUnitGraphic_t* p_this) override;
    bool selectByMouse 	        (dtyIntfcAbstractUnitGraphic_t* p_this) override;
    bool clickingChild          (dtyIntfcAbstractUnitGraphic_t* p_this) override;
    // --------------------- State management section - END

    // --------------------- Events handler section - START
	// ..................... Events handler: functions
    void vEventHndlKey_down     (dtyIntfcAbstractUnitGraphic_t* p_this)  override;
    void vEventHndlKey_up       (dtyIntfcAbstractUnitGraphic_t* p_this)  override;
    //void vEventHndlKey_left       (dtyIntfcAbstractUnitGraphic_t* p_this)  override;
    //void vEventHndlKey_right      (dtyIntfcAbstractUnitGraphic_t* p_this)  override;
    void vEventHndlKey_enter      (dtyIntfcAbstractUnitGraphic_t* p_this)  override;
    //void vEventHndlKey_home       (dtyIntfcAbstractUnitGraphic_t* p_this)  override;
    // --------------------- Events handler section - END


};


#endif 	// TUI_FNCT_ABST_UNIT_1_MAP_H
