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
 * dtyString.h
 *
 *  Created on: Nov, 15h 2024 (Fri)
 *      Author: Marco Dau
 */
 
#ifndef DTY_STRING_H
#define DTY_STRING_H

#include <stddef.h>
#include <cstdint>


#define DTY_STRING_BUFFER_SIZE_MAX      1000

class dtyString_t {

    public:
        dtyString_t (void);
        dtyString_t (char* p_pSrcChar, size_t p_srcBuffSize);

        uint16_t    getStrLength(void);
        size_t      getBuffSize(void);
        char*       getBuffPtr(void);

        void        setPtrBufferTo(char* p_pSrcChar, size_t p_srcBuffSize);
        size_t      setPtrBufferFrom(char** p_ppDestChar);

        size_t      copyBufferFrom(char* p_pSrcChar, size_t p_srcBuffSize);
        uint16_t    copyBufferToString(char* p_pDstChar, size_t p_dstBuffSize);
        size_t      copyBufferTo(char* p_pDstChar, size_t p_dstBuffSize);

        bool        copyStringTo(char* p_pSrcChar);
        uint16_t    copyStringFrom(char* p_pDstChar, size_t p_dstBuffSize);

        static  void strncpy    (char* p_pDstChar, char* p_pSrcChar, size_t p_dstBuffSize);
        static  void strncpy    (uint8_t* p_pDstChar, char* p_pSrcChar, size_t p_dstBuffSize);
        static  void strncpy    (char* p_pDstChar, const char* p_pSrcChar, size_t p_dstBuffSize);
        static  void strncpy    (uint8_t* p_pDstChar, const char* p_pSrcChar, size_t p_dstBuffSize);

        static  void strncpyU    (char* p_pDstChar, char* p_pSrcChar, size_t p_dstBuffSize);
        static  void strncpyU    (uint8_t* p_pDstChar, char* p_pSrcChar, size_t p_dstBuffSize);
        static  void strncpyU    (char* p_pDstChar, const char* p_pSrcChar, size_t p_dstBuffSize);
        static  void strncpyU    (uint8_t* p_pDstChar, const char* p_pSrcChar, size_t p_dstBuffSize);


    private:

        union unionCharPtrs_t {
           char *chr;
           const char* cchr;
        };

        static void strncpyU    (char* p_pDstChar, unionCharPtrs_t p_pSrcChar, size_t p_dstBuffSize);
 
        char*       g_pStr;
        size_t      g_buffSize;
};


#endif 	// DTY_STRING_H
