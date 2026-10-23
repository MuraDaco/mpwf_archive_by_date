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
 * dtyString.cpp
 *
 *  Created on: Nov, 15h 2024 (Fri)
 *      Author: Marco Dau
 */
 
#include "dtyString.h"


dtyString_t::dtyString_t (void) :
     g_pStr         {nullptr}
    ,g_buffSize     {0}
{}

dtyString_t::dtyString_t (char* p_pSrcChar, size_t p_srcBuffSize) :
     g_pStr         {p_pSrcChar}
    ,g_buffSize     {(p_srcBuffSize > DTY_STRING_BUFFER_SIZE_MAX) ? DTY_STRING_BUFFER_SIZE_MAX : p_srcBuffSize}
{}

uint16_t    dtyString_t::getStrLength(void) {
    uint16_t l_strLength = 0;

    if(g_pStr)
        for(uint16_t it = 0; it < g_buffSize; it++) {
            if(g_pStr[it] == 0) {
                l_strLength = it;
                break;
            }
        }

    return l_strLength;
}
size_t dtyString_t::getBuffSize(void)    {
    return g_buffSize;
}

char* dtyString_t::getBuffPtr(void)   {
    return g_pStr;
}


void dtyString_t::setPtrBufferTo(char* p_pSrcChar, size_t p_srcBuffSize)  {

    g_pStr      = p_pSrcChar;
    g_buffSize  = (p_srcBuffSize > DTY_STRING_BUFFER_SIZE_MAX) ? DTY_STRING_BUFFER_SIZE_MAX : p_srcBuffSize;

}

size_t dtyString_t::setPtrBufferFrom(char** p_ppDestChar)    {
    *p_ppDestChar = g_pStr;
    return g_buffSize;
}

size_t dtyString_t::copyBufferFrom(char* p_pSrcChar, size_t p_srcBuffSize)    {
    size_t it = 0;
    while(
            (it < g_buffSize)
        &&  (it < p_srcBuffSize)
    )   {
        g_pStr[it] = p_pSrcChar[it];
        it++;
    }
    return it;
}

uint16_t dtyString_t::copyBufferToString(char* p_pDstChar, size_t p_dstBuffSize)    {
    size_t it = 0;
    while(
            (it < g_buffSize)
        &&  (it < p_dstBuffSize)
    )   {
        p_pDstChar[it] = g_pStr[it];
        it++;
    }

    if(it < p_dstBuffSize) p_pDstChar[it] = 0; else { it = 0; p_pDstChar[0] = 0;}
    return it;
}

size_t dtyString_t::copyBufferTo(char* p_pDstChar, size_t p_dstBuffSize)  {
    size_t it = 0;
    while(
            (it < g_buffSize)
        &&  (it < p_dstBuffSize)
    )   {
        p_pDstChar[it] = g_pStr[it];
        it++;
    }

    return it;
}

bool dtyString_t::copyStringTo(char* p_pSrcChar)  {
    size_t it = 0;
    while(
            (it < g_buffSize)
    )   {
        g_pStr[it] = p_pSrcChar[it];
        if(0 == p_pSrcChar[it])
            break;
        it++;
    }
    return (it < g_buffSize);
}

uint16_t dtyString_t::copyStringFrom(char* p_pDstChar, size_t p_dstBuffSize)  {
    size_t it = 0;
    while(
            (it < g_buffSize)
        &&  (it < p_dstBuffSize)
    )   {
        p_pDstChar[it] = g_pStr[it];
        if(0 == p_pDstChar[it])
            break;
        it++;
    }

    if(p_pDstChar[it]) {
        if(p_dstBuffSize <= it) p_pDstChar[p_dstBuffSize-1] = 0;
        it = p_dstBuffSize-1;
    }

    // return string length = position of null-terminator character
    return it;
}


void dtyString_t::strncpy    (char* p_pDstChar, char* p_pSrcChar, size_t p_dstBuffSize)     {
    size_t it = 0;
    while(it < p_dstBuffSize)   {
        p_pDstChar[it] = p_pSrcChar[it];
        if(0 == p_pDstChar[it])
            break;
        it++;
    }

    if(it == p_dstBuffSize) p_pDstChar[it-1] = 0; 
}

void dtyString_t::strncpy    (uint8_t* p_pDstChar, char* p_pSrcChar, size_t p_dstBuffSize)     {
    strncpy(reinterpret_cast<char*>(p_pDstChar), p_pSrcChar, p_dstBuffSize);
}

void dtyString_t::strncpy    (char* p_pDstChar, const char* p_pSrcChar, size_t p_dstBuffSize)     {
    size_t it = 0;
    while(it < p_dstBuffSize)   {
        p_pDstChar[it] = p_pSrcChar[it];
        if(0 == p_pDstChar[it])
            break;
        it++;
    }

    if(it == p_dstBuffSize) p_pDstChar[it-1] = 0; 
}

void dtyString_t::strncpy    (uint8_t* p_pDstChar, const char* p_pSrcChar, size_t p_dstBuffSize)     {
    strncpy(reinterpret_cast<char*>(p_pDstChar), p_pSrcChar, p_dstBuffSize);
}


void dtyString_t::strncpyU    (char* p_pDstChar, unionCharPtrs_t p_pSrcCharU, size_t p_dstBuffSize)     {
    size_t it = 0;
    while(it < p_dstBuffSize)   {
        p_pDstChar[it] = p_pSrcCharU.chr[it];
        if(0 == p_pDstChar[it])
            break;
        it++;
    }

    if(it == p_dstBuffSize) p_pDstChar[it-1] = 0; 
}

void dtyString_t::strncpyU    (char* p_pDstChar, char* p_pSrcChar, size_t p_dstBuffSize)     {
    unionCharPtrs_t l_pSrcCharU = {.chr = p_pSrcChar};
    strncpyU(p_pDstChar, l_pSrcCharU, p_dstBuffSize);
}

void dtyString_t::strncpyU    (uint8_t* p_pDstChar, char* p_pSrcChar, size_t p_dstBuffSize)     {
    unionCharPtrs_t l_pSrcCharU = {.chr = p_pSrcChar};
    strncpyU(reinterpret_cast<char*>(p_pDstChar), l_pSrcCharU, p_dstBuffSize);
}

void dtyString_t::strncpyU    (char* p_pDstChar, const char* p_pSrcChar, size_t p_dstBuffSize)     {
    unionCharPtrs_t l_pSrcCharU = {.cchr = p_pSrcChar};
    strncpyU(p_pDstChar, l_pSrcCharU, p_dstBuffSize);
}

void dtyString_t::strncpyU    (uint8_t* p_pDstChar, const char* p_pSrcChar, size_t p_dstBuffSize)     {
    unionCharPtrs_t l_pSrcCharU = {.cchr = p_pSrcChar};
    strncpyU(reinterpret_cast<char*>(p_pDstChar), l_pSrcCharU, p_dstBuffSize);
}


// *****

/// uint16_t dtyString_t::getLength(void)   {
///     uint16_t l_length = 0;
///     if(g_pChar)
///         for(uint16_t i = 0; (g_pChar[i] != 0) && (i < g_size); i++) 
///             {l_length = (i < g_size) ? ++i : i;}
/// 
///     uint16_t it = 0;
///     while(g_pChar[it] != 0)  {
///         if(it >= g_size)  {
///             // overflow source buffer
///             it = g_size;
///             break;
///         }
///         it++;
///     }
/// 
///     return l_length;
/// }
/// 
/// void dtyString_t::setLength(uint16_t p_length)   {
///     g_size   = p_length;
/// }
/// 
/// char* dtyString_t::getString(void)   {
///     return g_pChar;
/// }
/// 
/// void dtyString_t::setString(char* p_pChar)   {
///     g_pChar = p_pChar;
/// }
/// 
/// 
/// //void dtyString_t::copyStringFrom(char* p_pDestChar, size_t p_size)
/// //void dtyString_t::copyStringTo(char* p_pSrcChar, size_t p_size)
/// void dtyString_t::copyString(char* p_pChar, size_t p_size)  {
///     uint16_t l_length = 0;
///     // for(uint16_t i = 0; (g_pChar[i] != 0) && (i < g_size) && (i < p_size); i++) {
///     //     p_pChar[i] = g_pChar[i];
///     //     l_length = i;
///     // }
/// 
///     // string_length = number of characters
///     // string_length = buffer_length - 1;
///     // p_pChar[string_length] = 0
/// 
///     // copyBuffer do not set the last byte to 0 therefore it is possible that it returns a buffer without null terminating character
///     // copyString set the last byte to 0
/// 
///     uint16_t it = 0;
///     for(;;)  {
///         if(it >= g_size)  {
///             // overflow source buffer
///             p_pChar[it] = 0;
///             break;
///         }
///         if(it >= p_size)  {
///             // overflow destination buffer
///             if(p_size) p_pChar[p_size-1] = 0;
///             break;
///         }
///         if(g_pChar[it] == 0)  {
///             // overflow destination buffer
///             p_pChar[it] = 0;
///             break;
///         }
///         p_pChar[it] = g_pChar[it];
///         it++;
///     }
/// 
/// 
/// }
/// 
/// 
