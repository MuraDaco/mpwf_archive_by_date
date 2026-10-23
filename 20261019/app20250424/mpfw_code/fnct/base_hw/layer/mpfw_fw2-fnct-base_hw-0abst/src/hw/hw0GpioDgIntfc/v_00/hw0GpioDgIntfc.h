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
 * hw0GpioDgIntfc.h
 *
 *  Created on: Mar,  9th 2026 (Mon)
 *      Author: Marco Dau
 */


#ifndef     HW_0_GPIO_DG_INTFC_H
#define     HW_0_GPIO_DG_INTFC_H

#include <cstdint>

#include "hw0GpioIntfc.h"
// using namespace hw0GpioIntfc_ns;
// ****************************************************
// section start **** CLASS DEFINITION *****

class hw0GpioDgIntfc_t
{

// ****************************************************
// section start **** TYPEs DEFINITIONs *****
    public:

        typedef struct gpio_base_struct
        {
            uint8_t     mcuId;
            uint8_t     port;
            uint8_t     pin;
            const gpio_config_struct_t& config;
        } gpio_base_struct_t;

        typedef struct gpio_conf2_struct
        {
            uint8_t*    ptrPort;
            uint8_t     pin;
        } gpio_config2_struct_t;

        typedef struct gpio_conf3_struct
        {
            uint8_t     mcuId;
            uint8_t     port;
            uint8_t     pin;
        } gpio_config3_struct_t;

    // section end   **** TYPEs DEFINITIONs ***** 
    // ****************************************************
    // --------------------------
// ****************************************************
// section start **** PIN PORT MANAGEMENT *****

    public:
        static uint32_t     pinRead         (uint8_t  p_port,      uint32_t p_pin)                      ;
        static void         pinWrite        (uint8_t  p_Port,      uint32_t p_pin, uint8_t p_status)    ;

        virtual uint32_t    pinRead         (void) {return 0;}                              ;
        virtual void        pinWrite        ([[maybe_unused]] uint8_t p_status) {}          ;
        virtual void        pinInit         (void) {}                                       ;
        virtual void        pinInit_Step1   (void) {}                                       ;
        virtual void        pinInit_Step2   (void) {}                                       ;

        virtual void        pinConfig       ([[maybe_unused]] uint8_t  p_Port,      [[maybe_unused]] uint8_t p_pin, [[maybe_unused]] gpio_config_struct_t& p_config) {};
        virtual void        setHigh         (void)                                                                  = 0;
        virtual void        setLow          (void)                                                                  = 0;
        virtual void        tglPin          (void)                                                                  = 0;
        virtual void        setPin          (bool p_state)                                                          = 0;
        virtual bool        getPin          (void)                                                                  = 0;

    // section end   **** PIN PORT MANAGEMENT *****
    // ****************************************************
    // --------------------------
//    // ****************************************************
//    // section start **** DISPLAY  *****
//    
//        public:
//            virtual fmt_str_t* getPinStatusFormattedString(void) = 0;
//            virtual bool update (void) = 0;
//    
//        // section end   **** DISPLAY *****
//        // ****************************************************
//        // --------------------------



};


#endif  //  HW_0_GPIO_DG_INTFC_H
