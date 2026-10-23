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
 * tuiGrphAbstUnit2Coord.h
 *
 *  Created on: Jan, 29th 2025 (Wed)
 *      Author: Marco Dau
 */
 
#ifndef TUI_GRPH_ABST_UNIT_COORD_H
#define TUI_GRPH_ABST_UNIT_COORD_H

#include "tuiGrphAbstUnit1State.h"

class tuiGrphAbstUnit2Coord_t:  public tuiGrphAbstUnit1State_t {

// ****************************************************
// section start **** CONSTRUCTOR *****
    protected:
        tuiGrphAbstUnit2Coord_t ();
        tuiGrphAbstUnit2Coord_t (box_t p_box  );
        tuiGrphAbstUnit2Coord_t (              margins_t p_margin);
        tuiGrphAbstUnit2Coord_t (box_t p_box  ,margins_t p_margin);
    // section end   **** CONSTRUCTOR *****
    // ****************************************************
    // --------------------------
// ****************************************************
// section start **** INIT *****

    public:
        void initCoordBase      (void);
        void initCoordWin       (void);
        void initCoordNdspBox   (void);
        void initBoundsBase     (void);
        void initBoundsWin      (void);
        void initBoundsWinRoot  (void);

        // void                setParent   (tuiGrphAbstUnit2Coord_t* p_pParent);
        // tuiGrphAbstUnit2Coord_t*  getParent   (void);

    private:
        // tuiGrphAbstUnit2Coord_t* g_pParent;

    // section end   **** INIT *****
    // ****************************************************
    // --------------------------
// ****************************************************
// section start **** AVAILABLE DISPLAY/MOUSE AREA *****

    // - parent available display area dimensions
    public:
        int32_t     getDspAreaAbsRefX       (void) override;
        int32_t     getDspAreaAbsRefY       (void) override;
        int32_t     getMouseAreaAbsRefX     (void);
        int32_t     getMouseAreaAbsRefY     (void);
        uint16_t    getDspAreaDimXw         (void) override;
        uint16_t    getDspAreaDimYh         (void) override;
        void        updDspAreaDims          (void);

    protected:
        uint16_t g_dspAreaW; 
        uint16_t g_dspAreaH;
    // section end   **** AVAILABLE DISPLAY/MOUSE AREA *****
    // ****************************************************
    // --------------------------
// ****************************************************
// section start **** PARAMETERS *****

    protected:
        void updParams          (void);
        void updCoordNboundX    (void);
        void updCoordNboundY    (void);
        void updCoordNboundS    (void);

    public:
        void updParamsAfterParentMod            (void) override;

    // section end   **** PARAMETERS *****
    // ****************************************************
    // --------------------------
// ****************************************************
// section start **** COORDINATES *****

    public:    
        void initRelCoordX      (int32_t p_x);
        int32_t getRelCoordX       (void);
        void setRelCoordX       (int32_t p_x);
        void incRelCoordX       (int32_t p_delta);
        void initRelCoordY      (int32_t p_y);
        int32_t getRelCoordY       (void) override;
        void setRelCoordY       (int32_t p_y) override;
        void incRelCoordY       (int32_t p_delta) override;
        void initRelCoordS      (int32_t p_x, int32_t p_y) override;
        void setRelCoords       (int32_t p_x, int32_t p_y);

        void updAbsCoordX       (void);
        void updAbsCoordY       (void);
        void updAbsCoords       (void);

    protected:
        //      - relative respect parent window (N.B.: parent window can be different than root window)
        int32_t g_x0r;  
        int32_t g_y0r;

        //      - absolute respect parent window (N.B.: to set these coords you must use "updAbsCoord" functions)
        int32_t g_x0a;  
        int32_t g_y0a;
        //      - absolute respect root window (N.B.: to set these coords you must use "updAbsCoord" functions)
        //          - the mouse coords are given, by platform driver functions (i.e. ncurses library), respect root window
        int32_t g_mouseX0a;
        int32_t g_mouseY0a;

    // section end   **** COORDINATES *****
    // ****************************************************
    // --------------------------
// ****************************************************
// section start **** MARGINS *****

    protected:
        //  - margins (N.B. these parameters are set by the class constructor)
        uint8_t g_marginXleft;
        uint8_t g_marginXright;
        uint8_t g_marginYtop;
        uint8_t g_marginYbottom;
    // section end   **** MARGINS *****
    // ****************************************************
    // --------------------------
// ****************************************************
// section start **** DIMENSIONS *****
    public:    
        void setDimW        (uint16_t p_w);
        void updDimW        (void);
        uint16_t getDimW    (void) override;

        void setDimH        (uint16_t p_h) override;
        void updDimH        (void);
        uint16_t getDimH    (void) override;

        void setDims        (uint16_t p_w, uint16_t p_h);
        void updDims        (void);

    protected:
        uint16_t g_w; 
        uint16_t g_h;
    // section end   **** DIMENSIONS *****
    // ****************************************************
    // --------------------------
// ****************************************************
// section start **** BOUNDS *****
    public:
        //      - horizontal coords
        int32_t     getBoundXleft       (void) ;
        int32_t     getBoundXright      (void) ;
        void        updBoundX           (void) ;
        //      - vertical coords
        int32_t     getBoundYupper      (void) ;
        int32_t     getBoundYlower      (void) ;
        void        updBoundY           (void) override;
        //      - all coords
        void        updBounds           (void) ;

    protected:
        //  - bounds (N.B.: to set these bounds you must use "updBound" functions)
        int16_t g_boundXleft;
        int16_t g_boundXright;
        int16_t g_boundYupper;
        int16_t g_boundYlower;
    // section end   **** BOUNDS *****
    // ****************************************************
    // --------------------------
// ****************************************************
// section start **** MOUSE CLICK MANAGEMENT *****
    public:
        bool bMouseClickInsideBounds    (void) override;
        static void updAbsMouseCoordX          (int16_t p_deltaY);
        void updAbsMouseCoordY          (int16_t p_deltaY) override;

    protected:
        static uint16_t g_xMouse;
        static uint16_t g_yMouse;
    // section end   **** MOUSE CLICK MANAGEMENT *****
    // ****************************************************
    // --------------------------
// ****************************************************
// section start **** CURSOR MANAGEMENT *****

    protected:
        static uint16_t g_position;
        static uint16_t g_xCursor;
        static uint16_t g_yCursor;
    // section end   **** CURSOR MANAGEMENT *****
    // ****************************************************
    // --------------------------
// ****************************************************
// section start **** CONTAINER FUNCTION INTERFACE *****

    // functions called by container
    public:
        int32_t getDistanceFromBound                (void) override;
        int16_t getDisplayMaxH                      (void) override;
        bool    bVisibleCompletely                  (void) override;

    // sub-section ** VIRTUAL **
        void updCoordNboundsChilds              (void) override;

    // section end   **** CONTAINER FUNCTION INTERFACE *****
    // ****************************************************
    // --------------------------



};

#endif 	// TUI_GRPH_ABST_UNIT_COORD_H
