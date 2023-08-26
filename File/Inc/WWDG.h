/*
    ******************************************************************************
    * @Company              : Woojin Industrial Systems Co., Ltd.
    * @Engineer             : D.S.JANG
    * @ModuleName           : WWDG.h
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


#ifndef __WWDG_H__
#define __WWDG_H__


#ifdef __cplusplus
 extern "C" {
#endif
   
   
void WWDG_Init(void);

static void WWDG_Error_Handler(void);



#ifdef __cplusplus
}
#endif


#endif