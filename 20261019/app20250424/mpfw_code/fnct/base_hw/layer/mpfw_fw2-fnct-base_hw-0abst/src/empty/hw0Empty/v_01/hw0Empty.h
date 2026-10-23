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
 * hw0Empty.h
 *
 *  Created on: Jan, 7th 2026 (Wed)
 *      Author: Marco Dau
 */


#include "hw0ConfigUsart.h"
#include "hw0GpioIntfc.h"
#include "hw0GpioDgIntfc.h"
#include "hwComChIntfc.h"
#include "hw0UsartRs485Params.h"

#ifndef BASE_HW_0_EMPTY_H
#define BASE_HW_0_EMPTY_H

namespace fw2 { namespace fnct { namespace base { namespace hw {


    class hw0Empty_t   {
            void do_nothing (void);
    };

}   }   }   }   // fw2::fnct::base::hw

#endif  // BASE_HW_0_EMPTY_H