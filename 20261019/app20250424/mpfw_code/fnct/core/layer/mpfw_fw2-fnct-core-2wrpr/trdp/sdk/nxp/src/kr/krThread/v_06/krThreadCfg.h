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
 * krThreadCfg.h
 *
 *  Created on: Jan, 4 2023
 *      Author: Marco Dau
 */


#ifndef KR_THREAD_CFG_H_
#define KR_THREAD_CFG_H_

// system include
#include <cstdint>

// lib/wp include (wrap system include depending on platform selected)
#include <wp_sys_thread.h>

namespace fw2 {namespace wrapper {namespace core	{

class krThreadCfg_t {

public:
	UBaseType_t				priority;
	configSTACK_DEPTH_TYPE 	stackSize;
	StackType_t*			xStack;
    

};

} } } // namespace fw2::wrapper::core

#endif  /* KR_THREAD_CFG_H_ */