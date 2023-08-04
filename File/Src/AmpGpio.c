

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





/*****************************************************************************
* @brief - RTC 현재 시간을 설정하는 부분.
* @param -
* @retval-
******************************************************************************/

// LED GPIO OFF --> 점등 /  GPIO ON --> OFF
void setRSP_Led(bool state)     
{ 
  // if(state == false){HAL_GPIO_WritePin(RSP_LED_Port, RSP_LED_Pin, true); }
  //  else if(state == true){HAL_GPIO_WritePin(RSP_LED_Port, RSP_LED_Pin, false);}
}


void setOSP_Led(bool state)     
{ 
  //  if(state == false){HAL_GPIO_WritePin(OSP_LED_Port, OSP_LED_Pin, true); }
  //  else if(state == true){HAL_GPIO_WritePin(OSP_LED_Port, OSP_LED_Pin, false);}
    
} 



void setAMP_Standby(bool state)
{ 
	HAL_GPIO_WritePin(AMP_STANDBY_Port, AMP_STANDBY, state); 
	HAL_GPIO_WritePin(AMP_STANDBY_Port, AMP_STANDBY, state); 

}



//릴레이 접점은 GPIO OFF --> 소리 출력 / GPIO ON --> 소리 CUT

// setBk_Out_1(true) : 소리를 출력 한다.
void setBk_Out_1(bool state)    
{ 
    
//    if(state == false) 
//    {
//	   // HAL_GPIO_WritePin(BK_OUT1_Port, BK_OUT1_Pin, true); 
//	   // HAL_GPIO_WritePin(BK_OUT1_Port, BK_OUT1_Pin, true); 
//    }
//    else if(state == true) 
//    {
//	   // HAL_GPIO_WritePin(BK_OUT1_Port, BK_OUT1_Pin, false); 
//	  // HAL_GPIO_WritePin(BK_OUT1_Port, BK_OUT1_Pin, false); 
//    }
}


void setBk_Out_2(bool state)    
{ 
//    if(state == false) 
//    {
//	    HAL_GPIO_WritePin(BK_OUT2_Port, BK_OUT2_Pin, true); 
//	    HAL_GPIO_WritePin(BK_OUT2_Port, BK_OUT2_Pin, true); 
//    }
//    else if(state == true) 
//    {
//	    HAL_GPIO_WritePin(BK_OUT2_Port, BK_OUT2_Pin, false); 
//	    HAL_GPIO_WritePin(BK_OUT2_Port, BK_OUT2_Pin, false); 
//    }
}



void setBk_Out_3(bool state)    
{ 
//    if(state == false) 
//    {
//	    HAL_GPIO_WritePin(BK_OUT3_Port, BK_OUT3_Pin, true); 
//	    HAL_GPIO_WritePin(BK_OUT3_Port, BK_OUT3_Pin, true); 
//    }
//    else if(state == true) 
//    {
//	    HAL_GPIO_WritePin(BK_OUT3_Port, BK_OUT3_Pin, false); 
//	    HAL_GPIO_WritePin(BK_OUT3_Port, BK_OUT3_Pin, false); 
//    }
}


void setBk_Out_4(bool state)    
{ 
//    if(state == false) 
//    {
//	    HAL_GPIO_WritePin(BK_OUT4_Port, BK_OUT4_Pin, true); 
//	    HAL_GPIO_WritePin(BK_OUT4_Port, BK_OUT4_Pin, true); 
//    }
//    else if(state == true) 
//    {
//	    HAL_GPIO_WritePin(BK_OUT4_Port, BK_OUT4_Pin, false); 
//	    HAL_GPIO_WritePin(BK_OUT4_Port, BK_OUT4_Pin, false); 
//    }
}


void setBk_Out_5(bool state)    
{ 
//    if(state == false) 
//    {
//	    HAL_GPIO_WritePin(BK_OUT5_Port, BK_OUT5_Pin, true); 
//	    HAL_GPIO_WritePin(BK_OUT5_Port, BK_OUT5_Pin, true); 
//    }
//    else if(state == true) 
//    {
//	    HAL_GPIO_WritePin(BK_OUT5_Port, BK_OUT5_Pin, false); 
//	    HAL_GPIO_WritePin(BK_OUT5_Port, BK_OUT5_Pin, false); 
//    }
    
}


void setBk_Out_6(bool state)    
{ 
//    if(state == false) 
//    {
//	    HAL_GPIO_WritePin(BK_OUT6_Port, BK_OUT6_Pin, true); 
//	    HAL_GPIO_WritePin(BK_OUT6_Port, BK_OUT6_Pin, true); 
//    }
//    else if(state == true) 
//    {
//	    HAL_GPIO_WritePin(BK_OUT6_Port, BK_OUT6_Pin, false); 
//	    HAL_GPIO_WritePin(BK_OUT6_Port, BK_OUT6_Pin, false); 
//    }
    
}





















