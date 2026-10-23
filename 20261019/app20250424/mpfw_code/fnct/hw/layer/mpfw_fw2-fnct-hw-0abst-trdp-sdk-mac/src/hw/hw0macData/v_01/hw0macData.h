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
 * hw0macData.h
 *
 *  Created on: Mar,  9th 2026 (Mon)
 *      Author: Marco Dau
 */
 
#ifndef HW_0_MAC_DATA_H
#define HW_0_MAC_DATA_H

#include <cstdint>
#include <sys/types.h>
#include <unistd.h>             // for getpid(), ftruncate()

namespace hw0macData_ns  {

    typedef struct init_params_struct
    {
        uint8_t mcuId;
        bool    shmReset;
    } init_params_t;

    typedef struct _shm_process_struct
    {
        pid_t pid;
        uint8_t  status;
    } shm_process_struct_t;

    typedef shm_process_struct_t*     (* pProx_Func_t)       (void);


};

#endif 	// HW_0_MAC_DATA_H
