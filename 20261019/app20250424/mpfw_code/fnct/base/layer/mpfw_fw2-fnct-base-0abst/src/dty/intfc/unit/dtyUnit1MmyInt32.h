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
 * dtyUnit1MmyInt32.h
 *
 *  Created on: Dec, 23rd 2024
 *      Author: Marco Dau
 */
 
#ifndef DTY_UNIT_1_MMY_INT32_H
#define DTY_UNIT_1_MMY_INT32_H

#include "dtyUnit0Base.h"

class dtyUnit1MmyInt32_t : public dtyUnit0Base_t  {

public:

// ****************************************************
// section start **** CONSTANTS *****
	enum kDigit {
		kDigitNum = 10
	};
    // section end   **** CONSTANTS ***** 
    // ****************************************************
    // --------------------------
// ****************************************************
// section start **** CONSTRUCTOR *****
    public:
	dtyUnit1MmyInt32_t(void);
	dtyUnit1MmyInt32_t(int32_t* p_pValue);

    // section end   **** CONSTRUCTOR ***** 
    // ****************************************************
    // --------------------------
// ****************************************************
// section start **** VALUE MANAGEMENT *****

    // sub-section start -- Instance (no static) attribute
        private:

	    int32_t*   g_pValue    ;
	    int32_t    g_tmpValue  ;
        // sub-section end -- Instance (no static) attribute
        
    // sub-section start -- Class (static) attribute
        public:
	        static const char*		g_pStringValue;

        protected:
	        static char				g_StringValue[kDigitNum+1];
        // sub-section end -- Class (static) attribute

    // sub-section start -- Interface functions
        public:

        void set_pValue         (int32_t* p_pValue);
        void vUpdate            (void);
        bool bStringToValue     (char* p_str );
        void vValueToString     (void);
        // sub-section end -- Interface functions

    // sub-section start -- Interface functions by dtyUnit0Base_t
        public:
        
                void	vSetDbg		                (int32_t p_str);
        virtual void	vSet		                (char* p_str)	override;
        //virtual void	vGet		                (void*)	{} // = 0;
        //virtual void*	xGet		                (void)	{return nullptr;} // = 0;
        virtual void	vInc		                (void)	        override;
        virtual void	vDec		                (void)	        override;
        virtual void	vConfirm	                (void)	        override;
        virtual void	vSelected	                (void)	        override;
        virtual void	vUpdateInit	                (void)	        override;
        // virtual void	vSearchFirst                (void)	{} // = 0;
        // virtual void	vSearchNext					(void)	{} // = 0;
        // virtual void	vSearchPrev					(void)	{} // = 0;
        // virtual bool	bSearchLast  				(void)	{return true;} // = 0;
        // virtual bool	bDisplayable    			(void)	{return true;};
        
        // sub-section end -- Interface functions by dtyUnit0Base_t
        
    // section end   **** VALUE MANAGEMENT ***** 
    // ****************************************************
    // --------------------------

};


#endif 	// DTY_UNIT_1_MMY_INT32_H
