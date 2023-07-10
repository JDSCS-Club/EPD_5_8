

/*
    ******************************************************************************
    * @Company              : Woojin Industrial Systems Co., Ltd.
    * @Engineer             : D.S.JANG
    * @ModuleName           : Main.c
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



#include "main.h"
#include "AmpGpio.h"



/*****************************************************************************
* @brief - RTC 현재 시간을 설정하는 부분.
* @param -
* @retval-
******************************************************************************/

bool getAmp1_Pault(void)        { return HAL_GPIO_ReadPin(AMP1_PAULT_Port, AMP1_PAULT_Pin); }
bool getAmp2_Pault(void)        { return HAL_GPIO_ReadPin(AMP2_PAULT_Port, AMP2_PAULT_Pin); }
bool getAmp3_Pault(void)        { return HAL_GPIO_ReadPin(AMP3_PAULT_Port, AMP3_PAULT_Pin); }

bool getSW_RS(void)             { return (HAL_GPIO_ReadPin(SW_RS_Port, SW_RS_Pin) == true ? false : true); }
bool getSW_SL(void)             { return (HAL_GPIO_ReadPin(SW_SL_Port, SW_SL_Pin) == true ? false : true); }
bool getSW_SR(void)             { return (HAL_GPIO_ReadPin(SW_SR_Port, SW_SR_Pin) == true ? false : true); }
bool getSW_AR(void)             { return (HAL_GPIO_ReadPin(SW_AR_Port, SW_AR_Pin) == true ? false : true); }
bool getSW_Broad(void)          { return (HAL_GPIO_ReadPin(SW_BROAD_Port, SW_BROAD_Pin) == true ? false : true); }



/*****************************************************************************
* @brief - RTC 현재 시간을 설정하는 부분.
* @param -
* @retval-
******************************************************************************/

// LED GPIO OFF --> 점등 /  GPIO ON --> OFF
void setRSP_Led(bool state)     
{ 
    if(state == false){HAL_GPIO_WritePin(RSP_LED_Port, RSP_LED_Pin, true); }
    else if(state == true){HAL_GPIO_WritePin(RSP_LED_Port, RSP_LED_Pin, false);}
}


void setOSP_Led(bool state)     
{ 
    if(state == false){HAL_GPIO_WritePin(OSP_LED_Port, OSP_LED_Pin, true); }
    else if(state == true){HAL_GPIO_WritePin(OSP_LED_Port, OSP_LED_Pin, false);}
    
} 



void setAMP_Standby(bool state)
{ 
	HAL_GPIO_WritePin(AMP_STANDBY_Port, AMP_STANDBY_Pin, state); 
	HAL_GPIO_WritePin(AMP_STANDBY_Port, AMP_STANDBY_Pin, state); 

}



//릴레이 접점은 GPIO OFF --> 소리 출력 / GPIO ON --> 소리 CUT

// setBk_Out_1(true) : 소리를 출력 한다.
void setBk_Out_1(bool state)    
{ 
    
    if(state == false) 
    {
	    HAL_GPIO_WritePin(BK_OUT1_Port, BK_OUT1_Pin, true); 
	    HAL_GPIO_WritePin(BK_OUT1_Port, BK_OUT1_Pin, true); 
    }
    else if(state == true) 
    {
	    HAL_GPIO_WritePin(BK_OUT1_Port, BK_OUT1_Pin, false); 
	    HAL_GPIO_WritePin(BK_OUT1_Port, BK_OUT1_Pin, false); 
    }
}


void setBk_Out_2(bool state)    
{ 
    if(state == false) 
    {
	    HAL_GPIO_WritePin(BK_OUT2_Port, BK_OUT2_Pin, true); 
	    HAL_GPIO_WritePin(BK_OUT2_Port, BK_OUT2_Pin, true); 
    }
    else if(state == true) 
    {
	    HAL_GPIO_WritePin(BK_OUT2_Port, BK_OUT2_Pin, false); 
	    HAL_GPIO_WritePin(BK_OUT2_Port, BK_OUT2_Pin, false); 
    }
}



void setBk_Out_3(bool state)    
{ 
    if(state == false) 
    {
	    HAL_GPIO_WritePin(BK_OUT3_Port, BK_OUT3_Pin, true); 
	    HAL_GPIO_WritePin(BK_OUT3_Port, BK_OUT3_Pin, true); 
    }
    else if(state == true) 
    {
	    HAL_GPIO_WritePin(BK_OUT3_Port, BK_OUT3_Pin, false); 
	    HAL_GPIO_WritePin(BK_OUT3_Port, BK_OUT3_Pin, false); 
    }
}


void setBk_Out_4(bool state)    
{ 
    if(state == false) 
    {
	    HAL_GPIO_WritePin(BK_OUT4_Port, BK_OUT4_Pin, true); 
	    HAL_GPIO_WritePin(BK_OUT4_Port, BK_OUT4_Pin, true); 
    }
    else if(state == true) 
    {
	    HAL_GPIO_WritePin(BK_OUT4_Port, BK_OUT4_Pin, false); 
	    HAL_GPIO_WritePin(BK_OUT4_Port, BK_OUT4_Pin, false); 
    }
}


void setBk_Out_5(bool state)    
{ 
    if(state == false) 
    {
	    HAL_GPIO_WritePin(BK_OUT5_Port, BK_OUT5_Pin, true); 
	    HAL_GPIO_WritePin(BK_OUT5_Port, BK_OUT5_Pin, true); 
    }
    else if(state == true) 
    {
	    HAL_GPIO_WritePin(BK_OUT5_Port, BK_OUT5_Pin, false); 
	    HAL_GPIO_WritePin(BK_OUT5_Port, BK_OUT5_Pin, false); 
    }
    
}


void setBk_Out_6(bool state)    
{ 
    if(state == false) 
    {
	    HAL_GPIO_WritePin(BK_OUT6_Port, BK_OUT6_Pin, true); 
	    HAL_GPIO_WritePin(BK_OUT6_Port, BK_OUT6_Pin, true); 
    }
    else if(state == true) 
    {
	    HAL_GPIO_WritePin(BK_OUT6_Port, BK_OUT6_Pin, false); 
	    HAL_GPIO_WritePin(BK_OUT6_Port, BK_OUT6_Pin, false); 
    }
    
}



void setAmp_Mute_1(bool state)  
{ 
    HAL_GPIO_WritePin(AMP_Mute1_Port, AMP_Mute1_Pin, state); 
    HAL_GPIO_WritePin(AMP_Mute1_Port, AMP_Mute1_Pin, state); 
}

void setAmp_Mute_2(bool state)  
{ 
    HAL_GPIO_WritePin(AMP_Mute2_Port, AMP_Mute2_Pin, state); 
    HAL_GPIO_WritePin(AMP_Mute2_Port, AMP_Mute2_Pin, state); 
}


















