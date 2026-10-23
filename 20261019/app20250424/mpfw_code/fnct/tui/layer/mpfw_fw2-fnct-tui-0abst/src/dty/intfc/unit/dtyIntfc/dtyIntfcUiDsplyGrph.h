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
 * dtyIntfcUiDsplyGrph.h
 *
 *  Created on: Jan, 28th 2025 (Tue)
 *      Author: Marco Dau
 */
 
#ifndef DTY_INTFC_UI_DSPLY_GRPH_H
#define DTY_INTFC_UI_DSPLY_GRPH_H


class dtyIntfcUiDsplyGrph_t {

    public:

        virtual void clear   	            (void) {};
        virtual void display                (void) {};
        virtual void display                ([[maybe_unused]] bool p_recursively) {};
        virtual void refreshWin             (void) {};
        virtual void refreshWinChildren     (void) {};

};

#endif 	// DTY_INTFC_UI_DSPLY_GRPH_H
