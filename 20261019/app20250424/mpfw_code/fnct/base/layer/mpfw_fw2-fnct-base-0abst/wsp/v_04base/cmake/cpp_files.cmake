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

include_guard()

    set(CURR_MOD_NAME       FNCT-BASE-0ABST)

    set(${CURR_MOD_NAME}_cmmn_SOURCE_FILES_CPP
    
        ${${CURR_MOD_NAME}_cmmn_SRC_DIR}/dty/intfc/cntnr/dtyCntnr0BaseUnit/v_${${CURR_MOD_NAME}_dtyCntnr0BaseUnit_VER}/dtyCntnr0BaseUnit.cpp
        ${${CURR_MOD_NAME}_cmmn_SRC_DIR}/dty/intfc/general/v_${${CURR_MOD_NAME}_general_VER}/dtyBaseArray.cpp
        ${${CURR_MOD_NAME}_cmmn_SRC_DIR}/dty/intfc/general/v_${${CURR_MOD_NAME}_general_VER}/dtyBaseUnit.cpp
        ${${CURR_MOD_NAME}_cmmn_SRC_DIR}/dty/intfc/general/v_${${CURR_MOD_NAME}_general_VER}/dtyString/v_${${CURR_MOD_NAME}_dtyString_VER}/dtyString.cpp
        ${${CURR_MOD_NAME}_cmmn_SRC_DIR}/dty/intfc/unit/dtyUnit0Base.cpp
        ${${CURR_MOD_NAME}_cmmn_SRC_DIR}/dty/intfc/unit/dtyUnit1MmyInt32.cpp

        ${${CURR_MOD_NAME}_cmmn_SRC_DIR}/sys/sysError/v_00/sysErrorTest.cpp

    )
