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
 * tuiGrphAbstUnit3Event.cpp
 *
 *  Created on: Jan, 30th 2025 (Thu)
 *      Author: Marco Dau
 */
 

#include "tuiGrphAbstUnit3Event.h"

#include <stdio.h>

tuiGrphAbstUnit3Event_t::tuiGrphAbstUnit3Event_t       (dtyIntfcAbstractUnitFunctional_t* p_pUnit    )    :
     tuiGrphAbstUnit2Coord_t    ()
    ,g_pUnit                    {p_pUnit}
{}

tuiGrphAbstUnit3Event_t::tuiGrphAbstUnit3Event_t       (dtyIntfcAbstractUnitFunctional_t* p_pUnit    ,box_t p_box    )    :
     tuiGrphAbstUnit2Coord_t    (p_box)
    ,g_pUnit                    {p_pUnit}
{}

tuiGrphAbstUnit3Event_t::tuiGrphAbstUnit3Event_t       (dtyIntfcAbstractUnitFunctional_t* p_pUnit                    ,margins_t p_margin )    :
     tuiGrphAbstUnit2Coord_t    (p_margin)
    ,g_pUnit                    {p_pUnit}
{}

tuiGrphAbstUnit3Event_t::tuiGrphAbstUnit3Event_t       (dtyIntfcAbstractUnitFunctional_t* p_pUnit    ,box_t p_box    ,margins_t p_margin )    :
     tuiGrphAbstUnit2Coord_t    (p_box, p_margin)
    ,g_pUnit                    {p_pUnit}
{}

bool tuiGrphAbstUnit3Event_t::bNotNull       	    (void)  {
    return (nullptr != g_pUnit);
}

bool tuiGrphAbstUnit3Event_t::initChildren       (void) 	{
    return true;
}

bool tuiGrphAbstUnit3Event_t::loop            (void)  {
    g_pUnit->loop(this);
    return false;
}

bool tuiGrphAbstUnit3Event_t::loopChildren    (void)  {
    return true;
}


void tuiGrphAbstUnit3Event_t::end 	        (void)      {
}

void tuiGrphAbstUnit3Event_t::endChildren  (void)      {
}


void tuiGrphAbstUnit3Event_t::clear            (void)  {
    g_pUnit->clear(this);
}

void tuiGrphAbstUnit3Event_t::display          (void)  {
    g_pUnit->display(this);
}

void tuiGrphAbstUnit3Event_t::display          (bool p_recursively)  {
    g_pUnit->display(this, p_recursively);
}

// --------------------- Container section - START
void tuiGrphAbstUnit3Event_t::updCoordNboundsChilds    (void)       {
    
    g_pUnit->updCoordNboundsChilds();
}
// --------------------- Container section - END


bool tuiGrphAbstUnit3Event_t::select           (void)  {
    return g_pUnit->select(this);
}

bool tuiGrphAbstUnit3Event_t::deSelect         (void)  {
    return g_pUnit->deSelect(this);
}

void tuiGrphAbstUnit3Event_t::eventOn          (void)  {
    g_pUnit->eventOn(this);
}

bool tuiGrphAbstUnit3Event_t::selectByMouse    (void)  {
    return g_pUnit->selectByMouse(this);
}

bool tuiGrphAbstUnit3Event_t::selectTst        (void)  {
    return (g_status == tuiState_t::select) || (g_status == tuiState_t::eventOn);
}

void tuiGrphAbstUnit3Event_t::dbgState_01          (void)  {
    char l_str[100];
    snprintf(l_str, sizeof(l_str),"sts %02d - stsX %02d - %s", g_debugStatus, g_debugStatusX, g_pUnit->getName());
    //mvwprintw   (stdscr, 2, 100, "*** deselect status debug: sts %02d - stsX %02d ***", g_debugStatus, g_debugStatusX);
    dbgPrint    (l_str);
}

void tuiGrphAbstUnit3Event_t::dbgState_01          (bool p_test)  {
    char l_str[100];
    if(p_test)
        // mvwprintw   (stdscr, 2, 80, "*** deselect status debug: sts %02d - stsX %02d - parent match---", g_debugStatus, g_debugStatusX);
        snprintf(l_str, sizeof(l_str),"sts %02d - stsX %02d - %s -  true", g_debugStatus, g_debugStatusX, g_pUnit->getName());
    else
        // mvwprintw   (stdscr, 2, 80, "*** deselect status debug: sts %02d - stsX %02d - parent NO match", g_debugStatus, g_debugStatusX);
        snprintf(l_str, sizeof(l_str),"sts %02d - stsX %02d - %s - false", g_debugStatus, g_debugStatusX, g_pUnit->getName());

    dbgPrint    (l_str);
}

void tuiGrphAbstUnit3Event_t::vEventHndlKey_down	        (tuiGrphAbstUnit3Event_t* p_this)  {
    p_this->g_pUnit->vEventHndlKey_down(p_this);
}

void tuiGrphAbstUnit3Event_t::vEventHndlKey_up	            (tuiGrphAbstUnit3Event_t* p_this)  {
    p_this->g_pUnit->vEventHndlKey_up(p_this);
}

void tuiGrphAbstUnit3Event_t::vEventHndlKey_left	        (tuiGrphAbstUnit3Event_t* p_this)  {
    p_this->g_pUnit->vEventHndlKey_left(p_this);
}

void tuiGrphAbstUnit3Event_t::vEventHndlKey_right	        (tuiGrphAbstUnit3Event_t* p_this)  {
    p_this->g_pUnit->vEventHndlKey_right(p_this);
}

void tuiGrphAbstUnit3Event_t::vEventHndlKey_enter	        (tuiGrphAbstUnit3Event_t* p_this)  {
    p_this->g_pUnit->vEventHndlKey_enter(p_this);
}

void tuiGrphAbstUnit3Event_t::vEventHndlKey_home	        (tuiGrphAbstUnit3Event_t* p_this)  {
    p_this->g_pUnit->vEventHndlKey_home(p_this);
}

void tuiGrphAbstUnit3Event_t::vEventHndlKey_del            (tuiGrphAbstUnit3Event_t* p_this)  {
    p_this->g_pUnit->vEventHndlKey_del(p_this);
}

void tuiGrphAbstUnit3Event_t::vEventHndlKey_backSpace      (tuiGrphAbstUnit3Event_t* p_this)  {
    p_this->g_pUnit->vEventHndlKey_backSpace(p_this);
}

void tuiGrphAbstUnit3Event_t::vEventHndlKey_typeChar       (tuiGrphAbstUnit3Event_t* p_this)  {
    p_this->g_pUnit->vEventHndlKey_typeChar(p_this);
}

tuiGrphAbstUnit3Event_t::eventHandler_t tuiGrphAbstUnit3Event_t::g_eventKeyArray[]  = {
     vEventHndlKey_down
    ,vEventHndlKey_up
    ,vEventHndlKey_left
    ,vEventHndlKey_right
    ,vEventHndlKey_enter
    ,vEventHndlKey_home
    ,vEventHndlKey_del
    ,vEventHndlKey_backSpace
    ,vEventHndlKey_typeChar
};


void tuiGrphAbstUnit3Event_t::vEventHndlMouse_rollUp       (tuiGrphAbstUnit3Event_t* p_this)  {
    p_this->g_pUnit->vEventHndlMouse_rollUp(p_this);
}

void tuiGrphAbstUnit3Event_t::vEventHndlMouse_rollDown     (tuiGrphAbstUnit3Event_t* p_this)  {
    p_this->g_pUnit->vEventHndlMouse_rollDown(p_this);
}

tuiGrphAbstUnit3Event_t::eventHandler_t tuiGrphAbstUnit3Event_t::g_eventMouseArray[]  = {
     vEventHndlMouse_rollUp
    ,vEventHndlMouse_rollDown
};

void tuiGrphAbstUnit3Event_t::debug_01         (void)  {

}
