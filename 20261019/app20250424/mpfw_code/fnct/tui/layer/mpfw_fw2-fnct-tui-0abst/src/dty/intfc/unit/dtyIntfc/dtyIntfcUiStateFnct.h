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
 * dtyIntfcUiStateFnct.h
 *
 *  Created on: Jan, 28th 2025 (Tue)
 *      Author: Marco Dau
 */
 
#ifndef DTY_INTFC_UI_STATE_FNCT_H
#define DTY_INTFC_UI_STATE_FNCT_H

class dtyIntfcAbstractUnitGraphic_t;

class dtyIntfcUiStateFnct_t {

    public:

        virtual void selectStateSet     ([[maybe_unused]] bool p_selectState) {};
        virtual bool select     	    ([[maybe_unused]] dtyIntfcAbstractUnitGraphic_t* p_this) {return false;};
        virtual bool deSelect   	    ([[maybe_unused]] dtyIntfcAbstractUnitGraphic_t* p_this) {return false;};
        virtual void eventOn    	    ([[maybe_unused]] dtyIntfcAbstractUnitGraphic_t* p_this) {};
        virtual bool selectByMouse 	    ([[maybe_unused]] dtyIntfcAbstractUnitGraphic_t* p_this) {return false;};
        virtual bool clickingChild      ([[maybe_unused]] dtyIntfcAbstractUnitGraphic_t* p_this) {return false;};


};

#endif 	// DTY_INTFC_UI_STATE_FNCT_H
