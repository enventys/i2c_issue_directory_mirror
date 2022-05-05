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
/**
  * @brief BH1750 operate mode
  */
typedef enum
{
    POWER_OFF_CMD   =   0x00,   
    POWER_ON_CMD    =   0x01,   
    RESET_REGISTER  =   0x07,   
    CONT_H_MODE     =   0x10,   
    CONT_H_MODE2    =   0x11,   
    CONT_L_MODE     =   0x13,   
    ONCE_H_MODE     =   0x20,   
    ONCE_H_MODE2    =   0x21,   
    ONCE_L_MODE     =   0x23    
} BH1750_MODE;


/* Exported constants --------------------------------------------------------*/

/**
  * @brief BH1750 operate address
  */
#define BH1750_ADDR_WRITE   0x46    //01000110
#define BH1750_ADDR_READ    0x47    //01000111

/* Exported functions ------------------------------------------------------- */
/**
  * @brief Init the ADC
  * @param none
  * @retval  none
  */
void HW_AdcInit( void );
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
  * @brief Get light level
  * @param none
  * @retval light level
  */
uint8_t GetLightLevel(void);
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
