//  *******************************************************************************
//  
//  mpfw / fw2 - Multi Platform FirmWare FrameWork 
//      library that contains the essential code that is used in every application
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
 * sysErrorTest.h
 *
 *  Created on: Feb, 18th 2026 (wed)
 *      Author: Marco Dau
 */

#ifndef     SYS_ERROR_TEST_H
#define     SYS_ERROR_TEST_H

#include <cstddef>
#include <cstdint>

#include "sysError.h"

namespace fw2 { namespace fnct { namespace base	{



class sysErrorTest_t {

    public:

        static void print_value  (kSysError_t p_errorCode);

    public:
        
        INIT_ERROR_CODE_GROUP(sysErrorTest  );
        MAKE_ERROR_CODE(first_byte      ,1  );
        MAKE_ERROR_CODE(coding          ,2  );
        MAKE_ERROR_CODE(length          ,3  );
        MAKE_ERROR_CODE(length_overflow ,4  );
        MAKE_ERROR_CODE(no_ending_char  ,49 );

};

} } }   // fw2::fnct::base

#endif  //  SYS_ERROR_TEST_H