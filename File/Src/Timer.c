

/*
    ******************************************************************************
    * @Company              : Woojin Industrial Systems Co., Ltd.
    * @Engineer             : D.S.JANG
    * @ModuleName           : Timer.c
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
#include "Timer.h"
#include "LED.h"
#include "Flash.h"
#include "main.h"
#include "spi_flash.h"
#include "CharLCD.h"

#include "test.h"


 TIM_HandleTypeDef TimHandle3,TimHandle4,TimHandle5,TimHandle8;
	
 TIM_OC_InitTypeDef Tim3Pwm,Tim8Pwm;
	
	
    uint32_t nTime_Flage = 0;
    uint32_t nTime_Flage_1ms = 0;
    uint32_t nTime_Flage_100us = 0;
    uint32_t nLedPrintf_Flag = 0;
	
    uint32_t nLcdPrintf_Cnt = 0;
	



/*****************************************************************************
   Initialize TIM3 peripheral as follow:
       + Period = 10000 - 1
       + Prescaler = ((SystemCoreClock/2)/10000) - 1          
       + ClockDivision = 0
       + Counter direction = Up
       + TIM1 , 9 , 10, 11 번은 최대 168MHZ
       + TIM 2,3,4,5 12,13,14, 6,7 최대 84MHZ 
       + 따라서 클럭 속도 계산 식도 다르다.
       + 타이머 속도는 = 1/(SystemCoreClock / Period / Prescaler );
       
   Time               Period        Prescaler
   1000(500)ms       10000-1       ((SystemCoreClock /2)/10000) - 1    
   100(50)  ms       10000-1       ((SystemCoreClock /2)/100000) - 1
   10(5)    ms       10000-1       ((SystemCoreClock /2)/1000000) - 1(84)
   1000(500)us       10000-1       ((SystemCoreClock /2)/10000000) - 1(7)
   100(50)  us       1000 -1       ((SystemCoreClock /2)/10000000) - 1 (7)
   10(5)    us       100-1         ((SystemCoreClock /2)/10000000) - 1 (7)
 //1000ns  10-1          ((SystemCoreClock /2)/10000000) - 1 (7)
******************************************************************************/
    uint32_t uwPrescalerValue_Time3 = 0;
    uint32_t uwPrescalerValue_Time4 = 0;
	uint32_t uwPrescalerValue_Time5 = 0;
	uint32_t uwPrescalerValue_Time8 = 0;

void Timer_init(void)
{

/************************************TIM4***********************************************************/    
    //TIM4은 최대 84MHz 이므로 속도 값이 더 작다.(1ms)
    /* Compute the prescaler value to have TIM3 counter clock equal to 10 KHz */
    //uwPrescalerValue_Time4 = (uint32_t) ((SystemCoreClock/2)/10000000) - 1;

    /* Set TIMx instance */
    TimHandle4.Instance = TIM4;

    TimHandle4.Init.Period = 10000-1;
    TimHandle4.Init.Prescaler = (uint32_t) ((SystemCoreClock/2)/10000000) - 1;;
    TimHandle4.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
    TimHandle4.Init.CounterMode = TIM_COUNTERMODE_UP;

    HAL_TIM_Base_Init(&TimHandle4);
    
    HAL_TIM_Base_Start_IT(&TimHandle4);
	
    
    HAL_Delay( 500 );
	
/*****************************TIM5******************************************************************/
	 //TIM5는 최대 84MHZ 이므로 속도 값이 크다.()
    /* Compute the prescaler value to have TIM3 counter clock equal to 10 KHz */
    //uwPrescalerValue_Time5 = (uint32_t) ((SystemCoreClock /2)/10000000) - 1;

    /* Set TIMx instance */

    TimHandle5.Instance = TIM5;

    TimHandle5.Init.Period = 1000-1; //주기.
    TimHandle5.Init.Prescaler = (uint32_t) ((SystemCoreClock/2)/10000000) - 1;;
    TimHandle5.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
    TimHandle5.Init.CounterMode = TIM_COUNTERMODE_UP;

    HAL_TIM_Base_Init(&TimHandle5);
    HAL_TIM_Base_Start_IT(&TimHandle5);
	
	
/**********************TIM8*************************************************************************/   	
	
// //TIM8는 최대 84MHZ 이므로 속도 값이 크다.(500ms)
//    /* Compute the prescaler value to have TIM3 counter clock equal to 10 KHz */
//    uwPrescalerValue_Time8 = (uint32_t) ((SystemCoreClock)/10000000) - 1;

//    /* Set TIMx instance */
//    TimHandle8.Instance = TIM8;

//    TimHandle8.Init.Period = 1000-1; //주기.
//    TimHandle8.Init.Prescaler = uwPrescalerValue_Time8; //분주
//    TimHandle8.Init.ClockDivision = 0;
//    TimHandle8.Init.CounterMode = TIM_COUNTERMODE_UP;
//	TimHandle8.Init.RepetitionCounter = 0;
//	
//	HAL_TIM_PWM_Init(&TimHandle8);
//	
////    HAL_TIM_Base_Init(&TimHandle3);
////    HAL_TIM_Base_Start_IT(&TimHandle3);


}


/*****************************************************************************
* @brief - 100 micro  타이머 
* @param -
* @retval-
******************************************************************************/

void TIM3_IRQHandler(void)
{
    //HAL_TIM_IRQHandler(&TimHandle3);
  

}


/*****************************************************************************
* @brief - 1ms 타이머 
* @param -
* @retval-
******************************************************************************/
void TIM4_IRQHandler(void)
{
    HAL_TIM_IRQHandler(&TimHandle4);

}


/*****************************************************************************
* @brief - 100 micro 타이머 
* @param -
* @retval-
******************************************************************************/
void TIM5_IRQHandler(void)
{
    HAL_TIM_IRQHandler(&TimHandle5);

}


/*****************************************************************************
* @brief - 타이머 인터럽트 함수
* @param -
* @retval-
******************************************************************************/
int dTimerCnt4 = 0;


void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{

    if (htim->Instance == TIM3) // 100us
    {
		
		
		
    }  	
    else if(htim->Instance == TIM4) //1ms
    {
	    Time_Main();
	    Flash_TIM();
        
        USART_TIM();
        
	    //LED_Timer_1ms(); // LED 1ms  타이커,
        //SPI_FLASH_Timer_1ms();
        //lcd_Timer();
        
       
	    nTime_Flage_1ms++;
        
        
        if(!(nTime_Flage_1ms%10000))
        {
          //nTime_Flage = 1;
        }
            
        if(!(nTime_Flage_1ms%1000))
        {
            //MyPrintf_USART1("===========TIM4 Tim s: %d \n\r",HAL_GetTick());
            
            
            
        }

    }
    else if(htim->Instance == TIM5) //100 us
    {
            
            nTime_Flage_100us++;
            

            if(!(nTime_Flage_100us%1000))
            {
                
                
                    //MyPrintf_USART1("TIM5 : %d \n\r",HAL_GetTick());
                    //nLedPrintf_Flag = 1;
                    // LED_init(); // LED 디스 플레이 함수.
                
                    //OLED_Print(); // 약 350ms 필요.
            }

            
    }
    
    
}

/*****************************************************************************
* @brief - 타이머 인터럽트 함수
* @param -
* @retval-
******************************************************************************/

static void Timer_Error_Handler(void)
{
  /* Turn LED5 on */
  while(1)
  {
  }
}





