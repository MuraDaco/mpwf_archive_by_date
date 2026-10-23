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
 * mcuPinPort.h
 *
 *  Created on: Mar, 6th 2026 (Fri)
 *      Author: Marco Dau
 */


#ifndef MCU_PIN_PORT_H
#define MCU_PIN_PORT_H

#include "hw0GpioDgIntfc.h"

// ****************************************************
// section start **** CLASS DEFINITION *****

class mcuPinPort_t :    public     hw0GpioDgIntfc_t    // (all platforms)     - component interface
{

// ****************************************************
// section start **** CONSTRUCTOR *****
    public:

        mcuPinPort_t  (uint8_t  p_port,    uint8_t p_pin, uint8_t p_dir);

    // section end   **** CONSTRUCTOR ***** 
    // ****************************************************
    // --------------------------
// ****************************************************
// section start **** PIN PORT MANAGEMENT *****

    public:

        uint32_t     pinRead         (void)                                                         override;
        void         pinWrite        (uint8_t p_status)                                             override;
        void         pinInit_Step1   (void)                                                         override;
        void         pinInit_Step2   (void)                                                         override;

        // void    pinConfig   (uint8_t  p_Port,      uint8_t p_pin, gpio_config_struct_t& p_config)   ; // override;
        void    setHigh     (void)                                                                  override;
        void    setLow      (void)                                                                  override;
        void    tglPin      (void)                                                                  override;
        void    setPin      (bool p_state)                                                          override;
        bool    getPin      (void)                                                                  override;

    protected:
        volatile uint8_t* g_ptrPort;
        uint8_t g_port;
        uint8_t g_pin;

        uint8_t g_dir;

        gpio_config_struct_t g_config;
        uint8_t g_valuePinOld;
        bool    g_valueModified;
        
    private:

    // section end   **** PIN PORT MANAGEMENT *****
    // ****************************************************
    // --------------------------



};


#endif 	// MCU_PIN_PORT_H
