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
#   include_files.cmake
#
#   Created on: Aug, 26th 2025  (Tue)
#   Author: Marco Dau
##
### ---------------------------

include_guard()

    set(CURR_MOD_NAME     FNCT-CORE-3REAL)

    ## MODULE DIRECTORY Definitions
        set(KR_END_STATIC_DIR                   krEndStatic/v_${KR_END_STATIC_VER}                              )
        set(KR_EVENT_DIR                        krEvent/v_${KR_EVENT_VER}                                       )
        set(KR_INIT_DIR                         krInit/v_${KR_INIT_VER}                                         )
        set(KR_INIT_STATIC_DIR                  krInitStatic/v_${KR_INIT_STATIC_VER}                            )
        set(KR_INIT_STATIC_WP_DIR               krInitStaticWP/v_${KR_INIT_STATIC_VER}							)
        set(KR_TIMER_DIR                        krTimer/v_${KR_TIMER_VER}                                       )
    
        set(SV_SYNC_DIR                         svSync/v_${SV_SYNC_VER}                                         )
        set(SV_STATE_DIR                        svState/v_${SV_STATE_VER}                                       )
        set(SV_STATE_MACHINE_DIR                svStateMachine/v_${SV_STATE_MACHINE_VER}                        )
    
        set(DG_INTERFACE_DIR                    dgInterface/v_${DG_INTERFACE_VER}                               )
        set(DG_FORMAT_DIGIT_DIR                 dgFormatDigit/v_${DG_FORMAT_DIGIT_VER}                          )
    
    # INCLUDE CONFIG DIRECTORY Definitions
        set(DT_DEF_DIR                          dtDef/v_${DT_DEF_VER}                                           )

    set(${CURR_MOD_NAME}_cmmn_SOURCE_FILES_H

        # ---------------------------------
        # ... configuration

        # ---------------------------------
        ${${CURR_MOD_NAME}_cmmn_SRC_DIR}/cg
        ${${CURR_MOD_NAME}_cmmn_SRC_DIR}/cs

        ${${CURR_MOD_NAME}_cmmn_SRC_DIR}/com/comBuffer/comBuffer_Lin/v_${${CURR_MOD_NAME}_comBuffer_Lin_VER}
        ${${CURR_MOD_NAME}_cmmn_SRC_DIR}/com/comProtocolStatus/v_${${CURR_MOD_NAME}_comProtocolStatus_VER}

        ${${CURR_MOD_NAME}_cmmn_SRC_DIR}/dt/${DT_DEF_DIR}

        ${${CURR_MOD_NAME}_cmmn_SRC_DIR}/sv/${SV_SYNC_DIR}
        ${${CURR_MOD_NAME}_cmmn_SRC_DIR}/sv/${SV_STATE_DIR}
        ${${CURR_MOD_NAME}_cmmn_SRC_DIR}/sv/${SV_STATE_MACHINE_DIR}
        ${${CURR_MOD_NAME}_cmmn_SRC_DIR}/dg/${DG_INTERFACE_DIR}
        ${${CURR_MOD_NAME}_cmmn_SRC_DIR}/dg/${DG_FORMAT_DIGIT_DIR}

    )
