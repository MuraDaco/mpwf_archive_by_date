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
 * dtyIntfcAbstractUnitGraphic.h
 *
 *  Created on: Jan, 28th 2025 (Tue)
 *      Author: Marco Dau
 */
 
#ifndef DTY_INTFC_ABSTRACT_UNIT_GRAPHIC_H
#define DTY_INTFC_ABSTRACT_UNIT_GRAPHIC_H


#include "dtyIntfcUiCoord.h"
#include "dtyIntfcUiInOut.h"
#include "dtyIntfcUiCntnrGrph.h"
#include "dtyIntfcUiStateGrph.h"
#include "dtyIntfcUiDsplyGrph.h"
#include "dtyIntfcProcessGrph.h"

class dtyIntfcAbstractUnitGraphic_t :    public dtyIntfcUiCoord_t
                                        ,public dtyIntfcUiInOut_t
                                        ,public dtyIntfcUiCntnrGrph_t
                                        ,public dtyIntfcUiStateGrph_t
                                        ,public dtyIntfcUiDsplyGrph_t

                                        ,public dtyIntfcProcessGrph_t
{};


#endif  // DTY_INTFC_ABSTRACT_UNIT_GRAPHIC_H
