


































 

 



































 

 

 


 
 
 

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
  
 

 






const CH_CN Font12CN_Table[] = 
{
 
 
{"��",
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x1D,0xC0,0x1D,0x80,0x3B,0xFF,0x3B,0x07,
0x3F,0x77,0x7E,0x76,0xF8,0x70,0xFB,0xFE,0xFB,0xFE,0x3F,0x77,0x3F,0x77,0x3E,0x73,
0x38,0x70,0x38,0x70,0x3B,0xE0,0x00,0x00,0x00,0x00},

 
 
{"��",
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x30,0x00,0x73,0xFF,0x70,0x0F,0xFE,0x1E,
0x7E,0x3C,0x6E,0x38,0xEE,0x30,0xEF,0xFF,0xFC,0x30,0x7C,0x30,0x38,0x30,0x3E,0x30,
0x7E,0x30,0xE0,0x30,0xC1,0xF0,0x00,0x00,0x00,0x00},

 
 
{"��",
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x30,0x0E,0x30,0x0E,0x3F,0xEE,0x30,0xEE,
0xFC,0xFF,0x76,0xCE,0x77,0xFE,0x7B,0xFE,0xFF,0xFE,0xF3,0xDE,0xF3,0xCE,0x37,0xEE,
0x3E,0x6E,0x3C,0x0E,0x30,0x3E,0x00,0x00,0x00,0x00},

 
 
{"ݮ",
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x06,0x70,0xFF,0xFF,0x3E,0x70,0x38,0x00,
0x7F,0xFF,0xE0,0x00,0xFF,0xFC,0x3B,0x8C,0x39,0xCC,0xFF,0xFF,0x73,0x9C,0x71,0xDC,
0x7F,0xFF,0x00,0x1C,0x01,0xF8,0x00,0x00,0x00,0x00},

 
 
{"��",
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xE0,0x1F,0xFF,0xF0,0x3E,0x00,0x0E,0x1F,
0xCF,0xFB,0xFF,0xF8,0x3F,0xFF,0x0F,0xFF,0x7F,0xD8,0x7F,0xDC,0x6F,0xCE,0xED,0xFF,
0xFD,0xF7,0xF9,0xC0,0x00,0x00,0x00,0x00,0x00,0x00},

 
 
{"a",
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x3E,0x00,0x67,0x00,0x07,0x80,0x0F,0x80,0x7F,0x80,0xE3,0x80,0xE7,0x80,0xE7,0x80,
0x7F,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},

 
 
{"b",
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x70,0x00,0x70,0x00,0x70,0x00,0x70,0x00,
0x7F,0x00,0x7B,0x80,0x71,0xC0,0x71,0xC0,0x71,0xC0,0x71,0xC0,0x71,0xC0,0x7B,0x80,
0x7F,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},

 
 
{"c",
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x3F,0x00,0x73,0x00,0xF0,0x00,0xE0,0x00,0xE0,0x00,0xE0,0x00,0xF0,0x00,0x73,0x00,
0x3F,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},

 
 
{"A",
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x0E,0x00,0x1F,0x00,0x1F,0x00,
0x1F,0x00,0x3B,0x80,0x3B,0x80,0x71,0x80,0x7F,0xC0,0x71,0xC0,0xE0,0xE0,0xE0,0xE0,
0xE0,0xE0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},
};

cFONT Font12CN = {
  Font12CN_Table,
  sizeof(Font12CN_Table)/sizeof(CH_CN),   
  11,  
  16,  
  21,  
};

 
