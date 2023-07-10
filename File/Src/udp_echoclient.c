/**
/*
    ******************************************************************************
    * @Company              : Woojin Industrial Systems Co., Ltd.
    * @Engineer             : D.S.JANG
    * @ModuleName           : udp_echoclient.c
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
#include "stm32f4xx_hal.h"
#include "main.h"
#include "lwip/pbuf.h"
#include "lwip/udp.h"
#include "lwip/tcp.h"
#include "udp_echoclient.h"
#include <string.h>
#include <stdio.h>
#include <stdarg.h>

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/



u8_t   data[500];
__IO   uint32_t message_count = 0;

__IO   uint8_t  Flag = 0;
__IO   uint8_t  Syslog_Flag = 0;

__IO uint16_t mUdp_Server_Port = 0x600;

struct udp_pcb *upcb;
/* Private functions ---------------------------------------------------------*/

/**
  * @brief  Connect to UDP echo server
  * @param  None
  * @retval None
  */
void udp_echoclient_connect(void)
{
    //   struct udp_pcb *upcb;
    struct pbuf *p;
   
    
    ip4_addr_t DestIPaddr;
    err_t err;

    message_count++;

    if (Flag == 0) 
    {
        Flag = 1;
        /* Create a new UDP control block  */
        upcb = udp_new();
    } 
    else 
    {
  
        //sprintf((char*)data, "sending udp client message %d", (int*)message_count);
        //p = pbuf_alloc(PBUF_TRANSPORT,strlen((char*)data), PBUF_POOL);
        
        //IP4_ADDR( &DestIPaddr, DEST_IP_ADDR0, DEST_IP_ADDR1, DEST_IP_ADDR2, DEST_IP_ADDR3 );
        //수신 버퍼에서 src Ip를 확인 하고, 처리 한다. 그래서 여기서는 따로 처리 하지 않는다.
       
        
        mUdp_Server_Port |= (IP_ADDR1_INPUT_DATA << 1);
        mUdp_Server_Port |= (IP_ADDR2_INPUT_DATA&0x01);
        
        //UDP_SERVER_PORT
        err= udp_connect(upcb, &mLed_Process_Flag.sDestIPaddr, mUdp_Server_Port);
        
        
         if (err == ERR_OK) 
        {
        
            p = pbuf_alloc(PBUF_TRANSPORT,sizeof(mEthernet_Tx_struct), PBUF_POOL);

            if (p != NULL) 
            {
                /* copy data to pbuf */
                pbuf_take(p, (uint8_t *)&mEthernet_Tx_struct, sizeof(mEthernet_Tx_struct));

                /* send udp data */
                udp_send(upcb, p); 

                /* free pbuf */
                pbuf_free(p);
            }
        }
        
        return ;    
    }

    if (upcb!=NULL) 
    {
        /*assign destination IP address */
        //IP4_ADDR( &DestIPaddr, DEST_IP_ADDR0, DEST_IP_ADDR1, DEST_IP_ADDR2, DEST_IP_ADDR3 );
		//수신 버퍼에서 src Ip를 확인 하고, 처리 한다. 그래서 여기서는 따로 처리 하지 않는다.
        /* configure destination IP address and port */
        err= udp_connect(upcb, &mLed_Process_Flag.sDestIPaddr, UDP_SERVER_PORT);

        if (err == ERR_OK) 
        {
            /* Set a receive callback for the upcb */
            udp_recv(upcb, udp_receive_callback, NULL);

            /* allocate pbuf from pool*/            
            p = pbuf_alloc(PBUF_TRANSPORT,sizeof(mEthernet_Tx_struct), PBUF_POOL);

            if (p != NULL) 
            {
                /* copy data to pbuf */

                pbuf_take(p, (uint8_t *)&mEthernet_Tx_struct, sizeof(mEthernet_Tx_struct));

                /* send udp data */
                udp_send(upcb, p); 

                /* free pbuf */
                pbuf_free(p);
            } 
            else 
            {
                MyPrintf_USART1("\n\r can not allocate pbuf ");
            }
        } 
        else 
        {
            MyPrintf_USART1("\n\r can not connect udp pcb");
        }
    } 
    else 
    {
        MyPrintf_USART1("\n\r can not create udp pcb");
    } 
}



/*******************************************************************************
  * @brief Syslog Send.
  * @param  None
  * @retval None
  ******************************************************************************/
void udp_SysLog_Connect(char * format, ... )
{
    
    va_list args;
	static char szBuf[1024];
	
	va_start(args, format);
	vsprintf(szBuf, format, args);
	

     //   struct udp_pcb *upcb;
    struct pbuf *p;
    
    
    ip4_addr_t DestIPaddr;
    err_t err;

    message_count++;

    if (Syslog_Flag == 0) 
    {
        Syslog_Flag = 1;
        /* Create a new UDP control block  */
        upcb = udp_new();
    } 
    else 
    {

        if (upcb!=NULL) 
        {
            /*assign destination IP address */
            IP4_ADDR( &DestIPaddr, DEST_IP_ADDR0, DEST_IP_ADDR1, DEST_IP_ADDR2, DEST_IP_ADDR3 );

            //udp_bind(upcb, &upcb->local_ip, upcb->local_port);

            /* configure destination IP address and port */
            err= udp_connect(upcb, &DestIPaddr, 30000);

            if (err == ERR_OK) 
            {
                /* Set a receive callback for the upcb */
                udp_recv(upcb, udp_receive_callback, NULL);

                //sprintf((char*)data, "sending udp client message %d", (int*)message_count);

                /* allocate pbuf from pool*/
                p = pbuf_alloc(PBUF_TRANSPORT,strlen((char*)szBuf), PBUF_POOL);


                if (p != NULL) 
                {
                    /* copy data to pbuf */
                    pbuf_take(p, (char*)szBuf, strlen((char*)szBuf));


                    /* send udp data */
                    udp_send(upcb, p); 

                    /* free pbuf */
                    pbuf_free(p);
                } 
                else 
                {
                    MyPrintf_USART1("\n\r Syslog can not allocate pbuf ");
                }
            } 
            else 
            {
                MyPrintf_USART1("\n\r Syslog can not connect udp pcb");
            }
        } 
        
        
    }

	va_end(args);
    
}


/*******************************************************************************
  * @brief Syslog Send.
  * @param  None
  * @retval None
  ******************************************************************************/
void udp_SysLog(char * format, ... )
{
    
    va_list args;
	static char szBuf[1024];
	
	va_start(args, format);
	vsprintf(szBuf, format, args);
	

     //   struct udp_pcb *upcb;
    struct pbuf *p;
    
    
    ip4_addr_t DestIPaddr;
    err_t err;

    message_count++;

    if (Syslog_Flag == 0) 
    {
        Syslog_Flag = 1;
        /* Create a new UDP control block  */
        upcb = udp_new();
    } 
    else 
    {

        if (upcb!=NULL) 
        {
            /*assign destination IP address */
            IP4_ADDR( &DestIPaddr, 10, 128, 100, 100 );

            //udp_bind(upcb, &upcb->local_ip, upcb->local_port);

            /* configure destination IP address and port */
            err= udp_connect(upcb, &DestIPaddr, 514);

            if (err == ERR_OK) 
            {
                /* Set a receive callback for the upcb */
                udp_recv(upcb, udp_receive_callback, NULL);

                //sprintf((char*)data, "sending udp client message %d", (int*)message_count);

                /* allocate pbuf from pool*/
                p = pbuf_alloc(PBUF_TRANSPORT,strlen((char*)szBuf), PBUF_POOL);


                if (p != NULL) 
                {
                    /* copy data to pbuf */
                    pbuf_take(p, (char*)szBuf, strlen((char*)szBuf));


                    /* send udp data */
                    udp_send(upcb, p); 

                    /* free pbuf */
                    pbuf_free(p);
                } 
                else 
                {
                    MyPrintf_USART1("\n\r Syslog can not allocate pbuf ");
                }
            } 
            else 
            {
                MyPrintf_USART1("\n\r Syslog can not connect udp pcb");
            }
        } 
        
        
    }

	va_end(args);
    
}

/**
  * @brief This function is called when an UDP datagrm has been received on the port UDP_PORT.
  * @param arg user supplied argument (udp_pcb.recv_arg)
  * @param pcb the udp_pcb which received data
  * @param p the packet buffer that was received
  * @param addr the remote IP address from which the packet was received
  * @param port the remote port from which the packet was received
  * @retval None
  */

 
//void udp_receive_callback(void *arg, struct udp_pcb *upcb, struct pbuf *p, struct ip_addr *addr, u16_t port)
void udp_receive_callback(void *arg, struct udp_pcb *pcb, struct pbuf *p, const ip_addr_t *addr, u16_t port)
{
    Flag = 0;
    
    Syslog_Flag = 0;
    /*increment message count */
    message_count++;

    /* Free receive pbuf */
    pbuf_free(p);

    /* free the UDP connection, so we can accept new clients */
    udp_remove(upcb);   
}

/******************* (C) COPYRIGHT 2011 STMicroelectronics *****END OF FILE****/
