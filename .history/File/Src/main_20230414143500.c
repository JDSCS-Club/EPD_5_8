
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
#include "lwip/opt.h"
#include "lwip/init.h"
#include "lwip/netif.h"
#include "lwip/timeouts.h"
#include "lwip/debug.h"
#include "lwip/udp.h"

#include "lwip/igmp.h"

#include "netif/etharp.h"
#include "ethernetif.h"
#include "app_ethernet.h"
#include "tcp_echoserver.h"
#include "udp_echoclient.h"
#include "lwip/debug.h"
#include "lwip/udp.h"


#include "AmpGpio.h"
#include "LED.h"
#include "Timer.h"
#include "USRAT.h"

#include "spi_flash.h"
#include "WWDG.h"

#include "build_defs.h"

#include "CRC8.h"


#include "debug_task.h"


#include "Flash.h"

#include "test.h"


//#include "CharLCD.h"

#ifdef USE_LCD
#include "lcd_log.h"
#endif



/* Private typedef -----------------------------------------------------------*/
uint8_t mEtherNetRx_Flag = 0;

uint32_t m_Main_TIM_Cnt = 0;
uint32_t m_Main_TIM_Cnt_Reset = 0;

uint8_t IP_ADDR1_INPUT_DATA; // TRAIN CAR NUM
uint8_t IP_ADDR2_INPUT_DATA; // UNIT NUM
//uint8_t IP_ADDR3_INPUT_DATA;
//uint8_t IP_ADDR4_INPUT_DATA;

    
uint32_t IP_ADDR_VAL_DATA; // MAC Address 를 설정 하는 변수.
   
    
uint8_t mTimerFlag_10s = 0; // 10초 타이머 플레그
    
    

/* Private define ------------------------------------------------------------*/



/* Private macro -------------------------------------------------------------*/

/* Private variables ---------------------------------------------------------*/
struct netif gnetif;


pmETHERNET_RX_STRUCT pmEthernet_Rx_struct;
mETHERNET_TX_STRUCT mEthernet_Tx_struct;


mLED_PROCESS_Flag mLed_Process_Flag;



/* Private function prototypes -----------------------------------------------*/
static void SystemClock_Config(void);
static void BSP_Config(void);
static void Netif_Config(void);
    

    
    
/* Private function prototypes -----------------------------------------------*/
static void RTC_AlarmInit(void);
static void RTC_AlarmConfig(void);
static void RTC_SetTimeConfig(void);
static void RTC_TimeShow(uint8_t* showtime);
    
    
    
void MX_ADC1_Init(void);
void MX_ADC3_Init(void);
void MX_ADC_DMA_Init(void);


    
    
RTC_DateTypeDef  sdatestructure; //날짜 설정을 한다.
RTC_TimeTypeDef  stimestructure; //시간 설정을 한다.
RTC_AlarmTypeDef salarmstructure; //알람 설정을 한다.


RTC_DateTypeDef sdatestructureget; // 날짜 정보를 읽어 온다.
RTC_TimeTypeDef stimestructureget; // 시간 정보를 읽어 온다.

uint8_t mAlarmAEventCallback_Flag = 5;


uint8_t mDI_CheckFlag = 0;


/* Private functions ---------------------------------------------------------*/
        /* RTC handler declaration */
RTC_HandleTypeDef RtcHandle;
/* Buffer used for displaying Time */
uint8_t aShowTime[50] = { "ttttTimer Count :" };

//  I2C_HandleTypeDef hi2c1;
//  I2C_HandleTypeDef hi2c2;
    
ADC_HandleTypeDef AdcHandle1;  
DMA_HandleTypeDef hdma_adc1;


ADC_HandleTypeDef AdcHandle3;
DMA_HandleTypeDef hdma_adc3;
    
    
__IO uint16_t uhADCxConvertedValue = 0;

__IO uint16_t uhADCxConvertedValue_Cnt = 0;

__IO uint16_t ADCValue1[6];
__IO uint16_t ADCValue3[6];
__IO uint16_t ANS_AdcCH1_Data;
__IO uint16_t ANS_AdcCH2_Data;
__IO uint16_t ANS_AdcCPU_Data;

AnsSetFlag mAnsSetFlag;

    
    


/**
  * @brief  Main program
  * @param  None
  * @retval None
  */
  
//int dEtherBuf[200];

uint8_t aTestBuf[200];
    


char mLCDPrintBuf[4][128];

char mLCDPrintBuf_2[2][128];

/*****************************************************************************
* @brief - RTC ?袁⑹삺 ??뮄而?????끉?젟??꼶?뮉 ?겫???겫?
* @param -
* @retval-
******************************************************************************/   
const unsigned char completeVersion[] =
{
	'V',
	VERSION_MAJOR_INIT,
	'.',
	VERSION_MINOR_INIT,
	'.',
	VERSION__REVISION_INIT,
	//'-','T',
	//BUILD_HOUR_CH0, BUILD_HOUR_CH1,
    
	//BUILD_MIN_CH0, BUILD_MIN_CH1,
    
	//BUILD_SEC_CH0, BUILD_SEC_CH1,
	//' ',' ',' ',' ',' ',' ',
	'\0'
};

/*****************************************************************************
* @brief - RTC ?袁⑹삺 ??뮄而?????끉?젟??꼶?뮉 ?겫???겫?
* @param -
* @retval-
******************************************************************************/
const unsigned char completeVersionBuild[] = 
{
	'B',
	BUILD_YEAR_CH2,
	BUILD_YEAR_CH3,
   
	BUILD_MONTH_CH0,
	BUILD_MONTH_CH1,
   
	BUILD_DAY_CH0,
	BUILD_DAY_CH1,
	//'-','T',
	//BUILD_HOUR_CH0, BUILD_HOUR_CH1,
    
	//BUILD_MIN_CH0, BUILD_MIN_CH1,
    
	//BUILD_SEC_CH0, BUILD_SEC_CH1,
	//' ',' ',' ',' ',' ',' ',
	'\0'
    
};


/*****************************************************************************
* @brief - RTC ?袁⑹삺 ??뮄而?????끉?젟??꼶?뮉 ?겫???겫?
* @param -
* @retval-
******************************************************************************/
void PRINT_SYSLOG(char *format, ...)
{
    
    udp_SysLog(format);
    
}


/*****************************************************************************
* @brief - RTC ?袁⑹삺 ??뮄而?????끉?젟??꼶?뮉 ?겫???겫?
* @param -
* @retval-
******************************************************************************/

int d_TestSp_RS_Flag = 0;
int d_TestSp_AR_Flag = 0;
int d_TestSp_SL_Flag = 0;
int d_TestSp_SR_Flag = 0;
    
int main(void)
{
    
    uint8_t     nRbuf[10]; 
	
	/* STM32F4xx HAL library initialization:
	   - Configure the Flash prefetch, instruction and Data caches
	   - Configure the Systick to generate an interrupt each 1 msec

	   - Set NVIC Group Priority to 4
	   - Global MSP (MCU Support Package) initialization
	 */
    

	HAL_Init();  
    
    //HAL_Delay(400);

	/* Configure the system clock to 168 MHz */
	SystemClock_Config();

    
    //HAL_Delay(600);
	/* Configure the BSP */
	BSP_Config();

    
    //HAL_Delay(600);
	/* Initialize the LwIP stack */
	lwip_init();

    
   // HAL_Delay(600);
	/* Configure the Network interface */
	Netif_Config();

	/* tcp echo server Init */
	//tcp_echoserver_init();

   // HAL_Delay(600);
    
	/* Notify user about the network interface config */
	User_notification(&gnetif);


	Timer_init(); 

	USRAT_init();

    
	MX_I2C1_Init();
    MX_I2C1_Init();
    
	//MX_I2C2_Init();
   // MX_I2C2_Init();

    
    I2C_HAL_ReadBytes(&hi2c1,0x48,0x00,(uint8_t *)nRbuf,2);
    
    
//        if(I2C_HAL_WriteBytes(&hi2c1,0x48,0x00,(uint8_t *)nRbuf,2))
//        {
//            MyPrintf_USART1("++++++++++++ Write Calibration Register  ++++++++++++ \n\r" );
//        }
//        else
//        {
//            MyPrintf_USART1( "++Write Test NG \n\r" );
//        }
    
    
    
//    if(HAL_I2C_Master_Transmit_IT(&hi2c1, (uint16_t)0x48<<1, nRbuf, 2)!= HAL_OK)
//	{
//		/* Error_Handler() function is called when Timout error occurs.
//			When Acknowledge failure ocucurs (Slave don't acknowledge it's address)
//			Master restarts communication */
//		
//		  MyPrintf_USART1("Audio i2c tx error = %d\r\n",nRbuf);
//		
//	}
//	else{
//		
//          MyPrintf_USART1("Audio i2c OK = %02x-%02x\r\n",nRbuf[0],nRbuf[1]);
//          
//	}


	//RTC_AlarmInit();
	

    MyPrintf_USART1("Power i2c OK = %02x-%02x\r\n",nRbuf[0],nRbuf[1]);
    
	Flash_Init();
	HAL_Delay(10);


    //-------------------ADC MAC 설정 
    MX_ADC_DMA_Init();
	MX_ADC1_Init();
    MX_ADC3_Init();
    //----------------------------
    

	//--------------LCD 초기 설정 부분.
	OLED_1in3_c_test();
    OLED_Print(); // 약 350ms 필요.
	//-----------------------

	
    MyPrintf_USART1("SystemClock  = %d/ AHB(HCLK) : %d / APB1(PCLK1) : %d / APBP2(PCLK2) : %d \n\r", HAL_RCC_GetSysClockFreq(), HAL_RCC_GetHCLKFreq(), HAL_RCC_GetPCLK1Freq(), HAL_RCC_GetPCLK2Freq());
    MyPrintf_USART1("---- AMP ID Switch  = [%d--%d] \n\r",IP_ADDR1_INPUT_DATA,IP_ADDR2_INPUT_DATA);
    
    
	MyPrintf_USART1("---- %s", completeVersion);
	MyPrintf_USART1("-%s\r\n", completeVersionBuild);
    
    
//	sprintf(&mLCDPrintBuf[1][0], "%s-%s", completeVersion, completeVersionBuild);
//    
//    sprintf(&mLCDPrintBuf_2[0][0], "ANSM_ON");
//    
//    sprintf(&mLCDPrintBuf_2[1][0], "AMP_VOL_DEFAULT");
    
   

	static int s_100msCng = 0;   
    
	static int s_200msCng = 0;   
	static int s_1000msCng = 0;  
        

    static int s_MainTimeCng = 0;  
    
    static int sOLED_InitCnt = 0;
    
    
    
    mLed_Process_Flag.sMy_IP_Info = IP_ADDR1_INPUT_DATA;
	mLed_Process_Flag.sAnsm_Run_Flag = true;
    memset(mLed_Process_Flag.sSt_Buf_Val,0x00,sizeof(mLed_Process_Flag.sSt_Buf_Val)); // buffer Init
    
    
    sprintf(&mLCDPrintBuf[2][0], "--------------------");
    
    
    //AUDIO_AMP_Boot_Set();
    
    WWDG_Init(); //
    
    ethernetif_set_link(&gnetif);
    
	while (1)
	{  
		/* Read a received packet from the Ethernet buffers and send it 
		   to the lwIP for handling */
     
        ethernetif_input(&gnetif);
        
        
        //ethernetif_set_link(&gnetif);
        
		/* Handle timeouts */
		sys_check_timeouts();
    
		/* 내부 메모리 저장 및 읽기 */  
		//Flash_Main();
	  
		//SPI_FLASH_Main();
    
		USARTRX_MainPro();
    
        
//        if(HAL_GetTick() >= 15000 ) // 15초 부팅 할때 초기 AMP  제어 OFF
//        {
//            s_MainTimeCng++;
//                
//
//            if(s_MainTimeCng == 1)
//            {
//                s_MainTimeCng++;
//                    
//                s_100msCng = HAL_GetTick();
//                s_200msCng = HAL_GetTick();
//                s_1000msCng = HAL_GetTick(); 
//                
//            }
//            
//            // 500ms 마다 스피커 동작 DI를 체크 한다.
//             //s_DI_Check = ((getSW_RS() << 3) | (getSW_AR() << 2) | (getSW_SL() << 1) | (getSW_SR() & 0x01));
//            if ((HAL_GetTick() - s_100msCng >= 100) )
//            {
//                
//                s_100msCng = HAL_GetTick();
//
//                    
//                MX_I2C_Process();
//
//            }
//        
//           // 100MS 마다 ADC DMA 스켄.
//            if (HAL_GetTick() - s_200msCng >= 100)
//            {
//                s_200msCng = HAL_GetTick();
//            
//                HAL_ADC_Start_DMA(&AdcHandle1, (uint32_t*)&ADCValue1, 1) ;
//                HAL_ADC_Start_DMA(&AdcHandle3, (uint32_t*)&ADCValue3, 1) ;
//            
//            }
//            
//
//              // 1초마다 LCD 화면 갱신 및 AMP 고장 확인.
//            if (HAL_GetTick() - s_1000msCng >= 1000)
//            {
//                s_1000msCng = HAL_GetTick();
//
//                sOLED_InitCnt++;
//                
//                if(!(sOLED_InitCnt % 120) && (sOLED_InitCnt < 400)) //Power On 400초 동안 ( 120초 마다 한번씩  초기화 로직 추가.)
//                {
//                    OLED_1in3_C_Init();
//                }
//                
//                mLed_Process_Flag.sOLED_Display_Flag = true;
//                
//               // MyPrintf_USART1("OLED Tim s: %d \n\r",HAL_GetTick());
//                
//                OLED_Print(); // 약 150ms 필요. --> 클럭속도 4000 향상하면 50ms 까지 감소.
//            
//                //MyPrintf_USART1("OLED Tim e: %d \n\r",HAL_GetTick());
//                
//                mLed_Process_Flag.sOLED_Display_Flag = false;
//                
//                if(mLed_Process_Flag.sAudio_Play_mode == true)
//                {
//                    
//                    AMP_FAULT();
//                }
//                
//                 // 계속 전송하는 방식으로 변경. 
//                  udp_SysLog_Connect("AMP_%01d%01d%01d%01d_A%03d",
//                                       ((mLed_Process_Flag.sSt_Buf_Val[0] & 0x80) == 0x80 ? 1 : 0) ,
//                                       ((mLed_Process_Flag.sSt_Buf_Val[1] & 0x80) == 0x80 ? 1 : 0) ,
//                                       ((mLed_Process_Flag.sSt_Buf_Val[2] & 0x80) == 0x80 ? 1 : 0) ,
//                                       ((mLed_Process_Flag.sSt_Buf_Val[3] & 0x08) == 0x08 ? 1 : 0) ,
//                                        mLed_Process_Flag.sCurrentVal );
//                
//                
//                
//            
//            }
//            
//   
//        }
//        
//
//          //------------ UDP 수신 데이타 처리 부분.
//        if((mLed_Process_Flag.sEth_Rx_Finish_TimeCnt) == 1) // 통신 time out 완료 
//        {
//
//            mLed_Process_Flag.sEth_Rx_Finish_TimeCnt = 0;
//         
//            
//            pmEthernet_Rx_struct = (mETHERNET_RX_STRUCT *)mLed_Process_Flag.sRx_Public_Buf;
//            
//            
//            if(mLed_Process_Flag.sEth_Rx_Request_Flag) //수신  flag
//            {
//                mLed_Process_Flag.sEth_Rx_Request_Flag = 0;
//                
//                
//                udp_SysLog_Connect("AMP_%01d%01d%01d%01d_A%03d",
//                                   ((mLed_Process_Flag.sSt_Buf_Val[0] & 0x80) == 0x80 ? 1 : 0) ,
//                                   ((mLed_Process_Flag.sSt_Buf_Val[1] & 0x80) == 0x80 ? 1 : 0) ,
//                                   ((mLed_Process_Flag.sSt_Buf_Val[2] & 0x80) == 0x80 ? 1 : 0) ,
//                                   ((mLed_Process_Flag.sSt_Buf_Val[3] & 0x08) == 0x08 ? 1 : 0) ,
//                                    mLed_Process_Flag.sCurrentVal );
//                
//                
//            }
//
//        }
//        
//        
//        if(mLed_Process_Flag.sSpk_check_Cnt == 1)
//        {
//            mLed_Process_Flag.sSpk_check_Cnt = 0;
//            
//            mLed_Process_Flag.sSpk_check_Flag = true;
//                
//            AMP_SPK_CHECK();
//            
//        }
//    
//            
//        
//       
//
//
//        /*
//        if (mLed_Process_Flag.sClock_Start_Flage) // RTC ??뮄而? ??끉?젟????꼶?뮉 ?겫???겫?
//        {
//            mLed_Process_Flag.sClock_Start_Flage = 0;
//
//            mLed_Process_Flag.sReClock_Start_Flage = 1;
//
//            mAlarmAEventCallback_Flag = 5;
//
//            RTC_SetTimeConfig();
//
//            memset(&mLed_Process_Flag.sRx_PII_Ascii_Buf[0],0x00,sizeof(mLed_Process_Flag.sRx_PII_Ascii_Buf));
//
//        }
//        
//		*/
//        
//        
//		if (nTime_Flage)
//		{
//			nTime_Flage = 0;
//          
//            mLed_Process_Flag.sEth_Rx_Request_Flag = 0;
//            
//			udp_SysLog_Connect("FDI - sending udp client message %d",mEthernet_Tx_struct.sWatchdog_Cnt);
//			udp_echoclient_connect();
//            
//  
//		}
//          
//    
//		//네트워크 설정 다시 리셋 하는 부분.
//	  
//		if (mLed_Process_Flag.sEth_Rx_RESET_Flag == 2 && mTimerFlag_10s)
//		{
//			mTimerFlag_10s = 0;
//             
//			netif_set_down(&gnetif);
//    
//            
//			MyPrintf_USART1("%s(%d)\r\n", __func__, __LINE__);
//            
//			// MyPrintf_USART1 (" ########### Netif_Set_down  \n\r");
//            
//		}
//		else if (mLed_Process_Flag.sEth_Rx_RESET_Flag == 1 && mTimerFlag_10s)
//		{
//            
//			mTimerFlag_10s = 0;
//             
//			ethernetif_notify_conn_changed(&gnetif);
//            
//			MyPrintf_USART1("$$$$$$$$$--netif_set_RESET----------$$$$$$$$$\r\n");
//            
//		}
        

#ifdef USE_DHCP
		/* handle periodic timers for LwIP */
		DHCP_Periodic_Handle(&gnetif);
#endif 
	}
}




///*****************************************************************************
//* @brief -
//* @param -
//* @retval-
//******************************************************************************/
//int __io_putchar(int ch)
//{
//	return(ITM_SendChar(ch));
//}

/*****************************************************************************
* @brief - RTC ?쁽?옱 ?떆媛꾩쓣 ?꽕?젙?븯?뒗 遺?遺?.
* @param -
* @retval-
******************************************************************************/
static void BSP_Config(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;

	/* Enable PB14 to IT mode: Ethernet Link interrupt */ 
	__HAL_RCC_GPIOC_CLK_ENABLE();
	GPIO_InitStructure.Pin = GPIO_PIN_0;
	GPIO_InitStructure.Mode = GPIO_MODE_IT_FALLING;
	GPIO_InitStructure.Pull = GPIO_NOPULL;
	HAL_GPIO_Init(GPIOC, &GPIO_InitStructure);

	/* Enable EXTI Line interrupt */
//	HAL_NVIC_SetPriority(EXTI15_10_IRQn, 0xF, 0);
//	HAL_NVIC_EnableIRQ(EXTI15_10_IRQn); 
    
    
	HAL_NVIC_SetPriority(EXTI0_IRQn, 0x0, 0);
	HAL_NVIC_EnableIRQ(EXTI0_IRQn);
    

    
    IP_ADDR_VAL_DATA = (0x01 % 11) * 100;
	IP_ADDR_VAL_DATA = IP_ADDR_VAL_DATA + ((0x01 % 11) * 10);
    
    
//	//
	__GPIOD_CLK_ENABLE();

	GPIO_InitStructure.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStructure.Pull = GPIO_PULLDOWN;
	GPIO_InitStructure.Pin = GPIO_PIN_6;
	HAL_GPIO_Init(GPIOD, &GPIO_InitStructure);
    
	/* Configure LED1, LED2 */
	//BSP_LED_Init(LED1);
	//BSP_LED_Init(LED2);

	/* Set Systick Interrupt to the highest priority */
	HAL_NVIC_SetPriority(SysTick_IRQn, 0x0, 0x0);

//	// RUN LED
//	__GPIOI_CLK_ENABLE();
//
//	GPIO_InitStructure.Mode = GPIO_MODE_OUTPUT_PP;
//	GPIO_InitStructure.Pull = GPIO_PULLUP;
//	GPIO_InitStructure.Pin = GPIO_PIN_11;
//	HAL_GPIO_Init(GPIOI, &GPIO_InitStructure);
//
//	/*Hex ??끉?맄燁??揶쏅?れ뱽 ??럩堉? ??뫀?뼄.*/
//	//HSW 1,2 스위치를 이용해서, 장치 식별을 한다.
//	__GPIOH_CLK_ENABLE();
//	GPIO_InitStructure.Mode = GPIO_MODE_INPUT;
//	GPIO_InitStructure.Pull = GPIO_PULLUP;
//	GPIO_InitStructure.Pin = GPIO_PIN_8 | GPIO_PIN_9 | GPIO_PIN_10 | GPIO_PIN_11 | GPIO_PIN_12 | GPIO_PIN_13 | GPIO_PIN_14 | GPIO_PIN_15;
//	GPIO_InitStructure.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
//	HAL_GPIO_Init(GPIOH, &GPIO_InitStructure);
//
//    
//    // 차량 번호를 설정 하는 
//	IP_ADDR1_INPUT_DATA =  HAL_GPIO_ReadPin(GPIOH, GPIO_PIN_8);  
//	IP_ADDR1_INPUT_DATA |= HAL_GPIO_ReadPin(GPIOH, GPIO_PIN_9)  << 1;
//	IP_ADDR1_INPUT_DATA |= HAL_GPIO_ReadPin(GPIOH, GPIO_PIN_10) << 2;
//	IP_ADDR1_INPUT_DATA |= HAL_GPIO_ReadPin(GPIOH, GPIO_PIN_11) << 3;
//    
//	IP_ADDR1_INPUT_DATA = ((~IP_ADDR1_INPUT_DATA) & 0x0F);
//    
//    //l/R 를 설정 하는 부분.
//	IP_ADDR2_INPUT_DATA = HAL_GPIO_ReadPin(GPIOH, GPIO_PIN_12);
//	IP_ADDR2_INPUT_DATA |= HAL_GPIO_ReadPin(GPIOH, GPIO_PIN_13) << 1;
//	IP_ADDR2_INPUT_DATA |= HAL_GPIO_ReadPin(GPIOH, GPIO_PIN_14) << 2;
//	IP_ADDR2_INPUT_DATA |= HAL_GPIO_ReadPin(GPIOH, GPIO_PIN_15) << 3;
//
//    
//	IP_ADDR2_INPUT_DATA = ((~IP_ADDR2_INPUT_DATA) & 0x0F);
//    
//    
//	
//
//	/*RS 485 RTS PIN */
//	__GPIOC_CLK_ENABLE();
//	GPIO_InitStructure.Mode = GPIO_MODE_OUTPUT_PP;
//	GPIO_InitStructure.Pull = GPIO_PULLUP;
//	GPIO_InitStructure.Pin =  GPIO_PIN_12;
//	GPIO_InitStructure.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
//	HAL_GPIO_Init(GPIOC, &GPIO_InitStructure);
//  
//    
//	//AMP SD
//	__GPIOD_CLK_ENABLE();
//
//	GPIO_InitStructure.Pin = AMP_STANDBY_Pin;
//	GPIO_InitStructure.Pull = GPIO_NOPULL;
//	GPIO_InitStructure.Mode = GPIO_MODE_OUTPUT_PP;
//    GPIO_InitStructure.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
//	HAL_GPIO_Init(GPIOD, &GPIO_InitStructure);
//    
//	HAL_GPIO_WritePin(AMP_STANDBY_Port, AMP_STANDBY_Pin, GPIO_PIN_SET);
//    
//
//	//BK_OUT
//	__GPIOD_CLK_ENABLE();
//
//	GPIO_InitStructure.Pin = BK_OUT1_Pin | BK_OUT2_Pin | BK_OUT3_Pin | BK_OUT4_Pin | BK_OUT5_Pin | BK_OUT6_Pin;
//	GPIO_InitStructure.Pull = GPIO_NOPULL;
//	GPIO_InitStructure.Mode = GPIO_MODE_OUTPUT_PP;
//	GPIO_InitStructure.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
//	HAL_GPIO_Init(GPIOD, &GPIO_InitStructure);
//    
//	HAL_GPIO_WritePin(BK_OUT1_Port, BK_OUT1_Pin, GPIO_PIN_SET);
//	HAL_GPIO_WritePin(BK_OUT2_Port, BK_OUT2_Pin, GPIO_PIN_SET);
//	HAL_GPIO_WritePin(BK_OUT3_Port, BK_OUT3_Pin, GPIO_PIN_SET);
//    
//	HAL_GPIO_WritePin(BK_OUT4_Port, BK_OUT4_Pin, GPIO_PIN_SET);
//	HAL_GPIO_WritePin(BK_OUT5_Port, BK_OUT5_Pin, GPIO_PIN_SET);
//	HAL_GPIO_WritePin(BK_OUT6_Port, BK_OUT6_Pin, GPIO_PIN_SET);
//    
//
//	//Mute
//	__GPIOD_CLK_ENABLE();
//
//	GPIO_InitStructure.Pin = AMP_Mute1_Pin | AMP_Mute2_Pin;
//	GPIO_InitStructure.Pull = GPIO_NOPULL;
//	GPIO_InitStructure.Mode = GPIO_MODE_OUTPUT_PP;
//	HAL_GPIO_Init(GPIOD, &GPIO_InitStructure);
//    
//	HAL_GPIO_WritePin(AMP_Mute1_Port, AMP_Mute1_Pin, GPIO_PIN_RESET);
//	HAL_GPIO_WritePin(AMP_Mute2_Port, AMP_Mute2_Pin, GPIO_PIN_RESET);
//    
//   
//    
//	//LED
//	__GPIOD_CLK_ENABLE();
//
//	GPIO_InitStructure.Pin = RSP_LED_Pin | OSP_LED_Pin;
//	GPIO_InitStructure.Pull = GPIO_NOPULL;
//	GPIO_InitStructure.Mode = GPIO_MODE_OUTPUT_PP;
//	HAL_GPIO_Init(GPIOD, &GPIO_InitStructure);
//    
//	HAL_GPIO_WritePin(RSP_LED_Port, RSP_LED_Pin, GPIO_PIN_SET);
//	HAL_GPIO_WritePin(OSP_LED_Port, OSP_LED_Pin, GPIO_PIN_SET);
//    
//    
//    
//	// INT PUT
//
//	__GPIOD_CLK_ENABLE();
//	GPIO_InitStructure.Pin = AMP1_PAULT_Pin | AMP2_PAULT_Pin | AMP3_PAULT_Pin;
//	GPIO_InitStructure.Pull = GPIO_PULLUP;
//	GPIO_InitStructure.Mode = GPIO_MODE_INPUT;  
//	GPIO_InitStructure.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
//	HAL_GPIO_Init(GPIOD, &GPIO_InitStructure);
//    
//    
//	// BK
//	__GPIOE_CLK_ENABLE();
//	GPIO_InitStructure.Pin = SW_RS_Pin | SW_SL_Pin | SW_SR_Pin | SW_AR_Pin | SW_BROAD_Pin;
//	GPIO_InitStructure.Pull = GPIO_PULLUP;
//	GPIO_InitStructure.Mode = GPIO_MODE_INPUT;  
//	GPIO_InitStructure.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
//	HAL_GPIO_Init(GPIOE, &GPIO_InitStructure);
//    
//    
//	// AMP 
//	__GPIOA_CLK_ENABLE();
//	GPIO_InitStructure.Pin = ANS_OUT_Pin;
//	GPIO_InitStructure.Pull = GPIO_NOPULL;
//	GPIO_InitStructure.Mode = GPIO_MODE_ANALOG;  
//	//GPIO_InitStructure.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
//	HAL_GPIO_Init(ANS_OUT_Port, &GPIO_InitStructure);
//    
 

   
        
}


/*****************************************************************************
* @brief - RTC ?쁽?옱 ?떆媛꾩쓣 ?꽕?젙?븯?뒗 遺?遺?.
* @param -
* @retval-
******************************************************************************/
static void Netif_Config(void)
{
	ip_addr_t ipaddr;
	ip_addr_t netmask;
	ip_addr_t gw;

#ifdef USE_DHCP
	ip_addr_set_zero_ip4(&ipaddr);
	ip_addr_set_zero_ip4(&netmask);
	ip_addr_set_zero_ip4(&gw);
#else
	IP_ADDR4(&ipaddr, IP_ADDR0, IP_ADDR1, IP_ADDR2, IP_ADDR3);
	IP_ADDR4(&netmask, NETMASK_ADDR0, NETMASK_ADDR1, NETMASK_ADDR2, NETMASK_ADDR3);
	IP_ADDR4(&gw, GW_ADDR0, GW_ADDR1, GW_ADDR2, GW_ADDR3);
#endif /* USE_DHCP */

	/* Add the network interface */    
	netif_add(&gnetif, &ipaddr, &netmask, &gw, NULL, &ethernetif_init, &ethernet_input);

    HAL_Delay(10);
    
	/* Registers the default network interface */
	netif_set_default(&gnetif);
    
    HAL_Delay(10);

	if (netif_is_link_up(&gnetif))
	{
		/* When the netif is fully configured this function must be called */
		netif_set_up(&gnetif);
        
		MyPrintf_USART1("+------------netif_set_up-------------------+\r\n");
	}
	else
	{
		/* When the netif link is down this function must be called */
		netif_set_down(&gnetif);
        
		mLed_Process_Flag.sEth_UpLInk_Cnt = 0;
        
		MyPrintf_USART1("+------------netif_set_down-------------------+\r\n");
        
	}

	/* Set the link callback function, this function is called on change of link status*/
	netif_set_link_callback(&gnetif, ethernetif_update_config);
}

/*****************************************************************************
* @brief - 
* @param -
* @retval-
******************************************************************************/
void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
	if (GPIO_Pin == GPIO_PIN_0)
	{
		ethernetif_set_link(&gnetif);
	}
}

/**
  * @brief  System Clock Configuration
  *         The system Clock is configured as follow : 
  *            System Clock source            = PLL (HSE)
  *            SYSCLK(Hz)                     = 168000000
  *            HCLK(Hz)                       = 168000000
  *            AHB Prescaler                  = 1
  *            APB1 Prescaler                 = 4
  *            APB2 Prescaler                 = 2
  *            HSE Frequency(Hz)              = 25000000
  *            PLL_M                          = 25
  *            PLL_N                          = 336
  *            PLL_P                          = 2
  *            PLL_Q                          = 7
  *            VDD(V)                         = 3.3
  *            Main regulator output voltage  = Scale1 mode
  *            Flash Latency(WS)              = 5
  * @param  None
  * @retval None
  */
static void SystemClock_Config(void)
{
	RCC_ClkInitTypeDef RCC_ClkInitStruct;
	RCC_OscInitTypeDef RCC_OscInitStruct;

	/* Enable Power Control clock */
	__HAL_RCC_PWR_CLK_ENABLE();

	/* The voltage scaling allows optimizing the power consumption when the device is 
	 clocked below the maximum system frequency, to update the voltage scaling value 
	 regarding system frequency refer to product datasheet.  */
	__HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);

	/* Enable HSE Oscillator and activate PLL with HSE as source */
	RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
	RCC_OscInitStruct.HSEState = RCC_HSE_ON;
	RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
	RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
	RCC_OscInitStruct.PLL.PLLM = 25;
	RCC_OscInitStruct.PLL.PLLN = 336;
	RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
	RCC_OscInitStruct.PLL.PLLQ = 7;
	if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
	{
		Error_Handler();
	}

	/* Select PLL as system clock source and configure the HCLK, PCLK1 and PCLK2 
	 clocks dividers */
	RCC_ClkInitStruct.ClockType = (RCC_CLOCKTYPE_SYSCLK | RCC_CLOCKTYPE_HCLK | RCC_CLOCKTYPE_PCLK1 | RCC_CLOCKTYPE_PCLK2);
	RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
	RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
	RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV4;  
	RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV2;  
	if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_5) != HAL_OK)
	{
		Error_Handler();
	}

	/* STM32F405x/407x/415x/417x Revision Z devices: prefetch is supported  */
	if (HAL_GetREVID() == 0x1001)
	{
		/* Enable the Flash prefetch */
		__HAL_FLASH_PREFETCH_BUFFER_ENABLE();
	}
}



/*****************************************************************************
* @brief - RTC ?袁⑹삺 ??뮄而?????끉?젟??꼶?뮉 ?겫???겫?
* @param -
* @retval-
******************************************************************************/
static void RTC_AlarmInit(void)
{
	/*##-1- Configure the RTC peripheral #######################################*/
	RtcHandle.Instance = RTC;

	/* Configure RTC prescaler and RTC data registers */
	/* RTC configured as follow:
		- Hour Format    = Format 24
		- Asynch Prediv  = Value according to source clock
		- Synch Prediv   = Value according to source clock
		- OutPut         = Output Disable
		- OutPutPolarity = High Polarity
		- OutPutType     = Open Drain */
	RtcHandle.Init.HourFormat = RTC_HOURFORMAT_24;
	RtcHandle.Init.AsynchPrediv = RTC_ASYNCH_PREDIV;
	RtcHandle.Init.SynchPrediv = RTC_SYNCH_PREDIV;
	RtcHandle.Init.OutPut = RTC_OUTPUT_DISABLE;
	RtcHandle.Init.OutPutPolarity = RTC_OUTPUT_POLARITY_HIGH;
	RtcHandle.Init.OutPutType = RTC_OUTPUT_TYPE_OPENDRAIN;
	__HAL_RTC_RESET_HANDLE_STATE(&RtcHandle);
    
	if (HAL_RTC_Init(&RtcHandle) != HAL_OK)
	{
		/* Initialization Error */
		Error_Handler();
	}
	/*##-2- Configure Alarm ####################################################*/
	/* Configure RTC Alarm */
	RTC_AlarmConfig();

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
    

/*****************************************************************************
  * @brief  Compares two buffers.
  * @param  pBuffer1, pBuffer2: buffers to be compared.
  * @param  BufferLength: buffer's length
  * @retval 0  : pBuffer1 identical to pBuffer2
  *         >0 : pBuffer1 differs from pBuffer2
  ******************************************************************************/
void UDPdebug_print_JDS(struct udp_hdr *udphdr)
{
  
	/*
	 
	MyPrintf_USART1("+------------UDP-------------------+\n");
	MyPrintf_USART1("|     %5"U16_F"     |     %5"U16_F"     | (src port, dest port)\n",
		lwip_ntohs(udphdr->src),
		lwip_ntohs(udphdr->dest));
	MyPrintf_USART1("+-------------------------------+\n");
	MyPrintf_USART1("|     %5"U16_F"     |     0x%04"X16_F"    | (len, chksum)\n",
		lwip_ntohs(udphdr->len),
		lwip_ntohs(udphdr->chksum));
	MyPrintf_USART1("+-------------------------------+\n");
	
	
	*/
	                                             
   
}

/*****************************************************************************
* @brief -
* @param -
* @retval-
******************************************************************************/

uint8_t d_SR_Flag;
int d_SR_Cnt;

uint8_t d_SL_Flag;
int d_SL_Cnt;

uint8_t d_AR_Flag;
int d_AR_Cnt;

uint8_t d_RS_Flag;
int d_RS_Cnt;


void Time_Main(void)
{
    uint8_t     nRbuf_1[2];
    uint8_t     nRbuf_2[2];
    
    static uint8_t d_10Sec_Cnt = 0;
    
    static uint8_t mResetCnt = 0;
   
	
	m_Main_TIM_Cnt++;
    
    
    ONTD(getSW_SR(),&d_SR_Flag,5,&d_SR_Cnt);
    ONTD(getSW_SL(),&d_SL_Flag,5,&d_SL_Cnt);
    ONTD(getSW_AR(),&d_AR_Flag,5,&d_AR_Cnt);
    ONTD(getSW_RS(),&d_RS_Flag,5,&d_RS_Cnt);
        
            
    mDI_CheckFlag = ((d_SR_Flag << 3) | (d_SL_Flag << 2) | ( d_AR_Flag<< 1) | (d_RS_Flag & 0x01));  
    
    
    
	if (!(m_Main_TIM_Cnt % 100)) // 100ms 
	{

		HAL_GPIO_TogglePin(GPIOI, GPIO_PIN_11); // RUN LED
        
        if(mLed_Process_Flag.sSpk_check_Cnt) mLed_Process_Flag.sSpk_check_Cnt--;
        

	}
    

	if (mLed_Process_Flag.sEth_Rx_Finish_TimeCnt > 1)
	{
		mLed_Process_Flag.sEth_Rx_Finish_TimeCnt--;
	}
    

    if (!(m_Main_TIM_Cnt % 1000)) // 1000ms 
	{
        if(mLed_Process_Flag.sCurrentTestFlag == TRUE) // 
        {
            //----------------------------------------
          //  processCurrentVal();
            //----------------------------------------
        }
        else if(mLed_Process_Flag.sCurrentTestFlag == FALSE)
        {
            
        }
        
        //ethernetif_set_link(&gnetif);

        
    }
    
        
            
	if (!(m_Main_TIM_Cnt % 60000)) // 10sec
	{

        
        d_10Sec_Cnt++;

        
        sprintf(&mLCDPrintBuf[0][0], "IP : %s", ip4addr_ntoa(&gnetif.ip_addr));
        
         if(mLed_Process_Flag.sAudio_Play_mode == true)
         {
             //sprintf(&mLCDPrintBuf[2][15], "Temp-%02d",mLed_Process_Flag.sCpu_Temp);
         }
         else
         {
             sprintf(&mLCDPrintBuf[2][0], "-----*****-----Temp-%02d",mLed_Process_Flag.sCpu_Temp);
         }
        
         
         udp_SysLog("(%dT,%d)[build : %s] -> SPK_%01d%01d%01d%01d--TEMP : %d -- ANSM : %d -- Current : %03d mA ",
                    
                            mLed_Process_Flag.sTrainID,
                            mLed_Process_Flag.sDHCP_IP_Val,
                            completeVersionBuild,
                           ((mLed_Process_Flag.sSt_Buf_Val[0] & 0x80) == 0x80 ? 1 : 0) ,
                           ((mLed_Process_Flag.sSt_Buf_Val[1] & 0x80) == 0x80 ? 1 : 0) ,
                           ((mLed_Process_Flag.sSt_Buf_Val[2] & 0x80) == 0x80 ? 1 : 0) ,
                           ((mLed_Process_Flag.sSt_Buf_Val[3] & 0x08) == 0x08 ? 1 : 0) ,
                            mLed_Process_Flag.sCpu_Temp,
                            mAnsSetFlag.tAnsCnt,
                            mLed_Process_Flag.sCurrentVal );
         
         
    
    }

        
        
		/*
		if (mAlarmAEventCallback_Flag)
		{
			//RTC_TimeShow(aShowTime);

			mAlarmAEventCallback_Flag = 5;
		}
        */
    
        
    if (!(m_Main_TIM_Cnt % 10000)) // 10sec
    {
//        HAL_GPIO_WritePin(GPIOD, GPIO_PIN_6, false); 
//        HAL_GPIO_WritePin(GPIOD, GPIO_PIN_6, false); 
//        HAL_GPIO_WritePin(GPIOD, GPIO_PIN_6, false); 
//        HAL_GPIO_WritePin(GPIOD, GPIO_PIN_6, true); 
        //////--------------------------------------------------------------------//////
        MyPrintf_USART1("~~~~~~~~~~~~NewPulse 4_line PAMP~~~~~~~~~~~~\n\r");
		MyPrintf_USART1("CPU RUN Time  = %d Second  \n\r", (m_Main_TIM_Cnt / 1000));
        MyPrintf_USART1("IP  : %s\n\r", ip4addr_ntoa(&gnetif.ip_addr));
		MyPrintf_USART1("MAC : %x-%x-%x-%x-%x-%x \n\r", gnetif.hwaddr[0], gnetif.hwaddr[1], gnetif.hwaddr[2], gnetif.hwaddr[3], gnetif.hwaddr[4], gnetif.hwaddr[5]);
        MyPrintf_USART1("ANSM : %02d\r\n",mAnsSetFlag.tAnsCnt);
        MyPrintf_USART1("Temp : %02d\r\n",mLed_Process_Flag.sCpu_Temp);
        //////--------------------------------------------------------------------//////
        
        
        mTimerFlag_10s = 1;
        
        
        mResetCnt++;
        
        HAL_GPIO_WritePin(GPIOD, GPIO_PIN_6, false); 
        HAL_GPIO_WritePin(GPIOD, GPIO_PIN_6, false); 
        HAL_GPIO_WritePin(GPIOD, GPIO_PIN_6, true); 
        HAL_GPIO_WritePin(GPIOD, GPIO_PIN_6, true); 


        HAL_GPIO_WritePin(GPIOD, GPIO_PIN_6, false); 
        HAL_GPIO_WritePin(GPIOD, GPIO_PIN_6, false); 

        HAL_GPIO_WritePin(GPIOD, GPIO_PIN_6, true); 
        HAL_GPIO_WritePin(GPIOD, GPIO_PIN_6, true); 
        
        //netif_set_down(&gnetif);
        
        //ethernetif_notify_conn_changed(&gnetif);
        
        //Netif_Config();
       // ethernetif_set_link(&gnetif);
            
            
//        
//        if(mResetCnt & 0x01)
//        {
//        
//            HAL_GPIO_WritePin(GPIOD, GPIO_PIN_6, false); 
//            HAL_GPIO_WritePin(GPIOD, GPIO_PIN_6, false); 
//             HAL_GPIO_WritePin(GPIOD, GPIO_PIN_6, true); 
//            HAL_GPIO_WritePin(GPIOD, GPIO_PIN_6, true); 
//            
//            
//            HAL_GPIO_WritePin(GPIOD, GPIO_PIN_6, false); 
//            HAL_GPIO_WritePin(GPIOD, GPIO_PIN_6, false); 
//            
//            HAL_GPIO_WritePin(GPIOD, GPIO_PIN_6, true); 
//            HAL_GPIO_WritePin(GPIOD, GPIO_PIN_6, true); 
//            
//           // Netif_Config();
//            
//        }
//        else
//        {
//
//            HAL_GPIO_WritePin(GPIOD, GPIO_PIN_6, true); 
//            HAL_GPIO_WritePin(GPIOD, GPIO_PIN_6, true); 
//            
//           // Netif_Config();
//        }
//    
        
        
		if (netif_is_link_up(&gnetif))  // 링크 UP인 경우에만 동작 한다.
		{
            m_Main_TIM_Cnt_Reset = 0;
            
            mLed_Process_Flag.sDHCP_IP_Val = ip4_addr4(&gnetif.ip_addr);
            mLed_Process_Flag.sTrainID = ip4_addr3(&gnetif.ip_addr);
            
			MyPrintf_USART1(" @@@@  CPU.....netif_is_link_up \n\r");
  
        
#if LWIP_IGMP 
        
			if (mLed_Process_Flag.sDhcp_Complete < 2) //DHCP 확인 동작이 완료 되었다면.
			{
                
				mLed_Process_Flag.sDhcp_Complete++;
                
				ip4_addr_t allrouters;

				//IP4_ADDR(&allrouters, 233, 253, 18, 3);
                IP4_ADDR(&allrouters, 224, 0, 0, 1);
                
				igmp_joingroup(&gnetif.ip_addr, &allrouters);
                
                MyPrintf_USART1("++++++igmp group : %d\n\r",mLed_Process_Flag.sDhcp_Complete);
			}

#endif

    
//			mLed_Process_Flag.sEth_UpLInk_Cnt++;
//        
//			if (mLed_Process_Flag.sEth_Rx_RESET_Flag){mLed_Process_Flag.sEth_Rx_RESET_Flag--; }
//            
//            
//            mLed_Process_Flag.sEth_Rx_Cnt++;
//            
//            if(mLed_Process_Flag.sEth_Rx_Cnt == 6)// 60 초 동안  데이타 수신이 없으면,
//            {
//                mLed_Process_Flag.sEth_Rx_RESET_Flag = 2; // 네트워크 리셋 동작 한다.
//            }
//            else if(mLed_Process_Flag.sEth_Rx_Cnt == 8) // 80 초 동안  데이타  수신이 없으면
//            {
//                 udp_SysLog_Connect(" @@@@  CPU Processing SystemReset ");
//			     MyPrintf_USART1(" @@@@  CPU Processing SystemReset \n\r");
//
//			     HAL_NVIC_SystemReset(); // 장치 Reset 한다.
//                
//            }
			
		}
		else
		{
            m_Main_TIM_Cnt_Reset++;
            
			MyPrintf_USART1(" @@@@ netif_is_link_Down \n\r");
            
			if ((m_Main_TIM_Cnt_Reset) >= 6) // 부팅하고 60초 동안 네트워크 연결이 없으면, 리셋 한다.
			{
                
				HAL_NVIC_SystemReset();
			}

            
		}
        
        
	}
    
}




/*****************************************************************************
* @brief - RTC ?袁⑹삺 ??뮄而?????끉?젟??꼶?뮉 ?겫???겫?
* @param -
* @retval-
******************************************************************************/

static void RTC_AlarmConfig(void)
{


	/*##-1- Configure the RTC Alarm peripheral #################################*/
	/* Set Alarm to 02:20:30
	   RTC Alarm Generation: Alarm on Hours, Minutes and Seconds */
	salarmstructure.Alarm = RTC_ALARM_A;
	salarmstructure.AlarmDateWeekDay = RTC_WEEKDAY_MONDAY;
	salarmstructure.AlarmDateWeekDaySel = RTC_ALARMDATEWEEKDAYSEL_DATE;
	salarmstructure.AlarmMask = RTC_ALARMMASK_DATEWEEKDAY;
	salarmstructure.AlarmSubSecondMask = RTC_ALARMSUBSECONDMASK_NONE;
	salarmstructure.AlarmTime.TimeFormat = RTC_HOURFORMAT12_AM;
	salarmstructure.AlarmTime.Hours = 0;
	salarmstructure.AlarmTime.Minutes = 0;
	salarmstructure.AlarmTime.Seconds = 1;
	salarmstructure.AlarmTime.SubSeconds = 1;

	if (HAL_RTC_SetAlarm_IT(&RtcHandle, &salarmstructure, RTC_FORMAT_BCD) != HAL_OK)
	{
		/* Initialization Error */
		Error_Handler();
	}

	/*##-2- Configure the Date #################################################*/
	/* Set Date: Tuesday February 18th 2014 */
	sdatestructure.Year = 0x20;
	sdatestructure.Month = RTC_MONTH_JUNE;
	sdatestructure.Date = 0x23;
	sdatestructure.WeekDay = RTC_WEEKDAY_TUESDAY;

	if (HAL_RTC_SetDate(&RtcHandle, &sdatestructure, RTC_FORMAT_BCD) != HAL_OK)
	{
		/* Initialization Error */
		Error_Handler();
	}

	/*##-3- Configure the Time #################################################*/
	/* Set Time: 02:20:00 */
	stimestructure.Hours = 0;
	stimestructure.Minutes = 0;
	stimestructure.Seconds = 0x00;
	stimestructure.TimeFormat = RTC_HOURFORMAT12_AM;
	stimestructure.DayLightSaving = RTC_DAYLIGHTSAVING_NONE;
	stimestructure.StoreOperation = RTC_STOREOPERATION_RESET;

	if (HAL_RTC_SetTime(&RtcHandle, &stimestructure, RTC_FORMAT_BCD) != HAL_OK)
	{
		/* Initialization Error */
		Error_Handler();
	}
}


/*****************************************************************************
* @brief - RTC ?袁⑹삺 ??뮄而?????끉?젟??꼶?뮉 ?겫???겫?
* @param -
* @retval-
******************************************************************************/
static void  RTC_SetTimeConfig(void)
{
	/* Set Time: 02:20:00 */
	stimestructure.Hours = mLed_Process_Flag.sClock_Data.sHours;
	stimestructure.Minutes = mLed_Process_Flag.sClock_Data.sMinutes;
	stimestructure.Seconds = mLed_Process_Flag.sClock_Data.sSeconds;


	if (HAL_RTC_SetTime(&RtcHandle, &stimestructure, RTC_FORMAT_BCD) != HAL_OK)
	{
		/* Initialization Error */
		Error_Handler();
	}

}


/*****************************************************************************
* @brief - RTC ?袁⑹삺 ??뮄而?????끉?젟??꼶?뮉 ?겫???겫?
* @param -
* @retval-
******************************************************************************/
static void RTC_TimeShow(uint8_t* showtime)
{

	/* Get the RTC current Time */
	HAL_RTC_GetTime(&RtcHandle, &stimestructureget, RTC_FORMAT_BCD);
	/* Get the RTC current Date */
	HAL_RTC_GetDate(&RtcHandle, &sdatestructureget, RTC_FORMAT_BCD);
	/* Display time Format : hh:mm:ss */

	 // 23시 59분 59초  다음은 00:00:00 이다.
	if (stimestructureget.Hours == 0x23 && stimestructureget.Minutes == 0x59 && stimestructureget.Seconds == 0x59)
	{
		salarmstructure.AlarmTime.Hours = 0;
		salarmstructure.AlarmTime.Minutes = 0;
		salarmstructure.AlarmTime.Seconds = 0;
	}
	else if (stimestructureget.Minutes == 0x59 && stimestructureget.Seconds == 0x59)
	{
		salarmstructure.AlarmTime.Hours = BIN_BCD(BCD_BIN(stimestructureget.Hours) + 1);
		salarmstructure.AlarmTime.Minutes = 0x0;
		salarmstructure.AlarmTime.Seconds = 0x0;


	}
	else if (stimestructureget.Seconds == 0x59)
	{
		salarmstructure.AlarmTime.Hours = stimestructureget.Hours;
		salarmstructure.AlarmTime.Minutes = BIN_BCD(BCD_BIN(stimestructureget.Minutes) + 1);
		salarmstructure.AlarmTime.Seconds = 0x0;

	}
	else
	{
		salarmstructure.AlarmTime.Hours = stimestructureget.Hours;
		salarmstructure.AlarmTime.Minutes = stimestructureget.Minutes;
		salarmstructure.AlarmTime.Seconds = BIN_BCD(BCD_BIN(stimestructureget.Seconds) + 1);

	}

	HAL_RTC_SetAlarm_IT(&RtcHandle, &salarmstructure, RTC_FORMAT_BCD);

	//MyPrintf_USART1("--------Timer Count : %02d:%02d:%02d \n\r", BCD_BIN(stimestructureget.Hours), BCD_BIN(stimestructureget.Minutes), BCD_BIN(stimestructureget.Seconds));
    
	sprintf(&mLCDPrintBuf[3][0], "%02d:%02d:%02d", BCD_BIN(stimestructureget.Hours), BCD_BIN(stimestructureget.Minutes), BCD_BIN(stimestructureget.Seconds));

}


/*****************************************************************************
* @brief - RTC ?袁⑹삺 ??뮄而?????끉?젟??꼶?뮉 ?겫???겫?
* @param -
* @retval-
******************************************************************************/
void HAL_RTC_AlarmAEventCallback(RTC_HandleTypeDef *RtcHandle)
{


	RTC_TimeShow(aShowTime);

	if (mAlarmAEventCallback_Flag) mAlarmAEventCallback_Flag--;

	if (mLed_Process_Flag.sReClock_Start_Flage)
	{

		//mLed_Process_Flag.sAscii_NorMal_Flag = 1;

		//mLed_Process_Flag.sScroll_Cnt_Finish = 160;

		//sprintf(&mLed_Process_Flag.sRx_PII_Ascii_Buf[0],"%s", completeVersion);
		//sprintf((char *)&mLed_Process_Flag.sRx_PII_Ascii_Buf[0], "  %02d:%02d:%02d  ", BCD_BIN(stimestructureget.Hours), BCD_BIN(stimestructureget.Minutes), BCD_BIN(stimestructureget.Seconds));
		//sprintf(&mLed_Process_Flag.sRx_PII_Ascii_Buf[25], "C - %02d:%02d:%02d    ", BCD_BIN(stimestructureget.Hours), BCD_BIN(stimestructureget.Minutes), BCD_BIN(stimestructureget.Seconds));
       
        
		//mLed_Process_Flag.sAscii_Rx_Cnt++;
	}



}


/*****************************************************************************
* @brief -MX_ADC_DMA_Init
* @param -
* @retval-
******************************************************************************/
void MX_ADC_DMA_Init(void)
{
	/* DMA controller clock enable */
	__HAL_RCC_DMA2_CLK_ENABLE();

	/* DMA interrupt init */
	/* DMA2_Stream0_IRQn interrupt configuration */
	HAL_NVIC_SetPriority(DMA2_Stream0_IRQn, 5, 0);
	HAL_NVIC_EnableIRQ(DMA2_Stream0_IRQn);
    
    
    HAL_NVIC_SetPriority(DMA2_Stream4_IRQn, 6, 0);
	HAL_NVIC_EnableIRQ(DMA2_Stream4_IRQn);
}
/*****************************************************************************
* @brief -MX_ADC1_Init
* @param -
* @retval-
******************************************************************************/
void MX_ADC1_Init(void)
{
	ADC_ChannelConfTypeDef sConfig;
	/*##-1- Configure the ADC peripheral #######################################*/
    
    
	//AdcHandle.Instance = ADC3;
    AdcHandle1.Instance = ADC1;
  
        
	AdcHandle1.Init.ClockPrescaler = ADC_CLOCKPRESCALER_PCLK_DIV2;
	AdcHandle1.Init.Resolution = ADC_RESOLUTION_12B;
	AdcHandle1.Init.ScanConvMode = DISABLE;
	AdcHandle1.Init.ContinuousConvMode = ENABLE;
	AdcHandle1.Init.DiscontinuousConvMode = DISABLE;
	AdcHandle1.Init.NbrOfDiscConversion = 0;
	AdcHandle1.Init.ExternalTrigConvEdge = ADC_EXTERNALTRIGCONVEDGE_NONE;
	AdcHandle1.Init.ExternalTrigConv = ADC_EXTERNALTRIGCONV_T1_CC1;
	AdcHandle1.Init.DataAlign = ADC_DATAALIGN_RIGHT;
	AdcHandle1.Init.NbrOfConversion = 1;
	AdcHandle1.Init.DMAContinuousRequests = ENABLE;
	AdcHandle1.Init.EOCSelection = DISABLE;
      
	if (HAL_ADC_Init(&AdcHandle1) != HAL_OK)
	{
		/* Initialization Error */
		Error_Handler(); 
	}
  
	/*##-2- Configure ADC regular channel ######################################*/
	/* Note: Considering IT occurring after each number of size of              */
	/*       "uhADCxConvertedValue"  ADC conversions (IT by DMA end             */
	/*       of transfer), select sampling time and ADC clock with sufficient   */
	/*       duration to not create an overhead situation in IRQHandler.        */
    
	sConfig.Channel = ADC_CHANNEL_TEMPSENSOR; 
	sConfig.Rank = 1;
	sConfig.SamplingTime = ADC_SAMPLETIME_480CYCLES;
	sConfig.Offset = 0;
    
    if (HAL_ADC_ConfigChannel(&AdcHandle1, &sConfig) != HAL_OK)
	{
		/* Channel Configuration Error */
		Error_Handler(); 
	}
    
	/*##-3- Start the conversion process and enable interrupt ##################*/
	/* Note: Considering IT occurring after each number of ADC conversions      */
	/*       (IT by DMA end of transfer), select sampling time and ADC clock    */
	/*       with sufficient duration to not create an overhead situation in    */
	/*        IRQHandler. */ 
    
    
//	if (HAL_ADC_Start_DMA(&AdcHandle, (uint32_t*)&ADCValue, 1) != HAL_OK)
//	{
//		/* Start Conversation Error */
//		Error_Handler(); 
//	}
//  

}
/*****************************************************************************
* @brief -MX_ADC1_Init
* @param -
* @retval-
******************************************************************************/
void MX_ADC3_Init(void)
{
	ADC_ChannelConfTypeDef sConfig;
	/*##-1- Configure the ADC peripheral #######################################*/
    
    
	AdcHandle3.Instance = ADC3;
        
	AdcHandle3.Init.ClockPrescaler = ADC_CLOCKPRESCALER_PCLK_DIV2;
	AdcHandle3.Init.Resolution = ADC_RESOLUTION_12B;
	AdcHandle3.Init.ScanConvMode = DISABLE;
	AdcHandle3.Init.ContinuousConvMode = ENABLE;
	AdcHandle3.Init.DiscontinuousConvMode = DISABLE;
	AdcHandle3.Init.NbrOfDiscConversion = 0;
	AdcHandle3.Init.ExternalTrigConvEdge = ADC_EXTERNALTRIGCONVEDGE_NONE;
	AdcHandle3.Init.ExternalTrigConv = ADC_EXTERNALTRIGCONV_T1_CC1;
	AdcHandle3.Init.DataAlign = ADC_DATAALIGN_RIGHT;
	AdcHandle3.Init.NbrOfConversion = 1;
	AdcHandle3.Init.DMAContinuousRequests = ENABLE;
	AdcHandle3.Init.EOCSelection = DISABLE;
      
	if (HAL_ADC_Init(&AdcHandle3) != HAL_OK)
	{
		/* Initialization Error */
		Error_Handler(); 
	}
  
	/*##-2- Configure ADC regular channel ######################################*/
	/* Note: Considering IT occurring after each number of size of              */
	/*       "uhADCxConvertedValue"  ADC conversions (IT by DMA end             */
	/*       of transfer), select sampling time and ADC clock with sufficient   */
	/*       duration to not create an overhead situation in IRQHandler.        */
    
	sConfig.Channel = ADC_CHANNEL_0; 
	sConfig.Rank = 1;
	sConfig.SamplingTime = ADC_SAMPLETIME_480CYCLES;
	sConfig.Offset = 0;
    
    if (HAL_ADC_ConfigChannel(&AdcHandle3, &sConfig) != HAL_OK)
	{
		/* Channel Configuration Error */
		Error_Handler(); 
	}
}

/*****************************************************************************
* @brief - HAL_ADC_ConvCpltCallback
* @param - temp = (float)ADCValue[0]*3.3/(float)4096;
 	       ANS_AdcCH1_Data = (uint16_t)(temp*10);
* @retval-
******************************************************************************/
uint32_t rawValue;
__IO uint16_t ANS_AdcCPU_Data;

void HAL_ADC_ConvCpltCallback(ADC_HandleTypeDef* hadc)
{
    
	float temp;
    float volt;
    float v25 = 1.43;
    float avg_slope = 4.3;
    
	uhADCxConvertedValue_Cnt++;
    
	//rawValue = HAL_ADC_GetValue(&hadc1);
    
	temp = (float)ADCValue3[0] * 3.3 / (float)4096;
	ANS_AdcCH1_Data = (uint16_t)(temp * 10);
	
	//sprintf(&mLCDPrintBuf[3][0],"%04d",ADCValue[0]);
    
	//temp = (float)ADCValue[0]*3.3/(float)4095;
	//volt = (uint16_t)(((float)ADCValue1[0] * 8) / 10000);
    
   // volt = (float)ADCValue[0]*(3.3/(float)4095);
   // temp = (((v25-volt)*1000)/avg_slope)+25;//+25.0;
 //	ANS_AdcCPU_Data = (uint16_t)temp;
    
    volt = (float)ADCValue1[0] * 3.3 / 0xfff;
    ANS_AdcCPU_Data = (volt-0.76)/0.0025 + 25.0;
 
    mLed_Process_Flag.sCpu_Temp = ANS_AdcCPU_Data;
    
     
	if (ADCValue3[0] > 2200)
	{
		if (mAnsSetFlag.tAnsCnt < 30) mAnsSetFlag.tAnsCnt++;
	}
	else
	{
		if (mAnsSetFlag.tAnsCnt) mAnsSetFlag.tAnsCnt--;
        
	}

    
    HAL_ADC_Stop_DMA(&AdcHandle1);
    HAL_ADC_Stop_DMA(&AdcHandle3);
	
}


/*****************************************************************************
* @brief - Error_Handler
* @param -
* @retval-
******************************************************************************/
void AUDIO_AMP_Boot_Set(void)
{
    uint8_t     nRbuf_1[2];
    
    //--------------AMP IC 추기 설정 부분.
	setAMP_Standby(true); // 모든 AMP IC
    HAL_Delay(10);
    setAMP_Standby(false); // 모든 AMP IC
    HAL_Delay(10);
    setAMP_Standby(true); // 모든 AMP IC
    
    njw1192_default_value();
    HAL_Delay(10);
    
    
    
    //-------AMP----------
	AMP_Init(AMP_ID_1);
    
    HAL_Delay(100);
	//AMP MUTE

    AMP_Mute_ON(AMP_ID_1, AMP_CH_All, AMP_ID_2, AMP_CH_All, AMP_ID_3, AMP_CH_All); // amp ic all mute
	
    HAL_Delay(100);
    
    nRbuf_1[0] = 0xFF;
    I2C_HAL_ReadBytes(&hi2c2, AMP_ID_1, 0x06, (uint8_t *)nRbuf_1, 1);
    MyPrintf_USART1("getAmp1 Mode read :%02X \r\n", nRbuf_1[0]); 

    nRbuf_1[0] = 0xFF;
    I2C_HAL_ReadBytes(&hi2c2, AMP_ID_2, 0x06, (uint8_t *)nRbuf_1, 1);     
    MyPrintf_USART1("getAmp2 Mode read :%02X \r\n", nRbuf_1[0]); 

    nRbuf_1[0] = 0xFF;
    I2C_HAL_ReadBytes(&hi2c2, AMP_ID_3, 0x06, (uint8_t *)nRbuf_1, 1);
    MyPrintf_USART1("getAmp3 Mode read :%02X \r\n", nRbuf_1[0]); 
   
    //setAMP_Standby(false); // 모든 AMP IC
	
    
    setBk_Out_1(false);
    setBk_Out_3(false);
    setBk_Out_5(false);

    setBk_Out_6(false);
        

    
	// AUDIO IC MUTE 기능 OFF 초기화
	setAmp_Mute_1(true);
	setAmp_Mute_2(true);
    
    njw1192_mute(true); // Audio Mute 
    //-----------------------------------
}
/*****************************************************************************
* @brief - Error_Handler
* @param -
* @retval-
******************************************************************************/
void Error_Handler(void)
{
    /* Turn LED5 on */
    while(1)
    {
    }
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t* file, uint32_t line)
{
	/* User can add his own implementation to report the file name and line number,
	   ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */

	 /* Infinite loop */
	while (1)
	{
	}
}
#endif

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
