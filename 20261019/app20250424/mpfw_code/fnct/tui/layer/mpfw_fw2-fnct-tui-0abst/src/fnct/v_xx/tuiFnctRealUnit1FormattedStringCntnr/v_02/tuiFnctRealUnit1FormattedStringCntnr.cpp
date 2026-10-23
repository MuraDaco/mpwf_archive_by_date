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
 

#include "tuiFnctRealUnit1FormattedStringCntnr.h"


// ****************************************************
// section start **** CONSTRUCTOR *****

    tuiFnctRealUnit1FormattedStringCntnr_t::tuiFnctRealUnit1FormattedStringCntnr_t      (void)   :
        tuiFnctAbstUnit0_t      ("-")
        ,g_selectState          {false}
        ,g_pString              {nullptr}
    {}

    tuiFnctRealUnit1FormattedStringCntnr_t::tuiFnctRealUnit1FormattedStringCntnr_t      (const char* p_strName   ,dtyString_t* p_pString   )   :
        tuiFnctAbstUnit0_t      (p_strName)
        ,g_selectState          {false}
        ,g_pString              {p_pString}
    {}

    // section end   **** CONSTRUCTOR *****
    // ****************************************************
    // --------------------------
// ****************************************************
// section start **** PROCESS MANAGEMENT *****

// --------------------- Process section - START

    // protected:
    bool tuiFnctRealUnit1FormattedStringCntnr_t::init   	            ([[maybe_unused]] dtyIntfcAbstractUnitGraphic_t* p_this)  {
        if(g_pString)   {
            uint16_t l_h;
            
            l_h =   g_pString->getBuffSize() / p_this->getDimW();
            l_h += (g_pString->getBuffSize() % p_this->getDimW()) ? 1 : 0;
            p_this->setDimH(l_h);
            p_this->updBoundY();

            p_this->setEventStatus(false);
        }
        return true;
    }

    bool tuiFnctRealUnit1FormattedStringCntnr_t::initChildren           ([[maybe_unused]] dtyIntfcAbstractUnitGraphic_t* p_this)  {
        return true;
    }

    bool tuiFnctRealUnit1FormattedStringCntnr_t::loop   	            ([[maybe_unused]] dtyIntfcAbstractUnitGraphic_t* p_this)  {
        return true;
    }

    bool tuiFnctRealUnit1FormattedStringCntnr_t::loopChildren           ([[maybe_unused]] dtyIntfcAbstractUnitGraphic_t* p_this)  {
        return true;
    }

    void tuiFnctRealUnit1FormattedStringCntnr_t::end       	            ([[maybe_unused]] dtyIntfcAbstractUnitGraphic_t* p_this)  {

    }

    void tuiFnctRealUnit1FormattedStringCntnr_t::endChildren            ([[maybe_unused]] dtyIntfcAbstractUnitGraphic_t* p_this)  {

    }

    // section end   **** PROCESS MANAGEMENT *****
    // ****************************************************
    // --------------------------
// ****************************************************
// section start **** DISPLAY *****

    // protected:
    void tuiFnctRealUnit1FormattedStringCntnr_t::clear     	        (dtyIntfcAbstractUnitGraphic_t* p_this)  {
        p_this->frameClear();
    }

    void tuiFnctRealUnit1FormattedStringCntnr_t::display     	    (dtyIntfcAbstractUnitGraphic_t* p_this)  {
        if(g_pString)   {
            if(g_pStringInfo)   {
                p_this->stringPrint2(markerToColor(g_pStringInfo->g_marker), g_selectState, g_pString->getBuffPtr(), g_pString->getBuffSize());    
            } else {
                p_this->stringPrint2(markerToColor(kMarker_t::defaultX), false, g_pString->getBuffPtr(), g_pString->getBuffSize());
            }
        }
    }

    void tuiFnctRealUnit1FormattedStringCntnr_t::display     	    (dtyIntfcAbstractUnitGraphic_t* p_this, [[maybe_unused]] bool p_recursively)  {
        display(p_this);
    }

    void tuiFnctRealUnit1FormattedStringCntnr_t::displayChildren    ([[maybe_unused]] dtyIntfcAbstractUnitGraphic_t* p_this, [[maybe_unused]] bool p_recursively)  {
    }

    void tuiFnctRealUnit1FormattedStringCntnr_t::refreshChildren    ([[maybe_unused]] dtyIntfcAbstractUnitGraphic_t* p_this)  {
    }
    // section end   **** DISPLAY *****
    // ****************************************************
    // --------------------------
// ****************************************************
// section start **** STATE MANAGEMENT *****

    // protected:

    void tuiFnctRealUnit1FormattedStringCntnr_t::selectStateSet       (bool p_selectState)  {
        g_selectState = p_selectState;
    }

    bool tuiFnctRealUnit1FormattedStringCntnr_t::select     	        (dtyIntfcAbstractUnitGraphic_t* p_this)  {
        bool l_result = false;

        if(g_pString)   {
            if(g_pStringInfo)   {
                l_result = true;
                p_this->stringPrint2( markerToColor( g_pStringInfo->g_marker), 
                                                    g_selectState, 
                                                    g_pString->getBuffPtr(), 
                                                    g_pString->getBuffSize()
                                                );
            } else {
                l_result = p_this->stringPrint2(    tuiState_t::select, 
                                                    markerToColor(kMarker_t::defaultX), 
                                                    true, 
                                                    g_pString->getBuffPtr(), 
                                                    g_pString->getBuffSize()
                                                );
            }
        }

        return l_result;
    }

    bool tuiFnctRealUnit1FormattedStringCntnr_t::deSelect   	        ([[maybe_unused]] dtyIntfcAbstractUnitGraphic_t* p_this)  {
        bool l_result = false;

        if(g_pString)   {
            if(g_pStringInfo)   {
                l_result = true;
                p_this->stringPrint2( markerToColor( g_pStringInfo->g_marker), 
                                                    g_selectState, 
                                                    g_pString->getBuffPtr(), 
                                                    g_pString->getBuffSize()
                                                );
            } else {
                l_result = p_this->stringPrint2(    tuiState_t::deselect, 
                                                    markerToColor(kMarker_t::defaultX), 
                                                    false, 
                                                    g_pString->getBuffPtr(), 
                                                    g_pString->getBuffSize()
                                                );
            }
        }

        return l_result;
    }

    void tuiFnctRealUnit1FormattedStringCntnr_t::eventOn    	        ([[maybe_unused]] dtyIntfcAbstractUnitGraphic_t* p_this)  {
    }

    bool tuiFnctRealUnit1FormattedStringCntnr_t::selectByMouse        ([[maybe_unused]] dtyIntfcAbstractUnitGraphic_t* p_this)  {
        p_this->deselectBackNselect();
        p_this->parentDeselectBackNeventOn();
        return true;
    }

    bool tuiFnctRealUnit1FormattedStringCntnr_t::clickingChild        ([[maybe_unused]] dtyIntfcAbstractUnitGraphic_t* p_this) {
        return false;
    }

    // section end   **** STATE MANAGEMENT *****
    // ****************************************************
    // --------------------------
// ****************************************************
// section start **** STREAM CONTAINER *****

    // public:
    void tuiFnctRealUnit1FormattedStringCntnr_t::cntnrInit          (dtyString_t* p_pString, dtyStringInfo_t* p_pStringInfo)  {
        g_pString       = p_pString;
        g_pStringInfo   = p_pStringInfo;
    }

    void tuiFnctRealUnit1FormattedStringCntnr_t::setPtrData          (void* p_pData)  {
        g_pString       = static_cast<dtyString_t*>(p_pData);
    }

    void tuiFnctRealUnit1FormattedStringCntnr_t::setPtrDataInfo      (void* p_pDataInfo)  {
        g_pStringInfo   = static_cast<dtyStringInfo_t*>(p_pDataInfo);
    }

    void tuiFnctRealUnit1FormattedStringCntnr_t::cntnrUpdParams          (dtyIntfcAbstractUnitGraphic_t* p_this)  {
        uint16_t l_h;
        // IMPORTANT NOTE:
        // The (-1) term in the expressions below needs because the "printString" functions take the first column to insert rows of string info.
        // At the moment there is only one info about string rows: weather they are the first row
        // l_h =   g_pString->getBuffSize() / p_this->getDimW();
        // l_h += (g_pString->getBuffSize() % p_this->getDimW()) ? 1 : 0;
        l_h =   g_pString->getBuffSize() / (p_this->getDimW() - 1);
        l_h += (g_pString->getBuffSize() % (p_this->getDimW() - 1)) ? 1 : 0;
        p_this->setDimH(l_h);
        p_this->updBoundY();
    }


    // section end   **** STREAM CONTAINER *****
    // ****************************************************
    // --------------------------
// ****************************************************
// section start **** FUNCTIONAL DATA MANAGEMENT *****

    // private:
    uint8_t tuiFnctRealUnit1FormattedStringCntnr_t::markerToColor        (kMarker_t p_marker)        {
        uint8_t l_result = 0;

        switch (p_marker)   {
            case kMarker_t::defaultX:
                l_result = fmt_yellow;
                break;
            case kMarker_t::deviceRx:
                l_result = kFormatColor_t::fmt_magenta;
                break;
            case kMarker_t::deviceTx:
                l_result = kFormatColor_t::fmt_cyan;
                break;
            default:
                l_result = kFormatColor_t::fmt_white;
                break;
        }

        return l_result;
    }

    // section end   **** FUNCTIONAL DATA MANAGEMENT *****
    // ****************************************************
    // --------------------------
// ****************************************************
// section start **** DEBUG *****

    //public:
    void tuiFnctRealUnit1FormattedStringCntnr_t::displayDebug            (dtyIntfcAbstractUnitGraphic_t* p_this, uint32_t p_dbgParam1, uint32_t p_dbgParam2)      {
        if(g_pString)   {
            p_this->debugPrint(p_dbgParam1, p_dbgParam2, g_pString->getBuffPtr());
        }
    }

    // section end   **** DEBUG *****
    // ****************************************************
    // --------------------------
