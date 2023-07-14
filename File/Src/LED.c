/*
    ******************************************************************************
    * @Company              : Woojin Industrial Systems Co., Ltd.
    * @Engineer             : D.S.JANG
    * @ModuleName           : LED.c
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

#include "main.h"
#include "stm32f4xx_hal.h"
#include "LED.h"
#include "Color_Code_256.h"
#include "SEPTA_IMAGE_1.h"

#include "spi_flash.h"



#define COLDEPTH 		3
#define BRIGHTNESS		100
#define ROWS 			16
#define COLUMNS 		64


uint32_t mLEDAddCntLine = 0;
uint32_t mLEDAddCnt = 0;


pFDI_SCREEN_BOKCK mFdi_Screen_Print;

char mStringBuf[15][40];

/*****************************************************************************
* @brief -
* @param -
* @retval-
******************************************************************************/


void LED_GPIO_Init(void)
{
    uint8_t *pVd = (uint8_t *)SRAM_USED_TO_STREAM_BUF;     //0x11ffff

	uint8_t *pVdDot = (uint8_t *)SRAM_USED_TO_SCREEN_OUT;
    
    uint8_t *pVerDisplay = (uint8_t *)SRAM_USER_TO_VER_OUT;
    
    
    
    
	GPIO_InitTypeDef   GPIO_InitStructure;

	 /*LDM0-R0 */
	__GPIOA_CLK_ENABLE();
	GPIO_InitStructure.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStructure.Pull = GPIO_PULLUP;
	GPIO_InitStructure.Pin = GPIO_PIN_6;
	GPIO_InitStructure.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
	HAL_GPIO_Init(GPIOA, &GPIO_InitStructure); 
	
	
	/*LDM0-B0 , LDM0-G0*/
	__GPIOB_CLK_ENABLE();
	GPIO_InitStructure.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStructure.Pull = GPIO_PULLUP;
	GPIO_InitStructure.Pin = GPIO_PIN_0 | GPIO_PIN_5;
	GPIO_InitStructure.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
	HAL_GPIO_Init(GPIOB, &GPIO_InitStructure);
	
	__GPIOC_CLK_ENABLE();
	GPIO_InitStructure.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStructure.Pull = GPIO_PULLUP;
	GPIO_InitStructure.Pin =  GPIO_PIN_6 | GPIO_PIN_7 | GPIO_PIN_8;
	GPIO_InitStructure.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
	HAL_GPIO_Init(GPIOC, &GPIO_InitStructure);
	
	
	__GPIOF_CLK_ENABLE();
	GPIO_InitStructure.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStructure.Pull = GPIO_PULLUP;
	GPIO_InitStructure.Pin = GPIO_PIN_4 | GPIO_PIN_5 | GPIO_PIN_6 | GPIO_PIN_7 | GPIO_PIN_8 | GPIO_PIN_9;
	GPIO_InitStructure.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
	HAL_GPIO_Init(GPIOF, &GPIO_InitStructure);
    


	memset(pVdDot, 0, 6144);
    memset(pVerDisplay,0,9216);
	memset(pVd, 0, (6144 * 6));
    
    
    
}

/*****************************************************************************
* @brief -GPIO_PIN_9  =  R0  0x200
*         GPIO_PIN_10 =  G0  0x400
*         GPIO_PIN_11 =  B0  0x800

*         GPIO_PIN_12 =  R1  0x1000
*         GPIO_PIN_13 =  G1  0x2000
*         GPIO_PIN_14 =  B1  0x4000

*         GPIO_PIN_15 =  A0 0x8000
*         GPIO_PIN_4  =  A1 0x10
*         GPIO_PIN_5  =  A2 0x40

*         GPIO_PIN_6 =  CLK 0x20
*         GPIO_PIN_7 =  LAT 0x80
*         GPIO_PIN_8 =  OE  0x100 
       G     B    R
       1     0    1  - 노랑.
       1     1    1  - 화이트.
       
 
* @param -
* @retval-
******************************************************************************/


void LED_init(void)
{


				
}



/*****************************************************************************
* @brief -
* @param -
* @retval-
        1) brightvalue : 화면 밝기 조절 변수.
           -> H : 50 / M : 100 / L : 150 으로 설정.

******************************************************************************/

    

uint8_t dTest_Print_Flag = 1;
uint8_t mSEPTA_Mark_Flag = 0;


void LED_SCREEN_PRINT(void)
{
	uint8_t rowcounter = 0;
	uint16_t colcounter = 0;
	int8_t pwmindex = 0;
	uint8_t delaybrightness = 100 - BRIGHTNESS;
    
    /***********************
     brightvalue : 화면 밝기 조절 변수.
     H : 50 / M : 100 / L : 150 으로 설정.
    ***********************/
	uint8_t brightvalue = 100;  //if needed to dim display even more
    
    uint8_t sColorCode = 0;
    uint16_t sColorCode_Cnt = 0;
    
    uint16_t sDelyTime = 0;
	
    uint8_t *pVd = (uint8_t *)SRAM_USED_TO_SCREEN_OUT; // 0x20011800 ; ; 

    
    if(dTest_Print_Flag)
    {
      dTest_Print_Flag = 0;

      
        if(mLed_Process_Flag.sPattern_Test_Flag)
        {
            mLed_Process_Flag.sPattern_Test_Flag = LED_Pattern_TEST();
            LED_Block_Screen_Buf();
        }
		else if (mLed_Process_Flag.sReClock_Start_Flage) //시간 설정 부분.
		{
            LED_FONT_POSITION(&mLed_Process_Flag.sRx_PII_Ascii_Buf[0]);
            
			LED_Block_Screen_Buf();
		}
        else if(mLed_Process_Flag.sScreen_ScanFlag)
        {

            
            mLed_Process_Flag.sScreen_ScanFlag = 0;

            LED_Block_Screen_Buf();
        }
        else if(LED_Imag_ScreenNormal_Cnt()) // 노말 버번 출력 기능.
        {
            LED_Block_Screen_Buf();
        }
    
    
        for (pwmindex = 7; pwmindex>=(7-(COLDEPTH-1)); pwmindex--)
        { 
          sColorCode_Cnt = 0;
            for (rowcounter=0 ; rowcounter<(16/2) ; rowcounter++) 
            {
                //GPIO_SetBits(OEPORT,OEPIN);
                HAL_GPIO_WritePin(GPIOF, GPIO_PIN_9, GPIO_PIN_SET);  // OE - High

                for (colcounter=0 ; colcounter<384 ; colcounter++) 
                {
                  
                    //상단 칼라 코드 값을 확인 한다.
                    sColorCode = pVd[sColorCode_Cnt];
  
                    HAL_GPIO_WritePin(GPIOF, GPIO_PIN_7, GPIO_PIN_RESET);  // CLK Low

                    
                    if (((m_ColorCode_256[sColorCode][0] >> pwmindex) & 0x01)==1) HAL_GPIO_WritePin(GPIOA,GPIO_PIN_6,GPIO_PIN_SET);// RED
                    else HAL_GPIO_WritePin(GPIOA,GPIO_PIN_6,GPIO_PIN_RESET);

                    if (((m_ColorCode_256[sColorCode][1] >> pwmindex) & 0x01)==1) HAL_GPIO_WritePin(GPIOB,GPIO_PIN_5,GPIO_PIN_SET);
                    else HAL_GPIO_WritePin(GPIOB,GPIO_PIN_5,GPIO_PIN_RESET);

                    if (((m_ColorCode_256[sColorCode][2] >> pwmindex) & 0x01)==1) HAL_GPIO_WritePin(GPIOB,GPIO_PIN_0,GPIO_PIN_SET);
                    else HAL_GPIO_WritePin(GPIOB,GPIO_PIN_0,GPIO_PIN_RESET);
                    
                    //하단 칼라 코드 값을 확인 한다.   
                    //screen width siae 96 * 16 (line) = 1536
                     sColorCode = pVd[3072 + sColorCode_Cnt];
                     
                     if (((m_ColorCode_256[sColorCode][0] >> pwmindex) & 0x01)==1) HAL_GPIO_WritePin(GPIOC,GPIO_PIN_6,GPIO_PIN_SET);
                    else HAL_GPIO_WritePin(GPIOC,GPIO_PIN_6,GPIO_PIN_RESET);

                    if (((m_ColorCode_256[sColorCode][1] >> pwmindex) & 0x01)==1) HAL_GPIO_WritePin(GPIOC,GPIO_PIN_7,GPIO_PIN_SET);
                    else HAL_GPIO_WritePin(GPIOC,GPIO_PIN_7,GPIO_PIN_RESET);

                    if (((m_ColorCode_256[sColorCode][2] >> pwmindex) & 0x01)==1) HAL_GPIO_WritePin(GPIOC,GPIO_PIN_8,GPIO_PIN_SET);
                    else HAL_GPIO_WritePin(GPIOC,GPIO_PIN_8,GPIO_PIN_RESET);

                    
                     HAL_GPIO_WritePin(GPIOF, GPIO_PIN_7, GPIO_PIN_SET);  // CLK High
                     
                    if (colcounter>brightvalue)  HAL_GPIO_WritePin(GPIOF, GPIO_PIN_9, GPIO_PIN_RESET);  // OE - High
                    
                    sColorCode_Cnt++;
                }
                
                
                
                 HAL_GPIO_WritePin(GPIOF, GPIO_PIN_9, GPIO_PIN_SET);  // OE - High
                
                sDelyTime = 100;
                while(sDelyTime--);
                //HAL_Delay(1);
                
                HAL_GPIO_WritePin(GPIOF,GPIO_PIN_8,GPIO_PIN_SET); // LAT - High
                
                
                HAL_GPIO_WritePin(GPIOF, GPIO_PIN_4, ((rowcounter & 0x01) ? GPIO_PIN_SET : GPIO_PIN_RESET)); //A0
                HAL_GPIO_WritePin(GPIOF, GPIO_PIN_5, ((rowcounter & 0x02) ? GPIO_PIN_SET : GPIO_PIN_RESET));  //A1
                HAL_GPIO_WritePin(GPIOF, GPIO_PIN_6, ((rowcounter & 0x04) ? GPIO_PIN_SET : GPIO_PIN_RESET));  //A2      
        

                
                HAL_GPIO_WritePin(GPIOF,GPIO_PIN_8,GPIO_PIN_RESET); // LAT - Low
                
                sDelyTime = 100;
                while(sDelyTime--);
                //HAL_Delay(delaybrightness);
                //HAL_Delay(1);

                HAL_GPIO_WritePin(GPIOF, GPIO_PIN_9, GPIO_PIN_RESET);  // OE - Low
                
                
                sDelyTime = (192*(pwmindex-(8-COLDEPTH)+1)*(pwmindex-(8-COLDEPTH)+1)-59)+150;
                
                while(sDelyTime--);
               
                //HAL_Delay((8-COLDEPTH)+1);
                //HAL_Delay(59*(pwmindex-(8-COLDEPTH)+1)*(pwmindex-(8-COLDEPTH)+1)-59);
                
                
                
                

                
            }
        }
        
        dTest_Print_Flag = 1;
    }
    
    HAL_GPIO_WritePin(GPIOF, GPIO_PIN_9, GPIO_PIN_SET);  // OE - High
	
	
	
}

/*****************************************************************************
* @brief -
* @param -
* @retval-

	memset(pVd,0,6144);
	memset(pVdDot,0,(6144*6));
******************************************************************************/
uint8_t s_LED_FONT_MAP[32]; // 메모리 고정 성을 확보 하기 위해, 전역 변수로 변경.

void LED_FONT_POSITION(uint8_t *nAscii_Len_Buf)
{
	uint32_t sAsciiCnt = 0;
	uint32_t sDelayCnt = 0;

	//uint8_t *pVd = (uint8_t *)SRAM_USED_TO_STREAM_BUF;     //0x11ffff
	//uint8_t *pVd_Scroll = (uint8_t *)SRAM_USED_TO_STREAM_SCROLL_BUF;
	//uint8_t *pVdDot = (uint8_t *)SRAM_USED_TO_SCREEN_OUT;



	uint8_t *spData;
	uint32_t spData_Ko = 0;


	//memset(pVd, 0, 6144);
	//memset(pVdDot, 0, (6144 * 6));

	mLed_Process_Flag.sAscii_Char_RxLen = 0;


	for (sAsciiCnt = 0; sAsciiCnt < 50; sAsciiCnt++)
	{
		//spData_Ko = 0;

		//for(sDelayCnt = 0; sDelayCnt < 1000; sDelayCnt++){}//SPI 데이타 읽어 오는 속도를 충분이 보장해 주기 위해 딜레이 기능 카운터 추가.

		if (nAscii_Len_Buf[sAsciiCnt])
		{
			if (nAscii_Len_Buf[sAsciiCnt] == 0x1B)
			{
				sAsciiCnt++;
				mLed_Process_Flag.sAscii_Color_Code = nAscii_Len_Buf[sAsciiCnt];

			}
			else
			{


				if ((nAscii_Len_Buf[sAsciiCnt] & 0xFF) < 0xA1) // 영 숫자 
				{
					if ((nAscii_Len_Buf[sAsciiCnt] & 0xFF)) // 0 이 아니라면. 실행 한다.
					{

						spData_Ko = (nAscii_Len_Buf[sAsciiCnt] - 0x20) * 16;


						SPI_FLASH_BufferRead(s_LED_FONT_MAP, spData_Ko, 16); /* Read data from SPI FLASH memory */


						spData = (uint8_t *)&s_LED_FONT_MAP[0];

						LED_Imag_ScreenUp(spData);

                        if(mLed_Process_Flag.sReClock_Start_Flage)
                        {
                            mLed_Process_Flag.sAscii_Char_RxLen += 16;
                        }
                        else
                        {
                            mLed_Process_Flag.sAscii_Char_RxLen += 8;
                        }
					}

				}
				else
				{

					if (((nAscii_Len_Buf[sAsciiCnt] & 0xFF) >= 0xA1) && ((nAscii_Len_Buf[sAsciiCnt] & 0xFF) < 0xB0))
					{
						spData_Ko = (nAscii_Len_Buf[sAsciiCnt++] - 0xA1) * 3008;

						spData_Ko = spData_Ko + ((nAscii_Len_Buf[sAsciiCnt] - 0xA1) * 32) + 3008;


					}
					else if (((nAscii_Len_Buf[sAsciiCnt] & 0xFF) >= 0xB0) && ((nAscii_Len_Buf[sAsciiCnt] & 0xFF) < 0xCA))
					{
						spData_Ko = (nAscii_Len_Buf[sAsciiCnt++] - 0xB0) * 3008;

						spData_Ko = spData_Ko + ((nAscii_Len_Buf[sAsciiCnt] - 0xA1) * 32) + 39104;

					}
					else if (((nAscii_Len_Buf[sAsciiCnt] & 0xFF) >= 0xCA))
					{
						spData_Ko = (nAscii_Len_Buf[sAsciiCnt++] - 0xCA) * 3008;

						spData_Ko = spData_Ko + ((nAscii_Len_Buf[sAsciiCnt] - 0xA1) * 32) + 114304;

					}

					//spData = (uint8_t *)&m_LED_FONT_MAP[spData_Ko]; // 한글 폰트 버퍼에서 위치를 전달 한다.

					SPI_FLASH_BufferRead(s_LED_FONT_MAP, spData_Ko, 32); /* Read data from SPI FLASH memory */


					spData = (uint8_t *)&s_LED_FONT_MAP[0];


					LED_Imag_ScreenUp_16Font(spData);

					mLed_Process_Flag.sAscii_Char_RxLen += 16;

				}



			}

		}
		else
		{
			if (nAscii_Len_Buf[sAsciiCnt + 1]) // 2바이트 연속 "0" 이면, 브레이크 처리 한다.
			{
				//break;
			}
		}

	}

}


/*****************************************************************************
* @brief -
* @param -
* @retval-
******************************************************************************/

void LED_Imag_ScreenUp(uint8_t *Imag)
{
    
    int i,j;
	uint32_t Font_16=0;
	uint32_t Lint_sort=0;
	uint8_t *pVd = (uint8_t *)SRAM_USER_TO_VER_OUT;     //0x11ffff
	

    
	for(i=0;i<16;i++)
	{
		
        if(mLed_Process_Flag.sReClock_Start_Flage)
        {
            
            Lint_sort = (192*(i*2)) + mLed_Process_Flag.sAscii_Char_RxLen;
            
            for(j=7;j>=0;j--)
            {
                pVd[(Lint_sort++)]=(((Imag[(i)]&0xff)>>j)&0x01) ? (mLed_Process_Flag.sAscii_Color_Code) : 0 ;
                pVd[(Lint_sort++)]=(((Imag[(i)]&0xff)>>j)&0x01) ? (mLed_Process_Flag.sAscii_Color_Code) : 0 ;
                
                

            }
            
            Lint_sort = (192*(i*2)) + mLed_Process_Flag.sAscii_Char_RxLen;
            
             for(j=7;j>=0;j--)
            {
                pVd[192+ (Lint_sort++)]=(((Imag[(i)]&0xff)>>j)&0x01) ? (mLed_Process_Flag.sAscii_Color_Code) : 0 ;
                pVd[192+ (Lint_sort++)]=(((Imag[(i)]&0xff)>>j)&0x01) ? (mLed_Process_Flag.sAscii_Color_Code) : 0 ;

            }
            
            
        }
        else
        {
            if(mLed_Process_Flag.sAscii_Char_RxLen < 192)
            {
                Lint_sort = (192*i) + mLed_Process_Flag.sAscii_Char_RxLen;
            }
            else Lint_sort = (192*i) + mLed_Process_Flag.sAscii_Char_RxLen + 3072;
            

            
            for(j=7;j>=0;j--)
            {
                pVd[(Lint_sort++)]=(((Imag[(i)]&0xff)>>j)&0x01) ? (mLed_Process_Flag.sAscii_Color_Code) : 0 ;

            }
        }
		
	}
      
}

/*****************************************************************************
* @brief -
* @param -
* @retval-
******************************************************************************/

void LED_Imag_ScreenDown(uint8_t *Imag)
{
     int i,j;
	uint32_t Font_16=0;
	uint32_t Lint_sort=0;
	uint8_t *pVd = (uint8_t *)(SRAM_USER_TO_VER_OUT+3072);     //0x11ffff
	

    
	for(i=0;i<16;i++)
	{
		

		Lint_sort = (192*i) + mLed_Process_Flag.sAscii_Char_RxLen;
		
		for(j=7;j>=0;j--)
		{
			pVd[(Lint_sort++)]=(((Imag[(i)]&0xff)>>j)&0x01) ? (mLed_Process_Flag.sAscii_Color_Code) : 0 ;

		}
		
	}


}


/*****************************************************************************
* @brief -
* @param -
* @retval-
******************************************************************************/
void LED_Imag_ScreenUp_16Font(uint8_t *Imag)
{
    int i,j;

	uint32_t Lint_sort=0;
	uint8_t *pVd = (uint8_t *)SRAM_USER_TO_VER_OUT;     //0x11ffff
	
    
	for(i=0;i<16;i++)
	{
		

		if(mLed_Process_Flag.sAscii_Char_RxLen < 192)
        {
            Lint_sort = (192*i) + mLed_Process_Flag.sAscii_Char_RxLen;
        }
        else Lint_sort = (192*i) + mLed_Process_Flag.sAscii_Char_RxLen + 3072;
        
		
		for(j=7;j>=0;j--)
		{
			pVd[(Lint_sort++)]=(((Imag[(i*2)]&0xFFFF)>>j)&0x01) ? (mLed_Process_Flag.sAscii_Color_Code) : 0 ;

		}
        
        for(j=7;j>=0;j--)
		{
			pVd[(Lint_sort++)]=(((Imag[(i*2+1)]&0xFFFF)>>j)&0x01) ? (mLed_Process_Flag.sAscii_Color_Code) : 0 ;

		}
		
	}
    
    
}

/*****************************************************************************
* @brief - 버전 정보를 현시하기 위해서 버퍼 내용을 정리 하는 부분.
* @param -
* @retval-
******************************************************************************/
uint8_t LED_Imag_ScreenNormal_Cnt(void)
{
     static uint32_t mNormal_MoveCnt = 0;
     
     
    uint16_t sDisyPlay_Time = 1500; //30초 기준.
    mNormal_MoveCnt++;
    
    if(!mLed_Process_Flag.sEth_Rx_Flag)
    {
    
        if(mNormal_MoveCnt < sDisyPlay_Time)
        {
          
            mLed_Process_Flag.sAscii_NorMal_Flag = 1;
            if(mNormal_MoveCnt == 1)
            {
                //memset(&mLCDPrintBuf[0][0],0x20,40);  
                //memset(&mLCDPrintBuf[1][0],0x20,40);  
                
                memset(&mLed_Process_Flag.sRx_PII_Ascii_Buf[0],0x20,50);  
                
                sprintf((char *)&mLed_Process_Flag.sRx_PII_Ascii_Buf[0],"%s", completeVersion);
                sprintf((char *)&mLed_Process_Flag.sRx_PII_Ascii_Buf[25],"%s", completeVersionBuild);

                
                LED_FONT_POSITION(&mLed_Process_Flag.sRx_PII_Ascii_Buf[0]);
               
            }
            
         
            return 1;
        }
        else
        {
            if(mNormal_MoveCnt == sDisyPlay_Time)
            {
                
                mLed_Process_Flag.sAscii_NorMal_Flag = 0;
                
                LED_Block_Screen_Buf();
                
            }
            return 0;
        }
    }
    else
    {
        mLed_Process_Flag.sAscii_NorMal_Flag = 0;
        return 0;
    }
    

    
}
/*****************************************************************************
* @brief - LED 모둘 하단에 스크롤 기능을 구현.
* @param -
* @retval-
******************************************************************************/


void LED_Imag_ScreenScroll(void)
{
    

}

/*****************************************************************************
* @brief -  화면 출력 방법
* @param -
* @retval-

         |<--------------------96-------------------------------->|
__       |<------32-------->|<------32-------->|<------32-------->|
|      1 |2)----------------64
|      2 |   4)-------------128
|      3 |      6)----------192
 U     4 |         8)-------256
       5 |          10)-----320
       6 |            12)   384
 P     7 |              14) 448
       8 |                16)512                               --->1536
|      9 |1)line_Print_count-32
|     10 |    3)-------------96 
|     11 |       5)----------160
|     12 |          7)-------224
|     13 |            9)-----288 
|     14 |             11)   352
|     15 |               13)-416
|__   16 |                 15)480
        
        ~
        ~


******************************************************************************/
void LED_Block_Screen_Buf(void)
{
	int i,j,sLINE,s12_Block,sDot;
	uint32_t sDotPrintCnt = 0;
	uint32_t sDotPrintCnt_Led = 0;
	uint32_t Font_16=0;
	uint32_t Lint_sort=0;
    
    
    uint64_t sBlk_Blink_Time;
     
	
	
	uint32_t sDotLineCnt = 0;
	
	
    
    if(mLed_Process_Flag.sPattern_Test_Flag)
    {
        mFdi_Screen_Print =(FDI_SCREEN_BOKCK *) (SRAM_USER_TO_VER_OUT);
    }
    else if (mLed_Process_Flag.sReClock_Start_Flage) //시간 설정 부분.
    {
        mFdi_Screen_Print =(FDI_SCREEN_BOKCK *) (SRAM_USER_TO_VER_OUT);
    }
    else if(mLed_Process_Flag.sEth_Rx_Flag) // 스트림 메모리 확인 부분.
    {
        
        sBlk_Blink_Time = (mLed_Process_Flag.sScreen_Page_Cnt) * 6144;
        
        mFdi_Screen_Print =(FDI_SCREEN_BOKCK *) (SRAM_USED_TO_STREAM_BUF + sBlk_Blink_Time);
    }
    else if(mLed_Process_Flag.sAscii_NorMal_Flag)
    {
         mFdi_Screen_Print =(FDI_SCREEN_BOKCK *) (SRAM_USER_TO_VER_OUT);
    }
    else
    {   // 통신 수신 데이타가 없다면,  기본 이미지  표출.
        mFdi_Screen_Print =(FDI_SCREEN_BOKCK *)m_336_MARK_FTNDD;
    }
	
	uint8_t *pVd = (uint8_t *)SRAM_USED_TO_SCREEN_OUT; // 0x2001ABFF ; 


	//sDotPrintCnt = nLine*192; // 화면 가로 사이즈(96*2)
        
    //LED_Imag_ScreenScroll();
    
    
    for(Lint_sort = 0;Lint_sort<8;Lint_sort++)
    {
    
         sDotPrintCnt = Lint_sort*384; // 화면 가로 사이즈(96*2)
         
        for(s12_Block=0; s12_Block<12;s12_Block++)
        {
                

            for(sDot = 0 ; sDot < 16 ; sDot++)
            {

                pVd[sDotPrintCnt] = mFdi_Screen_Print->nLine[Lint_sort+8].s16_Dot[s12_Block][sDot];


                pVd[3072 + sDotPrintCnt] = mFdi_Screen_Print->nLine[Lint_sort+24].s16_Dot[s12_Block][sDot];
	            

                sDotPrintCnt++;

            }

            for(sDot = 0 ; sDot < 16 ; sDot++)
            {

                pVd[sDotPrintCnt] = mFdi_Screen_Print->nLine[Lint_sort].s16_Dot[s12_Block][sDot];

                pVd[3072 + sDotPrintCnt] = mFdi_Screen_Print->nLine[Lint_sort+16].s16_Dot[s12_Block][sDot];

                sDotPrintCnt++;

            }
            
        }
    }
	
}


/*****************************************************************************
* @brief - 통신으로 패턴 테스트 명령을 받으면, 약 1분(3000) 패턴을 최 우선으로 표출 한다.
* @param -
* @retval-
******************************************************************************/
uint8_t LED_Pattern_TEST(void)
{

    static uint32_t sPattern_Cnt = 0;
    
    int i,j;
	uint32_t Font_16=0;
    
	uint32_t Lint_sort=0;
    
	uint8_t *pVd_Up = (uint8_t *)SRAM_USER_TO_VER_OUT; 
    uint8_t *pVd_Down = (uint8_t *)(SRAM_USER_TO_VER_OUT+3072);     //0x11ffff
    
    uint32_t sFontLen = 0;
    
    
    if(sPattern_Cnt == 9999) // 한번 실행 완료 된 것이라면,  그리고,  통신으로 동일 명령을  수신 했으면, 다시 실행 하기  위해 카운터 Reset.
    {
        sPattern_Cnt = 0;
    }
    

    if(sPattern_Cnt < 3000) 
    {
        sPattern_Cnt++;
        
        if(sPattern_Cnt == 1) //동일 내용을 여러번 표출 하는  것을 방지 하고, 부하를 감소.
        {
            for(Font_16 = 0; Font_16 < 3072; Font_16++)
            {
                
                
                pVd_Up[(Lint_sort)]=((0xFF>>j)&0x01) ? mLed_Process_Flag.sPattern_Test_ColorData : 0 ;
                pVd_Down[(Lint_sort++)]=((0xFF>>j)&0x01) ? mLed_Process_Flag.sPattern_Test_ColorData : 0 ;
                        
                
            }

        }
        return 1;
    }
    else 
    {
       
        sPattern_Cnt = 9999;
        return 0; 
    }
    
    
}


/*****************************************************************************
* @brief -
* @param -
* @retval-
******************************************************************************/

uint32_t mLed_BlinkFlag_Cnt;


void LED_Timer_1ms(void)
{

  
    mLed_BlinkFlag_Cnt++;
//    
//    mLed_PatternTimeFlagCnt++;
//    
    
    // 서버 동기화 비트가 있으면, 동기화 비트를  우선 순위가 높다.
    if(mLed_Process_Flag.sScreen_Page_Cnt_Rx_Comand_Flag)
    {
        
        if(mLed_Process_Flag.sScreen_Page_Cnt_Rx_Comand != mLed_Process_Flag.sScreen_Page_Cnt_Rx_ReComand)
        {
            
            
            if(mLed_Process_Flag.sScreen_Page_Check_Buf[mLed_Process_Flag.sScreen_Page_Cnt_Rx_Comand])
            {
                if(!mLed_Process_Flag.sScreen_Page_Cnt_Rx_Comand)
                {
                    
                    mLed_Process_Flag.sScreen_Page_Cnt = 0;
                }
                else
                {
                    mLed_Process_Flag.sScreen_Page_Cnt_Rx_ReComand = mLed_Process_Flag.sScreen_Page_Cnt_Rx_Comand;
                    mLed_Process_Flag.sScreen_Page_Cnt = mLed_Process_Flag.sScreen_Page_Cnt_Rx_ReComand;
                }
            
                mLed_Process_Flag.sScreen_ScanFlag = 1;
                
                
                
            }
  
        }
       
        
    } // 서버 동기화 비트가 없으면, 수시한 데이타를 이용해서 계산 한다.
    else if (!(mLed_BlinkFlag_Cnt % (mLed_Process_Flag.sScreen_Play_Time) )) 
	{
        
        mLed_Process_Flag.sScreen_ScanFlag = 1;
        
        
        if(mLed_Process_Flag.sEth_Rx_Flag)
        {
            mLed_Process_Flag.sScreen_Page_Cnt++;
            
            mLed_Process_Flag.sScreen_Page_Cnt = (mLed_Process_Flag.sScreen_Page_Cnt) % ((mLed_Process_Flag.sScreen_Display_Data_Page)/6);
        }
        
	}

//    
//    if (!(mLed_PatternTimeFlagCnt % 1000)) 
//	{
//		mLed_PatternFlag = 1; 
//
//    
//	}

    

}


