//  *******************************************************************************
//  
//  mpfw / fw2 - Multi Platform FirmWare FrameWork 
//      library that contains the "main" entry point and, 
//      eventualy, application code that is platform dependent
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
 * app_init.c
 *
 *  Created on: Dec, 26th 2025 (Fri)
 *      Author: Marco Dau
 */

#include "app_init.h"

#include <iomanip>      // std::quoted()
#include <iostream>
#include <string>

// module include

#include <pphManager.h>
#include <tuiManager.h>


using namespace mpfw::apps;

#define OUTPUT(a) std::cout << "output: " #a << '\n'

void app_init::init     (void)    {

    std::cout << "performing init without parameters" << '\n';

}

void app_init::init     (int argc, char *argv[])    {


    OUTPUT(million);
    std::cout << "output: " "test" << '\n';

    pphManager_t::init(argc, argv);

    tuiManager_t::init();

}


