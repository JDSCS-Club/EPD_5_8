/*
 * naranja_boron.c
 *
 *  Created on: 2019. 12. 24.
 *      Author: RobertKim
 */
//--------------------------------------------------------------------------------------------//
//
//--------------------------------------------------------------------------------------------//
#include "main.h"
#include "stdbool.h"
#include "naranja_boron.h"
#include "adc.h"
//--------------------------------------------------------------------------------------------//
//
//--------------------------------------------------------------------------------------------//
typedef enum
{
	CHARGE_RATE_UNKNOWN = 0u,
	CHARGE_RATE_75_UNDER,
	CHARGE_RATE_100_UNDER,
	CHARGE_RATE_100
} ChargeRateState;
//--------------------------------------------------------------------------------------------//
//
//--------------------------------------------------------------------------------------------//
uint8_t u8RS485Id = false;
bool bCurLedCtr = false;
bool bAmpOnOff = false;
bool bCurAmpOnOff = false;
bool bAmpStateChange = false;

ChargeRateState curChargeState = CHARGE_RATE_UNKNOWN;
ChargeRateState viaChargeState = CHARGE_RATE_UNKNOWN;
uint16_t u16LedChangeTick = 0;
uint16_t u16Led75UnderFlickerTick = 0;
uint16_t u16Led100UnderFlickerTick = 0;
uint16_t u16AmpSettingTick = 0;
bool bAmpSettingDetected = false;
uint16_t u16BatVol = 0;
uint16_t u16CntBatVol = 0;
uint32_t u16BatVolSum = 0;

uint8_t uDI_getMasterIn;
uint8_t uSpk_Stat;
uint8_t uRssi_NgFlag;

uint8_t uAudioPlayFlag = false;
//--------------------------------------------------------------------------------------------//
//
//--------------------------------------------------------------------------------------------//
/**
  * @brief  75% LED
  */
bool getLed75(void){ return HAL_GPIO_ReadPin(LED_75_GPIO_Port, LED_75_Pin); }
void setLed75(bool state){ HAL_GPIO_WritePin(LED_75_GPIO_Port, LED_75_Pin, state); }
void toggleLed75(void){ HAL_GPIO_TogglePin(LED_75_GPIO_Port, LED_75_Pin); }
void led75On(void){ HAL_GPIO_WritePin(LED_75_GPIO_Port, LED_75_Pin, false); }
void led75Off(void){ HAL_GPIO_WritePin(LED_75_GPIO_Port, LED_75_Pin, true); }
//--------------------------------------------------------------------------------------------//
//
//--------------------------------------------------------------------------------------------//
/**
  * @brief  100% Red LED
  */
bool getLed100Red(void){ return HAL_GPIO_ReadPin(LED_100_RED_GPIO_Port, LED_100_RED_Pin); }
void setLed100Red(bool state){ HAL_GPIO_WritePin(LED_100_RED_GPIO_Port, LED_100_RED_Pin, state); }
void toggleLed100Red(void){ HAL_GPIO_TogglePin(LED_100_RED_GPIO_Port, LED_100_RED_Pin); }
void led100RedOn(void){ HAL_GPIO_WritePin(LED_100_RED_GPIO_Port, LED_100_RED_Pin, false); }
void led100RedOff(void){ HAL_GPIO_WritePin(LED_100_RED_GPIO_Port, LED_100_RED_Pin, true); }
//--------------------------------------------------------------------------------------------//
//
//--------------------------------------------------------------------------------------------//
/**
  * @brief  100% Green LED
  */
bool getLed100Green(void){ return HAL_GPIO_ReadPin(LED_100_GREEN_GPIO_Port, LED_100_GREEN_Pin); }
void setLed100Green(bool state){ HAL_GPIO_WritePin(LED_100_GREEN_GPIO_Port, LED_100_GREEN_Pin, state); }
void led100GreenOn(void){ HAL_GPIO_WritePin(LED_100_GREEN_GPIO_Port, LED_100_GREEN_Pin, false); }
void led100GreenOff(void){ HAL_GPIO_WritePin(LED_100_GREEN_GPIO_Port, LED_100_GREEN_Pin, true); }
//--------------------------------------------------------------------------------------------//
//
//--------------------------------------------------------------------------------------------//
/**
  * @brief  get Charger detection
  */
bool getChargerDet(void){ return HAL_GPIO_ReadPin(CHARGER_DET_GPIO_Port, CHARGER_DET_Pin); }
//--------------------------------------------------------------------------------------------//
//
//--------------------------------------------------------------------------------------------//
/**
  * @brief  get Charge rate
  */
uint8_t getChargeRate(void){ return (Get_Adc2_Value() * 100) / ADC_MAX_DATA; }
//--------------------------------------------------------------------------------------------//
//
//--------------------------------------------------------------------------------------------//
/**
  * @brief  get VCC input
  */
bool getVccIn(void){ return !HAL_GPIO_ReadPin(VCC_IN_GPIO_Port, VCC_IN_Pin); }
//--------------------------------------------------------------------------------------------//
//
//--------------------------------------------------------------------------------------------//
/**
  * @brief  get Radio module operation state
  */
bool getStandBy(void){ return HAL_GPIO_ReadPin(ST_BY_GPIO_Port, ST_BY_Pin); }
//--------------------------------------------------------------------------------------------//
//
//--------------------------------------------------------------------------------------------//
/**
  * @brief  get Light state
  */
bool getLightOn(void){ return HAL_GPIO_ReadPin(LIGHT_ON_GPIO_Port, LIGHT_ON_Pin); }
//--------------------------------------------------------------------------------------------//
//
//--------------------------------------------------------------------------------------------//
/**
  * @brief  get Master input
  */
//#if defined( MASTER_IN_OUT_GPIO_Port )
//
////	MASTER_IN 신호 Output으로 수정.
//bool getMasterIn(void){ return 1; }
//#else
bool getMasterIn(void){ return !HAL_GPIO_ReadPin(MASTER_IN_GPIO_Port, MASTER_IN_Pin); }
//#endif
//--------------------------------------------------------------------------------------------//
//
//--------------------------------------------------------------------------------------------//
/**
  * @brief  get Digital input
  */
bool getDICtl(void){ return HAL_GPIO_ReadPin(DI_CTL_GPIO_Port, DI_CTL_Pin); }
//--------------------------------------------------------------------------------------------//
//
//--------------------------------------------------------------------------------------------//
/**
  * @brief  Override On
  */
bool getOverrideOn(void){ return HAL_GPIO_ReadPin(OVERRIDE_GPIO_Port, OVERRIDE_Pin); }
void setOverrideOn(GPIO_PinState state){ HAL_GPIO_WritePin(OVERRIDE_GPIO_Port, OVERRIDE_Pin, state); }
//--------------------------------------------------------------------------------------------//
//
//--------------------------------------------------------------------------------------------//
/**
  * @brief  set RF LED
  */
void setRfLed(GPIO_PinState state){ HAL_GPIO_WritePin(RF_LED_GPIO_Port, RF_LED_Pin, state); }

void rfLedOn(void){ HAL_GPIO_WritePin(RF_LED_GPIO_Port, RF_LED_Pin, false); }
void rfLedOff(void){ HAL_GPIO_WritePin(RF_LED_GPIO_Port, RF_LED_Pin, true); }
//--------------------------------------------------------------------------------------------//
//
//--------------------------------------------------------------------------------------------//
/**
  * @brief  set RS485 inactive state
  */

//--------------------------------------------------------------------------------------------//
//
//--------------------------------------------------------------------------------------------//

bool getVccRfIn(void){ return !HAL_GPIO_ReadPin(VCC_RF_IN_Port, VCC_RF_IN); }
bool getAmpFault(void){ return HAL_GPIO_ReadPin(AMP_FAULT_Port, AMP_FAULT_Pin); }
bool getVccLedIn(void){ return !HAL_GPIO_ReadPin(VCC_LED_IN_Port, VCC_LED_IN); }
bool getVccAudioIn(void){ return !HAL_GPIO_ReadPin(VCC_AUDIO_IN_Port, VCC_AUDIO_IN); }
//--------------------------------------------------------------------------------------------//
//
//--------------------------------------------------------------------------------------------//
/**
  * @brief  set LED CTR pin
  */
void setLedCtr(void ){  HAL_GPIO_WritePin(LED_CTL_GPIO_Port, LED_CTL_Pin, true); }
void ledCtrOn(void){  HAL_GPIO_WritePin(LED_CTL_GPIO_Port, LED_CTL_Pin, true); }
void ledCtrOff(void){  HAL_GPIO_WritePin(LED_CTL_GPIO_Port, LED_CTL_Pin, false); }
//--------------------------------------------------------------------------------------------//
//
//--------------------------------------------------------------------------------------------//

bool getAudioOn(void){ return HAL_GPIO_ReadPin(AUDIO_ON_GPIO_Port, AUDIO_ON_Pin); }


/**
  * @brief  get Audio state
  */

void RF_POWN_ON(void)  { HAL_GPIO_WritePin(GPIOD, RF_POWN_EN_Pin, GPIO_PIN_SET); }
void RF_POWN_OFF(void) { HAL_GPIO_WritePin(GPIOD, RF_POWN_EN_Pin, GPIO_PIN_RESET); }


//--------------------------------------------------------------------------------------------//
//
//--------------------------------------------------------------------------------------------//
/**
  * @brief  get RS485 ID
  */
uint8_t getRS485Id(void)
{
	uint8_t id = HAL_GPIO_ReadPin(DEV_ID0_GPIO_Port, DEV_ID0_Pin);
	id |= HAL_GPIO_ReadPin(DEV_ID1_GPIO_Port, DEV_ID1_Pin) << 1;
	id |= HAL_GPIO_ReadPin(DEV_ID2_GPIO_Port, DEV_ID2_Pin) << 2;
	id |= HAL_GPIO_ReadPin(DEV_ID3_GPIO_Port, DEV_ID3_Pin) << 3;
	return id;
}
//--------------------------------------------------------------------------------------------//
//
//--------------------------------------------------------------------------------------------//
/**
  * @brief  get Charge rate state
  */
ChargeRateState getChargeRateState(void)
{
	if(getChargerDet())
		return CHARGE_RATE_100;

	if(u16BatVol < VOLTAGE_BAT_75)
		return CHARGE_RATE_75_UNDER;
	else if(u16BatVol >= VOLTAGE_BAT_75 && u16BatVol < VOLTAGE_BAT_100)
		return CHARGE_RATE_100_UNDER;
	else if(u16BatVol >= VOLTAGE_BAT_100)
		return CHARGE_RATE_100;
	else
		return CHARGE_RATE_UNKNOWN;
}
//--------------------------------------------------------------------------------------------//
//
//--------------------------------------------------------------------------------------------//
/**
  * @brief	process Override output
  */
void processOverrideOn(void)
{
    static int sDataVal = 0;
    static int sDateValRe = 0;
        
    static int sCnt = 0;
        
	setOverrideOn(uDI_getMasterIn);
        
     
    sDataVal = uDI_getMasterIn;
        
    if(sDataVal != sDateValRe)
    {
     
      sCnt++;
          
      if(sCnt > 5 )
      {
        sCnt = 0;
        sDateValRe = sDataVal;
      
      }
          
       cmd_occ(2);
         
    }
       
     
}
//--------------------------------------------------------------------------------------------//
//
//--------------------------------------------------------------------------------------------//
/**
  * @brief	process RF LED
  */
void processRfLed(void)
{
	if(getStandBy())
		rfLedOn();
	else
		rfLedOff();
}
//--------------------------------------------------------------------------------------------//
//
//--------------------------------------------------------------------------------------------//
/**
  * @brief	process Charge LED
  */
void processChargeLed(void)
{
    
    static int sTimeCnt = 0;
    
    sTimeCnt++;
    
//    if(!(sTimeCnt%5000))
//    {
//        printf( "getChargeRateState [%d],[%d] \n", getChargeRateState(),viaChargeState);
//        //u16LedChangeTick = 1000;
//    }
    
    
	ChargeRateState chargeRateState = getChargeRateState();
    
	if(viaChargeState == CHARGE_RATE_UNKNOWN)
	{
		viaChargeState = chargeRateState;
		curChargeState = chargeRateState;
	}
	else if(viaChargeState != chargeRateState)
	{
		viaChargeState = chargeRateState;
		u16LedChangeTick = 5000;
	}
    

	if(curChargeState != viaChargeState && u16LedChangeTick == 0)
    {
		curChargeState = viaChargeState;
    }

	switch(curChargeState)
	{
		case CHARGE_RATE_75_UNDER:
		{
			if(u16Led75UnderFlickerTick == 0)
			{
				u16Led75UnderFlickerTick = 500;
                
				toggleLed75();
               // HAL_GPIO_TogglePin(GPIOB, GPIO_PIN_3);
				led100RedOff();
				led100GreenOff();
                
               // MyPrintf_USART1( "CHARGE_RATE_75_UNDER \r\n");
                
			}
			break;
		}
		case CHARGE_RATE_100_UNDER:
		{
			if(u16Led100UnderFlickerTick == 0)
			{
				u16Led100UnderFlickerTick = 500;
				led75On();
				toggleLed100Red();
				led100GreenOff();
                // MyPrintf_USART1( "CHARGE_RATE_100_UNDER \r\n");
			}
			break;
		}
		case CHARGE_RATE_100:
		{
			led75Off();
			led100RedOff();
			led100GreenOn();
            
           // MyPrintf_USART1( "CHARGE_RATE_100 \r\n");
            
			break;
		}
		default:
		{
			curChargeState = CHARGE_RATE_UNKNOWN;
			led75Off();
			led100RedOff();
			led100GreenOff();
            
           // MyPrintf_USART1( "default \r\n");
            
			break;
		}
	}
}
//--------------------------------------------------------------------------------------------//
//
//--------------------------------------------------------------------------------------------//
/**
  * @brief	process Light LED
  */
void processLightLed(void)
{
    static int sCnnt = 0;
    
    static int sLedFlag = 0;
        
            
        
	if(!uDI_getMasterIn)//양산 버전. 대승객 방송이 아니라면,
    //if(uDI_getMasterIn)
	{
         sCnnt++;
             
		//	방공등 Off
		bool bLightOn = getLightOn();
         
        
        if(bLightOn != sLedFlag)
        {
        
            sLedFlag = bLightOn;
            
            if(bLightOn)
            {
                ledCtrOn();   
                
                 if(GetDbg() == 2) MyPrintf_USART1("----- ledCtrOn \r\n" ); 
                        
            }
            else
            {
                ledCtrOff();
                    
                if(GetDbg() == 2) MyPrintf_USART1("----- ledCtrOff \r\n" ); 

            }
                
            bCurLedCtr = bLightOn;
        }
            
       
        
         
            
	}
	else
	{
		//	방공등 On
		ledCtrOn();
		bCurLedCtr = true;
	}
}
//--------------------------------------------------------------------------------------------//
//
//--------------------------------------------------------------------------------------------//
/**
  * @brief	process audio amp
  */
void processAudioAmpProcess(void)
{

   // MyPrintf_USART1("%s(%d)\n\r", __func__, __LINE__ );
    
	if(getAudioOn())
	{
        
        
		bAmpOnOff = true;
		if(bCurAmpOnOff != bAmpOnOff)
		{
            //MyPrintf_USART1("getAudioOn -> bCurAmpOnOff(ON) \r\n"); 
            
			bCurAmpOnOff = bAmpOnOff;
			AMP_Init(AMP_ID_1);

			HAL_GPIO_WritePin(SD_GPIO_Port, SD_Pin, true); // SD

			u16AmpSettingTick = 100;
		}

		if(bAmpSettingDetected)
		{
			bAmpSettingDetected = false;
			AMP_Mute_OFF(AMP_ID_1, AMP_ID_2, AMP_ID_3); // 모든 채널을 ON 하고 릴레이로 제어 한다.
                
            uAudioPlayFlag = true;
		}
            
	}
	else
	{
		bAmpOnOff = false;
		if(bCurAmpOnOff != bAmpOnOff)
		{
			bCurAmpOnOff = bAmpOnOff;
			AMP_Mute_ON(AMP_ID_1, AMP_CH_All, AMP_ID_2, AMP_CH_All, AMP_ID_3, AMP_CH_All); 
			u16AmpSettingTick = 500;
                
            uAudioPlayFlag = false;
		}

		if(bAmpSettingDetected)
		{
			bAmpSettingDetected = false;
			//setAmpSd(false);

			//HAL_GPIO_WritePin(SD_GPIO_Port, SD_Pin, false); // SD
		}
	}
}
//--------------------------------------------------------------------------------------------//
//
//--------------------------------------------------------------------------------------------//
/**
  * @brief	process get battery voltage
  */
void processGetBatVol(void)
{
	u16CntBatVol++;
	uint16_t batVol = getAdc2Vol();
    
    //printf("Time-Tick --->[%d]\n", u16LedChangeTick);
    
	if(!getVccIn())
	{
		batVol-=VOLTAGE_CHARGE_BAT;
	}
	else
	{
		if(bCurLedCtr)
			batVol += VOLTAGE_LOAD_LED;
		if(getAudioOn())
			batVol += VOLTAGE_LOAD_AUDIO;
	}
    
	u16BatVolSum += batVol;
	if(u16CntBatVol >=10)
	{
		u16BatVol = u16BatVolSum / u16CntBatVol;
		u16CntBatVol = 0;
		u16BatVolSum = 0;
        
        //MyPrintf_USART1("bat----> [%d]\n", u16BatVol);
	}
}
//--------------------------------------------------------------------------------------------//
//
//--------------------------------------------------------------------------------------------//
/**
  * @brief	process Test Debug printf
  */
void processTestDebug(void)
{
	//if(u16CntBatVol == 1)	// cycle 1 sec
	//{
		MyPrintf_USART1("getChargerDet():%d\n\r", getChargerDet());
		MyPrintf_USART1("u16BatVol:%d\n\r", u16BatVol);
		MyPrintf_USART1("getVccIn():%d\n\r", getVccIn());
		MyPrintf_USART1("getRS485Id():%d\n\r", getRS485Id());
		MyPrintf_USART1("getMasterIn():%d\n\r", getMasterIn());
		MyPrintf_USART1("getDICtl():%d\n\r", getDICtl());
		MyPrintf_USART1("getOverrideOn():%d\n\r", getOverrideOn());
		MyPrintf_USART1("getStandBy():%d\n\r", getStandBy());
        MyPrintf_USART1("getVccLedIn():%d\n\r", getVccLedIn());
        MyPrintf_USART1("getVccAudioIn():%d\n\r", getVccAudioIn());
        MyPrintf_USART1("getVccRfIn():%d\n\r", getVccRfIn());
        
	//}
}


//--------------------------------------------------------------------------------------------//
//
//--------------------------------------------------------------------------------------------//
/*****************************************************************************
* @brief - 
* @param -
* @retval-
******************************************************************************/


void ONTD_Function(void)
{
    static int sMasterCnt = 0;
        
    ONTD(getMasterIn(),&uDI_getMasterIn,3,&sMasterCnt);
           
}



/*****************************************************************************
* @brief - 
* @param -
* @retval-
******************************************************************************/
void ONTD(uint8_t IN,uint8_t *OUT,uint8_t MS,int *CLK )
{
	uint8_t CE;
	
	if(!IN){*CLK = 0; *OUT = 0;}		
	CE = NOT(*OUT) && IN;	
	if(CE)
	{
		if(MS == *CLK) {*OUT = 1;}
		else *CLK = *CLK+1;
	}
}
  
      