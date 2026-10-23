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
 * dtyCntnr1StreamListX.h
 *
 *  Created on: Nov, 10th 2024
 *      Author: Marco Dau
 *
 */
 
#ifndef DTY_CNTNR_1_STREAM_LIST_X_H
#define DTY_CNTNR_1_STREAM_LIST_X_H

#include "dtyCntnr0BaseUnit.h"

#include "dtyCntnr0StreamUnitIntfc.h"
#include "dtyIntfcAbstractUnitFunctional.h"
#include "dtyIntfcAbstractUnitGraphic.h"

class dtyCntnr1StreamListX_t : public dtyCntnr0BaseUnit_t  {

// ****************************************************
// section start **** CONBSTRUCTOR *****
    public:

    dtyCntnr1StreamListX_t  (dtyCntnr0StreamUnitIntfc_t* p_streamUnit, dtyIntfcAbstractUnitFunctional_t*  p_loopPTuiUnit, dtyIntfcAbstractUnitGraphic_t*  p_loopPTuiGraphic);

    // section end   **** CONBSTRUCTOR ***** 
    // ****************************************************
    // --------------------------
// ****************************************************
// section start **** STRUCT & DATA STREAM MANAGEMENT: READ/WRITE *****

    // sub-section ** READ **
        //    private:
        //    uint32_t    getBlockDataIdHeaderPrev        (uint32_t p_idHeader);
        //    uint32_t    getBlockDataIdHeaderNext        (uint32_t p_idHeader);
        //    uint32_t    getBlockDataId                  (uint32_t p_idHeader);
        //    uint16_t    getBlockDataSize                (uint32_t p_idHeader);
        //    kMarker_t   getBlockDataMarker              (uint32_t p_idHeader);
        //
        // sub-section ** WRITE **
        public:
            void        add             (uint8_t* p_pBufIn, uint16_t p_bufInSize)                                             ;
            void        add             (uint8_t* p_pBufIn, uint16_t p_bufInSize, kMarker_t p_marker, kDataType_t p_dataType) ;
        //
        //    private:
        //    uint32_t    getWriteHeaderIdNext            (uint32_t p_idHeader);
        //
        //    uint8_t*    g_pBuf;
        //    uint32_t    g_bufSize;
        //
        //    uint32_t g_writeHeaderIdCurrent;
        //    uint32_t g_writeDataIdCurrent;
        //
    dtyCntnr0StreamUnitIntfc_t* g_streamUnit;
    // section end   **** STRUCT & DATA STREAM MANAGEMENT: READ/WRITE ***** 
    // ****************************************************
    // --------------------------
// ****************************************************
// section start **** LOOP MANAGEMENT *****
    private:

    dtyIntfcAbstractUnitFunctional_t    *g_loopPTuiUnit;             // it can be defined as static; it is a temporary variable BUT to make it static you MUST remember to update its g_pBuf & g_bufSize paramters every time you start to use it
    dtyIntfcAbstractUnitGraphic_t       *g_loopPTuiGraphic;          // it can be defined as static; it is a temporary variable BUT to make it static you MUST remember to call init procedure every time you start to use it
    uint32_t    g_loopIdHeader;     // it can be defined as static; it is a temporary variable
    uint32_t    g_loopIdData;       // it can be defined as static; it is a temporary variable
    uint32_t    g_loopDataSize;     // it can be defined as static; it is a temporary variable
    int32_t     g_loopY0r;          // it can be defined as static; it is a temporary variable
    uint32_t    g_loopH;            // it can be defined as static; it is a temporary variable
    bool        g_loopSelect;       // it can be defined as static; it is a temporary variable
    int32_t     g_loopRows;         // it can be defined as static; it is a temporary variable

    private:
    // virtual override
    uint8_t getLoopInitCycles               (void)  override;
    bool    resetLoopElement                (void)  override;
    bool    nextLoopElement                 (void)  override;
    
    void    loopTuiParamSet                 (void);
    bool    loopInit                        (uint32_t p_idHeader, int32_t p_y0r);
    bool    loopDisplayBegin                (void);
    bool    loopDisplayEnd                  (void);

    // section end   **** LOOP MANAGEMENT ***** 
    // ****************************************************
    // --------------------------
// ****************************************************
// section start **** DISPLAY *****
    private:

    enum kPosition_t: int8_t  {
         top
        ,topButLastRowOnly
        ,bottom
        };

    bool    updCntnrRelCoord                (int32_t p_delta)  override;
    void    updElementCoordNbounds          (void)  override;

    void    initDisplay                     (uint8_t p_id, void* p_pParent)    override;
    void    clearDisplayBox                 (void)  override;
    void    dspElement                      ([[maybe_unused]] bool p_recursively)   override; // test

    bool initDisplayBeginParams             (uint32_t p_idHeader);
    void setDisplayBeginParams              (uint32_t p_idHeader, kPosition_t p_position);
    bool bDisplayLastRowVsLowerBound        (void);

    uint8_t  g_displayBoxH;
    uint8_t  g_displayBoxW;

    uint32_t g_displayBeginIdHeader;
    uint32_t g_displayBeginIdData;
    uint32_t g_displayBeginDataSize;
    int32_t  g_displayBeginY0r;
    uint32_t g_displayBeginH;

    // section end   **** DISPLAY ***** 
    // ****************************************************
    // --------------------------
// ****************************************************
// section start **** INPUT EVENTS: SELECTION & MOUSE ROLL *****
    public:
        bool    selectElementLast               (void);
        void*   getSelectedItem                 (void) override;
        void*   getSelectedItemPtrData          (void);

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

        uint32_t g_selectHeaderId;

    // section end   **** INPUT EVENTS: SELECTION & MOUSE ROLL ***** 
    // ****************************************************


};


#endif 	// DTY_CNTNR_1_STREAM_LIST_X_H
