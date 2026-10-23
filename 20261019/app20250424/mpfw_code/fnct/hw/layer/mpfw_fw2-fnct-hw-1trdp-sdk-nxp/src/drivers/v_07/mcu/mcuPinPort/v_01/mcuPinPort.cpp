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
 * mcuPinPort.cpp
 *
 *  Created on: Jun, 27 2024
 *      Author: Marco Dau
 */

#include "mcuPinPort.h"

#include "fsl_gpio.h"
#include "fsl_iocon.h"
#include "pin_mux.h"


// ****************************************************
// section start **** MACRO DEFINEs *****


    #define pinSet          g_ptrPort[g_pin] = 1
    #define pinClr          g_ptrPort[g_pin] = 0
    #define pinTst          g_ptrPort[g_pin]
    #define pinTgl          g_ptrPort[g_pin] = pinTst ? 0 : 1

    #define PIN_SET         GPIO->SET[g_port] = (1 << g_pin)    // g_ptrPortArray[g_port] = g_ptrPortArray[g_port] |  (1 << g_pin)
    #define PIN_CLR         GPIO->CLR[g_port] = (1 << g_pin)    // g_ptrPortArray[g_port] = g_ptrPortArray[g_port] & ~(1 << g_pin)

    // section end   **** ENUMs DEFINITIONs ***** 
    // ****************************************************
    // --------------------------

// ****************************************************
// section start **** CONSTRUCTOR *****

    mcuPinPort_t::mcuPinPort_t(                 uint8_t  p_port, uint8_t p_pin, uint8_t p_dir) :
         g_ptrPort      { GPIO->B[p_port]   }
        ,g_port         { p_port            }
        ,g_pin          { p_pin             }
        ,g_dir          { p_dir          }
    {}


    // section end   **** CONSTRUCTOR ***** 
    // ****************************************************
    // --------------------------
// ****************************************************
// section start **** PIN PORT MANAGEMENT *****

    // public:

//        uint32_t hw0GpioDgIntfc_t::pinRead   (uint8_t p_port, uint32_t p_pin)    {
//            return GPIO_PinRead(GPIO, p_port, p_pin);
//        }
//
//        void hw0GpioDgIntfc_t::pinWrite  (uint8_t  p_Port, uint32_t p_pin, uint8_t p_status) {
//            GPIO_PinWrite(GPIO, p_Port, p_pin, p_status);
//        }

        uint32_t mcuPinPort_t::pinRead   (void)    {
            return GPIO_PinRead(GPIO, g_port, g_pin);
        }

        void mcuPinPort_t::pinWrite  (uint8_t p_status) {
            GPIO_PinWrite(GPIO, g_port, g_pin, p_status);
        }

        void mcuPinPort_t::pinInit_Step1   (void)    {
            const uint32_t digital_io_port_config = (/* Pin is configured as PIO */
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

            IOCON_PinMuxSet(IOCON, g_port, g_pin, digital_io_port_config);

            GPIO_PortInit(GPIO, g_port );
        }

        void mcuPinPort_t::pinInit_Step2   (void)    {
            
            
            if(k_modePort_output == g_dir)  {
                // Define the init structure for the output pin
                gpio_pin_config_t out_config = {
                    kGPIO_DigitalOutput,
                    1                       // Set default output value
                };

                GPIO_PinInit (GPIO, g_port, g_pin, &out_config);

            } else {
                // Define the init structure for the output pin
                gpio_pin_config_t in_config = {
                    kGPIO_DigitalInput,
                    0                       // this value is not used
                };

                GPIO_PinInit (GPIO, g_port, g_pin, &in_config);
            }
            
        }

//         void mcuPinPort_t::pinConfig ([[maybe_unused]] uint8_t  p_Port,      [[maybe_unused]] uint8_t p_pin, gpio_config_struct_t& p_config)    {
//             g_config.type = p_config.type;
//             g_config.mode = p_config.mode;
//         }

        void mcuPinPort_t::setHigh        (void)    {
            if(k_modePort_output == g_dir)
                pinSet;
        }

        void mcuPinPort_t::setLow         (void)    {
            if(k_modePort_output == g_dir)
                pinClr;
        }

        void mcuPinPort_t::tglPin       (void)  {
            if(pinTst)  {
                pinClr;
                g_valuePinOld = 0;
            }
            else    {
                pinSet;
                g_valuePinOld = 1;
            }
            g_valueModified = true;
        }

        void mcuPinPort_t::setPin       (bool p_state)  {
            if(p_state) {
                pinSet;
                g_valuePinOld = 1;
            }
            else    {
                pinClr;
                g_valuePinOld = 0;
            }
        }

        bool mcuPinPort_t::getPin       (void)    {
            g_valuePinOld = pinTst;
            if(pinTst)  {
                g_valuePinOld = 1;
            }
            else    {
                g_valuePinOld = 0;
            }
            return pinTst;
        }

    // section end   **** PIN PORT MANAGEMENT *****
    // ****************************************************
    // --------------------------
