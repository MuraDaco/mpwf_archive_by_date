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


    set(CURR_MOD_NAME       FNCT-CORE-0ABST)

    set(${CURR_MOD_NAME}_cmmn_SOURCE_FILES_CPP
        ${${CURR_MOD_NAME}_cmmn_SRC_DIR}/kr/krEndStatic/v_${${CURR_MOD_NAME}_krEndStatic_VER}/krEndStaticManager.cpp
        ${${CURR_MOD_NAME}_cmmn_SRC_DIR}/kr/krEvent/v_${${CURR_MOD_NAME}_krEvent_VER}/krEvent.cpp
        ${${CURR_MOD_NAME}_cmmn_SRC_DIR}/kr/krInit/v_${${CURR_MOD_NAME}_krInit_VER}/krInit.cpp
        ${${CURR_MOD_NAME}_cmmn_SRC_DIR}/kr/krInitStatic/v_${${CURR_MOD_NAME}_krInitStatic_VER}/krInitStaticManager.cpp
        ${${CURR_MOD_NAME}_cmmn_SRC_DIR}/kr/krInitStaticWP/v_${${CURR_MOD_NAME}_krInitStaticWP_VER}/krInitStaticWPManager.cpp

	)