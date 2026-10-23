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
 * dtyIntfcUiInOut.h
 *
 *  Created on: Jan, 28th 2025 (Tue)
 *      Author: Marco Dau
 */
 
#ifndef DTY_INTFC_UI_IN_OUT_H
#define DTY_INTFC_UI_IN_OUT_H

#include "dtyTypesDefs.h"
using namespace dtyTypesDefs_t; 


class dtyIntfcAbstractUnitGraphic_t;

class dtyIntfcUiInOut_t {

public:

    // INIT

    virtual void initWin                            (void) = 0;
    virtual void initWin                            (uint16_t p_rootX0a, uint16_t p_rootY0a) = 0;
    virtual void setGraphEnvWindow                  (dtyIntfcAbstractUnitGraphic_t* p_pParent) = 0;
    virtual void initGraphEnv                       (void) = 0;
    virtual void initGraphEnvColor                  (void) = 0;
    virtual void deinitGraphEnv                     (void) = 0;
    virtual void endGraphEnv                        (void) = 0;


    // OUTPUT

    virtual void frameClear                         (void) = 0;

    virtual void nameOnly                           (bool p_select, const char* g_strName) = 0;

    // .... string
    virtual void nameOnly                           (const char* g_strName) = 0;
    virtual void nameOnly                           (uint16_t p_x, const char* p_strName) = 0;
    virtual void nameOnly                           (uint16_t p_x, const char* p_strName, uint32_t p_info) = 0;
    virtual bool nameOnly                           (tuiState_t p_mode, const char* g_strName) = 0;
    virtual bool nameOnly                           (tuiState_t p_mode, uint16_t p_x, const char* g_strName) = 0;

    // .... formatted string
    virtual void fmtStringOnly                      (fmt_str_t* p_fmtStr) = 0;
    virtual void fmtStringOnly                      (uint16_t p_x, fmt_str_t* p_fmtStr) = 0;
    virtual void fmtStringOnly                      (uint16_t p_x, fmt_str_t* p_fmtStr, uint32_t p_info) = 0;
    virtual bool fmtStringOnly                      (tuiState_t p_mode, fmt_str_t* p_fmtStr) = 0;
    virtual bool fmtStringOnly                      (tuiState_t p_mode, uint16_t p_x, fmt_str_t* p_fmtStr) = 0;

    virtual void frameNnameTest                     (const char* p_strName, const char* p_strValue) = 0;
    virtual void frameNnameTest                     (const char* g_strName) = 0;
    virtual bool frameNnameTest                     (tuiState_t p_mode, const char* p_strName, const char* p_strValue) = 0;
    virtual bool frameNnameTest                     (tuiState_t p_mode, const char* p_strName) = 0;

    virtual void nameNstatus                        (const char* p_strName, uint8_t p_status) = 0;
    virtual bool nameNstatus                        (tuiState_t p_mode, const char* p_strName, uint8_t p_status) = 0;
    virtual bool nameNstatus                        (tuiState_t p_mode, const char* p_strName, uint8_t p_status, bool p_repaint) = 0;

    virtual void content                            (char* p_str, uint8_t p_size) = 0;
    virtual void content                            (uint8_t p_begin) = 0;
    virtual bool content                            (tuiState_t p_mode, char* p_str, uint8_t p_size) = 0;
    virtual void content                            (char* p_str, uint8_t p_begin, uint8_t p_size) = 0;

    virtual void stringPrint                        (uint8_t p_rowMarker, bool p_select, char* p_pStr, uint32_t p_strSize) = 0;
    virtual bool stringPrint                        (tuiState_t p_mode, uint8_t p_rowMarker, bool p_select, char* p_pStr, uint32_t p_strSize) = 0;
    virtual void stringPrint2                       (uint8_t p_rowMarker, bool p_select, char* p_pStr, uint32_t p_strSize) = 0;
    virtual bool stringPrint2                       (tuiState_t p_mode, uint8_t p_rowMarker, bool p_select, char* p_pStr, uint32_t p_strSize) = 0;

    virtual void debugPrint                         ([[maybe_unused]] uint32_t p_dbgParam1, [[maybe_unused]] uint32_t p_dbgParam2, [[maybe_unused]] char* p_pStr) = 0;

    virtual uint8_t colorCodeTranslator             (dtyTypesDefs_t::kColor_t p_color) = 0;
//
//    virtual void frameBox                           (const char* g_strName) = 0;
//    virtual bool frameBox                           (dtyTypesDefs_t::tuiState_t p_mode, const char* g_strName) = 0;
//
//    virtual void frameNname                         (const char* g_strName) = 0;
//    virtual bool frameNname                         (dtyTypesDefs_t::tuiState_t p_mode, const char* g_strName) = 0;
//    virtual void frameNameNstatus                   (const char* g_strName, char* p_str) = 0;
//    virtual bool frameNameNstatus                   (dtyTypesDefs_t::tuiState_t p_mode, const char* g_strName, char* p_str) = 0;
//
//
//    virtual void rowPrint                           (uint8_t b_row, bool p_bRowBegin, uint8_t p_rowMarker, char* p_pRowStr, uint8_t p_rowLength) = 0;
//    virtual void rowPrintX                          (uint8_t p_rowMarker, bool p_select, char* p_pStr, uint32_t p_strSize) = 0;
//    virtual void statusPrintX                       (void) = 0;
//    virtual void statusPrintX                       (char* p_pStr, uint32_t p_strSize) = 0;

    virtual void positionCursor                     (bool p_status, uint8_t p_position) = 0;
    virtual bool isSelected                         (void) = 0;
    virtual bool isSelectedOrEventOn                (void) = 0;

    virtual void dbgPrint                           (char* p_str) = 0;
    virtual void dbgPrint                           (uint16_t p_x, uint16_t p_y, char* p_str) = 0;

    virtual void dbgExit                            (const char* p_strExit) = 0;
    virtual void dbgStep                            (const char* p_strStep) = 0;
    virtual void dbgStep                            (const char* p_strStep, uint32_t p_param1, uint32_t p_param2) = 0;
    virtual void dbgStep                            (uint8_t p_y, const char* p_strStep, uint32_t p_param1, uint32_t p_param2) = 0;


    // INPUT
    virtual bool uiEventStatus                      (void) = 0;
    virtual int uiEventKeyCode                      (void) = 0;
    virtual dtyTypesDefs_t::tuiEventCode_t  uiHandlerEventCode      (void) = 0;
    virtual bool uiMouseEventStatus                 (void) = 0;
    virtual bool uiMouseEventCode_ButtonPressed     (void) = 0;

};

#endif 	// DTY_INTFC_UI_IN_OUT_H
