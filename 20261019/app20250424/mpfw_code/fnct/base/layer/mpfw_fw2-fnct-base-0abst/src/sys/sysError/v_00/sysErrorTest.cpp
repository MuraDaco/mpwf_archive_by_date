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
 * sysErrorTest.cpp
 *
 *  Created on: Feb,  18th 2026 (Wed)
 *      Author: Marco Dau
 */

#include "sysErrorTest.h"

#include <iostream>
#include <string>
using namespace std;
using namespace fw2::fnct::base;

    void sysErrorTest_t::print_value  (kSysError_t p_errorCode)   {

        cout << "sysErrorTest_call -> "    
                                        << endl << "     -- "
                                        << to_string(static_cast<uint8_t>(p_errorCode)) << " -- " 
                                        << endl;

    }

