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
 * app_Manager.cpp
 *
 *  Created on: Dec, 27th 2025 (Sat)
 *      Author: Marco Dau
 */

#include "app_ManagerCmmn.h"

#include "pphManager.h"
#include "sysTimer.h"

#include "app_threads.h"
#include "app_threadsConfig.h"
#include "app_pphDef_ModCmmn.h"
#include "app_cmmn_pphDef_Buttons.h"
#include "app_cmmn_pphDef_Leds.h"
using namespace mpfw::apps;
#include "krTimer.h"
#include "krTimerManager.h"
using namespace fw2::core::core;


uint8_t app_ManagerCmmn_t::g_status = 0xff;
uint8_t app_ManagerCmmn_t::g_ptrBuf_A[] = ".1234.01u|ZZ_answer|";
uint8_t app_ManagerCmmn_t::g_ptrBuf_B[] = ".1234.01u|YY_answer|";
uint8_t app_ManagerCmmn_t::g_ptrBuf_C[] = ".1234.01u|XX_answer|";

bool app_ManagerCmmn_t::g_tx_on = true;

krTimer_t  app_ManagerCmmn_t::g_krTimer1  = {handlerTimer1, krThreadId::krThread_App_1, krTimer_t::krTimer_STATUS_RUN};

uint8_t app_ManagerCmmn_t::g_timer_test = 1;

void     app_ManagerCmmn_t::handlerTimer1   (void)  {
    if(g_timer_test) g_timer_test--;
    if(g_timer_test_led1) g_timer_test_led1--;

}


void app_ManagerCmmn_t::thread_loopApp1 (krThreadId p_ThreadId) {
    if(krThreadId::krThread_App_1 == p_ThreadId) {

        if( app_threads_t::statusThread_match(kStatusThread_LOOP_APP_1) )   {
            rx_tx(&pph_USART_2_REAL);

            if(0 == g_timer_test)    {
                g_timer_test = 200;
                #ifdef USART_REAL_
                    uint8_t l_str1[] = "01u| REAL    - Messaggio di test del 2026.09.06 ore 15.35|";
                #else
                    uint8_t l_str1[] = "01u| VIRTUAL - Messaggio di test del 2026.09.06 ore 15.35|";
                #endif    
                if(pph_USART_2_REAL.tx_packetSent(l_str1, sizeof(l_str1)))  {
                    while(!pph_USART_2_REAL.getBufferStatusFree()){
                    }
                }
            }


            app_threads_t::statusThread_next();
        }
    }
}

void app_ManagerCmmn_t::rx_tx (comBufferInterface_t* p_usart) {
            uint8_t l_id1 = 0; 
            uint8_t l_rxBufferSize = p_usart->rx_packetCheck();
            if(l_rxBufferSize)  {
                uint8_t* l_pPphUsartBuff = p_usart->rxBuff_getPtrCleaned();

                // 1. step: init
                if(
                        ( 'A'   == l_pPphUsartBuff[4] ) 
                    &&  ( 'A'   == l_pPphUsartBuff[5] ) 
                    &&  ( 0xff  == g_status ) 
                ) g_status = 1;
                if(
                        ( 'B'   == l_pPphUsartBuff[4] ) 
                    &&  ( 'B'   == l_pPphUsartBuff[5] ) 
                    &&  ( 0xff  == g_status ) 
                ) g_status = 2;
                if(
                        ( 'C'   == l_pPphUsartBuff[4] ) 
                    &&  ( 'C'   == l_pPphUsartBuff[5] ) 
                    &&  ( 0xff  == g_status ) 
                ) g_status = 3;


                // 2. step: answer
                if(
                        ( '1'   == l_pPphUsartBuff[4] ) 
                    &&  ( '1'   == l_pPphUsartBuff[5] ) 
                    &&  (  1    == g_status ) 
                )   {
                    l_id1 = 1;
                }
                if(
                        ( '2'   == l_pPphUsartBuff[4] ) 
                    &&  ( '2'   == l_pPphUsartBuff[5] ) 
                    &&  (  2    == g_status ) 
                )   {
                    l_id1 = 2;
                }

                if(
                        ( '3'   == l_pPphUsartBuff[4] ) 
                    &&  ( '3'   == l_pPphUsartBuff[5] ) 
                    &&  (  3    == g_status ) 
                )   {
                    l_id1 = 3;
                }

                // unlock the rxBuffer to receive other new packets
                p_usart->setBufferStatusFree();
            }

            
            // 2. step: answer
            if(
                    ( 1   == l_id1 ) 
            )   {
                if(p_usart->tx_packetSent(g_ptrBuf_A, sizeof(g_ptrBuf_A)))  {
                    while(!p_usart->getBufferStatusFree()){
                    }
                    g_status = 0xff;
                }

            }
            if(
                    ( 2   == l_id1 ) 
            )   {
                if(p_usart->send(g_ptrBuf_B) > 0)   {
                    while(!p_usart->getBufferStatusFree()){
                    }
                }
            }
            if(
                    ( 3   == l_id1 ) 
            )   {
                p_usart->send(g_ptrBuf_C);
            }

}

uint8_t app_ManagerCmmn_t::setStatus (comBufferInterface_t* p_usart) {

    uint8_t l_status = 0; 
    // uint8_t l_rxBufferSize = p_usart->rx_packetCheck();
    uint8_t l_rxBufferSize = 0;
    if(l_rxBufferSize)  {
        uint8_t* l_pPphUsartBuff = p_usart->rxBuff_getPtrCleaned();

        // 1. step: init
        if(
                ( 'F'   == l_pPphUsartBuff[4] ) 
            &&  ( 'F'   == l_pPphUsartBuff[5] ) 
            &&  ( 0xff  == g_status ) 
        ) g_status = 4;
        if(
                ( 'G'   == l_pPphUsartBuff[4] ) 
            &&  ( 'G'   == l_pPphUsartBuff[5] ) 
            &&  ( 0xff  == g_status ) 
        ) g_status = 5;
        if(
                ( 'H'   == l_pPphUsartBuff[4] ) 
            &&  ( 'H'   == l_pPphUsartBuff[5] ) 
            &&  ( 0xff  == g_status ) 
        ) g_status = 6;


        // 2. step: answer
        if(
                (   ( '1'   == l_pPphUsartBuff[4] ) 
                &&  ( '1'   == l_pPphUsartBuff[5] ) 
                &&  (  4    == g_status ) 
                )
            ||  (   ( '2'   == l_pPphUsartBuff[4] ) 
                &&  ( '2'   == l_pPphUsartBuff[5] ) 
                &&  (  5    == g_status ) 
                )
            ||  (   ( '3'   == l_pPphUsartBuff[4] ) 
                &&  ( '3'   == l_pPphUsartBuff[5] ) 
                &&  (  6    == g_status ) 
                )
        )   {
            l_status = g_status;
        }

        // unlock the rxBuffer to receive other new packets
        p_usart->setBufferStatusFree();
    }

    return l_status;
}

uint8_t  app_ManagerCmmn_t::g_timer_test_led1 = 0;
bool     app_ManagerCmmn_t::g_once = true;
bool     app_ManagerCmmn_t::g_led1_blink = true;

void app_ManagerCmmn_t::thread_loopApp2 (krThreadId p_ThreadId) {
    if(krThreadId::krThread_App_2 == p_ThreadId) {

        if( app_threads_t::statusThread_match(kStatusThread_LOOP_APP_2) )   {
            
            if(!PPH_OBJ(BUTTON_SW2_ISP2).getPin())   {
                // key pressed
                PPH_OBJ(LED_LED3_D9).setHigh();
            } else {
                // key released
                PPH_OBJ(LED_LED3_D9).setLow();
            }

            if(!PPH_OBJ(BUTTON_SW3_ISP1).getPin())   {
                // key pressed
                PPH_OBJ(LED_LED2_D11).setHigh();
            } else {
                // key released
                PPH_OBJ(LED_LED2_D11).setLow();
            }

            if(!PPH_OBJ(BUTTON_SW4_ISP0).getPin())   {
                // key pressed
                if(g_once)  {
                    g_once = false;
                    if(g_led1_blink)
                        g_led1_blink = false;
                    else
                        g_led1_blink = true;
                }
            } else {
                g_once = true;
            }

            if(g_led1_blink)    {
                if(0 == g_timer_test_led1)    {
                    g_timer_test_led1 = 1;
                    PPH_OBJ(LED_LED1_D12).tglPin();
                }

            } else {

                if(!PPH_OBJ(BUTTON_SW5_USER).getPin())   {
                    PPH_OBJ(LED_LED1_D12).setHigh();
                } else {
                    PPH_OBJ(LED_LED1_D12).setLow();
                }

            }


            app_threads_t::statusThread_next();
        }
    }
}


