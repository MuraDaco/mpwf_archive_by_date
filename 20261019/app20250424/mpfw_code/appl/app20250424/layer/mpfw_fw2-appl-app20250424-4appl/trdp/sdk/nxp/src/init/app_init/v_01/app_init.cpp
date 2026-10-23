//  *******************************************************************************
//  
//  mpfw / fw2 - Multi Platform FirmWare FrameWork 
//      library that contains the "main" entry point and, 
//      eventualy, application code that is platform dependent
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
 * app_init.c
 *
 *  Created on: Dec, 26th 2025 (Fri)
 *      Author: Marco Dau
 */

#include "app_init.h"

#include "fsl_common.h"
#include "fsl_iocon.h"
#include "pin_mux.h"
#include "fsl_gpio.h"

// #include "hwConfig_hwUsartRs485.h"

#include "pphManager.h"

#include "app_pphDef_ModCmmn.h"
#include "app_cmmn_pphDef_Buttons.h"
#include "app_cmmn_pphDef_Leds.h"


// namespace mpfw { namespace apps {

// #define RIT_IRQ_ID RIT_IRQn
// /* Get source clock for RIT driver */
// #define RIT_SOURCE_CLOCK CLOCK_GetFreq(kCLOCK_CoreSysClk)

// rit_config_t app_init::ritConfig;


void app_init::init     (void)    {

    pphManager_t::init();

//     /* Structure of initialize RIT */
//     rit_config_t ritConfig;
// 
//     /*
//      * ritConfig.enableRunInDebug = false;
//      */
//     RIT_GetDefaultConfig(&ritConfig);
// 
//     /* Init rit module */
//     RIT_Init(RIT, &ritConfig);
// 
//     /* Set timer period for Compare register. */
//     RIT_SetTimerCompare(RIT, RIT_SOURCE_CLOCK);
// 
//     /* Set to enable the Counter register auto clear to zero when the counter value equals the set period. */
//     RIT_SetCountAutoClear(RIT, true);
// 
// 
//     /* Start counting */
//     RIT_StartTimer(RIT);
// 
//     /* Enable at the NVIC */
//     EnableIRQ(RIT_IRQ_ID);

//     bool l_tx_on = false;
//     while(1)    {
//             if(
//                     !PPH_OBJ(BUTTON_SW2_ISP2).getPin()
//                 ||  !PPH_OBJ(BUTTON_SW4_ISP0).getPin()                    
//             )   {
//                 // button pressed -> leds off
//                 PPH_OBJ(LED_LED2_D11).setHigh();
//                 PPH_OBJ(LED_LED3_D9).setHigh();
//                 l_tx_on = true;
//             } else {
//                 // button released -> leds on
//                 PPH_OBJ(LED_LED2_D11).setLow();
//                 PPH_OBJ(LED_LED3_D9).setLow();
//             }
// 
//             if(!PPH_OBJ(BUTTON_SW5_USER).getPin())   {
//                 // button pressed
//                 pph_USART_2_REAL.rx_eventBegin();
//             }
// 
//             if(PPH_OBJ(BUTTON_SW3_ISP1).getPin())   {
//                 // button released
//                 PPH_OBJ(LED_LED1_D12).setHigh();
//             } else {
//                 // button pressed
//                 PPH_OBJ(LED_LED1_D12).setLow();
// 
//                 if(l_tx_on) {
//                     // leds ON
//                     PPH_OBJ(LED_LED2_D11).setHigh();
//                     PPH_OBJ(LED_LED3_D9).setHigh();
//                     uint8_t l_str1[] = "01u|Messaggio di test|";
//                     // pph_USART_2_REAL.send(l_str1);
//                     if(pph_USART_2_REAL.tx_packetSent(l_str1, sizeof(l_str1)))  {
//                         while(!pph_USART_2_REAL.getBufferStatusFree()){
//                             if(!PPH_OBJ(BUTTON_SW4_ISP0).getPin())   {
//                                 // button pressed
//                                 pph_USART_2_REAL.setBufferStatusFree();                            
//                             }
//                         }
//                     }
//                     l_tx_on = false;
//                 }
//             }
//     }

//    // *********************************************************************************************************
//    // pin to read the sw2 button state
//    const uint32_t port0_pin6_config = (/* Pin is configured as PIO0_6 */
//                                        IOCON_PIO_FUNC0 |
//                                        /* Selects pull-up function */
//                                        IOCON_PIO_MODE_PULLUP |
//                                        /* Input function is not inverted */
//                                        IOCON_PIO_INV_DI |
//                                        /* Enables digital function */
//                                        IOCON_PIO_DIGITAL_EN |
//                                        /* Input filter disabled */
//                                        IOCON_PIO_INPFILT_OFF |
//                                        /* Standard mode, output slew rate control is enabled */
//                                        IOCON_PIO_SLEW_STANDARD |
//                                        /* Open drain is disabled */
//                                        IOCON_PIO_OPENDRAIN_DI);
//    /* PORT0 PIN6 (coords: A5) is configured as PIO0_6 */
//    IOCON_PinMuxSet(IOCON, 0U, 6U, port0_pin6_config);
//
//
//    // pin to drive led 2 & max 485-DE
//    const uint32_t port3_pin3_config = (/* Pin is configured as PIO3_3 */
//                                        IOCON_PIO_FUNC0 |
//                                        /* Selects pull-up function */
//                                        IOCON_PIO_MODE_PULLUP |
//                                        /* Input function is not inverted */
//                                        IOCON_PIO_INV_DI |
//                                        /* Enables digital function */
//                                        IOCON_PIO_DIGITAL_EN |
//                                        /* Input filter disabled */
//                                        IOCON_PIO_INPFILT_OFF |
//                                        /* Standard mode, output slew rate control is enabled */
//                                        IOCON_PIO_SLEW_STANDARD |
//                                        /* Open drain is disabled */
//                                        IOCON_PIO_OPENDRAIN_DI);
//    /* PORT3 PIN3 (coords: A13) is configured as PIO3_3 */
//    IOCON_PinMuxSet(IOCON, 3U, 3U, port3_pin3_config);
//
//
//    // *********************************************************************************************************
//    // pin to read the sw3 button state
//    const uint32_t port0_pin5_config = (/* Pin is configured as PIO0_6 */
//                                        IOCON_PIO_FUNC0 |
//                                        /* Selects pull-up function */
//                                        IOCON_PIO_MODE_PULLUP |
//                                        /* Input function is not inverted */
//                                        IOCON_PIO_INV_DI |
//                                        /* Enables digital function */
//                                        IOCON_PIO_DIGITAL_EN |
//                                        /* Input filter disabled */
//                                        IOCON_PIO_INPFILT_OFF |
//                                        /* Standard mode, output slew rate control is enabled */
//                                        IOCON_PIO_SLEW_STANDARD |
//                                        /* Open drain is disabled */
//                                        IOCON_PIO_OPENDRAIN_DI);
//    /* PORT0 PIN6 (coords: E7) is configured as PIO0_5 */
//    IOCON_PinMuxSet(IOCON, 0U, 5U, port0_pin5_config);
//
//
//    // pin to drive led 3 & max 485-RE
//    const uint32_t port2_pin2_config = (/* Pin is configured as PIO2_2 */
//                                        IOCON_PIO_FUNC0 |
//                                        /* Selects pull-up function */
//                                        IOCON_PIO_MODE_PULLUP |
//                                        /* Input function is not inverted */
//                                        IOCON_PIO_INV_DI |
//                                        /* Enables digital function */
//                                        IOCON_PIO_DIGITAL_EN |
//                                        /* Input filter disabled */
//                                        IOCON_PIO_INPFILT_OFF |
//                                        /* Standard mode, output slew rate control is enabled */
//                                        IOCON_PIO_SLEW_STANDARD |
//                                        /* Open drain is disabled */
//                                        IOCON_PIO_OPENDRAIN_DI);
//    /* PORT3 PIN3 (coords: C3) is configured as PIO3_3 */
//    IOCON_PinMuxSet(IOCON, 2U, 2U, port2_pin2_config);
//
//    // enable clock & reset peripheral according with the compile time definitions
//    GPIO_PortInit(GPIO, APP_BOARD_MARCO_TEST_SW2_PORT );
//    GPIO_PortInit(GPIO, APP_BOARD_MARCO_TEST_LED2_PORT);
//
//    GPIO_PortInit(GPIO, APP_BOARD_MARCO_TEST_SW3_PORT );
//    GPIO_PortInit(GPIO, APP_BOARD_MARCO_TEST_LED3_PORT);
//
//    /* Define the init structure for the output LED pin*/
//    gpio_pin_config_t led_config = {
//        kGPIO_DigitalOutput,
//        0,
//    };
//
//    GPIO_PinInit (GPIO, APP_BOARD_MARCO_TEST_LED2_PORT, APP_BOARD_MARCO_TEST_LED2_PIN, &led_config);
//    // rs485 tx enable
//    GPIO_PinWrite(GPIO, APP_BOARD_MARCO_TEST_LED2_PORT, APP_BOARD_MARCO_TEST_LED2_PIN, 1);
//
//    GPIO_PinInit (GPIO, APP_BOARD_MARCO_TEST_LED3_PORT, APP_BOARD_MARCO_TEST_LED3_PIN, &led_config);
//    // rs485 rx disable
//    GPIO_PinWrite(GPIO, APP_BOARD_MARCO_TEST_LED3_PORT, APP_BOARD_MARCO_TEST_LED3_PIN, 1);


}


#pragma GCC push_options
#pragma GCC optimize("O0")

void app_init::optimize_func     (void)    {

    if(hwManagerTbl_t::UnitPtrArray[0]) return;

}

#pragma GCC pop_options


// } }	// mpfw::apps
