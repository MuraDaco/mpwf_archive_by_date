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
 * dtyUnit1MmyInt32.cpp
 *
 *  Created on: Dec, 23rd 2024
 *      Author: Marco Dau
 */
 
#include <cstdint>

#include "dtyUnit1MmyInt32.h"


// ************************************************************ ATTRIBUTE
// +++++++++++++++++++++ Class (Static) attribute

// ****************************************************
// section start **** CONSTRUCTOR *****
    
    dtyUnit1MmyInt32_t::dtyUnit1MmyInt32_t(void) :
             dtyUnit0Base_t   {}
    		//,g_pValue        {nullptr}
    {}

    dtyUnit1MmyInt32_t::dtyUnit1MmyInt32_t(int32_t* p_pValue) :
             dtyUnit0Base_t   {}
    		,g_pValue        {p_pValue   }
    {}

    // section end   **** CONSTRUCTOR ***** 
    // ****************************************************
    // --------------------------
// ****************************************************
// section start **** VALUE MANAGEMENT *****

    // sub-section start -- Class (static) attribute

        char				dtyUnit1MmyInt32_t::g_StringValue[kDigitNum+1] = "3297070";
        const char*			dtyUnit1MmyInt32_t::g_pStringValue				{g_StringValue};

        // sub-section end -- Class (static) attribute

    // sub-section start -- Interface functions

        void dtyUnit1MmyInt32_t::set_pValue         (int32_t* p_pValue)     {
            g_pValue = p_pValue;
        }

        /* This function makes parameter modification operative
         */
        void	dtyUnit1MmyInt32_t::vUpdate			(void) {
        	if(m_bTemporValueChanged) {
                if(g_pValue)
        		    *g_pValue = g_tmpValue;
        	}
        }

        bool	dtyUnit1MmyInt32_t::bStringToValue	([[maybe_unused]] char* p_str ) {
        	return false;
        }

        void	dtyUnit1MmyInt32_t::vValueToString	(void) {
        	int32_t l_value		{g_tmpValue};
        	char l_remandier;

        	g_pStringValue = g_StringValue;

        	// set null string terminator
        	g_StringValue[kDigitNum]	= 0;
        	for(uint8_t i=1; i<=kDigitNum; i++) {
        		l_remandier	= static_cast<char>(l_value % 10);
        		l_value		= l_value / 10;
                if(
                        (l_remandier || l_value)
                    ||  (1 == i)
                )
        		    g_StringValue[kDigitNum - i] = static_cast<char>('0' + l_remandier);
                else
        		    g_StringValue[kDigitNum - i] = static_cast<char>(' ');
        	}
        }

        // sub-section end -- Interface functions

    // sub-section start -- Interface functions by dtyUnit0Base_t

        void	dtyUnit1MmyInt32_t::vSetDbg			(int32_t p_value)	{
            if(g_pValue)    {
                *g_pValue = p_value;
        	    vSelected();
            }
        }

        void	dtyUnit1MmyInt32_t::vSet			(char* p_str)	{
        	p_str += 2;

        	if(bStringToValue(p_str)) {
        		vConfirm();
        	}
        }

        void	dtyUnit1MmyInt32_t::vInc				(void) {
        	(g_tmpValue)++;
        	vValueToString();
        }

        void	dtyUnit1MmyInt32_t::vDec				(void) {
        	(g_tmpValue)--;
        	vValueToString();
        }

        void	dtyUnit1MmyInt32_t::vConfirm			(void) {
        	if(!m_bTemporValueChanged) {
        		m_bTemporValueChanged = true;

        		if(m_bApplyChangesImmediatly) {
        			vUpdate();
        		}

        	}
        }

        void	dtyUnit1MmyInt32_t::vSelected			(void) {
        	if(!m_bTemporValueChanged) {
                if(g_pValue)
            		g_tmpValue = *g_pValue;
                else
                    g_tmpValue = 5;
        	}
        	vValueToString();
        }

        /*
         * This function must be call only after calling
         * vLoadDataStructure()
         */
        void	dtyUnit1MmyInt32_t::vUpdateInit	(void) {
            if(g_pValue)
              	*g_pValue = g_tmpValue;
        }

        // sub-section end -- Interface functions by dtyUnit0Base_t

    // section end   **** VALUE MANAGEMENT ***** 
    // ****************************************************
    // --------------------------
