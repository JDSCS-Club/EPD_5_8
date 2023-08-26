

/*
    ******************************************************************************
    * @Company              : Woojin Industrial Systems Co., Ltd.
    * @Engineer             : D.S.JANG
    * @ModuleName           : LED.h
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


#ifndef __LED_H__
#define __LED_H__


#ifdef __cplusplus
 extern "C" {
#endif
   
   

//#include "stm32f4xx_hal.h"




#define ALL_DISPLAY_SIZE 6144
#define HALF_DISPLAY_SIZE 3072


//#define ALL_DOTPRINT_ADDRESS 0x20010000
//#define ALL_DISPLAY_ADDRESS  0x20011800 
//#define ALL_DISPLAY_ADDRESSDown  0x20012400
//#define ALL_DISPLAY_ADDRESS_DOWN_SCROLDATA  0x20013000




void LED_GPIO_Init(void);
void LED_init(void);

void LED_SCREEN_PRINT(void);
	

void LED_Imag_ScreenUp(uint8_t *Imag);
void LED_Imag_ScreenDown(uint8_t *Imag);
void LED_Imag_ScreenScroll(void);
uint8_t LED_Imag_ScreenScroll_Cnt(void);
uint8_t LED_Imag_ScreenNormal_Cnt(void);

void LED_Imag_ScreenUp_16Font(uint8_t *Imag);



void LED_Block_Screen_Buf(void);
void LED_FONT_POSITION(uint8_t *nAscii_Len_Buf);
uint8_t LED_Pattern_TEST(void);

void LED_Timer_1ms(void);

extern char mStringBuf[15][40] ;




//// PII 표출 문장 정리
//typedef struct
//{
//	uint8_t s16_Dot[1][160];
//}PRINT_DOT16;
//
//
//typedef struct
//{
//	PRINT_DOT16 nLine[32];
//
//}FDI_SCREEN_BOKCK, *pFDI_SCREEN_BOKCK;

///////////////////////////////////////////////////
// FDI LED 모듈 출력 구조체
//
///////////////////////////////////////////////////

typedef struct
{
	uint8_t s16_Dot[12][16];
}PRINT_DOT16;


typedef struct
{
	PRINT_DOT16 nLine[32];

}FDI_SCREEN_BOKCK, *pFDI_SCREEN_BOKCK;


/////////////////////////////////////////////////

//extern int mLed_PatternFlag;
//extern int mLed_PatternFlag_Cnt;
//extern int mLed_PatternTimeFlagCnt;
//
//extern int mLed_BlinkFlag;








#ifdef __cplusplus
}
#endif



#endif




