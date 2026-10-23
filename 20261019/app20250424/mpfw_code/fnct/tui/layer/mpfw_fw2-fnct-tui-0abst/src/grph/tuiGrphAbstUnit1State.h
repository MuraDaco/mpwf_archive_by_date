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
 * tuiGrphAbstUnit1State.h
 *
 *  Created on: Jan, 29th 2025 (Wed)
 *      Author: Marco Dau
 */
 
#ifndef TUI_GPRH_ABST_UNIT_1_STATE_H
#define TUI_GPRH_ABST_UNIT_1_STATE_H

#include "tuiGrphAbstUnit0.h"

#include "dtyTypesDefs.h"
using namespace dtyTypesDefs_t; 

class tuiGrphAbstUnit1State_t: public tuiGrphAbstUnit0_t {

    protected:
        tuiGrphAbstUnit1State_t       (void);
    // ---------------------  INTERFACE section - START
    public:
        // bool selectByMouse 	        (void) override;

    protected:
        // bool select     	        (void) override;
        // bool deSelect   	        (void) override;
        // void eventOn    	        (void) override;
        // virtual bool selectTst              (void) = 0;

        virtual void dbgState_01            (void) = 0;    
        virtual void dbgState_01            (bool p_test) = 0;    
    // ---------------------  INTERFACE section -   END

public:
    // common functions
    void deselectBackNeventOn               (void) override;
    void deselectBackNselect                (void) override;
    // void setParent                          (tuiGrphAbstUnit1State_t* p_pParent);
    // tuiGrphAbstUnit1State_t* getParent           (void);
    void parentDeselectBackNeventOn         (void) override;
    bool getEventStatus                     (void);
    void setEventStatus                     (bool p_eventStatus) override;


protected:
    bool g_eventStatus;
    tuiState_t g_status;
private:
    // tuiGrphAbstUnit1State_t* g_pParent;

private:
    void selectBack                            (void) override;
    dtyIntfcAbstractUnitGraphic_t* searchCommonAncestor    (void) override;
    dtyIntfcAbstractUnitGraphic_t* deselectBack            (dtyIntfcAbstractUnitGraphic_t* p_poCommonAncestor, bool p_commonAncestorIsNextEventON) override;

protected:
    void selectNeventOnInit                     (void);
    static dtyIntfcAbstractUnitGraphic_t* g_poSelected;
    static dtyIntfcAbstractUnitGraphic_t* g_poEventOn;



// **** --------------------- Debug section - START

public:
    // debug
    virtual void debug_01    	(void) = 0;
    static uint8_t g_debugStatus;
    static uint8_t g_debugStatusX;

private:
    void debugDeselectBack (dtyIntfcAbstractUnitGraphic_t* p_poCommonAncestor, bool p_commonAncestorIsNextEventON);

// **** --------------------- Debug section - END

};

#endif 	// TUI_GRAPHIC_STATE_H
