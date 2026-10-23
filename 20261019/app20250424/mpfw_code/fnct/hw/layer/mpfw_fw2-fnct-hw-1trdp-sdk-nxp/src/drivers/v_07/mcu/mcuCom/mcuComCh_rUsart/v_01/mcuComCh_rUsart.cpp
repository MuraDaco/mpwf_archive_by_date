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
 * mcuComCh_rUsart.cpp
 *
 *  Created on: Ago, 31st 2026  (Mon)
 *      Author: Marco Dau
 */

#include "mcuComCh_rUsart.h"

#include "fsl_usart.h"

#include "pin_mux.h"
#include "fsl_iocon.h"
#include "fsl_gpio.h"
#include "clock_config.h"

// ****************************************************
// section start **** CONSTRUCTOR *****

    mcuComCh_rUsart_t::mcuComCh_rUsart_t(mcuComCh_rUsartInitParams_t* p_pConfig) :
         g_pConfig           {p_pConfig}
        ,g_pUsartRegs        {p_pConfig->register_ptr}
    {}

    mcuComCh_rUsart_t::mcuComCh_rUsart_t(mcuComCh_vUsartInitParams_t* p_pConfig) :
         g_pConfig           {reinterpret_cast<mcuComCh_rUsartInitParams_t*>(p_pConfig)}
        ,g_pUsartRegs        {p_pConfig->register_ptr}
    {}


    // section end   **** CONSTRUCTOR ***** 
    // ****************************************************
    // --------------------------

#define UNUSED(X) (void)X      // To avoid gcc/g++ warnings

// general
    bool    mcuComCh_rUsart_t::chkInterruptsRaised     (void)    {
        return  (
                    (0U != (g_pUsartRegs->FIFOSTAT & USART_FIFOSTAT_RXNOTEMPTY_MASK))       // RX INTERRUPT
                ||  (0U != (g_pUsartRegs->FIFOSTAT & USART_FIFOSTAT_RXERR_MASK))            // RX INTERRUPT overrun error
                ||  (0U != (g_pUsartRegs->FIFOSTAT & USART_FIFOSTAT_TXNOTFULL_MASK) )       // TX INTERRUPT
                ||  (                                                                       // TX INTERRUPT last byte completely sent
                        ( 0U != (g_pUsartRegs->INTENSET & USART_INTENSET_TXIDLEEN_MASK) )
                    &&  ( 0U != (g_pUsartRegs->INTSTAT  & USART_INTSTAT_TXIDLE_MASK)    )
                )
        );
    }

// transmit
    bool    mcuComCh_rUsart_t::tx_chkInterruptRaised   (void)                         {
        return (
                    (0 != (g_pUsartRegs->FIFOSTAT & USART_FIFOSTAT_TXNOTFULL_MASK))         // TX INTERRUPT
                ||  (                                                                       // TX INTERRUPT last byte completely sent
                        ( 0U != (g_pUsartRegs->INTENSET & USART_INTENSET_TXIDLEEN_MASK) )
                    &&  ( 0U != (g_pUsartRegs->INTSTAT  & USART_INTSTAT_TXIDLE_MASK)    )
                )
        );
    }

    // ******************
    // It is called in an "application thread/routine" when the user has to send a packet 
    // therefore when the buffer status is set to "init"
    void    mcuComCh_rUsart_t::tx_eventBegin           (void)                         {
        // case "virtual"
        //      . do nothing
        //          N.B.: the interrupt routine is simulated by a "loop" routine (vhwLoop) and it is always performed at every "main" cycle
        // case "real"
        //      1. enable tx interrupt
        //      2. set tx-enable pin (automatically clear rx-enable pin) (Rs485 config)
        g_pUsartRegs->FIFOINTENSET |= USART_FIFOINTENSET_TXLVL_MASK;
        setTxEnablePin();    // in "virtual" case it doesn't any
    }

    // ******************
    // It is called in an "interrupt thread/routine" when the buffer status is set to "tx running" (from "init" status)
    void    mcuComCh_rUsart_t::tx_eventFirstData       (void)                         {
        //  "virtual" case: 
        //      1. lock the channel setting [writerPid] parameter; you can think it as the tx interrupt enable and, at the same time, the signal/trigger of the rx interrupt
        //         this event has to be called from the interrupt thread to manage the shared memory in the inter-process comunication
        //         N.B.: the channel can be locked (update the [writerPid] parameter) in a safe manner only in the [vhwLoop]/[simulated_interrupt] routine 
        //               because the vhwLopp routine is performed inside the "shared memory time slot" of the its own process
        //  "real" case:    do nothing
    }


    // ******************
    // It is called in an "interrupt thread/routine" when the buffer status is "tx running"
    void    mcuComCh_rUsart_t::tx_eventSendData        (uint8_t p_data)         {
        //  "virtual" case: 
        //      write to the shared memory buffer, the buffer that is shared with other processes (N.B.: not threads but processes)) 
        //  "real" case: 
        //      write to the mcu usart register
        g_pUsartRegs->FIFOWR = p_data;
    }

    // ******************
    // It is called in an "interrupt thread/routine" when the buffer status is set to "waiting_last_byte_send"/"idle" (from "running" status)
    // N.B.: the buffer status is set to "waiting_last_byte_send" when the parsing of the packet by a protocol procedure detects the end of packet
    void    mcuComCh_rUsart_t::tx_eventLastData        (void)                         {
        //  "virtual" case: do nothing
        //  "real" case: 
        //      1. disable tx "interrupt buffer"
        //      2. enable  tx "interrupt idle"/"last byte completely sent"
        // DIS-able tx interrupt
        g_pUsartRegs->FIFOINTENCLR = USART_FIFOINTENCLR_TXLVL_MASK;
        // EN-able "last byte completely sent"/"tx idle" interrupt
        g_pUsartRegs->INTENSET |= USART_INTENSET_TXIDLEEN_MASK;
    }

    // It is called in an "interrupt thread/routine" when the "last byte has been completely sent" or error is detected
    // when "last byte has been completely sent" event happens the buffer status is set to "free" 
    // when error is detected the buffer status is set to "tx error"
    void    mcuComCh_rUsart_t::tx_eventEnd             (void)                         {
        // the last byte has just been completely sent

        //  "virtual" case: 
        //      . un-lock the channel/shared memory buffer
        //  "real" case: 
        // DIS-able tx interrupt
        g_pUsartRegs->FIFOINTENCLR = USART_FIFOINTENCLR_TXLVL_MASK;
        //      . DIS-able "last byte completely sent"/"tx idle" interrupt
        g_pUsartRegs->INTENCLR |= USART_INTENCLR_TXIDLECLR_MASK;
    }

// receive
    bool    mcuComCh_rUsart_t::rx_chkInterruptRaised     (void)    {
        return  (
                    (0U != (g_pUsartRegs->FIFOSTAT & USART_FIFOSTAT_RXNOTEMPTY_MASK))       // RX INTERRUPT
                ||  (0U != (g_pUsartRegs->FIFOSTAT & USART_FIFOSTAT_RXERR_MASK))            // RX INTERRUPT overrun error
                );
    }

    bool    mcuComCh_rUsart_t::rx_chkError_overrun   (void)                         {
        return (0U != (g_pUsartRegs->FIFOSTAT & USART_FIFOSTAT_RXERR_MASK));            // RX INTERRUPT overrun error
    }

    // It is called in an "application thread/routine" when the user makes ready to receive a packet 
    // therefore when the buffer status is set to "waiting to receive a packet"
    void    mcuComCh_rUsart_t::rx_eventBegin           (void)                         {
        // "virtual" case:  
        //      . do nothing
        //      . it is not necessary to enable the "rx interrupt" because the "interrupt thread/routine" is always performed
        // "real" case:     
        //      1. enable rx interrupt
        //      2. set rx-enable pin (automatically clear tx-enable pin)
        // Enable receiver interrupt.
        g_pUsartRegs->FIFOINTENSET |= USART_FIFOINTENSET_RXLVL_MASK;
        setRxEnablePin();    // rs485 channel: enable rx (automatically disable tx)
    }

    // It is called in an "interrupt thread/routine" when the buffer status is "rx running"
    uint8_t    mcuComCh_rUsart_t::rx_eventReceiveData     (void)                         {
        //  "virtual" case: 
        //      . read from the shared memory buffer, the buffer that is shared with other processes (N.B.: not threads but processes)) 
        //  "real" case: 
        //      . read from the mcu usart register
        return g_pUsartRegs->FIFORD;
    }

    // It is called in an "interrupt thread/routine" when the "last byte has been received" or error is detected
    // when the last byte is received the buffer status is set to "rx completed" 
    // when error is detected the buffer status is set to "rx error"
    // 
    void    mcuComCh_rUsart_t::rx_eventEnd             (void)                         {
        // "virtual" case:
        //      . do nothing
        // "real" case:     
        //      1. DIS-able rx interrupt
        g_pUsartRegs->FIFOINTENCLR = USART_FIFOINTENCLR_RXLVL_MASK | USART_FIFOINTENSET_RXERR_MASK;
    }


    void    mcuComCh_rUsart_t::setTxEnablePin      (void) {
        if(g_pConfig->rs485_enabled) {
            GPIO_PinWrite(GPIO, g_pConfig->DE_port, g_pConfig->DE_pin, 1);
            GPIO_PinWrite(GPIO, g_pConfig->RE_port, g_pConfig->RE_pin, 1);
        }
    }

    void    mcuComCh_rUsart_t::clrTxEnablePin      (void) {
        setRxEnablePin();
    }

    void    mcuComCh_rUsart_t::setRxEnablePin      (void) {
        if(g_pConfig->rs485_enabled) {
            GPIO_PinWrite(GPIO, g_pConfig->DE_port, g_pConfig->DE_pin, 0);
            GPIO_PinWrite(GPIO, g_pConfig->RE_port, g_pConfig->RE_pin, 0);
        }
    }

    void    mcuComCh_rUsart_t::clrRxEnablePin      (void) {
        setTxEnablePin();
    }

// *****

    void mcuComCh_rUsart_t::mcuInit_step1 (void)        {
        // CLOCK_AttachClk(kFRO12M_to_FLEXCOMM4);
        // RESET_PeripheralReset(kFC4_RST_SHIFT_RSTn);

        BOARD_BootClockPLL180M();
//        CLOCK_AttachClk(g_pConfig->clock_attach);
        // - step 1
        //      - configuring pins: tx, rx, rs485-enable-tx, rs485-enable-rx
        InitPins_IOCON();   // (see Table Table 256 pag. 196 [UM10912_LPC546xx_User_Manual.pdf])
    }

    void mcuComCh_rUsart_t::mcuInit_step2 (void)        {

        InitPins_GPIO();    // (see Table Table 283 pag. 234 [UM10912_LPC546xx_User_Manual.pdf])

        // - step 2
        //      - configuring UART module

        // - step 2.1.a
        //      - load default configuration
        //
        // config.baudRate_Bps = 115200U;
        // config.parityMode = kUSART_ParityDisabled;
        // config.stopBitCount = kUSART_OneStopBit;
        // config.loopback = false;
        // config.enableTx = false;
        // config.enableRx = false;
        //
        usart_config_t config;
        USART_GetDefaultConfig(&config);
        // - step 2.1.b
        //      - default configuration customization
        config.baudRate_Bps = 9600;
        config.enableTx     = true;
        config.enableRx     = true;


        // - step 2.2
        //      - enabling and configuring UART
        // - step 2.2.a 
        //      - attach 12 MHz clock to FLEXCOMM4 (USART)
        // . CLOCK_AttachClk
        //      . input
        //          - typedef enum _clock_attach_id / clock_attach_id_t in fsl_clock.h
        //      . register
        //          - SYSCON->MAINCLKSELA / SYSCON->FCLKSEL4 (see Table Table 118 & 157 [UM10912_LPC546xx_User_Manual.pdf])
        CLOCK_AttachClk(g_pConfig->clock_attach);

        // - step 2.2.b 
        //      - enable clock and reset/start UART
        //      - set UART registers based on configuration previously set
        // . CLOCK_EnableClock(s_flexcommClocks[idx]); 
        //      . input 
        //          - typedef enum _clock_ip_name" in fsl_clock.h
        //      . register
        //          - SYSCON->AHBCLKCTRLSET register (see Table Table 118 & 140 [UM10912_LPC546xx_User_Manual.pdf])
        // . RESET_PeripheralReset(s_flexcommResets[idx]);
        //      . input:
        //          - typedef enum _SYSCON_RSTn in fsl_reset.h
        //      . register
        //          - SYSCON->PRESETCTRL / SYSCON->PRESETCTRLSET / SYSCON->PRESETCTRLCLR (see Table Table 118 & 130 [UM10912_LPC546xx_User_Manual.pdf])
        uint32_t l_clock_freq = CLOCK_GetFlexCommClkFreq(g_pConfig->flexcomm_id);
        USART_Init(g_pConfig->register_ptr, &config, l_clock_freq  );

        uint8_t l_str[] = "**.** 2026.04.06_15:44 - Init uart message test **";

        USART_WriteBlocking(g_pConfig->register_ptr, l_str, sizeof(l_str) - 1);
        // - step 2.2.c
        //      - enabling and configuring interrupt UART to use a no-blocking tx-rx procedures
        //
        //      - set priority interrupt 
        //  . NVIC_SetPriority
        //      . inputs
        //          - typedef enum IRQn / IRQn_Type in LPC54608.h
        //          - integer in the range of 0...7 (0 max priority / 7 min priority)
        //      . register
        //          - NVIC->IP regiter (see Table 89 & 104 [UM10912_LPC546xx_User_Manual.pdf])
        NVIC_SetPriority(g_pConfig->irq_n, g_pConfig->nvic_priority);

        //      - set handler of the interrupt
        //          - hang the "USART_TransferHandleIRQ" function (fsl_uasart.c) to "FLEXCOMM0_DriverIRQHandler" function (fsl_flexcomm.c)
        //          - N.B.: "FLEXCOMM0_DriverIRQHandler" is called by "FLEXCOMM0_IRQHandler" function (startup_lpc54608.cpp)
        //          - see Table 88 in [UM10912_LPC546xx_User_Manual.pdf] & Table B1-4 in [DDI0403E_e_armv7m_arm.pdf]
        // . EnableIRQ
        //      . input
        //          - typedef enum IRQn / IRQn_Type in LPC54608.h
        //      . register
        //          - NVIC->ISER register (see Table 89 & 90 [UM10912_LPC546xx_User_Manual.pdf])

        (void)EnableIRQ(FLEXCOMM4_IRQn);

    }

    void mcuComCh_rUsart_t::InitPins_IOCON (void)      {
    
        /* Enables the clock for the IOCON block. 0 = Disable; 1 = Enable.: 0x01u */
        CLOCK_EnableClock(kCLOCK_Iocon);
    
        // *********************************************************************************************************
        // usart4 RX & TX pin configuration
        const uint32_t iocon_usart_config = (/* Pin is configured as FC4_RXD_SDA_MOSI */
                                             g_pConfig->icon_func |              
                                             /* No addition pin function */
                                             IOCON_PIO_MODE_INACT |
                                             /* Input function is not inverted */
                                             IOCON_PIO_INV_DI |
                                             /* Enables digital function */
                                             IOCON_PIO_DIGITAL_EN |
                                             /* Input filter disabled */
                                             IOCON_PIO_INPFILT_OFF |
                                             /* Standard mode, output slew rate control is enabled */
                                             IOCON_PIO_SLEW_STANDARD |
                                             /* Open drain is disabled */
                                             IOCON_PIO_OPENDRAIN_DI);
        /* PORT0 PIN29 (coords: K5) is configured as FC4_RXD_SDA_MOSI */
        // IOCON_PinMuxSet(IOCON, g_pConfig->rx_port, g_pConfig->rx_pin, iocon_usart_config);
        IOCON_PinMuxSet(IOCON, g_pConfig->rx_port, g_pConfig->rx_pin, iocon_usart_config);
        // IOCON_PinMuxSet(IOCON, g_pConfig->tx_port, g_pConfig->tx_pin, iocon_usart_config);
        IOCON_PinMuxSet(IOCON, g_pConfig->tx_port, g_pConfig->tx_pin, iocon_usart_config);
    
    
        // *********************************************************************************************************

        
        if(g_pConfig->rs485_enabled) {
            const uint32_t iocon_rs485_config = (/* Pin is configured as digital PIN */
                                                IOCON_PIO_FUNC0 |
                                                /* Selects pull-up function */
                                                IOCON_PIO_MODE_PULLUP |
                                                /* Input function is not inverted */
                                                IOCON_PIO_INV_DI |
                                                /* Enables digital function */
                                                IOCON_PIO_DIGITAL_EN |
                                                /* Input filter disabled */
                                                IOCON_PIO_INPFILT_OFF |
                                                /* Standard mode, output slew rate control is enabled */
                                                IOCON_PIO_SLEW_STANDARD |
                                                /* Open drain is disabled */
                                                IOCON_PIO_OPENDRAIN_DI);
            // pin to drive led 2 & max 485-DE
            /* PORT3 PIN3 (coords: A13) is configured as PIO3_3 */
            IOCON_PinMuxSet(IOCON, g_pConfig->DE_port, g_pConfig->DE_pin, iocon_rs485_config);
            // pin to drive led 3 & max 485-RE
            /* PORT3 PIN3 (coords: C3) is configured as PIO3_3 */
            IOCON_PinMuxSet(IOCON, g_pConfig->RE_port, g_pConfig->RE_pin, iocon_rs485_config);

            // enable clock & reset peripheral according with the compile time definitions
            GPIO_PortInit(GPIO, g_pConfig->DE_port);
            GPIO_PortInit(GPIO, g_pConfig->RE_port);
        }
    
   
    }

    void mcuComCh_rUsart_t::InitPins_GPIO    (void)      {

        if(g_pConfig->rs485_enabled) {

            /* Define the init structure for the output LED pin*/
            gpio_pin_config_t out_config = {
                kGPIO_DigitalOutput,
                0,
            };

            GPIO_PinInit (GPIO, g_pConfig->DE_port, g_pConfig->DE_pin, &out_config);
            GPIO_PinInit (GPIO, g_pConfig->RE_port, g_pConfig->RE_pin, &out_config);

            // rs485 tx enable & rs485 rx disable
            setTxEnablePin();
        }
    }
