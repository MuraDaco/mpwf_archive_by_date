#   *******************************************************************************
#   
#   mpfw / fw2 - Multi Platform FirmWare FrameWork 
#       library that contains the wrapper code to manage the threads
#   Copyright (C) (2023) Marco Dau
#   
#   This program is free software: you can redistribute it and/or modify
#   it under the terms of the GNU Affero General Public License as published
#   by the Free Software Foundation, either version 3 of the License, or
#   (at your option) any later version.
#   
#   This program is distributed in the hope that it will be useful,
#   but WITHOUT ANY WARRANTY; without even the implied warranty of
#   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#   GNU Affero General Public License for more details.
#   
#   You should have received a copy of the GNU Affero General Public License
#   along with this program.  If not, see <https://www.gnu.org/licenses/>.
#   
#   You can contact me by the following email address
#   marco <d o t> ing <d o t> dau <a t> gmail <d o t> com
#   
#   *******************************************************************************

### ---------------------------
##
#   cpp_files.cmake
#
#   Created on: Aug, 26th 2025  (Tue)
#   Author: Marco Dau
##
### ---------------------------

include_guard()

    set(CURR_MOD_NAME       FNCT-HW-1TRDP-SDK-NXP)

    set(${CURR_MOD_NAME}_cmmn_SOURCE_FILES_CPP

        ## mcu
			${${CURR_MOD_NAME}_cmmn_SRC_DIR}/drivers/v_${${CURR_MOD_NAME}_drivers_VER}/mcu/mcuPinPort/v_${${CURR_MOD_NAME}_mcuPinPort_VER}/mcuPinPort.cpp
        	${${CURR_MOD_NAME}_cmmn_SRC_DIR}/drivers/v_${${CURR_MOD_NAME}_drivers_VER}/mcu/mcuCom/mcuComCh_rUsart/v_${${CURR_MOD_NAME}_mcuComCh_rUsart_VER}/mcuComCh_rUsart.cpp
        	## ${${CURR_MOD_NAME}_cmmn_SRC_DIR}/drivers/v_${${CURR_MOD_NAME}_drivers_VER}/mcu/mcuCom/mcuComCh_vUsart/v_${${CURR_MOD_NAME}_mcuComCh_vUsart_VER}/mcuComCh_vUsartInitParams.cpp

        ## sdk
			${${CURR_MOD_NAME}_cmmn_SRC_DIR}/drivers/v_${${CURR_MOD_NAME}_drivers_VER}/sdk/update/fsl_usart_upd/v_00/fsl_usart_upd.c

    )

