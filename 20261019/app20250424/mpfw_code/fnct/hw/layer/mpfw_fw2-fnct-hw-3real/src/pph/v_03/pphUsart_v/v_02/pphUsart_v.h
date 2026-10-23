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
 * pphUsart_v.h
 *
 *  Created on: Mar,  3rd 2026 (Tue)
 *      Author: Marco Dau
 */


#ifndef PPH_USART_V_H
#define PPH_USART_V_H

#include "pphMacroDefine.h"
#include "hwComCh_vUsart.h"
#include "comProtocolStatus.h"

#define PPH_TX_BUFFER_SIZE  HW_2_USART_CMMN_TX_BUFFER_SIZE
#define PPH_RX_BUFFER_SIZE  HW_2_USART_CMMN_RX_BUFFER_SIZE

class pphUsart_v_t :   public hwComCh_vUsart_t
{

    public:
        pphUsart_v_t  (mcuComCh_vUsartInitParams_t* p_pConfig);

    private:
        comProtocolStatus_t g_proto;
};

#endif 	// PPH_USART_V_H
