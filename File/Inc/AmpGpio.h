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
     
     

///* Private defines -----------------------------------------------------------*/
//     
//#define SD_Pin                          GPIO_PIN_3
//#define SD_GPIO_Port                    GPIOE
//#define LED_CTL_Pin                     GPIO_PIN_4
//#define LED_CTL_GPIO_Port               GPIOE   
//#define MASTER_IN_Pin 			        GPIO_PIN_5
//#define MASTER_IN_GPIO_Port 	        GPIOE
//#define DI_CTL_Pin                      GPIO_PIN_6
//#define DI_CTL_GPIO_Port                GPIOE  
//     
//     
//#define VCC_AUDIO_IN                    GPIO_PIN_13
//#define VCC_AUDIO_IN_Port               GPIOC
//#define VCC_LED_IN                      GPIO_PIN_14
//#define VCC_LED_IN_Port                 GPIOC
//#define CHARGER_DET_Pin 		        GPIO_PIN_15
//#define CHARGER_DET_GPIO_Port 	        GPIOC
//#define BAT_VCC_Pin 			        GPIO_PIN_0
//#define BAT_VCC_GPIO_Port               GPIOC
//     
//     
// 
//#define LED_75_Pin                      GPIO_PIN_10
//#define LED_75_GPIO_Port                GPIOD
//#define RF_LED_Pin                      GPIO_PIN_11
//#define RF_LED_GPIO_Port                GPIOD
//#define LED_100_RED_Pin                 GPIO_PIN_12
//#define LED_100_RED_GPIO_Port           GPIOD
//#define LED_100_GREEN_Pin               GPIO_PIN_13
//#define LED_100_GREEN_GPIO_Port         GPIOD
//#define LIGHT_ON_Pin                    GPIO_PIN_15
//#define LIGHT_ON_GPIO_Port              GPIOD
//     
//     
//     
//     
//#define ST_BY_Pin                       GPIO_PIN_8
//#define ST_BY_GPIO_Port                 GPIOC
//#define POP_UP_Pin                      GPIO_PIN_9
//#define POP_UP_GPIO_Port                GPIOC
//     
//     
//#define AUDIO_ON_Pin                    GPIO_PIN_8
//#define AUDIO_ON_GPIO_Port              GPIOA     
//#define OVERRIDE_Pin                    GPIO_PIN_11
//#define OVERRIDE_GPIO_Port              GPIOA
//#define NTC_Pin 			            GPIO_PIN_12
//#define NTC_GPIO_Port 			        GPIOA
//     
//   //  
//#define VCC_RF_IN                       GPIO_PIN_0
//#define VCC_RF_IN_Port                  GPIOD
//#define AMP_STANDBY                     GPIO_PIN_1  //AMP STANDBY Pin
//#define AMP_STANDBY_Port                GPIOD
//#define AMP_FAULT                       GPIO_PIN_2
//#define AMP_FAULT_Port                  GPIOD   
//     
//     
//#define VCC_IN_Pin 			            GPIO_PIN_1
//#define VCC_IN_GPIO_Port 		        GPIOE
//     
//     
//     
//     
//#define DEV_ID3_Pin                     GPIO_PIN_4
//#define DEV_ID3_GPIO_Port               GPIOA
//#define DEV_ID2_Pin                     GPIO_PIN_10
//#define DEV_ID2_GPIO_Port               GPIOC
//#define DEV_ID1_Pin                     GPIO_PIN_11
//#define DEV_ID1_GPIO_Port               GPIOC
//#define DEV_ID0_Pin                     GPIO_PIN_12
//#define DEV_ID0_GPIO_Port               GPIOC
//     
//     
//#define SCL1_Pin                        GPIO_PIN_8
//#define I2C1_GPIO_Port                  GPIOB
//#define SDA1_Pin                        GPIO_PIN_9
//#define I2C1_GPIO_Port                  GPIOB    
//     
//
//#define PHY_RST                         GPIO_PIN_7
//#define PHY_RST_Port                    GPIOE
//#define PHY_PWR_INT                     GPIO_PIN_8
//#define PHY_PWR_INT_Port                GPIOE
//    
//     
//     



//#define RE_Pin                          GPIO_PIN_3
//#define RE_GPIO_Port                    GPIOC
//#define RE1_Pin                         GPIO_PIN_0
//#define RE1_GPIO_Port                   GPIOA

















     
     
///////////////////////////////////////////////////////////////////////////
//// INT PUT
//#define ANS_OUT_Pin                 GPIO_PIN_0
//#define ANS_OUT_Port                GPIOA
//
//
//#define AMP1_PAULT_Pin               GPIO_PIN_2
//#define AMP1_PAULT_Port              GPIOD
//
//
//
//
//#define AMP2_PAULT_Pin               GPIO_PIN_3
//#define AMP2_PAULT_Port              GPIOD
//
//
//#define AMP3_PAULT_Pin               GPIO_PIN_4
//#define AMP3_PAULT_Port              GPIOD
//
//
//     
//#define SW_RS_Pin                    GPIO_PIN_10
//#define SW_RS_Port                   GPIOE
//
//
//
//#define SW_SL_Pin                    GPIO_PIN_11
//#define SW_SL_Port                   GPIOE
//
//
//
//#define SW_SR_Pin                    GPIO_PIN_12
//#define SW_SR_Port                   GPIOE
//
//
//
//#define SW_AR_Pin                    GPIO_PIN_13
//#define SW_AR_Port                   GPIOE
//
//
//
//#define SW_BROAD_Pin                 GPIO_PIN_14
//#define SW_BROAD_Port                GPIOE
//
//
//// OUT PUT
//
//
//#define RSP_LED_Pin                GPIO_PIN_0
//#define RSP_LED_Port               GPIOD
//
//
//
//#define OSP_LED_Pin                GPIO_PIN_
//#define OSP_LED_Port               GPIOD
//
//
//#define AMP_STANDBY_Pin           GPIO_PIN_1
//#define AMP_STANDBY_Port          GPIOD
//
//
//
//#define BK_OUT1_Pin                GPIO_PIN_8
//#define BK_OUT1_Port               GPIOD
//
//
//
//#define BK_OUT2_Pin                GPIO_PIN_9
//#define BK_OUT2_Port               GPIOD
//
//
//
//#define BK_OUT3_Pin                GPIO_PIN_10
//#define BK_OUT3_Port               GPIOD
//
//
//
//
//#define BK_OUT4_Pin                GPIO_PIN_11
//#define BK_OUT4_Port               GPIOD
//
//
//
//
//#define BK_OUT5_Pin                GPIO_PIN_12
//#define BK_OUT5_Port               GPIOD
//
//
//
//#define BK_OUT6_Pin                GPIO_PIN_13
//#define BK_OUT6_Port               GPIOD
//
//
//
//
//#define AMP_Mute1_Pin               GPIO_PIN_14
//#define AMP_Mute1_Port              GPIOD
//
//
//
//#define AMP_Mute2_Pin                GPIO_PIN_15
//#define AMP_Mute2_Port               GPIOD
//     
    



#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */


/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
     
     
     