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
 * krThreadCfgTbl.cpp
 *
 *  Created on: Jan, 4 2023
 *      Author: Marco Dau
 */

// lib include
#include "krThreadCfgTbl.h"
#include <cg_krThread.h>

namespace fw2 {namespace wrapper {namespace core	{

#define STACK_SIZE_00   200
#define STACK_SIZE_01   200
#define STACK_SIZE_02   200
#define STACK_SIZE_03   200
#define STACK_SIZE_04   200

StackType_t ptrStackBuf_00[STACK_SIZE_00];
StackType_t ptrStackBuf_01[STACK_SIZE_01];
StackType_t ptrStackBuf_02[STACK_SIZE_02];
StackType_t ptrStackBuf_03[STACK_SIZE_03];
StackType_t ptrStackBuf_04[STACK_SIZE_04];


krThreadCfg_t krThreadCfgTbl_t::ThreadCfgArray[] = {
    {1, STACK_SIZE_00,  ptrStackBuf_00  },
    {1, STACK_SIZE_01,  ptrStackBuf_01  },
    {1, STACK_SIZE_02,  ptrStackBuf_02  },
    {1, STACK_SIZE_03,  ptrStackBuf_03  },
    {1, STACK_SIZE_04,  ptrStackBuf_04  },
    {0, 0,              nullptr         }
};



}   } } // namespace fw2::wrapper::core
