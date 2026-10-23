//  *******************************************************************************
//  
//  mpfw / fw2 - Multi Platform FirmWare FrameWork 
//      library that contains the essential code that is used in every application
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
 * krTimerManager.cpp
 *
 *  Created on: Sep, 19 2022
 *      Author: Marco Dau
 */

// module include
#include "krTimerManager.h"

namespace fw2 { namespace core { namespace core {

#define RIT_IRQ_ID RIT_IRQn
/* Get source clock for RIT driver */
#define RIT_SOURCE_CLOCK CLOCK_GetFreq(kCLOCK_CoreSysClk)

rit_config_t krTimerManager_t::ritConfig;

uint16_t krTimerManager_t::g_timer_test = 1;
void krTimerManager_t::interrupt_rit_handler  (void)
{
    RIT_ClearStatusFlags(RIT, kRIT_TimerFlag);
    // if(g_timer_test) g_timer_test = 0;
    LoopUpdate(krThread_InterruptRIT);
    __DSB();
}


void krTimerManager_t::Init (void) {

    /* Structure of initialize RIT */
    rit_config_t ritConfig;

    /*
     * ritConfig.enableRunInDebug = false;
     */
    RIT_GetDefaultConfig(&ritConfig);

    /* Init rit module */
    RIT_Init(RIT, &ritConfig);

    /* Set timer period for Compare register. */
    RIT_SetTimerCompare(RIT, RIT_SOURCE_CLOCK);

    /* Set to enable the Counter register auto clear to zero when the counter value equals the set period. */
    RIT_SetCountAutoClear(RIT, true);


    /* Start counting */
    RIT_StartTimer(RIT);

    /* Enable at the NVIC */
    EnableIRQ(RIT_IRQ_ID);

}


} } }	// namespace fw2::core::core

