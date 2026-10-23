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
 * tuiFnctRealUnit1MmyInt.h
 *
 *  Created on: Dec, 26th 2024 (Thu)
 *      Author: Marco Dau
 */
 
#ifndef TUI_FNCT_REAL_UNIT_1_MMY_INT_H
#define TUI_FNCT_REAL_UNIT_1_MMY_INT_H

#include "tuiFnctAbstUnit0.h"
#include "dtyUnit1MmyInt32.h"

#include "dtyIntfcAbstractUnitGraphic.h"


class tuiFnctRealUnit1MmyInt_t :    public tuiFnctAbstUnit0_t
{

// ****************************************************
// section start **** CONSTRUCTOR *****

    public:
    tuiFnctRealUnit1MmyInt_t       (dtyUnit1MmyInt32_t* p_pdtyUnit1MmyInt32   );
    tuiFnctRealUnit1MmyInt_t       (const char* p_strName  ,dtyUnit1MmyInt32_t* p_pdtyUnit1MmyInt32   );

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

    // section end   **** STATE MANAGEMENT *****
    // ****************************************************
    // --------------------------
// ****************************************************
// section start **** SPECIFIC DATA *****

    private:

        dtyUnit1MmyInt32_t* g_pdtyUnit1MmyInt32;

    // section end   **** SPECIFIC DATA *****
    // ****************************************************
    // --------------------------
// ****************************************************
// section start **** CONTAINER *****

    public:
    void setValData        (uint32_t p_vData)   override;
    void setPtrData        (void* p_vData)      override;

    // section end   **** CONTAINER *****
    // ****************************************************
    // --------------------------
// ****************************************************
// section start **** DEBUG FUNCTIONS *****
    private:
        bool g_dbgSelect;
    public:
        void dbgSet             (int32_t p_value);
        void dbgSetMode         (bool p_select);
        void dbgRefreshValue    (dtyIntfcAbstractUnitGraphic_t* p_this);

    // section end   **** DEBUG FUNCTIONS *****
    // ****************************************************
    // --------------------------

};


#endif 	// TUI_FNCT_REAL_UNIT_1_MMY_INT_H
