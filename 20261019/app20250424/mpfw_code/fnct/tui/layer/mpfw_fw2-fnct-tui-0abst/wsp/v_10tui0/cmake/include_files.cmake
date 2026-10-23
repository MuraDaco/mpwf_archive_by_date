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

    set(${CURR_MOD_NAME}_cmmn_SOURCE_FILES_H

        # ---------------------------------
        # ... own configuration files
        #     N.B.: their location is set in "set_public_dirs.cmake" file

        # ---------------------------------

 		## dty/
 			## intfc/cntnr
        	${${CURR_MOD_NAME}_SRC_DIR}/dty/intfc/cntnr/v_${${CURR_MOD_NAME}_cntnr_VER}
        	${${CURR_MOD_NAME}_SRC_DIR}/dty/intfc/cntnr/dtyCntnr1StreamList/v_${${CURR_MOD_NAME}_dtyCntnr1StreamList_VER}
        	${${CURR_MOD_NAME}_SRC_DIR}/dty/intfc/cntnr/v_xx/dtyCntnr1StreamListX/v_${${CURR_MOD_NAME}_dtyCntnr1StreamListX_VER}
        	${${CURR_MOD_NAME}_SRC_DIR}/dty/intfc/cntnr/v_xx/dtyCntnr1StreamUnitStringV1/v_${${CURR_MOD_NAME}_dtyCntnr1StreamUnitStringV1_VER}

 			## intfc/unit
        	${${CURR_MOD_NAME}_SRC_DIR}/dty/intfc/unit/dtyIntfc
        	${${CURR_MOD_NAME}_SRC_DIR}/dty/intfc/unit/dtyIntfcProcess/v_${${CURR_MOD_NAME}_dtyIntfcProcessGrph_VER}

 		## fnct
        	${${CURR_MOD_NAME}_SRC_DIR}/fnct/v_${${CURR_MOD_NAME}_fnct_VER}
        	${${CURR_MOD_NAME}_SRC_DIR}/fnct/v_xx/tuiFnctAbstUnit1Cntnr/v_${${CURR_MOD_NAME}_tuiFnctAbstUnit1Cntnr_VER}
        	${${CURR_MOD_NAME}_SRC_DIR}/fnct/v_xx/tuiFnctRealUnit1FormattedString/v_${${CURR_MOD_NAME}_tuiFnctRealUnit1FormattedString_VER}
        	${${CURR_MOD_NAME}_SRC_DIR}/fnct/v_xx/tuiFnctRealUnit1FormattedStringCntnr/v_${${CURR_MOD_NAME}_tuiFnctRealUnit1FormattedStringCntnr_VER}
	        ${${CURR_MOD_NAME}_SRC_DIR}/fnct/v_xx/tuiFnctRealUnit2Cntnr/v_${${CURR_MOD_NAME}_tuiFnctRealUnit2Cntnr_VER}

 		## grph
        	${${CURR_MOD_NAME}_SRC_DIR}/grph


    )
