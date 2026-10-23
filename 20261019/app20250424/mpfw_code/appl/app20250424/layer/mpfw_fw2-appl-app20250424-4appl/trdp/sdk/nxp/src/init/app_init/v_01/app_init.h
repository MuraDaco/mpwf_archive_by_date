//  *******************************************************************************
//  
//  mpfw / fw2 - Multi Platform FirmWare FrameWork 
//      library that contains the application code that is platform independent
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
 * app_init.h
 *
 *  Created on: Dec, 26th 2025 (Fri)
 *      Author: Marco Dau
 */

#ifndef APP_INIT_H_
#define APP_INIT_H_


// lib include
#include "cg_krThread.h"


// #define PTR_TASK_OF_ xxxx krInitStatic_001_APPL_CORE_4APPL_APP_INIT_init &mpfw::apps::app_init::init
#define PTR_TASK_OF_krInitStatic_001_APPL_CORE_4APPL_APP_INIT_init &app_init::init

// #include "fsl_rit.h"
// 
// namespace mpfw { namespace apps {


class app_init {

public:
    static void init   (void);
private:
    static void optimize_func   (void);

//     /* Structure of initialize RIT */
//     static rit_config_t ritConfig;



};

// } }	// mpfw::apps

#endif /* APP_INIT_H_ */
