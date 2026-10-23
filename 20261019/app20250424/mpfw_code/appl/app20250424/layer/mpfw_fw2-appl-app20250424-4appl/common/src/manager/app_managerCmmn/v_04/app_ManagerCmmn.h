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
 * app_ManagerCmmn.h
 *
 *  Created on: Apr, 15th 2026 (Wed)
 *      Author: Marco Dau
 */


#ifndef APP_MANAGER_CMMN_H
#define APP_MANAGER_CMMN_H

#include <cstdint>

#include "dtyTypesDefs.h"
using namespace dtyTypesDefs_t; 

#include "krTimer.h"
using namespace fw2::core::core;

#include "pphManager.h"
#include "comBufferInterface.h"
using namespace fw2::fnct::base;

#include "cg_krThread.h"

#define PTR_TASK_OF_krThread_001_APPL_APP20250424_4APPL_thread_loopApp1     &app_ManagerCmmn_t::thread_loopApp1
#define PTR_TASK_OF_krThread_002_APPL_APP20250424_4APPL_thread_loopApp2     &app_ManagerCmmn_t::thread_loopApp2

#define PTR_TASK_OF_krTimer_002_APPL_APP20250424_4APPL_g_krTimer1           &app_ManagerCmmn_t::g_krTimer1


class app_ManagerCmmn_t {

public:

    static void     thread_loopApp1    (krThreadId p_ThreadId);

    static void     thread_loopApp2    (krThreadId p_ThreadId);
    static void     rx_tx              (comBufferInterface_t* p_usart);
    static uint8_t  setStatus          (comBufferInterface_t* p_usart);

    static krTimer_t  g_krTimer1;
    static void     handlerTimer1   (void);
    static uint8_t  g_timer_test;
    static uint8_t  g_timer_test_led1;
    static bool     g_once;
    static bool     g_led1_blink;

private:
    static uint8_t g_status;
    static uint8_t g_ptrBuf_A[];
    static uint8_t g_ptrBuf_B[];
    static uint8_t g_ptrBuf_C[];

    static bool     g_tx_on;

};


#endif 	// APP_MANAGER_CMMN_H
