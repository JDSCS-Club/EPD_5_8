


/*
    ******************************************************************************
    * @Company              : Woojin Industrial Systems Co., Ltd.
    * @Engineer             : D.S.JANG
    * @ModuleName           : USRAT.c
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



#include "stm32f4xx_hal.h"
//#incldue "stm32f407xx.h"
#include "string.h"
#include "stdarg.h"

#include "main.h"
#include "QBuf.h"



UART_HandleTypeDef UartHandle1; 

UART_HandleTypeDef UartHandle3;

UART_HandleTypeDef UartHandle4;

UART_HandleTypeDef UartHandle6;

DMA_HandleTypeDef hdma_usart4_tx;
DMA_HandleTypeDef hdma_usart4_rx;


__IO ITStatus UartReady = RESET;


USART_INIT_SHAPE USART_1Ch;
USART_INIT_SHAPE USART_3Ch;
USART_INIT_SHAPE USART_4Ch;
USART_INIT_SHAPE USART_6Ch;

RING_BUF_PRO RingBuf;


uint16_t crc16tab[256]= {
	0x0000,0x1021,0x2042,0x3063,0x4084,0x50a5,0x60c6,0x70e7,
	0x8108,0x9129,0xa14a,0xb16b,0xc18c,0xd1ad,0xe1ce,0xf1ef,
	0x1231,0x0210,0x3273,0x2252,0x52b5,0x4294,0x72f7,0x62d6,
	0x9339,0x8318,0xb37b,0xa35a,0xd3bd,0xc39c,0xf3ff,0xe3de,
	0x2462,0x3443,0x0420,0x1401,0x64e6,0x74c7,0x44a4,0x5485,
	0xa56a,0xb54b,0x8528,0x9509,0xe5ee,0xf5cf,0xc5ac,0xd58d,
	0x3653,0x2672,0x1611,0x0630,0x76d7,0x66f6,0x5695,0x46b4,
	0xb75b,0xa77a,0x9719,0x8738,0xf7df,0xe7fe,0xd79d,0xc7bc,
	0x48c4,0x58e5,0x6886,0x78a7,0x0840,0x1861,0x2802,0x3823,
	0xc9cc,0xd9ed,0xe98e,0xf9af,0x8948,0x9969,0xa90a,0xb92b,
	0x5af5,0x4ad4,0x7ab7,0x6a96,0x1a71,0x0a50,0x3a33,0x2a12,
	0xdbfd,0xcbdc,0xfbbf,0xeb9e,0x9b79,0x8b58,0xbb3b,0xab1a,
	0x6ca6,0x7c87,0x4ce4,0x5cc5,0x2c22,0x3c03,0x0c60,0x1c41,
	0xedae,0xfd8f,0xcdec,0xddcd,0xad2a,0xbd0b,0x8d68,0x9d49,
	0x7e97,0x6eb6,0x5ed5,0x4ef4,0x3e13,0x2e32,0x1e51,0x0e70,
	0xff9f,0xefbe,0xdfdd,0xcffc,0xbf1b,0xaf3a,0x9f59,0x8f78,
	0x9188,0x81a9,0xb1ca,0xa1eb,0xd10c,0xc12d,0xf14e,0xe16f,
	0x1080,0x00a1,0x30c2,0x20e3,0x5004,0x4025,0x7046,0x6067,
	0x83b9,0x9398,0xa3fb,0xb3da,0xc33d,0xd31c,0xe37f,0xf35e,
	0x02b1,0x1290,0x22f3,0x32d2,0x4235,0x5214,0x6277,0x7256,
	0xb5ea,0xa5cb,0x95a8,0x8589,0xf56e,0xe54f,0xd52c,0xc50d,
	0x34e2,0x24c3,0x14a0,0x0481,0x7466,0x6447,0x5424,0x4405,
	0xa7db,0xb7fa,0x8799,0x97b8,0xe75f,0xf77e,0xc71d,0xd73c,
	0x26d3,0x36f2,0x0691,0x16b0,0x6657,0x7676,0x4615,0x5634,
	0xd94c,0xc96d,0xf90e,0xe92f,0x99c8,0x89e9,0xb98a,0xa9ab,
	0x5844,0x4865,0x7806,0x6827,0x18c0,0x08e1,0x3882,0x28a3,
	0xcb7d,0xdb5c,0xeb3f,0xfb1e,0x8bf9,0x9bd8,0xabbb,0xbb9a,
	0x4a75,0x5a54,0x6a37,0x7a16,0x0af1,0x1ad0,0x2ab3,0x3a92,
	0xfd2e,0xed0f,0xdd6c,0xcd4d,0xbdaa,0xad8b,0x9de8,0x8dc9,
	0x7c26,0x6c07,0x5c64,0x4c45,0x3ca2,0x2c83,0x1ce0,0x0cc1,
	0xef1f,0xff3e,0xcf5d,0xdf7c,0xaf9b,0xbfba,0x8fd9,0x9ff8,
	0x6e17,0x7e36,0x4e55,0x5e74,0x2e93,0x3eb2,0x0ed1,0x1ef0
};



uint8_t mUSARTRXFlag_1Ch = 0;
uint8_t mUSARTRXFlag_3Ch = 0;
uint8_t mUSARTRXFlag_4Ch = 0;
uint8_t mUSARTRXFlag_6Ch = 0;

uint8_t mUSART_RXBuf_1ch[USART_BUF_MIN];
uint8_t mUSART_GetRXBuf_1ch[USART_BUF_Get];
uint8_t mUSART_TXBuf_1ch[USART_BUF_MIN];
uint8_t mUSART_RXBufBackUp_1ch[USART_BUF_MIN];


uint8_t mUSART_RXBuf_3ch[USART_BUF_MIN];
uint8_t mUSART_GetRXBuf_3ch[USART_BUF_Get];
uint8_t mUSART_TXBuf_3ch[USART_BUF_MIN];
uint8_t mUSART_RXBufBackUp_3ch[USART_BUF_MIN];

uint8_t mUSART_RXBuf_4ch[USART_BUF_MIN];
uint8_t mUSART_GetRXBuf_4ch[USART_BUF_Get];
uint8_t mUSART_TXBuf_4ch[USART_BUF_MIN];
uint8_t mUSART_RXBufBackUp_4ch[USART_BUF_MIN];


uint8_t mUSART_RXBuf_6ch[USART_BUF_MIN];
uint8_t mUSART_GetRXBuf_6ch[USART_BUF_Get];
uint8_t mUSART_TXBuf_6ch[USART_BUF_MIN];
uint8_t mUSART_RXBufBackUp_6ch[USART_BUF_MIN];


uint8_t mUSART_TIM_Flag = 0;
uint8_t mUSART_TIM_60sFlag = 0;

uint8_t mSSID_TIM_1sFlag = 0;


uint32_t mUSART_TIM_Cnt = 0;


uint8_t mXbeeSSID[3][2][10] = {"+++","OK","ATID\r","OK","ATCN\r","OK"};
uint8_t mXbeeSSIDFlagCnt = 0;
uint8_t mSSID[10];


/**
  * @brief UART MSP Initialization 
  *        This function configures the hardware resources used in this example: 
  *           - Peripheral's clock enable
  *           - Peripheral's GPIO Configuration  
  * @param huart: UART handle pointer
  * @retval None
  */
  


void HAL_UART_MspInit(UART_HandleTypeDef *huart)
{  
	GPIO_InitTypeDef  GPIO_InitStruct;
   
  
	if (huart->Instance == USART1)
	{

		/*##-1- Enable peripherals and GPIO Clocks #################################*/
		/* Enable GPIO TX/RX clock */
		__HAL_RCC_GPIOA_CLK_ENABLE();

		/* Enable USART1 clock */
		__HAL_RCC_USART1_CLK_ENABLE(); 

		/*##-2- Configure peripheral GPIO ##########################################*/  
		/* UART TX /GPIO pin configuration  */
		GPIO_InitStruct.Pin       = GPIO_PIN_9 | GPIO_PIN_10;
		GPIO_InitStruct.Mode      = GPIO_MODE_AF_PP;
		GPIO_InitStruct.Pull      = GPIO_PULLUP;
		GPIO_InitStruct.Speed     = GPIO_SPEED_HIGH;
		GPIO_InitStruct.Alternate = GPIO_AF7_USART1;

		HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

		/* UART RX GPIO pin configuration  */
		//GPIO_InitStruct.Pin = GPIO_PIN_10;

		//HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);


		HAL_NVIC_SetPriority(USART1_IRQn, 14, 1);
		HAL_NVIC_EnableIRQ(USART1_IRQn);
	}
    
    
	else if (huart->Instance == USART3)
	{
		/*##-1- Enable peripherals and GPIO Clocks #################################*/
	  /* Enable GPIO TX/RX clock */
		__HAL_RCC_GPIOD_CLK_ENABLE();

		/* Enable USART1 clock */
		__HAL_RCC_USART3_CLK_ENABLE(); 

		/*##-2- Configure peripheral GPIO ##########################################*/  
		/* UART TX GPIO pin configuration  */
		GPIO_InitStruct.Pin       = GPIO_PIN_8 | GPIO_PIN_9;
		GPIO_InitStruct.Mode      = GPIO_MODE_AF_PP;
		GPIO_InitStruct.Pull      = GPIO_PULLUP;
		GPIO_InitStruct.Speed     = GPIO_SPEED_HIGH;
		GPIO_InitStruct.Alternate = GPIO_AF7_USART3;

		HAL_GPIO_Init(GPIOD, &GPIO_InitStruct);

		/* UART RX GPIO pin configuration  */
		//GPIO_InitStruct.Pin = GPIO_PIN_11;
		//GPIO_InitStruct.Alternate = GPIO_AF7_USART3;

		//HAL_GPIO_Init(GPIOD, &GPIO_InitStruct);


		HAL_NVIC_SetPriority(USART3_IRQn, 15, 1);
		HAL_NVIC_EnableIRQ(USART3_IRQn);
	}
    else if (huart->Instance == USART6)
	{
       /*##-1- Enable peripherals and GPIO Clocks #################################*/
	  /* Enable GPIO TX/RX clock */
		__HAL_RCC_GPIOC_CLK_ENABLE();

		/* Enable USART1 clock */
		__HAL_RCC_USART6_CLK_ENABLE(); 

		/*##-2- Configure peripheral GPIO ##########################################*/  
		/* UART TX GPIO pin configuration  */
		GPIO_InitStruct.Pin       = GPIO_PIN_6 | GPIO_PIN_7;
		GPIO_InitStruct.Mode      = GPIO_MODE_AF_PP;
		GPIO_InitStruct.Pull      = GPIO_PULLUP;
		GPIO_InitStruct.Speed     = GPIO_SPEED_HIGH;
		GPIO_InitStruct.Alternate = GPIO_AF8_USART6;

		HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

		/* UART RX GPIO pin configuration  */
		//GPIO_InitStruct.Pin = GPIO_PIN_11;
		//GPIO_InitStruct.Alternate = GPIO_AF7_USART3;

		//HAL_GPIO_Init(GPIOD, &GPIO_InitStruct);


		HAL_NVIC_SetPriority(USART6_IRQn, 15, 1);
		HAL_NVIC_EnableIRQ(USART6_IRQn);
        
    }
    

  
}

/**
  * @brief UART MSP De-Initialization 
  *        This function frees the hardware resources used in this example:
  *          - Disable the Peripheral's clock
  *          - Revert GPIO configuration to their default state
  * @param huart: UART handle pointer
  * @retval None
  */
void HAL_UART_MspDeInit(UART_HandleTypeDef *huart)
{

	if (huart->Instance == USART1)
	{
		__HAL_RCC_USART1_CLK_DISABLE();
		/*##-1- Reset peripherals ##################################################*/
		__HAL_RCC_USART1_FORCE_RESET();
		__HAL_RCC_USART1_RELEASE_RESET();

		/*##-2- Disable peripherals and GPIO Clocks #################################*/
		/* Configure UART Tx as alternate function  */
		HAL_GPIO_DeInit(GPIOA, GPIO_PIN_9);
		/* Configure UART Rx as alternate function  */
		HAL_GPIO_DeInit(GPIOA, GPIO_PIN_10);

		HAL_NVIC_DisableIRQ(USART1_IRQn);
	}
    
	else if (huart->Instance == USART3)
	{
		__HAL_RCC_USART3_CLK_DISABLE();
		/*##-1- Reset peripherals ##################################################*/
		__HAL_RCC_USART3_FORCE_RESET();
		__HAL_RCC_USART3_RELEASE_RESET();

		/*##-2- Disable peripherals and GPIO Clocks #################################*/
		/* Configure UART Tx as alternate function  */
		HAL_GPIO_DeInit(GPIOD, GPIO_PIN_8);
		/* Configure UART Rx as alternate function  */
		HAL_GPIO_DeInit(GPIOD, GPIO_PIN_9);

		HAL_NVIC_DisableIRQ(USART3_IRQn);
	}
    else if (huart->Instance == USART6)
	{
		__HAL_RCC_USART6_CLK_DISABLE();
		/*##-1- Reset peripherals ##################################################*/
		__HAL_RCC_USART6_FORCE_RESET();
		__HAL_RCC_USART6_RELEASE_RESET();

		/*##-2- Disable peripherals and GPIO Clocks #################################*/
		/* Configure UART Tx as alternate function  */
		HAL_GPIO_DeInit(GPIOC, GPIO_PIN_6);
		/* Configure UART Rx as alternate function  */
		HAL_GPIO_DeInit(GPIOC, GPIO_PIN_7);

		HAL_NVIC_DisableIRQ(USART6_IRQn);
	}

  
}

/*****************************************************************************
* @brief -
* @param -
* @retval-
******************************************************************************/
uint16_t dUSART_Test = 0;

void USRAT_init(void)
{
    /*##-1- Configure the UART peripheral ######################################*/
    /* Put the USART peripheral in the Asynchronous mode (UART Mode) */
    /* UART1 configured as follow:
      - Word Length = 8 Bits
      - Stop Bit = One Stop bit
      - Parity = None
      - BaudRate = 9600 baud
      - Hardware flow control disabled (RTS and CTS signals) */
      
    /*############################## USART1  디버깅 ####################################*/      
    UartHandle1.Instance          = USART1;

    UartHandle1.Init.BaudRate     = 115200;
    UartHandle1.Init.WordLength   = UART_WORDLENGTH_8B;
    UartHandle1.Init.StopBits     = UART_STOPBITS_1;
    UartHandle1.Init.Parity       = UART_PARITY_NONE;
    UartHandle1.Init.HwFlowCtl    = UART_HWCONTROL_NONE;
    UartHandle1.Init.Mode         = UART_MODE_TX_RX;
    UartHandle1.Init.OverSampling = UART_OVERSAMPLING_16;


    HAL_UART_Init(&UartHandle1);

    HAL_UART_Receive_IT(&UartHandle1, (uint8_t *)mUSART_RXBuf_1ch, 1);   // 인터럽트 발생.


    
    
    //############################## USART3  Xbee ####################################
    UartHandle3.Instance          = USART3;

    UartHandle3.Init.BaudRate     = 115200;
    UartHandle3.Init.WordLength   = UART_WORDLENGTH_8B;
    UartHandle3.Init.StopBits     = UART_STOPBITS_1;
    UartHandle3.Init.Parity       = UART_PARITY_NONE;
    UartHandle3.Init.HwFlowCtl    = UART_HWCONTROL_NONE;
    UartHandle3.Init.Mode         = UART_MODE_TX_RX;
    UartHandle3.Init.OverSampling = UART_OVERSAMPLING_16;


    HAL_UART_Init(&UartHandle3);

    HAL_UART_Receive_IT(&UartHandle3, (uint8_t *)mUSART_RXBuf_3ch, 1);

    //############################## USART6  Xbee ####################################
    UartHandle6.Instance          = USART6;

    UartHandle6.Init.BaudRate     = 115200;
    UartHandle6.Init.WordLength   = UART_WORDLENGTH_8B;
    UartHandle6.Init.StopBits     = UART_STOPBITS_1;
    UartHandle6.Init.Parity       = UART_PARITY_NONE;
    UartHandle6.Init.HwFlowCtl    = UART_HWCONTROL_NONE;
    UartHandle6.Init.Mode         = UART_MODE_TX_RX;
    UartHandle6.Init.OverSampling = UART_OVERSAMPLING_16;


    HAL_UART_Init(&UartHandle6);

    HAL_UART_Receive_IT(&UartHandle6, (uint8_t *)mUSART_RXBuf_6ch, 1);


//    //############################## USART1 ####################################
    USART_1Ch.nRxOK = HAL_BUSY;
    USART_1Ch.nRxOK_Cnt = 0;
    USART_1Ch.nRxLen = 40; // 초기 길이를 10으로 지정.
    USART_1Ch.nRxPos = 0;
    USART_1Ch.nRxTimeOut = 5;
    USART_1Ch.nTxLen = 10;
    USART_1Ch.nTxPos = 0;
    USART_1Ch.nTxOK = TRUE;
    USART_1Ch.nTxOK_Cnt = 0;
    USART_1Ch.nTxTimeOut = 200;
    USART_1Ch.nRxDlyTm = 0;
    USART_1Ch.nRxBuffer = mUSART_RXBuf_1ch;
    USART_1Ch.nGetRxBuf = mUSART_GetRXBuf_1ch;
    USART_1Ch.nTxBuffer = mUSART_TXBuf_1ch;
    USART_1Ch.nRxBuf_BackUp = mUSART_RXBufBackUp_1ch;

    memset(USART_1Ch.nRxBuffer,0,sizeof(mUSART_RXBuf_1ch));
    memset(USART_1Ch.nTxBuffer,0,sizeof(mUSART_TXBuf_1ch));
    memset(USART_1Ch.nRxBuf_BackUp,0,sizeof(mUSART_RXBufBackUp_1ch));

    //############################## USART3 ####################################
    USART_3Ch.nRxOK = 0;
    USART_3Ch.nRxOK_Cnt = 0;
    USART_3Ch.nRxLen = 20; // 초기 길이를 10으로 지정.
    USART_3Ch.nRxPos = 0;
    USART_3Ch.nTxLen = 10;
    USART_3Ch.nTxPos = 0;
    USART_3Ch.nTxOK = TRUE;
    USART_3Ch.nTxOK_Cnt = 0;
    USART_3Ch.nRxDlyTm = 0;
    USART_3Ch.nRxBuffer = mUSART_RXBuf_3ch;
    USART_3Ch.nGetRxBuf = mUSART_GetRXBuf_3ch;
    USART_3Ch.nTxBuffer = mUSART_TXBuf_3ch;
    USART_3Ch.nRxBuf_BackUp = mUSART_RXBufBackUp_3ch;

    memset(USART_3Ch.nRxBuffer,0,sizeof(mUSART_RXBuf_3ch));
    memset(USART_3Ch.nTxBuffer,0,sizeof(mUSART_TXBuf_3ch));
    memset(USART_3Ch.nRxBuf_BackUp,0,sizeof(mUSART_RXBufBackUp_3ch));
    
    
     //############################## USART6 ####################################
    USART_6Ch.nRxOK = 0;
    USART_6Ch.nRxOK_Cnt = 0;
    USART_6Ch.nRxLen = 20; // 초기 길이를 10으로 지정.
    USART_6Ch.nRxPos = 0;
    USART_6Ch.nTxLen = 10;
    USART_6Ch.nTxPos = 0;
    USART_6Ch.nTxOK = TRUE;
    USART_6Ch.nTxOK_Cnt = 0;
    USART_6Ch.nRxDlyTm = 0;
    USART_6Ch.nRxBuffer = mUSART_RXBuf_3ch;
    USART_6Ch.nGetRxBuf = mUSART_GetRXBuf_3ch;
    USART_6Ch.nTxBuffer = mUSART_TXBuf_3ch;
    USART_6Ch.nRxBuf_BackUp = mUSART_RXBufBackUp_3ch;

    memset(USART_6Ch.nRxBuffer,0,sizeof(mUSART_RXBuf_6ch));
    memset(USART_6Ch.nTxBuffer,0,sizeof(mUSART_TXBuf_6ch));
    memset(USART_6Ch.nRxBuf_BackUp,0,sizeof(mUSART_RXBufBackUp_6ch));
    
    //Cli Command 
    init_queue( &g_qUart1 );
    
     //RF Console
    init_queue( &g_qUart6 );



}

/*****************************************************************************
* @brief -
* @param -
* @retval-
******************************************************************************/
uint16_t crc16_ccitt_Woojin(uint8_t *buf, int len)
{
	int counter;
	uint16_t crc = 0xFFFF;
	for( counter = 0; counter < len; counter++)
		crc = (crc<<8) ^ crc16tab[((crc>>8) ^ buf[counter])];
        
    buf[len] = WORD_L(crc);
    buf[len+1] = WORD_H(crc);
    
    buf[len+2] = 0x03;

	return crc;
}

/*****************************************************************************
* @brief -
* @param -
* @retval-
******************************************************************************/
void USRAT_GPIO_Init(void)
{



}

/*****************************************************************************
* @brief -
* @param -
* @retval-
******************************************************************************/

void USART1_IRQHandler(void)
{
	HAL_UART_IRQHandler(& UartHandle1);
}

/*****************************************************************************
* @brief -
* @param -
* @retval-
******************************************************************************/

void USART3_IRQHandler(void)
{
	HAL_UART_IRQHandler(& UartHandle3);
}
/*****************************************************************************
* @brief -
* @param -
* @retval-
******************************************************************************/

void UART4_IRQHandler(void)
{
	HAL_UART_IRQHandler(& UartHandle4);
}

/*****************************************************************************
* @brief -
* @param -
* @retval-
******************************************************************************/

void USART6_IRQHandler(void)
{
	HAL_UART_IRQHandler(& UartHandle6);
}
/*****************************************************************************
  * @brief  This function handles DMA RX interrupt request.  
  * @param  None
  * @retval None  
******************************************************************************/

void DMA1_Stream2_IRQHandler(void)
{
    HAL_DMA_IRQHandler(&hdma_usart4_rx);
}


/*****************************************************************************
  * @brief  This function handles DMA TX interrupt request.
  * @param  None
  * @retval None  
******************************************************************************/
void DMA1_Stream4_IRQHandler(void)
{
    HAL_DMA_IRQHandler(&hdma_usart4_tx);
}
/*****************************************************************************
  * @brief  Tx Transfer completed callback
  * @param  UartHandle: UART handle. 
  * @note   This example shows a simple way to report end of IT Tx transfer, and 
  *         you can add your own implementation. 
  * @retval None
  ******************************************************************************/
void HAL_UART_TxCpltCallback(UART_HandleTypeDef *huart)
{
	/* Set transmission flag: transfer complete */
	//UartReady = SET;



}

/*****************************************************************************
  * @brief  Rx Transfer completed callback
  * @param  UartHandle: UART handle
  * @note   This example shows a simple way to report end of IT Rx transfer, and 
  *         you can add your own implementation.
  * @retval None
  ******************************************************************************/
void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
	/* Set transmission flag: transfer complete */
	//UartReady = SET;


	if(huart->Instance == USART1)
	{
        
        
		USART_1Ch.nRxOK = HAL_UART_Receive_IT(&UartHandle1, (uint8_t *)USART_1Ch.nGetRxBuf, 1);
        
        //	문자 Queue에 쌓기.
		qput( &g_qUart1, USART_1Ch.nGetRxBuf[0] );
        
        

	}
	else  if(huart->Instance == USART3)
	{
        
		HAL_UART_Receive_IT(&UartHandle3, (uint8_t *)USART_3Ch.nGetRxBuf, 1);
		
	}
    else  if(huart->Instance == USART6)
	{
        
		HAL_UART_Receive_IT(&UartHandle6, (uint8_t *)USART_6Ch.nGetRxBuf, 1);
        
        qput( &g_qUart6, USART_6Ch.nGetRxBuf[0] );
		
	}
	
}

/*****************************************************************************
  * @brief  UART error callbacks
  * @param  UartHandle: UART handle
  * @note   This example shows a simple way to report transfer error, and you can
  *         add your own implementation.
  * @retval None
  ******************************************************************************/
void HAL_UART_ErrorCallback(UART_HandleTypeDef *huart)
{
	/* Turn LED3 on: Transfer error in reception/transmission process */

}

/*****************************************************************************
* @brief -
* @param -
* @retval-
******************************************************************************/

void USARTRX_MainPro(void)
{
    uint8_t sRXBuf[5];
    uint8_t sKeypadFalg = 0;

    USART_RingBuf_Pro();
    
    
    if(USART_1Ch.nRxOK == HAL_OK)
    {
        USART_1Ch.nRxOK = HAL_BUSY;
        
        USART_1CH_PRO(USART_1Ch.nGetRxBuf);
        
        
    }
  

}



/*****************************************************************************
* @brief - USART_1CH_PRO
* @param - XCTU 와 연결 컨넥션 하는 기능으로 사용.
* @retval-
******************************************************************************/

void USART_1CH_PRO(uint8_t *pData)
{

    if(!USART_1Ch.nRxTimeOut) { USART_1Ch.nRxPos = 0;}
        
    USART_1Ch.nRxTimeOut = 5;
    
    USART_1Ch.nRxBuffer[USART_1Ch.nRxPos++] = pData[0];
		

    switch(USART_1Ch.nRxPos)
    {
//    case 0x01 :
//				
//				
//        break;
//    case 0x02 :
//    
//        break;
    
    default :
        
        if(USART_1Ch.nRxPos >= 5 )
        {
            if (strncmp((char*)(USART_1Ch.nRxBuffer), "DEBUG", 5) == 0)
            {
                memcpy(USART_1Ch.nRxBuf_BackUp , USART_1Ch.nRxBuffer,USART_1Ch.nRxLen);
            }
            
            USART_1Ch.nRxPos = 0;
            
   
        }
        break;
     }

     
}


/*****************************************************************************
* @brief - USART_1CH_PRO
* @param -
* @retval-
******************************************************************************/

void USART_3CH_PRO(uint8_t *pData)
{

	
	
     
}


/*****************************************************************************
* @brief - RF Console
* @param -
* @retval-
******************************************************************************/

void USART_6CH_PRO(uint8_t *pData)
{
    int nTick;
    static int s_nTick_F = 0;
    static int s_nTick_R = 0;
    static int s_RxnTick;

    static int s_RxOkFlag =0;
    static int s_RxOkLen =0;

    int s_EtxLen = 0;

    int idx;

    //=============================================================================
    int nTick_2;
    static int s_2_nTick_F = 0;
    static int s_2_nTick_R = 0;
    char d;


    //=============================================================================
    //
    char	c;

    nTick = HAL_GetTick();

    while (qcount(&g_qUart6) > 0)
    {

        s_nTick_F = nTick;

        // 통신 중간에 타임 아웃시 카운터 클리어 하는 부분 추가.
        if ( (s_nTick_F - s_nTick_R) >= 5){  USART_6Ch.nRxPos = 0; }
        s_nTick_R = s_nTick_F;

        c = qget(&g_qUart6);
        //		printf( "0x%02X ", c );

        USART_6Ch.nRxBuffer[USART_6Ch.nRxPos++] = c;		//	Buffering

       // s_EtxLen = (sizeof(FRAME_SDR) - 3);

        switch(USART_6Ch.nRxPos)
        {
            case 1:  break;
            default:
            if(USART_6Ch.nRxPos >= 7 )
            {
                if (strncmp((char*)(USART_6Ch.nRxBuffer), "RSSI_NG", 7) == 0)
                {
             

                    Dump( "Rx : ", USART_6Ch.nRxBuffer, USART_6Ch.nRxPos );

                    USART_6Ch.nRxPos = 0;

                }
                else
                {
                    init_queue(&g_qUart6);		//	Queue Clear

                    USART_6Ch.nRxPos = 0;
                }
                
                USART_6Ch.nRxOK = 1;

            }
            break;
        }
    }

    // RX 수신 OK 하면.
    if ( ((nTick - s_RxnTick) >= 10) && (USART_6Ch.nRxOK == 1))
    {
        USART_6Ch.nRxOK = 0;
        s_RxnTick = nTick;

    //ProcessFrame(rxbuffer_2, s_RxOkLen);
    }
    

     
}

/*****************************************************************************
* @brief - 1ms 타이머 함수
* @param -
* @retval-
******************************************************************************/
void USART_TIM(void)
{
    
    if(USART_1Ch.nRxTimeOut) { USART_1Ch.nRxTimeOut--;}
    
    
	
//		1mUSART_TIM_Flag = 1;
//	
//		mUSART_TIM_Cnt++;
//		//Keypad 누르면, 일정 시간동안 추가로 기다린다.
//		if(!(mUSART_TIM_Cnt%(30000+ (nKeypadNum_ChangFlage*5000)))){ mUSART_TIM_60sFlag  = 1; }
//		
//		if(!(mUSART_TIM_Cnt%2000)) {mSSID_TIM_1sFlag = 1;}
		

}


	

/*****************************************************************************
* @brief - MyPrintf
* @param -
* @retval-
******************************************************************************/

void MyPrintf(uint8_t *pData,int len,char * format, ...)
{
	int i;
	int sLne;

	uint8_t sBuf[512];
	uint8_t sBuf_2[10];
	
	va_list args;
	static char szBuf2[1024];
	
	va_start(args, format);
	vsprintf(szBuf2, format, args);
	
	sLne = strlen(szBuf2);
	
	memcpy(&sBuf[0],(uint8_t*)szBuf2,sLne);
	
	
	for(i = 0; i < len; i++)
	{
		//printf("%02X-",pData[i]);
		
		sprintf((char*)&sBuf_2[0],"%02X-", pData[i]);
		memcpy(&sBuf[sLne+(i*3)],&sBuf_2[0],3);
		
	}

	
	//printf("\n\r");
	
	sprintf((char*)&sBuf_2[0],"\n\r");
	memcpy(&sBuf[sLne + (i*3)],&sBuf_2[0],4);
	
	//HAL_UART_Transmit_IT(&UartHandle1, (uint8_t *)&sBuf[0],sLne + (i*3)+2);
    DP_RING_BUF_PUSH((uint8_t *)&sBuf[0],sLne + (i*3)+2,4);
    
	////HAL_UART_Transmit_DMA(&UartHandle1, (uint8_t *)&sBuf[0], sLne + (i * 3) + 2);
	va_end(args);
	
	
	
}


//*********************************************************************************************************
// MyPrintf_USART1
//*********************************************************************************************************
int mChen = 0;

void MyPrintf_USART1(char *format, ... )
{
	va_list args;
	static char szBuf[1024];
    
    mChen = 1;
	
	va_start(args, format);
	vsprintf(szBuf, format, args);
	
    
	//HAL_UART_Transmit_IT(&UartHandle1, (uint8_t*)szBuf,strlen(szBuf));
    
    if(mChen == 0x01)
    {
        DP_RING_BUF_PUSH((uint8_t*)szBuf,strlen(szBuf),1);
    }
    else if(mChen == 0x03)
    {
        DP_RING_BUF_PUSH((uint8_t*)szBuf,strlen(szBuf),3);
    }
     else if(mChen == 0x06)
    {
        DP_RING_BUF_PUSH((uint8_t*)szBuf,strlen(szBuf),6);
    }
    
	////HAL_UART_Transmit_DMA(&UartHandle1, (uint8_t*)szBuf, strlen(szBuf));


	va_end(args);
}

//*****************************************************************************************
//	BCD_BIN
//*****************************************************************************************
uint16_t BCD_BIN(uint16_t nInput)
{
    uint16_t sNum = 0;

    sNum += ((nInput>>12)&0xf) * 1000;
    sNum += ((nInput>>8)&0xf) * 100;
    sNum += ((nInput>>4)&0xf) * 10;
    sNum += ((nInput)&0xf);
    return sNum;
}

//*****************************************************************************************
//	BCD_BIN
//*****************************************************************************************
uint16_t BIN_BCD(uint16_t nInput)
{
	uint16_t sNum = 0;

	sNum += ((nInput / 1000) & 0xf) << 12;
	sNum += ((nInput / 100) & 0xf) << 8;
	sNum += ((nInput / 10) & 0xf) << 4;
	sNum += ((nInput) % 10);
	return sNum;
}


//*****************************************************************************************
//	ASC? HEX? ???.
//*****************************************************************************************
uint8_t ConvAsc2Hex(char chDat)
{
	int nBuf = 0;	
	if(chDat >= '0' && chDat <= '9') nBuf = chDat-'0';		
	else
	if(chDat >= 'a' && chDat <= 'f') nBuf = ((chDat-'a') + 10);		
	else
	if(chDat >= 'A' && chDat <= 'F') nBuf = ((chDat-'A') + 10);
	
	return nBuf;
}

//*****************************************************************************************
//	???? ASC? HEX? ???.
//*****************************************************************************************
int FunConvAscHex(char *InchData,uint8_t *OuthexData,int Len)
{
	int i;
	int sCnt = 0;
	for(i=0;i<Len; )
	{
		OuthexData[sCnt] = (ConvAsc2Hex(InchData[i++])<<4)&0xF0;
		OuthexData[sCnt] |= ConvAsc2Hex(InchData[i++])&0x0F;

		sCnt++;
	}
	return sCnt;
}

//*****************************************************************************************
//	?? ASC???
//*****************************************************************************************
uint8_t IsNumAsc(char nCh)
{
	if(nCh >= '0' && nCh <= '9') return TRUE;
	return FALSE;
}

//*****************************************************************************************
//	ASC? DEC? ???.
//*****************************************************************************************
uint8_t ConvAsc2Dec(char nCh)
{
	int nBuf = 0;	
	if(nCh >= '0' && nCh <= '9') nBuf = nCh-'0'; else return 0;
	return nBuf;
}

//*****************************************************************************************
//	HEX? ASC? ???.
//*****************************************************************************************
char ConvHex2Asc(uint8_t btCh)
{
	char chBuf = '0';
	if(btCh >= 0 && btCh <= 9) chBuf = btCh+'0';
	else if(btCh >= 10 && btCh <= 15) chBuf = (btCh-10)+'A';
	return chBuf;
}
//*****************************************************************************************
//	DEC? HEX? ???.
//*****************************************************************************************
int ConvDec2Hex(char nCh)
{
	return ((((nCh / 0x10) & 0x0F) << 4) | ((nCh % 0x10) & 0x0F));
}

int FunConvHexAsc(uint8_t *InhexData,char *OUTAscData,int Len)
{
	int i;
	int sCnt = 0;
	for(i=0;i<Len;i++)
	{
		OUTAscData[sCnt++] = ConvHex2Asc(BYTE_H(InhexData[i]));
		OUTAscData[sCnt++] = ConvHex2Asc(BYTE_L(InhexData[i]));
	}
	return sCnt;
}


//========================================================================
void Dump( char *sTitle, char *sBuf, int nSize )
//========================================================================
{
	MyPrintf_USART1( "[%08d]%s ", HAL_GetTick(), sTitle );

	int idx;
	for ( idx = 0; idx < nSize; idx++ )
	{
		MyPrintf_USART1( "%02X ", sBuf[idx] );
	}
	MyPrintf_USART1("\n");
}


/*****************************************************************************
* @brief - MyPrintf
* @param -
* @retval-
******************************************************************************/

void USART_RingBuf_Pro(void)
{

  	uint8_t sCh;
    
    
    if(WORD_L(RingBuf.nPop_Cnt) != WORD_L(RingBuf.nPush_Cnt))
    {
 
        sCh = RingBuf.nRingData[(RingBuf.nPop_Cnt+1)%RING_BUF_SIZE].nCh;
        

        if(WORD_L(sCh) == 1)
        {
            if(UartHandle1.gState == HAL_UART_STATE_READY) // 통신 상태가 준비 일때 전송 한다.
            {
                
                DP_RING_BUF_POP(USART_1Ch.nTxBuffer,&USART_1Ch.nTxLen);
                HAL_UART_Transmit_IT(&UartHandle1, (uint8_t*)USART_1Ch.nTxBuffer,USART_1Ch.nTxLen);
            }

        }
        
        else if(WORD_L(sCh) == 3) // 485
        {
            if(UartHandle3.gState == HAL_UART_STATE_READY) // 통신 상태가 준비 일때 전송 한다.
            {
                
                HAL_GPIO_WritePin(RTS_3CH_Port,RTS_3CH_Pin,GPIO_PIN_SET); // CLK High   -> RTS ON
                
                DP_RING_BUF_POP(USART_3Ch.nTxBuffer,&USART_3Ch.nTxLen); 
                HAL_UART_Transmit_IT(&UartHandle3, (uint8_t*)USART_3Ch.nTxBuffer,USART_3Ch.nTxLen);
                
                //HAL_GPIO_WritePin(RTS_3CH_Port,RTS_3CH_Pin,GPIO_PIN_RESET);  //RTS OFF
                
            }

        }
         else if(WORD_L(sCh) == 6)
        {
            if(UartHandle6.gState == HAL_UART_STATE_READY) // 통신 상태가 준비 일때 전송 한다.
            {
                
                DP_RING_BUF_POP(USART_6Ch.nTxBuffer,&USART_6Ch.nTxLen);
                HAL_UART_Transmit_IT(&UartHandle6, (uint8_t*)USART_6Ch.nTxBuffer,USART_6Ch.nTxLen);
            }

        }


    }
    else{
      
      if(UartHandle3.gState == HAL_UART_STATE_READY)
      {
           HAL_GPIO_WritePin(RTS_3CH_Port,RTS_3CH_Pin,GPIO_PIN_RESET);  //RTS OFF
      }
      
    }
    

}
/******************************************************************
	PASS_RING_BUF_PUSH
*******************************************************************/
void DP_RING_BUF_PUSH(uint8_t *pData,uint16_t pLen,uint8_t Ch)
{
	uint16_t sLen;
	uint8_t sCh;

	sLen = (pLen >= 256) ? 256 : pLen ;
	sCh = Ch;


	RingBuf.nPush_Cnt++;
	RingBuf.nPush_Cnt = (RingBuf.nPush_Cnt)%RING_BUF_SIZE;
	
	if(WORD_L(RingBuf.nPush_Cnt) != WORD_L(RingBuf.nPop_Cnt))
	{
		RingBuf.nRingData[RingBuf.nPush_Cnt].nLen = sLen;
		RingBuf.nRingData[RingBuf.nPush_Cnt].nCh = sCh;
		memcpy(RingBuf.nRingData[RingBuf.nPush_Cnt].nDataBuf,pData,sLen);
	}
	else
	{
		RingBuf.nPop_Cnt++;
		RingBuf.nPop_Cnt = (RingBuf.nPop_Cnt)%RING_BUF_SIZE;
		RingBuf.nRingData[RingBuf.nPush_Cnt].nLen = sLen;
		RingBuf.nRingData[RingBuf.nPush_Cnt].nCh = sCh;
		memcpy(RingBuf.nRingData[RingBuf.nPush_Cnt].nDataBuf,pData,sLen);
	}
}
/******************************************************************
	PASS_RING_BUF_POP
*******************************************************************/
void DP_RING_BUF_POP(uint8_t *pData,uint16_t *pLen)
{
	if(WORD_L(RingBuf.nPush_Cnt) != WORD_L(RingBuf.nPop_Cnt))
	{
		RingBuf.nPop_Cnt++;
		RingBuf.nPop_Cnt = (RingBuf.nPop_Cnt)%RING_BUF_SIZE;

		*pLen =RingBuf.nRingData[RingBuf.nPop_Cnt].nLen;
		memcpy(pData,RingBuf.nRingData[RingBuf.nPop_Cnt].nDataBuf,*pLen);
	}
}





