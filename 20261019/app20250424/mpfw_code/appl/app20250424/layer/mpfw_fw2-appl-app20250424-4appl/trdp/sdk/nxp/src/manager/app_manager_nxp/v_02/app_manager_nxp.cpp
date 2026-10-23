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
 * app_manager_nxp.h
 *
 *  Created on: Apr, 22nd 2026 (Thu)
 *      Author: Marco Dau
 */

#include "app_manager_nxp.h"

#include "pphManager.h"
#include "sysTimer.h"

#include "app_threads.h"
#include "app_threadsConfig.h"
using namespace mpfw::apps;
#include "app_pphDef_Mod_nxp.h"
#include "app_ManagerCmmn.h"


uint8_t app_manager_nxp_t::g_ptrBuf_F[] = ".1234.01u|UU_answer|";
uint8_t app_manager_nxp_t::g_ptrBuf_G[] = ".1234.01u|TT_answer|";
uint8_t app_manager_nxp_t::g_ptrBuf_H[] = ".1234.01u|SS_answer|";

void app_manager_nxp_t::thread_loopApp3 (krThreadId p_ThreadId) {
    if(krThreadId::krThread_App_3 == p_ThreadId) {

        if( app_threads_t::statusThread_match(kStatusThread_LOOP_APP_3) )   {
            
            uint8_t l_status = app_ManagerCmmn_t::setStatus(&pph_USART_1_REAL);

            if(4 == l_status) {
                pph_USART_1_REAL.send(g_ptrBuf_F);
            }

            if(5 == l_status) {
                pph_USART_1_REAL.send(g_ptrBuf_G);
            }

            if(6 == l_status) {
                pph_USART_1_REAL.send(g_ptrBuf_H);
            }

            app_threads_t::statusThread_next();
        }
    }
}


