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
 * tuiGrphAbstUnit3Event.h
 *
 *  Created on: Jan, 30th 2025 (Thu)
 *      Author: Marco Dau
 */
 
#ifndef TUI_GRPH_ABST_UNIT_3_EVENT_H
#define TUI_GRPH_ABST_UNIT_3_EVENT_H

#include "tuiGrphAbstUnit2Coord.h"

class dtyIntfcAbstractUnitFunctional_t;


class tuiGrphAbstUnit3Event_t :     public tuiGrphAbstUnit2Coord_t
{
    typedef void    (* eventHandler_t)      (tuiGrphAbstUnit3Event_t*);

public:
    tuiGrphAbstUnit3Event_t       (dtyIntfcAbstractUnitFunctional_t* p_pUnit  );
    tuiGrphAbstUnit3Event_t       (dtyIntfcAbstractUnitFunctional_t* p_pUnit  ,box_t p_box    );
    tuiGrphAbstUnit3Event_t       (dtyIntfcAbstractUnitFunctional_t* p_pUnit                  ,margins_t p_margin );
    tuiGrphAbstUnit3Event_t       (dtyIntfcAbstractUnitFunctional_t* p_pUnit  ,box_t p_box    ,margins_t p_margin );

    // --------------------- General section - START
    bool bNotNull           (void)  override;
    dtyIntfcAbstractUnitFunctional_t* g_pUnit;
    // --------------------- General section - START

    // --------------------- Process section - START
    // bool init                   (void)      override;
    // bool init                   (dtyIntfcAbstractUnitGraphic_t* p_pParent)       override;
    bool initChildren           (void)      override;
    bool loop                   (void)      override;
    bool loopChildren           (void)      override;
    void end                    (void)      override;
    void endChildren            (void)      override;
    // --------------------- Process section - START

    // --------------------- Display section - START
    void clear              (void)                  override;
    void display            (void)                  override;
    void display            (bool p_recursively)    override;
    // --------------------- Display section - START

    // --------------------- Container section - START
    void updCoordNboundsChilds          (void)  override;
    // --------------------- Container section - END

    // --------------------- State management section - START
    bool select             (void)                  override;
    bool deSelect           (void)                  override;
    void eventOn            (void)                  override;
    bool selectByMouse      (void)                  override;
    bool selectTst          (void)                  override;
    void dbgState_01        (void)                  override;
    void dbgState_01        (bool p_test)           override;
    
    // --------------------- State management section - END

    // --------------------- Events handler section - START
    private:
	// ..................... Events KEY handler: functions
    // the "event" & the "event array" is equal for all the instanticies of the current class therefore ...
    // the event handler function & the event array must to be defined as static
    static void vEventHndlKey_down	        (tuiGrphAbstUnit3Event_t* p_this);
    static void vEventHndlKey_up	        (tuiGrphAbstUnit3Event_t* p_this);
    static void vEventHndlKey_left	        (tuiGrphAbstUnit3Event_t* p_this);
    static void vEventHndlKey_right	        (tuiGrphAbstUnit3Event_t* p_this);
    static void vEventHndlKey_enter	        (tuiGrphAbstUnit3Event_t* p_this);
    static void vEventHndlKey_home	        (tuiGrphAbstUnit3Event_t* p_this);

    static void vEventHndlKey_del	        (tuiGrphAbstUnit3Event_t* p_this);
    static void vEventHndlKey_backSpace	    (tuiGrphAbstUnit3Event_t* p_this);
    static void vEventHndlKey_typeChar	    (tuiGrphAbstUnit3Event_t* p_this);

	// ..................... Events KEY handler: array
    protected:
    static eventHandler_t g_eventKeyArray[];

    private:
	// ..................... Events MOUSE handler: functions
    static void vEventHndlMouse_rollUp	    (tuiGrphAbstUnit3Event_t* p_this);
    static void vEventHndlMouse_rollDown	(tuiGrphAbstUnit3Event_t* p_this);

	// ..................... Events KEY handler: array
    protected:
    static eventHandler_t g_eventMouseArray[];

    // --------------------- Events handler section - END

    // --------------------- Debug management section - START
    void debug_01               (void) override;
    // --------------------- Debug management section - END


};


#endif 	// TUI_GRPH_ABST_UNIT_3_EVENT_H
