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
 * dtyCntnr1ArrayTuiMap.h
 *
 *  Created on: Nov, 20th 2024 (Wed)
 *      Author: Marco Dau
 *
 */
 
#ifndef DTY_CNTNR_1_ARRAY_TUI_MAP_H
#define DTY_CNTNR_1_ARRAY_TUI_MAP_H

#include <cstdint>
#include "dtyCntnr0BaseUnit.h"

#include "dtyIntfcAbstractUnitGraphic.h"

class dtyCntnr1ArrayTuiMap_t : public dtyCntnr0BaseUnit_t  {

public:
// ****************************************************
// section start **** CONSTRUCTOR *****

    dtyCntnr1ArrayTuiMap_t   (dtyIntfcAbstractUnitGraphic_t** p_array);

    // section end   **** CONSTRUCTOR ***** 
    // ****************************************************
    // --------------------------
// ****************************************************
// section start **** ARRAY CONTAINER MANAGEMENT *****
    dtyIntfcAbstractUnitGraphic_t** g_array;
    dtyIntfcAbstractUnitGraphic_t*  g_poParent;
    uint8_t     g_arraySize;

    //int32_t     g_x0r;
    int32_t     g_y0r;
    uint16_t    g_h;
    // section end   **** ARRAY CONTAINER MANAGEMENT ***** 
    // ****************************************************
    // --------------------------
// ****************************************************
// section start **** PROCESS MANAGEMENT *****

    public:
        void    initDisplay                     (uint8_t p_id, void* p_pParent) override;
        void    loopChild                       (void)                          override;

    // section end   **** PROCESS MANAGEMENT *****
    // ****************************************************
    // --------------------------
// ****************************************************
// section start **** LOOP MANAGEMENT *****
    private:
        // virtual override functions
            uint8_t getLoopInitCycles               (void)  override;
            bool    resetLoopElement                (void)  override;
            bool    nextLoopElement                 (void)  override;

        // parameters
            uint8_t     g_loopIdElement;
            int32_t     g_loopBoundYtop;
            int32_t     g_loopBoundYbottom;

    // section end   **** LOOP MANAGEMENT ***** 
    // ****************************************************
    // --------------------------
// ****************************************************
// section start **** DISPLAY *****
    private:

        bool    updCntnrRelCoord                (int32_t p_delta)               override;
        void    updElementCoordNbounds          (void)                          override;

        void    clearDisplayBox                 (void)                          override;
        void    dspElement                      (bool p_recursively)            override;

    // section end   **** DISPLAY ***** 
    // ****************************************************
    // --------------------------
// ****************************************************
// section start **** INPUT EVENTS: SELECTION & MOUSE ROLL *****

    private:
        // roll
        void    shiftLoopElementRollUp          (void)  override;
        void    shiftLoopElementRollDown        (void)  override;
        // select
        bool    selectElementByMouse            (void) override;
        void    shiftLoopElementBySelect        (int32_t p_delta)  override;
        int32_t getDeltaShiftBySelect           (void) override;
        void    updSelectElement                (void) override;
        bool    setSelectPrev                   (void) override;
        bool    setSelectNext                   (void) override;
        bool    bSelectVisibleCompletely        (void) override;
        bool    bFindSelectedElement            (void);
        void*   getSelectedItem                 (void) override;

        void resetSelectElement         (void);

        uint8_t     g_selectIdElement;

    // section end   **** INPUT EVENTS: SELECTION & MOUSE ROLL ***** 
    // ****************************************************

};


#endif 	// DTY_CNTNR_1_ARRAY_TUI_MAP_H
