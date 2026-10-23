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
 * app_threadsConfig.h
 *
 *  Created on: Apr, 15th 2026 (Wed)
 *      Author: Marco Dau
 */

#ifndef APP_THREADS_CONFIG_H_
#define APP_THREADS_CONFIG_H_

namespace mpfw { namespace apps {


    enum kStatusThread_t {
    	 kStatusThread_FIRST
    	,kStatusThread_LOOP_APP_0 = kStatusThread_FIRST
    	,kStatusThread_LOOP_APP_1
    	,kStatusThread_LAST
    	,kStatusThread_LOOP_APP_2 = kStatusThread_LAST
        ,kStatusThread_Num
    };



} }	// mpfw::apps

#endif /* APP_THREADS_CONFIG_H_ */
