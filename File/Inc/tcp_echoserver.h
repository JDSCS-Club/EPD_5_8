/*
    ******************************************************************************
    * @Company              : Woojin Industrial Systems Co., Ltd.
    * @Engineer             : D.S.JANG
    * @ModuleName           : tcp_echoserver.h
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

#ifndef __TCP_ECHOSERVER_H__
#define __TCP_ECHOSERVER_H__



#ifdef __cplusplus
 extern "C" {
#endif
   


void tcp_echoserver_init(void);
void tcp_echoclient_connect(void);


#ifdef __cplusplus
}
#endif


#endif /* __TCP_ECHOSERVER */
