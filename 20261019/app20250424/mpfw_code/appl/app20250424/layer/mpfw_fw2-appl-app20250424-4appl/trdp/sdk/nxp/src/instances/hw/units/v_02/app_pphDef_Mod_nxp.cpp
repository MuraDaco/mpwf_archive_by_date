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
 * app_app_pphDef_nxp.cpp
 *
 *  Created on: Apr, 22nd 2026 (Thu)
 *      Author: Marco Dau
 */


#include "app_pphDef_Mod_nxp.h"


// mcuComCh_rUsartInitParams_t glo_usart_v_Params_2Real = HW_USART_R_INIT_PARAMS_DEF;

#define USART0_FLEXCOMM_ID  0
#define HW_USART_1_INIT_PARAMS_DEF    {   \
                                         USART0_FLEXCOMM_ID                             /*  USART_FLEXCOMM_ID   */   \
                                        ,USART0                                         /* ,USART_REG_PTR       */   \
                                        ,kFRO12M_to_FLEXCOMM0                           /* ,USART_CLOCK_ATTACH  */   \
                                        ,FLEXCOMM0_IRQn                                 /* ,USART_IRQn          */   \
                                        ,5                                              /* ,USART_NVIC_PRIO     */   \
                                        ,IOCON_PIO_FUNC1                                /* ,IOCON_PIO_FUNC1     */   \
                                        ,29                                             /* ,USART_RX_PIN        */   \
                                        ,0                                              /* ,USART_RX_PORT       */   \
                                        ,30                                             /* ,USART_TX_PIN        */   \
                                        ,0                                              /* ,USART_TX_PORT       */   \
                                        ,false                                          /* ,USART_RS485_EN      */   \
                                        ,2                                              /* ,RS485_RE_PIN        */   \
                                        ,2                                              /* ,RS485_RE_PORT       */   \
                                        ,3                                              /* ,RS485_DE_PIN        */   \
                                        ,3                                              /* ,RS485_DE_PORT       */   \
                                    }

mcuComCh_rUsartInitParams_t glo_usartParams_1Real    = HW_USART_1_INIT_PARAMS_DEF;
PPH_DEF_CPP_USART_2 (pphUsart_r_t ,USART_1_REAL ,glo_usartParams_1Real        )

