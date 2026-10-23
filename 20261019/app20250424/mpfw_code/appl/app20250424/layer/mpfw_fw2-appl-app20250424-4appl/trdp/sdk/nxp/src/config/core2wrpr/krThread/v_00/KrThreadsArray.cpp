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
 * krThreadsArray.cpp
 *
 *  Created on: Apr, 13th 2026 (Mon)
 *      Author: Marco Dau
 */

// module include
#include "krThreadsArray.h"

#include "krThreadCfgTbl.h"

namespace fw2 {namespace wrapper {namespace core	{


krThread_t krThreadsArray_t::ThreadArray[] = {
    {krThread_Zero,  &krThreadCfgTbl_t::ThreadCfgArray[0]},
    {krThread_One,   &krThreadCfgTbl_t::ThreadCfgArray[1]},
    {krThread_Two,   &krThreadCfgTbl_t::ThreadCfgArray[2]},
    {krThread_Three, &krThreadCfgTbl_t::ThreadCfgArray[3]},
    {krThread_Four,  &krThreadCfgTbl_t::ThreadCfgArray[4]},
    {krThread_Num,   nullptr},
};

} } }   // end - namespace fw2::wrapper::core
