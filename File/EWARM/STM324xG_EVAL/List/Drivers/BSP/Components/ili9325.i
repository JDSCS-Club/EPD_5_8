


































  

 




































  

 


 



































  

 


 
 
 

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
  void     (*Init)(void);
  uint16_t (*ReadID)(void);
  void     (*DisplayOn)(void);
  void     (*DisplayOff)(void);
  void     (*SetCursor)(uint16_t, uint16_t);
  void     (*WritePixel)(uint16_t, uint16_t, uint16_t);
  uint16_t (*ReadPixel)(uint16_t, uint16_t);
  
    
  void     (*SetDisplayWindow)(uint16_t, uint16_t, uint16_t, uint16_t);
  void     (*DrawHLine)(uint16_t, uint16_t, uint16_t, uint16_t);
  void     (*DrawVLine)(uint16_t, uint16_t, uint16_t, uint16_t);
  
  uint16_t (*GetLcdPixelWidth)(void);
  uint16_t (*GetLcdPixelHeight)(void);
  void     (*DrawBitmap)(uint16_t, uint16_t, uint8_t*);
  void     (*DrawRGBImage)(uint16_t, uint16_t, uint16_t, uint16_t, uint8_t*);
}LCD_DrvTypeDef;    


 



 



 



 



 



 



  



  
  


 



 
   


  



 


   
   


   
   


  


 
  


  
void     ili9325_Init(void);
uint16_t ili9325_ReadID(void);
void     ili9325_WriteReg(uint8_t LCDReg, uint16_t LCDRegValue);
uint16_t ili9325_ReadReg(uint8_t LCDReg);

void     ili9325_DisplayOn(void);
void     ili9325_DisplayOff(void);
void     ili9325_SetCursor(uint16_t Xpos, uint16_t Ypos);
void     ili9325_WritePixel(uint16_t Xpos, uint16_t Ypos, uint16_t RGBCode);
uint16_t ili9325_ReadPixel(uint16_t Xpos, uint16_t Ypos);

void     ili9325_DrawHLine(uint16_t RGBCode, uint16_t Xpos, uint16_t Ypos, uint16_t Length);
void     ili9325_DrawVLine(uint16_t RGBCode, uint16_t Xpos, uint16_t Ypos, uint16_t Length);
void     ili9325_DrawBitmap(uint16_t Xpos, uint16_t Ypos, uint8_t *pbmp);
void     ili9325_DrawRGBImage(uint16_t Xpos, uint16_t Ypos, uint16_t Xsize, uint16_t Ysize, uint8_t *pdata);

void     ili9325_SetDisplayWindow(uint16_t Xpos, uint16_t Ypos, uint16_t Width, uint16_t Height);


uint16_t ili9325_GetLcdPixelWidth(void);
uint16_t ili9325_GetLcdPixelHeight(void);

 
extern LCD_DrvTypeDef   ili9325_drv;

 
void     LCD_IO_Init(void);
void     LCD_IO_WriteMultipleData(uint8_t *pData, uint32_t Size);
void     LCD_IO_WriteReg(uint8_t Reg);
uint16_t LCD_IO_ReadData(uint16_t Reg);



  
      




  



  



 
  
 



  



  
  




 



  



  



 



  
  


 
     


   



  
LCD_DrvTypeDef   ili9325_drv = 
{
  ili9325_Init,
  ili9325_ReadID,
  ili9325_DisplayOn,
  ili9325_DisplayOff,
  ili9325_SetCursor,
  ili9325_WritePixel,
  ili9325_ReadPixel,
  ili9325_SetDisplayWindow,
  ili9325_DrawHLine,
  ili9325_DrawVLine,
  ili9325_GetLcdPixelWidth,
  ili9325_GetLcdPixelHeight,
  ili9325_DrawBitmap,
  ili9325_DrawRGBImage,  
};

static uint16_t ArrayRGB[320] = {0};


  
  


 



  
  


    





 
void ili9325_Init(void)
{  
   
  LCD_IO_Init();
  
   
  ili9325_WriteReg(0x00, 0x0001);  
  ili9325_WriteReg(0x01, 0x0100);  
  ili9325_WriteReg(0x02, 0x0700);  
  ili9325_WriteReg(0x03, 0x1018);  
  ili9325_WriteReg(0x04, 0x0000);  
  ili9325_WriteReg(0x08, 0x0202);  
  ili9325_WriteReg(0x09, 0x0000);  
  ili9325_WriteReg(0x0A, 0x0000);  
  ili9325_WriteReg(0x0C, 0x0000);  
  ili9325_WriteReg(0x0D, 0x0000);  
  ili9325_WriteReg(0x0F, 0x0000);  
  
   
  ili9325_WriteReg(0x10, 0x0000);  
  ili9325_WriteReg(0x11, 0x0000);  
  ili9325_WriteReg(0x12, 0x0000);  
  ili9325_WriteReg(0x13, 0x0000);  
  
  ili9325_WriteReg(0x10, 0x17B0);  
  ili9325_WriteReg(0x11, 0x0137);  
  
  ili9325_WriteReg(0x12, 0x0139);  
  
  ili9325_WriteReg(0x13, 0x1d00);  
  ili9325_WriteReg(0x29, 0x0013);  
  
  ili9325_WriteReg(0x20, 0x0000);  
  ili9325_WriteReg(0x21, 0x0000);  
  
   
  ili9325_WriteReg(0x30, 0x0007);
  ili9325_WriteReg(0x31, 0x0302);
  ili9325_WriteReg(0x32, 0x0105);
  ili9325_WriteReg(0x35, 0x0206);
  ili9325_WriteReg(0x36, 0x0808);
  ili9325_WriteReg(0x37, 0x0206);
  ili9325_WriteReg(0x38, 0x0504);
  ili9325_WriteReg(0x39, 0x0007);
  ili9325_WriteReg(0x3C, 0x0105);
  ili9325_WriteReg(0x3D, 0x0808);
  
   
  ili9325_WriteReg(0x50, 0x0000);  
  ili9325_WriteReg(0x51, 0x00EF);  
  ili9325_WriteReg(0x52, 0x0000);  
  ili9325_WriteReg(0x53, 0x013F);  
  
  ili9325_WriteReg(0x60,  0xA700);  
  ili9325_WriteReg(0x61,  0x0001);  
  ili9325_WriteReg(0x6A, 0x0000);  
  
   
  ili9325_WriteReg(0x80, 0x0000);
  ili9325_WriteReg(0x81, 0x0000);
  ili9325_WriteReg(0x82, 0x0000);
  ili9325_WriteReg(0x83, 0x0000);
  ili9325_WriteReg(0x84, 0x0000);
  ili9325_WriteReg(0x85, 0x0000);
  
   
  ili9325_WriteReg(0x90, 0x0010);
  ili9325_WriteReg(0x92, 0x0000);
  ili9325_WriteReg(0x93, 0x0003);
  ili9325_WriteReg(0x95, 0x0110);
  ili9325_WriteReg(0x97, 0x0000);
  ili9325_WriteReg(0x98, 0x0000);
  
   
   
   
  ili9325_WriteReg(0x03, 0x1018);
  
    
  ili9325_WriteReg(0x07, 0x0173);    
  
    
  ili9325_SetCursor(0, 0);
  
   
  LCD_IO_WriteReg(0x22);
}





 
void ili9325_DisplayOn(void)
{
   
  ili9325_WriteReg(0x10, 0x0000);  
  ili9325_WriteReg(0x11, 0x0000);  
  ili9325_WriteReg(0x12, 0x0000);  
  ili9325_WriteReg(0x13, 0x0000);  

  ili9325_WriteReg(0x10, 0x17B0);  
  ili9325_WriteReg(0x11, 0x0137);  

  ili9325_WriteReg(0x12, 0x0139);  

  ili9325_WriteReg(0x13, 0x1d00);  
  ili9325_WriteReg(0x29, 0x0013);  
 
   
  ili9325_WriteReg(0x07, 0x0173);  
}





 
void ili9325_DisplayOff(void)
{
   
  ili9325_WriteReg(0x10, 0x0000);  
  ili9325_WriteReg(0x11, 0x0000);  
  ili9325_WriteReg(0x12, 0x0000);  
  ili9325_WriteReg(0x13, 0x0000);  
  
  ili9325_WriteReg(0x29, 0x0000);  
  
   
  ili9325_WriteReg(0x07, 0x0); 
}





 
uint16_t ili9325_GetLcdPixelWidth(void)
{
 return (uint16_t)320;
}





 
uint16_t ili9325_GetLcdPixelHeight(void)
{
 return (uint16_t)240;
}





 
uint16_t ili9325_ReadID(void)
{
  LCD_IO_Init(); 
  return (ili9325_ReadReg(0x00));
}






 
void ili9325_SetCursor(uint16_t Xpos, uint16_t Ypos)
{
  ili9325_WriteReg(0x20, Ypos);
  ili9325_WriteReg(0x21, (((uint16_t)320) - 1 - Xpos));      
}







 
void ili9325_WritePixel(uint16_t Xpos, uint16_t Ypos, uint16_t RGBCode)
{
   
  ili9325_SetCursor(Xpos, Ypos);
  
   
  LCD_IO_WriteReg(0x22);

   
  LCD_IO_WriteMultipleData((uint8_t*)&RGBCode, 2);
}





 
uint16_t ili9325_ReadPixel(uint16_t Xpos, uint16_t Ypos)
{
   
  ili9325_SetCursor(Xpos, Ypos);
  
   
  return (LCD_IO_ReadData(0x22));
}






 
void ili9325_WriteReg(uint8_t LCDReg, uint16_t LCDRegValue)
{
  LCD_IO_WriteReg(LCDReg);
  
   
  LCD_IO_WriteMultipleData((uint8_t*)&LCDRegValue, 2);
}





 
uint16_t ili9325_ReadReg(uint8_t LCDReg)
{ 
   
  return (LCD_IO_ReadData(LCDReg));
}








 
void ili9325_SetDisplayWindow(uint16_t Xpos, uint16_t Ypos, uint16_t Width, uint16_t Height)
{
   
  ili9325_WriteReg(0x50, (Ypos));
   
  ili9325_WriteReg(0x51, (Ypos + Height - 1));
  
   
  ili9325_WriteReg(0x52, ((uint16_t)320) - Xpos - Width);
   
  ili9325_WriteReg(0x53, ((uint16_t)320) - Xpos - 1);  
}








 
void ili9325_DrawHLine(uint16_t RGBCode, uint16_t Xpos, uint16_t Ypos, uint16_t Length)
{
  uint16_t counter = 0;
  
   
  ili9325_SetCursor(Xpos, Ypos); 
  
   
  LCD_IO_WriteReg(0x22);

   
  for(counter = 0; counter < Length; counter++)
  {
    ArrayRGB[counter] = RGBCode;
  }  

  LCD_IO_WriteMultipleData((uint8_t*)&ArrayRGB[0], Length * 2);
}








 
void ili9325_DrawVLine(uint16_t RGBCode, uint16_t Xpos, uint16_t Ypos, uint16_t Length)
{
  uint16_t counter = 0;

   
   
   
  ili9325_WriteReg(0x03, 0x1010);
  
   
  ili9325_SetCursor(Xpos, Ypos);
  
   
  LCD_IO_WriteReg(0x22);

   
  for(counter = 0; counter < Length; counter++)
  {
    ArrayRGB[counter] = RGBCode;
  }
  
   
  LCD_IO_WriteMultipleData((uint8_t*)&ArrayRGB[0], Length * 2);
  
   
   
   
  ili9325_WriteReg(0x03, 0x1018);  
}







 
void ili9325_DrawBitmap(uint16_t Xpos, uint16_t Ypos, uint8_t *pbmp)
{
  uint32_t index = 0, size = 0;
   
  size = *(volatile uint16_t *) (pbmp + 2);
  size |= (*(volatile uint16_t *) (pbmp + 4)) << 16;
   
  index = *(volatile uint16_t *) (pbmp + 10);
  index |= (*(volatile uint16_t *) (pbmp + 12)) << 16;
  size = (size - index)/2;
  pbmp += index;
   
   
   
  ili9325_WriteReg(0x03, 0x1008);

   
  ili9325_SetCursor(Xpos, Ypos);  
  
   
  LCD_IO_WriteReg(0x22);
 
  LCD_IO_WriteMultipleData((uint8_t*)pbmp, size*2);
 
   
   
   
  ili9325_WriteReg(0x03, 0x1018);
}









 
void ili9325_DrawRGBImage(uint16_t Xpos, uint16_t Ypos, uint16_t Xsize, uint16_t Ysize, uint8_t *pdata)
{
  uint32_t size = 0;

  size = (Xsize * Ysize);

   
  ili9325_SetCursor(Xpos, Ypos);  
  
   
  LCD_IO_WriteReg(0x22);
 
  LCD_IO_WriteMultipleData((uint8_t*)pdata, size*2);
}



  



  
  


  



 
  
 
