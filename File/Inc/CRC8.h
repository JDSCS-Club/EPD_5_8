/*
    ******************************************************************************
    * @Company              : Woojin Industrial Systems Co., Ltd.
    * @Engineer             : D.S.JANG
    * @ModuleName           : CRC8.h
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


#ifndef __CRC8_H__
#define __CRC8_H__


#ifdef __cplusplus
 extern "C" {
#endif
   
   
unsigned crc8(unsigned crc, unsigned char const *data, size_t len);
unsigned crc8_slow(unsigned crc, unsigned char const *data, size_t len);

unsigned short crc16_ccitt(unsigned char const *data, int len);


#ifdef __cplusplus
}
#endif

#endif
