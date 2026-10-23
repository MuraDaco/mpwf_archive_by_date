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
 * tuiFnctAbstUnit1Map.cpp
 *
 *  Created on: Oct, 27th 2024
 *      Author: Marco Dau
 */
 

#include "tuiFnctAbstUnit1Map.h"

#define NO_CHILD_SELECTED 0xff

tuiFnctAbstUnit1Map_t::tuiFnctAbstUnit1Map_t      (const char* p_strName, dtyIntfcAbstractUnitGraphic_t** p_childrenSet) :
    tuiFnctAbstUnit0_t          (p_strName)
    ,g_childrenSet              {p_childrenSet}
    ,g_childCurrentId           {NO_CHILD_SELECTED}
    ,g_childrenNum              {0}
    ,g_bChildrenSetEmpty        {true}
{}

bool tuiFnctAbstUnit1Map_t::init   	            ([[maybe_unused]] dtyIntfcAbstractUnitGraphic_t* p_this)  {
    initChildren(p_this);
    return true;
}

bool tuiFnctAbstUnit1Map_t::initChildren       (dtyIntfcAbstractUnitGraphic_t* p_this) 	{

    // check children set existence
    if(!g_childrenSet)
        // children set does not exist, therefore ...
        // do nothing & exit
        return false; 


    // run [init] function for each [child]
    // the loop end condition is when you meet a child (the last child of the set) with a null tuiUnit obiect (g_pUnit == nullptr)
    uint8_t l_id = 0;
    //while(g_childrenSet[l_id]->bNotNull())    {
    while(g_childrenSet[l_id])    {
        g_childrenSet[l_id]->init(p_this);
        l_id++;

    }
    
    // check the status of children set (weather it is empty or not); default status is empty (g_bChildrenSetEmpty = false, see constructor)
    if(l_id) {
        // childen set is NOT empty
        g_bChildrenSetEmpty = false;
        // initialize last child of the set
        g_childrenNum = l_id;
    }

    return true;
}

void tuiFnctAbstUnit1Map_t::display     	    (dtyIntfcAbstractUnitGraphic_t* p_this)  {
    p_this->frameNnameTest(g_strName);
}

void tuiFnctAbstUnit1Map_t::display     	    (dtyIntfcAbstractUnitGraphic_t* p_this, bool p_recursively)  {
    display(p_this);
    if(p_recursively) displayChildren(p_this, p_recursively);
}

void tuiFnctAbstUnit1Map_t::displayChildren     ([[maybe_unused]] dtyIntfcAbstractUnitGraphic_t* p_this, bool p_recursively)    {
    if(g_bChildrenSetEmpty) return;

    for(uint8_t l_id=0; l_id<g_childrenNum; l_id++) g_childrenSet[l_id]->display(p_recursively);
}

void tuiFnctAbstUnit1Map_t::refreshChildren     ([[maybe_unused]] dtyIntfcAbstractUnitGraphic_t* p_this)    {
    if(g_bChildrenSetEmpty) return;

    for(uint8_t l_id=0; l_id<g_childrenNum; l_id++) g_childrenSet[l_id]->refreshWin();

}


bool tuiFnctAbstUnit1Map_t::selectByMouse     (dtyIntfcAbstractUnitGraphic_t* p_this)    {

    if(!clickingChild(p_this)) {
        p_this->deselectBackNeventOn();
    }
    return true;
}

bool tuiFnctAbstUnit1Map_t::clickingChild     ([[maybe_unused]] dtyIntfcAbstractUnitGraphic_t* p_this)    {
    if(g_bChildrenSetEmpty) return false;

    bool l_result = false;

    for(uint8_t l_id=0; l_id<g_childrenNum; l_id++) {
        if(g_childrenSet[l_id]->bMouseClickInsideBounds()) {
            g_childCurrentId = l_id;
            l_result = g_childrenSet[l_id]->selectByMouse();
            break;
        }
    }

    return l_result;
}

void tuiFnctAbstUnit1Map_t::vEventHndlKey_up     ([[maybe_unused]] dtyIntfcAbstractUnitGraphic_t* p_this)    {
    if(g_bChildrenSetEmpty) return;

    if(NO_CHILD_SELECTED != g_childCurrentId) {
        if(0 == g_childCurrentId)
            g_childCurrentId = g_childrenNum;
        g_childCurrentId--;
    } else {
        g_childCurrentId = 0;
    }
    g_childrenSet[g_childCurrentId]->deselectBackNselect();

}

void tuiFnctAbstUnit1Map_t::vEventHndlKey_down	([[maybe_unused]] dtyIntfcAbstractUnitGraphic_t* p_this)  {
    if(g_bChildrenSetEmpty) return;

    if(NO_CHILD_SELECTED != g_childCurrentId) {
        g_childCurrentId++;
        if(g_childrenNum == g_childCurrentId)
            g_childCurrentId = 0;
    } else {
        g_childCurrentId = 0;
    }
    g_childrenSet[g_childCurrentId]->deselectBackNselect();

}

void tuiFnctAbstUnit1Map_t::vEventHndlKey_enter	([[maybe_unused]] dtyIntfcAbstractUnitGraphic_t* p_this)  {
    if(g_bChildrenSetEmpty) return;

    if(NO_CHILD_SELECTED != g_childCurrentId) {
        if(g_childrenSet[g_childCurrentId]->selectTst()) {
            g_childrenSet[g_childCurrentId]->deselectBackNeventOn();
        }
    }

}
