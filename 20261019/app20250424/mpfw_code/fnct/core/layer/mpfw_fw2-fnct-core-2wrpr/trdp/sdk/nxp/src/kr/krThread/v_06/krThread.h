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
 * krThread.h
 *
 *  Created on: Jul, 30 2025 (wed)
 *      Author: Marco Dau
 */

#ifndef KR_THREAD_H_
#define KR_THREAD_H_

// module include
#include "krThreadTbl.h"

// system include
#include <cstdint>

// lib/wp include (wrap system include depending on platform selected)
#include <wp_sys_thread.h>
#include <krThreadCfg.h>


// lib/cg include
#include <cg_krThread.h>

namespace fw2 {namespace wrapper {namespace core	{


class krThread_t {
public:
	krThread_t(krThreadId p_ThreadId, krThreadCfg_t* p_ptrThreadConfig);

	enum krThread_STATUS {
		krThread_STATUS_STOP	= 0,
		krThread_STATUS_RUN		= 1,
		krThread_STATUS_END		= 2
	};
	

	static  krThread_STATUS g_Status;
	krThreadId g_ThreadId;
	krThreadCfg_t* g_ptrThreadConfig;
	StaticTask_t g_xTaskBuffer;
	thread_t g_Thread;
	
			void CreateStatic 	(void);
			void Join 	(void);

	static	void Exit 	(void);
	static 	void Loop (void* p_Void);
	static 	void Loop (krThreadId p_thread);

private:

	static StaticTask_t xTaskBuffer;
	static StackType_t  xStack[];
	
	// StaticTask_t g_xTaskBuffer;
	// StackType_t *g_ptrStack;


};

	
} } }	// end - namespace fw2::wrapper::core


#endif /* KR_THREAD_H_ */
