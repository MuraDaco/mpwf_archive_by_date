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
 * tuiFnctRealUnit1FormattedStringCntnr.h
 *
 *  Created on: Feb,  1st 2025 (Sat)
 *      Author: Marco Dau
 */
 
#ifndef TUI_FNCT_REAL_UNIT_1_FORMATTED_STRING_CNTNR_H
#define TUI_FNCT_REAL_UNIT_1_FORMATTED_STRING_CNTNR_H

#include "tuiFnctAbstUnit0.h"

#include "dtyTypesDefs.h"
using namespace dtyTypesDefs_t; 

#include "dtyString.h"

#include "dtyIntfcAbstractUnitGraphic.h"


class tuiFnctRealUnit1FormattedStringCntnr_t :    public tuiFnctAbstUnit0_t 
{

// ****************************************************
// section start **** CONSTRUCTOR *****

    public:
    tuiFnctRealUnit1FormattedStringCntnr_t       (void);
    tuiFnctRealUnit1FormattedStringCntnr_t       (const char* p_strName  ,dtyString_t* p_pString = nullptr   );

    // section end   **** CONSTRUCTOR *****
    // ****************************************************
    // --------------------------
// ****************************************************
// section start **** PROCESS MANAGEMENT *****

    protected:
    bool init   	            (dtyIntfcAbstractUnitGraphic_t* p_this) override;
    bool initChildren           (dtyIntfcAbstractUnitGraphic_t* p_this) override;
    bool loop   	            (dtyIntfcAbstractUnitGraphic_t* p_this) override;
    bool loopChildren           (dtyIntfcAbstractUnitGraphic_t* p_this) override;
    void end       	            (dtyIntfcAbstractUnitGraphic_t* p_this) override;
    void endChildren            (dtyIntfcAbstractUnitGraphic_t* p_this) override;

    // section end   **** PROCESS MANAGEMENT *****
    // ****************************************************
    // --------------------------
// ****************************************************
// section start **** DISPLAY *****

    protected:
    void clear                  (dtyIntfcAbstractUnitGraphic_t* p_this) override;
    void display                (dtyIntfcAbstractUnitGraphic_t* p_this) override;
    void display                (dtyIntfcAbstractUnitGraphic_t* p_this, bool p_recursively) override;
    void displayChildren        (dtyIntfcAbstractUnitGraphic_t* p_this, bool p_recursively) override;
    void refreshChildren        (dtyIntfcAbstractUnitGraphic_t* p_this) override;

    // section end   **** DISPLAY *****
    // ****************************************************
    // --------------------------
// ****************************************************
// section start **** STATE MANAGEMENT *****

    protected:
        void selectStateSet         (bool p_selectState)                    override;
        bool select     	        (dtyIntfcAbstractUnitGraphic_t* p_this) override;
        bool deSelect   	        (dtyIntfcAbstractUnitGraphic_t* p_this) override;
        void eventOn    	        (dtyIntfcAbstractUnitGraphic_t* p_this) override;
        bool selectByMouse 	        (dtyIntfcAbstractUnitGraphic_t* p_this) override;
        bool clickingChild          (dtyIntfcAbstractUnitGraphic_t* p_this) override;

        bool g_selectState;

    // section end   **** STATE MANAGEMENT *****
    // ****************************************************
    // --------------------------
// ****************************************************
// section start **** CONTAINER *****

    public:
    void cntnrInit           (dtyString_t* p_pString, dtyStringInfo_t* p_pStringInfo)   override;
    void setPtrData          (void* p_pData)                                            override;
    void setPtrDataInfo      (void* p_pDataInfo)                                        override;
    void cntnrUpdParams      (dtyIntfcAbstractUnitGraphic_t* p_this)                    override;

    // section end   **** CONTAINER *****
    // ****************************************************
    // --------------------------
// ****************************************************
// section start **** FUNCTIONAL DATA MANAGEMENT *****

    private:

    dtyString_t*        g_pString;
    dtyStringInfo_t*    g_pStringInfo;

    uint8_t markerToColor     (kMarker_t p_marker);

    // section end   **** FUNCTIONAL DATA MANAGEMENT *****
    // ****************************************************
    // --------------------------
// ****************************************************
// section start **** DEBUG *****

    public:
    void displayDebug       (dtyIntfcAbstractUnitGraphic_t* p_this, uint32_t p_dbgParam1, uint32_t p_dbgParam2);

    // section end   **** DEBUG *****
    // ****************************************************
    // --------------------------

};


#endif 	// TUI_FNCT_REAL_UNIT_1_FORMATTED_STRING_CNTNR_H
