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
 * app_sysExit.cpp
 *
 *  Created on: Jan,  20th 2026 (Tue)
 *      Author: Marco Dau
 */

#include <iostream>
#include <stdexcept>

#include "sysExit.h"
#include "pphManager.h"
#include "tuiManager.h"

void sysExit_t::exit (void)  {
    try { 
        throw 12; 
    } catch (int i) {
        tuiManager_t::end();

        pphManager_t::end();

        std::cout << " the integer exception was caught, with value: " << i << '\n';
        std::exit(i);
    }
}