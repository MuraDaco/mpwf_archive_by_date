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
 * sysDebug.h
 *
 *  Created on: Jan,  20th 2026 (Tue)
 *      Author: Marco Dau
 */

#ifndef SYS_DEBUG_H
#define SYS_DEBUG_H

class sysDebug_t {

    public:

        static void exit    (void);
        static void exit    (int p_errorCode);
        static void msg     (char* p_str);
        static void msg     (uint16_t p_x, uint16_t p_y, char* p_str);

};


#endif  // SYS_DEBUG_H
