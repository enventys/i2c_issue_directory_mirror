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

HAL_StatusTypeDef MX_I2C1_Init(I2C_HandleTypeDef *hi2c)
{
  HAL_StatusTypeDef ret = HAL_OK;
  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOB_CLK_ENABLE();
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOH_CLK_ENABLE();

  hi2c->Instance = I2C1;
  hi2c->Init.Timing = 0x40000A0B;
  hi2c->Init.OwnAddress1 = 0;
  hi2c->Init.AddressingMode = I2C_ADDRESSINGMODE_7BIT;
  hi2c->Init.DualAddressMode = I2C_DUALADDRESS_DISABLE;
  hi2c->Init.OwnAddress2 = 0;
  hi2c->Init.OwnAddress2Masks = I2C_OA2_NOMASK;
  hi2c->Init.GeneralCallMode = I2C_GENERALCALL_DISABLE;
  hi2c->Init.NoStretchMode = I2C_NOSTRETCH_DISABLE;
  if (HAL_I2C_Init(hi2c) != HAL_OK)
  {
    ret = HAL_ERROR;
  }

  if (HAL_I2CEx_ConfigAnalogFilter(hi2c, I2C_ANALOGFILTER_ENABLE) != HAL_OK)
  {
    ret = HAL_ERROR;
  }

  if (HAL_I2CEx_ConfigDigitalFilter(hi2c, 0) != HAL_OK)
  {
    ret = HAL_ERROR;
  }

  return ret;
}
extern void HAL_I2C_MspInit(I2C_HandleTypeDef* i2cHandle)
{

  GPIO_InitTypeDef GPIO_InitStruct = {0};
  if(i2cHandle->Instance==I2C1)
  {
    __HAL_RCC_GPIOB_CLK_ENABLE();
    /**I2C1 GPIO Configuration    
    PB9     ------> I2C1_SDA
    PB8     ------> I2C1_SCL 
    */
    __HAL_RCC_I2C1_CLK_ENABLE();
    GPIO_InitStruct.Pin = GPIO_PIN_9|GPIO_PIN_8;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_OD;
    GPIO_InitStruct.Pull = GPIO_PULLUP;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
    GPIO_InitStruct.Alternate = GPIO_AF4_I2C1;
    HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);
  }
}

void HAL_I2C_MspDeInit(I2C_HandleTypeDef* i2cHandle)
{

  if(i2cHandle->Instance==I2C1)
  {
    /* Peripheral clock disable */
    __HAL_RCC_I2C1_CLK_DISABLE();
  
    /**I2C1 GPIO Configuration    
    PB9     ------> I2C1_SDA
    PB8     ------> I2C1_SCL 
    */
    HAL_GPIO_DeInit(GPIOB, GPIO_PIN_9|GPIO_PIN_8);

  }
} 

uint8_t BH1750_Send_Cmd(uint8_t cmd)
{
    return HAL_I2C_Master_Transmit(&hi2c, BH1750_ADDR_WRITE, (uint8_t*)&cmd, 1, 0xFFFF);
}

uint8_t BH1750_Read_Dat(uint8_t* dat)
{
    return HAL_I2C_Master_Receive(&hi2c, BH1750_ADDR_READ, dat, 2, 0xFFFF);
}
uint16_t BH1750_Dat_To_Lux(uint8_t* dat)
{
    uint16_t lux = 0;
    lux = dat[0];
    lux <<= 8;
    lux += dat[1];
    lux = (int)(lux / 1.2);

    return lux;
}
uint8_t GetLightLevel(void)
{
    uint8_t dat[2] = {0};
    BH1750_Send_Cmd(POWER_ON_CMD);
    if(HAL_OK == BH1750_Send_Cmd(CONT_H_MODE))
    {
        HAL_Delay(200);
        if(HAL_OK == BH1750_Read_Dat(dat))
        {
            //PRINTF("\r\nLight Sensor Illuminance: %dLux\r\n", BH1750_Dat_To_Lux(dat));
            
            APP_LOG(TS_ON, VLEVEL_M, "Light= %d\r\n", BH1750_Dat_To_Lux(dat));
            return BH1750_Dat_To_Lux(dat);
        }
    }
    return 0;
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

