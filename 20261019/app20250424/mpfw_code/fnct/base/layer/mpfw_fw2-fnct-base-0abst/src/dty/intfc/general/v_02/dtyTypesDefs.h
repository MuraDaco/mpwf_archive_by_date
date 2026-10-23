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
 * dtyTypesDefs.h
 *
 *  Created on: Jan, 28th 2025 (Tue)
 *      Author: Marco Dau
 */
 
#ifndef DTY_TYPES_DEFS_H
#define DTY_TYPES_DEFS_H

#include <stddef.h>
#include <cstdint>

#define tuiEventCodeNum(a) static_cast<uint8_t>(a)

class dtyIntfcAbstractUnitFunctional_t;

namespace dtyTypesDefs_t  {

    // ************************************
    // **** CONTAINERS
        struct dtyBuffer_t {
            uint8_t* pBuf;
            size_t   size;
        };
    // **** CONTAINERS - END
    // ************************************
    // ************************************
    // **** USER INTERFACE

        // ************************************
        // **** ELEMENTS GEOMETRIC PROPERTIES
            typedef struct __point__ {
                uint8_t x;
                uint8_t y;
            } point_t;

            typedef struct __dimension__ {
                uint8_t width;
                uint8_t height;
            } dimension_t;

            typedef struct __box__ {
                // height & width
                uint8_t height;
                uint8_t width;
                // start point
                uint8_t yStart;
                uint8_t xStart;
            } box_t;

            typedef struct __margins__ {
                uint8_t Top;
                uint8_t Bottom;
                uint8_t Left;
                uint8_t Right;
            } margins_t;
        // **** ELEMENTS GEOMETRIC PROPERTIES - END
        // ************************************
        // ************************************
        // **** STATUS
            enum class tuiMode_t: uint8_t {
                 undefined
                ,deselect
                ,select
                ,eventOn
                ,num
            };

            enum class tuiState_t: uint8_t {
                 undefined
                ,deselect
                ,select
                ,eventOn
                ,num
            };

            enum class tuiActivationStatus_t: uint8_t {
                 undefined
                ,enabled
                ,disabled
                ,num
            };
        // **** STATUS - END
        // ************************************
        // ************************************
        // **** KEYBOARD

            enum class tuiEventCode_t: uint8_t {
                 keyDown
                ,keyUp
                ,keyLeft
                ,keyRight
                ,keyEnter
                ,keyHome
                ,keyDel
                ,keyBackspace
                ,keyTypeChar
                ,mouse
                ,mouseRollUp
                ,mouseRollDown
                ,noEvent = 0xff
            };

        // **** KEYBOARD - END
        // ************************************
        // ************************************
        // **** DISPLAY
            enum kFormatColor_t: int8_t  {
                     fmt_yellow     = 4
                    ,fmt_magenta
                    ,fmt_cyan
                    ,fmt_white
            };

            enum kColor_t: int8_t  {
                // --------
                // standard
                    black
                    ,red
                    ,green
                    ,yellow
                    ,blue
                    ,magenta
                    ,cyan
                    ,white
                // --------
                // low
                    ,black_low
                    ,red_low
                    ,green_low
                    ,yellow_low
                    ,blue_low
                    ,magenta_low
                    ,cyan_low
                    ,white_low
                // --------
                // high
                    ,black_high
                    ,red_high
                    ,green_high
                    ,yellow_high
                    ,blue_high
                    ,magenta_high
                    ,cyan_high
                    ,white_high
            };

        // **** DISPLAY - END
        // ************************************

    // **** USER INTERFACE - END
    // ************************************
    // ************************************
    // **** STRING INFO
        enum kMarker_t: int8_t  {
             defaultX = 0x18      // end marker = 0xe8
            ,deviceRx = 0x07      // end marker = 0xf9
            ,deviceTx = 0x06      // end marker = 0xfa
            ,testTx   = 0x15      // end marker = 0xeb
        };

        enum kDataType_t: int8_t  {
             ascii
            ,binary
        };

        typedef struct formatted_string_type    {
            kColor_t color;
            const char*    str;
        } fmt_str_t;

        class dtyStringInfo_t {
            public:
            bool        g_select;
            kMarker_t   g_marker;
        };

    // **** STRING INFO - END
    // ************************************
    // ************************************
    // **** FUNCTION POINTERS
        typedef void    (* tuiUnitFunc_t)       (dtyIntfcAbstractUnitFunctional_t* p_this);

        typedef void    (* func_t)              (void);
        typedef void    (* funcCallback_t)      (void);
        typedef void    (* event_t)             (void);
        typedef void    (* event_pVoid_t)       (void*);
        typedef void    (* void_f_uint8_t)      (uint8_t);
        typedef void    (* void_f_pVoid_t)      (void*);
        typedef int     (* int_f_int_x_2)       (int, int);
    // **** FUNCTION POINTERS - END
    // ************************************
};

#endif 	// DTY_TYPES_DEFS_H
