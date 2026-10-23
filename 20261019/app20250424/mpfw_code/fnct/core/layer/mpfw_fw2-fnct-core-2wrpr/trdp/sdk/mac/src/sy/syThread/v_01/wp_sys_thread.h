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
 * wp_sys_thread.h
 *
 *  Created on: Sep, 19 2022
 *      Author: Marco Dau
 */

#ifndef WP_SYS_THREAD_H_
#define WP_SYS_THREAD_H_

#include <thread>
typedef std::thread thread_t;
#include <chrono>

using namespace std::this_thread;     // sleep_for, sleep_until
using namespace std::chrono_literals; // ns, us, ms, s, h, etc.

namespace fw2 {namespace wrapper {namespace core	{

void wp_sleep_for(uint16_t p_Duration);

}   } } // namespace fw2::wrapper::core

#endif  /* WP_SYS_THREAD_H_ */