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
 * sysErrorGroup.h
 *
 *  Created on: Feb,  18th 2026 (Wed)
 *      Author: Marco Dau
 */

#ifndef     SYS_ERROR_GROUP_H
#define     SYS_ERROR_GROUP_H

#define     SYS_ERROR_GROUP_DEFAULT_H

#include <cstdint>

namespace fw2 { namespace fnct { namespace base	{
    

    enum class encSysErrorGroup_t: uint8_t    {
        base
        ,comProtocolStatus   = 1
        ,comBuffer_Lin
        ,sysErrorTest
        
    };

} } }   // fw2::fnct::base


#endif  //  SYS_ERROR_H
