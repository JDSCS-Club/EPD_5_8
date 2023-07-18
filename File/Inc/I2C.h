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



#ifndef __I2C_H
#define __I2C_H



#ifdef __cplusplus
 extern "C" {
#endif

        extern I2C_HandleTypeDef hi2c1;
        extern I2C_HandleTypeDef hi2c2;


        void MX_I2C_Process(void);
         
        void MX_I2C1_Init(void);
        void MX_I2C2_Init(void);

        void AMP_Init(uint16_t Address); // Amp_Up 초기화


        //void AMP_Mute_OFF(uint16_t Address); // Amp Mute
        // void AMP_Mute_ON(uint16_t Address); // Amp Mute

        void AMP_Mute_OFF(
                   uint16_t Address1, 
                   uint16_t Address2, 
                   uint16_t Address3);

        void AMP_Mute_ON(
                   uint16_t Address1,uint8_t ad_ch1,
                   uint16_t Address2,uint8_t ad_ch2,
                   uint16_t Address3,uint8_t ad_ch3);
          
          

        int I2C_HAL_WriteBytes(I2C_HandleTypeDef *hi2c,uint16_t DevAddress,uint16_t MemAddress, uint8_t *pData,uint16_t TxBufferSize);

         
         
        int I2C_HAL_ReadBytes(I2C_HandleTypeDef *hi2c,uint16_t DevAddress,uint16_t MemAddress, uint8_t *pData,uint16_t RxBufferSize);


        void AMP_FAULT(void);

        void AMP_SPK_CHECK(void);

        int AMP_PowOn_Check(void);

        void processCurrentVal(void);

        int at24_HAL_WriteBytes(I2C_HandleTypeDef *hi2c,uint16_t DevAddress,uint16_t MemAddress, uint8_t *pData,uint16_t TxBufferSize);
        int at24_HAL_ReadBytes(I2C_HandleTypeDef *hi2c,uint16_t DevAddress,uint16_t MemAddress, uint8_t *pData,uint16_t RxBufferSize);
     
        
       
//========================================================================

        
void TestEEPROM( I2C_HandleTypeDef *hi2c );

         
enum eEEPAddr
{
	EPPAddrQBufLog = 0x100,

	EPPAddrMagicNumH = (EPPAddrQBufLog - 8),
	EPPAddrMagicNumL,
	EPPAddrMaxLogSizeH,
	EPPAddrMaxLogSizeL,
	EPPAddrQBufStartH,
	EPPAddrQBufStartL,
	EPPAddrQBufEndH,
	EPPAddrQBufEndL,
};

enum eEEPVal
{
	EEPMagicNumH = 0xAA,
	EEPMagicNumL = 0x55,

	EEPLogMaxSize = 0x800, //	4 KB
//	EEPLogMaxSize = 0x40, //	64 Byte	- 원형큐 시험용.
};

void TestEEPLog(void);

int EEPLogInit(I2C_HandleTypeDef *hi2c);
int EEPLogReset		( void );

int EEPLogGetMaxSize( void );
int EEPLogGetSize	( void );

int EEPLogWrite		( char sBuf[] );
//int EEPLogRead		( char sBuf[] );

int EEPLogPrint		( void );

int cmd_logPrint(int argc, char *argv[]);

int cmd_logTest(int argc, char *argv[]);

int cmd_logReset(int argc, char *argv[]);

     

     
 #ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */