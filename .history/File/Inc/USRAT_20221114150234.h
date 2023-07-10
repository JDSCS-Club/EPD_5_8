

/*
    ******************************************************************************
    * @Company              : Woojin Industrial Systems Co., Ltd.
    * @Engineer             : D.S.JANG
    * @ModuleName           : USRAT.h
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

#ifndef __USRAT_H__
#define __USRAT_H__


#ifdef __cplusplus
 extern "C" {
#endif
   


#include "stm32f4xx_hal.h"

//#define USART1_IRQHandler                USART1_IRQHandler
//#define USART3_IRQHandler                USART3_IRQHandler 
//#define UART4_IRQHandler                 UART4_IRQHandler

#define USART_BUF_Get 5
#define USART_BUF_MIN 256
#define USART_BUF_MAX 500

#define TRUE		1
#define FALSE		0

#define STX 	0x02 
#define ETX 	0x03



#define RING_BUF_SIZE 50


/******************************************************************
	TX_RX ????
*******************************************************************/
typedef struct
{
	uint16_t nTxPos;         // 전송하는 현재 위치.
	uint16_t nTxLen;         // 전송 전체 길이.
	uint8_t nTxOK;          // TX 완료.
	uint8_t nTxOK_Cnt;      // 전체 전송 카운터.
	uint8_t nTx_Rts_Off;    // -------
	uint8_t *nTxBuffer;     // TX 버퍼.
	uint16_t nTxTimeOut;     // TX 전송 OUT 시간. 256 ms  이상일때 를 위해 형을 uint16_t
	uint8_t nRxOK;          // Rx 완료.
	uint8_t nRxOK_Cnt;      // RX 전체 전송 카운터
	uint8_t nRxRearPos;     // ------------ 
	uint8_t nRxCommand;    // ------------ 
	uint16_t nRxPos;         // RX 현재 위치
	uint8_t nRxDlyTm;       // 
	uint16_t nRxLen;         // RX 수신 길이
	uint8_t *nRxBuffer;     // RX Buff
	uint8_t *nGetRxBuf;     // RX 임시 Buff
	uint8_t *nRxBuf_BackUp; // RX 완료 버퍼.
	uint16_t nRxTimeOut;     // RX 수신 대기 
	uint8_t nBPS;
} USART_INIT_SHAPE,*pUSART_INIT_SHAPE;


typedef struct
{
		uint8_t nSTX;
		uint8_t nMsgLen1; // 0x0D - 전체 같이, 0x0A - Operator ID, 0x08 - Route ID
		uint8_t nMsgLen2; 
		uint8_t SequeNum; //TX Cnt = 0~127  |  RX Cnt = 128 ~ 256 
		uint8_t CommCod1; //RNS 10 / OCC 80
		uint8_t CommCod2; //51,52,53 -> A1,A2,A3
		
} USART_PROTOCOL_HEAD, *pUSART_PROTOCOL_HEAD;


//-------------- ROUTEID---------------
typedef struct
{
	USART_PROTOCOL_HEAD nHead;
	uint8_t nRouteIDBuf[3];
	uint8_t nCRC[2];
	uint8_t nETX;
} USART_ROUTEID_PTC, *pUSART_ROUTEID_PTC;


//-------------- Operrator----------------
typedef struct
{
	USART_PROTOCOL_HEAD nHead;
	uint8_t nOperatorIDBuf[5];
	uint8_t nCRC[2];
	uint8_t nETX;
} USART_OPERATOR_PTC, *pUSART_OPERATOR_PTC;

//--------------ROU-OPER----------------
typedef struct
{
	USART_PROTOCOL_HEAD nHead;
	uint8_t nRouteIDBuf[3];
	uint8_t nOperatorIDBuf[5];
	uint8_t nCRC[2];
	uint8_t nETX;
} USART_ROU_OPER_PTC, *pUSART_ROU_OPER_PTC;




typedef struct
{
	uint8_t nCh;	//전송 해야할 채널
	uint16_t nLen;	//전송 길이
	uint8_t nDataBuf[256];//전송 데이타
}RING_DATA;

typedef struct
{
	uint16_t nPush_Cnt;	//입력 카운터
	uint16_t nPop_Cnt;		//출력 카운터
	RING_DATA nRingData[RING_BUF_SIZE];
}RING_BUF_PRO;




//void USART1_IRQHandler(void);
//void USART3_IRQHandler(void);
//void UART4_IRQHandler(void);



extern UART_HandleTypeDef UartHandle1;
extern UART_HandleTypeDef UartHandle4;
extern UART_HandleTypeDef UartHandle3;

extern USART_INIT_SHAPE USART_1Ch;
extern USART_INIT_SHAPE USART_3Ch;
extern USART_INIT_SHAPE USART_4Ch;


extern uint8_t mSSID[10];
extern uint8_t mXbeeSSIDFlagCnt;

void USRAT_GPIO_Init(void);
void USRAT_init(void);
void USARTRX_MainPro(void);
uint16_t crc16_ccitt_Woojin(uint8_t *buf, int len);
void USART_TIM(void);

void USART_1CH_PRO(uint8_t *pData);
void USART_3CH_PRO(uint8_t *pData);

void DP_RING_BUF_PUSH(uint8_t *pData,uint16_t pLen,uint8_t Ch);
void DP_RING_BUF_POP(uint8_t *pData,uint16_t *pLen);
void USART_RingBuf_Pro(void);








void MyPrintf(uint8_t *pData,int len,char * format, ...);

uint16_t BCD_BIN(uint16_t nInput);
uint16_t BIN_BCD(uint16_t nInput);
uint8_t ConvAsc2Hex(char chDat);
int FunConvAscHex(char *InchData,uint8_t *OuthexData,int Len);
uint8_t IsNumAsc(char nCh);
uint8_t ConvAsc2Dec(char nCh);
char ConvHex2Asc(uint8_t btCh);
int ConvDec2Hex(char nCh);
int FunConvHexAsc(uint8_t *InhexData,char *OUTAscData,int Len);
void MyPrintf_USART1(char * format, ... );



#ifdef __cplusplus
}
#endif


#endif









