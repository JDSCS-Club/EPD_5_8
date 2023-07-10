 /*
    ******************************************************************************
    * @Company              : Woojin Industrial Systems Co., Ltd.
    * @Engineer             : D.S.JANG
    * @ModuleName           : Main.h
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
#ifndef __AMPGPIO_H
#define __AMPGPIO_H

#ifdef __cplusplus
 extern "C" {
#endif
  

#include "stm32f4xx_hal.h"
     
     


// INT PUT
#define ANS_OUT_Pin                 GPIO_PIN_0
#define ANS_OUT_Port                GPIOA


#define AMP1_PAULT_Pin               GPIO_PIN_2
#define AMP1_PAULT_Port              GPIOD




#define AMP2_PAULT_Pin               GPIO_PIN_3
#define AMP2_PAULT_Port              GPIOD


#define AMP3_PAULT_Pin               GPIO_PIN_4
#define AMP3_PAULT_Port              GPIOD


     
#define SW_RS_Pin                    GPIO_PIN_10
#define SW_RS_Port                   GPIOE



#define SW_SL_Pin                    GPIO_PIN_11
#define SW_SL_Port                   GPIOE



#define SW_SR_Pin                    GPIO_PIN_12
#define SW_SR_Port                   GPIOE



#define SW_AR_Pin                    GPIO_PIN_13
#define SW_AR_Port                   GPIOE



#define SW_BROAD_Pin                 GPIO_PIN_14
#define SW_BROAD_Port                GPIOE


// OUT PUT


#define RSP_LED_Pin                GPIO_PIN_0
#define RSP_LED_Port               GPIOD



#define OSP_LED_Pin                GPIO_PIN_1
#define OSP_LED_Port               GPIOD


#define AMP_STANDBY_Pin           GPIO_PIN_7
#define AMP_STANDBY_Port          GPIOD



#define BK_OUT1_Pin                GPIO_PIN_8
#define BK_OUT1_Port               GPIOD



#define BK_OUT2_Pin                GPIO_PIN_9
#define BK_OUT2_Port               GPIOD



#define BK_OUT3_Pin                GPIO_PIN_10
#define BK_OUT3_Port               GPIOD




#define BK_OUT4_Pin                GPIO_PIN_11
#define BK_OUT4_Port               GPIOD




#define BK_OUT5_Pin                GPIO_PIN_12
#define BK_OUT5_Port               GPIOD



#define BK_OUT6_Pin                GPIO_PIN_13
#define BK_OUT6_Port               GPIOD




#define AMP_Mute1_Pin               GPIO_PIN_14
#define AMP_Mute1_Port              GPIOD



#define AMP_Mute2_Pin                GPIO_PIN_15
#define AMP_Mute2_Port               GPIOD


bool getAmp1_Pault(void);        
bool getAmp2_Pault(void);        
bool getAmp3_Pault(void);        
bool getSW_RS(void);             
bool getSW_SL(void);            
bool getSW_SR(void);             
bool getSW_AR(void);            
bool getSW_Broad(void);         
    



void setRSP_Led(bool state);     
void setOSP_Led(bool state) ;   
void setAMP_Standby(bool state);
void setBk_Out_1(bool state);   
void setBk_Out_2(bool state);    
void setBk_Out_3(bool state);   
void setBk_Out_4(bool state);    
void setBk_Out_5(bool state);   
void setBk_Out_6(bool state);    
void setAmp_Mute_1(bool state);
void setAmp_Mute_2(bool state); 



#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */


/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
     
     
     