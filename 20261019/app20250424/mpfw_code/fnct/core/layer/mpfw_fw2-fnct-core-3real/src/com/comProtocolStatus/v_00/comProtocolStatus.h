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
 * comProtocolStatus.h
 *
 *  Created on: Feb, 1st 2026 (Sun)
 *      Author: Marco Dau
 */

#ifndef     COM_PROTOCOL_STATUS_H
#define     COM_PROTOCOL_STATUS_H

#include <cstddef>
#include <cstdint>

#include "sysError.h"

#include "comProtocolInterface.h"
using namespace fw2::fnct::base;

namespace fw2 { namespace fnct { namespace core	{



class comProtocolStatus_t: public comProtocolInterface_t {

    public:
        comProtocolStatus_t (void);

        void        init                    (void)                                      override;
        void        reset                   (uint8_t* p_buffPtr, size_t p_buffSize)     override;
        void        reset                   (void)                                      override;
        int32_t     checkBuffer             (uint8_t* p_buffPtr, size_t p_buffSize)     override;
        uint16_t    get_length              (void)                                      override;
        uint16_t    get_lengthCleaned       (void)                                      override;
        uint8_t     get_firstDirtyBytes     (void)                                      override;
        void        set_length              (uint16_t p_length)                         override;
        void        set_ending_character    (uint8_t p_ending_char)                     override;
        uint8_t     getData                 (void)                                      override;
        void        setData                 (uint8_t p_value)                           override;
        int16_t     update                  (void)                                      override;
        size_t      getBuff                 (uint8_t** p_pbuffPtr)                      override;
        kSysError_t getError                (void)                                      override;
        char        getErrorDetails         (void)                                      override;


    private:

        enum k_state_t: uint8_t  {

             waiting_header        
            ,waiting_coding        
            ,waiting_length_info   
            ,waiting_length_100_figure      = waiting_length_info
            ,waiting_ending_char_definition
            ,waiting_ending_char_to_set     = waiting_ending_char_definition
            ,waiting_length_010_figure
            ,waiting_length_001_figure
            ,waiting_packet_end_by_ending_char
            ,waiting_packet_end_by_length
            ,end

        };

        INIT_ERROR_CODE_GROUP(comProtocolStatus  );
        MAKE_ERROR_CODE(first_byte      ,1  );
        MAKE_ERROR_CODE(coding          ,2  );
        MAKE_ERROR_CODE(length          ,3  );
        MAKE_ERROR_CODE(length_overflow ,4  );
        MAKE_ERROR_CODE(no_ending_char  ,5  );

        
        enum k_header_term_t: char  {

             start                  = '0'
            ,data_type_binary       = '1'
            ,data_type_text         = '2'
            // ,data_type_bin_to_ascii_hex    = '3'
            // ,data_type_bin_to_ascii_dec    = '4'
            // ,data_type_bin_to_ascii_oct    = '5'
            ,ending_char_setting    = 'u'

        };
        
        k_state_t   g_state;
        kSysError_t g_error;
        char        g_error_details;
    

};

} } }   // fw2::fnct::core

#endif  //  COM_PROTOCOL_STATUS_H