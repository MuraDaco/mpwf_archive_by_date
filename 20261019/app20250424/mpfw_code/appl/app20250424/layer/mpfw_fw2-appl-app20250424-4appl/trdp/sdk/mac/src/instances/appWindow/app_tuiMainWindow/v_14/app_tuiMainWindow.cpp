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
 * app_tuiMainWindow.cpp
 *
 *  Created on: Oct, 23rd 2024
 *      Author: Marco Dau
 */
 

#include "app_tuiMainWindow.h"

#include "shmManager.h"
#include "sdkClipboard.h"

// -------------------------------------------------------
// **************************************************
// *** start section - WINDOW ELEMENTS ARRAYS DEFINITION


    // "WindowRoot" children definition
        TUI_DEF_CPP_UNIT        (tuiGrphRealUnit5Win_t,  tuiFnctRealUnit1Debug_t,    tuiGrphZAppMain_t, WindowRoot
            ,  8, 25,  0,  0, unitDebug1
            ,  2,  2,  1,  1 );
        TUI_DEF_CPP_UNIT_PAR    (tuiGrphRealUnit5Win_t,  tuiFnctRealUnit1Button_t,    tuiGrphZAppMain_t, WindowRoot
            ,  1, 25,  8,  0, buttonCopy
            ,  1,  1,  1,  1, "Copy to Clipboard"       ,buttonCopyToClip );
        TUI_DEF_CPP_UNIT_PAR    (tuiGrphRealUnit5Win_t,  tuiFnctRealUnit1Button_t,    tuiGrphZAppMain_t, WindowRoot
            ,  1, 25, 10,  0, buttonPaste
            ,  1,  1,  1,  1, "Paste from Clipboard"    ,buttonPasteFromClip );
        TUI_DEF_CPP_UNIT        (tuiGrphRealUnit5Win_t,  tuiFnctRealUnit1Debug_t,    tuiGrphZAppMain_t, WindowRoot
            ,  8, 25,  8, 25, unitDebug2
            ,  2,  2,  1,  1 );
        TUI_DEF_CPP_UNIT        (tuiGrphRealUnit5Base_t, tuiFnctRealUnit1Debug_t,    tuiGrphZAppMain_t, WindowRoot
            ,  8, 25,  0, 25, unitDebug5
            ,  2,  2,  1,  1 );
        // "windowDebug1" children definition
            TUI_DEF_CPP_UNIT        (tuiGrphRealUnit5Base_t, tuiFnctRealUnit1Debug_t,    tuiGrphZAppMain_t, windowDebug1
                ,  8, 25,  0,  0, unitDebug3
                ,  2, 2, 1, 1 );
            TUI_DEF_CPP_UNIT_GRPH   (tuiGrphRealUnit5Base_t, tuiFnctRealUnit1Debug_t,    tuiGrphZAppMain_t, windowDebug1
                ,  8, 25,  0, 25, unitDebug5
                ,  2,  2,  1,  1 );
            TUI_DEF_CPP_STREAM_FRMTD_STR (tuiGrphRealUnit5Base_t, tuiFnctRealUnit1Debug_t,    tuiGrphZAppMain_t, windowDebug1
                ,  8, 41,  0, 50, tstStreamFStr
                ,  1,  1,  1,  1 );
            TUI_DEF_CPP_UNIT_PAR   (tuiGrphRealUnit5Base_t, tuiFnctRealUnit1MmyInt_t,    tuiGrphZAppMain_t, windowDebug1
                ,  1, 25,  8,  0, pid
                ,  1,  1,  1,  1, "pid", &shmManager_t::g_dtyPid_new );
            TUI_DEF_CPP_UNIT        (tuiGrphRealUnit5Base_t, tuiFnctRealUnit1Debug_t,    tuiGrphZAppMain_t, windowDebug1
                ,  8, 25,  8, 25, unitDebug4
                ,  2,  2,  1,  1 );
            TUI_DEF_CPP_CPLT_UNIT_3_SHM_PROX_X   (tuiGrphZAppMain_t, windowDebug1
                ,  8, 25,  8, 50, pidBufferX
                ,  1,  1,  1,  1);
            TUI_DEF_CPP_UNIT_PAR    (tuiGrphRealUnit5Base_t, tuiFnctRealUnit3McuUsart_t, tuiGrphZAppMain_t, windowDebug1
                , 15, 45, 16,  0, usart1
                ,  2,  1,  2,  2, &PPH_OBJ  (USART_1) );
            // TUI_DEF_CPP_CPLX_MCU_USART    (tuiGrphRealUnit5Base_t, tuiFnctRealCplx3McuUsartX_t, tuiGrphZAppMain_t, windowDebug1
            //     , 15, 45, 16, 45, usart2Dbg
            //     ,  2,  1,  2,  2, &PPH_OBJ  (USART_1_DBG) );
            // TUI_DEF_CPP_CPLT_CPLX_MCU_USART    (tuiGrphZAppMain_t, windowDebug1
            //     , 15, 45, 16, 45, usart3Dbg
            //     ,  2,  1,  2,  2, &PPH_OBJ  (USART_1_DBG) );
            // TUI_DEF_CPP_CPLT_CPLX_MCU_USART_XX    (tuiGrphZAppMain_t, windowDebug1
            //     , 15, 45, 16, 45, usart4Dbg
            //     ,  2,  1,  2,  2, &PPH_OBJ  (USART_1_DBG) );
            TUI_DEF_CPP_CPLT_CPLX_MCU_USART_UU    (tuiGrphZAppMain_t, windowDebug1
                , 15, 45, 16, 45, usart5Dbg
                ,  2,  1,  2,  2, &PPH_OBJ  (USART_1_DBG) );
            // "windowDebug1_A" children definition
                TUI_DEF_CPP_UNIT_GRPH   (tuiGrphRealUnit5Base_t, tuiFnctRealUnit1Debug_t,    tuiGrphZAppMain_t, windowDebug1_A
                    ,  4, 15,  0,  0, unitDebug5
                    ,  1, 1, 1, 1 );
                TUI_DEF_CPP_UNIT_GRPH   (tuiGrphRealUnit5Base_t, tuiFnctRealUnit1Debug_t,    tuiGrphZAppMain_t, windowDebug1_A
                    ,  8, 25,  0,  0, unitDebug4
                    ,  1,  1,  1,  1 );
                TUI_DEF_CPP_UNIT_GRPH   (tuiGrphRealUnit5Base_t, tuiFnctRealUnit1Debug_t,    tuiGrphZAppMain_t, windowDebug1_A
                    ,  6, 20,  0,  0, unitDebug3
                    ,  1,  1,  1,  1 );
                TUI_DEF_CPP_UNIT_GRPH   (tuiGrphRealUnit5Base_t, tuiFnctRealUnit1Debug_t,    tuiGrphZAppMain_t, windowDebug1_A
                    ,  5, 15,  0,  0, unitDebug5
                    ,  1, 1, 1, 1 );
                TUI_DEF_CPP_UNIT_GRPH   (tuiGrphRealUnit5Base_t, tuiFnctRealUnit1Debug_t,    tuiGrphZAppMain_t, windowDebug1_A
                    , 10, 25,  0,  0, unitDebug4
                    ,  1,  1,  1,  1 );
                TUI_DEF_CPP_UNIT_GRPH   (tuiGrphRealUnit5Base_t, tuiFnctRealUnit1Debug_t,    tuiGrphZAppMain_t, windowDebug1_A
                    ,  7, 20,  0,  0, unitDebug3
                    ,  1,  1,  1,  1 );
            TUI_DEF_CPP_CPLT_UNIT_FORMATTED_STRING_CNTNR    ( tuiGrphZAppMain_t, windowDebug1
                , 10, 30, 32, 41,  formattedStyringDbg_A
                ,  2,  1,  2,  2 );
            TUI_DEF_CPP_CPLT_CTNR_STREAM_FORMATTED_STRING   ( tuiGrphZAppMain_t, windowDebug1
                , 10, 50, 42, 41,  streamFormattedStringDbg_A
                ,  2,  1,  2,  2 );
            TUI_DEF_CPP_GRPH_CTNR_STREAM_FORMATTED_STRING   ( tuiGrphZAppMain_t, windowDebug1
                , 10, 50, 52, 41,  streamFormattedStringDbg_B
                ,  2,  1,  2,  2 );


    // ----------------------------------
    // "WindowRoot" definition
        TUI_DEF_CPP_WINDOW_ROOT   (tuiGrphRealUnit5Root_t, tuiFnctRealUnit1Map_t, tuiGrphZAppMain_t
                            ,WindowRoot,                                5,  2,  5,  5,
            TUI_PTR_UNIT    (WindowRoot,  8, 25,  0,  0, unitDebug1,    2,  2,  1,  1 ),
            TUI_PTR_UNIT    (WindowRoot,  8, 25,  0, 25, unitDebug5,    2,  2,  1,  1 ),
            TUI_PTR_UNIT    (WindowRoot,  1, 25,  8,  0, buttonCopy,    1,  1,  1,  1 ),
            TUI_PTR_UNIT    (WindowRoot,  1, 25, 10,  0, buttonPaste,   1,  1,  1,  1 ),
            TUI_PTR_UNIT    (WindowRoot,  8, 25,  8, 25, unitDebug2,    2,  2,  1,  1 ),
            TUI_PTR_WINDOW  (WindowRoot, 32,100, 16,  0, windowDebug1,  2,  2,  1,  1 ),
            );
        // "windowDebug1" definition
            TUI_DEF_CPP_WINDOW  (tuiGrphRealUnit5Win_t, tuiFnctRealUnit2Cntnr_t, Map_t, tuiGrphZAppMain_t, WindowRoot
                , 32,100, 16,  0    ,windowDebug1,                                                 2,  2,  1,  1,
                TUI_PTR_UNIT        (windowDebug1,  8, 25,  0,  0, unitDebug3                   ,  2,  2,  1,  1 ),
                TUI_PTR_UNIT        (windowDebug1,  8, 25,  0, 25, unitDebug5                   ,  2,  2,  1,  1 ),
                TUI_PTR_UNIT        (windowDebug1,  8, 41,  0, 50, tstStreamFStr                ,  1,  1,  1,  1 ),
                TUI_PTR_UNIT        (windowDebug1,  1, 25,  8,  0, pid                          ,  1,  1,  1,  1 ),
                TUI_PTR_UNIT        (windowDebug1,  8, 25,  8, 25, unitDebug4                   ,  2,  2,  1,  1 ),
                TUI_PTR_CPLT        (windowDebug1,  8, 25,  8, 50, pidBufferX                   ,  1,  1,  1,  1 ),
                TUI_PTR_UNIT        (windowDebug1, 15, 45, 16,  0, usart1                       ,  2,  1,  2,  2 ),
                TUI_PTR_CPLT        (windowDebug1, 15, 45, 16, 45, usart5Dbg                    ,  2,  1,  2,  2 ),
                TUI_PTR_WINDOW      (windowDebug1, 20, 40, 32,  0, windowDebug1_A               ,  2,  1,  2,  2 ),
                TUI_PTR_CPLT        (windowDebug1, 10, 30, 32, 41, formattedStyringDbg_A        ,  2,  1,  2,  2 ),
                TUI_PTR_CPLT        (windowDebug1, 10, 50, 42, 41, streamFormattedStringDbg_A   ,  2,  1,  2,  2 ),
                TUI_PTR_UNIT        (windowDebug1, 10, 50, 52, 41, streamFormattedStringDbg_B   ,  2,  1,  2,  2 ),
                );
            // "windowDebug1_A" definition
                TUI_DEF_CPP_WINDOW  (tuiGrphRealUnit5Base_t, tuiFnctRealUnit2Cntnr_t, List_t, tuiGrphZAppMain_t, windowDebug1
                    , 20, 40, 32,  0    ,windowDebug1_A,                                2,  1,  2,  2,
                    TUI_PTR_UNIT        (windowDebug1_A,  4, 15,  0,  0, unitDebug5,    1,  1,  1,  1 ),
                    TUI_PTR_UNIT        (windowDebug1_A,  8, 25,  0,  0, unitDebug4,    1,  1,  1,  1 ),
                    TUI_PTR_UNIT        (windowDebug1_A,  6, 20,  0,  0, unitDebug3,    1,  1,  1,  1 ),
                    TUI_PTR_UNIT        (windowDebug1_A,  5, 15,  0,  0, unitDebug5,    1,  1,  1,  1 ),
                    TUI_PTR_UNIT        (windowDebug1_A, 10, 25,  0,  0, unitDebug4,    1,  1,  1,  1 ),
                    TUI_PTR_UNIT        (windowDebug1_A,  7, 20,  0,  0, unitDebug3,    1,  1,  1,  1 ),
                    );

    // *** end   section - WINDOW ELEMENTS ARRAY DEFINITION
    // **************************************************
// -------------------------------------------------------

void tuiGrphZAppMain_t::buttonCopyToClip  (void)      {
    sdkClipboard_t::copy("test clipboard");
}

void tuiGrphZAppMain_t::buttonPasteFromClip  (void)      {
    sdkClipboard_t::copy((sdkClipboard_t::paste() + " -- prova clip").c_str());
}
