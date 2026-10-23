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
 * dtyIntfcUiCntnrGrph.h
 *
 *  Created on: Jan, 28th 2025 (Tue)
 *      Author: Marco Dau
 */
 
#ifndef DTY_INTFC_UI_CNTNR_GRPH_H
#define DTY_INTFC_UI_CNTNR_GRPH_H

class dtyIntfcAbstractUnitGraphic_t;

class dtyIntfcUiCntnrGrph_t {

public:

// ****************************************************
// section start **** CHILDREN MANAGEMENT *****

    // to be implemented whether the class has children
    virtual void updCoordNboundsChilds          (void) {};

    virtual void                            setParent   (dtyIntfcAbstractUnitGraphic_t* p_pParent) = 0;
    virtual dtyIntfcAbstractUnitGraphic_t*  getParent   (void)  = 0;

    // section end   **** CHILDREN MANAGEMENT *****
    // ****************************************************
    // --------------------------

    virtual bool bNotNull           (void) = 0;


};

#endif 	// DTY_INTFC_UI_CNTNR_GRPH_H
