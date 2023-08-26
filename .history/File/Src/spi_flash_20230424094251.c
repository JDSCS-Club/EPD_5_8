/*
    ******************************************************************************
    * @Company              : Woojin Industrial Systems Co., Ltd.
    * @Engineer             : D.S.JANG
    * @ModuleName           : spi_flash.c
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
#include "spi_flash.h"
#include "USRAT.h"

/* Private typedef -----------------------------------------------------------*/
#define SPI_FLASH_PageSize    256

/* Private define ------------------------------------------------------------*/
#define WRITE      0x02  /* Write to Memory Page_Program */

#define WRSR       0x01  /* Write Status Register instruction */

#define WREN       0x06  /* Write enable instruction */
#define WRDI       0x04  /* Write disables instruction */



#define READ       0x03  /* Read from Memory Read */
#define HS_READ    0x0B  /* *HighSpeed_Read*/
#define RDSR       0x05  /* Read Status Register instruction  */

#define ULBPR	   0x98  /* Global Block Protection Unlock */


#define RDID       0x9F  /* Read identification */

#define SE         0x20  /* Sector Erase instruction  4KByte Memory Array*/
#define BE         0xD8  /* Bulk Erase instruction  64,32 or 8KByte Memory Array*/
#define CE         0xC7  /* Chip_Erase Erase Full Array*/

#define WIP_Flag   0x80  /* Write In Progress (WIP) flag */


#define Dummy_Byte 0xFF


SPI_HandleTypeDef SpiMemoryHandle;



uint8_t SPI_Tx_Buffer[SPI_Buff_SIZE] = "STM32F40x SPI Firmware Library Example: communication with an M25P64 SPI FLASH";


uint8_t SPI_Index, SPI_Rx_Buffer[SPI_Buff_SIZE];
__IO uint32_t SPI_FLASH_ID;


uint32_t mSPI_Time_Cnt = 1;
uint32_t mSPI_Write_Cnt = 0;


uint16_t nBufCmapCnt = 1;
uint16_t nBufCmapCnt2 = 1;

/*****************************************************************************
* @brief -
* @param -
* @retval-
******************************************************************************/
void SPI_FLASH_Main(void)
{
    uint32_t sSpi_Mermory_Address = 0;
	
	if((mSPI_Time_Cnt==5000))
	{
		
        mSPI_Time_Cnt++;
        
        
        mSPI_Write_Cnt = mSPI_Write_Cnt %70;
        
		sSpi_Mermory_Address = SPI_FLASH_SectorToErase * mSPI_Write_Cnt;
        
		SPI_FLASH_ID = SPI_FLASH_ReadID(); /* Get SPI Flash ID */
		//SPI_FLASH_BufferRead(Rx_Buffer, sSpi_Mermory_Address, SPI_RX_BufferSize()); /* Read data from SPI FLASH memory */
		
		if(SST26VF032B_FLASH_ID == (SPI_FLASH_ID&0xFFFF))
		{
     
          
			SPI_FLASH_SectorErase(sSpi_Mermory_Address); /* Erase SPI FLASH Sector to write on */
			//	
			// SPI_Chip_Erase();
			//	
			SPI_FLASH_BufferWrite(SPI_Tx_Buffer, sSpi_Mermory_Address, 20); /* Write Tx_Buffer data to SPI FLASH memory */
	
			SPI_FLASH_BufferRead(SPI_Rx_Buffer, sSpi_Mermory_Address, 20); /* Read data from SPI FLASH memory */
			//nBufCmapCnt = Buffercmp(SPI_Tx_Buffer, SPI_Rx_Buffer, 20); /* Check the corectness of written dada */

			//	SPI_FLASH_SectorErase(SPI_FLASH_SectorToErase);
			//	SPI_FLASH_BufferRead(SPI_Rx_Buffer, sSpi_Mermory_Address, 20);
			//	
			//	for (SPI_Index = 0; SPI_Index < 20; SPI_Index++)
			//	{
			//		if (SPI_Rx_Buffer[SPI_Index] != 0xFF)
			//		{
			//			nBufCmapCnt2 = 0;
			//		}
			//	}
			
			 MyPrintf_USART1("---SPI ADDRESS : %X  ---SPI Read Data : %s  ---SPI Time : %d\n\r",sSpi_Mermory_Address, SPI_Rx_Buffer,mSPI_Time_Cnt);
             
             mSPI_Write_Cnt++;
			
		}
	
		

	}
	
	
}

/*****************************************************************************
* @brief -
* @param -
* @retval-
******************************************************************************/
void HAL_SPI_MspInit(SPI_HandleTypeDef* hspi)
{
	GPIO_InitTypeDef GPIO_InitStruct;
	if (hspi->Instance == SPI1)
	{

		  /* Peripheral clock enable */
		__HAL_RCC_SPI1_CLK_ENABLE();
  
		/**SPI1 GPIO Configuration    
		PA5     ------> SPI1_SCK
		PA7     ------> SPI1_MOSI
		PB4     ------> SPI1_MISO 
		*/
		GPIO_InitStruct.Pin = GPIO_PIN_5; 
		GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
		GPIO_InitStruct.Pull = GPIO_NOPULL;
		GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
		GPIO_InitStruct.Alternate = GPIO_AF5_SPI2;
		HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

		GPIO_InitStruct.Pin = GPIO_PIN_5 | GPIO_PIN_6;		
		GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
		GPIO_InitStruct.Pull = GPIO_NOPULL;
		GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
		GPIO_InitStruct.Alternate = GPIO_AF5_SPI2;
		HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);


	}
	
}
/*****************************************************************************
* @brief -
* @param -
* @retval-
******************************************************************************/
void HAL_SPI_MspDeInit(SPI_HandleTypeDef* hspi)
{

	if (hspi->Instance == SPI1)
	{

		  /* Peripheral clock disable */
		__HAL_RCC_SPI1_CLK_ENABLE();
  
		/**SPI1 GPIO Configuration    
		PA5     ------> SPI1_SCK
		PA7     ------> SPI1_MOSI
		PB4     ------> SPI1_MISO 
		*/
		HAL_GPIO_DeInit(GPIOB, GPIO_PIN_5);
		HAL_GPIO_DeInit(GPIOA, GPIO_PIN_5 | GPIO_PIN_6);



	}

}
/*****************************************************************************
* @brief -
* @param -
* @retval-
******************************************************************************/
void SPI_FLASH_Init(void)
{
//  SPI_InitTypeDef  SPI_InitStructure;

	GPIO_InitTypeDef   GPIO_InitStructure;

	__GPIOI_CLK_ENABLE();

	GPIO_InitStructure.Pin = GPIO_PIN_0 |  GPIO_PIN_5 | GPIO_PIN_4;
	GPIO_InitStructure.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStructure.Pull = GPIO_PULLUP;
	GPIO_InitStructure.Speed = GPIO_SPEED_FREQ_MEDIUM;
	HAL_GPIO_Init(GPIOI, &GPIO_InitStructure); 


	HAL_GPIO_WritePin(GPIOI, GPIO_PIN_0,GPIO_PIN_SET);

	HAL_GPIO_WritePin(GPIOI,GPIO_PIN_5,GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOI,GPIO_PIN_4,GPIO_PIN_SET);



	SpiMemoryHandle.Instance = SPI2;
	SpiMemoryHandle.Init.Mode = SPI_MODE_MASTER;
	SpiMemoryHandle.Init.Direction = SPI_DIRECTION_2LINES;
	SpiMemoryHandle.Init.DataSize = SPI_DATASIZE_8BIT;
	SpiMemoryHandle.Init.CLKPolarity = SPI_POLARITY_LOW;
	SpiMemoryHandle.Init.CLKPhase = SPI_PHASE_1EDGE;
	SpiMemoryHandle.Init.NSS = SPI_NSS_SOFT;
	SpiMemoryHandle.Init.BaudRatePrescaler = SPI_BAUDRATEPRESCALER_2;
	SpiMemoryHandle.Init.FirstBit = SPI_FIRSTBIT_MSB;
	SpiMemoryHandle.Init.TIMode = SPI_TIMODE_DISABLE;
	SpiMemoryHandle.Init.CRCCalculation = SPI_CRCCALCULATION_DISABLE;
	SpiMemoryHandle.Init.CRCPolynomial = 10;

	if (HAL_SPI_Init(&SpiMemoryHandle) != HAL_OK)
	{
		Error_Handler();
	}


	SPI_FLASH_GlobalBlockProtec();
	
}

/*****************************************************************************
* @brief -
* @param -
* @retval-
******************************************************************************/
void SPI_FLASH_SectorErase(uint32_t SectorAddr)
{
	
	uint8_t tx_spi_buf[100];
	uint8_t rx_spi_buf[100];


	SPI_FLASH_WriteEnable();

	SPI_FLASH_CS_LOW();

	tx_spi_buf[0] = SE;
	HAL_SPI_TransmitReceive(&SpiMemoryHandle,tx_spi_buf,rx_spi_buf,1,1);

	tx_spi_buf[0] = (SectorAddr & 0xFFFFFF) >> 16;
	HAL_SPI_TransmitReceive(&SpiMemoryHandle,tx_spi_buf,rx_spi_buf,1,1);
	tx_spi_buf[0] = (SectorAddr & 0xFFFF) >> 8;
	HAL_SPI_TransmitReceive(&SpiMemoryHandle,tx_spi_buf,rx_spi_buf,1,1);
	tx_spi_buf[0] = SectorAddr & 0xFF;
	HAL_SPI_TransmitReceive(&SpiMemoryHandle,tx_spi_buf,rx_spi_buf,1,1);


	SPI_FLASH_CS_HIGH();

	SPI_FLASH_WaitForWriteEnd();
}


/*****************************************************************************
* @brief -
* @param -
* @retval-
******************************************************************************/
void SPI_Chip_Erase(void)
{
	uint8_t tx_spi_buf[100];
	uint8_t rx_spi_buf[100];

	/* Send write enable instruction */
	SPI_FLASH_WriteEnable();

	SPI_FLASH_CS_LOW();

	
	tx_spi_buf[0] = CE;
	HAL_SPI_TransmitReceive(&SpiMemoryHandle,tx_spi_buf,rx_spi_buf,1,1);

	SPI_FLASH_CS_HIGH();
    
	//SPI_FLASH_WriteDisable();

	SPI_FLASH_WaitForWriteEnd();
}

/*****************************************************************************
* @brief -
* @param -
* @retval-
******************************************************************************/
void SPI_FLASH_BulkErase(void)
{
	uint8_t tx_spi_buf[100];
	uint8_t rx_spi_buf[100];

	/* Send write enable instruction */
	SPI_FLASH_WriteEnable();

	SPI_FLASH_CS_LOW();

	
	tx_spi_buf[0] = BE;
	HAL_SPI_TransmitReceive(&SpiMemoryHandle, tx_spi_buf, rx_spi_buf, 1, 1);

	SPI_FLASH_CS_HIGH();
    
	//SPI_FLASH_WriteDisable();

	SPI_FLASH_WaitForWriteEnd();
	
}

/*****************************************************************************
* @brief -
* @param -
* @retval-
******************************************************************************/
void SPI_FLASH_PageWrite(uint8_t* pBuffer, uint32_t WriteAddr, uint16_t NumByteToWrite)
{
    uint8_t Cnt = 0;
    uint8_t tx_spi_buf[100];
    uint8_t rx_spi_buf[100];

    SPI_FLASH_WriteEnable();

    SPI_FLASH_CS_LOW();


    tx_spi_buf[0] = WRITE;

    HAL_SPI_TransmitReceive(&SpiMemoryHandle,tx_spi_buf,rx_spi_buf,1,1);

    tx_spi_buf[0] = (WriteAddr & 0xFFFFFF) >> 16;
    HAL_SPI_TransmitReceive(&SpiMemoryHandle,tx_spi_buf,rx_spi_buf,1,1);

    tx_spi_buf[0] = (WriteAddr& 0xFFFF) >> 8;
    HAL_SPI_TransmitReceive(&SpiMemoryHandle,tx_spi_buf,rx_spi_buf,1,1);

    tx_spi_buf[0] = WriteAddr & 0xFF;
    HAL_SPI_TransmitReceive(&SpiMemoryHandle,tx_spi_buf,rx_spi_buf,1,1);



    while (NumByteToWrite--)
    {
        HAL_SPI_TransmitReceive(&SpiMemoryHandle,&pBuffer[Cnt],rx_spi_buf,1,1);

        Cnt++;
    }


    SPI_FLASH_CS_HIGH();

    SPI_FLASH_WaitForWriteEnd();

}

/*****************************************************************************
* @brief -
* @param -
* @retval-
******************************************************************************/
void SPI_FLASH_BufferWrite(uint8_t* pBuffer, uint32_t WriteAddr, uint16_t NumByteToWrite)
{
    uint8_t NumOfPage = 0, NumOfSingle = 0, Addr = 0, count = 0, temp = 0;

    Addr = WriteAddr % SPI_FLASH_PageSize;
    count = SPI_FLASH_PageSize - Addr;
    NumOfPage =  NumByteToWrite / SPI_FLASH_PageSize;
    NumOfSingle = NumByteToWrite % SPI_FLASH_PageSize;

    if (Addr == 0) /* WriteAddr is SPI_FLASH_PageSize aligned  */
    {
        if (NumOfPage == 0) /* NumByteToWrite < SPI_FLASH_PageSize */
        {
            SPI_FLASH_PageWrite(pBuffer, WriteAddr, NumByteToWrite);
        }
        else /* NumByteToWrite > SPI_FLASH_PageSize */
        {
            while (NumOfPage--)
            {
                SPI_FLASH_PageWrite(pBuffer, WriteAddr, SPI_FLASH_PageSize);
                WriteAddr +=  SPI_FLASH_PageSize;
                pBuffer += SPI_FLASH_PageSize;
            }

            SPI_FLASH_PageWrite(pBuffer, WriteAddr, NumOfSingle);
        }
    }
    else /* WriteAddr is not SPI_FLASH_PageSize aligned  */
    {
        if (NumOfPage == 0) /* NumByteToWrite < SPI_FLASH_PageSize */
        {
            if (NumOfSingle > count) /* (NumByteToWrite + WriteAddr) > SPI_FLASH_PageSize */
            {
                temp = NumOfSingle - count;

                SPI_FLASH_PageWrite(pBuffer, WriteAddr, count);
                WriteAddr +=  count;
                pBuffer += count;

                SPI_FLASH_PageWrite(pBuffer, WriteAddr, temp);
            }
            else
            {
                SPI_FLASH_PageWrite(pBuffer, WriteAddr, NumByteToWrite);
            }
        }
        else /* NumByteToWrite > SPI_FLASH_PageSize */
        {
            NumByteToWrite -= count;
            NumOfPage =  NumByteToWrite / SPI_FLASH_PageSize;
            NumOfSingle = NumByteToWrite % SPI_FLASH_PageSize;

            SPI_FLASH_PageWrite(pBuffer, WriteAddr, count);
            WriteAddr +=  count;
            pBuffer += count;

            while (NumOfPage--)
            {
                SPI_FLASH_PageWrite(pBuffer, WriteAddr, SPI_FLASH_PageSize);
                WriteAddr +=  SPI_FLASH_PageSize;
                pBuffer += SPI_FLASH_PageSize;
            }

            if (NumOfSingle != 0)
            {
                SPI_FLASH_PageWrite(pBuffer, WriteAddr, NumOfSingle);
            }
        }
    }
}

/*****************************************************************************
* @brief -
* @param -
* @retval-
******************************************************************************/
void SPI_FLASH_BufferRead(uint8_t* pBuffer, uint32_t ReadAddr, uint16_t NumByteToRead)
{
	uint8_t i;
	uint8_t tx_spi_buf[384];
	uint8_t rx_spi_buf[384];

	SPI_FLASH_WriteEnable();

	SPI_FLASH_CS_LOW();

	tx_spi_buf[0] = HS_READ; // HighSpeed_Read_Cont COMM
	HAL_SPI_TransmitReceive(&SpiMemoryHandle,tx_spi_buf,rx_spi_buf,1,1);

	tx_spi_buf[0] = (ReadAddr & 0xFFFFFF) >> 16;
	HAL_SPI_TransmitReceive(&SpiMemoryHandle,tx_spi_buf,rx_spi_buf,1,1);

	tx_spi_buf[0] = (ReadAddr& 0xFFFF) >> 8;
	HAL_SPI_TransmitReceive(&SpiMemoryHandle,tx_spi_buf,rx_spi_buf,1,1);

	tx_spi_buf[0] = ReadAddr & 0xFF;
	HAL_SPI_TransmitReceive(&SpiMemoryHandle,tx_spi_buf,rx_spi_buf,1,1);




	tx_spi_buf[0] = Dummy_Byte;
	HAL_SPI_TransmitReceive(&SpiMemoryHandle,tx_spi_buf,rx_spi_buf,1,2);

	for(i = 0;i < NumByteToRead;i++)
	{
		tx_spi_buf[0] = Dummy_Byte;
		HAL_SPI_TransmitReceive(&SpiMemoryHandle,tx_spi_buf,rx_spi_buf,1,2);
		*pBuffer = rx_spi_buf[0];
		pBuffer++;
	}

	SPI_FLASH_CS_HIGH();
	  
}

/*****************************************************************************
* @brief -
* @param -
* @retval-
******************************************************************************/
uint32_t SPI_FLASH_ReadID(void)
{
	uint32_t Temp = 0, Temp0 = 0, Temp1 = 0, Temp2 = 0;

	uint8_t tx_spi_buf[100];
	uint8_t rx_spi_buf[100];


	SPI_FLASH_CS_LOW();

	tx_spi_buf[0] = RDID;
	HAL_SPI_TransmitReceive(&SpiMemoryHandle,tx_spi_buf,rx_spi_buf,1,1);

	tx_spi_buf[0] = Dummy_Byte;
	HAL_SPI_TransmitReceive(&SpiMemoryHandle,tx_spi_buf,rx_spi_buf,1,1);
	Temp0 = rx_spi_buf[0];

	tx_spi_buf[0] = Dummy_Byte;
	HAL_SPI_TransmitReceive(&SpiMemoryHandle,tx_spi_buf,rx_spi_buf,1,1);
	Temp1 = rx_spi_buf[0];

	
	
	tx_spi_buf[0] = Dummy_Byte;
	HAL_SPI_TransmitReceive(&SpiMemoryHandle,tx_spi_buf,rx_spi_buf,1,1);
	Temp2 = rx_spi_buf[0];


	SPI_FLASH_CS_HIGH();


	Temp = (Temp0 << 16) | (Temp1 << 8) | Temp2;

	return Temp;
}

/*****************************************************************************
* @brief -
* @param -
* @retval-
******************************************************************************/
void SPI_FLASH_StartReadSequence(uint32_t ReadAddr)
{

	uint8_t tx_spi_buf[100];
	uint8_t rx_spi_buf[100];


	SPI_FLASH_WriteEnable();

	SPI_FLASH_CS_LOW();

	tx_spi_buf[0] = READ;
	HAL_SPI_TransmitReceive(&SpiMemoryHandle, tx_spi_buf, rx_spi_buf, 1, 1);

	tx_spi_buf[0] = (ReadAddr & 0xFFFFFF) >> 16;
	HAL_SPI_TransmitReceive(&SpiMemoryHandle, tx_spi_buf, rx_spi_buf, 1, 1);
	tx_spi_buf[0] = (ReadAddr & 0xFFFF) >> 8;
	HAL_SPI_TransmitReceive(&SpiMemoryHandle, tx_spi_buf, rx_spi_buf, 1, 1);
	tx_spi_buf[0] = ReadAddr & 0xFF;
	HAL_SPI_TransmitReceive(&SpiMemoryHandle, tx_spi_buf, rx_spi_buf, 1, 1);


	SPI_FLASH_CS_HIGH();

	SPI_FLASH_WaitForWriteEnd();
	

}

/*****************************************************************************
* @brief -
* @param -
* @retval-
******************************************************************************/
uint8_t SPI_FLASH_ReadByte(void)
{
    return 0;
//  return (SPI_FLASH_SendByte(Dummy_Byte));
}

/*****************************************************************************
* @brief -
* @param -
* @retval-
******************************************************************************/
uint8_t SPI_FLASH_SendByte(uint8_t byte)
{
//  /* Loop while DR register in not emplty */
//  while (SPI_I2S_GetFlagStatus(SPI2, SPI_I2S_FLAG_TXE) == RESET);


//  /* Send byte through the SPI1 peripheral */
//  SPI_I2S_SendData(SPI2, byte);
//	//HAL_SPI_Transmit_IT(&SpiMemoryHandle,&byte,1);

//  /* Wait to receive a byte */
//  while (SPI_I2S_GetFlagStatus(SPI2, SPI_I2S_FLAG_RXNE) == RESET);

//  /* Return the byte read from the SPI bus */
//  return SPI_I2S_ReceiveData(SPI2);
    
    return 0;
}

/*****************************************************************************
* @brief -
* @param -
* @retval-
******************************************************************************/
uint16_t SPI_FLASH_SendHalfWord(uint16_t HalfWord)
{
//  /* Loop while DR register in not emplty */
//  while (SPI_I2S_GetFlagStatus(SPI2, SPI_I2S_FLAG_TXE) == RESET);

//  /* Send Half Word through the SPI1 peripheral */
//  SPI_I2S_SendData(SPI2, HalfWord);

//  /* Wait to receive a Half Word */
//  while (SPI_I2S_GetFlagStatus(SPI2, SPI_I2S_FLAG_RXNE) == RESET);

//  /* Return the Half Word read from the SPI bus */
//  return SPI_I2S_ReceiveData(SPI2);
}

/*****************************************************************************
* @brief -
* @param -
* @retval-
******************************************************************************/
void SPI_FLASH_WriteEnable(void)
{
	uint8_t tx_spi_buf[100];
	uint8_t rx_spi_buf[100];

	SPI_FLASH_CS_LOW();

	tx_spi_buf[0] = WREN; // 0x06
	HAL_SPI_TransmitReceive(&SpiMemoryHandle,tx_spi_buf,rx_spi_buf,1,1);

	SPI_FLASH_CS_HIGH();
}

/*****************************************************************************
* @brief -
* @param -
* @retval-
******************************************************************************/
void SPI_FLASH_WriteDisable(void)
{
	
	uint8_t tx_spi_buf[100];
	uint8_t rx_spi_buf[100];
	/* Select the FLASH: Chip Select low */
	SPI_FLASH_CS_LOW();

	tx_spi_buf[0] = WRDI; // 
	HAL_SPI_TransmitReceive(&SpiMemoryHandle,tx_spi_buf,rx_spi_buf,1,1);

	SPI_FLASH_CS_HIGH();
	
	
}

/*****************************************************************************
* @brief -
* @param -
* @retval-
******************************************************************************/
void SPI_FLASH_WaitForWriteEnd(void)
{
    uint8_t FLASH_Status = 0;

    uint8_t tx_spi_buf[100];
    uint8_t rx_spi_buf[100];


    SPI_FLASH_CS_LOW();

    tx_spi_buf[0] = RDSR;
    HAL_SPI_TransmitReceive(&SpiMemoryHandle,tx_spi_buf,rx_spi_buf,1,1);


    do
    {
        tx_spi_buf[1] = Dummy_Byte;
        HAL_SPI_TransmitReceive(&SpiMemoryHandle,tx_spi_buf,rx_spi_buf,1,1);

        FLASH_Status = rx_spi_buf[0];

    }
    while ((FLASH_Status & WIP_Flag) == 0x80); /* Write in progress */

    SPI_FLASH_CS_HIGH();
	
}


/*****************************************************************************
* @brief -
* @param -
* @retval-
******************************************************************************/
void SPI_FLASH_GlobalBlockProtec(void)
{	
	
    uint8_t tx_spi_buf[100];
    uint8_t rx_spi_buf[100];

    SPI_FLASH_CS_LOW();

    tx_spi_buf[0] = ULBPR;
    HAL_SPI_TransmitReceive(&SpiMemoryHandle,tx_spi_buf,rx_spi_buf,1,1);

    SPI_FLASH_CS_HIGH();

}


/*****************************************************************************
* @brief -
* @param -
* @retval-
******************************************************************************/
void Error_Handler(void)
{
    /* Turn LED5 on */
    while(1)
    {
    }
}

/*****************************************************************************
* @brief -
* @param -
* @retval-
******************************************************************************/
void SPI_FLASH_Timer_1ms(void)
{
  
    mSPI_Time_Cnt++;
    //if(mSPI_Time_Cnt) mSPI_Time_Cnt--;


}



/**
  * @}
  */ 

/**
  * @}
  */ 

/******************* (C) COPYRIGHT 2009 STMicroelectronics *****END OF FILE****/
