



































   

 




































  

 

   
 



































 

 


 
 
 

  #pragma system_include

 
 

 

  #pragma system_include














 


 
 


  #pragma system_include

 



 

 

 

 
#pragma rtmodel = "__dlib_version", "6"

 


 



























 


  #pragma system_include

 
 
 


  #pragma system_include

 

 

 

 

   

 
 


   #pragma system_include






 




 


 


 


 

 


 

 

 

 

 

 

 

 

 

 
















 



















 











 























 





 



 










 














 













 








 













 













 















 











 








 








 






 





 












 





 













 






 


   


  







 







 




 






 




 




 













 

   




 







 







 







 










 





 

















 


 


 













 

   


 


 



 

 

 
  typedef unsigned int _Wchart;
  typedef unsigned int _Wintt;

 

 
typedef unsigned int     _Sizet;

 
typedef signed char   __int8_t;
typedef unsigned char  __uint8_t;
typedef signed short int   __int16_t;
typedef unsigned short int  __uint16_t;
typedef signed int   __int32_t;
typedef unsigned int  __uint32_t;
   typedef signed long long int   __int64_t;
   typedef unsigned long long int  __uint64_t;
typedef signed int   __intptr_t;
typedef unsigned int  __uintptr_t;

 
typedef struct _Mbstatet
{  
    unsigned int _Wchar;   
    unsigned int _State;   

} _Mbstatet;

 

 
  typedef struct __va_list __Va_list;


    typedef struct __FILE _Filet;

 
typedef struct
{
    long long _Off;     
  _Mbstatet _Wstate;
} _Fpost;


 

 
  
   
  _Pragma("object_attribute = __weak") __intrinsic __nounwind void __iar_Locksyslock_Malloc(void);
  _Pragma("object_attribute = __weak") __intrinsic __nounwind void __iar_Locksyslock_Stream(void);
  _Pragma("object_attribute = __weak") __intrinsic __nounwind void __iar_Locksyslock_Debug(void);
  _Pragma("object_attribute = __weak") __intrinsic __nounwind void __iar_Locksyslock_StaticGuard(void);
  _Pragma("object_attribute = __weak") __intrinsic __nounwind void __iar_Unlocksyslock_Malloc(void);
  _Pragma("object_attribute = __weak") __intrinsic __nounwind void __iar_Unlocksyslock_Stream(void);
  _Pragma("object_attribute = __weak") __intrinsic __nounwind void __iar_Unlocksyslock_Debug(void);
  _Pragma("object_attribute = __weak") __intrinsic __nounwind void __iar_Unlocksyslock_StaticGuard(void);

      _Pragma("object_attribute = __weak") __intrinsic __nounwind void __iar_Lockfilelock(_Filet *);
      _Pragma("object_attribute = __weak") __intrinsic __nounwind void __iar_Unlockfilelock(_Filet *);

  typedef void *__iar_Rmtx;

  _Pragma("object_attribute = __weak") __intrinsic __nounwind void __iar_Initdynamiclock(__iar_Rmtx *);
  _Pragma("object_attribute = __weak") __intrinsic __nounwind void __iar_Dstdynamiclock(__iar_Rmtx *);
  _Pragma("object_attribute = __weak") __intrinsic __nounwind void __iar_Lockdynamiclock(__iar_Rmtx *);
  _Pragma("object_attribute = __weak") __intrinsic __nounwind void __iar_Unlockdynamiclock(__iar_Rmtx *);

  






 


 
  typedef signed char          int8_t;
  typedef unsigned char        uint8_t;

  typedef signed short int         int16_t;
  typedef unsigned short int       uint16_t;

  typedef signed int         int32_t;
  typedef unsigned int       uint32_t;

  typedef signed long long int         int64_t;
  typedef unsigned long long int       uint64_t;


 
typedef signed char      int_least8_t;
typedef unsigned char    uint_least8_t;

typedef signed short int     int_least16_t;
typedef unsigned short int   uint_least16_t;

typedef signed int     int_least32_t;
typedef unsigned int   uint_least32_t;

 
  typedef signed long long int   int_least64_t;
  typedef unsigned long long int uint_least64_t;



 
typedef signed int       int_fast8_t;
typedef unsigned int     uint_fast8_t;

typedef signed int      int_fast16_t;
typedef unsigned int    uint_fast16_t;

typedef signed int      int_fast32_t;
typedef unsigned int    uint_fast32_t;

  typedef signed long long int    int_fast64_t;
  typedef unsigned long long int  uint_fast64_t;

 
typedef signed long long int          intmax_t;
typedef unsigned long long int        uintmax_t;


 
typedef signed int          intptr_t;
typedef unsigned int        uintptr_t;

 
typedef int __data_intptr_t; typedef unsigned int __data_uintptr_t;

 






















 











 



 



 
    


 



 



 
typedef struct
{  
  void       (*Init)(uint16_t);
  uint16_t   (*ReadID)(uint16_t);
  void       (*Reset)(uint16_t);
  void       (*Start)(uint16_t);
  uint8_t    (*DetectTouch)(uint16_t);
  void       (*GetXY)(uint16_t, uint16_t*, uint16_t*);
  void       (*EnableIT)(uint16_t);
  void       (*ClearIT)(uint16_t);
  uint8_t    (*GetITStatus)(uint16_t);
  void       (*DisableIT)(uint16_t);
}TS_DrvTypeDef;


 



 



 



 



 



 



































  

 


 



 



 
    


 



 



 
typedef enum
{
  IO_PIN_RESET = 0,
  IO_PIN_SET
}IO_PinState;

typedef enum
{
   IO_MODE_INPUT = 0,    
   IO_MODE_OUTPUT,       
   IO_MODE_IT_RISING_EDGE,    
   IO_MODE_IT_FALLING_EDGE,   
   IO_MODE_IT_LOW_LEVEL,      
   IO_MODE_IT_HIGH_LEVEL,     
    
   IO_MODE_ANALOG,            
   IO_MODE_OFF,               
   IO_MODE_INPUT_PU,          
   IO_MODE_INPUT_PD,          
   IO_MODE_OUTPUT_OD,           
   IO_MODE_OUTPUT_OD_PU,        
   IO_MODE_OUTPUT_OD_PD,        
   IO_MODE_OUTPUT_PP,           
   IO_MODE_OUTPUT_PP_PU,        
   IO_MODE_OUTPUT_PP_PD,        
   IO_MODE_IT_RISING_EDGE_PU,    
   IO_MODE_IT_RISING_EDGE_PD,    
   IO_MODE_IT_FALLING_EDGE_PU,   
   IO_MODE_IT_FALLING_EDGE_PD,   
   IO_MODE_IT_LOW_LEVEL_PU,      
   IO_MODE_IT_LOW_LEVEL_PD,      
   IO_MODE_IT_HIGH_LEVEL_PU,     
   IO_MODE_IT_HIGH_LEVEL_PD,     

}IO_ModeTypedef;



 
typedef struct
{  
  void       (*Init)(uint16_t);
  uint16_t   (*ReadID)(uint16_t);
  void       (*Reset)(uint16_t);
  
  void       (*Start)(uint16_t, uint32_t);
  uint8_t    (*Config)(uint16_t, uint32_t, IO_ModeTypedef);
  void       (*WritePin)(uint16_t, uint32_t, uint8_t);
  uint32_t   (*ReadPin)(uint16_t, uint32_t);
  
  void       (*EnableIT)(uint16_t);
  void       (*DisableIT)(uint16_t);
  uint32_t    (*ITStatus)(uint16_t, uint32_t);
  void       (*ClearIT)(uint16_t, uint32_t);
    
}IO_DrvTypeDef;


 



 



 



 



 



 



  



 
    


     



  


  
   


  

    
    
  

  

         

  
    
  

  

  

  

  

  

  

  

    

    

 

 


  
   


  


  
   


 



 
void     stmpe811_Init(uint16_t DeviceAddr);
void     stmpe811_Reset(uint16_t DeviceAddr);
uint16_t stmpe811_ReadID(uint16_t DeviceAddr);
void     stmpe811_EnableGlobalIT(uint16_t DeviceAddr);
void     stmpe811_DisableGlobalIT(uint16_t DeviceAddr);
void     stmpe811_EnableITSource(uint16_t DeviceAddr, uint8_t Source);
void     stmpe811_DisableITSource(uint16_t DeviceAddr, uint8_t Source);
void     stmpe811_SetITPolarity(uint16_t DeviceAddr, uint8_t Polarity);
void     stmpe811_SetITType(uint16_t DeviceAddr, uint8_t Type);
uint8_t  stmpe811_GlobalITStatus(uint16_t DeviceAddr, uint8_t Source);
uint8_t  stmpe811_ReadGITStatus(uint16_t DeviceAddr, uint8_t Source);
void     stmpe811_ClearGlobalIT(uint16_t DeviceAddr, uint8_t Source);



 
void     stmpe811_IO_Start(uint16_t DeviceAddr, uint32_t IO_Pin);
uint8_t  stmpe811_IO_Config(uint16_t DeviceAddr, uint32_t IO_Pin, IO_ModeTypedef IO_Mode);
void     stmpe811_IO_InitPin(uint16_t DeviceAddr, uint32_t IO_Pin, uint8_t Direction);
void     stmpe811_IO_EnableAF(uint16_t DeviceAddr, uint32_t IO_Pin);
void     stmpe811_IO_DisableAF(uint16_t DeviceAddr, uint32_t IO_Pin);
void     stmpe811_IO_SetEdgeMode(uint16_t DeviceAddr, uint32_t IO_Pin, uint8_t Edge);
void     stmpe811_IO_WritePin(uint16_t DeviceAddr, uint32_t IO_Pin, uint8_t PinState);
uint32_t stmpe811_IO_ReadPin(uint16_t DeviceAddr, uint32_t IO_Pin);
void     stmpe811_IO_EnableIT(uint16_t DeviceAddr);
void     stmpe811_IO_DisableIT(uint16_t DeviceAddr);
void     stmpe811_IO_EnablePinIT(uint16_t DeviceAddr, uint32_t IO_Pin);
void     stmpe811_IO_DisablePinIT(uint16_t DeviceAddr, uint32_t IO_Pin);
uint32_t stmpe811_IO_ITStatus(uint16_t DeviceAddr, uint32_t IO_Pin);
void     stmpe811_IO_ClearIT(uint16_t DeviceAddr, uint32_t IO_Pin);



 
void     stmpe811_TS_Start(uint16_t DeviceAddr);
uint8_t  stmpe811_TS_DetectTouch(uint16_t DeviceAddr);
void     stmpe811_TS_GetXY(uint16_t DeviceAddr, uint16_t *X, uint16_t *Y);
void     stmpe811_TS_EnableIT(uint16_t DeviceAddr);
void     stmpe811_TS_DisableIT(uint16_t DeviceAddr);
uint8_t  stmpe811_TS_ITStatus (uint16_t DeviceAddr);
void     stmpe811_TS_ClearIT (uint16_t DeviceAddr);

void     IOE_Init(void);
void     IOE_ITConfig (void);
void     IOE_Delay(uint32_t delay);
void     IOE_Write(uint8_t addr, uint8_t reg, uint8_t value);
uint8_t  IOE_Read(uint8_t addr, uint8_t reg);
uint16_t IOE_ReadMultiple(uint8_t addr, uint8_t reg, uint8_t *buffer, uint16_t length);

 
extern TS_DrvTypeDef stmpe811_ts_drv;

 
extern IO_DrvTypeDef stmpe811_io_drv;




  



 



  



 

 



 



  
  


    



  



  


 



  


  



  

   
TS_DrvTypeDef stmpe811_ts_drv = 
{
  stmpe811_Init,
  stmpe811_ReadID,
  stmpe811_Reset,
  stmpe811_TS_Start,
  stmpe811_TS_DetectTouch,
  stmpe811_TS_GetXY,
  stmpe811_TS_EnableIT,
  stmpe811_TS_ClearIT,
  stmpe811_TS_ITStatus,
  stmpe811_TS_DisableIT,
};

  
IO_DrvTypeDef stmpe811_io_drv = 
{
  stmpe811_Init,
  stmpe811_ReadID,
  stmpe811_Reset,
  stmpe811_IO_Start,
  stmpe811_IO_Config,
  stmpe811_IO_WritePin,
  stmpe811_IO_ReadPin,
  stmpe811_IO_EnableIT,
  stmpe811_IO_DisableIT,
  stmpe811_IO_ITStatus,
  stmpe811_IO_ClearIT,
};

 
uint8_t stmpe811[2] = {0};


  



 
static uint8_t stmpe811_GetInstance(uint16_t DeviceAddr); 


  



 





 
void stmpe811_Init(uint16_t DeviceAddr)
{
  uint8_t instance;
  uint8_t empty;
  
   
  instance = stmpe811_GetInstance(DeviceAddr);
  
   
  if(instance == 0xFF)
  {
     
    empty = stmpe811_GetInstance(0);
    
    if(empty < 2)
    {
       
      stmpe811[empty] = DeviceAddr;
      
       
      IOE_Init(); 
      
       
      stmpe811_Reset(DeviceAddr);
    }
  }
}
 




 
void stmpe811_Reset(uint16_t DeviceAddr)
{
     
  IOE_Write(DeviceAddr, 0x03, 2);

   
  IOE_Delay(10); 
  
   
  IOE_Write(DeviceAddr, 0x03, 0);
  
   
  IOE_Delay(2); 
}





 
uint16_t stmpe811_ReadID(uint16_t DeviceAddr)
{
   
  IOE_Init(); 
  
   
  return ((IOE_Read(DeviceAddr, 0x00) << 8) |          (IOE_Read(DeviceAddr, 0x01)));
}





 
void stmpe811_EnableGlobalIT(uint16_t DeviceAddr)
{
  uint8_t tmp = 0;
  
   
  tmp = IOE_Read(DeviceAddr, 0x09);
  
       
  tmp |= (uint8_t)0x01;
  
   
  IOE_Write(DeviceAddr, 0x09, tmp); 
}





 
void stmpe811_DisableGlobalIT(uint16_t DeviceAddr)
{
  uint8_t tmp = 0;
  
   
  tmp = IOE_Read(DeviceAddr, 0x09);

       
  tmp &= ~(uint8_t)0x01;
 
   
  IOE_Write(DeviceAddr, 0x09, tmp);
    
}













 
void stmpe811_EnableITSource(uint16_t DeviceAddr, uint8_t Source)
{
  uint8_t tmp = 0;
  
   
  tmp = IOE_Read(DeviceAddr, 0x0A);

       
  tmp |= Source; 
  
   
  IOE_Write(DeviceAddr, 0x0A, tmp);   
}













 
void stmpe811_DisableITSource(uint16_t DeviceAddr, uint8_t Source)
{
  uint8_t tmp = 0;
  
   
  tmp = IOE_Read(DeviceAddr, 0x0A);

       
  tmp &= ~Source; 
  
   
  IOE_Write(DeviceAddr, 0x0A, tmp);   
}








 
void stmpe811_SetITPolarity(uint16_t DeviceAddr, uint8_t Polarity)
{
  uint8_t tmp = 0;
  
    
  tmp = IOE_Read(DeviceAddr, 0x09);
  
   
  tmp &= ~(uint8_t)0x04;
    
   
  tmp |= Polarity;
  
   
  IOE_Write(DeviceAddr, 0x09, tmp);
 
}








 
void stmpe811_SetITType(uint16_t DeviceAddr, uint8_t Type)
{
  uint8_t tmp = 0;
  
    
  tmp = IOE_Read(DeviceAddr, 0x09);
  
   
  tmp &= ~(uint8_t)0x02;
    
   
  tmp |= Type;
  
   
  IOE_Write(DeviceAddr, 0x09, tmp);
 
}













 
uint8_t stmpe811_GlobalITStatus(uint16_t DeviceAddr, uint8_t Source)
{
   
  return((IOE_Read(DeviceAddr, 0x0B) & Source) == Source);
}













 
uint8_t stmpe811_ReadGITStatus(uint16_t DeviceAddr, uint8_t Source)
{
   
  return((IOE_Read(DeviceAddr, 0x0B) & Source));
}














 
void stmpe811_ClearGlobalIT(uint16_t DeviceAddr, uint8_t Source)
{
   
  IOE_Write(DeviceAddr, 0x0B, Source);
}








 
void stmpe811_IO_Start(uint16_t DeviceAddr, uint32_t IO_Pin)
{
  uint8_t mode;
  
   
  mode = IOE_Read(DeviceAddr, 0x04);
  
       
  mode &= ~(0x04 | 0x01);  
  
     
  IOE_Write(DeviceAddr, 0x04, mode); 

   
  stmpe811_IO_DisableAF(DeviceAddr, (uint8_t)IO_Pin);
}















 
uint8_t stmpe811_IO_Config(uint16_t DeviceAddr, uint32_t IO_Pin, IO_ModeTypedef IO_Mode)
{
  uint8_t error_code = 0;

   
  switch(IO_Mode)
  {
  case IO_MODE_INPUT:  
    stmpe811_IO_InitPin(DeviceAddr, IO_Pin, 0x00);
    break;
    
  case IO_MODE_OUTPUT:  
    stmpe811_IO_InitPin(DeviceAddr, IO_Pin, 0x01);
    break;
  
  case IO_MODE_IT_RISING_EDGE:  
    stmpe811_IO_EnableIT(DeviceAddr);
    stmpe811_IO_EnablePinIT(DeviceAddr, IO_Pin);
    stmpe811_IO_InitPin(DeviceAddr, IO_Pin, 0x00); 
    stmpe811_SetITType(DeviceAddr, 0x02);      
    stmpe811_IO_SetEdgeMode(DeviceAddr, IO_Pin, 0x02); 
    break;
  
  case IO_MODE_IT_FALLING_EDGE:  
    stmpe811_IO_EnableIT(DeviceAddr);
    stmpe811_IO_EnablePinIT(DeviceAddr, IO_Pin);
    stmpe811_IO_InitPin(DeviceAddr, IO_Pin, 0x00); 
    stmpe811_SetITType(DeviceAddr, 0x02);    
    stmpe811_IO_SetEdgeMode(DeviceAddr, IO_Pin, 0x01); 
    break;
  
  case IO_MODE_IT_LOW_LEVEL:  
    stmpe811_IO_EnableIT(DeviceAddr);
    stmpe811_IO_EnablePinIT(DeviceAddr, IO_Pin);
    stmpe811_IO_InitPin(DeviceAddr, IO_Pin, 0x00); 
    stmpe811_SetITType(DeviceAddr, 0x00);
    stmpe811_SetITPolarity(DeviceAddr, 0x00);      
    break;
    
  case IO_MODE_IT_HIGH_LEVEL:  
    stmpe811_IO_EnableIT(DeviceAddr);
    stmpe811_IO_EnablePinIT(DeviceAddr, IO_Pin);
    stmpe811_IO_InitPin(DeviceAddr, IO_Pin, 0x00); 
    stmpe811_SetITType(DeviceAddr, 0x00);
    stmpe811_SetITPolarity(DeviceAddr, 0x04);  
    break;    

  default:
    error_code = (uint8_t) IO_Mode;
    break;
  } 
  return error_code;
}









 
void stmpe811_IO_InitPin(uint16_t DeviceAddr, uint32_t IO_Pin, uint8_t Direction)
{
  uint8_t tmp = 0;   
  
   
  tmp = IOE_Read(DeviceAddr, 0x13);
  
   
  if (Direction != 0x00)
  {
    tmp |= (uint8_t)IO_Pin;
  }  
  else 
  {
    tmp &= ~(uint8_t)IO_Pin;
  }
  
   
  IOE_Write(DeviceAddr, 0x13, tmp);   
}








 
void stmpe811_IO_DisableAF(uint16_t DeviceAddr, uint32_t IO_Pin)
{
  uint8_t tmp = 0;
  
   
  tmp = IOE_Read(DeviceAddr, 0x17);

   
  tmp |= (uint8_t)IO_Pin;

   
  IOE_Write(DeviceAddr, 0x17, tmp);
  
}








 
void stmpe811_IO_EnableAF(uint16_t DeviceAddr, uint32_t IO_Pin)
{
  uint8_t tmp = 0;
  
   
  tmp = IOE_Read(DeviceAddr, 0x17);

      
  tmp &= ~(uint8_t)IO_Pin;   
  
   
  IOE_Write(DeviceAddr, 0x17, tmp); 
}











 
void stmpe811_IO_SetEdgeMode(uint16_t DeviceAddr, uint32_t IO_Pin, uint8_t Edge)
{
  uint8_t tmp1 = 0, tmp2 = 0;   
  
   
  tmp1 = IOE_Read(DeviceAddr, 0x16);
  tmp2 = IOE_Read(DeviceAddr, 0x15);

   
  tmp1 &= ~(uint8_t)IO_Pin;
  
   
  tmp2 &= ~(uint8_t)IO_Pin;

   
  if (Edge & 0x01)
  {
    tmp1 |= (uint8_t)IO_Pin;
  }

   
  if (Edge & 0x02)
  {
    tmp2 |= (uint8_t)IO_Pin;
  }

   
  IOE_Write(DeviceAddr, 0x16, tmp1);
  IOE_Write(DeviceAddr, 0x15, tmp2);
}









 
void stmpe811_IO_WritePin(uint16_t DeviceAddr, uint32_t IO_Pin, uint8_t PinState)
{
   
  if (PinState != 0)
  {
     
    IOE_Write(DeviceAddr, 0x10, (uint8_t)IO_Pin);
  }
  else
  {
     
    IOE_Write(DeviceAddr, 0x11, (uint8_t)IO_Pin);
  } 
}








 
uint32_t stmpe811_IO_ReadPin(uint16_t DeviceAddr, uint32_t IO_Pin)
{
  return((uint32_t)(IOE_Read(DeviceAddr, 0x12) & (uint8_t)IO_Pin));
}





 
void stmpe811_IO_EnableIT(uint16_t DeviceAddr)
{ 
  IOE_ITConfig();
  
   
  stmpe811_EnableITSource(DeviceAddr, 0x80);
  
   
  stmpe811_EnableGlobalIT(DeviceAddr); 
}





 
void stmpe811_IO_DisableIT(uint16_t DeviceAddr)
{
   
  stmpe811_DisableGlobalIT(DeviceAddr);
  
   
  stmpe811_DisableITSource(DeviceAddr, 0x80);    
}








 
void stmpe811_IO_EnablePinIT(uint16_t DeviceAddr, uint32_t IO_Pin)
{
  uint8_t tmp = 0;
  
   
  tmp = IOE_Read(DeviceAddr, 0x0C);
  
       
  tmp |= (uint8_t)IO_Pin;
  
   
  IOE_Write(DeviceAddr, 0x0C, tmp);  
}








 
void stmpe811_IO_DisablePinIT(uint16_t DeviceAddr, uint32_t IO_Pin)
{
  uint8_t tmp = 0;
  
   
  tmp = IOE_Read(DeviceAddr, 0x0C);
  
       
  tmp &= ~(uint8_t)IO_Pin;
  
   
  IOE_Write(DeviceAddr, 0x0C, tmp);   
}







 
uint32_t stmpe811_IO_ITStatus(uint16_t DeviceAddr, uint32_t IO_Pin)
{
   
  return(IOE_Read(DeviceAddr, 0x0D) & (uint8_t)IO_Pin); 
}







 
void stmpe811_IO_ClearIT(uint16_t DeviceAddr, uint32_t IO_Pin)
{
   
  stmpe811_ClearGlobalIT(DeviceAddr, 0x80);
  
   
  IOE_Write(DeviceAddr, 0x0D, (uint8_t)IO_Pin);  
  
   
  IOE_Write(DeviceAddr, 0x14, (uint8_t)IO_Pin);
  
   
  IOE_Write(DeviceAddr, 0x15, (uint8_t)IO_Pin);
  
   
  IOE_Write(DeviceAddr, 0x16, (uint8_t)IO_Pin); 
}





 
void stmpe811_TS_Start(uint16_t DeviceAddr)
{
  uint8_t mode;
  
   
  mode = IOE_Read(DeviceAddr, 0x04);
  
       
  mode &= ~(0x04);  
  
     
  IOE_Write(DeviceAddr, 0x04, mode); 

     
  stmpe811_IO_EnableAF(DeviceAddr, (uint32_t)(0x80 | 0x40 | 0x20 | 0x10));
  
       
  mode &= ~(0x02 | 0x01);  
  
     
  IOE_Write(DeviceAddr, 0x04, mode); 
  
   
  IOE_Write(DeviceAddr, 0x20, 0x49);
  
   
  IOE_Delay(2); 
  
   
  IOE_Write(DeviceAddr, 0x21, 0x01);
  
   
  



 
  IOE_Write(DeviceAddr, 0x41, 0x9A); 
  
   
  IOE_Write(DeviceAddr, 0x4A, 0x01);
  
   
  IOE_Write(DeviceAddr, 0x4B, 0x01);
  
   
  IOE_Write(DeviceAddr, 0x4B, 0x00);
  
  


 
  IOE_Write(DeviceAddr, 0x56, 0x01);
  
   
  IOE_Write(DeviceAddr, 0x58, 0x01);
  
  


 
  IOE_Write(DeviceAddr, 0x40, 0x01);
  
   
  IOE_Write(DeviceAddr, 0x0B, 0xFF);

   
  IOE_Delay(2); 
}





 
uint8_t stmpe811_TS_DetectTouch(uint16_t DeviceAddr)
{
  uint8_t state;
  uint8_t ret = 0;
  
  state = ((IOE_Read(DeviceAddr, 0x40) & (uint8_t)0x80) == (uint8_t)0x80);
  
  if(state > 0)
  {
    if(IOE_Read(DeviceAddr, 0x4C) > 0)
    {
      ret = 1;
    }
  }
  else
  {
     
    IOE_Write(DeviceAddr, 0x4B, 0x01);
     
    IOE_Write(DeviceAddr, 0x4B, 0x00);
  }
  
  return ret;
}







 
void stmpe811_TS_GetXY(uint16_t DeviceAddr, uint16_t *X, uint16_t *Y)
{
  uint8_t  dataXYZ[4];
  uint32_t uldataXYZ;
  
  IOE_ReadMultiple(DeviceAddr, 0xD7, dataXYZ, sizeof(dataXYZ)) ;
  
   
  uldataXYZ = (dataXYZ[0] << 24)|(dataXYZ[1] << 16)|(dataXYZ[2] << 8)|(dataXYZ[3] << 0);     
  *X = (uldataXYZ >> 20) & 0x00000FFF;     
  *Y = (uldataXYZ >>  8) & 0x00000FFF;     
  
   
  IOE_Write(DeviceAddr, 0x4B, 0x01);
   
  IOE_Write(DeviceAddr, 0x4B, 0x00);
}





 
void stmpe811_TS_EnableIT(uint16_t DeviceAddr)
{
  IOE_ITConfig();
  
   
  stmpe811_EnableITSource(DeviceAddr, (0x01 | 0x02 | 0x04 | 0x08 | 0x10)); 
  
   
  stmpe811_EnableGlobalIT(DeviceAddr);
}





 
void stmpe811_TS_DisableIT(uint16_t DeviceAddr)
{
   
  stmpe811_DisableGlobalIT(DeviceAddr);
  
   
  stmpe811_DisableITSource(DeviceAddr, (0x01 | 0x02 | 0x04 | 0x08 | 0x10)); 
}





 
uint8_t stmpe811_TS_ITStatus(uint16_t DeviceAddr)
{
   
  return(stmpe811_ReadGITStatus(DeviceAddr, (0x01 | 0x02 | 0x04 | 0x08 | 0x10)));
}





 
void stmpe811_TS_ClearIT(uint16_t DeviceAddr)
{
   
  stmpe811_ClearGlobalIT(DeviceAddr, (0x01 | 0x02 | 0x04 | 0x08 | 0x10));
}






 
static uint8_t stmpe811_GetInstance(uint16_t DeviceAddr)
{
  uint8_t idx = 0;
  
   
  for(idx = 0; idx < 2 ; idx ++)
  {
    if(stmpe811[idx] == DeviceAddr)
    {
      return idx; 
    }
  }
  
  return 0xFF;
}



  



  



  



  

 
