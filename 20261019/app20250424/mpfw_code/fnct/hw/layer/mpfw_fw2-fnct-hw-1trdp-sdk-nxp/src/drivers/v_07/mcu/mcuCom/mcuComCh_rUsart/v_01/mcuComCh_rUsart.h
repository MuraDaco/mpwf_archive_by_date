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
 * mcuComCh_rUsart.h
 *
 *  Created on: Ago, 31st 2026  (Mon)
 *      Author: Marco Dau
 */


#ifndef     MCU_COM_CH_R_USART_H
#define     MCU_COM_CH_R_USART_H

#include "hwComChIntfc.h"
#include "hw0UsartRs485Params.h"
using namespace fw2::fnct::base::hw;

#include "mcuComCh_rUsartInitParams.h"
#include "mcuComCh_vUsartInitParams.h"

#include "fsl_usart_upd.h"

class mcuComCh_rUsart_t :    public hwComChIntfc_t
                            ,public hw0UsartRs485Params_t
{
    public:

        mcuComCh_rUsart_t  (mcuComCh_rUsartInitParams_t* p_pConfig);
        mcuComCh_rUsart_t  (mcuComCh_vUsartInitParams_t* p_pConfig);

        // init
            void    mcuInit_step1           (void);
            void    mcuInit_step2           (void);

        // general
            bool    chkInterruptsRaised     (void)                      override ;
        // transmit
            bool    tx_chkInterruptRaised   (void)                      override ;
            void    tx_eventBegin           (void)                      override ;
            void    tx_eventFirstData       (void)                      override ;
            void    tx_eventSendData        (uint8_t p_data)            override ;
            void    tx_eventLastData        (void)                      override ;
            void    tx_eventEnd             (void)                      override ;

        // receive

            bool    rx_chkInterruptRaised   (void)                      override ;
            bool    rx_chkError_overrun     (void)                      override ;
            void    rx_eventBegin           (void)                      override ;
            uint8_t rx_eventReceiveData     (void)                      override ;
            void    rx_eventEnd             (void)                      override ;

        // Rs485
            void    setTxEnablePin          (void)                      override ;
            void    clrTxEnablePin          (void)                      override ;
            void    setRxEnablePin          (void)                      override ;
            void    clrRxEnablePin          (void)                      override ;

    protected:

    private:

        void    InitPins_IOCON      (void);
        void    InitPins_GPIO       (void);

        mcuComCh_rUsartInitParams_t*    g_pConfig;
        USART_Type*                 g_pUsartRegs;

};


#endif  //  MCU_COM_CH_R_USART_H
