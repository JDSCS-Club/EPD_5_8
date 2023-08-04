/*
 * adc.c
 *
 *  Created on: Jan 16, 2020
 *      Author: RobertKim
 */
//--------------------------------------------------------------------------------------------//
//
//--------------------------------------------------------------------------------------------//
#include <adc.h>
#include "main.h"
//--------------------------------------------------------------------------------------------//
extern DMA_HandleTypeDef hdma_adc1;
extern ADC_HandleTypeDef AdcHandle1;

extern DMA_HandleTypeDef hdma_adc3;
extern ADC_HandleTypeDef AdcHandle3;
//--------------------------------------------------------------------------------------------//
/**
  * @brief  get ADC1 value
  */
uint32_t Get_Adc1_Value(void)
{
	uint32_t adcResult = 0;
	HAL_ADC_Start(&AdcHandle1);
	HAL_ADC_PollForConversion(&AdcHandle1, 100);
	adcResult = HAL_ADC_GetValue(&AdcHandle1);
	HAL_ADC_Stop(&AdcHandle1);
	return adcResult;
}
//--------------------------------------------------------------------------------------------//
//
//--------------------------------------------------------------------------------------------//
/**
  * @brief  get adc1 voltage(mV)
  */
      
//    volt = (float)ADCValue1[0] * 3.3 / 0xfff;
//    ANS_AdcCPU_Data = (volt-0.76)/0.0025 + 25.0;
      
uint16_t getAdc1Vol(void)
{
     float volt;
    volt = (Get_Adc1_Value() * 3.3) / 0xFFF;
    
	return (volt-0.76)/0.0025 + 25.0; 
}
//--------------------------------------------------------------------------------------------//
//
//--------------------------------------------------------------------------------------------//
/**
  * @brief  get ADC2 value
  */
uint32_t Get_Adc2_Value(void)
{
	uint32_t adcResult = 0;
	HAL_ADC_Start(&AdcHandle3);
	HAL_ADC_PollForConversion(&AdcHandle3, 100);
	adcResult = HAL_ADC_GetValue(&AdcHandle3);
	HAL_ADC_Stop(&AdcHandle3);
	return adcResult;
}
//--------------------------------------------------------------------------------------------//
//
//--------------------------------------------------------------------------------------------//
/**
  * @brief  get adc2 voltage(mV)
  */
uint16_t getAdc2Vol(void)
{
	return (Get_Adc2_Value() * ADC_MAX_VOL) / ADC_MAX_DATA;
}
//--------------------------------------------------------------------------------------------//
//
//--------------------------------------------------------------------------------------------//
