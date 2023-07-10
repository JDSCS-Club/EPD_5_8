/*
    ******************************************************************************
    * @Company              : Woojin Industrial Systems Co., Ltd.
    * @Engineer             : D.S.JANG
    * @ModuleName           : spi_flash.h
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

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __SPI_FLASH_H
#define __SPI_FLASH_H


#ifdef __cplusplus
 extern "C" {
#endif
   
   
/* Includes ------------------------------------------------------------------*/


#include "stm32f4xx_hal.h"
//#include "stm32f4xx_spi.h"
/* Exported types ------------------------------------------------------------*/
/* Exported constants --------------------------------------------------------*/
/* Uncomment the line corresponding to the STMicroelectronics evaluation board
   used to run the example */

#define SPI_Buff_SIZE 100

#define  SPI_FLASH_WriteAddress     0x10000
#define  SPI_FLASH_ReadAddress      SPI_FLASH_WriteAddress
#define  SPI_FLASH_SectorToErase    SPI_FLASH_WriteAddress
#define  SST26VF032B_FLASH_ID        0x002642

extern uint8_t SPI_Tx_Buffer[SPI_Buff_SIZE];
extern __IO uint32_t SPI_FLASH_ID;


#define countof(a) (sizeof(a) / sizeof(*(a)))
#define  SPI_RX_BufferSize() countof(SPI_Tx_Buffer)-1

extern uint8_t SPI_Index;
extern uint8_t SPI_Rx_Buffer[SPI_Buff_SIZE];

extern SPI_HandleTypeDef SpiMemoryHandle;



#define SPI_FLASH_CS_LOW()        HAL_GPIO_WritePin(GPIOA,GPIO_PIN_,GPIO_PIN_RESET);
#define SPI_FLASH_CS_HIGH()        HAL_GPIO_WritePin(GPIOA,GPIO_PIN_0,GPIO_PIN_SET);


/* Exported functions ------------------------------------------------------- */
/*----- High layer function -----*/
void SPI_FLASH_Main(void);
void SPI_FLASH_Init(void);
void SPI_FLASH_SectorErase(uint32_t SectorAddr);
void SPI_Chip_Erase(void);
void SPI_FLASH_BulkErase(void);
void SPI_FLASH_PageWrite(uint8_t* pBuffer, uint32_t WriteAddr, uint16_t NumByteToWrite);
void SPI_FLASH_BufferWrite(uint8_t* pBuffer, uint32_t WriteAddr, uint16_t NumByteToWrite);
void SPI_FLASH_BufferRead(uint8_t* pBuffer, uint32_t ReadAddr, uint16_t NumByteToRead);
uint32_t SPI_FLASH_ReadID(void);
void SPI_FLASH_StartReadSequence(uint32_t ReadAddr);

///*----- Low layer function -----*/
uint8_t SPI_FLASH_ReadByte(void);
uint8_t SPI_FLASH_SendByte(uint8_t byte);
uint16_t SPI_FLASH_SendHalfWord(uint16_t HalfWord);
void SPI_FLASH_WriteEnable(void);
void SPI_FLASH_WriteDisable(void);
void SPI_FLASH_GlobalBlockProtec(void);
	
void SPI_FLASH_Timer_1ms(void);

void SPI_FLASH_WaitForWriteEnd(void);

void Error_Handler(void);


#ifdef __cplusplus
}
#endif

#endif /* __SPI_FLASH_H */

/******************* (C) COPYRIGHT 2009 STMicroelectronics *****END OF FILE****/
