//  *******************************************************************************
//  
//  mpfw / fw2 - Multi Platform FirmWare FrameWork 
//      library that contains the wrapper code to manage the threads
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
 * krThread.cpp
 *
 *  Created on: Jul, 30 2025 (wed)
 *      Author: Marco Dau
 */

// moduel include
#include "krThread.h"


namespace fw2 {namespace wrapper {namespace core	{


krThread_t::krThread_STATUS krThread_t::g_Status = krThread_t::krThread_STATUS_RUN;

#define THREAD_STACK_SIZE 200
#define uart_task_PRIORITY (configMAX_PRIORITIES - 1)

// Structure that will hold the TCB of the task being created.
StaticTask_t	krThread_t::xTaskBuffer;
StackType_t		krThread_t::xStack[ THREAD_STACK_SIZE ];


krThread_t::krThread_t(krThreadId p_ThreadId, krThreadCfg_t* p_ptrThreadConfig)	:
	 g_ThreadId			{p_ThreadId			}
	,g_ptrThreadConfig	{p_ptrThreadConfig	}
{}



void krThread_t::CreateStatic 	(void)	{
	g_Thread = xTaskCreateStatic	(	Loop ,
										"Uart_static_task",
										g_ptrThreadConfig->stackSize,
										( void * ) g_ThreadId, 
										g_ptrThreadConfig->priority, 
										g_ptrThreadConfig->xStack, 
										&g_xTaskBuffer 
									);
}


void krThread_t::Loop (void * p_Void) {
	
	uint32_t l_thread_id = (uint32_t) p_Void;
	//uint32_t l_thread_id = static_cast<uint32_t>(p_Void);
	Loop((krThreadId) l_thread_id);
	//Loop((krThreadId) (p_Void));
	
}

void krThread_t::Loop (krThreadId p_thread) {
	//TickType_t xLastWakeTime;

    // /* The xLastWakeTime variable needs to be initialized with the current tick
    // count.  Note that this is the only time the variable is written to explicitly.
    // After this xLastWakeTime is automatically updated within vTaskDelayUntil(). */
    // xLastWakeTime = xTaskGetTickCount();

	do {

		krThreadTbl::ThreadLoopFunction_t*  l_PtrThreadLoopFunction;
		l_PtrThreadLoopFunction = krThreadTbl::LoopFunctionArray;
		while (l_PtrThreadLoopFunction[0]) {
			l_PtrThreadLoopFunction[0](p_thread);
			l_PtrThreadLoopFunction++;
		}


        // /* This task should execute every 250 milliseconds exactly.  As per
        // the vTaskDelay() function, time is measured in ticks, and the
        // pdMS_TO_TICKS() macro is used to convert milliseconds into ticks.
        // xLastWakeTime is automatically updated within vTaskDelayUntil(), so is not
        // explicitly updated by the task. */
        // vTaskDelayUntil( &xLastWakeTime, pdMS_TO_TICKS( 10 ) );

	} while (krThread_STATUS_END != g_Status);
}

void krThread_t::Join 	(void)	{
}

void krThread_t::Exit 	(void)	{
	g_Status = krThread_STATUS_END;
}


} } }	// end - namespace fw2::wrapper::core
