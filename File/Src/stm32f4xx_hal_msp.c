/**
/*
    ******************************************************************************
    * @Company              : Woojin Industrial Systems Co., Ltd.
    * @Engineer             : D.S.JANG
    * @ModuleName           : stm32f4xx_hal.c
    * @ProjectName          : SEPTA ML
    * @TargetDevices        : LEDC-A5.2
    * @ToolVersions         : IAR 8.32.2.
    * Dependencies          : SEPTA_ML_FDI.BIN
    * @Revision             : 1.0.0.0
    ******************************************************************************
    * @AdditionalComments   :
    *                        1) Ver 1.0.0.0 : 2018/07/11 First release.
    ******************************************************************************
*/

/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx_hal.h"
#include "main.h"
#include "AmpGpio.h"

extern DMA_HandleTypeDef hdma_adc1;
extern DMA_HandleTypeDef hdma_adc3;
/** @addtogroup STM32F4xx_HAL_Examples
  * @{
  */

/** @defgroup HAL_MSP
  * @brief HAL MSP module.
  * @{
  */

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

/** @defgroup HAL_MSP_Private_Functions
  * @{
  */

/**
  * @brief TIM MSP Initialization 
  *        This function configures the hardware resources used in this example: 
  *           - Peripheral's clock enable
  *           - Peripheral's GPIO Configuration  
  * @param htim: TIM handle pointer
  * @retval None
  */


/**
  * @brief TIM MSP Initialization 
  *        This function configures the hardware resources used in this example: 
  *           - Peripheral's clock enable
  *           - Peripheral's GPIO Configuration  
  * @param htim: TIM handle pointer
  * @retval None
  */
void HAL_TIM_Base_MspInit(TIM_HandleTypeDef *htim)
{
	/*##-1- Enable peripherals and GPIO Clocks #################################*/
	/* TIMx Peripheral clock enable */

	if (htim->Instance == TIM3)
	{

		//		__HAL_RCC_TIM3_CLK_ENABLE();

		//		HAL_NVIC_ClearPendingIRQ(TIM3_IRQn);

		//		/*##-2- Configure the NVIC for TIMx ########################################*/
		//		/* Set Interrupt Group Priority */ 
		//		HAL_NVIC_SetPriority(TIM3_IRQn, 4, 0);

		//		/* Enable the TIMx global Interrupt */
		//		HAL_NVIC_EnableIRQ(TIM3_IRQn);

		//		HAL_TIM_Base_Start_IT(htim);

	}
	else  if (htim->Instance == TIM4)
	{
		__HAL_RCC_TIM4_CLK_ENABLE();
		HAL_NVIC_ClearPendingIRQ(TIM4_IRQn);

		/*##-2- Configure the NVIC for TIMx ########################################*/
		/* Set Interrupt Group Priority */ 
		HAL_NVIC_SetPriority(TIM4_IRQn, 4, 0);

		/* Enable the TIMx global Interrupt */
		HAL_NVIC_EnableIRQ(TIM4_IRQn);

		HAL_TIM_Base_Start_IT(htim);
                
	}
	else  if (htim->Instance == TIM5)
	{
		__HAL_RCC_TIM5_CLK_ENABLE();
		HAL_NVIC_ClearPendingIRQ(TIM5_IRQn);

		/*##-2- Configure the NVIC for TIMx ########################################*/
		/* Set Interrupt Group Priority */ 
		HAL_NVIC_SetPriority(TIM5_IRQn, 4, 0);

		/* Enable the TIMx global Interrupt */
		HAL_NVIC_EnableIRQ(TIM5_IRQn);

		HAL_TIM_Base_Start_IT(htim);

	}
  
  
}



void HAL_TIM_Base_MspDeInit(TIM_HandleTypeDef *htim)
{
	/*##-1- Enable peripherals and GPIO Clocks #################################*/
	/* TIMx Peripheral clock enable */

	if (htim->Instance == TIM3)
	{

		//		__HAL_RCC_TIM3_CLK_DISABLE();

		//		//    HAL_NVIC_ClearPendingIRQ(TIM3_IRQn);
		//		//    
		//		//      /*##-2- Configure the NVIC for TIMx ########################################*/
		//		//      /* Set Interrupt Group Priority */ 
		//		//      HAL_NVIC_SetPriority(TIM3_IRQn, 4, 0);

		//		/* Enable the TIMx global Interrupt */
		//		HAL_NVIC_DisableIRQ(TIM3_IRQn);

		//		HAL_TIM_Base_Stop_IT(htim);

	}
	else  if (htim->Instance == TIM4)
	{

		__HAL_RCC_TIM4_CLK_DISABLE();

		//    HAL_NVIC_ClearPendingIRQ(TIM4_IRQn);

		//      /*##-2- Configure the NVIC for TIMx ########################################*/
		//      /* Set Interrupt Group Priority */ 
		//      HAL_NVIC_SetPriority(TIM4_IRQn, 4, 0);
		//      
		//      /* Enable the TIMx global Interrupt */
		HAL_NVIC_DisableIRQ(TIM4_IRQn);

		HAL_TIM_Base_Stop_IT(htim);

	}
	else  if (htim->Instance == TIM5)
	{

		__HAL_RCC_TIM5_CLK_DISABLE();

		//    HAL_NVIC_ClearPendingIRQ(TIM4_IRQn);

		//      /*##-2- Configure the NVIC for TIMx ########################################*/
		//      /* Set Interrupt Group Priority */ 
		//      HAL_NVIC_SetPriority(TIM4_IRQn, 4, 0);
		//      
		//      /* Enable the TIMx global Interrupt */
		HAL_NVIC_DisableIRQ(TIM5_IRQn);

		HAL_TIM_Base_Stop_IT(htim);

	}
  
  
}

	  /** @defgroup HAL_MSP_Private_Functions
  * @{
  */

  /**
	* @brief RTC MSP Initialization
	*        This function configures the hardware resources used in this example
	* @param hrtc: RTC handle pointer
	*
	* @note  Care must be taken when HAL_RCCEx_PeriphCLKConfig() is used to select
	*        the RTC clock source; in this case the Backup domain will be reset in
	*        order to modify the RTC Clock source, as consequence RTC registers (including
	*        the backup registers) and RCC_BDCR register are set to their reset values.
	*
	* @retval None
	*/
void HAL_RTC_MspInit(RTC_HandleTypeDef *hrtc)
{
	RCC_OscInitTypeDef        RCC_OscInitStruct;
	RCC_PeriphCLKInitTypeDef  PeriphClkInitStruct;

	/*##-1- Configue LSE as RTC clock soucre ###################################*/
#ifdef RTC_CLOCK_SOURCE_LSE
	RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_LSI | RCC_OSCILLATORTYPE_LSE;
	RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
	RCC_OscInitStruct.LSEState = RCC_LSE_ON;
	RCC_OscInitStruct.LSIState = RCC_LSI_OFF;
	if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
	{
		//Error_Handler();
	}

	PeriphClkInitStruct.PeriphClockSelection = RCC_PERIPHCLK_RTC;
	PeriphClkInitStruct.RTCClockSelection = RCC_RTCCLKSOURCE_LSE;
	if (HAL_RCCEx_PeriphCLKConfig(&PeriphClkInitStruct) != HAL_OK)
	{
		//Error_Handler();
	}
#elif defined (RTC_CLOCK_SOURCE_LSI)  
	RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_LSI | RCC_OSCILLATORTYPE_LSE;
	RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
	RCC_OscInitStruct.LSIState = RCC_LSI_ON;
	RCC_OscInitStruct.LSEState = RCC_LSE_OFF;
	if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
	{
		Error_Handler();
	}

	PeriphClkInitStruct.PeriphClockSelection = RCC_PERIPHCLK_RTC;
	PeriphClkInitStruct.RTCClockSelection = RCC_RTCCLKSOURCE_LSI;
	if (HAL_RCCEx_PeriphCLKConfig(&PeriphClkInitStruct) != HAL_OK)
	{
		Error_Handler();
	}
#else
#error Please select the RTC Clock source inside the main.h file
#endif /*RTC_CLOCK_SOURCE_LSE*/

  /*##-2- Enable RTC peripheral Clocks #######################################*/
  /* Enable RTC Clock */
	__HAL_RCC_RTC_ENABLE();

	/*##-3- Configure the NVIC for RTC Alarm ###################################*/
	HAL_NVIC_SetPriority(RTC_Alarm_IRQn, 0x0F, 0);
	HAL_NVIC_EnableIRQ(RTC_Alarm_IRQn);
}

/**
  * @brief RTC MSP De-Initialization
  *        This function freeze the hardware resources used in this example:
  *          - Disable the Peripheral's clock
  * @param hrtc: RTC handle pointer
  * @retval None
  */
void HAL_RTC_MspDeInit(RTC_HandleTypeDef *hrtc)
{
	/*##-1- Reset peripherals ##################################################*/
	__HAL_RCC_RTC_DISABLE();
}



/**
* @brief I2C MSP Initialization
* This function configures the hardware resources used in this example
* @param hi2c: I2C handle pointer
* @retval None
*/
void HAL_I2C_MspInit(I2C_HandleTypeDef* hi2c)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};
  
   if(hi2c->Instance==I2C1)
  {
  /* USER CODE BEGIN I2C2_MspInit 0 */

  /* USER CODE END I2C2_MspInit 0 */

    __HAL_RCC_GPIOB_CLK_ENABLE();
    /**I2C2 GPIO Configuration
    PB10     ------> I2C2_SCL
    PB11     ------> I2C2_SDA
    */
    GPIO_InitStruct.Pin = GPIO_PIN_6|GPIO_PIN_7;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_OD;
    GPIO_InitStruct.Pull = GPIO_PULLUP;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
    GPIO_InitStruct.Alternate = GPIO_AF4_I2C1;
    HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

    /* Peripheral clock enable */
    __HAL_RCC_I2C1_CLK_ENABLE();
  /* USER CODE BEGIN I2C2_MspInit 1 */
    /* Peripheral interrupt init*/
    
    
    HAL_NVIC_SetPriority(I2C1_ER_IRQn, 1, 0);
  HAL_NVIC_EnableIRQ(I2C1_ER_IRQn);
  HAL_NVIC_SetPriority(I2C1_EV_IRQn, 2, 0);
  HAL_NVIC_EnableIRQ(I2C1_EV_IRQn);
  

    

  /* USER CODE END I2C2_MspInit 1 */
  }
  else if(hi2c->Instance==I2C2)
  {
  /* USER CODE BEGIN I2C2_MspInit 0 */

  /* USER CODE END I2C2_MspInit 0 */

    __HAL_RCC_GPIOB_CLK_ENABLE();
    /**I2C2 GPIO Configuration
    PB10     ------> I2C2_SCL
    PB11     ------> I2C2_SDA
    */
    GPIO_InitStruct.Pin = GPIO_PIN_10|GPIO_PIN_11;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_OD;
    GPIO_InitStruct.Pull = GPIO_PULLUP;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
    GPIO_InitStruct.Alternate = GPIO_AF4_I2C2;
    HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

    /* Peripheral clock enable */
    __HAL_RCC_I2C2_CLK_ENABLE();
  /* USER CODE BEGIN I2C2_MspInit 1 */

    HAL_NVIC_SetPriority(I2C2_ER_IRQn, 1, 0);
  HAL_NVIC_EnableIRQ(I2C2_ER_IRQn);
  HAL_NVIC_SetPriority(I2C2_EV_IRQn, 2, 0);
  HAL_NVIC_EnableIRQ(I2C2_EV_IRQn);
    

  /* USER CODE END I2C2_MspInit 1 */
  }

}


/**
* @brief I2C MSP De-Initialization
* This function freeze the hardware resources used in this example
* @param hi2c: I2C handle pointer
* @retval None
*/
void HAL_I2C_MspDeInit(I2C_HandleTypeDef* hi2c)
{
  if(hi2c->Instance==I2C1)
  {
  /* USER CODE BEGIN I2C1_MspDeInit 0 */

  /* USER CODE END I2C1_MspDeInit 0 */
    /* Peripheral clock disable */
    __HAL_RCC_I2C1_CLK_DISABLE();

    /**I2C1 GPIO Configuration
    PB6     ------> I2C1_SCL
    PB7     ------> I2C1_SDA
    */
    HAL_GPIO_DeInit(GPIOB, GPIO_PIN_6);

    HAL_GPIO_DeInit(GPIOB, GPIO_PIN_7);

    
    HAL_NVIC_DisableIRQ(I2C1_ER_IRQn);
    HAL_NVIC_DisableIRQ(I2C1_EV_IRQn);
  
  
  /* USER CODE BEGIN I2C1_MspDeInit 1 */

  /* USER CODE END I2C1_MspDeInit 1 */
  }
  else if(hi2c->Instance==I2C2)
  {
  /* USER CODE BEGIN I2C3_MspDeInit 0 */

  /* USER CODE END I2C3_MspDeInit 0 */
    /* Peripheral clock disable */
    __HAL_RCC_I2C2_CLK_DISABLE();

    /**I2C3 GPIO Configuration
    PC9     ------> I2C3_SDA
    PA8     ------> I2C3_SCL
    */
    HAL_GPIO_DeInit(GPIOB, GPIO_PIN_10);

    HAL_GPIO_DeInit(GPIOB, GPIO_PIN_11);
    
    
    HAL_NVIC_DisableIRQ(I2C2_ER_IRQn);
    HAL_NVIC_DisableIRQ(I2C2_EV_IRQn);

  /* USER CODE BEGIN I2C3_MspDeInit 1 */

  /* USER CODE END I2C3_MspDeInit 1 */
  }

}


/**
* @brief ADC MSP De-Initialization
* This function freeze the hardware resources used in this example
* @param hadc: ADC handle pointer
* @retval None
*/


void HAL_ADC_MspInit(ADC_HandleTypeDef* hadc)
{

 //GPIO_InitTypeDef GPIO_InitStruct;
  if(hadc->Instance==ADC1)
  {
      GPIO_InitTypeDef          GPIO_InitStruct;
      //static DMA_HandleTypeDef  hdma_adc;
      
      /*##-1- Enable peripherals and GPIO Clocks #################################*/
      /* Enable GPIO clock */
//      __HAL_RCC_GPIOA_CLK_ENABLE();

      /* ADC3 Periph clock enable */
      __HAL_RCC_ADC1_CLK_ENABLE();
      /* Enable DMA2 clock */
     // __HAL_RCC_DMA2_CLK_ENABLE(); 
      
      /*##-2- Configure peripheral GPIO ##########################################*/ 
      /* ADC3 Channel8 GPIO pin configuration */
//      GPIO_InitStruct.Pin = ANS_OUT_Pin;
//      GPIO_InitStruct.Mode = GPIO_MODE_ANALOG;
//      GPIO_InitStruct.Pull = GPIO_NOPULL;
//      HAL_GPIO_Init(ANS_OUT_Port, &GPIO_InitStruct);
      
      /*##-3- Configure the DMA streams ##########################################*/
      /* Set the parameters to be configured */
	  hdma_adc1.Instance = DMA2_Stream4;
	  hdma_adc1.Init.Channel  = DMA_CHANNEL_0;
	  hdma_adc1.Init.Direction = DMA_PERIPH_TO_MEMORY;
	  hdma_adc1.Init.PeriphInc = DMA_PINC_DISABLE;
	  hdma_adc1.Init.MemInc = DMA_MINC_ENABLE;
	  hdma_adc1.Init.PeriphDataAlignment = DMA_PDATAALIGN_WORD;
	  hdma_adc1.Init.MemDataAlignment = DMA_MDATAALIGN_WORD;
	  hdma_adc1.Init.Mode = DMA_CIRCULAR;
	  hdma_adc1.Init.Priority = DMA_PRIORITY_LOW;
	  hdma_adc1.Init.FIFOMode = DMA_FIFOMODE_DISABLE;         
          
	  //hdma_adc1.Init.FIFOThreshold = DMA_FIFO_THRESHOLD_HALFFULL;
	  //hdma_adc1.Init.MemBurst = DMA_MBURST_SINGLE;
	  //hdma_adc1.Init.PeriphBurst = DMA_PBURST_SINGLE; 

	  HAL_DMA_Init(&hdma_adc1);
        
      /* Associate the initialized DMA handle to the the ADC handle */
	  __HAL_LINKDMA(hadc, DMA_Handle, hdma_adc1);

      /*##-4- Configure the NVIC for DMA #########################################*/
      /* NVIC configuration for DMA transfer complete interrupt */
     // HAL_NVIC_SetPriority(DMA2_Stream0_IRQn, 0, 0);   
     // HAL_NVIC_EnableIRQ(DMA2_Stream0_IRQn);
  }
  else if(hadc->Instance==ADC3)
  {
       GPIO_InitTypeDef          GPIO_InitStruct;
      //static DMA_HandleTypeDef  hdma_adc;
      
      /*##-1- Enable peripherals and GPIO Clocks #################################*/
      /* Enable GPIO clock */
      __HAL_RCC_GPIOA_CLK_ENABLE();

      /* ADC3 Periph clock enable */
      __HAL_RCC_ADC3_CLK_ENABLE();
      /* Enable DMA2 clock */
     // __HAL_RCC_DMA2_CLK_ENABLE(); 
      
      /*##-2- Configure peripheral GPIO ##########################################*/ 
      /* ADC3 Channel8 GPIO pin configuration */
      GPIO_InitStruct.Pin = ANS_OUT_Pin;
      GPIO_InitStruct.Mode = GPIO_MODE_ANALOG;
      GPIO_InitStruct.Pull = GPIO_NOPULL;
      HAL_GPIO_Init(ANS_OUT_Port, &GPIO_InitStruct);
      
      /*##-3- Configure the DMA streams ##########################################*/
      /* Set the parameters to be configured */
	  hdma_adc3.Instance = DMA2_Stream0;
	  hdma_adc3.Init.Channel  = DMA_CHANNEL_2;
	  hdma_adc3.Init.Direction = DMA_PERIPH_TO_MEMORY;
	  hdma_adc3.Init.PeriphInc = DMA_PINC_DISABLE;
	  hdma_adc3.Init.MemInc = DMA_MINC_ENABLE;
	  hdma_adc3.Init.PeriphDataAlignment = DMA_PDATAALIGN_WORD;
	  hdma_adc3.Init.MemDataAlignment = DMA_MDATAALIGN_WORD;
	  hdma_adc3.Init.Mode = DMA_CIRCULAR;
	  hdma_adc3.Init.Priority = DMA_PRIORITY_LOW;
	  hdma_adc3.Init.FIFOMode = DMA_FIFOMODE_DISABLE;         
          
	  //hdma_adc1.Init.FIFOThreshold = DMA_FIFO_THRESHOLD_HALFFULL;
	  //hdma_adc1.Init.MemBurst = DMA_MBURST_SINGLE;
	  //hdma_adc1.Init.PeriphBurst = DMA_PBURST_SINGLE; 

	  HAL_DMA_Init(&hdma_adc3);
        
      /* Associate the initialized DMA handle to the the ADC handle */
	  __HAL_LINKDMA(hadc, DMA_Handle, hdma_adc3);

      /*##-4- Configure the NVIC for DMA #########################################*/
      /* NVIC configuration for DMA transfer complete interrupt */
     // HAL_NVIC_SetPriority(DMA2_Stream0_IRQn, 0, 0);   
     // HAL_NVIC_EnableIRQ(DMA2_Stream0_IRQn);
      
  }

}

void HAL_ADC_MspDeInit(ADC_HandleTypeDef* hadc)
{

  if(hadc->Instance==ADC1)
  {
     //static DMA_HandleTypeDef  hdma_adc;
      
      /*##-1- Reset peripherals ##################################################*/
      //__HAL_RCC_ADC_FORCE_RESET();
      //__HAL_RCC_ADC_RELEASE_RESET();
	  
	  //__HAL_RCC_ADC1_CLK_ENABLE();
	  __HAL_RCC_ADC1_CLK_DISABLE();
	  //__HAL_RCC_DMA2_CLK_ENABLE(); 
	  //__HAL_RCC_DMA2_CLK_DISABLE();
      /*##-2- Disable peripherals and GPIO Clocks ################################*/
      /* De-initialize the ADC3 Channel8 GPIO pin */
      //HAL_GPIO_DeInit(ANS_OUT_Port, ANS_OUT_Pin);
      
      /*##-3- Disable the DMA Streams ############################################*/
      /* De-Initialize the DMA Stream associate to transmission process */

	  HAL_DMA_DeInit(&hdma_adc1); 
      /*##-4- Disable the NVIC for DMA ###########################################*/
      //HAL_NVIC_DisableIRQ(DMA2_Stream0_IRQn);
	  
  
  }
  else if(hadc->Instance==ADC3)
  {
       //static DMA_HandleTypeDef  hdma_adc;
      
      /*##-1- Reset peripherals ##################################################*/
      //__HAL_RCC_ADC_FORCE_RESET();
      //__HAL_RCC_ADC_RELEASE_RESET();
	  
	  //__HAL_RCC_ADC1_CLK_ENABLE();
	  __HAL_RCC_ADC3_CLK_DISABLE();
	  //__HAL_RCC_DMA2_CLK_ENABLE(); 
	  //__HAL_RCC_DMA2_CLK_DISABLE();
      /*##-2- Disable peripherals and GPIO Clocks ################################*/
      /* De-initialize the ADC3 Channel8 GPIO pin */
      HAL_GPIO_DeInit(ANS_OUT_Port, ANS_OUT_Pin);
      
      /*##-3- Disable the DMA Streams ############################################*/
      /* De-Initialize the DMA Stream associate to transmission process */

	  HAL_DMA_DeInit(&hdma_adc3); 
      /*##-4- Disable the NVIC for DMA ###########################################*/
      //HAL_NVIC_DisableIRQ(DMA2_Stream0_IRQn);
      
  }
  /* USER CODE BEGIN ADC1_MspDeInit 1 */

  /* USER CODE END ADC1_MspDeInit 1 */

}




/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
