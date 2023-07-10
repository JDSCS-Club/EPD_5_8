/**
  ******************************************************************************
  * File Name          : debug_task.h
  * Description        : debug task header file
  ******************************************************************************
	UART_HandleTypeDef huart1;
**/


/* Error code */


/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __DEBUG_TASK_H
#define __DEBUG_TASK_H

#ifdef __cplusplus
 extern "C" {
#endif



#define BACKSPACE 			0x08
#define ENTER 				0x0D

extern uint8_t gRxDbgData[1];
extern char cmd_exec;
extern uint8_t cmd_line[80];
extern int8_t cmd_line_index;
extern int8_t backup_cmd_line_index;
extern int8_t cmd_argc;
extern uint8_t cmd_argv[40][80];
extern UART_HandleTypeDef huart2;
extern UART_HandleTypeDef huart4;

extern uint8_t gRxdData2[1];
extern uint8_t gRxDbgData[1];

extern I2C_HandleTypeDef hi2c1;
extern I2C_HandleTypeDef hi2c2;

void debug_data_read(void);
void Debug_Do_Porcess(void);
//========================================================
//NJW1192 register define
#define NJW1192_ID_ADDR			0x40

#define NJW1192_SEL_ADDR		0x00
#define NJW1192_SEL_DATA		0x01

#define NJW1192_INPUT_GAIN		0x00
#define NJW1192_FRONT_CH		0x01
#define NJW1192_REAR_CH			0x02
#define NJW1192_TONE_CTRL		0x03
#define NJW1192_MUTE_CTRL		0x04
//NJW1192_INPUT_GAIN
#define NJW_GAIN_0dB			0x00
#define NJW_GAIN_6dB			0x40
#define NJW_GAIN_12dB			0x80
#define NJW_GAIN_18dB			0xC0

#define NJW_VOL_INGAIN0			0x3F
#define NJW_VOL_INGAIN1			0x3E
#define NJW_VOL_INGAIN2			0x3D
#define NJW_VOL_INGAIN3			0x3C
#define NJW_VOL_INGAIN4			0x3B
#define NJW_VOL_INGAIN5			0x3A
#define NJW_VOL_INGAIN6			0x39
#define NJW_VOL_INGAIN7			0x38
#define NJW_VOL_INGAIN8			0x37
#define NJW_VOL_INGAIN9			0x36
#define NJW_VOL_INGAIN10		0x35
#define NJW_VOL_INGAIN11		0x34
#define NJW_VOL_INGAIN12		0x33
#define NJW_VOL_INGAIN13		0x32
#define NJW_VOL_INGAIN14		0x31
#define NJW_VOL_INGAIN15		0x30
#define NJW_VOL_INGAIN16		0x2F
#define NJW_VOL_INGAIN17		0x2E
#define NJW_VOL_INGAIN18		0x2D
#define NJW_VOL_INGAIN19		0x2C
#define NJW_VOL_INGAIN20		0x2B
#define NJW_VOL_INGAIN21		0x2A
#define NJW_VOL_INGAIN22		0x29
#define NJW_VOL_INGAIN23		0x28
#define NJW_VOL_INGAIN24		0x27
#define NJW_VOL_INGAIN25		0x26
#define NJW_VOL_INGAIN26		0x25
#define NJW_VOL_INGAIN27		0x24
#define NJW_VOL_INGAIN28		0x23
#define NJW_VOL_INGAIN29		0x22
#define NJW_VOL_INGAIN30		0x21
#define NJW_VOL_INGAIN32		0x20
#define NJW_VOL_INGAIN34		0x1F
#define NJW_VOL_INGAIN36		0x1E
#define NJW_VOL_INGAIN38		0x1D
#define NJW_VOL_INGAIN40		0x1C
#define NJW_VOL_INGAIN42		0x1B
#define NJW_VOL_INGAIN44		0x1A
#define NJW_VOL_INGAIN46		0x19
#define NJW_VOL_INGAIN48		0x18
#define NJW_VOL_INGAIN50		0x17
#define NJW_VOL_INGAIN52		0x16
#define NJW_VOL_INGAIN54		0x15
#define NJW_VOL_INGAIN56		0x14
#define NJW_VOL_INGAIN58		0x13
#define NJW_VOL_INGAIN60		0x12
#define NJW_VOL_INGAIN62		0x11
#define NJW_VOL_INGAIN64		0x10
#define NJW_VOL_INGAIN66		0x0F
#define NJW_VOL_INGAIN68		0x0E
#define NJW_VOL_MUTE1			0x0D
#define NJW_VOL_MUTE2			0x0C
#define NJW_VOL_MUTE3			0x0B
#define NJW_VOL_MUTE4			0x0A
#define NJW_VOL_MUTE5			0x09
#define NJW_VOL_MUTE6			0x08
#define NJW_VOL_GAIN0			0x07
#define NJW_VOL_GAIN1			0x06
#define NJW_VOL_GAIN2			0x05
#define NJW_VOL_GAIN3			0x04
#define NJW_VOL_GAIN4			0x03
#define NJW_VOL_GAIN5			0x02
#define NJW_VOL_GAIN6			0x01
#define NJW_PRE_CHARGE			0x00
//NJW1192_FRONT_CH
// FL
#define NJW_VOLL_FGAIN_0			0xF0
#define NJW_VOLL_FGAIN_2			0xE0
#define NJW_VOLL_FGAIN_4			0xD0
#define NJW_VOLL_FGAIN_6			0xC0
#define NJW_VOLL_FGAIN_8			0xB0
#define NJW_VOLL_FGAIN_10			0xA0
#define NJW_VOLL_FGAIN_12			0x90
#define NJW_VOLL_FGAIN_16			0x80
#define NJW_VOLL_FGAIN_18			0x70
#define NJW_VOLL_FGAIN_20			0x60
#define NJW_VOLL_FGAIN_24			0x50
#define NJW_VOLL_FGAIN_32			0x40
#define NJW_VOLL_FGAIN_34			0x30
#define NJW_VOLL_FGAIN_36			0x20
#define NJW_VOLL_FGAIN_38			0x10
#define NJW_VOLL_FGAIN_42			0x00
//FR
#define NJW_VOLR_FGAIN_0			0x0F
#define NJW_VOLR_FGAIN_2			0x0E
#define NJW_VOLR_FGAIN_4			0x0D
#define NJW_VOLR_FGAIN_6			0x0C
#define NJW_VOLR_FGAIN_8			0x0B
#define NJW_VOLR_FGAIN_10			0x0A
#define NJW_VOLR_FGAIN_12			0x09
#define NJW_VOLR_FGAIN_16			0x08
#define NJW_VOLR_FGAIN_18			0x07
#define NJW_VOLR_FGAIN_20			0x06
#define NJW_VOLR_FGAIN_24			0x05
#define NJW_VOLR_FGAIN_32			0x04
#define NJW_VOLR_FGAIN_34			0x03
#define NJW_VOLR_FGAIN_36			0x02
#define NJW_VOLR_FGAIN_38			0x01
#define NJW_VOLR_FGAIN_42			0x00
//NJW1192_REAR_CH
//RL
#define NJW_VOLL_RGAIN_0			0xF0
#define NJW_VOLL_RGAIN_2			0xE0
#define NJW_VOLL_RGAIN_4			0xD0
#define NJW_VOLL_RGAIN_6			0xC0
#define NJW_VOLL_RGAIN_8			0xB0
#define NJW_VOLL_RGAIN_10			0xA0
#define NJW_VOLL_RGAIN_12			0x90
#define NJW_VOLL_RGAIN_16			0x80
#define NJW_VOLL_RGAIN_18			0x70
#define NJW_VOLL_RGAIN_20			0x60
#define NJW_VOLL_RGAIN_24			0x50
#define NJW_VOLL_RGAIN_32			0x40
#define NJW_VOLL_RGAIN_34			0x30
#define NJW_VOLL_RGAIN_36			0x20
#define NJW_VOLL_RGAIN_38			0x10
#define NJW_VOLL_RGAIN_42			0x00
//RR
#define NJW_VOLR_RGAIN_0			0x0F
#define NJW_VOLR_RGAIN_2			0x0E
#define NJW_VOLR_RGAIN_4			0x0D
#define NJW_VOLR_RGAIN_6			0x0C
#define NJW_VOLR_RGAIN_8			0x0B
#define NJW_VOLR_RGAIN_10			0x0A
#define NJW_VOLR_RGAIN_12			0x09
#define NJW_VOLR_RGAIN_16			0x08
#define NJW_VOLR_RGAIN_18			0x07
#define NJW_VOLR_RGAIN_20			0x06
#define NJW_VOLR_RGAIN_24			0x05
#define NJW_VOLR_RGAIN_32			0x04
#define NJW_VOLR_RGAIN_34			0x03
#define NJW_VOLR_RGAIN_36			0x02
#define NJW_VOLR_RGAIN_38			0x01
#define NJW_VOLR_RGAIN_42			0x00
//NJW1192_TONE_CTRL
#define NJW_TONE_BCB_CUT		0x00
#define NJW_TONE_BCB_BOOST		0x80

#define NJW_TONE_BCT_CUT		0x00
#define NJW_TONE_BCT_BOOST		0x08

#define NJW_TONEBASS_14			0x70
#define NJW_TONEBASS_12			0x60
#define NJW_TONEBASS_10			0x50
#define NJW_TONEBASS_8			0x40
#define NJW_TONEBASS_6			0x30
#define NJW_TONEBASS_4			0x20
#define NJW_TONEBASS_2			0x10
#define NJW_TONEBASS_0			0x00

#define NJW_TONETREBLE_14		0x07
#define NJW_TONETREBLE_12		0x06
#define NJW_TONETREBLE_10		0x05
#define NJW_TONETREBLE_8		0x04
#define NJW_TONETREBLE_6		0x03
#define NJW_TONETREBLE_4		0x02
#define NJW_TONETREBLE_2		0x01
#define NJW_TONETREBLE_0		0x00
//NJW1192_MUTE_CTRL
#define	NJW_FL_MUTE				0x00		
#define	NJW_FL_ACTIVE			0x80		

#define	NJW_FR_MUTE				0x00		
#define	NJW_FR_ACTIVE			0x40		

#define	NJW_RL_MUTE				0x00		
#define	NJW_RL_ACTIVE			0x20		

#define	NJW_RR_MUTE				0x00		
#define	NJW_RR_ACTIVE			0x10		

#define NJW_INPUT_SEL1			0x00
#define NJW_INPUT_SEL2			0x04
#define NJW_INPUT_SEL3			0x08
#define NJW_MONO_SEL			0x0C

#define NJW_LOUDNESS_OFF		0x00
#define NJW_LOUDNESS_ON			0x02

#define NJW_NORMAL				0x00
#define NJW_TEST_MODE			0x01

extern uint8_t njw1192_tx_data[2];

void njw1192_write(uint8_t *wData);
void njw1192_vol_setting(uint8_t vol_addr,uint8_t On_Off);

void njw1192_vol_setting_OutSpk(void);

void njw1192_default_value(void);

void njw1192_mute(uint8_t On_Off);



#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

