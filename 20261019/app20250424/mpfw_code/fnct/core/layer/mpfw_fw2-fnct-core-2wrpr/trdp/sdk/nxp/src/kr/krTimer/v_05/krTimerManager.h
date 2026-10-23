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
 * krTimerManager.h
 *
 *  Created on: Sep, 19 2022
 *      Author: Marco Dau
 */

#ifndef KR_TIMER_MANAGER_H_
#define KR_TIMER_MANAGER_H_

// module include
#include "krTimerManagerCmmn.h"

#include "fsl_rit.h"

// init definition
#define PTR_TASK_OF_krInitStatic_001_FNCT_CORE_2WRPR_KR_TIMER_init &krTimerManager_t::Init

// thread task definitions
// #define PTR_TASK_OF_ xxx krThread_004_FNCT_CORE_2WRPR_KR_TIMER_LoopUpdate &fw2::core::core::krTimerManagerCmmn_t::LoopUpdate


namespace fw2 { namespace core { namespace core {

class krTimerManager_t: public krTimerManagerCmmn_t {
public:

	static krTimerManager_t& getInstance()
	{
		static krTimerManager_t instance;

		return instance;
	}

	static void Init	 			    (void);
    static void interrupt_rit_handler   (void);
    static uint16_t g_timer_test;

private:
	krTimerManager_t() {}

    /* Structure of initialize RIT */
    static rit_config_t ritConfig;


};

} } }	// namespace fw2::core::core

#endif /* KR_TIMER_MANAGER_H_ */
