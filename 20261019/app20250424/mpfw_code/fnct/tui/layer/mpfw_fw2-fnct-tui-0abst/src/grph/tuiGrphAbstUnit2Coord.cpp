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
 * tuiGrphAbstUnit2Coord.cpp
 *
 *  Created on: Jan, 29th 2025 (Wed)
 *      Author: Marco Dau
 */

#include "tuiGrphAbstUnit2Coord.h"


// ****************************************************
// section start **** CONSTRUCTOR *****
    // protected:

    tuiGrphAbstUnit2Coord_t::tuiGrphAbstUnit2Coord_t    (void)      :
         g_x0r              {0}
        ,g_y0r              {0}
        ,g_x0a              {0}
        ,g_y0a              {0}
        ,g_mouseX0a         {0}
        ,g_mouseY0a         {0}
        ,g_marginXleft      {0}
        ,g_marginXright     {0}
        ,g_marginYtop       {0}
        ,g_marginYbottom    {0}
        ,g_w                {0}
        ,g_h                {0}
    {}


    tuiGrphAbstUnit2Coord_t::tuiGrphAbstUnit2Coord_t    (box_t p_box    )      :
         g_x0r              {p_box.xStart}
        ,g_y0r              {p_box.yStart}
        ,g_x0a              {0}
        ,g_y0a              {0}
        ,g_mouseX0a         {0}
        ,g_mouseY0a         {0}
        ,g_marginXleft      {1} // default margin = 1
        ,g_marginXright     {1} // default margin = 1
        ,g_marginYtop       {1} // default margin = 1
        ,g_marginYbottom    {1} // default margin = 1
        ,g_w                {p_box.width}
        ,g_h                {p_box.height}
    {}

    tuiGrphAbstUnit2Coord_t::tuiGrphAbstUnit2Coord_t    (                margins_t p_margin)      :
         g_x0r              {0}
        ,g_y0r              {0}
        ,g_x0a              {0}
        ,g_y0a              {0}
        ,g_mouseX0a         {0}
        ,g_mouseY0a         {0}
        ,g_marginXleft      {p_margin.Left}
        ,g_marginXright     {p_margin.Right}
        ,g_marginYtop       {p_margin.Top}
        ,g_marginYbottom    {p_margin.Bottom}
        ,g_w                {0}
        ,g_h                {0}
    {}

    tuiGrphAbstUnit2Coord_t::tuiGrphAbstUnit2Coord_t    (box_t p_box    ,margins_t p_margin)      :
         g_x0r              {p_box.xStart}
        ,g_y0r              {p_box.yStart}
        ,g_x0a              {0}
        ,g_y0a              {0}
        ,g_mouseX0a         {0}
        ,g_mouseY0a         {0}
        ,g_marginXleft      {p_margin.Left}
        ,g_marginXright     {p_margin.Right}
        ,g_marginYtop       {p_margin.Top}
        ,g_marginYbottom    {p_margin.Bottom}
        ,g_w                {p_box.width}
        ,g_h                {p_box.height}
    {}

    // section end   **** CONSTRUCTOR *****
    // ****************************************************
    // --------------------------
// ****************************************************
// section start **** INIT *****

    #define MAX(a,b) (a > b) ? a : b
    #define MIN(a,b) (a < b) ? a : b
    #define G_P_PARENT  static_cast<tuiGrphAbstUnit2Coord_t*>(g_pParent)

    void tuiGrphAbstUnit2Coord_t::initCoordBase       (void) 	{
        // g_x0a           = G_P_PARENT->getDspAreaAbsRefX() + g_x0r;
        // g_y0a           = G_P_PARENT->getDspAreaAbsRefY() + g_y0r;

        g_x0a           = g_pParent->getDspAreaAbsRefX() + g_x0r;
        g_y0a           = g_pParent->getDspAreaAbsRefY() + g_y0r;

        initCoordNdspBox();
        initBoundsBase();
        if(!g_w) updDimW();
        if(!g_h) updDimH();
    }

    void tuiGrphAbstUnit2Coord_t::initCoordWin       (void) 	{
    // -     updAbsCoords();
        g_x0a           = 0;
        g_y0a           = 0;

        initCoordNdspBox();
        initBoundsWin();

    }

    void tuiGrphAbstUnit2Coord_t::initCoordNdspBox       (void) 	{
        g_mouseX0a      = G_P_PARENT->getMouseAreaAbsRefX()  + g_x0r;
        g_mouseY0a      = G_P_PARENT->getMouseAreaAbsRefY()  + g_y0r;

        g_dspAreaW       = G_P_PARENT->getDspAreaDimXw();
        g_dspAreaH       = G_P_PARENT->getDspAreaDimYh();
    }

    void tuiGrphAbstUnit2Coord_t::initBoundsBase       (void) 	{

        g_boundXleft    = MAX(G_P_PARENT->getBoundXleft(),  g_x0a           );
        g_boundXright   = MIN(G_P_PARENT->getBoundXright(), g_x0a + g_w - 1 );

        g_boundYupper   = MAX(G_P_PARENT->getBoundYupper(), g_y0a           );
        g_boundYlower   = MIN(G_P_PARENT->getBoundYlower(), g_y0a + g_h - 1 );

    }

    void tuiGrphAbstUnit2Coord_t::initBoundsWin       (void) 	{

        // -     updBounds();
        g_boundXleft    = MAX(G_P_PARENT->getBoundXleft(),  g_mouseX0a           );
        //g_boundXleft = 0;
        g_boundXright   = MIN(G_P_PARENT->getBoundXright(), g_mouseX0a + g_w - 1 );
        //g_boundXright = g_w - 1;
        g_w = g_boundXright - g_boundXleft + 1;
        g_boundXleft = 0;
        g_boundXright = g_w - 1;

        // g_boundYupper   = MAX(G_P_PARENT->getBoundYupper(), g_mouseY0a           );
        g_boundYupper = 0;
        // g_boundYlower   = MIN(G_P_PARENT->getBoundYlower(), g_mouseY0a + g_h - 1 );
        g_boundYlower = g_h - 1;

    }

    void tuiGrphAbstUnit2Coord_t::initBoundsWinRoot (void)    {
        g_boundXleft = 0;
        g_boundXright = g_w - 1;
        g_boundYupper = 0;
        g_boundYlower = g_h - 1;
    }

        //     void tuiGrphAbstUnit2Coord_t::setParent                       (tuiGrphAbstUnit2Coord_t* p_pParent) {
        //         g_pParent = p_pParent;
        //     }
        // 
        //     tuiGrphAbstUnit2Coord_t* tuiGrphAbstUnit2Coord_t::getParent         (void)  {
        //         return g_pParent;
        //     }

    // section end   **** INIT *****
    // ****************************************************
    // --------------------------
// ****************************************************
// section start **** AVAILABLE DISPLAY AREA *****
    // - parent available display area dimensions

    int32_t tuiGrphAbstUnit2Coord_t::getDspAreaAbsRefX      (void)      {
        return g_x0a + g_marginXleft;
    }

    int32_t tuiGrphAbstUnit2Coord_t::getDspAreaAbsRefY      (void)      {
        return g_y0a + g_marginYtop;
    }

    int32_t tuiGrphAbstUnit2Coord_t::getMouseAreaAbsRefX       (void)      {
        return g_mouseX0a + g_marginXleft;
    }

    int32_t tuiGrphAbstUnit2Coord_t::getMouseAreaAbsRefY       (void)      {
        return g_mouseY0a + g_marginYtop;
    }

    uint16_t tuiGrphAbstUnit2Coord_t::getDspAreaDimXw      (void)  {
        return g_w - (g_marginXleft + g_marginXright);
    }

    uint16_t tuiGrphAbstUnit2Coord_t::getDspAreaDimYh      (void)  {
        return g_h - (g_marginYtop + g_marginYbottom);
    }

    void tuiGrphAbstUnit2Coord_t::updDspAreaDims       (void)   {
        g_dspAreaW = G_P_PARENT->getDspAreaDimXw();
        g_dspAreaH = G_P_PARENT->getDspAreaDimYh();
    }

    // section end   **** AVAILABLE DISPLAY AREA *****
    // ****************************************************
    // --------------------------
// ****************************************************
// section start **** PARAMETERS *****

    void tuiGrphAbstUnit2Coord_t::updParams   (void)     {
        updAbsCoords();
        updDspAreaDims();
        updBounds();

        updCoordNboundsChilds();
    }

    void tuiGrphAbstUnit2Coord_t::updCoordNboundX   (void)     {
        updAbsCoordX();
        updBoundX();
    }

    void tuiGrphAbstUnit2Coord_t::updCoordNboundY   (void)     {
        updAbsCoordY();
        updBoundY();
    }

    void tuiGrphAbstUnit2Coord_t::updCoordNboundS   (void)     {
        updAbsCoords();
        updBounds();
    }

    void tuiGrphAbstUnit2Coord_t::updParamsAfterParentMod   (void)     {
        initCoordNdspBox();
        initBoundsBase();
    
        updCoordNboundsChilds();
    }
    

    // section end   **** PARAMETERS *****
    // ****************************************************
    // --------------------------
// ****************************************************
// section start **** COORDINATES *****

    void tuiGrphAbstUnit2Coord_t::initRelCoordX               (int32_t p_x)       {
        g_x0r       = p_x;
    }

    int32_t tuiGrphAbstUnit2Coord_t::getRelCoordX       (void)   {
        return g_x0r;
    }

    void tuiGrphAbstUnit2Coord_t::setRelCoordX                (int32_t p_x)       {
        g_x0r = p_x;
        updCoordNboundX();
    }

    void tuiGrphAbstUnit2Coord_t::incRelCoordX                (int32_t p_delta)   {
        g_x0r += p_delta;
        updCoordNboundX();
        updCoordNboundsChilds();
    }

    void tuiGrphAbstUnit2Coord_t::initRelCoordY               (int32_t p_y)       {
        g_y0r       = p_y;
    }

    int32_t tuiGrphAbstUnit2Coord_t::getRelCoordY       (void)   {
        return g_y0r;
    }

    void tuiGrphAbstUnit2Coord_t::setRelCoordY                (int32_t p_y)       {
        g_y0r = p_y;
        updCoordNboundY();
    }

    void tuiGrphAbstUnit2Coord_t::incRelCoordY                (int32_t p_delta)   {
        g_y0r += p_delta;
        updCoordNboundY();
        updCoordNboundsChilds();
    }

    void tuiGrphAbstUnit2Coord_t::initRelCoordS               (int32_t p_x, int32_t p_y)      {
        initRelCoordX(p_x);
        initRelCoordY(p_y);
    }

    void tuiGrphAbstUnit2Coord_t::setRelCoords                (int32_t p_x, int32_t p_y)      {
        g_x0r = p_x; 
        g_y0r = p_y;
        updCoordNboundS();
    }

    void tuiGrphAbstUnit2Coord_t::updAbsCoordX                 (void)      {
        g_x0a          = G_P_PARENT->getDspAreaAbsRefX() + g_x0r;
        g_mouseX0a     = G_P_PARENT->getMouseAreaAbsRefX()  + g_x0r;
    }
    
    void tuiGrphAbstUnit2Coord_t::updAbsCoordY                 (void)      {
        g_y0a          = G_P_PARENT->getDspAreaAbsRefY() + g_y0r;
        g_mouseY0a     = G_P_PARENT->getMouseAreaAbsRefY()  + g_y0r;
    }

    void tuiGrphAbstUnit2Coord_t::updAbsCoords                 (void)      {
        g_x0a          = G_P_PARENT->getDspAreaAbsRefX() + g_x0r;
        g_y0a          = G_P_PARENT->getDspAreaAbsRefY() + g_y0r;

        g_mouseX0a     = G_P_PARENT->getMouseAreaAbsRefX()  + g_x0r;
        g_mouseY0a     = G_P_PARENT->getMouseAreaAbsRefY()  + g_y0r;
    }

    // section end   **** COORDINATES *****
    // ****************************************************
    // --------------------------
// ****************************************************
// section start **** MARGINS *****

    // section end   **** MARGINS *****
    // ****************************************************
    // --------------------------
// ****************************************************
// section start **** DIMENSIONS *****

    void tuiGrphAbstUnit2Coord_t::setDimW         (uint16_t p_w)     {
        g_w = p_w;
    }

    void tuiGrphAbstUnit2Coord_t::updDimW         (void)        {
        g_w = G_P_PARENT->getDspAreaDimXw();
    }

    uint16_t tuiGrphAbstUnit2Coord_t::getDimW     (void)     {
        return g_w;
    }

    void tuiGrphAbstUnit2Coord_t::setDimH         (uint16_t p_h)     {
        g_h = p_h;
    }

    void tuiGrphAbstUnit2Coord_t::updDimH         (void)        {
        //g_h = G_P_PARENT->getDspAreaDimYh();
        g_h = 1;
    }

    uint16_t tuiGrphAbstUnit2Coord_t::getDimH     (void)     {
        return g_h;
    }

    void tuiGrphAbstUnit2Coord_t::setDims         (uint16_t p_w, uint16_t p_h)        {
        g_w = p_w;
        g_h = p_h;
    }

    void tuiGrphAbstUnit2Coord_t::updDims         (void)        {
        g_w = G_P_PARENT->getDspAreaDimXw();
        g_h = G_P_PARENT->getDspAreaDimYh();
    }

    // section end   **** DIMENSIONS *****
    // ****************************************************
    // --------------------------
// ****************************************************
// section start **** BOUNDS *****

    int32_t tuiGrphAbstUnit2Coord_t::getBoundXleft             (void)      {
        //return (g_boundXleft  == g_x0a)                  ? g_boundXleft + 1 : g_boundXleft;
        return MAX(g_boundXleft, (g_x0a + g_marginXleft));
    }

    int32_t tuiGrphAbstUnit2Coord_t::getBoundXright            (void)      {
        //return ((g_boundXright + 1)  == (g_x0a + g_w))   ? g_boundXright - 1 : g_boundXright;
        return MIN(g_boundXright, ((g_x0a + g_w - 1) - g_marginXright));
    }

    void tuiGrphAbstUnit2Coord_t::updBoundX                    (void)      {
        g_boundXleft  = MAX(G_P_PARENT->getBoundXleft(),  g_x0a           );
        g_boundXright = MIN(G_P_PARENT->getBoundXright(), g_x0a + g_w - 1 );
    }

    //      - vertical coords

    int32_t tuiGrphAbstUnit2Coord_t::getBoundYupper            (void)      {
        return MAX(g_boundYupper, (g_y0a + g_marginYtop));
    }

    int32_t tuiGrphAbstUnit2Coord_t::getBoundYlower            (void)      {
        return MIN(g_boundYlower, ((g_y0a + g_h - 1) - g_marginYbottom));
    }

    void tuiGrphAbstUnit2Coord_t::updBoundY                    (void)      {
        g_boundYupper = MAX(G_P_PARENT->getBoundYupper(), g_y0a           );
        g_boundYlower = MIN(G_P_PARENT->getBoundYlower(), g_y0a + g_h - 1 );
    }

    //      - all coords

    void tuiGrphAbstUnit2Coord_t::updBounds                    (void)        {
        g_boundXleft  = MAX(G_P_PARENT->getBoundXleft(),  g_x0a           );
        g_boundXright = MIN(G_P_PARENT->getBoundXright(), g_x0a + g_w - 1 );

        g_boundYupper = MAX(G_P_PARENT->getBoundYupper(), g_y0a           );
        g_boundYlower = MIN(G_P_PARENT->getBoundYlower(), g_y0a + g_h - 1 );
    }


    // section end   **** BOUNDS *****
    // ****************************************************
    // --------------------------
// ****************************************************
// section start **** MOUSE CLICK MANAGEMENT *****
    uint16_t tuiGrphAbstUnit2Coord_t::g_xMouse;
    uint16_t tuiGrphAbstUnit2Coord_t::g_yMouse;
    // public:
    bool tuiGrphAbstUnit2Coord_t::bMouseClickInsideBounds (void)      {
        bool l_result = false;

        if(g_boundYupper <= g_boundYlower)    {
            uint16_t l_deltaX = (g_mouseX0a - g_x0a);   // (g_mouseX0a - g_x0a) is the delta between  root window & secondary windows (see ncureses library function)
            uint16_t l_boundLeft  = g_boundXleft  + l_deltaX; 
            uint16_t l_boundRight = g_boundXright + l_deltaX;

            uint16_t l_deltaY = (g_mouseY0a - g_y0a);   // idem like x-coords
            uint16_t l_boundUpper = g_boundYupper + l_deltaY; 
            uint16_t l_boundLower = g_boundYlower + l_deltaY;
            if(
                    ( (l_boundLeft  <= g_xMouse) && (g_xMouse <=  l_boundRight)  )
                &&  ( (l_boundUpper <= g_yMouse) && (g_yMouse <=  l_boundLower)  )
            ) {
                l_result = true;
            }
        }
        return l_result;
    }

    void tuiGrphAbstUnit2Coord_t::updAbsMouseCoordX       (int16_t p_deltaX)   {
        g_xMouse += p_deltaX;
    }

    void tuiGrphAbstUnit2Coord_t::updAbsMouseCoordY       (int16_t p_deltaY)   {
        g_yMouse += p_deltaY;
    }

    // section end   **** MOUSE CLICK MANAGEMENT *****
    // ****************************************************
    // --------------------------
// ****************************************************
// section start **** CURSOR MANAGEMENT *****
    uint16_t tuiGrphAbstUnit2Coord_t::g_xCursor;
    uint16_t tuiGrphAbstUnit2Coord_t::g_yCursor;
    uint16_t tuiGrphAbstUnit2Coord_t::g_position;

    // section end   **** CURSOR MANAGEMENT *****
    // ****************************************************
    // --------------------------
// ****************************************************
// section start **** CONTAINER FUNCTION INTERFACE *****

    int32_t tuiGrphAbstUnit2Coord_t::getDistanceFromBound   (void)   {
        if(g_y0a < g_boundYupper)
            return g_boundYupper - g_y0a;

        //  parent bounds         ----U-L---------
        //  select element box    -------o--------  o = u & l (element with g_h=1)
        //  select element bounds ------Lu--------
        if((g_boundYlower + 1) < (g_y0a + g_h))
            return (g_boundYlower + 1) - (g_y0a + g_h);

        return 0;
    }

    int16_t tuiGrphAbstUnit2Coord_t::getDisplayMaxH      (void)  {
        return g_h - (g_marginYtop + g_marginYbottom);
    }

    bool tuiGrphAbstUnit2Coord_t::bVisibleCompletely   (void)  {
        return (
                    ( g_boundYupper    ==  g_y0a)
                &&  ((g_boundYlower+1) == (g_y0a + g_h))
        );
    }

    void tuiGrphAbstUnit2Coord_t::updCoordNboundsChilds    (void)       {
        // a possible implementation is the following
        // g_cntr->updCoordNboundsChilds();
    }

    // section end   **** CONTAINER FUNCTION INTERFACE *****
    // ****************************************************
    // --------------------------

