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
 * app_pphDef_ModCmmn.h
 *
 *  Created on: Jun, 27 2024
 *      Author: Marco Dau
 */


#include "app_mcuPinPortDefineConfig.h"

// #define USART_REAL_

#ifdef USART_REAL_
    #include "pphUsart_r.h"
    extern PPH_DEF_H__(pphUsart_r_t,  USART_2_REAL )
#else
    #include "pphUsart_v.h"
    extern PPH_DEF_H__(pphUsart_v_t,  USART_2_REAL )
#endif
