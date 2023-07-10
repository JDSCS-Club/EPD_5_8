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



#include "stm32f4xx_hal.h"

#include "test.h"
#include "../Utilities/Fonts/fonts.h"
#include "main.h"
#include "I2C.h"
#include "AmpGpio.h"
#include "stdbool.h"

I2C_HandleTypeDef hi2c1;
I2C_HandleTypeDef hi2c2;



/*****************************************************************************
* @brief -
* @param -
* @retval-
******************************************************************************/
void MX_I2C1_Init(void)
{
	GPIO_InitTypeDef   GPIO_InitStructure;

	GPIO_InitStructure.Pin =  GPIO_PIN_6 | GPIO_PIN_7;
	GPIO_InitStructure.Mode = GPIO_MODE_AF_OD;
	GPIO_InitStructure.Pull = GPIO_PULLUP;
	GPIO_InitStructure.Speed = GPIO_SPEED_FREQ_MEDIUM;
	GPIO_InitStructure.Alternate = GPIO_AF4_I2C1;
        
	__GPIOB_CLK_ENABLE();
	HAL_GPIO_Init(GPIOB, &GPIO_InitStructure); 
        

	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_6, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_7, GPIO_PIN_SET);
        
        

	/* USER CODE BEGIN I2C2_Init 0 */

	/* USER CODE END I2C2_Init 0 */

	/* USER CODE BEGIN I2C2_Init 1 */

	/* USER CODE END I2C2_Init 1 */
	hi2c1.Instance = I2C1;
	hi2c1.Init.ClockSpeed = 400000;
	hi2c1.Init.DutyCycle = I2C_DUTYCYCLE_2;
	hi2c1.Init.OwnAddress1 = 0;
	hi2c1.Init.AddressingMode = I2C_ADDRESSINGMODE_7BIT;
	hi2c1.Init.DualAddressMode = I2C_DUALADDRESS_DISABLE;
	hi2c1.Init.OwnAddress2 = 0;
	hi2c1.Init.GeneralCallMode = I2C_GENERALCALL_DISABLE;
	hi2c1.Init.NoStretchMode = I2C_NOSTRETCH_DISABLE;
      
	if (HAL_I2C_Init(&hi2c1) != HAL_OK)
	{
		Error_Handler();
	}


}


/*****************************************************************************
* @brief -
* @param -
* @retval-
******************************************************************************/
void MX_I2C2_Init(void)
{
  
	GPIO_InitTypeDef   GPIO_InitStructure;

	GPIO_InitStructure.Pin =  GPIO_PIN_10 | GPIO_PIN_11;
	GPIO_InitStructure.Mode = GPIO_MODE_AF_OD;
	GPIO_InitStructure.Pull = GPIO_PULLUP;
	GPIO_InitStructure.Speed = GPIO_SPEED_FREQ_MEDIUM;
	GPIO_InitStructure.Alternate = GPIO_AF4_I2C2;
        
	__GPIOB_CLK_ENABLE();
	HAL_GPIO_Init(GPIOB, &GPIO_InitStructure); 
        

	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_10, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_11, GPIO_PIN_SET);

	/* USER CODE BEGIN I2C2_Init 0 */

	/* USER CODE END I2C2_Init 0 */

	/* USER CODE BEGIN I2C2_Init 1 */

	/* USER CODE END I2C2_Init 1 */
	hi2c2.Instance = I2C2;
	hi2c2.Init.ClockSpeed = 400000;
	hi2c2.Init.DutyCycle = I2C_DUTYCYCLE_2;
	hi2c2.Init.OwnAddress1 = 0;
	hi2c2.Init.AddressingMode = I2C_ADDRESSINGMODE_7BIT;
	hi2c2.Init.DualAddressMode = I2C_DUALADDRESS_DISABLE;
	hi2c2.Init.OwnAddress2 = 0;
	hi2c2.Init.GeneralCallMode = I2C_GENERALCALL_DISABLE;
	hi2c2.Init.NoStretchMode = I2C_NOSTRETCH_DISABLE;
      
	if (HAL_I2C_Init(&hi2c2) != HAL_OK)
	{
		Error_Handler();
	}

}


//--------------------------------------------------------------------------------------------//
// 전류 센서 측정 하는 부분.
// 최종 기능 업데이트시 적용 필요.   ( LED가 동작무 부하일때 측정중지하는 부분 필요 -  무부하일때 측정값 틀어짐 확인)
//--------------------------------------------------------------------------------------------//
// I2C_HAL_ReadBytes
// I2C_HAL_WriteBytes
void processCurrentVal(void)
{
       uint8_t     nRbuf[10];
       int sData_val = 0;
       
    static int bCurLedCtr =1;


    if(bCurLedCtr) // 전류 센서 값은 LED 동작 중일 때만 동작 한다.
    {
        nRbuf[0] = 0x41;
        nRbuf[1] = 0x27;   
            
        if(I2C_HAL_WriteBytes(&hi2c2,0x80,0x00,(uint8_t *)nRbuf,2))
        {
            MyPrintf_USART1("++++++++++++ Write Calibration Register  ++++++++++++ \n\r" );
        }
        else
        {
            MyPrintf_USART1( "++Write Test NG \n\r" );
        }


        nRbuf[0] = 0xFF;
        nRbuf[1] = 0xFF;  
         if(I2C_HAL_ReadBytes(&hi2c2,0x80,0x01,(uint8_t *)nRbuf,2))
        {
            //printf("++ INA226 OK \n\r");
                
             MyPrintf_USART1( "++ Read Shunt Register (%02X,%02X) ------\r\n",nRbuf[0],nRbuf[1] );
        }
        else
        {
            MyPrintf_USART1( "++ INA226 NG \n\r" );
        }


            
         if(I2C_HAL_ReadBytes(&hi2c2,0x80,0x02,(uint8_t *)nRbuf,2))
        {
            //printf("++ INA226 OK \n\r");
             //소주점 2번째 가지까지 환산. (ex : 2427 -> 24.27v)
             sData_val = (float)((nRbuf[0] << 8) | nRbuf[1]) / 7.77; 
                
             MyPrintf_USART1( "++ Read Bus Voltage Register (%d) \r\n",sData_val );
        }
        else
        {
            MyPrintf_USART1( "++ INA226 NG \n\r" );
        }
            
                
                    
        /////////////////////////////////////IC  상태를 전류 측정 상태로 변경 하는 값.        
            nRbuf[0] = 0x0A;
            nRbuf[1] = 0x00;   
                
            if(I2C_HAL_WriteBytes(&hi2c2,0x80,0x05,(uint8_t *)nRbuf,2))
            {
                MyPrintf_USART1("++ Write V-C Change \r\n" );
            }
            else
            {
                MyPrintf_USART1( "++Write Calibration NG \n\r" );
            }
      /////////////////////////////////////                  
                
         if(I2C_HAL_ReadBytes(&hi2c2,0x80,0x04,(uint8_t *)nRbuf,2))
        {
           
             // mA로 표현 --> 초기 대구 
             sData_val = (float)((nRbuf[0] << 8) | nRbuf[1]) / 2.6; 
             
             if(mLed_Process_Flag.sCurrentVal < sData_val) // 1초에 한번씩 체크하고, 최대 값을 저장 하도록 수정.
             {
                mLed_Process_Flag.sCurrentVal = sData_val; // 전류 측정 값 리턴.  
             }
            
            MyPrintf_USART1( "++ Read Current Register(%03d) \n\r",sData_val );
        }
        else
        {
            MyPrintf_USART1( "++ INA226 Read NG \n\r");
        }
            
                
                    
                
        if(I2C_HAL_ReadBytes(&hi2c2,0x80,0x03,(uint8_t *)nRbuf,2))
        {
            //printf("++ INA226 OK \n\r");
                
             MyPrintf_USART1( "++ Read Power Register(%02X,%02X) \n\r",nRbuf[0],nRbuf[1] );
        }
        else
        {
            MyPrintf_USART1( "++ INA226 NG \n\r" );
                
        }
            
                
                    
    }

        
    
}

/*****************************************************************************
* @brief -
* @param -
* @retval-
******************************************************************************/
void MX_I2C_Process(void)
{
	static uint16_t s_SpkCheck = 0; 
	static uint16_t R_s_SpkCheck = 0; 
	static uint16_t R_s_SpkCheckCnt = 0; 
    
	static uint16_t s_InitCnt = 0;
    
    static uint16_t s_SpCh1 = 0;
    static uint16_t s_SpCh2 = 0;
    

    uint8_t sPowerStandbyFlag;
        
    uint8_t     nRbuf_0[2];
    uint8_t     nRbuf_1[2];
    uint8_t     nRbuf_2[2];
    

	
	s_SpkCheck = mDI_CheckFlag;
    
            
	if (s_SpkCheck != R_s_SpkCheck)
	{
        
		R_s_SpkCheck = s_SpkCheck;
        
         setAMP_Standby(true); // 모든 AMP IC
         setAMP_Standby(false); // 모든 AMP IC
         setAMP_Standby(true); // 모든 AMP IC
           
         
      //---------AUDIO-----------------------

         njw1192_mute(false);
       //-------------------------------------
         
         R_s_SpkCheckCnt = 1;
          
        
         MyPrintf_USART1 ("+++++ AMP T : %d \r\n",HAL_GetTick() );
            
	}
			

	if (R_s_SpkCheckCnt)
	{

		R_s_SpkCheckCnt--;
        
        if (getSW_RS() || getSW_AR()) 
		{
            
            MyPrintf_USART1 ("+++++ AMP T-1 : %d \r\n",HAL_GetTick() );
            
                s_SpCh1++;
                
                setAmp_Mute_1(false);
                setAmp_Mute_2(false);
                  
                
                //--------------------Audio IC Vol seting ANSM---------------------------//   
                if(mLed_Process_Flag.sAnsm_Run_Flag)
                {
                    if ((mAnsSetFlag.tAnsCnt > 15) || (mLed_Process_Flag.tAmp_Vol_UpFlag == true))
                    {
                        mAnsSetFlag.tAnsFlgSet = true;
                        njw1192_vol_setting(mLed_Process_Flag.tAmp_Vol_UpFlag, true); // ANS ON_OFF 기능.
                    }
                    else
                    {
                        if (mAnsSetFlag.tAnsFlgSet) // 이전에 ANS가 ON 이였다면, 동작 한다.
                        {
                            mAnsSetFlag.tAnsFlgSet = false;
                            njw1192_vol_setting(0, false); // ANS ON_OFF 기능.
                        }
                        
                    }
                }
                else
                {
                    if(mLed_Process_Flag.tAmp_Vol_UpFlag == true)
                    {
                        mAnsSetFlag.tAnsFlgSet = true;
                        njw1192_vol_setting(mLed_Process_Flag.tAmp_Vol_UpFlag, true); // ANS ON_OFF 기능.
                        
                    }
                    else
                    {
                        if (mAnsSetFlag.tAnsFlgSet) // 이전에 ANS가 ON 이였다면, 동작 한다.
                        {
                            mAnsSetFlag.tAnsFlgSet = false;
                            njw1192_vol_setting(0, false); // ANS ON_OFF 기능.
                        }
                        
                        
                        if( TEST_ROOM == 1) //TEST 시험 할때는 항상 동작.
                        {
                            njw1192_vol_setting(0, false); // ANS ON_OFF 기능.
                        }
                    }
                    
                }
               //****************************************************************// 
                
                
               //--------------------AMP  IC Vol seting---------------------------//   
                if(s_SpCh1 == 1 && s_SpCh2 == 0)
                {
                    if(AMP_H_TEMP == 0)
                    {
                        AMP_Init(AMP_ID_1);
                    }
                    // 초기화 로직이 60ms  정도 소유 된다.  
                    // 가장 빠른 속도는  고온 모드로 동작하고, 초기화 로직을 삭제 하는 것이다.
                    else if(mLed_Process_Flag.sCurrentTestFlag == TRUE) // 스피커 체크  동작 일때만 정상 동작 하도록 수정.
                    {
                        AMP_Init(AMP_ID_1);

                    }
                    
                }
                
                sPowerStandbyFlag = AMP_PowOn_Check();
                
                if(sPowerStandbyFlag != 0x07) 
                {
                    udp_SysLog("--------->NG RS/AR PowerStandBy( %d )",sPowerStandbyFlag);
                }
                
                s_SpCh2 = 0;
                
                  AMP_Mute_OFF(AMP_ID_1, AMP_ID_2, AMP_ID_3);
                  
                //****************************************************************//   
             
                setBk_Out_1(true);
                setBk_Out_3(true);
                setBk_Out_5(true);

                
                if ((getSW_SL() && (mLed_Process_Flag.sDHCP_IP_Val == 96)) // IP 96은 실외 스피커  왼쪽.
                  ||(getSW_SR() && (mLed_Process_Flag.sDHCP_IP_Val == 97)))// IP 97은 실외 스피커 오른쪽.
                {
                    setOSP_Led(true);

                    setBk_Out_6(true);
                    
                }
                else
                {
                    setBk_Out_6(false);
                       
                }
                

                mLed_Process_Flag.sRom_Spk_Flag = true;
                mLed_Process_Flag.sOut_Spk_Flag = false;
                mLed_Process_Flag.sSpk_check_Cnt = 10;
                mLed_Process_Flag.sAudio_Play_mode = true;
                
     
                MyPrintf_USART1 ("+++++ AMP E-1 : %d \r\n",HAL_GetTick() );

                setRSP_Led(true);
                setOSP_Led(false);
                
            
		}
		else if ((getSW_SL() && (mLed_Process_Flag.sDHCP_IP_Val == 96)) // IP 96은 실외 스피커  왼쪽.
               ||(getSW_SR() && (mLed_Process_Flag.sDHCP_IP_Val == 97)))// IP 97은 실외 스피커 오른쪽.
		{
            
            
            
            s_SpCh2++;
                
            setAmp_Mute_1(false);
            setAmp_Mute_2(false);
			
			
             njw1192_vol_setting_OutSpk();
            
			//****************************************************************//   
                

			//--------------------AMP  IC Vol seting---------------------------//   
               
			 if(s_SpCh1 == 0 && s_SpCh2 == 1)
            { 
                
                // 실외 스피커는 사림이 인지하는 속도가 느리기 때문에 그대로 사용.
                AMP_Init(AMP_ID_1);
                mLed_Process_Flag.sAudio_Play_mode = true;
                
                
            }
            
            sPowerStandbyFlag = AMP_PowOn_Check();
                
            if(sPowerStandbyFlag != 0x07) 
            {
                udp_SysLog("--------->NG SL/SR PowerStandBy( %d )",sPowerStandbyFlag);
            }
			
            s_SpCh1 = 0;
            
            
            AMP_Mute_OFF(AMP_ID_1, AMP_ID_2, AMP_ID_3); // 모든 채널을 ON 하고 릴레이로 제어 한다.
            
            //****************************************************************//   
			
			setBk_Out_1(false);
			setBk_Out_3(false);
			setBk_Out_5(false);

			setBk_Out_6(true);
            
            mLed_Process_Flag.sRom_Spk_Flag = false;
            mLed_Process_Flag.sOut_Spk_Flag = true;
            mLed_Process_Flag.sSpk_check_Cnt = 10;
            mLed_Process_Flag.sAudio_Play_mode = true;
            
             
            setRSP_Led(false);
			setOSP_Led(true);
   
                
		}
		else
		{
            s_SpCh1 = 0;
            s_SpCh2 = 0 ;   
			
			setRSP_Led(false);
			setOSP_Led(false);

                
            //AMP close 노이즈 해결하기 위해 릴레이를  먼저 close
            setBk_Out_1(false);
			setBk_Out_3(false);
			setBk_Out_5(false);

			setBk_Out_6(false);
            
			AMP_Mute_ON(AMP_ID_1, AMP_CH_All, AMP_ID_2, AMP_CH_All, AMP_ID_3, AMP_CH_All); // amp ic all mute
                
            
          //---------AUDIO-----------------------
            njw1192_mute(true);
            setAmp_Mute_1(true);
            setAmp_Mute_2(true);
          //--------------------------------
            
            MyPrintf_USART1 ("+++++ AMP E : %d \r\n",HAL_GetTick() );
                
			mAnsSetFlag.tAnsCnt = 0; // ANSM 초기화
            
            //방송 시간이  스피커 체크 시간보다  짧으면 스피커 체크를 중단 한다.
            if(mLed_Process_Flag.sSpk_check_Cnt >= 1) { mLed_Process_Flag.sSpk_check_Cnt = 0;}
            
            
            mLed_Process_Flag.sRom_Spk_Flag = true;
            
            mLed_Process_Flag.sSpk_check_Cnt = 10;  // ** AMP Standby OFF count 
            
            mLed_Process_Flag.sAudio_Play_mode = false;
            

		}
	}

}


/*****************************************************************************
* @brief -
* @param -
* @retval-
******************************************************************************/
//========================================================================
int I2C_HAL_WriteBytes(I2C_HandleTypeDef *hi2c, uint16_t DevAddress, uint16_t MemAddress, uint8_t *pData, uint16_t TxBufferSize)
//========================================================================
{
	int TimeOut;

	TimeOut = 0;
	while (HAL_I2C_Mem_Write(hi2c, (uint16_t)DevAddress, (uint16_t)MemAddress, I2C_MEMADD_SIZE_8BIT, pData, (uint16_t)TxBufferSize,2) != HAL_OK && TimeOut < 2) TimeOut++;

	HAL_Delay(5);

	return 1;
}


/*****************************************************************************
* @brief -
* @param -
* @retval-
******************************************************************************/
//========================================================================
int I2C_HAL_ReadBytes(I2C_HandleTypeDef *hi2c, uint16_t DevAddress, uint16_t MemAddress, uint8_t *pData, uint16_t RxBufferSize)
//========================================================================
{
	int TimeOut;

	TimeOut = 0;
	while (HAL_I2C_Mem_Read(hi2c, (uint16_t)DevAddress, (uint16_t)MemAddress, I2C_MEMADD_SIZE_8BIT, pData, (uint16_t)RxBufferSize, 2) != HAL_OK && TimeOut < 2) TimeOut++;

	return 1;
}


/*****************************************************************************
* @brief -
* @param -
* @retval-
******************************************************************************/
void AMP_Init(uint16_t Address)
{
	//HAL_StatusTypeDef result;
    
	uint8_t     nRbuf[10];
      

     MyPrintf_USART1( "+++++ %s(%d)\r\n", __func__, __LINE__ );
     
     
	nRbuf[0] = 0x3A; // Set channel Gain
	I2C_HAL_WriteBytes(&hi2c2, AMP_ID_1, 0x08, (uint8_t *)nRbuf, 1);
    I2C_HAL_WriteBytes(&hi2c2, AMP_ID_2, 0x08, (uint8_t *)nRbuf, 1);
    I2C_HAL_WriteBytes(&hi2c2, AMP_ID_3, 0x08, (uint8_t *)nRbuf, 1);
    
    
    nRbuf[0] = 0x0C; //
	I2C_HAL_WriteBytes(&hi2c2, AMP_ID_1, 0x0A, (uint8_t *)nRbuf, 1);
    I2C_HAL_WriteBytes(&hi2c2, AMP_ID_2, 0x0A, (uint8_t *)nRbuf, 1);
    I2C_HAL_WriteBytes(&hi2c2, AMP_ID_3, 0x0A, (uint8_t *)nRbuf, 1);
    
    
    
    nRbuf[0] = 0xD2; // 
	I2C_HAL_WriteBytes(&hi2c2, AMP_ID_1, 0x0b, (uint8_t *)nRbuf, 1);
    
    nRbuf[0] = 0x12;
	I2C_HAL_WriteBytes(&hi2c2, AMP_ID_2, 0x0b, (uint8_t *)nRbuf, 1);
    
    nRbuf[0] = 0x16;
	I2C_HAL_WriteBytes(&hi2c2, AMP_ID_3, 0x0b, (uint8_t *)nRbuf, 1);
    
	HAL_Delay(5);  // 100ms 항상 유지 필요
      
	nRbuf[0] = 0xFF;
	I2C_HAL_ReadBytes(&hi2c2, AMP_ID_1, 0x00, (uint8_t *)nRbuf, 1);
	I2C_HAL_ReadBytes(&hi2c2, AMP_ID_2, 0x00, (uint8_t *)nRbuf, 1);
	I2C_HAL_ReadBytes(&hi2c2, AMP_ID_3, 0x00, (uint8_t *)nRbuf, 1);

    

}


/*****************************************************************************
* @brief -
* @param -
* @retval- // 0x09 Reserved // 
// 0x10 -> mute mode
// 0x00 -> play mode
******************************************************************************/

void AMP_Mute_OFF(
                    uint16_t Address1, 
                    uint16_t Address2, 
                    uint16_t Address3)
{
	uint8_t     nTbuf[10];
	uint8_t     nRbuf[10];
    
    uint8_t dCnt = 0;
    
    
	if (AMP_ID_1 == Address1)
	{
        
		nTbuf[0] = 0x09;
		I2C_HAL_WriteBytes(&hi2c2, AMP_ID_1, 0x0C, (uint8_t *)nTbuf, 1);
       
	}
    
	if (AMP_ID_2 == Address2)
	{
        
		nTbuf[0] = 0x09;
		I2C_HAL_WriteBytes(&hi2c2, AMP_ID_2, 0x0C, (uint8_t *)nTbuf, 1);
            
       
	}
    
	if (AMP_ID_3 == Address3)
	{
		nTbuf[0] = 0x09;
		I2C_HAL_WriteBytes(&hi2c2, AMP_ID_3, 0x0C, (uint8_t *)nTbuf, 1);
            
	}
     
    
}

/*****************************************************************************
* @brief -
* @param -
* @retval- // 0x09 Reserved // 
// 0x10 -> mute mode
// 0x00 -> play mode
******************************************************************************/

int AMP_PowOn_Check(void)
{
    uint8_t     nRbuf[2];
    uint8_t     nRbuf1[2];
    uint8_t     nRbuf2[2];
    
    static uint8_t sSwitchCnt = 0;
    
    static uint8_t sPowerStandBy = 0;
    
    
    
    nRbuf[0] = 0xFF;
    nRbuf1[0] = 0xFF;
    nRbuf2[0] = 0xFF;
    
    
    
    sPowerStandBy = 0;
    
    
    MyPrintf_USART1( "+++++ %s(%d)\r\n", __func__, __LINE__ );
    
    
    I2C_HAL_ReadBytes(&hi2c2, AMP_ID_1, 0x00, (uint8_t *)nRbuf, 1);
    I2C_HAL_ReadBytes(&hi2c2, AMP_ID_1, 0x01, (uint8_t *)nRbuf1, 1);
    
    
    if(nRbuf[0] == 0x00 && nRbuf1[0] == 0x00)
    {
        sPowerStandBy = sPowerStandBy | (0x01);
    }
    
    MyPrintf_USART1( "+++++ AMP_ID_1 (%x - %x)\r\n",nRbuf[0],nRbuf1[0] );
    
    
    I2C_HAL_ReadBytes(&hi2c2, AMP_ID_2, 0x00, (uint8_t *)nRbuf, 1);
    I2C_HAL_ReadBytes(&hi2c2, AMP_ID_2, 0x01, (uint8_t *)nRbuf1, 1);
    
     if(nRbuf[0] == 0x00 && nRbuf1[0] == 0x00)
    {
        sPowerStandBy = sPowerStandBy | (0x01 <<1);
    }
    
    MyPrintf_USART1( "+++++ AMP_ID_2 (%x - %x)\r\n",nRbuf[0],nRbuf1[0] );
    
    
    I2C_HAL_ReadBytes(&hi2c2, AMP_ID_3, 0x00, (uint8_t *)nRbuf, 1);
    I2C_HAL_ReadBytes(&hi2c2, AMP_ID_3, 0x01, (uint8_t *)nRbuf1, 1);
    
     if(nRbuf[0] == 0x00 && nRbuf1[0] == 0x00)
    {
        sPowerStandBy = sPowerStandBy | (0x01 <<2);
    }
    
    MyPrintf_USART1( "+++++ AMP_ID_3 (%x - %x)\r\n",nRbuf[0],nRbuf1[0] );
    
    
    return sPowerStandBy;
    
    
}

/*****************************************************************************
* @brief -
* @param -
* @retval-  // 0x0D : 1ch mute // 0x0B : 2ch mute   // 0x1F : all channels mute
******************************************************************************/
void AMP_Mute_ON(
                uint16_t Address1,
                uint8_t ad_ch1,
                uint16_t Address2,
                uint8_t ad_ch2,
                uint16_t Address3,
                uint8_t ad_ch3)
{
     
	uint8_t     nTbuf[10];
	uint8_t     nRbuf[10];

    
	if (AMP_ID_1 == Address1)
	{
        
		if (ad_ch1 == AMP_CH_All)
		{
			nTbuf[0] = 0x1F;
			I2C_HAL_WriteBytes(&hi2c2, AMP_ID_1, 0x0C, (uint8_t *)nTbuf, 1);
		}
		else if (ad_ch1 == AMP_CH_1) // 1ch mute
		{
			nTbuf[0] = 0x1D;
			I2C_HAL_WriteBytes(&hi2c2, AMP_ID_1, 0x0C, (uint8_t *)nTbuf, 1);
            
		}
		else if(ad_ch1 == AMP_CH_2) // 2ch mute
		{
			nTbuf[0] = 0x1B;
			I2C_HAL_WriteBytes(&hi2c2, AMP_ID_1, 0x0C, (uint8_t *)nTbuf, 1);
		}
        
       
	}
    
	if (AMP_ID_2 == Address2)
	{
        
		if (ad_ch2 == AMP_CH_All)
		{
			nTbuf[0] = 0x1F;
			I2C_HAL_WriteBytes(&hi2c2, AMP_ID_2, 0x0C, (uint8_t *)nTbuf, 1);
		}
		else if (ad_ch2 == AMP_CH_1) // 1ch mute
		{
			nTbuf[0] = 0x1D;
			I2C_HAL_WriteBytes(&hi2c2, AMP_ID_2, 0x0C, (uint8_t *)nTbuf, 1);
            
		}
		else if(ad_ch2 == AMP_CH_2) // 2ch mute
		{
			nTbuf[0] = 0x1B;
			I2C_HAL_WriteBytes(&hi2c2, AMP_ID_2, 0x0C, (uint8_t *)nTbuf, 1);
		}
            
       
	}
    
    
	if (AMP_ID_3 == Address3)
	{
		if (ad_ch3 == AMP_CH_All)
		{
			nTbuf[0] = 0x1F;
			I2C_HAL_WriteBytes(&hi2c2, AMP_ID_3, 0x0C, (uint8_t *)nTbuf, 1);
		}
		else if (ad_ch3 == AMP_CH_1) // 1ch mute
		{
			nTbuf[0] = 0x1D;
			I2C_HAL_WriteBytes(&hi2c2, AMP_ID_3, 0x0C, (uint8_t *)nTbuf, 1);
            
		}
		else if(ad_ch3 == AMP_CH_2) // 2ch mute
		{
			nTbuf[0] = 0x1B;
			I2C_HAL_WriteBytes(&hi2c2, AMP_ID_3, 0x0C, (uint8_t *)nTbuf, 1);
		}
        
            
	}
    
}

/*****************************************************************************
* @brief -
* @param -
* @retval-
******************************************************************************/

void AMP_FAULT(void)
{
	uint8_t     nRbuf[2];
    uint8_t     nRbuf1[2];
    uint8_t     nRbuf2[2];
    uint8_t     nRbuf3[2];

    static uint8_t sAmpRestCnt = 0;
    
 
    
      //-----------------------------------------------------------------------------------------------
        if (getAmp1_Pault() == false)
        {
            
            nRbuf[0] = 0xFF; 
            nRbuf1[0] = 0xFF;    
            I2C_HAL_ReadBytes(&hi2c2, AMP_ID_1, 0x00, (uint8_t *)nRbuf, 1);
            I2C_HAL_ReadBytes(&hi2c2, AMP_ID_1, 0x01, (uint8_t *)nRbuf1, 1);
                
            MyPrintf_USART1("+++++ getAmp1_Pault - 1:%02x / 2:%02x \r\n", nRbuf[0],nRbuf1[0]);
                
            sprintf(&mLCDPrintBuf[2][0], "P1-%2x", nRbuf[0]);
            
            mLed_Process_Flag.sAmp_Falut_val |= 0x01;
            
                
        }
        else
        {
            sprintf(&mLCDPrintBuf[2][0], "-----");
            
            mLed_Process_Flag.sAmp_Falut_val &= 0x0E;
        }
            
      //-----------------------------------------------------------------------------------------------      
        if (getAmp2_Pault() == false)
        {
            nRbuf[0] = 0xFF;    
            nRbuf1[0] = 0xFF;
            I2C_HAL_ReadBytes(&hi2c2, AMP_ID_2, 0x00, (uint8_t *)nRbuf, 1);
            I2C_HAL_ReadBytes(&hi2c2, AMP_ID_2, 0x01, (uint8_t *)nRbuf1, 1);
                
                
            MyPrintf_USART1("+++++ getAmp2_Pault - 1:%02x / 2:%02x \r\n", nRbuf[0],nRbuf1[0]);
                
            sprintf(&mLCDPrintBuf[2][5], "P2-%2x", nRbuf[0]);
            
            mLed_Process_Flag.sAmp_Falut_val |= 0x01<<1;
                
        }
        else
        {
            sprintf(&mLCDPrintBuf[2][5], "*****");
            
            mLed_Process_Flag.sAmp_Falut_val &= 0x0D;
        }
            
      //-----------------------------------------------------------------------------------------------      
        if (getAmp3_Pault() == false)
        {
            nRbuf[0] = 0xFF;    
            nRbuf1[0] = 0xFF;
            I2C_HAL_ReadBytes(&hi2c2, AMP_ID_3, 0x00, (uint8_t *)nRbuf, 1);
            I2C_HAL_ReadBytes(&hi2c2, AMP_ID_3, 0x01, (uint8_t *)nRbuf1, 1);
                
            
            MyPrintf_USART1("+++++ getAmp3_Pault - 1:%02x / 2:%02x \r\n", nRbuf[0],nRbuf1[0]);
                
            sprintf(&mLCDPrintBuf[2][10], "P3-%2x", nRbuf[0]);
            
             mLed_Process_Flag.sAmp_Falut_val |= 0x01<<2;
                
                
        }
        else
        {
            sprintf(&mLCDPrintBuf[2][10], "-----");
            
            mLed_Process_Flag.sAmp_Falut_val &= 0x0B;
        }

  //-----------------------------------------------------------------------------------------------
    sprintf(&mLCDPrintBuf[2][15], "Temp-%02d",mLed_Process_Flag.sCpu_Temp);
    
    
  //-----------------------------------------------------------------------------------------------
    
       // AMP 고장이 발새하고, 5초간 유지 된다면. 초기화를 다시 한다.
    if(mLed_Process_Flag.sAmp_Falut_val)
    {
        
        mLed_Process_Flag.sAmp_Fault_Cnt++;
        
        if(mLed_Process_Flag.sAmp_Fault_Cnt == 5)
        {
            mLed_Process_Flag.sAmp_Fault_Cnt = 0;
            
            nRbuf[0] = 0xFF;
            nRbuf1[0] = 0xFF;
            nRbuf2[0] = 0xFF;
            
            I2C_HAL_ReadBytes(&hi2c2, AMP_ID_1, 0x04, (uint8_t *)nRbuf, 1);
            I2C_HAL_ReadBytes(&hi2c2, AMP_ID_2, 0x04, (uint8_t *)nRbuf1, 1);
            I2C_HAL_ReadBytes(&hi2c2, AMP_ID_3, 0x04, (uint8_t *)nRbuf2, 1);
            
            MyPrintf_USART1("+++++ getAmpPault - 1:%02x -- 2:%02x -- 3:%02x \r\n", nRbuf[0],nRbuf1[0],nRbuf2[0]);
            
            sAmpRestCnt++;
            
            if(sAmpRestCnt &0x01)
            {
                setAmp_Mute_1(false);
                setAmp_Mute_2(false);
                
                setAMP_Standby(false); //   
 
            }

        }
        
        
    }
    else
    {
       
        
        if(sAmpRestCnt) //AMP가 고장이여서  REST 하는 Flag.
        {
            sAmpRestCnt = 0;
            
            mLed_Process_Flag.sAmp_Fault_Cnt_All++;
            
            

            setAMP_Standby(true);


            AMP_Init(AMP_CH_All);

            AMP_Mute_ON(AMP_ID_1, AMP_CH_All, AMP_ID_2, AMP_CH_All, AMP_ID_3, AMP_CH_All); // amp ic all mute

            AMP_Mute_OFF(AMP_ID_1, AMP_ID_2, AMP_ID_3);


            MyPrintf_USART1("+++++ getAmpPault ---> RESET\r\n");

            udp_SysLog("+++++ getAmpPault(%02d,%02d)/ Temp(%02d)---> RESET\r\n",IP_ADDR1_INPUT_DATA,IP_ADDR2_INPUT_DATA,mLed_Process_Flag.sCpu_Temp);
            
            if(mLed_Process_Flag.sAmp_Fault_Cnt_All >5 ) // 초기화 동작을  5회 이상 하면 시스템을 RESET 한다.
            {
                HAL_NVIC_SystemReset(); //시스템을 리겟 하는 기능 
            }
            
        }
        else // 아무런 고장이 없어서  초기화 하는 동작.
        {
            mLed_Process_Flag.sAmp_Fault_Cnt = 0;

            mLed_Process_Flag.sAmp_Fault_Cnt_All = 0;
            
        }
                

    }

    
    
}
/*****************************************************************************
* @brief - 
* @param -
* @retval-
******************************************************************************/


void AMP_SPK_CHECK(void)
{
    
    static uint8_t sSpkPlayModeFlag = 0;
    static uint16_t sSpkPlayCnt = 0;
    static uint8_t sPlayReadData[5];
    
    uint8_t     nRbuf_0[2];
    uint8_t     nRbuf_1[2];
    uint8_t     nRbuf_2[2];
    
    
    
    
    if(mLed_Process_Flag.sRom_Spk_Flag) //실내 스피커 체크 
    {
        
        mLed_Process_Flag.sRom_Spk_Flag = false;
        
        nRbuf_0[0] = 0xFF;
        nRbuf_1[0] = 0xFF;
        nRbuf_2[0] = 0xFF;
        
        I2C_HAL_ReadBytes(&hi2c2, AMP_ID_1, 0x06, (uint8_t *)nRbuf_0, 1);
        I2C_HAL_ReadBytes(&hi2c2, AMP_ID_2, 0x06, (uint8_t *)nRbuf_1, 1);
        I2C_HAL_ReadBytes(&hi2c2, AMP_ID_3, 0x06, (uint8_t *)nRbuf_2, 1);
        
        MyPrintf_USART1("+++++ In-Amp Mute/Play mode- 1:%02X / 2:%02X / 3:%02X \r\n",nRbuf_0[0],nRbuf_1[0],nRbuf_2[0] );
        
        
        
        if((nRbuf_0[0] == 0x06) && (nRbuf_1[0] == 0x06) && (nRbuf_2[0] == 0x06))
        {
            sSpkPlayModeFlag = true;
            
            
        }
        else
        {
            
            sSpkPlayModeFlag = false;
            
            sPlayReadData[0] = nRbuf_0[0];
            sPlayReadData[1] = nRbuf_1[0];
            sPlayReadData[2] = nRbuf_2[0];
            
            
        }
        

        if(mLed_Process_Flag.sAudio_Play_mode == true)
        {
            
            if(mLed_Process_Flag.sCurrentTestFlag == TRUE) //스피커 테스트  일때만 동작 하도록 수정.
            {
                nRbuf_1[0] = 0xFF;
                nRbuf_2[0] = 0xFF;

                // I2C_HAL_ReadBytes(&hi2c2, AMP_ID_1, 0x00, (uint8_t *)nRbuf_1, 1);
                    
                I2C_HAL_ReadBytes(&hi2c2, AMP_ID_1, 0x02, (uint8_t *)nRbuf_1, 1);
                I2C_HAL_ReadBytes(&hi2c2, AMP_ID_1, 0x03, (uint8_t *)nRbuf_2, 1);
                              
                MyPrintf_USART1("+++++ getAmp1 Spk read :%02X \r\n", ((nRbuf_1[0]&0xF0) | (nRbuf_2[0]&0x0F)));

                mLed_Process_Flag.sSt_Buf_Val[0] = ((nRbuf_1[0]&0xF0) | (nRbuf_2[0]&0x0F));
                
                
                nRbuf_1[0] = 0xFF;
                nRbuf_2[0] = 0xFF;
                
                // I2C_HAL_ReadBytes(&hi2c2, AMP_ID_2, 0x00, (uint8_t *)nRbuf_1, 1);

                I2C_HAL_ReadBytes(&hi2c2, AMP_ID_2, 0x02, (uint8_t *)nRbuf_1, 1);
                I2C_HAL_ReadBytes(&hi2c2, AMP_ID_2, 0x03, (uint8_t *)nRbuf_2, 1);
                              
                MyPrintf_USART1("+++++ getAmp2 Spk read :%02X \r\n", ((nRbuf_1[0]&0xF0) | (nRbuf_2[0]&0x0F)));
            
                mLed_Process_Flag.sSt_Buf_Val[1] = ((nRbuf_1[0]&0xF0) | (nRbuf_2[0]&0x0F));
                
                
                
                nRbuf_1[0] = 0xFF;
                nRbuf_2[0] = 0xFF;
                
                I2C_HAL_ReadBytes(&hi2c2, AMP_ID_3, 0x02, (uint8_t *)nRbuf_1, 1);
                
                if(mLed_Process_Flag.sOut_Spk_Flag) // 추가로 실외 스피커 동작 하면 같이 체크한다. 
                {
                    mLed_Process_Flag.sOut_Spk_Flag = false;

                    I2C_HAL_ReadBytes(&hi2c2, AMP_ID_3, 0x03, (uint8_t *)nRbuf_2, 1);
                }
                else 
                {
                    nRbuf_2[0] = 0x00;
                }
                              
                MyPrintf_USART1("+++++ getAmp3 Spk read :%02X \r\n", ((nRbuf_1[0]&0xF0) | (nRbuf_2[0]&0x0F)));
                
                mLed_Process_Flag.sSt_Buf_Val[2] = ((nRbuf_1[0]&0xF0) | (nRbuf_2[0]&0x0F));
            }
            
            
            
            //-------------------------------------------------//
            if(sSpkPlayModeFlag == true) //방송 출력 이 잘 동작 하는지 확인하는 카운터.
            {
                sSpkPlayCnt++;

                udp_SysLog("--------->(%dT,%d) Play Mode (Cnt : %d)",
                    mLed_Process_Flag.sTrainID,
                    mLed_Process_Flag.sDHCP_IP_Val,
                    sSpkPlayCnt);
                        
                      
            }
            else
            {
                udp_SysLog("--------->(%dT,%d) NG Play Mode (Amp_R1 : %d / Amp_R2 : %d / Amp_R3 : %d )",
                    mLed_Process_Flag.sTrainID,
                    mLed_Process_Flag.sDHCP_IP_Val,
                    sPlayReadData[0],
                    sPlayReadData[1],
                    sPlayReadData[2]);
                
            }
            ////////////////////////////////////////////////////

        }
        else
        {
            
            if(AMP_H_TEMP == 0)
            {
                //저온 돟작 모드는  Standby 를 OFF
                setAMP_Standby(false); //AMP Standby OFF 
                
                 MyPrintf_USART1("+++++ setAMP_Standby_OFF \r\n");
                
            }
            else
            {
                // 고온 동작 모드 Standby 를 OFF 하지 않고--> ON 상태를 유지.
            }
        }

    
    }
    else if(mLed_Process_Flag.sOut_Spk_Flag) // 실외 스피커만 동작 하면. 
     {
         mLed_Process_Flag.sOut_Spk_Flag = false;
         
         
        // I2C_HAL_ReadBytes(&hi2c2, AMP_ID_3, 0x00, (uint8_t *)nRbuf_1, 1);

        //I2C_HAL_ReadBytes(&hi2c2, AMP_ID_3, 0x02, (uint8_t *)nRbuf_1, 1);
         
         nRbuf_1[0] = 0x0F;
         nRbuf_2[0] = 0xFF;
         
        I2C_HAL_ReadBytes(&hi2c2, AMP_ID_3, 0x03, (uint8_t *)nRbuf_2, 1);
                      
        MyPrintf_USART1("+++++ getAmp3 Spk read :%02X \r\n", ((nRbuf_1[0]&0xF0) | (nRbuf_2[0]&0x0F)));
        
        mLed_Process_Flag.sSt_Buf_Val[3] = ((nRbuf_1[0]&0xF0) | (nRbuf_2[0]&0x0F));
        
        
        I2C_HAL_ReadBytes(&hi2c2, AMP_ID_1, 0x06, (uint8_t *)nRbuf_0, 1);
        I2C_HAL_ReadBytes(&hi2c2, AMP_ID_2, 0x06, (uint8_t *)nRbuf_1, 1);
        I2C_HAL_ReadBytes(&hi2c2, AMP_ID_3, 0x06, (uint8_t *)nRbuf_2, 1);
        
        MyPrintf_USART1("+++++ Out- Amp Mute/Play mode- 1:%02X / 2:%02X / 3:%02X \r\n",nRbuf_0[0],nRbuf_1[0],nRbuf_2[0] );
        
        
     }

    
}




