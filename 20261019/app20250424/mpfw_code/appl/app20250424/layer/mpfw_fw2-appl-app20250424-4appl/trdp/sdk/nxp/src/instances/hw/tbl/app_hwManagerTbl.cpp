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
 * app_pphManagerTbl.cpp
 *
 *  Created on: Jun, 27 2024
 *      Author: Marco Dau
 */

#include "hwManagerTbl.h"
#include "app_pphDef_ModCmmn.h"
#include "app_pphDef_Mod_nxp.h"
#include "app_cmmn_pphDef_Buttons.h"
#include "app_cmmn_pphDef_Leds.h"

hw2ProxCmmn_t*  hwManagerTbl_t::UnitPtrArray[]   = {
    // &PPH_OBJ   (USART_1_REAL)
     &PPH_OBJ   (USART_2_REAL)
    ,&PPH_OBJ   (BUTTON_SW2_ISP2)
    ,&PPH_OBJ   (BUTTON_SW3_ISP1)
    ,&PPH_OBJ   (BUTTON_SW4_ISP0)
    ,&PPH_OBJ   (BUTTON_SW5_USER)
    ,&PPH_OBJ   (LED_LED1_D12)
    // ,&PPH_OBJ   (LED_LED2_D11)
    // ,&PPH_OBJ   (LED_LED3_D9 )
    ,nullptr
};

