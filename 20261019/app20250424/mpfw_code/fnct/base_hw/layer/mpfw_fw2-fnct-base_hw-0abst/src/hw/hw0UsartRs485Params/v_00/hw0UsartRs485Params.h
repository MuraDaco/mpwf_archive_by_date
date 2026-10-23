//  *******************************************************************************
//  
//  mpfw / fw2 - Multi Platform FirmWare FrameWork 
//      library that contains the essential code that is used in every application
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
 * hw0UsartRs485Params.h
 *
 *  Created on: Feb, 16 2026 (Mon)
 *      Author: Marco Dau
 */

#ifndef     HW_0_USART_RS485_PARAMS_H
#define     HW_0_USART_RS485_PARAMS_H

#include <cstddef>
#include <cstdint>

namespace fw2 { namespace fnct { namespace base { namespace hw {



class hw0UsartRs485Params_t {

    public:
        virtual void    setTxEnablePin      (void)  = 0;
        virtual void    clrTxEnablePin      (void)  = 0;
        virtual void    setRxEnablePin      (void)  = 0;
        virtual void    clrRxEnablePin      (void)  = 0;

};

}   }   }   }   // fw2::fnct::base::hw

#endif  //  HW_0_USART_RS485_PARAMS_H