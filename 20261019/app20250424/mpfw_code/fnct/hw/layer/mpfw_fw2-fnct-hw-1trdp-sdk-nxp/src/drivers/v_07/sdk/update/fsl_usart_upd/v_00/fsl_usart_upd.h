/*
 * Copyright (c) 2016, Freescale Semiconductor, Inc.
 * Copyright 2016-2019 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef _FSL_USART_UPD_H_
#define _FSL_USART_UPD_H_

#include "fsl_usart.h"



/* Forward declaration of the handle typedef. */
typedef struct _usart_handle_v2 usart_handle_v2_t;

/*! @brief USART transfer callback function. */
typedef void (*usart_transfer_callback_v2_t)(void *userData);

/*! @brief USART handle structure. */
struct _usart_handle_v2
{

    usart_transfer_callback_v2_t callback; /*!< Callback function. */
    void *userData;                     /*!< USART callback function parameter.*/

};

/*! @brief Typedef for usart interrupt handler. */
typedef void (*flexcomm_usart_irq_handler_v2_t)(USART_Type *base, usart_handle_v2_t *handle);

/*******************************************************************************
 * API
 ******************************************************************************/

#if defined(__cplusplus)
extern "C" {
#endif /* _cplusplus */

/*!
 * @brief Initializes the USART handle.
 *
 * This function initializes the USART handle which can be used for other USART
 * transactional APIs. Usually, for a specified USART instance,
 * call this API once to get the initialized handle.
 *
 * @param base USART peripheral base address.
 * @param handle USART handle pointer.
 * @param callback The callback function.
 * @param userData The parameter of the callback function.
 */
status_t USART_TransferCreateHandle_v2(USART_Type *base
                                       ,usart_handle_v2_t *handle
                                       ,usart_transfer_callback_v2_t callback
                                       ,void* p_userData
);

/*!
 * @brief USART IRQ handle function.
 *
 * This function handles the USART transmit and receive IRQ request.
 *
 * @param base USART peripheral base address.
 * @param handle USART handle pointer.
 */
void USART_TransferHandleIRQ_v2(USART_Type *base, usart_handle_v2_t *handle);

#if defined(__cplusplus)
}
#endif

#endif /* _FSL_USART_UPD_H_ */
