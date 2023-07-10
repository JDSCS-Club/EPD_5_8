/*
    ******************************************************************************
    * @Company              : Woojin Industrial Systems Co., Ltd.
    * @Engineer             : D.S.JANG
    * @ModuleName           : ethernetif.c
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
#include "lwip/timeouts.h"
#include "netif/etharp.h"
#include "ethernetif.h"
#include "LED.h"
#include "CRC8.h"
#include "main.h"
#include "USRAT.h"
#include "Flash.h"
#include <string.h>

#include "sys.h"

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Network interface name */
#define IFNAME0 's'
#define IFNAME1 't'

/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
#if defined ( __ICCARM__ ) /*!< IAR Compiler */
  #pragma data_alignment=4   
#endif
__ALIGN_BEGIN ETH_DMADescTypeDef  DMARxDscrTab[ETH_RXBUFNB] __ALIGN_END;/* Ethernet Rx MA Descriptor */

#if defined ( __ICCARM__ ) /*!< IAR Compiler */
  #pragma data_alignment=4   
#endif
__ALIGN_BEGIN ETH_DMADescTypeDef  DMATxDscrTab[ETH_TXBUFNB] __ALIGN_END;/* Ethernet Tx DMA Descriptor */

#if defined ( __ICCARM__ ) /*!< IAR Compiler */
  #pragma data_alignment=4   
#endif
__ALIGN_BEGIN uint8_t Rx_Buff[ETH_RXBUFNB][ETH_RX_BUF_SIZE] __ALIGN_END; /* Ethernet Receive Buffer */

#if defined ( __ICCARM__ ) /*!< IAR Compiler */
  #pragma data_alignment=4   
#endif
__ALIGN_BEGIN uint8_t Tx_Buff[ETH_TXBUFNB][ETH_TX_BUF_SIZE] __ALIGN_END; /* Ethernet Transmit Buffer */

ETH_HandleTypeDef EthHandle;

/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/
/*******************************************************************************
                       Ethernet MSP Routines
*******************************************************************************/
/**
  * @brief  Initializes the ETH MSP.
  * @param  heth: ETH handle
  * @retval None
  */
void HAL_ETH_MspInit(ETH_HandleTypeDef *heth)
{ 
  GPIO_InitTypeDef GPIO_InitStructure;
  
  /* Enable GPIOs clocks */
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOE_CLK_ENABLE();
  
//  
//  __HAL_RCC_GPIOF_CLK_ENABLE();
//  __HAL_RCC_GPIOG_CLK_ENABLE();
//  __HAL_RCC_GPIOH_CLK_ENABLE();
//  __HAL_RCC_GPIOI_CLK_ENABLE(); 

/* Ethernet pins configuration ************************************************/
   /*
        ETH_MDIO -------------------------> PA2   -A2   - A2
        ETH_MDC --------------------------> PC1   -C1   - C1
        ETH_PPS_OUT ----------------------> PB5 X -     - 
        ETH_MII_CRS ----------------------> PH2   -A0   - A0
        ETH_MII_COL ----------------------> PH3   -A3   - A3
        ETH_MII_RX_ERB --------------------> PI10 -B10  - B10
        ETH_MII_RXD2 ---------------------> PH6   -B0   - B0
        ETH_MII_RXD3 ---------------------> PH7   -B1   - B1
        ETH_MII_TX_CLK -------------------> PC3   -C3   - C3
        ETH_MII_TXD2 ---------------------> PC2   -C2   - C2
        ETH_MII_TXD3 ---------------------> PB8   -E2   - E2 -
        ETH_MII_RX_CLK/ETH_RMII_REF_CLK---> PA1   -A1   - A1
        ETH_MII_RX_DV/ETH_RMII_CRS_DV ----> PA7   -A7   - A7
        ETH_MII_RXD0/ETH_RMII_RXD0 -------> PC4   -C4   - C4
        ETH_MII_RXD1/ETH_RMII_RXD1 -------> PC5   -C5   - C5
        ETH_MII_TX_EN/ETH_RMII_TX_EN -----> PG11  -B11  - B11
        ETH_MII_TXD0/ETH_RMII_TXD0 -------> PG13  -B12  - B12
        ETH_MII_TXD1/ETH_RMII_TXD1 -------> PG14  -B13  - B13
                                                  */

//  /* Configure PA1, PA2 , PA7 */
//  GPIO_InitStructure.Pin = GPIO_PIN_1 | GPIO_PIN_2 | GPIO_PIN_7;
//  GPIO_InitStructure.Speed = GPIO_SPEED_HIGH;
//  GPIO_InitStructure.Mode = GPIO_MODE_AF_PP;
//  GPIO_InitStructure.Pull = GPIO_NOPULL; 
//  GPIO_InitStructure.Alternate = GPIO_AF11_ETH;
//  HAL_GPIO_Init(GPIOA, &GPIO_InitStructure);
//
//  /* Configure PB5 and PB8 */
//  GPIO_InitStructure.Pin = GPIO_PIN_5 | GPIO_PIN_8;
//  HAL_GPIO_Init(GPIOB, &GPIO_InitStructure);
//
//  /* Configure PC1, PC2, PC3, PC4 and PC5 */
//  GPIO_InitStructure.Pin = GPIO_PIN_1 | GPIO_PIN_2 | GPIO_PIN_3 | GPIO_PIN_4 | GPIO_PIN_5;
//  HAL_GPIO_Init(GPIOC, &GPIO_InitStructure);
//                             
//  /* Configure PG11, PG14 and PG13 */
//  GPIO_InitStructure.Pin =  GPIO_PIN_11 | GPIO_PIN_13 | GPIO_PIN_14;
//  HAL_GPIO_Init(GPIOG, &GPIO_InitStructure);
//
//  /* Configure PH2, PH3, PH6, PH7 */
//  GPIO_InitStructure.Pin = GPIO_PIN_2 | GPIO_PIN_3 | GPIO_PIN_6 | GPIO_PIN_7;
//  HAL_GPIO_Init(GPIOH, &GPIO_InitStructure);
//
//  /* Configure PI10 */
//  GPIO_InitStructure.Pin = GPIO_PIN_10;
//  HAL_GPIO_Init(GPIOI, &GPIO_InitStructure);
  
  
    GPIO_InitStructure.Pin = GPIO_PIN_2;
    GPIO_InitStructure.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStructure.Pull = GPIO_NOPULL;
    GPIO_InitStructure.Speed = GPIO_SPEED_HIGH;
    GPIO_InitStructure.Alternate = GPIO_AF11_ETH;
    HAL_GPIO_Init(GPIOE, &GPIO_InitStructure);

    GPIO_InitStructure.Pin = GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3|GPIO_PIN_4
                          |GPIO_PIN_5;
    GPIO_InitStructure.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStructure.Pull = GPIO_NOPULL;
    GPIO_InitStructure.Speed = GPIO_SPEED_HIGH;
    GPIO_InitStructure.Alternate = GPIO_AF11_ETH;
    HAL_GPIO_Init(GPIOC, &GPIO_InitStructure);

    GPIO_InitStructure.Pin = GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3
                          |GPIO_PIN_7;
    GPIO_InitStructure.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStructure.Pull = GPIO_NOPULL;
    GPIO_InitStructure.Speed = GPIO_SPEED_HIGH;
    GPIO_InitStructure.Alternate = GPIO_AF11_ETH;
    HAL_GPIO_Init(GPIOA, &GPIO_InitStructure);

    GPIO_InitStructure.Pin = GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_10|GPIO_PIN_11
                          |GPIO_PIN_12|GPIO_PIN_13;
    GPIO_InitStructure.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStructure.Pull = GPIO_NOPULL;
    GPIO_InitStructure.Speed = GPIO_SPEED_HIGH;
    GPIO_InitStructure.Alternate = GPIO_AF11_ETH;
    HAL_GPIO_Init(GPIOB, &GPIO_InitStructure);
  

  
//  /* Enable ETHERNET clock  */
    __HAL_RCC_ETH_CLK_ENABLE();
//  
//  if (heth->Init.MediaInterface == ETH_MEDIA_INTERFACE_MII)
//  {
//    /* Output HSE clock (25MHz) on MCO pin (PA8) to clock the PHY */
//    //HAL_RCC_MCOConfig(RCC_MCO1, RCC_MCO1SOURCE_HSE, RCC_MCODIV_1);
//  }
}

/*******************************************************************************
                       LL Driver Interface ( LwIP stack --> ETH) 
*******************************************************************************/
/**
  * @brief In this function, the hardware should be initialized.
  * Called from ethernetif_init().
  *
  * @param netif the already initialized lwip network interface structure
  *        for this ethernetif
  */
static void low_level_init(struct netif *netif)
{ 
  uint32_t regvalue = 0;
  uint64_t sMacAdd = 0x183009003610; //SEPTA ML MAC 시작 주소.
  uint8_t sHSW_1 = 0;
  uint8_t sHSW_2 = 0;
  uint8_t sHSW_3 = 0;
  
  static int sAddr_Cnt = 0;
  
  sAddr_Cnt++;
  
  sAddr_Cnt = (sAddr_Cnt > 31 ) ? 0 : sAddr_Cnt;
  
  MyPrintf_USART1(">>>>>>>>>>>---------(%d)\r\n",sAddr_Cnt);
  

  
  uint8_t macaddress[6]= { MAC_ADDR0, MAC_ADDR1, MAC_ADDR2, MAC_ADDR3, MAC_ADDR4, MAC_ADDR5 };
  
  
//  sHSW_1 = IP_ADDR1_INPUT_DATA; 
//  sHSW_2 = IP_ADDR2_INPUT_DATA;
//  sHSW_3 = IP_ADDR3_INPUT_DATA;
//  
//  //sHSW_L = ((sHSW_L > 20) ? 20 : sHSW_L);
//    
//  sMacAdd = sMacAdd + (sHSW_3*30) + (sHSW_2*20) + (sHSW_1*1) + mID_TAG_INPUT_DATA; //sMacAddBuf[sHSW_L];
//  
//  macaddress[0] = (sMacAdd>>40)&0xFF;
//  macaddress[1] = (sMacAdd>>32)&0xFF;
//  macaddress[2] = (sMacAdd>>24)&0xFF;
//  macaddress[3] = (sMacAdd>>16)&0xFF;
//  macaddress[4] = (sMacAdd>>8)&0xFF;
//  macaddress[5] = (sMacAdd>>0)&0xFF;

  
  EthHandle.Instance = ETH;  
  EthHandle.Init.MACAddr = macaddress;
  EthHandle.Init.AutoNegotiation = ETH_AUTONEGOTIATION_DISABLE;
  EthHandle.Init.Speed = ETH_SPEED_100M;
  EthHandle.Init.DuplexMode = ETH_MODE_FULLDUPLEX;
  EthHandle.Init.MediaInterface = ETH_MEDIA_INTERFACE_MII;
  EthHandle.Init.RxMode = ETH_RXPOLLING_MODE;
  EthHandle.Init.ChecksumMode = ETH_CHECKSUM_BY_HARDWARE;
  
  
  EthHandle.Init.PhyAddress = DP83848_PHY_ADDRESS;
  
  //EthHandle.Init.PhyAddress = sAddr_Cnt;
  
  
  
  
  
  HAL_Delay(10);
  
  /* configure ethernet peripheral (GPIOs, clocks, MAC, DMA) */
  if (HAL_ETH_Init(&EthHandle) == HAL_OK)
  {
    /* Set netif link flag */
    netif->flags |= NETIF_FLAG_LINK_UP;
  }
  
  /* Initialize Tx Descriptors list: Chain Mode */
  HAL_ETH_DMATxDescListInit(&EthHandle, DMATxDscrTab, &Tx_Buff[0][0], ETH_TXBUFNB);
     
  HAL_Delay(10);
  /* Initialize Rx Descriptors list: Chain Mode  */
  HAL_ETH_DMARxDescListInit(&EthHandle, DMARxDscrTab, &Rx_Buff[0][0], ETH_RXBUFNB);

  HAL_Delay(10);
  /* set MAC hardware address length */
  netif->hwaddr_len = ETH_HWADDR_LEN;
  
  /* set MAC hardware address */
  netif->hwaddr[0] =  MAC_ADDR0 ;//MAC_ADDR0;
  netif->hwaddr[1] =  MAC_ADDR1;//MAC_ADDR1;
  netif->hwaddr[2] =  MAC_ADDR2;//IP_ADDR1_INPUT_DATA;
  netif->hwaddr[3] =  MAC_ADDR3;//IP_ADDR2_INPUT_DATA;
  netif->hwaddr[4] =  MAC_ADDR4;//IP_ADDR3_INPUT_DATA;
  netif->hwaddr[5] =  MAC_ADDR5;//IP_ADDR4_INPUT_DATA;
  
  /* maximum transfer unit */
  netif->mtu = 1500;
  
  /* device capabilities */
  /* don't set NETIF_FLAG_ETHARP if this device is not an ethernet one */
  netif->flags |= NETIF_FLAG_BROADCAST | NETIF_FLAG_ETHARP | NETIF_FLAG_IGMP;
  
  /* Enable MAC and DMA transmission and reception */
  HAL_ETH_Start(&EthHandle);
  
  HAL_Delay(10);
  /**** Configure PHY to generate an interrupt when Eth Link state changes ****/
  /* Read Register Configuration */
  HAL_ETH_ReadPHYRegister(&EthHandle, PHY_MICR, &regvalue);
  
  HAL_Delay(10);
  regvalue |= (PHY_MICR_INT_EN | PHY_MICR_INT_OE);

  /* Enable Interrupts */
  HAL_ETH_WritePHYRegister(&EthHandle, PHY_MICR, regvalue );
  
  HAL_Delay(10);
  /* Read Register Configuration */
  HAL_ETH_ReadPHYRegister(&EthHandle, PHY_MISR, &regvalue);
  
  HAL_Delay(10);
  regvalue |= PHY_MISR_LINK_INT_EN;
    
  /* Enable Interrupt on change of link status */
  HAL_ETH_WritePHYRegister(&EthHandle, PHY_MISR, regvalue);
}

/**
  * @brief This function should do the actual transmission of the packet. The packet is
  * contained in the pbuf that is passed to the function. This pbuf
  * might be chained.
  *
  * @param netif the lwip network interface structure for this ethernetif
  * @param p the MAC packet to send (e.g. IP packet including MAC addresses and type)
  * @return ERR_OK if the packet could be sent
  *         an err_t value if the packet couldn't be sent
  *
  * @note Returning ERR_MEM here if a DMA queue of your MAC is full can lead to
  *       strange results. You might consider waiting for space in the DMA queue
  *       to become availale since the stack doesn't retry to send a packet
  *       dropped because of memory failure (except for the TCP timers).
  */
static err_t low_level_output(struct netif *netif, struct pbuf *p)
{
  err_t errval;
  struct pbuf *q;
  uint8_t *buffer = (uint8_t *)(EthHandle.TxDesc->Buffer1Addr);
  __IO ETH_DMADescTypeDef *DmaTxDesc;
  uint32_t framelength = 0;
  uint32_t bufferoffset = 0;
  uint32_t byteslefttocopy = 0;
  uint32_t payloadoffset = 0;

  DmaTxDesc = EthHandle.TxDesc;
  bufferoffset = 0;
  
  /* copy frame from pbufs to driver buffers */
  for(q = p; q != NULL; q = q->next)
  {
    /* Is this buffer available? If not, goto error */
    if((DmaTxDesc->Status & ETH_DMATXDESC_OWN) != (uint32_t)RESET)
    {
      errval = ERR_USE;
      goto error;
    }
    
    /* Get bytes in current lwIP buffer */
    byteslefttocopy = q->len;
    payloadoffset = 0;
    
    /* Check if the length of data to copy is bigger than Tx buffer size*/
    while( (byteslefttocopy + bufferoffset) > ETH_TX_BUF_SIZE )
    {
      /* Copy data to Tx buffer*/
      memcpy( (uint8_t*)((uint8_t*)buffer + bufferoffset), (uint8_t*)((uint8_t*)q->payload + payloadoffset), (ETH_TX_BUF_SIZE - bufferoffset) );
      
      /* Point to next descriptor */
      DmaTxDesc = (ETH_DMADescTypeDef *)(DmaTxDesc->Buffer2NextDescAddr);
      
      /* Check if the buffer is available */
      if((DmaTxDesc->Status & ETH_DMATXDESC_OWN) != (uint32_t)RESET)
      {
        errval = ERR_USE;
        goto error;
      }
      
      buffer = (uint8_t *)(DmaTxDesc->Buffer1Addr);
      
      byteslefttocopy = byteslefttocopy - (ETH_TX_BUF_SIZE - bufferoffset);
      payloadoffset = payloadoffset + (ETH_TX_BUF_SIZE - bufferoffset);
      framelength = framelength + (ETH_TX_BUF_SIZE - bufferoffset);
      bufferoffset = 0;
    }
    
    /* Copy the remaining bytes */
    memcpy( (uint8_t*)((uint8_t*)buffer + bufferoffset), (uint8_t*)((uint8_t*)q->payload + payloadoffset), byteslefttocopy );
    bufferoffset = bufferoffset + byteslefttocopy;
    framelength = framelength + byteslefttocopy;
  }
  
  /* Prepare transmit descriptors to give to DMA */ 
  HAL_ETH_TransmitFrame(&EthHandle, framelength);
  
  errval = ERR_OK;
  
error:
  
  /* When Transmit Underflow flag is set, clear it and issue a Transmit Poll Demand to resume transmission */
  if ((EthHandle.Instance->DMASR & ETH_DMASR_TUS) != (uint32_t)RESET)
  {
    /* Clear TUS ETHERNET DMA flag */
    EthHandle.Instance->DMASR = ETH_DMASR_TUS;
    
    /* Resume DMA transmission*/
    EthHandle.Instance->DMATPDR = 0;
  }
  return errval;
}

/**
  * @brief Should allocate a pbuf and transfer the bytes of the incoming
  * packet from the interface into the pbuf.
  *
  * @param netif the lwip network interface structure for this ethernetif
  * @return a pbuf filled with the received packet (including MAC header)
  *         NULL on memory error
  */


uint8_t JDS_CRC1 = 0;
uint8_t JDS_CRC2 = 0;
static struct pbuf * low_level_input(struct netif *netif)
{
    struct pbuf *p = NULL;
    struct pbuf *q;
    uint16_t len;
    uint8_t *buffer;
    __IO ETH_DMADescTypeDef *dmarxdesc;
    uint32_t bufferoffset = 0;
    uint32_t payloadoffset = 0;
    uint32_t byteslefttocopy = 0;
    uint32_t i=0;
	
    uint8_t *pCrc;
    
    uint8_t sCrC = 0;
  
  if (HAL_ETH_GetReceivedFrame(&EthHandle) != HAL_OK)
    return NULL;
  
  /* Obtain the size of the packet and put it into the "len" variable. */
  len = EthHandle.RxFrameInfos.length;
  buffer = (uint8_t *)EthHandle.RxFrameInfos.buffer;
	
	

  if (len > 0)
  {
    /* We allocate a pbuf chain of pbufs from the Lwip buffer pool */
    p = pbuf_alloc(PBUF_RAW, len, PBUF_POOL);
  }
  
  if (p != NULL)
  {
    dmarxdesc = EthHandle.RxFrameInfos.FSRxDesc;
    bufferoffset = 0;
    
    for(q = p; q != NULL; q = q->next)
    {
      byteslefttocopy = q->len;
      payloadoffset = 0;
      
      /* Check if the length of bytes to copy in current pbuf is bigger than Rx buffer size */
      while( (byteslefttocopy + bufferoffset) > ETH_RX_BUF_SIZE )
      {
        /* Copy data to pbuf */
        memcpy( (uint8_t*)((uint8_t*)q->payload + payloadoffset), (uint8_t*)((uint8_t*)buffer + bufferoffset), (ETH_RX_BUF_SIZE - bufferoffset));
        
        /* Point to next descriptor */
        dmarxdesc = (ETH_DMADescTypeDef *)(dmarxdesc->Buffer2NextDescAddr);
        buffer = (uint8_t *)(dmarxdesc->Buffer1Addr);
        
        byteslefttocopy = byteslefttocopy - (ETH_RX_BUF_SIZE - bufferoffset);
        payloadoffset = payloadoffset + (ETH_RX_BUF_SIZE - bufferoffset);
        bufferoffset = 0;
      }
      
      /* Copy remaining data in pbuf */
      memcpy( (uint8_t*)((uint8_t*)q->payload + payloadoffset), (uint8_t*)((uint8_t*)buffer + bufferoffset), byteslefttocopy);
      bufferoffset = bufferoffset + byteslefttocopy;
    }
  } 
    
  /* Release descriptors to DMA */
  /* Point to first descriptor */
  dmarxdesc = EthHandle.RxFrameInfos.FSRxDesc;
  /* Set Own bit in Rx descriptors: gives the buffers back to DMA */
  for (i=0; i< EthHandle.RxFrameInfos.SegCount; i++)
  {  
    dmarxdesc->Status |= ETH_DMARXDESC_OWN;
    dmarxdesc = (ETH_DMADescTypeDef *)(dmarxdesc->Buffer2NextDescAddr);
  }
  
  /* Clear Segment_Count */
  EthHandle.RxFrameInfos.SegCount =0;
  
  /* When Rx Buffer unavailable flag is set: clear it and resume reception */
  if ((EthHandle.Instance->DMASR & ETH_DMASR_RBUS) != (uint32_t)RESET)  
  {
    /* Clear RBUS ETHERNET DMA flag */
    EthHandle.Instance->DMASR = ETH_DMASR_RBUS;
    /* Resume DMA reception */
    EthHandle.Instance->DMARPDR = 0;
  }
  return p;
}

/**
  * @brief This function should be called when a packet is ready to be read
  * from the interface. It uses the function low_level_input() that
  * should handle the actual reception of bytes from the network
  * interface. Then the type of the received packet is determined and
  * the appropriate input function is called.
  *
  * @param netif the lwip network interface structure for this ethernetif
  */

//uint8_t d_EthernetTestBuf[100];

	//uint16_t d_Type;
   


void ethernetif_input(struct netif *netif)
{
  err_t err;
  struct pbuf *p;
	
	
  struct eth_hdr* ethhdr;
  
  
  /* move received packet into a new pbuf */
  p = low_level_input(netif);
    
  	
  /* no packet could be read, silently ignore this */
  if (p == NULL) return;

  
	//ethhdr = (struct eth_hdr *)p->payload;
	

  //네트워크 수신 데이타 체크 하는 함수
 //memcpy(d_EthernetTestBuf, (uint8_t*)((uint8_t*)p->payload),100);
    
    
  /* entry point to the LwIP stack */
  err = netif->input(p, netif);
  
  
    
  if (err != ERR_OK)
  {
	  MyPrintf_USART1("ethernetif_input: IP input error\n");
    pbuf_free(p);
    p = NULL;
  }
}

/**
  * @brief Should be called at the beginning of the program to set up the
  * network interface. It calls the function low_level_init() to do the
  * actual setup of the hardware.
  *
  * This function should be passed as a parameter to netif_add().
  *
  * @param netif the lwip network interface structure for this ethernetif
  * @return ERR_OK if the loopif is initialized
  *         ERR_MEM if private data couldn't be allocated
  *         any other err_t on error
  */
err_t ethernetif_init(struct netif *netif)
{
  LWIP_ASSERT("netif != NULL", (netif != NULL));
  
#if LWIP_NETIF_HOSTNAME
  /* Initialize interface hostname */
  netif->hostname = "lwip";
#endif /* LWIP_NETIF_HOSTNAME */

  netif->name[0] = IFNAME0;
  netif->name[1] = IFNAME1;
  /* We directly use etharp_output() here to save a function call.
   * You can instead declare your own function an call etharp_output()
   * from it if you have to do some checks before sending (e.g. if link
   * is available...) */
  netif->output = etharp_output;
  netif->linkoutput = low_level_output;

  /* initialize the hardware */
  low_level_init(netif);

  return ERR_OK;
}

/**
  * @brief  Returns the current time in milliseconds
  *         when LWIP_TIMERS == 1 and NO_SYS == 1
  * @param  None
  * @retval Current Time value
  */
u32_t sys_now(void)
{
  return HAL_GetTick();
}

/**
  * @brief  This function sets the netif link status.
  * @param  netif: the network interface
  * @retval None
  */
void ethernetif_set_link(struct netif *netif)
{
  uint32_t regvalue = 0;
  
  /* Read PHY_MISR*/
  HAL_ETH_ReadPHYRegister(&EthHandle, PHY_MISR, &regvalue);
  
  /* Check whether the link interrupt has occurred or not */
  if((regvalue & PHY_LINK_INTERRUPT) != (uint16_t)RESET)
  {
    /* Read PHY_SR*/
    HAL_ETH_ReadPHYRegister(&EthHandle, PHY_SR, &regvalue);
    
    /* Check whether the link is up or down*/
    if((regvalue & PHY_LINK_STATUS)!= (uint16_t)RESET)
    {
      netif_set_link_up(netif);
    }
    else
    {
      netif_set_link_down(netif);
    }
  }
}

/**
  * @brief  Link callback function, this function is called on change of link status
  *         to update low level driver configuration.
  * @param  netif: The network interface
  * @retval None
  */
void ethernetif_update_config(struct netif *netif)
{
  __IO uint32_t tickstart = 0;
  uint32_t regvalue = 0;
  
  if(netif_is_link_up(netif))
  { 
    /* Restart the auto-negotiation */
    if(EthHandle.Init.AutoNegotiation != ETH_AUTONEGOTIATION_DISABLE)
    {
      /* Enable Auto-Negotiation */
      HAL_ETH_WritePHYRegister(&EthHandle, PHY_BCR, PHY_AUTONEGOTIATION);
      
      /* Get tick */
      tickstart = HAL_GetTick();
      
      /* Wait until the auto-negotiation will be completed */
      do
      {
        HAL_ETH_ReadPHYRegister(&EthHandle, PHY_BSR, &regvalue);
        
        /* Check for the Timeout ( 1s ) */
        if((HAL_GetTick() - tickstart ) > 1000)
        {
          /* In case of timeout */
          goto error;
        }
        
      } while (((regvalue & PHY_AUTONEGO_COMPLETE) != PHY_AUTONEGO_COMPLETE));
      
      /* Read the result of the auto-negotiation */
      HAL_ETH_ReadPHYRegister(&EthHandle, PHY_SR, &regvalue);
      
      /* Configure the MAC with the Duplex Mode fixed by the auto-negotiation process */
      if((regvalue & PHY_DUPLEX_STATUS) != (uint32_t)RESET)
      {
        /* Set Ethernet duplex mode to Full-duplex following the auto-negotiation */
        EthHandle.Init.DuplexMode = ETH_MODE_FULLDUPLEX;  
      }
      else
      {
        /* Set Ethernet duplex mode to Half-duplex following the auto-negotiation */
        EthHandle.Init.DuplexMode = ETH_MODE_HALFDUPLEX;           
      }
      /* Configure the MAC with the speed fixed by the auto-negotiation process */
      if(regvalue & PHY_SPEED_STATUS)
      {  
        /* Set Ethernet speed to 10M following the auto-negotiation */
        EthHandle.Init.Speed = ETH_SPEED_10M; 
      }
      else
      {   
        /* Set Ethernet speed to 100M following the auto-negotiation */ 
        EthHandle.Init.Speed = ETH_SPEED_100M;
      }
    }
    else /* AutoNegotiation Disable */
    {
    error :
      /* Check parameters */
      assert_param(IS_ETH_SPEED(EthHandle.Init.Speed));
      assert_param(IS_ETH_DUPLEX_MODE(EthHandle.Init.DuplexMode));
      
      /* Set MAC Speed and Duplex Mode to PHY */
      HAL_ETH_WritePHYRegister(&EthHandle, PHY_BCR, ((uint16_t)(EthHandle.Init.DuplexMode >> 3) |
                                                     (uint16_t)(EthHandle.Init.Speed >> 1))); 
    }

    /* ETHERNET MAC Re-Configuration */
    HAL_ETH_ConfigMAC(&EthHandle, (ETH_MACInitTypeDef *) NULL);

    /* Restart MAC interface */
    HAL_ETH_Start(&EthHandle);   
  }
  else
  {
    /* Stop MAC interface */
    HAL_ETH_Stop(&EthHandle);
  }

  ethernetif_notify_conn_changed(netif);
}

/**
  * @brief  This function notify user about link status changement.
  * @param  netif: the network interface
  * @retval None
  */
__weak void ethernetif_notify_conn_changed(struct netif *netif)
{
  /* NOTE : This is function could be implemented in user file 
            when the callback is needed,
  */  
}
/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/