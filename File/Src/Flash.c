
/*
    ******************************************************************************
    * @Company              : Woojin Industrial Systems Co., Ltd.
    * @Engineer             : D.S.JANG
    * @ModuleName           : Flash.c
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
#include "Flash.h"
#include "USRAT.h"



uint32_t FirstSector = 0, NbOfSectors = 0; 
uint32_t FlashAddressPosion = 0;
uint32_t SectorError = 0;

__IO uint8_t data8 = 0;

uint32_t mFLASH_TIM_Cnt = 1;

static FLASH_EraseInitTypeDef EraseInitStruct;


uint8_t mFlashMemoyBuf[110];

char mFlashMemoySaveBuf[100]="SW_UpData_BootLoad!!"; // 기록 시작 코드를 변경 # -> @ 18_0125

uint16_t mFlashSaveCnt = 7000;
uint8_t mFlashFlag = 0; //메모리 읽기를 하였는지 확인 하는 부분.


__IO uint32_t BootFlashReadAddress;


uint8_t dFlashReadBuf[20];

//*****************************************************************************
//* @brief -
//* @param -
//* @retval-
//******************************************************************************/

void Flash_Init(void)
{
	
	HAL_FLASH_Unlock();
	
	//HAL_FLASH_Lock();

	/* Get the 1st sector to erase */
	FirstSector = GetSector(FLASH_USER_START_ADDR);
	/* Get the number of sector to erase from 1st sector*/
	NbOfSectors = GetSector(FLASH_USER_END_ADDR) - FirstSector + 1;

	/* Fill EraseInit structure*/
	EraseInitStruct.TypeErase = FLASH_TYPEERASE_SECTORS;
	EraseInitStruct.VoltageRange = FLASH_VOLTAGE_RANGE_3;
	EraseInitStruct.Sector = FirstSector;
	EraseInitStruct.NbSectors = NbOfSectors;

}

//*****************************************************************************
//* @brief -
//* @param -
//* @retval-
//******************************************************************************/


void Flash_Main(void)
{
	if((mFLASH_TIM_Cnt == 7000))
	{
            //mFlashSaveCnt = 7000;
        mFLASH_TIM_Cnt++;
            
        
         BootFlashReadAddress = FLASH_USER_START_ADDR;
        
         FLASH_Read_Len(&BootFlashReadAddress,dFlashReadBuf,20);
         
         
          if (strncmp ((char*)(dFlashReadBuf), "SW_UpData_BootLoad!!", 20))// 같지 않다면
          {

                
                Flash_Write((uint8_t *)mFlashMemoySaveBuf,20);
                //MyPrintf_USART1("**Flash Memory Write  \n\r");
                
          }
          else
          {

                //MyPrintf_USART1("**Flash Memory OK \n\r");
          }

	}
	
}


//*****************************************************************************
//* @brief -
//* @param -
//* @retval-
//******************************************************************************/
void Flash_TIM(void)
{
	mFLASH_TIM_Cnt++;
	
	if(mFlashSaveCnt) {mFlashSaveCnt--;}
	
	
}

//*****************************************************************************
//* @brief -
//* @param -
//* @retval-
//******************************************************************************/
void Flash_Write(uint8_t *pData,uint8_t Len)
{
	int i;

	__HAL_FLASH_DATA_CACHE_DISABLE();
	__HAL_FLASH_INSTRUCTION_CACHE_DISABLE();

	__HAL_FLASH_DATA_CACHE_RESET();
	__HAL_FLASH_INSTRUCTION_CACHE_RESET();

	__HAL_FLASH_INSTRUCTION_CACHE_ENABLE();
	__HAL_FLASH_DATA_CACHE_ENABLE();
	
	
	//printf("%d - Flash Write-ST : %X  \n\r",mFLASH_TIM_Cnt,FlashAddressPosion);
	
	for(i = 0; i < Len ;i++)
	{
		if (HAL_FLASH_Program(FLASH_TYPEPROGRAM_BYTE, FlashAddressPosion, (uint64_t )pData[i]) == HAL_OK)
		{
			FlashAddressPosion = FlashAddressPosion + 1; //어드레스를 증가한다.
			
	
		}
		else
		{
			  Flash_Error_Handler();
		}
	}
	
	//MyPrintf(&pData[0],10,"Flash Write ADD : %X ",FlashAddressPosion);
	
	//printf("%d - Flash Write-END : %X  \n\r",mFLASH_TIM_Cnt,FlashAddressPosion);
	
	// 쓰기 동작후 메모리 
	if((FlashAddressPosion+100) >= FLASH_USER_END_ADDR)
	{
		Flash_Errase();
	}
		
}


//*****************************************************************************
//* @brief -
//* @param -
//* @retval-
//******************************************************************************/
void FLASH_Read_Len(__IO uint32_t* FlashAddress,uint8_t* Data ,uint16_t DataLength)
{
  uint32_t i=0;
  __IO uint8_t data8 = 0;
  
  for(i=0;i<DataLength;i++)
  {
    data8 = *(uint32_t*)*FlashAddress;
    Data[i] =(uint8_t) data8;
    
    *FlashAddress += 1;
  }
  
  
}



//*****************************************************************************
//* @brief -
//* @param -
//* @retval-
//******************************************************************************/
void Flash_Errase(void)
{
	 if(HAL_FLASHEx_Erase(&EraseInitStruct, &SectorError) != HAL_OK)
	  { 
		/* 
		  Error occurred while sector erase. 
		  User can add here some code to deal with this error. 
		  SectorError will contain the faulty sector and then to know the code error on this sector,
		  user can call function 'HAL_FLASH_GetError()'
		*/
		/*
		  FLASH_ErrorTypeDef errorcode = HAL_FLASH_GetError();
		*/
		Flash_Error_Handler();
	  }

}



//*****************************************************************************
//* @brief -
//* @param -
//* @retval-
//******************************************************************************/
void Flash_Read(uint8_t *pData)
{
	int i;
	FlashAddressPosion = FLASH_USER_START_ADDR;
	
	 data8 = *(__IO uint32_t*)FlashAddressPosion;

     
     
}


//*****************************************************************************
//* @brief -
//* @param -
//* @retval-
//******************************************************************************/
static uint32_t GetSector(uint32_t Address)
{
  uint32_t sector = 0;
  
  if((Address < ADDR_FLASH_SECTOR_1) && (Address >= ADDR_FLASH_SECTOR_0))
  {
    sector = FLASH_SECTOR_0;  
  }
  else if((Address < ADDR_FLASH_SECTOR_2) && (Address >= ADDR_FLASH_SECTOR_1))
  {
    sector = FLASH_SECTOR_1;  
  }
  else if((Address < ADDR_FLASH_SECTOR_3) && (Address >= ADDR_FLASH_SECTOR_2))
  {
    sector = FLASH_SECTOR_2;  
  }
  else if((Address < ADDR_FLASH_SECTOR_4) && (Address >= ADDR_FLASH_SECTOR_3))
  {
    sector = FLASH_SECTOR_3;  
  }
  else if((Address < ADDR_FLASH_SECTOR_5) && (Address >= ADDR_FLASH_SECTOR_4))
  {
    sector = FLASH_SECTOR_4;  
  }
  else if((Address < ADDR_FLASH_SECTOR_6) && (Address >= ADDR_FLASH_SECTOR_5))
  {
    sector = FLASH_SECTOR_5;  
  }
  else if((Address < ADDR_FLASH_SECTOR_7) && (Address >= ADDR_FLASH_SECTOR_6))
  {
    sector = FLASH_SECTOR_6;  
  }
  else if((Address < ADDR_FLASH_SECTOR_8) && (Address >= ADDR_FLASH_SECTOR_7))
  {
    sector = FLASH_SECTOR_7;  
  }
  else if((Address < ADDR_FLASH_SECTOR_9) && (Address >= ADDR_FLASH_SECTOR_8))
  {
    sector = FLASH_SECTOR_8;  
  }
  else if((Address < ADDR_FLASH_SECTOR_10) && (Address >= ADDR_FLASH_SECTOR_9))
  {
    sector = FLASH_SECTOR_9;  
  }
  else if((Address < ADDR_FLASH_SECTOR_11) && (Address >= ADDR_FLASH_SECTOR_10))
  {
    sector = FLASH_SECTOR_10;  
  }
  else /* (Address < FLASH_END_ADDR) && (Address >= ADDR_FLASH_SECTOR_11) */
  {
    sector = FLASH_SECTOR_11;
  }

  return sector;
}




//*****************************************************************************
//* @brief -
//* @param -
//* @retval-
//******************************************************************************/
static uint32_t GetSectorSize(uint32_t Sector)
{
  uint32_t sectorsize = 0x00;

  if((Sector == FLASH_SECTOR_0) || (Sector == FLASH_SECTOR_1) || (Sector == FLASH_SECTOR_2) || (Sector == FLASH_SECTOR_3))
  {
    sectorsize = 16 * 1024;
  }
  else if(Sector == FLASH_SECTOR_4)
  {
    sectorsize = 64 * 1024;
  }
  else
  {
    sectorsize = 128 * 1024;
  }  
  return sectorsize;
}


static void Flash_Error_Handler(void)
{
  /* Turn LED5 on */
  while(1)
  {
  }
}


