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
 * tuiFnctRealUnit1Ebox.h
 *
 *  Created on: Jan, 31st 2025 (Fri)
 *      Author: Marco Dau
 */
 

#include "tuiFnctRealUnit1Ebox.h"


tuiFnctRealUnit1Ebox_t::tuiFnctRealUnit1Ebox_t      (const char* p_strName  ,dtyBaseArray_t& p_rDtyStr   )   :
    tuiFnctAbstUnit0_t       (p_strName)
    ,g_rDtyStr              {p_rDtyStr}
    ,g_pFuncOwner           {nullptr}
    ,g_func                 {nullptr}
{}

tuiFnctRealUnit1Ebox_t::tuiFnctRealUnit1Ebox_t      (const char* p_strName  ,dtyBaseArray_t& p_rDtyStr  ,tuiFnctAbstUnit0_t* p_pFuncOwner ,tuiUnitFunc_t p_func   )    :
    tuiFnctAbstUnit0_t       (p_strName)
    ,g_rDtyStr              {p_rDtyStr}
    ,g_pFuncOwner           {p_pFuncOwner}
    ,g_func                 {p_func}
{}

// --------------------- Process section - START

bool tuiFnctRealUnit1Ebox_t::init   	            ([[maybe_unused]] dtyIntfcAbstractUnitGraphic_t* p_this)  {
    g_rDtyStr.initDsplyBox(p_this->getDspAreaDimXw());

    return true;
}

// --------------------- Process section - END


// --------------------- Display section - START

void tuiFnctRealUnit1Ebox_t::clear     	        (dtyIntfcAbstractUnitGraphic_t* p_this)  {
    p_this->frameClear();
}

void tuiFnctRealUnit1Ebox_t::display     	    (dtyIntfcAbstractUnitGraphic_t* p_this)  {
    p_this->frameNnameTest(g_strName);

    uint8_t l_size = g_rDtyStr.sizeDsplyStrFromBeginGet();
    if(l_size)  {
        p_this->content(g_rDtyStr.pDsplyStrBeginGet(), l_size);
    }
}

void tuiFnctRealUnit1Ebox_t::display     	    (dtyIntfcAbstractUnitGraphic_t* p_this, [[maybe_unused]] bool p_recursively)  {
    display(p_this);
}


// --------------------- Display section - END


// --------------------- State management section - START
#define CURSOR_HIDE false
#define CURSOR_SHOW true

bool tuiFnctRealUnit1Ebox_t::select     	        (dtyIntfcAbstractUnitGraphic_t* p_this)  {
    uint8_t l_position = g_rDtyStr.positionDsplyGet();
    p_this->positionCursor(CURSOR_HIDE,l_position);
    return p_this->frameNnameTest(tuiState_t::select, g_strName);    
}

bool tuiFnctRealUnit1Ebox_t::deSelect   	        (dtyIntfcAbstractUnitGraphic_t* p_this)  {
    uint8_t l_position = g_rDtyStr.positionDsplyGet();
    p_this->positionCursor(CURSOR_HIDE,l_position);
    return p_this->frameNnameTest(tuiState_t::deselect, g_strName);
}

void tuiFnctRealUnit1Ebox_t::eventOn    	        (dtyIntfcAbstractUnitGraphic_t* p_this)  {
    p_this->frameNnameTest(tuiState_t::eventOn, g_strName);
    // cursor management
    uint8_t l_position = g_rDtyStr.positionDsplyGet();
    p_this->positionCursor(CURSOR_SHOW,l_position);
}

bool tuiFnctRealUnit1Ebox_t::selectByMouse          (dtyIntfcAbstractUnitGraphic_t* p_this)  {
    p_this->deselectBackNeventOn();
    return true;
}


// --------------------- State management section - END

// --------------------- Events handler section - START

void tuiFnctRealUnit1Ebox_t::vEventHndlKey_down	(dtyIntfcAbstractUnitGraphic_t* p_this)  {
    g_rDtyStr.positionEnd();
    display(p_this);
    // cursor management
    uint8_t l_position = g_rDtyStr.positionDsplyGet();
    p_this->positionCursor(true,l_position);
}

void tuiFnctRealUnit1Ebox_t::vEventHndlKey_up	(dtyIntfcAbstractUnitGraphic_t* p_this)  {
    g_rDtyStr.positionBegin();
    display(p_this);
    // cursor management
    uint8_t l_position = g_rDtyStr.positionDsplyGet();
    p_this->positionCursor(true,l_position);
}

void tuiFnctRealUnit1Ebox_t::vEventHndlKey_left	(dtyIntfcAbstractUnitGraphic_t* p_this)  {
    if(g_rDtyStr.dsplyPositionDec())
        display(p_this);
    // cursor management
    uint8_t l_position = g_rDtyStr.positionDsplyGet();
    p_this->positionCursor(true,l_position);
}

void tuiFnctRealUnit1Ebox_t::vEventHndlKey_right	(dtyIntfcAbstractUnitGraphic_t* p_this)  {
    if(g_rDtyStr.dsplyPositionInc())
        display(p_this);
    // cursor management
    uint8_t l_position = g_rDtyStr.positionDsplyGet();
    p_this->positionCursor(true,l_position);
}

void tuiFnctRealUnit1Ebox_t::vEventHndlKey_enter	([[maybe_unused]] dtyIntfcAbstractUnitGraphic_t* p_this)  {
    if(g_func)  {
        g_func(g_pFuncOwner);
    } else {
        setStatus_toSuspend();
    }
}

void tuiFnctRealUnit1Ebox_t::vEventHndlKey_home	(dtyIntfcAbstractUnitGraphic_t* p_this)  {
    p_this->parentDeselectBackNeventOn();

}

void tuiFnctRealUnit1Ebox_t::vEventHndlKey_del	(dtyIntfcAbstractUnitGraphic_t* p_this)  {
    g_rDtyStr.del();

    uint8_t l_size  = g_rDtyStr.sizeDsplyStrFromPositionGet();
    uint8_t l_begin = g_rDtyStr.positionDsplyGet();
    if(l_size)
        p_this->content(g_rDtyStr.pDsplyStrPositionGet(), l_begin, l_size);
    else
        p_this->content(l_begin);

    p_this->positionCursor(true,l_begin);
}

void tuiFnctRealUnit1Ebox_t::vEventHndlKey_backSpace	(dtyIntfcAbstractUnitGraphic_t* p_this)  {
    if(g_rDtyStr.positionGet())     {
        if(g_rDtyStr.backSpace())
            display(p_this);

        uint8_t l_size  = g_rDtyStr.sizeDsplyStrFromPositionGet();
        uint8_t l_begin = g_rDtyStr.positionDsplyGet();
        if(l_size)
            p_this->content(g_rDtyStr.pDsplyStrPositionGet(), l_begin, l_size);
        else
            p_this->content(l_begin);

        p_this->positionCursor(true,l_begin);

    }
}

void tuiFnctRealUnit1Ebox_t::vEventHndlKey_typeChar	(dtyIntfcAbstractUnitGraphic_t* p_this)  {
    if(g_rDtyStr.ins(p_this->uiEventKeyCode()))
         display(p_this);

    uint8_t l_size  = g_rDtyStr.sizeDsplyStrFromPositionPrevGet();
    uint8_t l_begin = g_rDtyStr.positionDsplyGet();
    if(l_size)
        p_this->content(g_rDtyStr.pDsplyStrPositionPrevGet(), l_begin-1, l_size);
    else
        p_this->content(l_begin);

    p_this->positionCursor(true,l_begin);
}


// --------------------- Events handler section - START

// --------------------- Specific Data section - START

void tuiFnctRealUnit1Ebox_t::insertString  (const char* p_str) {
    g_rDtyStr.ins(p_str);
}

void tuiFnctRealUnit1Ebox_t::refreshDisplay  (dtyIntfcAbstractUnitGraphic_t* p_this) {
    display(p_this);
}


// --------------------- Specific Data section - END

// --------------------- STATUS MANAGEMENT section - START
    
void tuiFnctRealUnit1Ebox_t::setStatus              (kStatus_t p_status)     {
    g_status = p_status;
}

void tuiFnctRealUnit1Ebox_t::setStatus_toEdit       (void)   {
    g_status = edit;
}

void tuiFnctRealUnit1Ebox_t::setStatus_toSuspend    (void)   {
    g_status = suspend;
}

tuiFnctRealUnit1Ebox_t::kStatus_t tuiFnctRealUnit1Ebox_t::getStatus         (void)   {
    return g_status;
}

bool tuiFnctRealUnit1Ebox_t::chkStatusSuspend       (void)   {
    return  (suspend == g_status);
}


// --------------------- STATUS MANAGEMENT section - END
