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
 * dtyIntfcUiStateGrph.h
 *
 *  Created on: Jan, 28th 2025 (Tue)
 *      Author: Marco Dau
 */
 
#ifndef DTY_INTFC_UI_STATE_GRPH_H
#define DTY_INTFC_UI_STATE_GRPH_H

class dtyIntfcAbstractUnitGraphic_t;

class dtyIntfcUiStateGrph_t {

    public:
        virtual bool select     	    (void) = 0;
        virtual bool selectTst     	    (void) = 0;
        virtual bool deSelect   	    (void) = 0;
        virtual void eventOn    	    (void) = 0;
        virtual bool selectByMouse 	    (void) = 0;
        //virtual bool clickingChild      (void) = 0;

        virtual dtyIntfcAbstractUnitGraphic_t* searchCommonAncestor (void) = 0;
        virtual dtyIntfcAbstractUnitGraphic_t* deselectBack         (dtyIntfcAbstractUnitGraphic_t* p_poCommonAncestor, bool p_commonAncestorIsNextEventON) = 0;
        virtual void selectBack                                     (void) = 0;
        virtual void deselectBackNeventOn                           (void) = 0;
        virtual void setEventStatus                                 (bool p_eventStatus) = 0;

        virtual void deselectBackNselect(void) = 0;
        virtual void parentDeselectBackNeventOn(void) = 0;


};

#endif 	// DTY_INTFC_UI_STATE_GRPH_H
