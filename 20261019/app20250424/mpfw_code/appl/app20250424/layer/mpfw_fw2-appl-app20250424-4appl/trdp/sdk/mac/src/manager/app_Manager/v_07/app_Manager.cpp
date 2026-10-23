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
 * app_Manager.cpp
 *
 *  Created on: Dec, 27th 2025 (Sat)
 *      Author: Marco Dau
 */

#include "app_Manager.h"

#include "sysDebugModuleDefine.h"
#ifdef      DEBUG_DEF_APP_MANAGER_CPP
    #include "sysDebug.h"
#endif  //  DEBUG_DEF_APP_MANAGER_CPP


#include "pphManager.h"
#include "tuiManager.h"
#include "sysTimer.h"

#include "app_threads.h"
#include "app_threadsConfig.h"
#include "app_pphDef_ModCmmn.h"
using namespace mpfw::apps;

#include "app_ManagerCmmn.h"

void app_Manager_t::thread_interrupt (krThreadId p_ThreadId) {
    if(krThreadId::krThread_InterruptRIT == p_ThreadId) {

        pphManager_t::body(false);
    }
}


void app_Manager_t::thread_loopApp0 (krThreadId p_ThreadId) {
    if(krThreadId::krThread_App_0 == p_ThreadId) {

        tuiManager_t::body(false);

        if( app_threads_t::statusThread_match(kStatusThread_LOOP_APP_0) )   {
            tuiManager_t::body(false);
            // app_ManagerCmmn_t::rx_tx(&pph_USART_2_REAL);
            // tuiManager_t::body(false);
            app_threads_t::statusThread_next();
        }
    }
}

