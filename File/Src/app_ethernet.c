/*
    ******************************************************************************
    * @Company              : Woojin Industrial Systems Co., Ltd.
    * @Engineer             : D.S.JANG
    * @ModuleName           : app_ethernet.c
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
#include "main.h"
#include "lwip/dhcp.h"
#include "app_ethernet.h"
#include "usrat.h"
#include "main.h"
#ifdef USE_LCD
#include "lcd_log.h"
#endif

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
#ifdef USE_DHCP
#define MAX_DHCP_TRIES  3
uint32_t DHCPfineTimer = 0;
__IO uint8_t DHCP_state = DHCP_START;
#endif

//_IO uint8_t DHCP_state = DHCP_START;


/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/
/**
  * @brief  Notify the User about the nework interface config status 
  * @param  netif: the network interface
  * @retval None
  */
void User_notification(struct netif *netif) 
{
    uint8_t iptxt[20];
  
    if (netif_is_up(netif))
    {


        sprintf((char *)iptxt, "%s", ip4addr_ntoa((const ip4_addr_t *)&netif->ip_addr));
        MyPrintf_USART1 ("########### Static IP address: %s \n\r", iptxt);
    }
    else
    {  

        MyPrintf_USART1 ("########### The network cable is not connected  \n\r");
        
    }  
}

/**
  * @brief  This function notify user about link status changement.
  * @param  netif: the network interface
  * @retval None
  */
void ethernetif_notify_conn_changed(struct netif *netif)
{

  ip_addr_t ipaddr;
  ip_addr_t netmask;
  ip_addr_t gw;
  
  uint8_t iptxt[20];

  
  if(netif_is_link_up(netif))
  {

      //MyPrintf_USART1( "%s(%d)\r\n", __func__, __LINE__ );
      
    MyPrintf_USART1 ("########### The network cable is now connected  \n\r");

//    IP_ADDR4(&ipaddr, IP_ADDR0, IP_ADDR1, IP_ADDR2, IP_ADDR3);
//    IP_ADDR4(&netmask, NETMASK_ADDR0, NETMASK_ADDR1 , NETMASK_ADDR2, NETMASK_ADDR3);
//    IP_ADDR4(&gw, GW_ADDR0, GW_ADDR1, GW_ADDR2, GW_ADDR3);  
//    
//    netif_set_addr(netif, &ipaddr , &netmask, &gw);  
//    
//      
//
//    sprintf((char *)iptxt, "%s", ip4addr_ntoa((const ip4_addr_t *)&netif->ip_addr));
//    MyPrintf_USART1 ("########### Static IP address: %s \n\r", iptxt);
   
    
    DHCP_state = DHCP_START;
    
    
    /* When the netif is fully configured this function must be called.*/
    netif_set_up(netif);    
    
    
    mLed_Process_Flag.sDhcp_Complete = 0;
  }
  else
  {
    /*  When the netif link is down this function must be called.*/
    netif_set_down(netif);
    
    //MyPrintf_USART1( "%s(%d)\r\n", __func__, __LINE__ );
    MyPrintf_USART1 (" ########### Netif_Set_down  \n\r");
    
    mLed_Process_Flag.sEth_UpLInk_Cnt = 0;
    
    mLed_Process_Flag.sDhcp_Complete = 0;
    
    
  }
}

#ifdef USE_DHCP
/**
  * @brief  DHCP_Process_Handle
  * @param  None
  * @retval None
  */
void DHCP_Process(struct netif *netif)
{
  ip_addr_t ipaddr;
  ip_addr_t netmask;
  ip_addr_t gw;
  struct dhcp *dhcp;   
  
  uint8_t iptxt[20];

  switch (DHCP_state)
  {
    case DHCP_START:
    {
      ip_addr_set_zero_ip4(&netif->ip_addr);
      ip_addr_set_zero_ip4(&netif->netmask);
      ip_addr_set_zero_ip4(&netif->gw);
      
      DHCP_state = DHCP_WAIT_ADDRESS;
      dhcp_start(netif);
      
      
      sprintf((char *)iptxt, "%s", ip4addr_ntoa((const ip4_addr_t *)&netif->ip_addr));
      
      MyPrintf_USART1 ("########### State: Looking for DHCP server: %s\n\r", iptxt);
      

    }
    break;
    
  case DHCP_WAIT_ADDRESS:
    {
      if (dhcp_supplied_address(netif)) 
      {
        DHCP_state = DHCP_ADDRESS_ASSIGNED;
        
        dhcp_stop(netif);
        
        netif_set_up(netif);
        
        
        sprintf((char *)iptxt, "%s", ip4addr_ntoa((const ip4_addr_t *)&netif->ip_addr));
         
        mLed_Process_Flag.sMy_IP_Info = (u32_t)netif->ip_addr.addr >> 24;
            
        mLed_Process_Flag.sDhcp_Complete = 1;
        
        MyPrintf_USART1 ("########### IP address assigned by a DHCP server : %s\n\r", iptxt);
        
        
      }
      else
      {
        dhcp = (struct dhcp *)netif_get_client_data(netif, LWIP_NETIF_CLIENT_DATA_INDEX_DHCP);
    
        /* DHCP timeout */
        if (dhcp->tries > MAX_DHCP_TRIES)
        {
          DHCP_state = DHCP_TIMEOUT;
          
          /* Stop DHCP */
          dhcp_stop(netif);
          
          /* Static address used */
          IP_ADDR4(&ipaddr, IP_ADDR0 ,IP_ADDR1 , IP_ADDR2 , IP_ADDR3);
          IP_ADDR4(&netmask, NETMASK_ADDR0, NETMASK_ADDR1, NETMASK_ADDR2, NETMASK_ADDR3);
          IP_ADDR4(&gw, GW_ADDR0, GW_ADDR1, GW_ADDR2, GW_ADDR3);
          netif_set_addr(netif, &ipaddr, &netmask, &gw);
          
          
          sprintf((char *)iptxt, "%s", ip4addr_ntoa((const ip4_addr_t *)&netif->ip_addr));
          
         
          MyPrintf_USART1("########### DHCP Timeout !! \n\r");
          //MyPrintf_USART1 ("########### Static IP address: %s\n\r", iptxt);
          
         // sprintf(&mLCDPrintBuf[0][0],"Static IP address: %s\n\r", iptxt);
          

          netif_set_up(netif);
          
          
        }
        else
        {
          MyPrintf_USART1("########### DHCP TimeCnt[%d] \n\r",dhcp->tries);
          
          //sprintf(&mLCDPrintBuf[0][0],"DHCP TimeCnt[%d]",dhcp->tries);
        }
      }
    }
    break;
  case DHCP_LINK_DOWN:
    {
        
         dhcp = (struct dhcp *)netif_get_client_data(netif, LWIP_NETIF_CLIENT_DATA_INDEX_DHCP);
    
        /* DHCP timeout */
        if (dhcp->tries > MAX_DHCP_TRIES)
        {
          /* Stop DHCP */
          dhcp_stop(netif);
          DHCP_state = DHCP_OFF; 
        }
        else
        {
           
    
            /* When the netif is fully configured this function must be called.*/
            netif_set_up(netif);    
            
            
      
            
        }
        
        
    }
    break;
  default: break;
  }
}

/**
  * @brief  DHCP periodic check
  * @param  localtime the current LocalTime value
  * @retval None
  */
void DHCP_Periodic_Handle(struct netif *netif)
{  
  /* Fine DHCP periodic process every 500ms */
  if (HAL_GetTick() - DHCPfineTimer >= DHCP_FINE_TIMER_MSECS)
  {
    DHCPfineTimer =  HAL_GetTick();
    /* process DHCP state machine */
    DHCP_Process(netif);    
    
     //MyPrintf_USART1 ("DHCP_Periodic_Handle \n");
     
  }
}
#endif

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
