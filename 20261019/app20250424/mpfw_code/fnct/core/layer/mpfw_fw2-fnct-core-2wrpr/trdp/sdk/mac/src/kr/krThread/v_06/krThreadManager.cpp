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
 * krThreadManager.cpp
 *
 *  Created on: Jul, 30 2025 (wed)
 *      Author: Marco Dau
 */

// module include
#include <krThreadManager.h>

// system include
#include <cstdint>

namespace fw2 {namespace wrapper {namespace core	{

// thread definition
krThread_t* krThreadManager_t::g_krTh[krThread_Num];

void krThreadManagerCmmn_t::InitThenRun 	(void)	{
    // thread initialization
    for(uint16_t i=0; i<krThread_Num; i++)    {
        krThreadManager_t::g_krTh[i] = new krThread_t(static_cast<krThreadId>(i));
    }

//    krThread_t::Exit(); // improve the knowledge

    for(uint16_t i=0; i<krThread_Num; i++)    {
        krThreadManager_t::g_krTh[i]->Join();
    }
}



}   }   } // namespace fw2::wrapper::core
