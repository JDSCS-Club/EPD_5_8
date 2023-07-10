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
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/

#include "stm32f4xx_hal.h"
#include "stm324xg_eval.h"
#include "stm324xg_eval_lcd.h"
#include "lwip/udp.h"
#include "udp_echoclient.h"
	 
#include "string.h"
#include "USRAT.h"
     
#include "I2C.h"

#include "stdio.h"
#include "debug_task.h"

     
     
#include <stdio.h>
#include "stdbool.h"
     



enum AMP_MUTE
{
    AMP_ID_0        =   0x00,
	AMP_ID_1		=	0xD8,
    AMP_ID_2		=	0xDA,
    AMP_ID_3		=	0xDC,
    
    AMP_CH_All      =   0x00,
    AMP_CH_1        =   0x01,
    AMP_CH_2        =   0x02,
    
};

   
extern uint8_t IP_ADDR1_INPUT_DATA;
extern uint8_t IP_ADDR2_INPUT_DATA;
//extern uint8_t IP_ADDR3_INPUT_DATA;
//extern uint8_t IP_ADDR4_INPUT_DATA;


extern uint32_t IP_ADDR_VAL_DATA;



//extern I2C_HandleTypeDef hi2c1;
//extern I2C_HandleTypeDef hi2c2;

extern ADC_HandleTypeDef AdcHandle1;
extern DMA_HandleTypeDef hdma_adc1;

extern ADC_HandleTypeDef AdcHandle3;
extern DMA_HandleTypeDef hdma_adc3;


extern __IO uint16_t ADCValue[6];

	 
/* Exported types ------------------------------------------------------------*/

#define NOT(a)		(~a & 0x0001)
    
// 장치 공통 식별 코드
#define FDI_UNIT_KODE 1
#define SDI_UNIT_KODE 2
#define PII_UNIT_KODE 3
        
#define MAKE_5_BYTE(B1,B2,B3,B4,B5) (((B1&0xff)<<32) | ((B2&0xff)<<24) | ((B3&0xff)<<16) | ((B4&0xff)<<8) | ((B5)&0xff))
#define MAKE_DWORD(HH,HL,LH,LL)	(((HH)<<24) | ((HL&0xff)<<16) | ((LH&0xff)<<8) | ((LL)&0xff))
#define MAKE_WORD(H,L) (((H << 8) | (L & 0xff)) & 0xffff)
#define MAKE_BYTE(H,L) (((H << 4) | (L & 0x0f)) & 0xff)

#define BYTE_H(HL) (((HL)>>4) & 0xf)
#define BYTE_L(HL) ((HL) & 0xf)

#define WORD_H(HL) (((HL)>>8) & 0x0ff)
#define WORD_L(HL) ((HL) & 0x0ff)

#define DWORD_H(HL) (((HL)>>16) & 0xffff)
#define DWORD_L(HL) ((HL) & 0xffff)

#define DWORD_MASKING(HL) ((HL)&0xffffffff)

#define max(a,b)		(((a) > (b)) ? (a) : (b))
#define min(a,b)		(((a) < (b)) ? (a) : (b))



/* AMP 관련  ------------------------------------------------------------*/
#define TEST_ROOM 0 // 0 == 현차 -- 1 == 양산. 관련  응량 설정 하는 부분. 관리.
#define AMP_H_TEMP 1 // 0 == 저온 동작 조건 / 1 == 고온 동작 조건 ( 저온 동작 조건에서 고장 발생 하는 장치에 대하여 적용)


/* Exported constants --------------------------------------------------------*/
//#define USE_LCD        /* enable LCD  */  

//#define DEST_IP_ADDR0   10
//#define DEST_IP_ADDR1   128
//#define DEST_IP_ADDR2   100
//#define DEST_IP_ADDR3   100

#define DEST_IP_ADDR0   255
#define DEST_IP_ADDR1   255
#define DEST_IP_ADDR2   255
#define DEST_IP_ADDR3   255

#define UDP_SERVER_PORT    30013   /* define the UDP local connection port */
#define UDP_CLIENT_PORT    30013   /* define the UDP remote connection port */   
   

#define DEST_PORT       30013


#define USE_DHCP      1 /* enable DHCP, if disabled static address is used */


#define JDS_DEBUG 1


/*Static IP ADDRESS: IP_ADDR0.IP_ADDR1.IP_ADDR2.IP_ADDR3 */
#define IP_ADDR0   (uint8_t) 10
#define IP_ADDR1   (uint8_t) 128
#define IP_ADDR2   (uint8_t) (IP_ADDR1_INPUT_DATA & 0x0F) //((IP_ADDR4_INPUT_DATA<<4)|IP_ADDR3_INPUT_DATA)
#define IP_ADDR3   (uint8_t) ((IP_ADDR2_INPUT_DATA & 0x01) ? 96 : 97)
   
   
/*NETMASK*/
#define NETMASK_ADDR0   (uint8_t) 255
#define NETMASK_ADDR1   (uint8_t) 255
#define NETMASK_ADDR2   (uint8_t) 0
#define NETMASK_ADDR3   (uint8_t) 0

/*Gateway Address*/
#define GW_ADDR0   (uint8_t) 10 //10
#define GW_ADDR1   (uint8_t) 0 //61
#define GW_ADDR2   (uint8_t) 0 //0
#define GW_ADDR3   (uint8_t) 1 //1


#define MAC_ADDR0   0x18
#define MAC_ADDR1   0x30
#define MAC_ADDR2   0x09 + (IP_ADDR_VAL_DATA>>24)&0xFF
#define MAC_ADDR3   0    + (IP_ADDR_VAL_DATA>>16)&0xFF
#define MAC_ADDR4   0x32 + (IP_ADDR_VAL_DATA>>8)&0xFF
#define MAC_ADDR5   0x28 + (IP_ADDR_VAL_DATA>>0)&0xFF


///*****************************************************************************
//* @brief - 메모리 구조 정리.
//* @param -
//* @retval-
// 0x2000 0000 ~ 
//                  0x2001 0000    : 64kByte : 프로그램 코드 영역.(프로그램 추가 하면 증가 할수 있다.)
// 0x2001 0000 ~ 
//                  0x2001 0400    : Heap 영역 0x400(1024)
// 0x2001 0400 ~ 
//                  0x2001 2400    : Stack 역역. 0x2000(8192)
//
// 0x2001 2500 ~ 
// 
//
// 0x2001 3400 ~
//                  0x2001 5800 //버전 정보 현시 화면 버퍼.(6144+3072 = 9216 / 0x2400)
// 0x2001 5800 ~
//                  0x2001 7000 // 화면 출력 버퍼.(6144)
//0x2001 7000 ~ 
//                 
//                  0x2002 0000 // 화면 스크림  버퍼.  (6144 * 6 화면 = 36kbyte)
//******************************************************************************/

#define SRAM_USED_TO  0x20012500 // 사용자 사용 영역.



#define SRAM_USER_TO_VER_OUT    0x20013400 //버전 정보를 현시 하는 주소.

#define SRAM_USED_TO_SCREEN_OUT 0x20015800 // 스트린 출력 데이타 구조 정렬.(6144) 336 FDI 32*32 * 6ea   따라서 SEPTA ML FDI 보다 2배큰 버퍼 필요.

#define SRAM_USED_TO_STREAM_BUF 0x20017000 // 스트림 버퍼 시작 주소.
// ~~~~~~~~~
// 스트림 버퍼(18kByte)~
// ~~~~~~~~~
// 0x20020000 // SRAM 끝.


/* Exported types ------------------------------------------------------------*/
/* Exported constants --------------------------------------------------------*/
/* Uncomment to enable the adaquate RTC Clock Source */
#define RTC_CLOCK_SOURCE_LSE
/* #define RTC_CLOCK_SOURCE_LSI */

#ifdef RTC_CLOCK_SOURCE_LSI
#define RTC_ASYNCH_PREDIV  0x7F
#define RTC_SYNCH_PREDIV   0x0130
#endif

#ifdef RTC_CLOCK_SOURCE_LSE
#define RTC_ASYNCH_PREDIV  0x7F
#define RTC_SYNCH_PREDIV   0x00FF
#endif




 
//GPOP 내용 설정. 
//ADDRESS 입력 스위치
#define ID_SWITCH_1_0              GPIO_PIN_3
#define ID_SWITCH_1_0_Port               GPIOE

#define ID_SWITCH_1_1              GPIO_PIN_4
#define ID_SWITCH_1_1_Port               GPIOE

#define ID_SWITCH_1_2              GPIO_PIN_5
#define ID_SWITCH_1_2_Port               GPIOE

#define ID_SWITCH_1_3              GPIO_PIN_6
#define ID_SWITCH_1_3_Port               GPIOE


#define ID_SWITCH_2_0              GPIO_PIN_7
#define ID_SWITCH_2_0_Port               GPIOE

#define ID_SWITCH_2_1              GPIO_PIN_8
#define ID_SWITCH_2_1_Port               GPIOE

#define ID_SWITCH_2_2              GPIO_PIN_9
#define ID_SWITCH_2_2_Port               GPIOE

#define ID_SWITCH_2_3              GPIO_PIN_10
#define ID_SWITCH_2_3_Port               GPIOE


#define ID_SWITCH_3_0              GPIO_PIN_11
#define ID_SWITCH_3_0_Port               GPIOE

#define ID_SWITCH_3_1              GPIO_PIN_12
#define ID_SWITCH_3_1_Port               GPIOE

#define ID_SWITCH_3_2              GPIO_PIN_13
#define ID_SWITCH_3_2_Port               GPIOE

#define ID_SWITCH_3_3              GPIO_PIN_14
#define ID_SWITCH_3_3_Port               GPIOE




// PICTO 
#define PICTO_LED1                 GPIO_PIN_7
#define PICTO_LED1_Port                 GPIOD 

#define PICTO_LED2                 GPIO_PIN_10
#define PICTO_LED2_Port                 GPIOD 

#define PICTO_LED3                 GPIO_PIN_11
#define PICTO_LED3_Port                 GPIOD 

#define PICTO_LED4                  GPIO_PIN_0
#define PICTO_LED4_Port                 GPIOE 

#define PICTO_LED5                  GPIO_PIN_1
#define PICTO_LED5_Port                 GPIOE 

///////////////////////////////

#define STATUS_LED                  GPIO_PIN_11 
#define STATUS_LED_Port                 GPIOA 

#define TEST_MODE                   GPIO_PIN_8 
#define TEST_MODE_Port                  GPIOB 

#define MODE_SET                    GPIO_PIN_0
#define MODE_SET_Port                   GPIOD

/* Private defines -----------------------------------------------------------*/
//#define SPI1_SCK_Pin            GPIO_PIN_5
//#define SPI1_SCK_               GPIO_Port GPIOA
//#define SPI1_MISO_Pin           GPIO_PIN_6
//#define SPI1_MISO_GPIO_Port     GPIOA
//#define SPI1_MOSI_Pin           GPIO_PIN_7
//#define SPI1_MOSI_GPIO_Port     GPIOA
//#define IIC_SCL_SOFT_Pin        GPIO_PIN_6
//#define IIC_SCL_SOFT_GPIO_Port  GPIOC
//#define IIC_SDA_SOFT_Pin        GPIO_PIN_8
//#define IIC_SDA_SOFT_GPIO_Port  GPIOC

//#define OLED_DC_Pin             GPIO_PIN_8
//#define OLED_DC_GPIO_Port       GPIOA
//#define OLED_RST_Pin            GPIO_PIN_9
//#define OLED_RST_GPIO_Port      GPIOA
//#define OLED_CS_Pin             GPIO_PIN_6
//#define OLED_CS_GPIO_Port       GPIOB
//#define I2C1_SCL_Pin            GPIO_PIN_8
//#define I2C1_SCL_GPIO_Port      GPIOB
//#define I2C1_SDA_Pin            GPIO_PIN_9
//#define I2C1_SDA_GPIO_Port      GPIOB
         
/* Exported macro ------------------------------------------------------------*/
/* Exported functions ------------------------------------------------------- */
   
void Time_Main(void);
    





void UDPdebug_print_JDS(struct udp_hdr *udphdr);
    

void Error_Handler(void);

extern char mLCDPrintBuf[4][128];
extern char mLCDPrintBuf_2[2][128];
extern const unsigned char completeVersion[];
extern const unsigned char completeVersionBuild[];


extern uint8_t mDI_CheckFlag;

void ONTD(uint8_t IN,uint8_t *OUT,uint8_t MS,int *CLK );

void PRINT_SYSLOG(char *format, ...);


void AUDIO_AMP_Boot_Set(void);

///*****************************************************************************
//* @brief - 통신 수신 구조체 선언 부분.
//* @param -
//* @retval-
//******************************************************************************/
typedef union
{
    uint8_t Byte;
    struct
    {
        uint8_t L_4bit:4;
        uint8_t H_4bit:4;
        
    }b;
   
}BCD_4Bit;


typedef struct
{
    BCD_4Bit sYY;
    BCD_4Bit sMM;
    BCD_4Bit sDD;
    BCD_4Bit shh;
    BCD_4Bit smm;
    BCD_4Bit sss;
    
}TIMEE_BDC;



typedef union
{
      uint8_t Byte;   
      struct
      {
      
        uint8_t reset:1;     
        uint8_t Bit1:1; 
        uint8_t Bit2:1;     
        uint8_t Bit3:1;    
        uint8_t ScreenOff:1;  
        uint8_t Bit5:1;    
        uint8_t Bit6:1;  
        uint8_t Pattern:1;             
                   
      }b;  
      
} ServerComand_04;

///////////////////////////////////////////////////
typedef union
{
   
      uint8_t Byte;      
      struct
      {
        
        uint8_t RytryUpDataFlag:1;    
        uint8_t Bit1:1;  
        uint8_t Bit2:1;      
        uint8_t Bit3:1;   
        uint8_t Bit4:1;  
        uint8_t Bit5:1;     
        uint8_t Bit6:1;  
        uint8_t UpDataFlag:1;  
                 
      } b;    
           
} ServerComand_05;

///////////////////////////////////////////////////


typedef struct
{
	uint8_t H_CRC;
    uint8_t L_CRC;

}CRC_BLK;

typedef struct
{
	uint8_t H_Address;
    uint8_t L_Address;

}BLICK_ADD;


typedef struct
{
	uint8_t sSDR_TYPE_00;
    
	uint8_t sTrainID;  // 0 ~ 9  
	uint8_t sPosition; // L = 0 /R = 1
    
    uint8_t sSDR_Command_03;
    

    TIMEE_BDC sTime;
    
    
     //----------------------
    uint8_t sCM1_TestStartFlag: 1;
    uint8_t sCM1_Sp: 6;
    uint8_t sCM1_ANSMFlag:1;
    
    //----------------------
    uint8_t sCM2_Sp:6;
    uint8_t sCM2_Vol_SET_Flag:1;
    uint8_t sCM2_INPUT_GAIN_SET_Flag:1;
    
    //----------------------
    uint8_t sCM3_VOL_SET_Val: 6;
    uint8_t sCM3_INPUT_GAIN_SET_Val:2;
    
     //----------------------
    
    uint8_t sCM4_VOL2RL: 4;
    uint8_t sCM4_VOL2FL: 4;
     //----------------------
    
    uint8_t sCM5_TONE_TREBLE_SET_Val: 3;
    uint8_t sCM5_BCT_SET_Flag: 1;
    uint8_t sCM5_TONE_BASS_SET_Val:3;
    uint8_t sCM5_BCB_SET_Flag:1;
     //----------------------
    
    uint8_t sWatchdog_Cnt;

    
    
}mETHERNET_RX_STRUCT, *pmETHERNET_RX_STRUCT;


///*****************************************************************************
//* @brief - 통신 응답 구조체 선언 부분.
//* @param -
//* @retval-
//******************************************************************************/

typedef union
{

    uint8_t Byte;        
    struct
    {

        uint8_t sSelf_Testing:1;    
        uint8_t Bit1:1;         
        uint8_t Bit2:1;    
        uint8_t Bit3:1;    
        uint8_t sSelfTest_OK:1;  
        uint8_t sSelfTest_NG:1; 
        uint8_t Bit6:1;  
        uint8_t Bit7:1;  
       
    } b; 
           
} LED_Comand_02;


typedef union
{

        uint8_t Byte;    
        
        struct
        {

            uint8_t sStarted:1;  
            uint8_t sPrecess:1;      
            uint8_t sComplete:1;      
            uint8_t Bit3:1;
            uint8_t sBlock_OK:1;     
            uint8_t sBlock_NG:1;  
            uint8_t Bit6:1;  
            uint8_t Bit7:1;  
             
        } b;                            

} LED_Comand_03;



typedef union
{

    uint8_t Byte;   
    struct
    {
        uint8_t sbit1:1; 
        uint8_t sbit2:1;
        uint8_t sbit3:1; 
        uint8_t sbit4:1;  
        uint8_t sbit5:1; 
        uint8_t sbit6:1;   
        uint8_t sbit7:1; 
        uint8_t sbit8:1;  
                 
    } b;                            

}CRC_STATE_08; //CRC 응답 시작.


typedef union
{

    uint8_t Byte;
    struct
    {

        uint8_t sbit9:1;    
        uint8_t sbit10:1; 
        uint8_t sbit11:1;
        uint8_t sbit12:1; 
        uint8_t sbit13:1; 
        uint8_t sbit14:1;
        uint8_t sbit15:1;
        uint8_t sbit16:1;                 
                    
    } Bit;                            

}CRC_STATE_09;


typedef union
{

    uint8_t Byte;
    struct
    {
        uint8_t sbit17:1;
        uint8_t sbit18:1;  
        uint8_t sbit19:1;
        uint8_t sbit20:1; 
        uint8_t sbit21:1;
        uint8_t sbit22:1;
        uint8_t sbit23:1;  
        uint8_t sbit24:1;  
          
    } Bit;                            
            
}CRC_STATE_10;

typedef union
{

    uint8_t Byte;
    struct
    {
        uint8_t sbit25:1;
        uint8_t sbit26:1;  
        uint8_t sbit27:1;
        uint8_t sbit28:1; 
        uint8_t sbit29:1;
        uint8_t sbit30:1;
        uint8_t sbit31:1;  
        uint8_t sbit32:1;  
          
    } Bit;                            
            
}CRC_STATE_11;


typedef union
{

    uint8_t Byte;
    struct
    {
        uint8_t sbit33:1;
        uint8_t sbit34:1;  
        uint8_t sbit35:1;
        uint8_t sbit36:1; 
        uint8_t s04:1;
        uint8_t s05:1;
        uint8_t s06:1;  
        uint8_t s07:1;  
          
    } Bit;                            
            
}CRC_STATE_12;





typedef struct
{
    CRC_STATE_08 sBlock_State_1;
    CRC_STATE_09 sBlock_State_2;
    CRC_STATE_10 sBlock_State_3;
    CRC_STATE_11 sBlock_State_4;
    CRC_STATE_12 sBlock_State_5;
    
}CRC_PUBLIC_STRUCT;



typedef union
{
  struct
  {
  
    uint8_t sH:4;  
    uint8_t sL:4;  
 
  } Bit;                            
  uint8_t Byte;                     
}VER_SION_DATA_TYPE;

typedef struct
{
	uint8_t sYear;
    uint8_t sMonth;
    uint8_t sDay;
    
    VER_SION_DATA_TYPE sMajor;
    VER_SION_DATA_TYPE sMinor;
    VER_SION_DATA_TYPE sRevision;

}VER_SION_DATE;


typedef struct
{
	uint8_t sSR_TYPE_00;
    
	uint8_t sTrainID;  // 0 ~ 9  
	uint8_t sPosition; // L = 0 /R = 1
    
    uint8_t sSR_Command_03;
    
    

    TIMEE_BDC sTime;
    
    
     //----------------------
    uint8_t sCM1_TestStartFlag: 1;
    uint8_t sCM1_Sp: 6;
    uint8_t sCM1_ANSMFlag:1;
    
    //----------------------
    uint8_t sCM2_Sp:6;
    uint8_t sCM2_Vol_SET_Flag:1;
    uint8_t sCM2_INPUT_GAIN_SET_Flag:1;
    
    //----------------------
    uint8_t sCM3_VOL_SET_Val: 6;
    uint8_t sCM3_INPUT_GAIN_SET_Val:2;
    
     //----------------------
    
    uint8_t sCM4_VOL2RL: 4;
    uint8_t sCM4_VOL2FL: 4;
     //----------------------
    
    uint8_t sCM5_TONE_TREBLE_SET_Val: 3;
    uint8_t sCM5_BCT_SET_Flag: 1;
    uint8_t sCM5_TONE_BASS_SET_Val:3;
    uint8_t sCM5_BCB_SET_Flag:1;
     //----------------------
    
    uint8_t sCM6_Sp;
     //----------------------
    uint8_t sCM7_PAMP_Run_Current;
    
     //----------------------
    
    uint8_t sCM8_Self_Test_SP3_St:1;  // 스피키 상태 정보.
    uint8_t sCM8_Self_Test_SP2_St:1;  // 스피키 상태 정보.
    uint8_t sCM8_Self_Test_SP1_St:1;  // 스피키 상태 정보.
    uint8_t sCM8_Sp:4;
    uint8_t sCM8_Self_TestFlag:1;
    
     //----------------------
    
    uint8_t sCM9_Out_SP_St:1;  // 스피키 상태 정보.
    uint8_t sCM9_In_SP3_St:1;  // 스피키 상태 정보.
    uint8_t sCM9_In_SP2_St:1;  // 스피키 상태 정보.
    uint8_t sCM9_In_SP1_St:1;
    uint8_t sCM9_Sp:4;

    
    VER_SION_DATE sVerData;
    
    uint8_t sWatchdog_Cnt;


}mETHERNET_TX_STRUCT, *pmETHERNET_TX_STRUCT;



extern pmETHERNET_RX_STRUCT pmEthernet_Rx_struct;
extern mETHERNET_TX_STRUCT mEthernet_Tx_struct;
   

typedef struct
{

	uint8_t sHours;
	uint8_t sMinutes;
	uint8_t sSeconds;

}RTC_TIME;




///*****************************************************************************
//* @brief - 통신 응답 구조체 선언 부분.
//* @param -
//* @retval-
//******************************************************************************/
typedef struct
{
    uint8_t sMy_IP_Info;
    ip4_addr_t sDestIPaddr; // 
    
    uint16_t sEth_Rx_Cnt;   // 통신이 한번 이라도 동작 하면,   기록 한다.
    uint8_t sEth_Rx_RESET_Flag; // 통신 설정 이상 이라고 판단 하고, 설정   값을 리 셋 한다.
    uint8_t sEth_UpLInk_Cnt; // 통신이 UP 된 상태에서, 카운터를 시작 한다.


    uint8_t sEth_Rx_Flag;               //통신 상태 플레그
    uint8_t sEth_Rx_Request_Flag;       // 상태 데이타 응답 플레그
    uint16_t sEth_Rx_Finish_TimeCnt;    // 이미지 데이타 수신 완료 시간을 확인 하다, 3초 동안 수신이 없으면 종결로  처리.

    uint16_t sScreen_Play_Time;         //표출 시간.
    uint8_t sScreen_Max_Page;           //통신 으로 수신한 데이타 카운터 총 카운터 .
    uint8_t sScreen_CrcCheck_Mac_Page;  // CRC 값을 확인 하여 체크한  max page
    uint8_t sScreen_Display_Data_Page;
    
    uint8_t sScreen_Page_Cnt;           //현재 표출 해야 하는 페이지 카운트
    uint8_t sScreen_ScanFlag;           //표출 시간에 한번식 동작.
    
     // 통신으로 수시한 페이지 싱크 비트
    uint8_t sScreen_Page_Cnt_Rx_Comand_Flag;
    uint8_t sScreen_Page_Cnt_Rx_Comand;
    uint8_t sScreen_Page_Cnt_Rx_ReComand;
    uint8_t sScreen_Page_Check_Buf[18];
    
    

//    CRC_BLK sLed_CRC_Calculation[36];   //LED 가 계산한 CRC 값.
//    CRC_PUBLIC_STRUCT sCrc_Public_Struct; // 각 블럭 CRC 검사 결과.

//    uint16_t sStart_Blk_Add;            // 통신수신 데이타 주소 값 
//    uint16_t sRx_Blk_Add_Buf[36];       //통신으로 수신한 주소 데이타를 버퍼  한다.
//    uint16_t sDefault_Blk_Add_Buf[36];  //각 장치 마다 기본 버퍼 주소.
//    uint8_t  sRx_Blk_Add_Cnt;           // 통신 이미지 수산 카운터.
      uint8_t  sRx_Public_Buf[100];        // 프로토콜 수신 데이타 버퍼.
    
    
    uint8_t  sAscii_Code_Flag;          // PII 에서 문자를 수신 확인 하기 위해 사용.
    uint8_t  sRx_PII_Ascii_Buf[384];    //PII 에서 버퍼 데이타 수신 보관 하는 버퍼.
    uint16_t sScroll_Cnt_Finish;        //스크롤 진행 중인지 확인 하는 부분//
    uint8_t  sAscii_Rx_Cnt;             //문자 통신 수신 카운터
    uint8_t  sAscii_Re_Rx_Cnt;          //문자 통신 수신 카운터 기억
    uint8_t  sAscii_Color_Code;         //수신한 문자 칼라 코드.
    int16_t sAscii_Char_RxLen;         // 수신한 총 문자
    uint8_t  sAscii_NorMal_Flag;        //버번 현시를 위해 사용 하는 Flag
    
    uint8_t sPattern_Test_Flag;
    uint8_t sPattern_Test_ColorData; //패턴 TEST 칼라 코드 값을 확인 한다.

    uint8_t sClock_Start_Flage;
    uint8_t sReClock_Start_Flage; //동작 상태를 현시 하는 변수.
    RTC_TIME sClock_Data; // 시,분,초 값을 가지고 있는 변수.
    
    uint8_t sDhcp_Complete; //DHCP 체크 기능 완료 되었는지 확인 하는 기능.
    
    uint8_t sOLED_Display_Flag;
    
    
    
    //통신 데이타  처리 변수.
    
    uint8_t sAnsm_Run_Flag; //ANSM 기능 동작 여부를 통신으로 수신하여 적용.
    
    uint8_t tAmp_Vol_UpFlag; // ANSM MIC input Count
    
    
    //----------------AMP I2C Read 스피커 상태 정보를 체크 한다.
    uint8_t sRom_Spk_Flag;
    uint8_t sOut_Spk_Flag;
    uint8_t sSt_Buf_Val[4]; // 스피커 상태 정보 버퍼.
    uint8_t sSpk_check_Cnt; //스피커 동작 시간을 체크 하고 일정 시간이 지나면 상태 체크를 한다.
    uint8_t sSpk_check_Flag; //스피커 상태 정보 갱신을 확인 하는 플레그.
    
    uint16_t sCpu_Temp; // Cpu 온도 
    
    uint8_t sAudio_Play_mode;
    uint8_t sAmp_Fault_Cnt; //5회 동안 (5초) 계속 고장이면, 초기화 한다.
    uint8_t sAmp_Falut_val; //고장 AMP 위치를 기억.
    uint8_t sAmp_Fault_Cnt_All; // 5SET 5회 게속 고장이며,  시스템 RESET 한다.
    
    uint8_t sDHCP_IP_Val;
    uint8_t sTrainID;
    
    uint8_t sCurrentTestFlag; // PTT 시험을 시작 하는 플레그.
    uint16_t sCurrentVal; // top Pcb 전체 전류를 측정 한다.
    
    
}mLED_PROCESS_Flag;



extern mLED_PROCESS_Flag mLed_Process_Flag;

	 
	 
///*****************************************************************************
//* @brief - 통신 응답 구조체 선언 부분.
//* @param -
//* @retval-
//******************************************************************************/
	 typedef struct
	 {
		 uint8_t tAnsCnt;
		 uint8_t tAnsFlgSet;
		 
	 }AnsSetFlag;
	 
	 extern AnsSetFlag mAnsSetFlag;
	 
	 ///*****************************************************************************
//* @brief - 통신 응답 구조체 선언 부분.
//* @param -
//* @retval-
//******************************************************************************/
#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */


/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/

