//  *******************************************************************************
//  
//  mpfw / fw2 - Multi Platform FirmWare FrameWork 
//      library that contains the application code that is platform independent
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
 * app_end.h
 *
 *  Created on: Apr, 14th 2026 (Tue)
 *      Author: Marco Dau
 */

#ifndef APP_END_H_
#define APP_END_H_

#include <array>
#include <cstdint>
using namespace std;

// lib include
#include "cg_krThread.h"


#define PTR_TASK_OF_krEndStatic_001_APPL_CORE_4APPL_APP_END_end &mpfw::apps::app_end::end

namespace mpfw { namespace apps {


class app_end {

public:
    static void end   (void);




};

} }	// mpfw::apps

#endif /* APP_END_H_ */
