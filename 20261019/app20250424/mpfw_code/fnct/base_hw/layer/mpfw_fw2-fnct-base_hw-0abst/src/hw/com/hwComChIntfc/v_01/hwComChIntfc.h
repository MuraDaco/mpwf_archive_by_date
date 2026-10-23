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
 * hwComChIntfc.h
 *
 *  Created on: Sep, 1st 2026 (Tue)
 *      Author: Marco Dau
 */

#ifndef     HW_COM_CH_INTFC_H
#define     HW_COM_CH_INTFC_H

#include <cstddef>
#include <cstdint>

namespace fw2 { namespace fnct { namespace base { namespace hw {

class hwComChIntfc_t {

    public:
        // general
        virtual bool    chkInterruptsRaised     (void)            = 0;
        // transmit
        virtual bool    tx_chkInterruptRaised   (void)            = 0;
        virtual void    tx_eventBegin           (void)            = 0;
        virtual void    tx_eventFirstData       (void)            = 0;
        virtual void    tx_eventSendData        (uint8_t p_data)  = 0;
        virtual void    tx_eventLastData        (void)            = 0;
        virtual void    tx_eventEnd             (void)            = 0;

        // receive
        virtual bool    rx_chkInterruptRaised   (void)            = 0;
        virtual bool    rx_chkError_overrun     (void)            = 0;
        virtual void    rx_eventBegin           (void)            = 0;
        virtual uint8_t rx_eventReceiveData     (void)            = 0;
        virtual void    rx_eventEnd             (void)            = 0;



};

}   }   }   }   // fw2::fnct::base::hw

#endif  //  HW_COM_CH_INTFC_H