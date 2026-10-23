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
 * sysError.h
 *
 *  Created on: Feb,  18th 2026 (Wed)
 *      Author: Marco Dau
 */

#ifndef     SYS_ERROR_H
#define     SYS_ERROR_H

#include <cstdint>

#include "sysErrorGroup.h"


#ifdef SYS_ERROR_GROUP_DEFAULT_H

    // this macro has no sense because sysErrorGroup.h is one of default, it is for only compatibility between partial and total build
    // in partial build (build of library) it cannot define error group because it doesn't know any module involved in application build
    // instead in the total build (build the entire application, app + libraries) it can define the error group for all modules
    // the error group are define at application level.
    // default sysErrorGroup.h does not (it is better say "can not") define any error group because it is in the lower level of dependencies
    // its encSysErrorGroup_t enum class has only one element, the encSysErrorGroup_t::base one
    #define INIT_ERROR_CODE_GROUP(group)    static constexpr auto group    = 1;  \
                                            static constexpr auto class_name    = group                                    

    #define MAKE_ERROR_CODE(error, value)   static constexpr auto error         = static_cast<kSysError_t>(value + kSysErrorRange); \
                                            static_assert(kSysErrorRange > value, "value is equal or greater than range")
#else

    #define INIT_ERROR_CODE_GROUP(group)    static constexpr auto class_name    = encSysErrorGroup_t::group
    #define MAKE_ERROR_CODE(error, value)   static constexpr auto error         = static_cast<kSysError_t>(value + kSysErrorRange * static_cast<uint8_t>(class_name)); \
                                            static_assert(kSysErrorRange > value, "value is equal or greater than range")

#endif


namespace fw2 { namespace fnct { namespace base	{
    
    enum kSysError_t: uint8_t    {
        none
    };

    constexpr uint8_t kSysErrorRange  = 50;

} } }   // fw2::fnct::base


#endif  //  SYS_ERROR_H
