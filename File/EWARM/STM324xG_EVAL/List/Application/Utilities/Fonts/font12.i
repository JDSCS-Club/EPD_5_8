


































 

 



































 

 

 


 
 
 

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

 






















 











 


typedef struct _tFont
{    
  const uint8_t *table;
  uint16_t Width;
  uint16_t Height;
  
} sFONT;



typedef struct                                          
{
  unsigned char index[2];                               
  const char matrix[41*32/8];  
}CH_CN;


typedef struct
{    
  const CH_CN *table;
  uint16_t size;
  uint16_t ASCII_Width;
  uint16_t Width;
  uint16_t Height;
  
}cFONT;

extern sFONT Font24;
extern sFONT Font20;
extern sFONT Font16;
extern sFONT Font12;
extern sFONT Font8;

extern cFONT Font12CN;
extern cFONT Font24CN;
  
 

 





const uint8_t Font12_Table[] = 
{
	
	0x00, 
	0x00, 
	0x00, 
	0x00, 
	0x00, 
	0x00, 
	0x00, 
	0x00, 
	0x00, 
	0x00, 
	0x00, 
	0x00, 

	
	0x00, 
	0x10, 
	0x10, 
	0x10, 
	0x10, 
	0x10, 
	0x00, 
	0x00, 
	0x10, 
	0x00, 
	0x00, 
	0x00, 

	
	0x00, 
	0x6C, 
	0x48, 
	0x48, 
	0x00, 
	0x00, 
	0x00, 
	0x00, 
	0x00, 
	0x00, 
	0x00, 
	0x00, 

	
	0x00, 
	0x14, 
	0x14, 
	0x28, 
	0x7C, 
	0x28, 
	0x7C, 
	0x28, 
	0x50, 
	0x50, 
	0x00, 
	0x00, 

	
	0x00, 
	0x10, 
	0x38, 
	0x40, 
	0x40, 
	0x38, 
	0x48, 
	0x70, 
	0x10, 
	0x10, 
	0x00, 
	0x00, 

	
	0x00, 
	0x20, 
	0x50, 
	0x20, 
	0x0C, 
	0x70, 
	0x08, 
	0x14, 
	0x08, 
	0x00, 
	0x00, 
	0x00, 

	
	0x00, 
	0x00, 
	0x00, 
	0x18, 
	0x20, 
	0x20, 
	0x54, 
	0x48, 
	0x34, 
	0x00, 
	0x00, 
	0x00, 

	
	0x00, 
	0x10, 
	0x10, 
	0x10, 
	0x10, 
	0x00, 
	0x00, 
	0x00, 
	0x00, 
	0x00, 
	0x00, 
	0x00, 

	
	0x00, 
	0x08, 
	0x08, 
	0x10, 
	0x10, 
	0x10, 
	0x10, 
	0x10, 
	0x10, 
	0x08, 
	0x08, 
	0x00, 

	
	0x00, 
	0x20, 
	0x20, 
	0x10, 
	0x10, 
	0x10, 
	0x10, 
	0x10, 
	0x10, 
	0x20, 
	0x20, 
	0x00, 

	
	0x00, 
	0x10, 
	0x7C, 
	0x10, 
	0x28, 
	0x28, 
	0x00, 
	0x00, 
	0x00, 
	0x00, 
	0x00, 
	0x00, 

	
	0x00, 
	0x00, 
	0x10, 
	0x10, 
	0x10, 
	0xFE, 
	0x10, 
	0x10, 
	0x10, 
	0x00, 
	0x00, 
	0x00, 

	
	0x00, 
	0x00, 
	0x00, 
	0x00, 
	0x00, 
	0x00, 
	0x00, 
	0x18, 
	0x10, 
	0x30, 
	0x20, 
	0x00, 

	
	0x00, 
	0x00, 
	0x00, 
	0x00, 
	0x00, 
	0x7C, 
	0x00, 
	0x00, 
	0x00, 
	0x00, 
	0x00, 
	0x00, 

	
	0x00, 
	0x00, 
	0x00, 
	0x00, 
	0x00, 
	0x00, 
	0x00, 
	0x30, 
	0x30, 
	0x00, 
	0x00, 
	0x00, 

	
	0x00, 
	0x04, 
	0x04, 
	0x08, 
	0x08, 
	0x10, 
	0x10, 
	0x20, 
	0x20, 
	0x40, 
	0x00, 
	0x00, 

	
	0x00, 
	0x38, 
	0x44, 
	0x44, 
	0x44, 
	0x44, 
	0x44, 
	0x44, 
	0x38, 
	0x00, 
	0x00, 
	0x00, 

	
	0x00, 
	0x30, 
	0x10, 
	0x10, 
	0x10, 
	0x10, 
	0x10, 
	0x10, 
	0x7C, 
	0x00, 
	0x00, 
	0x00, 

	
	0x00, 
	0x38, 
	0x44, 
	0x04, 
	0x08, 
	0x10, 
	0x20, 
	0x44, 
	0x7C, 
	0x00, 
	0x00, 
	0x00, 

	
	0x00, 
	0x38, 
	0x44, 
	0x04, 
	0x18, 
	0x04, 
	0x04, 
	0x44, 
	0x38, 
	0x00, 
	0x00, 
	0x00, 

	
	0x00, 
	0x0C, 
	0x14, 
	0x14, 
	0x24, 
	0x44, 
	0x7E, 
	0x04, 
	0x0E, 
	0x00, 
	0x00, 
	0x00, 

	
	0x00, 
	0x3C, 
	0x20, 
	0x20, 
	0x38, 
	0x04, 
	0x04, 
	0x44, 
	0x38, 
	0x00, 
	0x00, 
	0x00, 

	
	0x00, 
	0x1C, 
	0x20, 
	0x40, 
	0x78, 
	0x44, 
	0x44, 
	0x44, 
	0x38, 
	0x00, 
	0x00, 
	0x00, 

	
	0x00, 
	0x7C, 
	0x44, 
	0x04, 
	0x08, 
	0x08, 
	0x08, 
	0x10, 
	0x10, 
	0x00, 
	0x00, 
	0x00, 

	
	0x00, 
	0x38, 
	0x44, 
	0x44, 
	0x38, 
	0x44, 
	0x44, 
	0x44, 
	0x38, 
	0x00, 
	0x00, 
	0x00, 

	
	0x00, 
	0x38, 
	0x44, 
	0x44, 
	0x44, 
	0x3C, 
	0x04, 
	0x08, 
	0x70, 
	0x00, 
	0x00, 
	0x00, 

	
	0x00, 
	0x00, 
	0x00, 
	0x30, 
	0x30, 
	0x00, 
	0x00, 
	0x30, 
	0x30, 
	0x00, 
	0x00, 
	0x00, 

	
	0x00, 
	0x00, 
	0x00, 
	0x18, 
	0x18, 
	0x00, 
	0x00, 
	0x18, 
	0x30, 
	0x20, 
	0x00, 
	0x00, 

	
	0x00, 
	0x00, 
	0x0C, 
	0x10, 
	0x60, 
	0x80, 
	0x60, 
	0x10, 
	0x0C, 
	0x00, 
	0x00, 
	0x00, 

	
	0x00, 
	0x00, 
	0x00, 
	0x00, 
	0x7C, 
	0x00, 
	0x7C, 
	0x00, 
	0x00, 
	0x00, 
	0x00, 
	0x00, 

	
	0x00, 
	0x00, 
	0xC0, 
	0x20, 
	0x18, 
	0x04, 
	0x18, 
	0x20, 
	0xC0, 
	0x00, 
	0x00, 
	0x00, 

	
	0x00, 
	0x00, 
	0x18, 
	0x24, 
	0x04, 
	0x08, 
	0x10, 
	0x00, 
	0x30, 
	0x00, 
	0x00, 
	0x00, 

	
	0x38, 
	0x44, 
	0x44, 
	0x4C, 
	0x54, 
	0x54, 
	0x4C, 
	0x40, 
	0x44, 
	0x38, 
	0x00, 
	0x00, 

	
	0x00, 
	0x30, 
	0x10, 
	0x28, 
	0x28, 
	0x28, 
	0x7C, 
	0x44, 
	0xEE, 
	0x00, 
	0x00, 
	0x00, 

	
	0x00, 
	0xF8, 
	0x44, 
	0x44, 
	0x78, 
	0x44, 
	0x44, 
	0x44, 
	0xF8, 
	0x00, 
	0x00, 
	0x00, 

	
	0x00, 
	0x3C, 
	0x44, 
	0x40, 
	0x40, 
	0x40, 
	0x40, 
	0x44, 
	0x38, 
	0x00, 
	0x00, 
	0x00, 

	
	0x00, 
	0xF0, 
	0x48, 
	0x44, 
	0x44, 
	0x44, 
	0x44, 
	0x48, 
	0xF0, 
	0x00, 
	0x00, 
	0x00, 

	
	0x00, 
	0xFC, 
	0x44, 
	0x50, 
	0x70, 
	0x50, 
	0x40, 
	0x44, 
	0xFC, 
	0x00, 
	0x00, 
	0x00, 

	
	0x00, 
	0x7E, 
	0x22, 
	0x28, 
	0x38, 
	0x28, 
	0x20, 
	0x20, 
	0x70, 
	0x00, 
	0x00, 
	0x00, 

	
	0x00, 
	0x3C, 
	0x44, 
	0x40, 
	0x40, 
	0x4E, 
	0x44, 
	0x44, 
	0x38, 
	0x00, 
	0x00, 
	0x00, 

	
	0x00, 
	0xEE, 
	0x44, 
	0x44, 
	0x7C, 
	0x44, 
	0x44, 
	0x44, 
	0xEE, 
	0x00, 
	0x00, 
	0x00, 

	
	0x00, 
	0x7C, 
	0x10, 
	0x10, 
	0x10, 
	0x10, 
	0x10, 
	0x10, 
	0x7C, 
	0x00, 
	0x00, 
	0x00, 

	
	0x00, 
	0x3C, 
	0x08, 
	0x08, 
	0x08, 
	0x48, 
	0x48, 
	0x48, 
	0x30, 
	0x00, 
	0x00, 
	0x00, 

	
	0x00, 
	0xEE, 
	0x44, 
	0x48, 
	0x50, 
	0x70, 
	0x48, 
	0x44, 
	0xE6, 
	0x00, 
	0x00, 
	0x00, 

	
	0x00, 
	0x70, 
	0x20, 
	0x20, 
	0x20, 
	0x20, 
	0x24, 
	0x24, 
	0x7C, 
	0x00, 
	0x00, 
	0x00, 

	
	0x00, 
	0xEE, 
	0x6C, 
	0x6C, 
	0x54, 
	0x54, 
	0x44, 
	0x44, 
	0xEE, 
	0x00, 
	0x00, 
	0x00, 

	
	0x00, 
	0xEE, 
	0x64, 
	0x64, 
	0x54, 
	0x54, 
	0x54, 
	0x4C, 
	0xEC, 
	0x00, 
	0x00, 
	0x00, 

	
	0x00, 
	0x38, 
	0x44, 
	0x44, 
	0x44, 
	0x44, 
	0x44, 
	0x44, 
	0x38, 
	0x00, 
	0x00, 
	0x00, 

	
	0x00, 
	0x78, 
	0x24, 
	0x24, 
	0x24, 
	0x38, 
	0x20, 
	0x20, 
	0x70, 
	0x00, 
	0x00, 
	0x00, 

	
	0x00, 
	0x38, 
	0x44, 
	0x44, 
	0x44, 
	0x44, 
	0x44, 
	0x44, 
	0x38, 
	0x1C, 
	0x00, 
	0x00, 

	
	0x00, 
	0xF8, 
	0x44, 
	0x44, 
	0x44, 
	0x78, 
	0x48, 
	0x44, 
	0xE2, 
	0x00, 
	0x00, 
	0x00, 

	
	0x00, 
	0x34, 
	0x4C, 
	0x40, 
	0x38, 
	0x04, 
	0x04, 
	0x64, 
	0x58, 
	0x00, 
	0x00, 
	0x00, 

	
	0x00, 
	0xFE, 
	0x92, 
	0x10, 
	0x10, 
	0x10, 
	0x10, 
	0x10, 
	0x38, 
	0x00, 
	0x00, 
	0x00, 

	
	0x00, 
	0xEE, 
	0x44, 
	0x44, 
	0x44, 
	0x44, 
	0x44, 
	0x44, 
	0x38, 
	0x00, 
	0x00, 
	0x00, 

	
	0x00, 
	0xEE, 
	0x44, 
	0x44, 
	0x28, 
	0x28, 
	0x28, 
	0x10, 
	0x10, 
	0x00, 
	0x00, 
	0x00, 

	
	0x00, 
	0xEE, 
	0x44, 
	0x44, 
	0x54, 
	0x54, 
	0x54, 
	0x54, 
	0x28, 
	0x00, 
	0x00, 
	0x00, 

	
	0x00, 
	0xC6, 
	0x44, 
	0x28, 
	0x10, 
	0x10, 
	0x28, 
	0x44, 
	0xC6, 
	0x00, 
	0x00, 
	0x00, 

	
	0x00, 
	0xEE, 
	0x44, 
	0x28, 
	0x28, 
	0x10, 
	0x10, 
	0x10, 
	0x38, 
	0x00, 
	0x00, 
	0x00, 

	
	0x00, 
	0x7C, 
	0x44, 
	0x08, 
	0x10, 
	0x10, 
	0x20, 
	0x44, 
	0x7C, 
	0x00, 
	0x00, 
	0x00, 

	
	0x00, 
	0x38, 
	0x20, 
	0x20, 
	0x20, 
	0x20, 
	0x20, 
	0x20, 
	0x20, 
	0x20, 
	0x38, 
	0x00, 

	
	0x00, 
	0x40, 
	0x20, 
	0x20, 
	0x20, 
	0x10, 
	0x10, 
	0x08, 
	0x08, 
	0x08, 
	0x00, 
	0x00, 

	
	0x00, 
	0x38, 
	0x08, 
	0x08, 
	0x08, 
	0x08, 
	0x08, 
	0x08, 
	0x08, 
	0x08, 
	0x38, 
	0x00, 

	
	0x00, 
	0x10, 
	0x10, 
	0x28, 
	0x44, 
	0x00, 
	0x00, 
	0x00, 
	0x00, 
	0x00, 
	0x00, 
	0x00, 

	
	0x00, 
	0x00, 
	0x00, 
	0x00, 
	0x00, 
	0x00, 
	0x00, 
	0x00, 
	0x00, 
	0x00, 
	0x00, 
	0xFE, 

	
	0x00, 
	0x10, 
	0x08, 
	0x00, 
	0x00, 
	0x00, 
	0x00, 
	0x00, 
	0x00, 
	0x00, 
	0x00, 
	0x00, 

	
	0x00, 
	0x00, 
	0x00, 
	0x38, 
	0x44, 
	0x3C, 
	0x44, 
	0x44, 
	0x3E, 
	0x00, 
	0x00, 
	0x00, 

	
	0x00, 
	0xC0, 
	0x40, 
	0x58, 
	0x64, 
	0x44, 
	0x44, 
	0x44, 
	0xF8, 
	0x00, 
	0x00, 
	0x00, 

	
	0x00, 
	0x00, 
	0x00, 
	0x3C, 
	0x44, 
	0x40, 
	0x40, 
	0x44, 
	0x38, 
	0x00, 
	0x00, 
	0x00, 

	
	0x00, 
	0x0C, 
	0x04, 
	0x34, 
	0x4C, 
	0x44, 
	0x44, 
	0x44, 
	0x3E, 
	0x00, 
	0x00, 
	0x00, 

	
	0x00, 
	0x00, 
	0x00, 
	0x38, 
	0x44, 
	0x7C, 
	0x40, 
	0x40, 
	0x3C, 
	0x00, 
	0x00, 
	0x00, 

	
	0x00, 
	0x1C, 
	0x20, 
	0x7C, 
	0x20, 
	0x20, 
	0x20, 
	0x20, 
	0x7C, 
	0x00, 
	0x00, 
	0x00, 

	
	0x00, 
	0x00, 
	0x00, 
	0x36, 
	0x4C, 
	0x44, 
	0x44, 
	0x44, 
	0x3C, 
	0x04, 
	0x38, 
	0x00, 

	
	0x00, 
	0xC0, 
	0x40, 
	0x58, 
	0x64, 
	0x44, 
	0x44, 
	0x44, 
	0xEE, 
	0x00, 
	0x00, 
	0x00, 

	
	0x00, 
	0x10, 
	0x00, 
	0x70, 
	0x10, 
	0x10, 
	0x10, 
	0x10, 
	0x7C, 
	0x00, 
	0x00, 
	0x00, 

	
	0x00, 
	0x10, 
	0x00, 
	0x78, 
	0x08, 
	0x08, 
	0x08, 
	0x08, 
	0x08, 
	0x08, 
	0x70, 
	0x00, 

	
	0x00, 
	0xC0, 
	0x40, 
	0x5C, 
	0x48, 
	0x70, 
	0x50, 
	0x48, 
	0xDC, 
	0x00, 
	0x00, 
	0x00, 

	
	0x00, 
	0x30, 
	0x10, 
	0x10, 
	0x10, 
	0x10, 
	0x10, 
	0x10, 
	0x7C, 
	0x00, 
	0x00, 
	0x00, 

	
	0x00, 
	0x00, 
	0x00, 
	0xE8, 
	0x54, 
	0x54, 
	0x54, 
	0x54, 
	0xFE, 
	0x00, 
	0x00, 
	0x00, 

	
	0x00, 
	0x00, 
	0x00, 
	0xD8, 
	0x64, 
	0x44, 
	0x44, 
	0x44, 
	0xEE, 
	0x00, 
	0x00, 
	0x00, 

	
	0x00, 
	0x00, 
	0x00, 
	0x38, 
	0x44, 
	0x44, 
	0x44, 
	0x44, 
	0x38, 
	0x00, 
	0x00, 
	0x00, 

	
	0x00, 
	0x00, 
	0x00, 
	0xD8, 
	0x64, 
	0x44, 
	0x44, 
	0x44, 
	0x78, 
	0x40, 
	0xE0, 
	0x00, 

	
	0x00, 
	0x00, 
	0x00, 
	0x36, 
	0x4C, 
	0x44, 
	0x44, 
	0x44, 
	0x3C, 
	0x04, 
	0x0E, 
	0x00, 

	
	0x00, 
	0x00, 
	0x00, 
	0x6C, 
	0x30, 
	0x20, 
	0x20, 
	0x20, 
	0x7C, 
	0x00, 
	0x00, 
	0x00, 

	
	0x00, 
	0x00, 
	0x00, 
	0x3C, 
	0x44, 
	0x38, 
	0x04, 
	0x44, 
	0x78, 
	0x00, 
	0x00, 
	0x00, 

	
	0x00, 
	0x00, 
	0x20, 
	0x7C, 
	0x20, 
	0x20, 
	0x20, 
	0x22, 
	0x1C, 
	0x00, 
	0x00, 
	0x00, 

	
	0x00, 
	0x00, 
	0x00, 
	0xCC, 
	0x44, 
	0x44, 
	0x44, 
	0x4C, 
	0x36, 
	0x00, 
	0x00, 
	0x00, 

	
	0x00, 
	0x00, 
	0x00, 
	0xEE, 
	0x44, 
	0x44, 
	0x28, 
	0x28, 
	0x10, 
	0x00, 
	0x00, 
	0x00, 

	
	0x00, 
	0x00, 
	0x00, 
	0xEE, 
	0x44, 
	0x54, 
	0x54, 
	0x54, 
	0x28, 
	0x00, 
	0x00, 
	0x00, 

	
	0x00, 
	0x00, 
	0x00, 
	0xCC, 
	0x48, 
	0x30, 
	0x30, 
	0x48, 
	0xCC, 
	0x00, 
	0x00, 
	0x00, 

	
	0x00, 
	0x00, 
	0x00, 
	0xEE, 
	0x44, 
	0x24, 
	0x28, 
	0x18, 
	0x10, 
	0x10, 
	0x78, 
	0x00, 

	
	0x00, 
	0x00, 
	0x00, 
	0x7C, 
	0x48, 
	0x10, 
	0x20, 
	0x44, 
	0x7C, 
	0x00, 
	0x00, 
	0x00, 

	
	0x00, 
	0x08, 
	0x10, 
	0x10, 
	0x10, 
	0x10, 
	0x20, 
	0x10, 
	0x10, 
	0x10, 
	0x08, 
	0x00, 

	
	0x00, 
	0x10, 
	0x10, 
	0x10, 
	0x10, 
	0x10, 
	0x10, 
	0x10, 
	0x10, 
	0x10, 
	0x00, 
	0x00, 

	
	0x00, 
	0x20, 
	0x10, 
	0x10, 
	0x10, 
	0x10, 
	0x08, 
	0x10, 
	0x10, 
	0x10, 
	0x20, 
	0x00, 

	
	0x00, 
	0x00, 
	0x00, 
	0x00, 
	0x00, 
	0x24, 
	0x58, 
	0x00, 
	0x00, 
	0x00, 
	0x00, 
	0x00, 
};

sFONT Font12 = {
  Font12_Table,
  7,  
  12,  
};

 