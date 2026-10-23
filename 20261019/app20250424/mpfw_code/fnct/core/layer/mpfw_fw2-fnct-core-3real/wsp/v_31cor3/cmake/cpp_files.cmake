#   *******************************************************************************
#   
#   mpfw / fw2 - Multi Platform FirmWare FrameWork 
#       library that contains the essential code that is used in every application
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

    set(CURR_MOD_NAME       FNCT-CORE-3REAL)

    ## MODULE DIRECTORY Definitions

    set(SV_SYNC_DIR                         svSync/v_${SV_SYNC_VER}                                     )
    set(SV_STATE_DIR                        svState/v_${SV_STATE_VER}                                   )
    set(SV_STATE_MACHINE_DIR                svStateMachine/v_${SV_STATE_MACHINE_VER}                    )

    set(DG_INTERFACE_DIR                    dgInterface/v_${DG_INTERFACE_VER}                           )
    set(DG_FORMAT_DIGIT_DIR                 dgFormatDigit/v_${DG_FORMAT_DIGIT_VER}                      )



    set(CODE_FILES_LIB_SV_SYNC
        ${${CURR_MOD_NAME}_cmmn_SRC_DIR}/sv/${SV_SYNC_DIR}/svSync.cpp
    )

    set(CODE_FILES_LIB_SV_STATE
        ${${CURR_MOD_NAME}_cmmn_SRC_DIR}/sv/${SV_STATE_DIR}/svState.cpp
    )

    set(CODE_FILES_LIB_SV_STATE_MACHINE
        ${${CURR_MOD_NAME}_cmmn_SRC_DIR}/sv/${SV_STATE_MACHINE_DIR}/svStateMachine.cpp
        ${${CURR_MOD_NAME}_cmmn_SRC_DIR}/sv/${SV_STATE_MACHINE_DIR}/svStateMachineManager.cpp
    )

    set(CODE_FILES_LIB_DG_INTERFACE
        ${${CURR_MOD_NAME}_cmmn_SRC_DIR}/dg/${DG_INTERFACE_DIR}/dgInterface.cpp
    )

    set(CODE_FILES_LIB_DG_FORMAT_DIGIT
        ${${CURR_MOD_NAME}_cmmn_SRC_DIR}/dg/${DG_FORMAT_DIGIT_DIR}/dgFormatDigit.cpp
    )

    set(${CURR_MOD_NAME}_cmmn_SOURCE_FILES_CPP

        ${${CURR_MOD_NAME}_cmmn_SRC_DIR}/com/comBuffer/comBuffer_Lin/v_${${CURR_MOD_NAME}_comBuffer_Lin_VER}/comBuffer_Lin.cpp
        ${${CURR_MOD_NAME}_cmmn_SRC_DIR}/com/comProtocolStatus/v_${${CURR_MOD_NAME}_comProtocolStatus_VER}/comProtocolStatus.cpp

        ${CODE_FILES_LIB_SV_SYNC}
        ${CODE_FILES_LIB_SV_STATE}
        ${CODE_FILES_LIB_SV_STATE_MACHINE}

        ${CODE_FILES_LIB_UY_PROTOCOL}
        ${CODE_FILES_LIB_DG_FORMAT_DIGIT}
        ${CODE_FILES_LIB_DG_INTERFACE}

    )

