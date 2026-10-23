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
 * tuiFnctRealUnit1Ebox.h
 *
 *  Created on: Jan, 31st 2025 (Fri)
 *      Author: Marco Dau
 */
 
#ifndef TUI_FNCT_REAL_UNIT_1_EBOX_H
#define TUI_FNCT_REAL_UNIT_1_EBOX_H

#include "tuiFnctAbstUnit0.h"

#include "dtyBaseArray.h"
#include "dtyTypesDefs.h"
using namespace dtyTypesDefs_t; 

#include "dtyIntfcAbstractUnitGraphic.h"

class tuiFnctRealUnit1Ebox_t :    public tuiFnctAbstUnit0_t
{

public:
    tuiFnctRealUnit1Ebox_t       (const char* p_strName  ,dtyBaseArray_t& p_rDtyStr   );
    tuiFnctRealUnit1Ebox_t       (const char* p_strName  ,dtyBaseArray_t& p_rDtyStr  ,tuiFnctAbstUnit0_t* p_pFuncOwner ,tuiUnitFunc_t p_func   );

protected:
   
    // --------------------- Process section - START
    bool init   	                    (dtyIntfcAbstractUnitGraphic_t* p_this) override;
    // --------------------- Process section - START

    // --------------------- Display section - START
    void clear                          (dtyIntfcAbstractUnitGraphic_t* p_this) override;
    void display                        (dtyIntfcAbstractUnitGraphic_t* p_this) override;
    void display                        (dtyIntfcAbstractUnitGraphic_t* p_this, bool p_recursively) override;
    // --------------------- Display section - END

    // --------------------- State management section - START
    bool select     	                (dtyIntfcAbstractUnitGraphic_t* p_this) override;
    bool deSelect   	                (dtyIntfcAbstractUnitGraphic_t* p_this) override;
    void eventOn    	                (dtyIntfcAbstractUnitGraphic_t* p_this) override;
    bool selectByMouse 	                (dtyIntfcAbstractUnitGraphic_t* p_this) override;
    // --------------------- State management section - END

    // --------------------- Events handler section - START
	// ..................... Events handler: functions
    void vEventHndlKey_down	            (dtyIntfcAbstractUnitGraphic_t* p_this) override;
    void vEventHndlKey_up	            (dtyIntfcAbstractUnitGraphic_t* p_this) override;
    void vEventHndlKey_left	            (dtyIntfcAbstractUnitGraphic_t* p_this) override;
    void vEventHndlKey_right	        (dtyIntfcAbstractUnitGraphic_t* p_this) override;
    void vEventHndlKey_enter	        (dtyIntfcAbstractUnitGraphic_t* p_this) override;
    void vEventHndlKey_home	            (dtyIntfcAbstractUnitGraphic_t* p_this) override;

    void vEventHndlKey_del	            (dtyIntfcAbstractUnitGraphic_t* p_this) override;
    void vEventHndlKey_backSpace	    (dtyIntfcAbstractUnitGraphic_t* p_this) override;
    void vEventHndlKey_typeChar	        (dtyIntfcAbstractUnitGraphic_t* p_this) override;
    // --------------------- Events handler section - END

private:

    // --------------------- Generic  Data section - START
    // const char* g_strName;
    // --------------------- Generic  Data section - END

    // --------------------- Specific Data section - START
    dtyBaseArray_t& g_rDtyStr;
    tuiFnctAbstUnit0_t* g_pFuncOwner;
    tuiUnitFunc_t g_func;
public:
    void insertString   (const char* p_str);
    void refreshDisplay (dtyIntfcAbstractUnitGraphic_t* p_this);
    // --------------------- Specific Data section - END

    // --------------------- STATUS MANAGEMENT section - START
    
    public:
        enum kStatus_t: int8_t  {
             edit
            ,suspend        // enterKeyPressed
        };

        kStatus_t g_status;

        void setStatus              (kStatus_t p_status);
        void setStatus_toEdit       (void);
        void setStatus_toSuspend    (void);
        kStatus_t getStatus         (void);
        bool chkStatusSuspend       (void);

    // --------------------- STATUS MANAGEMENT section - END

};


#endif 	// TUI_FNCT_REAL_UNIT_1_EBOX_H
