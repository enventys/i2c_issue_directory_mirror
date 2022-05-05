/*
 * Copyright 2020, muRata/SyChip Corporation
 * All Rights Reserved.
 *
 * This is UNPUBLISHED PROPRIETARY SOURCE CODE of muRata/SyChip Corporation;
 * the contents of this file may not be disclosed to third parties, copied
 * or duplicated in any form, in whole or in part, without the prior
 * written permission of muRata/SyChip Corporation.
 */

/**
  ******************************************************************************
  * @file    bsp_perip.h
  * @author  Murata/SyChip Team
  * @brief   bsp peripheral init and function.
  ******************************************************************************
*/

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __BSP_PERIP_H__
#define __BSP_PERIP_H__

#ifdef __cplusplus
extern "C" {
#endif
#include "stm32l072xx.h"

/******************************************************
 *                   Enumerations
 ******************************************************/


/* Exported constants --------------------------------------------------------*/


/* Exported functions ------------------------------------------------------- */
/**
  * @brief Init the Button 
  * @param none
  * @retval  none
  */
void MX_BUTTON_Init(void);

/**
  * @brief Button interrupt handler 
  * @param none
  * @retval  none
  */
void button_interrupt_handler(void);

/**
  * @brief Init the Led 
  * @param led_port     led GPIO port
  *        led_pin      led GPIO pin
  * @retval  none
  */
void Bsp_Led_Init(GPIO_TypeDef*   led_port,uint16_t led_pin);

/**
  * @brief turn on the Led 
  * @param led_port     led GPIO port
  *        led_pin      led GPIO pin
  * @retval  none
  */
void Bsp_Led_On(GPIO_TypeDef* led_port,uint16_t led_pin);
/**
  * @brief Toggle the Led 
  * @param led_port     led GPIO port
  *        led_pin      led GPIO pin
  * @retval  none
  */
void Bsp_Led_Toggle(GPIO_TypeDef* led_port,uint16_t led_pin);

/**
  * @brief turn off the Led 
  * @param led_port     led GPIO port
  *        led_pin      led GPIO pin
  * @retval  none
  */
void Bsp_Led_Off( GPIO_TypeDef* led_port,uint16_t led_pin);

#ifdef __cplusplus
}
#endif

#endif /* __TEST_GPIO_H__*/

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
