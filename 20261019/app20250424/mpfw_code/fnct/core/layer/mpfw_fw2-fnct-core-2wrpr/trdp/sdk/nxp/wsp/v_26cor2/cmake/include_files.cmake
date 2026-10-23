#   *******************************************************************************
#   
#   mpfw / fw2 - Multi Platform FirmWare FrameWork 
#       library that contains the "main" entry point and, 
#       eventualy, application code that is platform dependent
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
#   Created on: June, 1st 2025  (Sun)
#   Author: Marco Dau
##
### ---------------------------

include_guard()


    set(CURR_MOD_NAME       FNCT-CORE-2WRPR)

    set(${CURR_MOD_NAME}_sdk_SOURCE_FILES_H

        # ---------------------------------
        # ... configuration
        ${${CURR_MOD_NAME}_CONFIG_DIR}
        # ---------------------------------
        ${${CURR_MOD_NAME}_sdk_SRC_DIR}/kr/krThread/v_${KR_THREAD_VER}
        ${${CURR_MOD_NAME}_sdk_SRC_DIR}/sy/syThread/v_${SY_THREAD_VER}
        ${${CURR_MOD_NAME}_sdk_SRC_DIR}/kr/krTimer/v_${${CURR_MOD_NAME}_sdk_krTimer_VER}

    )
    
