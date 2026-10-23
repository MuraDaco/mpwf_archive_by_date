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
 * hw0GpioIntfc.h
 *
 *  Created on: Mar,  6th 2026 (Fri)
 *      Author: Marco Dau
 */


#ifndef     HW_0_GPIO_INTFC_H
#define     HW_0_GPIO_INTFC_H

#include <cstdint>


// ****************************************************
// section start **** NAMESPACE DEFINITION *****

namespace hw0GpioIntfc_ns
{

// ****************************************************
// section start **** ENUMs DEFINITIONs *****
    // public:

        enum k_typePort_t   {
             k_typePort_digital
            ,k_typePort_analog
            ,k_typePort_usart
            ,k_typePort_spi
            ,k_typePort_i2c
        };

        enum k_modePort_t: uint8_t   {
             k_modePort_input
            ,k_modePort_output
            ,k_modePort_data
            ,k_modePort_clck
        };

    // section end   **** ENUMs DEFINITIONs ***** 
    // ****************************************************
    // --------------------------
// ****************************************************
// section start **** TYPEs DEFINITIONs *****
    // public:

        typedef struct gpio_config_struct
        {
            k_typePort_t type;
            k_modePort_t mode;
        } gpio_config_struct_t;

    // section end   **** TYPEs DEFINITIONs ***** 
    // ****************************************************
    // --------------------------

};  // end of namespace hw0GpioIntfc_ns

using namespace hw0GpioIntfc_ns;

// ****************************************************
// section start **** CLASS DEFINITION *****

class hw0GpioIntfc_t  {
// ****************************************************
// section start **** CONSTANTs DEFINITIONs *****

    public:
        static constexpr gpio_config_struct_t din       = {k_typePort_digital ,k_modePort_input  };
        static constexpr gpio_config_struct_t dout      = {k_typePort_digital ,k_modePort_output };
        static constexpr gpio_config_struct_t ain       = {k_typePort_analog  ,k_modePort_input  };
        static constexpr gpio_config_struct_t aout      = {k_typePort_analog  ,k_modePort_output };

        static constexpr gpio_config_struct_t usart_rx  = {k_typePort_usart   ,k_modePort_input  };
        static constexpr gpio_config_struct_t usart_tx  = {k_typePort_usart   ,k_modePort_output };
        static constexpr gpio_config_struct_t spi_data  = {k_typePort_spi     ,k_modePort_data };
        static constexpr gpio_config_struct_t spi_clck  = {k_typePort_spi     ,k_modePort_clck };
        static constexpr gpio_config_struct_t i2c_data  = {k_typePort_i2c     ,k_modePort_data };
        static constexpr gpio_config_struct_t i2c_clck  = {k_typePort_i2c     ,k_modePort_clck };

    // section end   **** CONSTANTs DEFINITIONs ***** 
    // ****************************************************
    // --------------------------

};  // end of class hw0GpioIntfc_t


#endif  //  HW_0_GPIO_INTFC_H
