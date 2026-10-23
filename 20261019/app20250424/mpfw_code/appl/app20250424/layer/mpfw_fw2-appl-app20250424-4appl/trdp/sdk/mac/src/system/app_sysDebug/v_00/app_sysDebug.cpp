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
 * app_sysExit.cpp
 *
 *  Created on: Jan,  20th 2026 (Tue)
 *      Author: Marco Dau
 */

#include <iostream>
#include <stdexcept>

#include "sysDebug.h"

#include "tuiManager.h"
// #include "tuiGrphRealUnit5Root.h"

#include "pphManager.h"

void sysDebug_t::msg (char* p_str)  {
    tuiManager_t::g_baseMainWin->dbgStep(p_str);
}

void sysDebug_t::msg(uint16_t p_x, uint16_t p_y, char* p_str)  {
    tuiManager_t::g_baseMainWin->dbgPrint(p_x, p_y, p_str);

}

void sysDebug_t::exit (void)  {
    try { 
        throw 15; 
    } catch (int i) {
        // tuiManager_t::g_baseMainWin->end();
        tuiManager_t::g_baseMainWin->dbgExit("Exit by debug");

        pphManager_t::end();

        std::cout << " the integer exception was caught, with value: " << i << '\n';
        std::exit(i);
    }
}

void sysDebug_t::exit (int p_errorCode)  {
    try { 
        throw p_errorCode; 
    } catch (int i) {
        // tuiManager_t::g_baseMainWin->end();
        tuiManager_t::g_baseMainWin->dbgExit("Exit by debug");

        pphManager_t::end();

        std::cout << " the integer exception was caught, with value: " << i << '\n';
        std::exit(i);
    }
}

///     void tuiGrphAbstUnit4InOut_t::dbgPrint             (uint16_t p_x, uint16_t p_y, char* p_str)       {
///         [[maybe_unused]] uint16_t l_h;
///         uint16_t l_w;
///         getmaxyx(stdscr, l_h, l_w);
///         if(p_x < l_w)    {
///             mvwhline    (stdscr, p_y, p_x, ' '         , (l_w-1) - 80);
///             mvwprintw   (stdscr, p_y, p_x, "*** %s ***", p_str);
///             refreshWin();
///         }
///     }
/// 
///     void tuiGrphAbstUnit4InOut_t::dbgExit                        (const char* p_strExit) {
/// 
///         deinitGraphEnv();
///         endGraphEnv();
///         std::string l_strExit (p_strExit);
///         std::cout << l_strExit << '\n';
///         std::exit(0);
/// 
/// 
///     }
/// 
///     void tuiGrphAbstUnit4InOut_t::dbgStep                        (const char* p_strStep) {
/// 