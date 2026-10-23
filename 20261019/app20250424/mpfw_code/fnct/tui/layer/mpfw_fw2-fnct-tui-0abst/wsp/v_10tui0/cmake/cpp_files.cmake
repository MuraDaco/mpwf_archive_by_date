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


    set(CURR_MOD_NAME       FNCT-TUI-0ABST)

    set(${CURR_MOD_NAME}_cmmn_SOURCE_FILES_CPP

 	## dty/intfc/cntr
        ${${CURR_MOD_NAME}_SRC_DIR}/dty/intfc/cntnr/dtyCntnr1StreamList/v_${${CURR_MOD_NAME}_dtyCntnr1StreamList_VER}/dtyCntnr1StreamList.cpp
        ${${CURR_MOD_NAME}_SRC_DIR}/dty/intfc/cntnr/v_${${CURR_MOD_NAME}_cntnr_VER}/dtyCntnr1ArrayTuiList.cpp
        ${${CURR_MOD_NAME}_SRC_DIR}/dty/intfc/cntnr/v_${${CURR_MOD_NAME}_cntnr_VER}/dtyCntnr1ArrayTuiMap.cpp
        ${${CURR_MOD_NAME}_SRC_DIR}/dty/intfc/cntnr/v_xx/dtyCntnr1StreamListX/v_${${CURR_MOD_NAME}_dtyCntnr1StreamListX_VER}/dtyCntnr1StreamListX.cpp
        ${${CURR_MOD_NAME}_SRC_DIR}/dty/intfc/cntnr/v_xx/dtyCntnr1StreamUnitStringV1/v_${${CURR_MOD_NAME}_dtyCntnr1StreamUnitStringV1_VER}/dtyCntnr1StreamUnitStringV1.cpp

 	## fnct
        ${${CURR_MOD_NAME}_SRC_DIR}/fnct/v_${${CURR_MOD_NAME}_fnct_VER}/tuiFnctAbstUnit0.cpp
        ${${CURR_MOD_NAME}_SRC_DIR}/fnct/v_${${CURR_MOD_NAME}_fnct_VER}/tuiFnctAbstUnit1Map.cpp
        ${${CURR_MOD_NAME}_SRC_DIR}/fnct/v_${${CURR_MOD_NAME}_fnct_VER}/tuiFnctRealUnit1Button.cpp
        ${${CURR_MOD_NAME}_SRC_DIR}/fnct/v_${${CURR_MOD_NAME}_fnct_VER}/tuiFnctRealUnit1Debug.cpp
        ${${CURR_MOD_NAME}_SRC_DIR}/fnct/v_${${CURR_MOD_NAME}_fnct_VER}/tuiFnctRealUnit1Ebox.cpp
        ${${CURR_MOD_NAME}_SRC_DIR}/fnct/v_${${CURR_MOD_NAME}_fnct_VER}/tuiFnctRealUnit1Map.cpp
        ${${CURR_MOD_NAME}_SRC_DIR}/fnct/v_${${CURR_MOD_NAME}_fnct_VER}/tuiFnctRealUnit1MmyInt.cpp
        ## ${${CURR_MOD_NAME}_SRC_DIR}/fnct/v_${${CURR_MOD_NAME}_fnct_VER}/tuiFnctRealUnit2Cntnr.cpp

        ${${CURR_MOD_NAME}_SRC_DIR}/fnct/v_xx/tuiFnctAbstUnit1Cntnr/v_${${CURR_MOD_NAME}_tuiFnctAbstUnit1Cntnr_VER}/tuiFnctAbstUnit1Cntnr.cpp
        ${${CURR_MOD_NAME}_SRC_DIR}/fnct/v_xx/tuiFnctRealUnit1FormattedString/v_${${CURR_MOD_NAME}_tuiFnctRealUnit1FormattedString_VER}/tuiFnctRealUnit1FormattedString.cpp
        ${${CURR_MOD_NAME}_SRC_DIR}/fnct/v_xx/tuiFnctRealUnit1FormattedStringCntnr/v_${${CURR_MOD_NAME}_tuiFnctRealUnit1FormattedStringCntnr_VER}/tuiFnctRealUnit1FormattedStringCntnr.cpp
        ${${CURR_MOD_NAME}_SRC_DIR}/fnct/v_xx/tuiFnctRealUnit2Cntnr/v_${${CURR_MOD_NAME}_tuiFnctRealUnit2Cntnr_VER}/tuiFnctRealUnit2Cntnr.cpp

 	## grph
        ${${CURR_MOD_NAME}_SRC_DIR}/grph/tuiGrphAbstUnit0.cpp
        ${${CURR_MOD_NAME}_SRC_DIR}/grph/tuiGrphAbstUnit1State.cpp
        ${${CURR_MOD_NAME}_SRC_DIR}/grph/tuiGrphAbstUnit2Coord.cpp
        ${${CURR_MOD_NAME}_SRC_DIR}/grph/tuiGrphAbstUnit3Event.cpp

    )

