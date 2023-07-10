/**
  ******************************************************************************
  * File Name          : debug_task.c
  * Description        : debug task program body
  ******************************************************************************
**/

/* Includes ------------------------------------------------------------------*/

#include "main.h"
#include "stm32f4xx_hal.h"
#include "debug_task.h"
//#include "flash_if.h"

uint8_t gRxDbgData[1];

uint8_t cmd_line[80];
int8_t cmd_line_index = 0;
int8_t backup_cmd_line_index = 0;
int8_t cmd_argc = 0;
uint8_t cmd_argv[40][80];
char cmd_exec;

extern WWDG_HandleTypeDef hwwdg;



uint8_t njw1192_tx_data[2];


uint8_t gain_disp[2];
uint8_t premain_vol_gain;
uint8_t preroom_vol_gain;
uint8_t preextern_vol_gain;
uint8_t pretonebass_gain;
uint8_t pretonetreble_gain;
uint8_t preloudness_ctrl;

uint8_t main_vol_gain;
uint8_t room_vol_gain;
uint8_t extern_vol_gain;
uint8_t tonebass_gain;
uint8_t tonetreble_gain;
uint8_t loudness_ctrl;
uint16_t menu_disp_time;

#define I2C_ERR_BLINK_TIME		30
#define NJW_PARAMETER			0
#define I2C_DEAD_TIME			1

#define I2C_READ_STATBLE_TIME			100 //100ms


#define ANSM_NOISE_THRESHOLD	20//25
#define ANSM_GAIN_OFFSET		2//10//5 ANS 조정 10에서 2로 20180413
#define ANSM_LOW_GAIN_SET		1
#define ANSM_HIGH_GAIN_SET		2
uint8_t ansm_gain_flag;


 uint8_t njw_i2c_err;


void GetCmdBufferArgc(void)
{
	int8_t i;
	int8_t ch;
	int8_t cmd_argv_length = 0;

	cmd_argc = 0;

	memset(cmd_argv, 0x00, sizeof(cmd_argv));

	for(i=0; i<cmd_line_index; )
	{
		ch = cmd_line[i++];
		if(ch == 0x20)
		{
			cmd_argv[cmd_argc++][cmd_argv_length] = 0;
			cmd_argv_length = 0;

			while(i<cmd_line_index)
			{
				if(cmd_line[i++] != 0x20)
				{
					i--;
					break;
				}
			}
		}
		else
		{
			cmd_argv[cmd_argc][cmd_argv_length++] = ch;
		}
	}
}
void PrintPrompt(void)
{
	printf("\r\nP_AMP>");
}
int CheckCMDLine(char const *cmd,char arg)
{
	return !strncmp((char *)&cmd_argv[arg][0], cmd, strlen(cmd));
}

void debug_data_read(void)
{
	uint8_t  rx_data;
	uint8_t  tx_data[3]={0x08,0x20,0x08};;

	/* Read one byte from the receive data register */
	rx_data = gRxDbgData[0];
	if(rx_data)
	{
		cmd_line[cmd_line_index] = 0;
		if (rx_data == BACKSPACE)
		{
			if (cmd_line_index)
			{
				cmd_line_index--;
				HAL_UART_Transmit(&huart4, tx_data, 3, 30);
			}
		}
		else if(rx_data == ENTER)
		{
			if(cmd_line_index)
			{
				GetCmdBufferArgc();
				cmd_exec = SET;
			}
			PrintPrompt();
			backup_cmd_line_index = cmd_line_index;
			cmd_line_index = 0;
		}
		else
		{
			if(cmd_line_index < 80)
			{
				tx_data[0] = rx_data;
				HAL_UART_Transmit(&huart4, tx_data, 1, 10);
				cmd_line[cmd_line_index++] = rx_data;
			}
		}
	}
}
int8_t	Asc8ToDec(int8_t *ndata)
{
	int8_t	temp;
	temp = *ndata;
	if (temp >= '0' && temp <= '9')
	{
		temp -= '0';
	}
	/*
	if (temp > '@')
	{
		temp -= 'A';
	}
	else if (temp > 0x60)//'=0x60
	{
		temp -= 'a';
	}
	else
	{
		temp -= '0';
	}
	temp = (temp & 0x0F);
	*/
	return temp;
}
int8_t	Asc16ToDec(int8_t *ndata)
{
	int8_t	temp, temp2;

	//Ascii MSB data
	temp = *ndata;
	if (temp >= '0' && temp <= '9')
	{
		temp -= '0';
		temp = temp * 10;
	}
/*	if (temp > 0x60)//'=0x60
	{
		temp -= 'a';
	}
	else if (temp > '@')//@=0x40
	{
		temp -= 'A';
	}
	else
	{
		temp -= '0';
	}*/
	//temp = (temp << 4);

	//Ascii LSB data
	temp2 = *(ndata+1);
	if (temp2 >= '0' && temp2 <= '9')
	{
		temp2 -= '0';
	}
	/*if (temp2 > 0x60)//'=0x60
	{
		temp2 -= 'a';
	}
	else if (temp2 > '@')//@=0x40
	{
		temp2 -= 'A';
	}
	else
	{
		temp2 -= '0';
	}*/
	temp += temp2;
	return temp;
}
int8_t	Asc8ToHex(int8_t *ndata)
{
	int8_t	temp;
	temp = *ndata;

	if (temp > '@')
	{
		temp -= 'A';
	}
	else if (temp > 0x60)//'=0x60
	{
		temp -= 'a';
	}
	else
	{
		temp -= '0';
	}
	temp = (temp & 0x0F);

	return temp;
}
int8_t	Asc16ToHex(int8_t *ndata)
{
	int8_t	temp, temp2;

	//Ascii MSB data
	temp = *ndata;
	if (temp > 0x60)//'=0x60
	{
		temp -= 0x57;
	}
	else if (temp > '@')//@=0x40
	{
		temp -= 'A';
	}
	else
	{
		temp -= '0';
	}
	temp = (temp << 4);

	//Ascii LSB data
	temp2 = *(ndata+1);
	if (temp2 > 0x60)//'=0x60
	{
		temp2 -= 0x57;
	}
	else if (temp2 > '@')//@=0x40
	{
		temp2 -= 'A';
	}
	else
	{
		temp2 -= '0';
	}
	temp += temp2;
	return temp;
}

typedef  void (*pFunction)(void);
pFunction JumpToApplication;
uint32_t JumpAddress;
#define BOOT_VECTOR_ADDRESS     (uint32_t)0x08000000      /* Start user code address: ADDR_FLASH_PAGE_8 */

void Debug_Do_Porcess(void)
{
	uint8_t i;
	uint32_t flashdestination;
	uint32_t status;

	if(cmd_exec){
		if(CheckCMDLine("njw0",0)){
			njw1192_tx_data[NJW1192_SEL_ADDR] = NJW1192_INPUT_GAIN;
			njw1192_tx_data[NJW1192_SEL_DATA] = NJW_GAIN_0dB | NJW_VOL_GAIN0;
			njw1192_write(njw1192_tx_data);
			while (HAL_I2C_GetState(&hi2c1) != HAL_I2C_STATE_READY)
			{
			}			
		}
		else if(CheckCMDLine("njw10",0)){
			njw1192_tx_data[NJW1192_SEL_ADDR] = NJW1192_INPUT_GAIN;
			njw1192_tx_data[NJW1192_SEL_DATA] = NJW_GAIN_0dB | NJW_VOL_INGAIN10;
			njw1192_write(njw1192_tx_data);
			while (HAL_I2C_GetState(&hi2c1) != HAL_I2C_STATE_READY)
			{
			}			
		}
		else if(CheckCMDLine("njw",0)){
			njw1192_tx_data[NJW1192_SEL_ADDR] = NJW1192_INPUT_GAIN;
			njw1192_tx_data[NJW1192_SEL_DATA] = NJW_GAIN_0dB | NJW_VOL_GAIN0;
			njw1192_write(njw1192_tx_data);
			while (HAL_I2C_GetState(&hi2c1) != HAL_I2C_STATE_READY)
			{
			}			
			
			njw1192_tx_data[NJW1192_SEL_ADDR] = NJW1192_FRONT_CH;
			njw1192_tx_data[NJW1192_SEL_DATA] = NJW_VOLL_FGAIN_0|NJW_VOLR_FGAIN_0;
			njw1192_write(njw1192_tx_data);
			while (HAL_I2C_GetState(&hi2c1) != HAL_I2C_STATE_READY)
			{
			}			
			
			njw1192_tx_data[NJW1192_SEL_ADDR] = NJW1192_REAR_CH;
			njw1192_tx_data[NJW1192_SEL_DATA] = NJW_VOLL_RGAIN_0|NJW_VOLR_RGAIN_0;
			njw1192_write(njw1192_tx_data);
			while (HAL_I2C_GetState(&hi2c1) != HAL_I2C_STATE_READY)
			{
			}			
			
			njw1192_tx_data[NJW1192_SEL_ADDR] = NJW1192_TONE_CTRL;
			njw1192_tx_data[NJW1192_SEL_DATA] = NJW_TONE_BCB_CUT | NJW_TONEBASS_0 | NJW_TONE_BCT_CUT| NJW_TONETREBLE_0;
			njw1192_write(njw1192_tx_data);
			while (HAL_I2C_GetState(&hi2c1) != HAL_I2C_STATE_READY)
			{
			}			
			
			njw1192_tx_data[NJW1192_SEL_ADDR] = NJW1192_MUTE_CTRL;
			njw1192_tx_data[NJW1192_SEL_DATA] = NJW_FL_MUTE | NJW_FR_ACTIVE | NJW_RL_MUTE | NJW_RR_ACTIVE | NJW_MONO_SEL | NJW_LOUDNESS_OFF;
			njw1192_write(njw1192_tx_data);
			while (HAL_I2C_GetState(&hi2c1) != HAL_I2C_STATE_READY)
			{
			}			
			MyPrintf_USART1("njw %d\r\n",i);
		}
		else if(CheckCMDLine("tdastd",0)){
			//HAL_GPIO_WritePin(GPIOB, AMP_CH1_STBY_Pin|AMP_CH2_STBY_Pin, GPIO_PIN_SET);//RESET = active, SET = STDBY
		}
		else if(CheckCMDLine("tdaact",0)){
			//HAL_GPIO_WritePin(GPIOB, AMP_CH1_STBY_Pin|AMP_CH2_STBY_Pin, GPIO_PIN_RESET);//RESET = active, SET = STDBY
		}
		else if(CheckCMDLine("update",0)){
			flashdestination = (uint32_t)0x0807f800;
			
			//status = FLASH_Block_Erase(flashdestination);
			
			if(status == HAL_OK){
			  MyPrintf_USART1("\n\n\rErase success!!!\n\r");	  
			//  HAL_WWDG_Start(&hwwdg);
			  for(;;){;}
	  #if 0
			  JumpAddress = *(__IO uint32_t*) (BOOT_VECTOR_ADDRESS+4);
			  JumpToApplication = (pFunction) JumpAddress;
			  /* Initialize user application's Stack Pointer */
			  __set_MSP(*(__IO uint32_t*) BOOT_VECTOR_ADDRESS);
			  JumpToApplication();
	  #endif
			}
			//else if(status == FLASHIF_ERASEKO){
			//	printf("\n\n\rErase error occurred!!!\n\r");		
			//}
		}
		else if(CheckCMDLine("wdt",0)){
		//  HAL_WWDG_Start(&hwwdg);
		  for(;;){;}
		}
		PrintPrompt();
		cmd_exec = RESET;
	}
	//============================================================================
	//UART Lock 발생 시 reinitialize
	if(HAL_UART_GetState(&huart4) == HAL_UART_STATE_READY){
		HAL_UART_Receive_IT(&huart4, gRxDbgData, 1);
		MyPrintf_USART1("\r\n Uart5 Reinit\r\n");
	}
	//============================================================================
}


//*****************************************************************************
//* @brief -
//* @param -
//* @retval-
//******************************************************************************/
void njw1192_write(uint8_t *wData)
{
  static uint8_t njw_i2c_err = 0;
  
  
  
        
	if(HAL_I2C_Master_Transmit_IT(&hi2c1, (uint16_t)NJW1192_ID_ADDR<<1, wData, 2)!= HAL_OK)
	{
		/* Error_Handler() function is called when Timout error occurs.
			When Acknowledge failure ocucurs (Slave don't acknowledge it's address)
			Master restarts communication */
		
		  MyPrintf_USART1("Audio i2c tx error = %d\r\n",njw_i2c_err);
		
	}
	else{
		
          MyPrintf_USART1("Audio i2c OK = %02x-%02x\r\n",wData[0],wData[1]);
          
	}
}


//*****************************************************************************
//* @brief -
//* @param -
//* @retval-
//******************************************************************************/

void njw1192_vol_setting(uint8_t vol_addr,uint8_t On_Off)
{
	uint8_t temp;
	uint32_t break_time = 0;
	
	njw1192_tx_data[NJW1192_SEL_ADDR] = 0x00;
        
    if(vol_addr == true) // 볼륨업 기능 ON
    {
        if(On_Off == true)
        {
            //--현차 조건.                                           // 양산           // 시험실.
           // njw1192_tx_data[NJW1192_SEL_DATA] = (TEST_ROOM == 0) ?  NJW_VOL_GAIN0 : NJW_VOL_GAIN5;
              njw1192_tx_data[NJW1192_SEL_DATA] = (TEST_ROOM == 0) ?  NJW_VOL_INGAIN5 : NJW_VOL_GAIN5;
            
        }
        else{                                                      // 양산            // 시험실
           // njw1192_tx_data[NJW1192_SEL_DATA] = (TEST_ROOM == 0) ? NJW_VOL_INGAIN5 : NJW_VOL_INGAIN20;
              njw1192_tx_data[NJW1192_SEL_DATA] = (TEST_ROOM == 0) ? NJW_VOL_INGAIN10 : NJW_VOL_INGAIN20;
            
        }
    }
    else // VOL level Default
    {
        if(On_Off == true)
        {
                                                                    //양산            //시험실
            //njw1192_tx_data[NJW1192_SEL_DATA] = NJW_VOL_GAIN0;
              njw1192_tx_data[NJW1192_SEL_DATA] = NJW_VOL_INGAIN5;
        }
        else{                                                       //양산            //시험실
            //njw1192_tx_data[NJW1192_SEL_DATA] = (TEST_ROOM == 0) ? NJW_VOL_INGAIN10 : NJW_VOL_INGAIN30;
              njw1192_tx_data[NJW1192_SEL_DATA] = (TEST_ROOM == 0) ? NJW_VOL_INGAIN15 : NJW_VOL_INGAIN30;
            
        }
        
    }
        
            
	njw1192_write(njw1192_tx_data);
        
	while (HAL_I2C_GetState(&hi2c1) != HAL_I2C_STATE_READY)
	{	
		HAL_Delay(1);
		if(break_time++ > I2C_READ_STATBLE_TIME){
			break;
		}
	}			
}


//*****************************************************************************
//* @brief -
//* @param -
//* @retval-
//******************************************************************************/
void njw1192_vol_setting_OutSpk(void)
{
    uint8_t temp;
	uint32_t break_time = 0;
	
	njw1192_tx_data[NJW1192_SEL_ADDR] = 0x00;
                                                           //양산                 //시험실
    njw1192_tx_data[NJW1192_SEL_DATA] = (TEST_ROOM == 0) ? NJW_VOL_GAIN0 : NJW_VOL_INGAIN36;
    
    njw1192_write(njw1192_tx_data);
        
	while (HAL_I2C_GetState(&hi2c1) != HAL_I2C_STATE_READY)
	{	
		HAL_Delay(1);
		if(break_time++ > I2C_READ_STATBLE_TIME){
			break;
		}
	}
}
//*****************************************************************************
//* @brief -
//* @param -
//* @retval-
//******************************************************************************/
void njw1192_mute(uint8_t On_Off)
{
    uint32_t break_time = 0;
    
    if(On_Off == false)
    {
        njw1192_tx_data[0] = 0x04;
        
        njw1192_tx_data[1] = 0xCE;
        
        njw1192_write(njw1192_tx_data);
        
    }
    else if(On_Off == true)
    {
        njw1192_tx_data[0] = 0x04;
        
        njw1192_tx_data[1] = 0x0E;
        
        njw1192_write(njw1192_tx_data);
        
    }
    
    while (HAL_I2C_GetState(&hi2c1) != HAL_I2C_STATE_READY)
	{	
		HAL_Delay(1);
		if(break_time++ > I2C_READ_STATBLE_TIME){
			break;
		}
	}			
    
}

//*****************************************************************************
//* @brief -
//* @param -
//* @retval-
//******************************************************************************/
void njw1192_default_value(void)
{
	uint8_t temp;
	uint32_t break_time = 0;

	njw1192_tx_data[NJW1192_SEL_ADDR] = NJW1192_INPUT_GAIN;
        
        
#if NJW_PARAMETER
	njw1192_tx_data[NJW1192_SEL_DATA] = NJW_GAIN_0dB | NJW_VOL_MUTE1;
#else
	if(main_vol_gain>7){
		temp = (main_vol_gain+(54-(2*(main_vol_gain-8))));
		njw1192_tx_data[NJW1192_SEL_DATA] = NJW_GAIN_0dB | temp;
	}
	else{
		njw1192_tx_data[NJW1192_SEL_DATA] = NJW_GAIN_0dB | main_vol_gain;
	}
	ansm_gain_flag = ANSM_LOW_GAIN_SET;
#endif	
    
    njw1192_tx_data[0] = 0x00;
        
      
    if(TEST_ROOM == 0)
    {
        
        njw1192_tx_data[1] = (NJW_GAIN_0dB | NJW_VOL_INGAIN10);
    }
    else
    {
        njw1192_tx_data[1] = (NJW_GAIN_0dB | NJW_VOL_INGAIN30);
    }
        
           
	njw1192_write(njw1192_tx_data);

	break_time = 0;
	
    while (HAL_I2C_GetState(&hi2c1) != HAL_I2C_STATE_READY)
	{
	#if I2C_DEAD_TIME
		HAL_Delay(1);
		if(break_time++ > I2C_READ_STATBLE_TIME){
			break;
		}
	#endif	
	}			
    
//////////////////////////////////////////////////////////////////////////////      
                            
	njw1192_tx_data[NJW1192_SEL_ADDR] = NJW1192_FRONT_CH;
        
       // HAL_Delay( 10 );
        
        
#if NJW_PARAMETER
	njw1192_tx_data[NJW1192_SEL_DATA] = NJW_VOLL_FGAIN_0|NJW_VOLR_FGAIN_0;
#else
	temp = (room_vol_gain&0x0F)<<4;
	njw1192_tx_data[NJW1192_SEL_DATA] = temp | NJW_VOLR_FGAIN_0;
#endif	
    
    
    njw1192_tx_data[0] = 0x01;
    njw1192_tx_data[1] = 0xFF;
	njw1192_write(njw1192_tx_data);

	break_time = 0;
		
    while (HAL_I2C_GetState(&hi2c1) != HAL_I2C_STATE_READY)
	{
	#if I2C_DEAD_TIME
		HAL_Delay(1);
		if(break_time++ > I2C_READ_STATBLE_TIME){
			break;
		}
	#endif	
	}			
    
	
        
//////////////////////////////////////////////////////////////////////////////           
                
                    
	njw1192_tx_data[NJW1192_SEL_ADDR] = NJW1192_REAR_CH;
        
        
       // HAL_Delay( 10 );
        
#if NJW_PARAMETER
	njw1192_tx_data[NJW1192_SEL_DATA] = NJW_VOLL_RGAIN_0|NJW_VOLR_RGAIN_0;
#else
	temp = (extern_vol_gain&0x0F)<<4;
	njw1192_tx_data[NJW1192_SEL_DATA] = temp | NJW_VOLR_RGAIN_0;
#endif	
    
    
    
    njw1192_tx_data[0] = 0x02;
    njw1192_tx_data[1] = 0xFF;
    
	njw1192_write(njw1192_tx_data);

	break_time = 0;
    
    while (HAL_I2C_GetState(&hi2c1) != HAL_I2C_STATE_READY)
	{
	#if I2C_DEAD_TIME
		HAL_Delay(1);
		if(break_time++ > I2C_READ_STATBLE_TIME){
			break;
		}
	#endif	
	}			
	


////////////////////////////////////////////////////////////////////////////// 
	
	njw1192_tx_data[NJW1192_SEL_ADDR] = NJW1192_TONE_CTRL;
        
       // HAL_Delay( 10 );
        
#if NJW_PARAMETER
	njw1192_tx_data[NJW1192_SEL_DATA] = NJW_TONE_BCB_CUT | NJW_TONEBASS_0 | NJW_TONE_BCT_CUT| NJW_TONETREBLE_0;	
#else
	njw1192_tx_data[NJW1192_SEL_DATA] = ((tonebass_gain&0x0F)<<4) | (tonetreble_gain&0x0F);
#endif	
    
    
    njw1192_tx_data[0] = 0x03;
    njw1192_tx_data[1] = 0x08;
	njw1192_write(njw1192_tx_data);

	break_time = 0;
		
	while (HAL_I2C_GetState(&hi2c1) != HAL_I2C_STATE_READY)
	{
	#if I2C_DEAD_TIME
		HAL_Delay(1);
		if(break_time++ > I2C_READ_STATBLE_TIME){
			break;
		}
	#endif	
	}		
    
        
 ////////////////////////////////////////////////////////////////////////////// 
            
	njw1192_tx_data[NJW1192_SEL_ADDR] = NJW1192_MUTE_CTRL;
        
      //  HAL_Delay( 10 );
        
#if NJW_PARAMETER
	njw1192_tx_data[NJW1192_SEL_DATA] = NJW_FL_ACTIVE| NJW_FR_MUTE | NJW_RL_ACTIVE | NJW_RR_MUTE | NJW_MONO_SEL | NJW_LOUDNESS_OFF;
#else
	temp = (loudness_ctrl & 0x01)<<1;
	njw1192_tx_data[NJW1192_SEL_DATA] = NJW_FL_ACTIVE| NJW_FR_MUTE | NJW_RL_ACTIVE | NJW_RR_MUTE | NJW_MONO_SEL | temp;
	//njw1192_tx_data[NJW1192_SEL_DATA] = NJW_FL_MUTE| NJW_FR_MUTE | NJW_RL_MUTE| NJW_RR_MUTE | NJW_MONO_SEL | temp;
#endif	
    
    
    njw1192_tx_data[0] = 0x04;
    njw1192_tx_data[1] = 0xCE;
	njw1192_write(njw1192_tx_data);

	break_time = 0;
    
    while (HAL_I2C_GetState(&hi2c1) != HAL_I2C_STATE_READY)
	{
	#if I2C_DEAD_TIME
		HAL_Delay(1);
		if(break_time++ > I2C_READ_STATBLE_TIME){
			break;
		}
	#endif	
	}
    
	
}



