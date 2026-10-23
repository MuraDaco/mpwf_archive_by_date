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
 * app_tuiMainWindow.h
 *
 *  Created on: Oct, 23rd 2024
 *      Author: Marco Dau
 */
 
#ifndef TUI_GRPH_Z_APP_MAIN_H
#define TUI_GRPH_Z_APP_MAIN_H

// macro define
#include "tuiMacroDefine.h"

// pph modules
#include "hwManagerTbl.h"
#include "app_pphDef_Buttons.h"
#include "app_pphDef_Leds.h"
#include "app_pphDef_Mod1.h"

// dty modules
#include "dtyCntnr1ArrayTuiList.h"                  
#include "dtyCntnr1ArrayTuiMap.h"                   
#include "dtyCntnr1StreamList.h"                    
#include "tuiCplt_0dtyCntnr2StreamListFStr.h"       
#include "dtyUnit1MmyInt32.h"                       

// tui functional modules
#include "tuiFnctRealUnit1Debug.h"                  
#include "tuiFnctRealUnit1FormattedString.h"        
#include "tuiFnctRealUnit1FormattedStringCntnr.h"   
#include "tuiFnctRealUnit1Map.h"                    
#include "tuiFnctRealUnit1Ebox.h"                   
#include "tuiFnctRealUnit1MmyInt.h"                 
#include "tuiFnctRealUnit1DgtInOut.h"               
#include "tuiFnctRealUnit1Button.h"                 
#include "tuiFnctRealUnit2Cntnr.h"                  

#include "tuiFnctRealUnit3McuUsart.h"   // --> usart1
// #include "tuiFnctRealUnit3McuUsartX.h"              
// #include "tuiFnctRealCplx3McuUsartX.h"

// tui graphic modules
#include "tuiGrphRealUnit5Base.h"                 
#include "tuiGrphRealUnit5Win.h"                  
#include "tuiGrphRealUnit5Root.h"                 

// tui compelte modules (Class)
// #include "tuiCpltCplx3McuUsartX.h"
#include "tuiCpltCplx4McuUsartUU.h"     // --> usart5Dbg
    // derived from --> #include "tuiCpltCplx3McuUsartXX.h"

#include "tuiCpltCtnr2StreamFormattedString.h"
#include "tuiCpltUnit1FormattedStringCntnr.h"
#include "tuiCpltUnit3ShmProxX.h"

// tui compelte modules (Macro)
#include "tuiCplt_MacroDefCplx3McuUsart.h"  // --> usart5Dbg

#include "tuiCplt_MacroDefCtnr2StreamFormattedString.h"
#include "tuiCplt_MacroDefUnit1FormattedStringCntnr.h"
#include "tuiCplt_MacroDefUnit3ShmProxX.h"


class tuiGrphZAppMain_t {

public:


        TUI_DEF_H___WINDOW_ROOT   (tuiGrphRealUnit5Root_t, tuiFnctRealUnit1Map_t, WindowRoot);
            TUI_DEF_H___UNIT    (tuiGrphRealUnit5Win_t, tuiFnctRealUnit1Debug_t, WindowRoot
                ,  8, 25,  0,  0, unitDebug1
                ,  2,  2,  1,  1 );
            TUI_DEF_H___UNIT    (tuiGrphRealUnit5Win_t, tuiFnctRealUnit1Button_t, WindowRoot
                ,  1, 25,  8,  0, buttonCopy
                ,  1,  1,  1,  1 );
            TUI_DEF_H___UNIT    (tuiGrphRealUnit5Win_t, tuiFnctRealUnit1Button_t, WindowRoot
                ,  1, 25, 10,  0, buttonPaste
                ,  1,  1,  1,  1 );
            TUI_DEF_H___UNIT    (tuiGrphRealUnit5Win_t, tuiFnctRealUnit1Debug_t, WindowRoot
                ,  8, 25,  8, 25, unitDebug2
                ,  2,  2,  1,  1 );
            TUI_DEF_H___UNIT    (tuiGrphRealUnit5Base_t, tuiFnctRealUnit1Debug_t,WindowRoot
                ,  8, 25,  0, 25, unitDebug5
                ,  2,  2,  1,  1 );
            TUI_DEF_H___WINDOW  (tuiGrphRealUnit5Win_t, tuiFnctRealUnit2Cntnr_t, Map_t, WindowRoot
                , 32,100, 16,  0, windowDebug1
                ,  2,  2,  1,  1 );
                TUI_DEF_H___UNIT      (tuiGrphRealUnit5Base_t, tuiFnctRealUnit1Debug_t,    windowDebug1
                    ,  8, 25,  0,  0, unitDebug3
                    ,  2,  2,  1,  1 );
                TUI_DEF_H___UNIT_GRPH (tuiGrphRealUnit5Base_t, tuiFnctRealUnit1Debug_t,    windowDebug1
                    ,  8, 25,  0, 25, unitDebug5
                    ,  2,  2,  1,  1 );
                TUI_DEF_H___STREAM_FRMTD_STR    (tuiGrphRealUnit5Base_t, tuiFnctRealUnit1Debug_t, windowDebug1
                    ,  8, 41,  0, 50, tstStreamFStr
                    ,  1,  1,  1,  1 );
                TUI_DEF_H___UNIT      (tuiGrphRealUnit5Base_t, tuiFnctRealUnit1MmyInt_t,   windowDebug1
                    ,  1, 25,  8,  0, pid
                    ,  1,  1,  1,  1 );
                TUI_DEF_H___UNIT      (tuiGrphRealUnit5Base_t, tuiFnctRealUnit1Debug_t,    windowDebug1
                    ,  8, 25,  8, 25, unitDebug4
                    ,  2,  2,  1,  1 );
                TUI_DEF_H___CPLT_UNIT_3_SHM_PROX_X      (windowDebug1
                    ,  8, 25,  8, 50, pidBufferX
                    ,  1,  1,  1,  1 );
                TUI_DEF_H___UNIT      (tuiGrphRealUnit5Base_t, tuiFnctRealUnit3McuUsart_t, windowDebug1
                    , 15, 45, 16,  0, usart1
                    ,  2,  1,  2,  2 );
                // TUI_DEF_H___CPLX_MCU_USART      (tuiGrphRealUnit5Base_t, tuiFnctRealCplx3McuUsartX_t, windowDebug1
                //     , 15, 45, 16, 45, usart2Dbg
                //     ,  2,  1,  2,  2 );
                // TUI_DEF_H___CPLT_CPLX_MCU_USART      (windowDebug1
                //     , 15, 45, 16, 45, usart3Dbg
                //     ,  2,  1,  2,  2 );
                // TUI_DEF_H___CPLT_CPLX_MCU_USART_XX   (windowDebug1
                //     , 15, 45, 16, 45, usart4Dbg
                //     ,  2,  1,  2,  2 );
                TUI_DEF_H___CPLT_CPLX_MCU_USART_UU   (windowDebug1
                    , 15, 45, 16, 45, usart5Dbg
                    ,  2,  1,  2,  2 );
                TUI_DEF_H___WINDOW  (tuiGrphRealUnit5Base_t, tuiFnctRealUnit2Cntnr_t, List_t, windowDebug1
                    , 20, 40, 32,  0,  windowDebug1_A
                    ,  2,  1,  2,  2 );
                    TUI_DEF_H___UNIT_GRPH   (tuiGrphRealUnit5Base_t, tuiFnctRealUnit1Debug_t,  windowDebug1_A
                        ,  4, 15,  0,  0, unitDebug5
                        ,  1, 1, 1, 1 );
                    TUI_DEF_H___UNIT_GRPH   (tuiGrphRealUnit5Base_t, tuiFnctRealUnit1Debug_t,  windowDebug1_A
                        ,  8, 25,  0,  0, unitDebug4
                        ,  1,  1,  1,  1 );
                    TUI_DEF_H___UNIT_GRPH   (tuiGrphRealUnit5Base_t, tuiFnctRealUnit1Debug_t,  windowDebug1_A
                        ,  6, 20,  0,  0, unitDebug3
                        ,  1,  1,  1,  1 );
                    TUI_DEF_H___UNIT_GRPH   (tuiGrphRealUnit5Base_t, tuiFnctRealUnit1Debug_t,  windowDebug1_A
                        ,  5, 15,  0,  0, unitDebug5
                        ,  1, 1, 1, 1 );
                    TUI_DEF_H___UNIT_GRPH   (tuiGrphRealUnit5Base_t, tuiFnctRealUnit1Debug_t,  windowDebug1_A
                        , 10, 25,  0,  0, unitDebug4
                        ,  1,  1,  1,  1 );
                    TUI_DEF_H___UNIT_GRPH   (tuiGrphRealUnit5Base_t, tuiFnctRealUnit1Debug_t,  windowDebug1_A
                        ,  7, 20,  0,  0, unitDebug3
                        ,  1,  1,  1,  1 );
                TUI_DEF_H___CPLT_UNIT_FORMATTED_STRING_CNTNR    ( windowDebug1
                    , 10, 30, 32, 41,  formattedStyringDbg_A
                    ,  2,  1,  2,  2 );
                TUI_DEF_H___CPLT_CTNR_STREAM_FORMATTED_STRING   ( windowDebug1
                    , 10, 50, 42, 41,  streamFormattedStringDbg_A
                    ,  2,  1,  2,  2 );
                TUI_DEF_H___GRPH_CTNR_STREAM_FORMATTED_STRING   ( windowDebug1
                    , 10, 50, 52, 41,  streamFormattedStringDbg_B
                    ,  2,  1,  2,  2 );

    static void buttonCopyToClip    (void);
    static void buttonPasteFromClip (void);

};


#endif 	// TUI_GRPH_Z_APP_MAIN_H
