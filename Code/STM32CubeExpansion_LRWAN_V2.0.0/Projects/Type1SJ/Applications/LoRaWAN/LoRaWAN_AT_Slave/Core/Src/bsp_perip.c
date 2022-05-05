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
  * @file    bsp_perip.c
  * @author  Murata/SyChip Team
  * @brief   bsp peripheral init and function.
  ******************************************************************************
*/

#include "platform.h"
#include <stdarg.h>
#include "bsp_perip.h"
#include "stm32_timer.h"
#include "utilities.h"
#include "sys_app.h"

/* Private variables ---------------------------------------------------------*/
/* time button must be pressed to set to factory new state */
#define FACTORY_NEW_BUTTON_TIMEOUT              50

I2C_HandleTypeDef hi2c;

static uint32_t presstimes = 0;

static UTIL_TIMER_Object_t button_long_press_timer;

static bool button_state = SET;

/* Functions Definition ------------------------------------------------------*/
static void on_button_long_press_timeout_event(void* context)
{
    UTIL_TIMER_Stop(&button_long_press_timer);
    presstimes++;
    APP_LOG(TS_ON, VLEVEL_M, "Press time = %d\r\n",presstimes);
}

void MX_BUTTON_Init(void)
{
    presstimes = 0;
    
    GPIO_InitTypeDef  GPIO_InitStruct;
    
    /*##-1- Enable peripherals and GPIO Clocks #################################*/
    __GPIOA_CLK_ENABLE();
    /*##-2- Configure peripheral GPIO ##########################################*/
    GPIO_InitStruct.Pin       = GPIO_PIN_7;
    GPIO_InitStruct.Mode      = GPIO_MODE_IT_RISING_FALLING;
    GPIO_InitStruct.Pull      = GPIO_PULLUP;
    GPIO_InitStruct.Speed     = GPIO_SPEED_FREQ_HIGH;
    
    HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

    /*##-3- Configure the NVIC ########################################*/
    HAL_NVIC_SetPriority(EXTI4_15_IRQn, 3, 1);
    HAL_NVIC_EnableIRQ(EXTI4_15_IRQn);
    UTIL_TIMER_Create(&button_long_press_timer,  0xFFFFFFFFU, UTIL_TIMER_ONESHOT, on_button_long_press_timeout_event, NULL);
    UTIL_TIMER_SetPeriod(&button_long_press_timer, FACTORY_NEW_BUTTON_TIMEOUT);
}

void button_interrupt_handler(void)
{
    /* GPIO7 will trigger interuppt twice on reset */
    /* EXTI line interrupt detected */
    if (__HAL_GPIO_EXTI_GET_IT(GPIO_PIN_7) != RESET)
    {
        __HAL_GPIO_EXTI_CLEAR_IT(GPIO_PIN_7);
        if (HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_7) == GPIO_PIN_RESET && button_state ==GPIO_PIN_SET)
        {
            UTIL_TIMER_Stop(&button_long_press_timer);
            UTIL_TIMER_Start(&button_long_press_timer);
        }
        else
        {
            button_state = HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_7);
        }

    }
}

void Bsp_Led_Init(GPIO_TypeDef* led_port, uint16_t led_pin)
{
  GPIO_InitTypeDef  GPIO_InitStruct;
  
  /* Enable the GPIO_LED Clock */
  LED_GPIO_CLK_ENABLE();

  /* Configure the GPIO_LED pin */
  GPIO_InitStruct.Pin = led_pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;

  
  HAL_GPIO_Init(led_port, &GPIO_InitStruct);
  
}

void Bsp_Led_On(GPIO_TypeDef* led_port,uint16_t led_pin)
{
  HAL_GPIO_WritePin(led_port, led_pin, GPIO_PIN_SET); 
}

void Bsp_Led_Off( GPIO_TypeDef* led_port,uint16_t led_pin)
{
  HAL_GPIO_WritePin(led_port, led_pin, GPIO_PIN_RESET); 
}

void Bsp_Led_Toggle(GPIO_TypeDef* led_port,uint16_t led_pin)
{
  HAL_GPIO_TogglePin(led_port, led_pin);
}


/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/

