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
 * app_mcuPinPortDefineConfig.h
 *
 *  Created on: Jun, 27 2024
 *      Author: Marco Dau
 */


#ifndef APP_MCU_PIN_PORT_DEFINE_CONFIG_H
#define APP_MCU_PIN_PORT_DEFINE_CONFIG_H

#include "LPC54608.h"
#include "hw0UsartRs485Params.h"

using namespace fw2::fnct::base::hw;


// usart configuration registers
// step 1 - Determmine the usart pins 
#define DEMO_MARCO_USART_RX_PORT           3      // FUNC3 - FC4_RXD_SDA_MOSI       // see sheet 4 (LPC54608_Dev_brd_schematic_Rev-D_170614.pdf)  &  Table 256 pag. 196 (UM10912 User Manual)          & SYSCON_Type struct (LPC54608.h)
#define DEMO_MARCO_USART_RX_PIN            26                               // see sheet 4 (LPC54608_Dev_brd_schematic_Rev-D_170614.pdf)  &  Table 256 pag. 196 (UM10912 User Manual)          & SYSCON_Type struct (LPC54608.h)
#define DEMO_MARCO_USART_TX_PORT           3      // FUNC3 - FC4_TXD_SCL_MISO       // see sheet 4 (LPC54608_Dev_brd_schematic_Rev-D_170614.pdf)  &  Table 256 pag. 196 (UM10912 User Manual)          & SYSCON_Type struct (LPC54608.h)
#define DEMO_MARCO_USART_TX_PIN            27                               // see sheet 4 (LPC54608_Dev_brd_schematic_Rev-D_170614.pdf)  &  Table 256 pag. 196 (UM10912 User Manual)          & SYSCON_Type struct (LPC54608.h)
// in FC4_RXD_SDA_MOSI & FC4_TXD_SCL_MISO, FC4 stands for FlexComm4 (therefore FLEXCOMM_ID is 4) 
// to detertmine REG_PTR for FLEXCOMM4 / USART4 
//      see Fig. 2 - Main Memory Map pag. 21 (UM10912 User Manual) from 0x4008 A000 to 0x4008 B000 &
//      see "LPC54608.h" at line 14186
//      to know the offset registers respect base address 0x4008 A000 about FLEXCOMM4 / USART4 - see Tab. 429 pag. 383 (UM10912 User Manual)
// to detertmine CLOCK_ATTACH see Table 118 pag. 93 (UM10912 User Manual)


// step 2 - determine usart registers based on rx/tx pins
/* see Table 118 (UM10912 User Manual)          & SYSCON_Type struct (LPC54608.h) */
#define DEMO_MARCO_USART_FLEXCOMM_ID            4                       
#define DEMO_MARCO_USART_REG_PTR                USART4                  /* see Table 422 & 429 (UM10912 User Manual)    & USART_Type struct  (LPC54608.h) */
#define DEMO_MARCO_USART_CLOCK_ATTACH           kFRO12M_to_FLEXCOMM4    /* see Table 118 & 157 (UM10912 User Manual)    & SYSCON_Type (LPC54608.h) - typedef enum _clock_attach_id (fsl_clock.h) */
#define DEMO_MARCO_USART_CLK_FREQ               CLOCK_GetFlexCommClkFreq(DEMO_MARCO_USART_FLEXCOMM_ID)
#define DEMO_MARCO_USART_IRQn                   FLEXCOMM4_IRQn          /* see Table B1-4 (**DDI0403E_e_armv7m_arm.pdf** *pg B1-525*) & typedef enum IRQn USART_Type struct  (LPC54608.h) */
#define DEMO_MARCO_USART_NVIC_PRIO              5

// step 3 - configure interrupt
// LPC54608.h
// to understand "typedef enum IRQn" & FLEXCOMM4_IRQn defined at line 106 in LPC54608 see 
//      - Table 89 (Register overview: NVIC (base address 0xE000 E000)) pag. 74 (UM10912 User Manual)
//      - Fig. 2 Main Memory Map pag. 21 (UM10912 User Manual) from 0xE000 E000 ()
//          - N.B.: The NVIC registers are located on the ARM private peripheral bus.
//      - Table 90 (Interrupt Set-Enable Register 0) ISER0 register
//      - "void (* const g_pfnVectors[])(void)" defined at line 237 of startup_lpc54608.cpp
//      - Table 88. Connection of interrupt sources to the NVIC
//      - Table B1-4 Exception numbers & Table B1-5 Vector table format pag. B1-523 (DDI0403E_e_armv7m_arm.pdf - arm = Architecture Reference Manual)
//          - /Users/work/ObsiData/repo__main/smdl/repo__prjs/smdl/mpfw/docs/nxp/lpcxpresso54608D/getting_start/micro_manuals/MPU/DDI0403E_e_armv7m_arm.pdf

//      - Figure 3-1 System address map pag. 3-14 (DDI0439B_cortex_m4_r0p0_trm.pdf - trm = Technical Reference Manual)
//          - /Users/work/ObsiData/repo__main/smdl/repo__prjs/smdl/mpfw/docs/nxp/lpcxpresso54608D/getting_start/micro_manuals/MPU/arm_cortexm4_processor_trm_100166_0001_04_en.pdf

// *********************************************
#define APP_BOARD_MARCO_TEST_SW2_PORT 0U
#define APP_BOARD_MARCO_TEST_SW2_PIN  6U

#define APP_BOARD_MARCO_TEST_LED2_PORT 3U
#define APP_BOARD_MARCO_TEST_LED2_PIN  3U

// *********************************************
#define APP_BOARD_MARCO_TEST_SW3_PORT 0U
#define APP_BOARD_MARCO_TEST_SW3_PIN  5U

#define APP_BOARD_MARCO_TEST_LED3_PORT 2U
#define APP_BOARD_MARCO_TEST_LED3_PIN  2U


/*
    peripherals list
    - USART_RX
    - USART_TX
    - LED_TEST
    - LED_A
    - LED_B
    - LED_C
    - BUTTON_UP
    - SWITCH_TST1
    - ALARM_A_OUT
    - ALARM_A_IN

    for each (peripheral) create a #define of (PORT) and (PIN)
        #define MCU_[<device id>_]<peripheral name>_PORT_PTR  <sdk referiment port pointer>
        #define MCU_[<device id>_]<peripheral name>_PORT      <sdk referiment port ID>
        #define MCU_[<device id>_]<peripheral name>_PIN       <pin ID>

*/

// *********************************************
#define APP_BOARD_MARCO_TEST_SW2_PORT 0U
#define APP_BOARD_MARCO_TEST_SW2_PIN  6U

#define APP_BOARD_MARCO_TEST_LED2_PORT 3U
#define APP_BOARD_MARCO_TEST_LED2_PIN  3U

// *********************************************
#define APP_BOARD_MARCO_TEST_SW3_PORT 0U
#define APP_BOARD_MARCO_TEST_SW3_PIN  5U

#define APP_BOARD_MARCO_TEST_LED3_PORT 2U
#define APP_BOARD_MARCO_TEST_LED3_PIN  2U



#define MCU_BUTTON_SW2_ISP2         
#define MCU_BUTTON_SW3_ISP1         
#define MCU_BUTTON_SW4_ISP0         
#define MCU_BUTTON_SW5_USER         

// #define MCU_BUTTON_SW2_ISP2_PORT_PTR             SDK_MCU_PORT_0_PTR                 // see "LPC54608_Dev_brd_schematic_Rev-D_170614.pdf"
#define MCU_BUTTON_SW2_ISP2_PORT                 APP_BOARD_MARCO_TEST_SW2_PORT      // port 0 - see "LPC54608_Dev_brd_schematic_Rev-D_170614.pdf"
#define MCU_BUTTON_SW2_ISP2_PIN                  APP_BOARD_MARCO_TEST_SW2_PIN       // pin  6 - see "LPC54608_Dev_brd_schematic_Rev-D_170614.pdf"

// #define MCU_BUTTON_SW3_ISP1_PORT_PTR             SDK_MCU_PORT_0_PTR                 // see "LPC54608_Dev_brd_schematic_Rev-D_170614.pdf"
#define MCU_BUTTON_SW3_ISP1_PORT                 APP_BOARD_MARCO_TEST_SW3_PORT      // port 0 - see "LPC54608_Dev_brd_schematic_Rev-D_170614.pdf"
#define MCU_BUTTON_SW3_ISP1_PIN                  APP_BOARD_MARCO_TEST_SW3_PIN       // pin  5 - see "LPC54608_Dev_brd_schematic_Rev-D_170614.pdf"

// #define MCU_BUTTON_SW4_ISP0_PORT_PTR             SDK_MCU_PORT_0_PTR
#define MCU_BUTTON_SW4_ISP0_PORT                 0
#define MCU_BUTTON_SW4_ISP0_PIN                  4

// #define MCU_BUTTON_SW5_USER_PORT_PTR             SDK_MCU_PORT_1_PTR
#define MCU_BUTTON_SW5_USER_PORT                 1
#define MCU_BUTTON_SW5_USER_PIN                  1


#define MCU_LED_LED1_D12
#define MCU_LED_LED2_D11
#define MCU_LED_LED3_D9 


// #define MCU_LED_LED1_D12_PORT_PTR                SDK_MCU_PORT_3_PTR                 // see  "LPC54608_Dev_brd_schematic_Rev-D_170614.pdf"
#define MCU_LED_LED1_D12_PORT                    3U                 // see  "LPC54608_Dev_brd_schematic_Rev-D_170614.pdf"
#define MCU_LED_LED1_D12_PIN                     14U                // see  "LPC54608_Dev_brd_schematic_Rev-D_170614.pdf"

// #define MCU_LED_LED2_D11_PORT_PTR                SDK_MCU_PORT_3_PTR                 // see  "LPC54608_Dev_brd_schematic_Rev-D_170614.pdf"
#define MCU_LED_LED2_D11_PORT                    APP_BOARD_MARCO_TEST_LED2_PORT     // see  "LPC54608_Dev_brd_schematic_Rev-D_170614.pdf"
#define MCU_LED_LED2_D11_PIN                     APP_BOARD_MARCO_TEST_LED2_PIN      // see  "LPC54608_Dev_brd_schematic_Rev-D_170614.pdf"

// #define MCU_LED_LED3_D9_PORT_PTR                 SDK_MCU_PORT_2_PTR                 // see  "LPC54608_Dev_brd_schematic_Rev-D_170614.pdf"
#define MCU_LED_LED3_D9_PORT                     APP_BOARD_MARCO_TEST_LED3_PORT     // see  "LPC54608_Dev_brd_schematic_Rev-D_170614.pdf"
#define MCU_LED_LED3_D9_PIN                      APP_BOARD_MARCO_TEST_LED3_PIN      // see  "LPC54608_Dev_brd_schematic_Rev-D_170614.pdf"


#define ICON_FUNC_03            IOCON_PIO_FUNC3
#define USART_RX_PIN            DEMO_MARCO_USART_RX_PIN         // 26
#define USART_RX_PORT           DEMO_MARCO_USART_RX_PORT        // 3
#define USART_TX_PIN            DEMO_MARCO_USART_TX_PIN         // 27
#define USART_TX_PORT           DEMO_MARCO_USART_TX_PORT        // 3
#define USART4_RS485_EN         true                            // true
#define RS485_RE_PIN            APP_BOARD_MARCO_TEST_LED3_PIN   // 2
#define RS485_RE_PORT           APP_BOARD_MARCO_TEST_LED3_PORT  // 2
#define RS485_DE_PIN            APP_BOARD_MARCO_TEST_LED2_PIN   // 3
#define RS485_DE_PORT           APP_BOARD_MARCO_TEST_LED2_PORT  // 3

// ***********


// class hw0UsartRs485ParamsReal_t: public hw0UsartRs485Params_t {
// 
//     public:
//         void    clrTxEnablePin      (void) override;
//         void    setRxEnablePin      (void) override;
//         void    setTxEnablePin      (void) override;
//         void    clrRxEnablePin      (void) override;
// 
// 
// };

#define MCU_USART_1_REAL
#define MCU_USART_2_REAL

#define HW_USART_INIT_PARAMS_DEF    {   \
                                         DEMO_MARCO_USART_FLEXCOMM_ID    \
                                        ,DEMO_MARCO_USART_REG_PTR        \
                                        ,DEMO_MARCO_USART_CLOCK_ATTACH   \
                                        ,DEMO_MARCO_USART_IRQn           \
                                        ,DEMO_MARCO_USART_NVIC_PRIO      \
                                        ,ICON_FUNC_03                    \
                                        ,USART_RX_PIN                    \
                                        ,USART_RX_PORT                   \
                                        ,USART_TX_PIN                    \
                                        ,USART_TX_PORT                   \
                                        ,USART4_RS485_EN                 \
                                        ,RS485_RE_PIN                    \
                                        ,RS485_RE_PORT                   \
                                        ,RS485_DE_PIN                    \
                                        ,RS485_DE_PORT                   \
                                    }

#define HW_USART_R_INIT_PARAMS_DEF    HW_USART_INIT_PARAMS_DEF
// #include "mcuComCh_rUsartInitParams.h"
// extern mcuComCh_rUsartInitParams_t glo_usart_v_Params_2Real;
// #define HW_USART_V_INIT_PARAMS_DEF    { &glo_usart_v_Params_2Real }
#define HW_USART_V_INIT_PARAMS_DEF    HW_USART_INIT_PARAMS_DEF

#endif 	// APP_MCU_PIN_PORT_DEFINE_CONFIG_H
