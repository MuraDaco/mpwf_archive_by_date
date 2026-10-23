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


set(CURR_MOD_NAME        TRDP-SDK-NXP-0TRDP)

set(LIBS_SDK_PLATFORM_SRC_DIR                  ${${CURR_MOD_NAME}_cmmn_SRC_DIR}/v_${SDK_PLATFORM_LIB_VER} )

set(CODE_FILES_SDK_NXP_C_AMAZON
    ${LIBS_SDK_PLATFORM_SRC_DIR}/${SDK_NXP_AMAZON_FREERTOS_KERNEL_DIR}/portable/MemMang/heap_4.c
    ${LIBS_SDK_PLATFORM_SRC_DIR}/${SDK_NXP_AMAZON_FREERTOS_KERNEL_DIR}/portable/GCC/ARM_CM4F/port.c
    ${LIBS_SDK_PLATFORM_SRC_DIR}/${SDK_NXP_AMAZON_FREERTOS_KERNEL_DIR}/event_groups.c
    ${LIBS_SDK_PLATFORM_SRC_DIR}/${SDK_NXP_AMAZON_FREERTOS_KERNEL_DIR}/list.c
    ${LIBS_SDK_PLATFORM_SRC_DIR}/${SDK_NXP_AMAZON_FREERTOS_KERNEL_DIR}/queue.c
    ${LIBS_SDK_PLATFORM_SRC_DIR}/${SDK_NXP_AMAZON_FREERTOS_KERNEL_DIR}/stream_buffer.c
    ${LIBS_SDK_PLATFORM_SRC_DIR}/${SDK_NXP_AMAZON_FREERTOS_KERNEL_DIR}/tasks.c
    ${LIBS_SDK_PLATFORM_SRC_DIR}/${SDK_NXP_AMAZON_FREERTOS_KERNEL_DIR}/timers.c
)

set(CODE_FILES_SDK_NXP_C_BOARD
    ${LIBS_SDK_PLATFORM_SRC_DIR}/${SDK_NXP_BOARD_DIR}/board.c
    ${LIBS_SDK_PLATFORM_SRC_DIR}/${SDK_NXP_BOARD_DIR}/clock_config.c
    ${LIBS_SDK_PLATFORM_SRC_DIR}/${SDK_NXP_BOARD_DIR}/peripherals.c
    ${LIBS_SDK_PLATFORM_SRC_DIR}/${SDK_NXP_BOARD_DIR}/pin_mux.c
)

set(CODE_FILES_SDK_NXP_C_COMPONENT
    ${LIBS_SDK_PLATFORM_SRC_DIR}/${SDK_NXP_COMPONENT_LIST_DIR}/generic_list.c
    ${LIBS_SDK_PLATFORM_SRC_DIR}/${SDK_NXP_COMPONENT_SERIAL_DIR}/serial_manager.c
    ${LIBS_SDK_PLATFORM_SRC_DIR}/${SDK_NXP_COMPONENT_SERIAL_DIR}/serial_port_uart.c
    ${LIBS_SDK_PLATFORM_SRC_DIR}/${SDK_NXP_COMPONENT_UART_DIR}/usart_adapter.c
)


set(CODE_FILES_SDK_NXP_C_DRIVERS
    ${LIBS_SDK_PLATFORM_SRC_DIR}/${SDK_NXP_DRIVERS_DIR}/freertos/fsl_usart_freertos.c
    ${LIBS_SDK_PLATFORM_SRC_DIR}/${SDK_NXP_DRIVERS_DIR}/fsl_clock.c
    ${LIBS_SDK_PLATFORM_SRC_DIR}/${SDK_NXP_DRIVERS_DIR}/fsl_common.c
    ${LIBS_SDK_PLATFORM_SRC_DIR}/${SDK_NXP_DRIVERS_DIR}/fsl_emc.c
    ${LIBS_SDK_PLATFORM_SRC_DIR}/${SDK_NXP_DRIVERS_DIR}/fsl_flexcomm.c
    ${LIBS_SDK_PLATFORM_SRC_DIR}/${SDK_NXP_DRIVERS_DIR}/fsl_gpio.c
    ${LIBS_SDK_PLATFORM_SRC_DIR}/${SDK_NXP_DRIVERS_DIR}/fsl_i2c.c
    ${LIBS_SDK_PLATFORM_SRC_DIR}/${SDK_NXP_DRIVERS_DIR}/fsl_power.c
    ${LIBS_SDK_PLATFORM_SRC_DIR}/${SDK_NXP_DRIVERS_DIR}/fsl_reset.c
    ${LIBS_SDK_PLATFORM_SRC_DIR}/${SDK_NXP_DRIVERS_DIR}/fsl_rit.c
    ${LIBS_SDK_PLATFORM_SRC_DIR}/${SDK_NXP_DRIVERS_DIR}/fsl_spi.c
    ## ${LIBS_SDK_PLATFORM_SRC_DIR}/${SDK_NXP_DRIVERS_DIR}/fsl_usart.c
)

set(CODE_FILES_SDK_NXP_C_DEVICE
    ${LIBS_SDK_PLATFORM_SRC_DIR}/${SDK_NXP_DEVICE_DIR}/system_LPC54608.c
)


set(CODE_FILES_SDK_NXP_C_STARTUP
    ## ${LIBS_SDK_PLATFORM_SRC_DIR}/${SDK_NXP_STARTUP_DIR}/startup_lpc54608.cpp
)

set(CODE_FILES_SDK_NXP_C_UTILITIES
    ${LIBS_SDK_PLATFORM_SRC_DIR}/${SDK_NXP_UTILITIES_DIR}/fsl_debug_console.c
    ${LIBS_SDK_PLATFORM_SRC_DIR}/${SDK_NXP_UTILITIES_DIR}/fsl_str.c
)

set(${CURR_MOD_NAME}_cmmn_SOURCE_FILES_CPP

    ${CODE_FILES_SDK_NXP_C_AMAZON}
    ${CODE_FILES_SDK_NXP_C_BOARD}
    ${CODE_FILES_SDK_NXP_C_COMPONENT}
    ${CODE_FILES_SDK_NXP_C_DRIVERS}
    ${CODE_FILES_SDK_NXP_C_DEVICE}
    ${CODE_FILES_SDK_NXP_C_STARTUP}
    ${CODE_FILES_SDK_NXP_C_UTILITIES}

)

