























 



































 





 































 




 





 













































 




 





 

 


 


 



 

 

 

 

 

 



 

 


 

 

 


 


 
    
    
 
 

 

     
     

 


 


 


 

 


 





 





 


   
   
   
   
   
   
   






 


 





 


 


 



 































 






 































 

































 































 
  

 
 


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

  






 
 
 


  #pragma system_include

 
 

 

  #pragma system_include














 



 
  typedef _Sizet size_t;

typedef unsigned int __data_size_t;



 
#pragma rtmodel="__dlib_full_locale_support",   "1"

  
    __intrinsic __nounwind size_t __iar_Mbcurmax(void);
  


 



 
  typedef _Wchart wchar_t;

typedef struct
{  
  int quot;
  int rem;
} div_t;

typedef struct
{  
  long quot;
  long rem;
} ldiv_t;

  typedef struct
  {  
    long long quot;
    long long rem;
  } lldiv_t;


 
  
  __intrinsic __nounwind int             atexit(void (*)(void));
    __intrinsic __nounwind          int  at_quick_exit(void (*)(void)) ;
    __intrinsic __noreturn __nounwind void _Exit(int) ;
    __intrinsic __noreturn __nounwind void quick_exit(int) ;
  __intrinsic __noreturn __nounwind void   exit(int);
   __intrinsic __nounwind        char * getenv(const char *);
  __intrinsic __nounwind          int    system(const char *);



               __intrinsic __nounwind void *    aligned_alloc(size_t, size_t);
          __intrinsic __noreturn __nounwind void  abort(void) ;
  _Pragma("function_effects = no_state, always_returns")     __intrinsic __nounwind int       abs(int);
               __intrinsic __nounwind void *    calloc(size_t, size_t);
  _Pragma("function_effects = no_state, always_returns")     __intrinsic __nounwind div_t     div(int, int);
               __intrinsic __nounwind void      free(void *);
  _Pragma("function_effects = no_state, always_returns")     __intrinsic __nounwind long      labs(long);
  _Pragma("function_effects = no_state, always_returns")     __intrinsic __nounwind ldiv_t    ldiv(long, long);
    _Pragma("function_effects = no_state, always_returns")   __intrinsic __nounwind long long llabs(long long);
    _Pragma("function_effects = no_state, always_returns")   __intrinsic __nounwind lldiv_t   lldiv(long long, long long);
  _Pragma("function_effects = no_state, always_returns")     __intrinsic __nounwind double    fabs(double);
  _Pragma("function_effects = no_state, always_returns")     __intrinsic __nounwind float     fabsf(float);
  _Pragma("function_effects = no_state, always_returns")     __intrinsic __nounwind long double fabsl(long double);
               __intrinsic __nounwind void *    malloc(size_t);
  _Pragma("function_effects = no_write(1), always_returns")    __intrinsic __nounwind int       mblen(const char *, size_t);
    _Pragma("function_effects = no_read(1), no_write(2), always_returns")  __intrinsic __nounwind size_t mbstowcs(wchar_t *restrict,
                                                const char *restrict, size_t);
    _Pragma("function_effects = no_read(1), no_write(2), always_returns") __intrinsic __nounwind   int    mbtowc(wchar_t *restrict,
                                              const char *restrict, size_t);
               __intrinsic __nounwind int    rand(void);
               __intrinsic __nounwind void   srand(unsigned int);
               __intrinsic __nounwind void * realloc(void *, size_t);
               __intrinsic __nounwind void * __iar_realloc_in_place(void *, size_t);
  _Pragma("function_effects = no_write(1), no_read(2), always_returns") __intrinsic __nounwind long          strtol(const char *restrict,
                                                 char **restrict, int);
  _Pragma("function_effects = no_write(1), no_read(2), always_returns") __intrinsic __nounwind unsigned long strtoul(const char *, char **, int);
    _Pragma("function_effects = no_read(1), no_write(2), always_returns")  __intrinsic __nounwind size_t wcstombs(char *restrict,
                                               const wchar_t *restrict,
                                               size_t);
    _Pragma("function_effects = no_read(1), always_returns")     __intrinsic __nounwind int    wctomb(char *, wchar_t);
    _Pragma("function_effects = no_write(1), no_read(2), always_returns") __intrinsic __nounwind long long strtoll(const char *, char **, int);
    _Pragma("function_effects = no_write(1), no_read(2), always_returns") __intrinsic __nounwind unsigned long long strtoull(const char *,
                                                          char **, int);



  typedef int _Cmpfun(const void *, const void *);
  _Pragma("function_effects = no_write(1,2), always_returns")  __intrinsic void * bsearch(const void *,
                                                       const void *, size_t,
                                                       size_t, _Cmpfun *);
                __intrinsic void   qsort(void *, size_t, size_t,
                                                     _Cmpfun *);
               __intrinsic void     __qsortbbl(void *, size_t,
                                                          size_t, _Cmpfun *);
  _Pragma("function_effects = no_write(1), always_returns")    __intrinsic __nounwind double             atof(const char *);
  _Pragma("function_effects = no_write(1), always_returns")    __intrinsic __nounwind int                atoi(const char *);
  _Pragma("function_effects = no_write(1), always_returns")    __intrinsic __nounwind long               atol(const char *);
     _Pragma("function_effects = no_write(1), always_returns") __intrinsic __nounwind long long        atoll(const char *);
     _Pragma("function_effects = no_write(1), no_read(2), always_returns") __intrinsic __nounwind float         strtof(const char *restrict,
                                                    char **restrict);
     _Pragma("function_effects = no_write(1), no_read(2), always_returns") __intrinsic __nounwind long double   strtold(const char *, char **);
  _Pragma("function_effects = no_write(1), no_read(2), always_returns") __intrinsic __nounwind double           strtod(const char *restrict,
                                                    char **restrict);
    _Pragma("function_effects = no_state, always_returns")   __intrinsic __nounwind int              __iar_DLib_library_version(void);


  
  #pragma inline=no_body
  int abs(int i)
  {       
    return i < 0 ? -i : i;
  }

  #pragma inline=no_body
  long labs(long i)
  {  
    return i < 0 ? -i : i;
  }

    #pragma inline=no_body
    long long llabs(long long i)
    {  
      return i < 0 ? -i : i;
    }
  









 


  #pragma system_include




#pragma inline=forced_no_body
__intrinsic __nounwind
div_t div(int a, int b)
{
  int q = a / b;
  int r = a - (q*b);
  div_t d;
  d.quot = q;
  d.rem = r;
  return d;
}

#pragma inline=forced_no_body
__intrinsic __nounwind
ldiv_t ldiv(long a, long b)
{
  int q = a / b;
  int r = a - (q*b);
  ldiv_t ld;
  ld.quot = q;
  ld.rem = r;
  return ld;
}

    #pragma type_attribute=__value_in_regs
    lldiv_t __aeabi_ldivmod(long long n, long long d);

    #pragma inline=forced_no_body
    __intrinsic __nounwind
    lldiv_t lldiv(long long a, long long b)
    {
      return __aeabi_ldivmod(a, b);
    }








 
 
 

  #pragma system_include

 
 

 

  #pragma system_include














 



 
#pragma rtmodel="__dlib_file_descriptor","1"

 

  typedef _Filet FILE;


#pragma language = save
#pragma language = extended

      
         extern FILE __iar_Stdin;
         extern FILE __iar_Stdout;
         extern FILE __iar_Stderr;
      

#pragma language=restore



 
typedef _Fpost fpos_t;


 


   
  
    __intrinsic __nounwind    void   clearerr(FILE *);
    __intrinsic __nounwind    int    fclose(FILE *);
    __intrinsic __nounwind    int    feof(FILE *);
    __intrinsic __nounwind    int    ferror(FILE *);
    __intrinsic __nounwind    int    fflush(FILE *);
    __intrinsic __nounwind    int    fgetc(FILE *);
    __intrinsic __nounwind    int    fgetpos(FILE *restrict, fpos_t *restrict);
    __intrinsic __nounwind    char * fgets(char *restrict, int, FILE *restrict);
     __intrinsic __nounwind  FILE * fopen(const char *restrict, const char *restrict);
     _Pragma("__printf_args") _Pragma("library_default_requirements _Printf = unknown") __intrinsic __nounwind int    fprintf(FILE *restrict,
                                   const char *restrict, ...);
    __intrinsic __nounwind    int    fputc(int, FILE *);
    __intrinsic __nounwind    int    fputs(const char *restrict, FILE *restrict);
    __intrinsic __nounwind    size_t fread(void *restrict, size_t, size_t,
                                 FILE *restrict);
     __intrinsic __nounwind  FILE * freopen(const char *restrict,
                                   const char *restrict, FILE *restrict);
     _Pragma("__scanf_args") _Pragma("library_default_requirements _Scanf = unknown") __intrinsic __nounwind  int    fscanf(FILE *restrict, const char *restrict, ...);
    __intrinsic __nounwind    int    fseek(FILE *, long, int);
    __intrinsic __nounwind    int    fsetpos(FILE *, const fpos_t *);
    __intrinsic __nounwind    long   ftell(FILE *);
    __intrinsic __nounwind    size_t fwrite(const void *restrict, size_t, size_t,
                                  FILE *restrict);
    __intrinsic __nounwind    void   rewind(FILE *);
    __intrinsic __nounwind    void   setbuf(FILE *restrict, char *restrict);
    __intrinsic __nounwind    int    setvbuf(FILE *restrict, char *restrict,
                                   int, size_t);
     __intrinsic __nounwind  char * tmpnam(char *);
     __intrinsic __nounwind  FILE * tmpfile(void);
    __intrinsic __nounwind    int    ungetc(int, FILE *);
     _Pragma("__printf_args") _Pragma("library_default_requirements _Printf = unknown") __intrinsic __nounwind int    vfprintf(FILE *restrict, const char *restrict,
                                    __Va_list);
       _Pragma("__scanf_args") _Pragma("library_default_requirements _Scanf = unknown") __intrinsic __nounwind int   vfscanf(FILE *restrict, const char *restrict,
                                   __Va_list);
      __intrinsic __nounwind FILE *   fdopen(signed char, const char *);
      __intrinsic __nounwind signed char fileno(FILE *);
      __intrinsic __nounwind int      getw(FILE *);
      __intrinsic __nounwind int      putw(int, FILE *);
    __intrinsic __nounwind int        getc(FILE *);
    __intrinsic __nounwind int        putc(int, FILE *);
  


     
    _Pragma("function_effects = no_read(1), always_returns") __intrinsic __nounwind   char * __gets(char *, int);
    _Pragma("function_effects = no_read(1), always_returns")  __intrinsic __nounwind char * gets(char *);
  _Pragma("function_effects = no_write(1), always_returns")    __intrinsic __nounwind    void   perror(const char *);
  _Pragma("function_effects = no_write(1), always_returns")     _Pragma("__printf_args") _Pragma("library_default_requirements _Printf = unknown") __intrinsic __nounwind int    printf(const char *restrict, ...);
  _Pragma("function_effects = no_write(1), always_returns")    __intrinsic __nounwind    int    puts(const char *);
  _Pragma("function_effects = no_write(1), always_returns")     _Pragma("__scanf_args") _Pragma("library_default_requirements _Scanf = unknown") __intrinsic __nounwind  int    scanf(const char *restrict, ...);
  _Pragma("function_effects = no_read(1), no_write(2), always_returns")  _Pragma("__printf_args") _Pragma("library_default_requirements _Printf = unknown") __intrinsic __nounwind int    sprintf(char *restrict,
                                              const char *restrict, ...);
  _Pragma("function_effects = no_write(1,2), always_returns")  _Pragma("__scanf_args") _Pragma("library_default_requirements _Scanf = unknown") __intrinsic __nounwind  int    sscanf(const char *restrict,
                                             const char *restrict, ...);
                                       
  __intrinsic __nounwind                 int    __ungetchar(int);
  _Pragma("function_effects = no_write(1), always_returns")     _Pragma("__printf_args") _Pragma("library_default_requirements _Printf = unknown") __intrinsic __nounwind int    vprintf(const char *restrict,
                                              __Va_list);
    _Pragma("function_effects = no_write(1), always_returns")     _Pragma("__scanf_args") _Pragma("library_default_requirements _Scanf = unknown") __intrinsic __nounwind int vscanf(const char *restrict, __Va_list);
    _Pragma("function_effects = no_write(1,2), always_returns")  _Pragma("__scanf_args") _Pragma("library_default_requirements _Scanf = unknown") __intrinsic __nounwind int vsscanf(const char *restrict,
                                            const char *restrict, __Va_list);
  _Pragma("function_effects = no_read(1), no_write(2), always_returns")   _Pragma("__printf_args") _Pragma("library_default_requirements _Printf = unknown") __intrinsic __nounwind int vsprintf(char *restrict,
                                             const char *restrict, __Va_list);
                                 
  _Pragma("function_effects = no_write(1), always_returns") __intrinsic __nounwind size_t   __write_array(const void *, size_t, size_t);
    _Pragma("function_effects = no_read(1), no_write(3), always_returns")  _Pragma("__printf_args") _Pragma("library_default_requirements _Printf = unknown") __intrinsic __nounwind int snprintf(char *restrict, size_t,
                                              const char *restrict, ...);
    _Pragma("function_effects = no_read(1), no_write(3), always_returns")  _Pragma("__printf_args") _Pragma("library_default_requirements _Printf = unknown") __intrinsic __nounwind int vsnprintf(char *restrict, size_t,
                                               const char *restrict,
                                               __Va_list);

  __intrinsic __nounwind int                getchar(void);
  __intrinsic __nounwind int                putchar(int);
  
 
  __intrinsic __nounwind int                remove(const char *);
  __intrinsic __nounwind int                rename(const char *, const char *);







 


typedef int sys_prot_t;





 












 

 
 
 

  #pragma system_include

 
 

 

  #pragma system_include














 




 
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

 






















 











 
typedef uint8_t   u8_t;
typedef int8_t    s8_t;
typedef uint16_t  u16_t;
typedef int16_t   s16_t;
typedef uint32_t  u32_t;
typedef int32_t   s32_t;
typedef uintptr_t mem_ptr_t;







 

 
 
 

  #pragma system_include

 
 

 

  #pragma system_include














 




   
  typedef struct
  {  
    intmax_t quot;
    intmax_t rem;
  } imaxdiv_t;

   
  _Pragma("function_effects = no_state, write_errno, always_returns")    __intrinsic __nounwind intmax_t  imaxabs(intmax_t);
  _Pragma("function_effects = no_state, write_errno, always_returns")    __intrinsic __nounwind imaxdiv_t imaxdiv(intmax_t, intmax_t);

  _Pragma("function_effects = no_state, write_errno, no_write(1), always_returns") __intrinsic __nounwind intmax_t  strtoimax(const char *restrict,
                                               char **restrict, int);
  _Pragma("function_effects = no_state, write_errno, no_write(1), always_returns") __intrinsic __nounwind uintmax_t strtoumax(const char *restrict,
                                               char **restrict, int);
  _Pragma("function_effects = no_state, write_errno, no_write(1), always_returns") __intrinsic __nounwind intmax_t  wcstoimax(const _Wchart *restrict,
                                               _Wchart **restrict, int);
  _Pragma("function_effects = no_state, write_errno, no_write(1), always_returns") __intrinsic __nounwind uintmax_t wcstoumax(const _Wchart *restrict,
                                               _Wchart **restrict, int);



 

 






 











 










 




 




 



 







 


 









 































 




 







 

 
 

 
 
 
 




 

 




















 

 



 




 






 


 





 




 







 


 





 



 




 


 





 




 






 








 








 







 


 





 




 




 









 





 




 









 




 






 




 






 


















 


 





 




 




 




 





 




 




 




 




 







 






 






 





 




 




 





 





 




 




 



 



 


 



 



 


 





 




 


 



 




 







 




 










 


 





 



 




 


 





 




 


 





 





 





 






 





 






 



 





 




 







 





 


 





 




 



 



 



 



 


 





 




 


 



 


 





 




 


 



 






 



 





 



 


 





 




 


 




 







 


 





 




 




 


 





 




 


 




 


 





 




 



 

 

 




 

 




 

 










 


 


 





 




 


 



 



 



 


 





 




 


 



 




 



 



 




 







 








 





 




 





 





 




 




 



 





 














 






 




 







 








 


 





 




 




 




 





 


 





 




 



 



 




 




 




 







 









 




 


 





 




 




 



 




 




 













 


 





 




 


 





 





 





 




 



 





 





 



 





 





 





 





 





 





 


 





 




 


 



 










 








 


 





 




 


 



 






 





 







 





 




 




 




 



 



 



 



 



 





 








 


 





 




 


 





 





 




 




 



 



 



 



 



 



 



 



 



 



 




 


 





 




 


 



 



 



 



 




 



 



 


 





 


 




 



 


 





 


 



 


 





 



 



 



 



 



 



 




 




 



 



 




 



 




 




 





 


 



 





 






 











 







 




 












 











 








 










 


















 




 






 


 





 




 




 




 



 



 



 



 



 



 



 



 



 



 



 



 



 



 



 



 



 



 



 




 



 



 



 



 



 



 



 



 



 



 



 



 


 





 




 



 


 






 































 





 































 




 





 































 





 































 




 






 
typedef u16_t mem_size_t;

void  mem_init(void);
void *mem_trim(void *mem, mem_size_t size);
void *mem_malloc(mem_size_t size);
void *mem_calloc(mem_size_t count, mem_size_t size);
void  mem_free(void *mem);





 































 



 






 











 

 


 







 





























 







 




 

 
typedef enum {






 











 

 


 







 
MEMP_RAW_PCB,

MEMP_UDP_PCB,

MEMP_TCP_PCB,
MEMP_TCP_PCB_LISTEN,
MEMP_TCP_SEG,

MEMP_REASSDATA,
MEMP_FRAG_PBUF,





MEMP_SYS_TIMEOUT,













 
MEMP_PBUF,
MEMP_PBUF_POOL,





 




 
  MEMP_MAX
} memp_t;




 































 






 































 




 








 


struct memp {
  struct memp *next;
};


 
struct memp_desc {

   
  u16_t size;

   
  u16_t num;

   
  u8_t *base;

   
  struct memp **tab;
};



void memp_init_pool(const struct memp_desc *desc);

void *memp_malloc_pool(const struct memp_desc *desc);
void  memp_free_pool(const struct memp_desc* desc, void *mem);





 































 

extern const struct memp_desc* const memp_pools[MEMP_MAX];




 















 





 



 



 


void  memp_init(void);

void *memp_malloc(memp_t type);
void  memp_free(memp_t type, void *mem);






















 






 































 





 































 




 






 































 






 































 




 




 






























 





 































 




 







 


 
typedef s8_t err_t;

 
typedef enum {
 
  ERR_OK         = 0,
 
  ERR_MEM        = -1,
 
  ERR_BUF        = -2,
 
  ERR_TIMEOUT    = -3,
 
  ERR_RTE        = -4,
 
  ERR_INPROGRESS = -5,
 
  ERR_VAL        = -6,
 
  ERR_WOULDBLOCK = -7,
 
  ERR_USE        = -8,
 
  ERR_ALREADY    = -9,
 
  ERR_ISCONN     = -10,
 
  ERR_CONN       = -11,
 
  ERR_IF         = -12,

 
  ERR_ABRT       = -13,
 
  ERR_RST        = -14,
 
  ERR_CLSD       = -15,
 
  ERR_ARG        = -16
} err_enum_t;




 











 


 





 
typedef enum {
  

 
  PBUF_TRANSPORT,
  

 
  PBUF_IP,
  


 
  PBUF_LINK,
  



 
  PBUF_RAW_TX,
  
 
  PBUF_RAW
} pbuf_layer;




 
typedef enum {
  




 
  PBUF_RAM,
  

 
  PBUF_ROM,
  

 
  PBUF_REF,
  




 
  PBUF_POOL
} pbuf_type;


 

 
 
 
 
 

 
struct pbuf {
   
  struct pbuf *next;

   
  void *payload;

  





 
  u16_t tot_len;

   
  u16_t len;

   
  u8_t   type;

   
  u8_t flags;

  



 
  u16_t ref;
};





 
struct pbuf_rom {
   
  struct pbuf *next;

   
  const void *payload;
};

 
typedef void (*pbuf_free_custom_fn)(struct pbuf *p);

 
struct pbuf_custom {
   
  struct pbuf pbuf;
   
  pbuf_free_custom_fn custom_free_function;
};

 
   

 

struct pbuf *pbuf_alloc(pbuf_layer l, u16_t length, pbuf_type type);
struct pbuf *pbuf_alloced_custom(pbuf_layer l, u16_t length, pbuf_type type,
                                 struct pbuf_custom *p, void *payload_mem,
                                 u16_t payload_mem_len);
void pbuf_realloc(struct pbuf *p, u16_t size);
u8_t pbuf_header(struct pbuf *p, s16_t header_size);
u8_t pbuf_header_force(struct pbuf *p, s16_t header_size);
void pbuf_ref(struct pbuf *p);
u8_t pbuf_free(struct pbuf *p);
u16_t pbuf_clen(const struct pbuf *p);
void pbuf_cat(struct pbuf *head, struct pbuf *tail);
void pbuf_chain(struct pbuf *head, struct pbuf *tail);
struct pbuf *pbuf_dechain(struct pbuf *p);
err_t pbuf_copy(struct pbuf *p_to, const struct pbuf *p_from);
u16_t pbuf_copy_partial(const struct pbuf *p, void *dataptr, u16_t len, u16_t offset);
err_t pbuf_take(struct pbuf *buf, const void *dataptr, u16_t len);
err_t pbuf_take_at(struct pbuf *buf, const void *dataptr, u16_t len, u16_t offset);
struct pbuf *pbuf_skip(struct pbuf* in, u16_t in_offset, u16_t* out_offset);
struct pbuf *pbuf_coalesce(struct pbuf *p, pbuf_layer layer);

u8_t pbuf_get_at(const struct pbuf* p, u16_t offset);
int pbuf_try_get_at(const struct pbuf* p, u16_t offset);
void pbuf_put_at(struct pbuf* p, u16_t offset, u8_t data);
u16_t pbuf_memcmp(const struct pbuf* p, u16_t offset, const void* s2, u16_t n);
u16_t pbuf_memfind(const struct pbuf* p, const void* mem, u16_t mem_len, u16_t start_offset);
u16_t pbuf_strstr(const struct pbuf* p, const char* substr);





 































 





 































 




 







 































 





 































 




 




 































 

 




 































 




 




 


 

u16_t lwip_htons(u16_t x);

u32_t lwip_htonl(u32_t x);

 



 






 

 
void  lwip_itoa(char* result, size_t bufsize, int number);
 
int   lwip_strnicmp(const char* str1, const char* str2, size_t len);
 
int   lwip_stricmp(const char* str1, const char* str2);
 
char* lwip_strnstr(const char* buffer, const char* token, size_t n);






 































 





 































 




 





 
struct ip4_addr {
  u32_t addr;
};


 






























 

#pragma pack(1)


struct ip4_addr_packed {
  u32_t addr;
} ;































 

#pragma pack()



 
typedef struct ip4_addr ip4_addr_t;
typedef struct ip4_addr_packed ip4_addr_p_t;




 






























 

#pragma pack(1)


struct ip4_addr2 {
  u16_t addrw[2];
} ;































 

#pragma pack()


 
struct netif;

 
 
 
 




 








 



 

 
 
 
 
 
 

 
 
 

 








 


u8_t ip4_addr_isbroadcast_u32(u32_t addr, const struct netif *netif);

u8_t ip4_addr_netmask_valid(u32_t netmask);




 

 


 

u32_t ipaddr_addr(const char *cp);
int ip4addr_aton(const char *cp, ip4_addr_t *addr);
 
char *ip4addr_ntoa(const ip4_addr_t *addr);
char *ip4addr_ntoa_r(const ip4_addr_t *addr, char *buf, int buflen);







 



































 





 































 




 








 
enum lwip_ip_addr_type {
   
  IPADDR_TYPE_V4 =   0U,
   
  IPADDR_TYPE_V6 =   6U,
   
  IPADDR_TYPE_ANY = 46U
};




typedef ip4_addr_t ip_addr_t;





extern const ip_addr_t ip_addr_any;
extern const ip_addr_t ip_addr_broadcast;




 




 




 

 
 









 



 





 






 

 




 


 


 

 

 



 

enum lwip_internal_netif_client_data_index
{
   LWIP_NETIF_CLIENT_DATA_INDEX_DHCP,
   LWIP_NETIF_CLIENT_DATA_INDEX_MAX
};


struct netif;


 
enum netif_mac_filter_action {
   
  NETIF_DEL_MAC_FILTER = 0,
   
  NETIF_ADD_MAC_FILTER = 1
};





 
typedef err_t (*netif_init_fn)(struct netif *netif);





 
typedef err_t (*netif_input_fn)(struct pbuf *p, struct netif *inp);








 
typedef err_t (*netif_output_fn)(struct netif *netif, struct pbuf *p,
       const ip4_addr_t *ipaddr);







 
typedef err_t (*netif_linkoutput_fn)(struct netif *netif, struct pbuf *p);
 
typedef void (*netif_status_callback_fn)(struct netif *netif);

u8_t netif_alloc_client_data_id(void);


 


 



 
struct netif {
   
  struct netif *next;

   
  ip_addr_t ip_addr;
  ip_addr_t netmask;
  ip_addr_t gw;
  
 
  netif_input_fn input;
  


 
  netif_output_fn output;
  

 
  netif_linkoutput_fn linkoutput;
  
 
  netif_status_callback_fn link_callback;
  
 
  void *state;
  void* client_data[LWIP_NETIF_CLIENT_DATA_INDEX_MAX + 0];
   
  u8_t rs_count;
   
  u16_t mtu;
   
  u8_t hwaddr_len;
   
  u8_t hwaddr[6U];
   
  u8_t flags;
   
  char name[2];
   
  u8_t num;
};


 
extern struct netif *netif_list;
 
extern struct netif *netif_default;

void netif_init(void);

struct netif *netif_add(struct netif *netif,
                        const ip4_addr_t *ipaddr, const ip4_addr_t *netmask, const ip4_addr_t *gw,
                        void *state, netif_init_fn init, netif_input_fn input);
void netif_set_addr(struct netif *netif, const ip4_addr_t *ipaddr, const ip4_addr_t *netmask,
                    const ip4_addr_t *gw);
void netif_remove(struct netif * netif);




 
struct netif *netif_find(const char *name);

void netif_set_default(struct netif *netif);

void netif_set_ipaddr(struct netif *netif, const ip4_addr_t *ipaddr);
void netif_set_netmask(struct netif *netif, const ip4_addr_t *netmask);
void netif_set_gw(struct netif *netif, const ip4_addr_t *gw);
 
 
 
 
 
 

void netif_set_up(struct netif *netif);
void netif_set_down(struct netif *netif);


 


void netif_set_link_up(struct netif *netif);
void netif_set_link_down(struct netif *netif);
 

void netif_set_link_callback(struct netif *netif, netif_status_callback_fn link_callback);





err_t netif_input(struct pbuf *p, struct netif *inp);







 































 





 































 




 





 































 





 































 




 






 































 



 































 

#pragma pack(1)


 
struct ip_hdr {
   
  u8_t _v_hl;
   
  u8_t _tos;
   
  u16_t _len;
   
  u16_t _id;
   
  u16_t _offset;
   
  u8_t _ttl;
   
  u8_t _proto;
   
  u16_t _chksum;
   
  ip4_addr_p_t src;
  ip4_addr_p_t dest;
} ;































 

#pragma pack()


 

 






 

struct netif *ip4_route(const ip4_addr_t *dest);
err_t ip4_input(struct pbuf *p, struct netif *inp);
err_t ip4_output(struct pbuf *p, const ip4_addr_t *src, const ip4_addr_t *dest,
       u8_t ttl, u8_t tos, u8_t proto);
err_t ip4_output_if(struct pbuf *p, const ip4_addr_t *src, const ip4_addr_t *dest,
       u8_t ttl, u8_t tos, u8_t proto, struct netif *netif);
err_t ip4_output_if_src(struct pbuf *p, const ip4_addr_t *src, const ip4_addr_t *dest,
       u8_t ttl, u8_t tos, u8_t proto, struct netif *netif);












 


































 





 































 




 






 































 



 





 


 





 

struct ip_pcb {
 
  ip_addr_t local_ip; ip_addr_t remote_ip; u8_t so_options; u8_t tos; u8_t ttl ;
};



 

 

 
struct ip_globals
{
   
  struct netif *current_netif;
   
  struct netif *current_input_netif;
   
  struct ip_hdr *current_ip4_header;
   
  u16_t current_ip_header_tot_len;
   
  ip_addr_t current_iphdr_src;
   
  ip_addr_t current_iphdr_dest;
};
extern struct ip_globals ip_data;





 


 
 
 
 




 
 
 
 
 
 


 
 

 
 
 












 































 




 






























 

#pragma pack(1)


struct udp_hdr {
  u16_t src;
  u16_t dest;   
  u16_t len;
  u16_t chksum;
} ;































 

#pragma pack()






struct udp_pcb;














 
typedef void (*udp_recv_fn)(void *arg, struct udp_pcb *pcb, struct pbuf *p,
    const ip_addr_t *addr, u16_t port);

 
struct udp_pcb {
 
  ip_addr_t local_ip; ip_addr_t remote_ip; u8_t so_options; u8_t tos; u8_t ttl ;

 

  struct udp_pcb *next;

  u8_t flags;
   
  u16_t local_port, remote_port;



   
  udp_recv_fn recv;
   
  void *recv_arg;
};
 
extern struct udp_pcb *udp_pcbs;


 
struct udp_pcb * udp_new        (void);
struct udp_pcb * udp_new_ip_type(u8_t type);
void             udp_remove     (struct udp_pcb *pcb);
err_t            udp_bind       (struct udp_pcb *pcb, const ip_addr_t *ipaddr,
                                 u16_t port);
err_t            udp_connect    (struct udp_pcb *pcb, const ip_addr_t *ipaddr,
                                 u16_t port);
void             udp_disconnect (struct udp_pcb *pcb);
void             udp_recv       (struct udp_pcb *pcb, udp_recv_fn recv,
                                 void *recv_arg);
err_t            udp_sendto_if  (struct udp_pcb *pcb, struct pbuf *p,
                                 const ip_addr_t *dst_ip, u16_t dst_port,
                                 struct netif *netif);
err_t            udp_sendto_if_src(struct udp_pcb *pcb, struct pbuf *p,
                                 const ip_addr_t *dst_ip, u16_t dst_port,
                                 struct netif *netif, const ip_addr_t *src_ip);
err_t            udp_sendto     (struct udp_pcb *pcb, struct pbuf *p,
                                 const ip_addr_t *dst_ip, u16_t dst_port);
err_t            udp_send       (struct udp_pcb *pcb, struct pbuf *p);



 
void             udp_input      (struct pbuf *p, struct netif *inp);

void             udp_init       (void);

 





void udp_netif_ip_addr_changed(const ip_addr_t* old_addr, const ip_addr_t* new_addr);






 
































 





 































 




 





 
 
 


 
typedef enum {
  DHCP_AUTOIP_COOP_STATE_OFF  = 0,
  DHCP_AUTOIP_COOP_STATE_ON   = 1
} dhcp_autoip_coop_state_enum_t;

struct dhcp
{
   
  u32_t xid;
   
  struct dhcp_msg *msg_in;
   
  u8_t pcb_allocated;
   
  u8_t state;
   
  u8_t tries;
  u8_t subnet_mask_given;

  struct pbuf *p_out;  
  struct dhcp_msg *msg_out;  
  u16_t options_out_len;  
  u16_t request_timeout;  
  u16_t t1_timeout;   
  u16_t t2_timeout;   
  u16_t t1_renew_time;   
  u16_t t2_rebind_time;  
  u16_t lease_used;  
  u16_t t0_timeout;  
  ip_addr_t server_ip_addr;  
  ip4_addr_t offered_ip_addr;
  ip4_addr_t offered_sn_mask;
  ip4_addr_t offered_gw_addr;

  u32_t offered_t0_lease;  
  u32_t offered_t1_renew;  
  u32_t offered_t2_rebind;  
};


void dhcp_set_struct(struct netif *netif, struct dhcp *dhcp);
 
void dhcp_cleanup(struct netif *netif);
err_t dhcp_start(struct netif *netif);
err_t dhcp_renew(struct netif *netif);
err_t dhcp_release(struct netif *netif);
void dhcp_stop(struct netif *netif);
void dhcp_inform(struct netif *netif);
void dhcp_network_changed(struct netif *netif);
void dhcp_arp_reply(struct netif *netif, const ip4_addr_t *addr);
u8_t dhcp_supplied_address(const struct netif *netif);
 
void dhcp_coarse_tmr(void);
 
void dhcp_fine_tmr(void);








 

































 






 































 




 






 
































 






 































 




 








 

































 






 































 




 






 































 


































 

#pragma pack(1)


struct eth_addr {
  u8_t addr[6];
} ;































 

#pragma pack()
































 

#pragma pack(1)


 
struct eth_hdr {
  struct eth_addr dest;
  struct eth_addr src;
  u16_t type;
} ;































 

#pragma pack()

































 

#pragma pack(1)




 
struct eth_vlan_hdr {
  u16_t prio_vid;
  u16_t tpid;
} ;































 

#pragma pack()





 
enum eth_type {
   
  ETHTYPE_IP        = 0x0800U,
   
  ETHTYPE_ARP       = 0x0806U, 
   
  ETHTYPE_WOL       = 0x0842U,
   
  ETHTYPE_RARP      = 0x8035U,
   
  ETHTYPE_VLAN      = 0x8100U,
   
  ETHTYPE_IPV6      = 0x86DDU,
   
  ETHTYPE_PPPOEDISC = 0x8863U,
   
  ETHTYPE_PPPOE     = 0x8864U,
   
  ETHTYPE_JUMBO     = 0x8870U,
   
  ETHTYPE_PROFINET  = 0x8892U,
   
  ETHTYPE_ETHERCAT  = 0x88A4U,
   
  ETHTYPE_LLDP      = 0x88CCU,
   
  ETHTYPE_SERCOS    = 0x88CDU,
   
  ETHTYPE_MRP       = 0x88E3U,
   
  ETHTYPE_PTP       = 0x88F7U,
   
  ETHTYPE_QINQ      = 0x9100U
};

 

 


 


 









 































 


































 

#pragma pack(1)


 
struct etharp_hdr {
  u16_t hwtype;
  u16_t proto;
  u8_t hwlen;
  u8_t protolen;
  u16_t opcode;
  struct eth_addr shwaddr;
  struct ip4_addr2 sipaddr;
  struct eth_addr dhwaddr;
  struct ip4_addr2 dipaddr;
} ;































 

#pragma pack()



 
enum etharp_hwtype {
  HWTYPE_ETHERNET = 1
   
};

 
enum etharp_opcode {
  ARP_REQUEST = 1,
  ARP_REPLY   = 2
};



 


void etharp_tmr(void);
s8_t etharp_find_addr(struct netif *netif, const ip4_addr_t *ipaddr,
         struct eth_addr **eth_ret, const ip4_addr_t **ip_ret);
u8_t etharp_get_entry(u8_t i, ip4_addr_t **ipaddr, struct netif **netif, struct eth_addr **eth_ret);
err_t etharp_output(struct netif *netif, struct pbuf *q, const ip4_addr_t *ipaddr);
err_t etharp_query(struct netif *netif, const ip4_addr_t *ipaddr, struct pbuf *q);
err_t etharp_request(struct netif *netif, const ip4_addr_t *ipaddr);



 
void etharp_cleanup_netif(struct netif *netif);



void etharp_input(struct pbuf *p, struct netif *netif);






 
































 





 































 




 





  































 

#pragma pack(1)


 
struct dhcp_msg
{
  u8_t op;
  u8_t htype;
  u8_t hlen;
  u8_t hops;
  u32_t xid;
  u16_t secs;
  u16_t flags;
  ip4_addr_p_t ciaddr;
  ip4_addr_p_t yiaddr;
  ip4_addr_p_t siaddr;
  ip4_addr_p_t giaddr;
  u8_t chaddr[16U];
  u8_t sname[64U];
  u8_t file[128U];
  u32_t cookie;
 
 
 
  u8_t options[68U];
} ;































 

#pragma pack()



 
typedef enum {
  DHCP_STATE_OFF             = 0,
  DHCP_STATE_REQUESTING      = 1,
  DHCP_STATE_INIT            = 2,
  DHCP_STATE_REBOOTING       = 3,
  DHCP_STATE_REBINDING       = 4,
  DHCP_STATE_RENEWING        = 5,
  DHCP_STATE_SELECTING       = 6,
  DHCP_STATE_INFORMING       = 7,
  DHCP_STATE_CHECKING        = 8,
  DHCP_STATE_PERMANENT       = 9,   
  DHCP_STATE_BOUND           = 10,
  DHCP_STATE_RELEASING       = 11,  
  DHCP_STATE_BACKING_OFF     = 12
} dhcp_state_enum_t;

 

 

 


 

 

 





 




 
 

  #pragma system_include

 
 

 

  #pragma system_include














 











 


  #pragma system_include


  





 


  




 




  


 


  #pragma inline=forced_no_body
  _Pragma("function_effects = no_state, no_read(1), no_write(2), returns 1, always_returns") __intrinsic __nounwind void * memcpy(void * _D, const void * _S, size_t _N)
  {
    __aeabi_memcpy(_D, _S, _N);
    return _D;
  }

  #pragma inline=forced_no_body
  _Pragma("function_effects = no_state, no_read(1), no_write(2), returns 1, always_returns") __intrinsic __nounwind void * memmove(void * _D, const void * _S, size_t _N)
  {
    __aeabi_memmove(_D, _S, _N);
    return _D;
  }

  #pragma inline=forced_no_body
  _Pragma("function_effects = no_state, no_read(1), returns 1, always_returns") __intrinsic __nounwind void * memset(void * _D, int _C, size_t _N)
  {
    __aeabi_memset(_D, _N, _C);
    return _D;
  }




 

 

 

  _Pragma("function_effects = no_state, no_write(1,2), always_returns")   __intrinsic __nounwind   int       memcmp(const void *, const void *,
                                                   size_t);
  _Pragma("function_effects = no_state, no_read(1), no_write(2), returns 1, always_returns")  __intrinsic __nounwind void *    memcpy(void *restrict,
                                                   const void *restrict,
                                                   size_t);
  _Pragma("function_effects = no_state, no_read(1), no_write(2), returns 1, always_returns")  __intrinsic __nounwind void *    memmove(void *, const void *,
                                                    size_t);
  _Pragma("function_effects = no_state, no_read(1), returns 1, always_returns")     __intrinsic __nounwind void *    memset(void *, int, size_t);
  _Pragma("function_effects = no_state, no_write(2), returns 1, always_returns")     __intrinsic __nounwind char *    strcat(char *restrict,
                                                   const char *restrict);
  _Pragma("function_effects = no_state, no_write(1,2), always_returns")   __intrinsic __nounwind   int       strcmp(const char *, const char *);
  _Pragma("function_effects = no_write(1,2), always_returns")     __intrinsic __nounwind   int       strcoll(const char *, const char *);
  _Pragma("function_effects = no_state, no_read(1), no_write(2), returns 1, always_returns")  __intrinsic __nounwind char *    strcpy(char *restrict,
                                                   const char *restrict);
  _Pragma("function_effects = no_state, no_write(1,2), always_returns")   __intrinsic __nounwind   size_t    strcspn(const char *, const char *);
                    __intrinsic __nounwind char *    strerror(int);
  _Pragma("function_effects = no_state, no_write(1), always_returns")      __intrinsic __nounwind   size_t    strlen(const char *);
  _Pragma("function_effects = no_state, no_write(2), returns 1, always_returns")     __intrinsic __nounwind char *    strncat(char *restrict,
                                                    const char *restrict,
                                                    size_t);
  _Pragma("function_effects = no_state, no_write(1,2), always_returns")   __intrinsic __nounwind   int       strncmp(const char *, const char *,
                                                    size_t);
  _Pragma("function_effects = no_state, no_read(1), no_write(2), returns 1, always_returns")  __intrinsic __nounwind char *    strncpy(char *restrict,
                                                    const char *restrict,
                                                    size_t);
  _Pragma("function_effects = no_state, no_write(1,2), always_returns")   __intrinsic __nounwind   size_t    strspn(const char *, const char *);
  _Pragma("function_effects = no_write(2), always_returns")         __intrinsic __nounwind char *    strtok(char *restrict,
                                                   const char *restrict);
  _Pragma("function_effects = no_write(2), always_returns")        __intrinsic __nounwind   size_t    strxfrm(char *restrict,
                                                    const char *restrict,
                                                    size_t);
    _Pragma("function_effects = no_write(1), always_returns")      __intrinsic __nounwind   char *    strdup(const char *);
    _Pragma("function_effects = no_write(1,2), always_returns")   __intrinsic __nounwind   int       strcasecmp(const char *,
                                                       const char *);
    _Pragma("function_effects = no_write(1,2), always_returns")   __intrinsic __nounwind   int       strncasecmp(const char *,
                                                        const char *, size_t);
    _Pragma("function_effects = no_state, no_write(2), always_returns")    __intrinsic __nounwind   char *    strtok_r(char *, const char *,
                                                     char **);
    _Pragma("function_effects = no_state, no_write(1), always_returns")     __intrinsic __nounwind size_t    strnlen(char const *, size_t);


  _Pragma("function_effects = no_state, no_write(1), always_returns")    __intrinsic __nounwind void *memchr(const void *_S, int _C, size_t _N);
  _Pragma("function_effects = no_state, no_write(1), always_returns")    __intrinsic __nounwind char *strchr(const char *_S, int _C);
  _Pragma("function_effects = no_state, no_write(1,2), always_returns") __intrinsic __nounwind char *strpbrk(const char *_S, const char *_P);
  _Pragma("function_effects = no_state, no_write(1), always_returns")    __intrinsic __nounwind char *strrchr(const char *_S, int _C);
  _Pragma("function_effects = no_state, no_write(1,2), always_returns") __intrinsic __nounwind char *strstr(const char *_S, const char *_P);






 



 





 


 
 






 


 
u32_t dhcp_rx_options_val[(8 + 2)];


 
u8_t  dhcp_rx_options_given[(8 + 2)];

static u8_t dhcp_discover_request_options[] = {
  1,
  3,
  28,
  6
  };



static struct udp_pcb *dhcp_pcb;
static u8_t dhcp_pcb_refcount;

 
static err_t dhcp_discover(struct netif *netif);
static err_t dhcp_select(struct netif *netif);
static void dhcp_bind(struct netif *netif);
static err_t dhcp_decline(struct netif *netif);
static err_t dhcp_rebind(struct netif *netif);
static err_t dhcp_reboot(struct netif *netif);
static void dhcp_set_state(struct dhcp *dhcp, u8_t new_state);

 
static void dhcp_recv(void *arg, struct udp_pcb *pcb, struct pbuf *p, const ip_addr_t *addr, u16_t port);

 
static void dhcp_timeout(struct netif *netif);
static void dhcp_t1_timeout(struct netif *netif);
static void dhcp_t2_timeout(struct netif *netif);

 
 
static err_t dhcp_create_msg(struct netif *netif, struct dhcp *dhcp, u8_t message_type);
 
static void dhcp_delete_msg(struct dhcp *dhcp);
 
static void dhcp_option(struct dhcp *dhcp, u8_t option_type, u8_t option_len);
 
static void dhcp_option_byte(struct dhcp *dhcp, u8_t value);
static void dhcp_option_short(struct dhcp *dhcp, u16_t value);
static void dhcp_option_long(struct dhcp *dhcp, u32_t value);
 
static void dhcp_option_trailer(struct dhcp *dhcp);


 
static err_t
dhcp_inc_pcb_refcount(void)
{
  if (dhcp_pcb_refcount == 0) {
    do { if (!(dhcp_pcb == 0)) { ; }} while(0);

     
    dhcp_pcb = udp_new();

    if (dhcp_pcb == 0) {
      return ERR_MEM;
    }

    ((dhcp_pcb)->so_options |= (0x20U));

     
    udp_bind(dhcp_pcb, (&ip_addr_any), 68);
    udp_connect(dhcp_pcb, (&ip_addr_any), 67);
    udp_recv(dhcp_pcb, dhcp_recv, 0);
  }

  dhcp_pcb_refcount++;

  return ERR_OK;
}

 
static void
dhcp_dec_pcb_refcount(void)
{
  do { if (!((dhcp_pcb_refcount > 0))) { ; }} while(0);
  dhcp_pcb_refcount--;

  if (dhcp_pcb_refcount == 0) {
    udp_remove(dhcp_pcb);
    dhcp_pcb = 0;
  }
}












 
static void
dhcp_handle_nak(struct netif *netif)
{
  struct dhcp *dhcp = ((struct dhcp*)(netif)->client_data[(LWIP_NETIF_CLIENT_DATA_INDEX_DHCP)]);

  ;
  
 
  dhcp_set_state(dhcp, DHCP_STATE_BACKING_OFF);
   
  netif_set_addr(netif, ((&ip_addr_any)), ((&ip_addr_any)), ((&ip_addr_any)));
   
  dhcp_discover(netif);
}









 
static void
dhcp_check(struct netif *netif)
{
  struct dhcp *dhcp = ((struct dhcp*)(netif)->client_data[(LWIP_NETIF_CLIENT_DATA_INDEX_DHCP)]);
  err_t result;
  u16_t msecs;
  ;
  dhcp_set_state(dhcp, DHCP_STATE_CHECKING);
  
 
  result = etharp_query(netif, &dhcp->offered_ip_addr, 0);
  if (result != ERR_OK) {
    ;
  }
  if (dhcp->tries < 255) {
    dhcp->tries++;
  }
  msecs = 500;
  dhcp->request_timeout = (msecs + 500 - 1) / 500;
  ;
}





 
static void
dhcp_handle_offer(struct netif *netif)
{
  struct dhcp *dhcp = ((struct dhcp*)(netif)->client_data[(LWIP_NETIF_CLIENT_DATA_INDEX_DHCP)]);

  ;
   
  if ((dhcp_rx_options_given[2] != 0)) {
    (((&dhcp->server_ip_addr))->addr = (lwip_htonl((dhcp_rx_options_val[2]))));
    ;
     
    ((dhcp->offered_ip_addr). addr = (dhcp->msg_in->yiaddr). addr);
    ;

    dhcp_select(netif);
  } else {
    ;
  }
}








 
static err_t
dhcp_select(struct netif *netif)
{
  struct dhcp *dhcp = ((struct dhcp*)(netif)->client_data[(LWIP_NETIF_CLIENT_DATA_INDEX_DHCP)]);
  err_t result;
  u16_t msecs;
  u8_t i;

  ;
  dhcp_set_state(dhcp, DHCP_STATE_REQUESTING);

   
  result = dhcp_create_msg(netif, dhcp, 3);
  if (result == ERR_OK) {
    dhcp_option(dhcp, 57, 2);
    dhcp_option_short(dhcp, (netif->mtu));

     
    dhcp_option(dhcp, 50, 4);
    dhcp_option_long(dhcp, lwip_htonl(((&dhcp->offered_ip_addr)->addr)));

    dhcp_option(dhcp, 54, 4);
    dhcp_option_long(dhcp, lwip_htonl((((&dhcp->server_ip_addr))->addr)));

    dhcp_option(dhcp, 55, (sizeof(dhcp_discover_request_options)/sizeof((dhcp_discover_request_options)[0])));
    for (i = 0; i < (sizeof(dhcp_discover_request_options)/sizeof((dhcp_discover_request_options)[0])); i++) {
      dhcp_option_byte(dhcp, dhcp_discover_request_options[i]);
    }


    dhcp_option_trailer(dhcp);
     
    pbuf_realloc(dhcp->p_out, sizeof(struct dhcp_msg) - 68U + dhcp->options_out_len);

     
    udp_sendto_if_src(dhcp_pcb, dhcp->p_out, (&ip_addr_broadcast), 67, netif, (&ip_addr_any));
    dhcp_delete_msg(dhcp);
    ;
  } else {
    ;
  }
  if (dhcp->tries < 255) {
    dhcp->tries++;
  }
  msecs = (dhcp->tries < 6 ? 1 << dhcp->tries : 60) * 1000;
  dhcp->request_timeout = (msecs + 500 - 1) / 500;
  ;
  return result;
}




 
void
dhcp_coarse_tmr(void)
{
  struct netif *netif = netif_list;
  ;
   
  while (netif != 0) {
     
    struct dhcp *dhcp = ((struct dhcp*)(netif)->client_data[(LWIP_NETIF_CLIENT_DATA_INDEX_DHCP)]);
    if ((dhcp != 0) && (dhcp->state != DHCP_STATE_OFF)) {
       
      if (dhcp->t0_timeout && (++dhcp->lease_used == dhcp->t0_timeout)) {
        ;
         
        dhcp_release(netif);
        dhcp_discover(netif);
       
      } else if (dhcp->t2_rebind_time && (dhcp->t2_rebind_time-- == 1)) {
        ;
         
        dhcp_t2_timeout(netif);
       
      } else if (dhcp->t1_renew_time && (dhcp->t1_renew_time-- == 1)) {
        ;
         
        dhcp_t1_timeout(netif);
      }
    }
     
    netif = netif->next;
  }
}







 
void
dhcp_fine_tmr(void)
{
  struct netif *netif = netif_list;
   
  while (netif != 0) {
    struct dhcp *dhcp = ((struct dhcp*)(netif)->client_data[(LWIP_NETIF_CLIENT_DATA_INDEX_DHCP)]);
     
    if (dhcp != 0) {
       
      if (dhcp->request_timeout > 1) {
        dhcp->request_timeout--;
      }
      else if (dhcp->request_timeout == 1) {
        dhcp->request_timeout--;
         
        ;
         
        dhcp_timeout(netif);
      }
    }
     
    netif = netif->next;
  }
}








 
static void
dhcp_timeout(struct netif *netif)
{
  struct dhcp *dhcp = ((struct dhcp*)(netif)->client_data[(LWIP_NETIF_CLIENT_DATA_INDEX_DHCP)]);

  ;
   
  if ((dhcp->state == DHCP_STATE_BACKING_OFF) || (dhcp->state == DHCP_STATE_SELECTING)) {
    ;
    dhcp_discover(netif);
   
  } else if (dhcp->state == DHCP_STATE_REQUESTING) {
    ;
    if (dhcp->tries <= 5) {
      dhcp_select(netif);
    } else {
      ;
      dhcp_release(netif);
      dhcp_discover(netif);
    }
   
  } else if (dhcp->state == DHCP_STATE_CHECKING) {
    ;
    if (dhcp->tries <= 1) {
      dhcp_check(netif);
    
 
    } else {
       
      dhcp_bind(netif);
    }
  } else if (dhcp->state == DHCP_STATE_REBOOTING) {
    if (dhcp->tries < 2) {
      dhcp_reboot(netif);
    } else {
      dhcp_discover(netif);
    }
  }
}





 
static void
dhcp_t1_timeout(struct netif *netif)
{
  struct dhcp *dhcp = ((struct dhcp*)(netif)->client_data[(LWIP_NETIF_CLIENT_DATA_INDEX_DHCP)]);

  ;
  if ((dhcp->state == DHCP_STATE_REQUESTING) || (dhcp->state == DHCP_STATE_BOUND) ||
      (dhcp->state == DHCP_STATE_RENEWING)) {
    
 
    ;
    
 
    dhcp_renew(netif);
     
    if (((dhcp->t2_timeout - dhcp->lease_used) / 2) >= ((60 + 60 / 2) / 60))
    {
       dhcp->t1_renew_time = ((dhcp->t2_timeout - dhcp->lease_used) / 2);
    }
  }
}





 
static void
dhcp_t2_timeout(struct netif *netif)
{
  struct dhcp *dhcp = ((struct dhcp*)(netif)->client_data[(LWIP_NETIF_CLIENT_DATA_INDEX_DHCP)]);

  ;
  if ((dhcp->state == DHCP_STATE_REQUESTING) || (dhcp->state == DHCP_STATE_BOUND) ||
      (dhcp->state == DHCP_STATE_RENEWING) || (dhcp->state == DHCP_STATE_REBINDING)) {
     
    ;
    
 
    dhcp_rebind(netif);
     
    if (((dhcp->t0_timeout - dhcp->lease_used) / 2) >= ((60 + 60 / 2) / 60))
    {
       dhcp->t2_rebind_time = ((dhcp->t0_timeout - dhcp->lease_used) / 2);
    }
  }
}





 
static void
dhcp_handle_ack(struct netif *netif)
{
  struct dhcp *dhcp = ((struct dhcp*)(netif)->client_data[(LWIP_NETIF_CLIENT_DATA_INDEX_DHCP)]);


   
  ((&dhcp->offered_sn_mask)->addr = 0);
  ((&dhcp->offered_gw_addr)->addr = 0);

   
  if ((dhcp_rx_options_given[3] != 0)) {
     
    dhcp->offered_t0_lease = (dhcp_rx_options_val[3]);
  }
   
  if ((dhcp_rx_options_given[4] != 0)) {
     
    dhcp->offered_t1_renew = (dhcp_rx_options_val[4]);
  } else {
     
    dhcp->offered_t1_renew = dhcp->offered_t0_lease / 2;
  }

   
  if ((dhcp_rx_options_given[5] != 0)) {
     
    dhcp->offered_t2_rebind = (dhcp_rx_options_val[5]);
  } else {
     
    dhcp->offered_t2_rebind = (dhcp->offered_t0_lease * 7U) / 8U;
  }

   
  ((dhcp->offered_ip_addr). addr = (dhcp->msg_in->yiaddr). addr);


   
  if ((dhcp_rx_options_given[6] != 0)) {
     
    ((&dhcp->offered_sn_mask)->addr = (lwip_htonl((dhcp_rx_options_val[6]))));
    dhcp->subnet_mask_given = 1;
  } else {
    dhcp->subnet_mask_given = 0;
  }

   
  if ((dhcp_rx_options_given[7] != 0)) {
    ((&dhcp->offered_gw_addr)->addr = (lwip_htonl((dhcp_rx_options_val[7]))));
  }


}








 
void
dhcp_set_struct(struct netif *netif, struct dhcp *dhcp)
{
  do { if (!(netif != 0)) { ; }} while(0);
  do { if (!(dhcp != 0)) { ; }} while(0);
  do { if (!(((struct dhcp*)(netif)->client_data[(LWIP_NETIF_CLIENT_DATA_INDEX_DHCP)]) == 0)) { ; }} while(0);

   
  memset(dhcp, 0, sizeof(struct dhcp));
   
  (netif)->client_data[(LWIP_NETIF_CLIENT_DATA_INDEX_DHCP)] = (dhcp);
}









 
void dhcp_cleanup(struct netif *netif)
{
  do { if (!(netif != 0)) { ; }} while(0);

  if (((struct dhcp*)(netif)->client_data[(LWIP_NETIF_CLIENT_DATA_INDEX_DHCP)]) != 0) {
    mem_free(((struct dhcp*)(netif)->client_data[(LWIP_NETIF_CLIENT_DATA_INDEX_DHCP)]));
    (netif)->client_data[(LWIP_NETIF_CLIENT_DATA_INDEX_DHCP)] = (0);
  }
}













 
err_t
dhcp_start(struct netif *netif)
{
  struct dhcp *dhcp;
  err_t result;

  do { if (!((netif != 0))) { ; return ERR_ARG;;}} while(0);
  do { if (!((((netif)->flags & 0x01U) ? (u8_t)1 : (u8_t)0))) { ; return ERR_ARG;;}} while(0);
  dhcp = ((struct dhcp*)(netif)->client_data[(LWIP_NETIF_CLIENT_DATA_INDEX_DHCP)]);
  ;

   
  if (netif->mtu < 576) {
    ;
    return ERR_MEM;
  }

   
  if (dhcp == 0) {
    ;
    dhcp = (struct dhcp *)mem_malloc(sizeof(struct dhcp));
    if (dhcp == 0) {
      ;
      return ERR_MEM;
    }

     
    (netif)->client_data[(LWIP_NETIF_CLIENT_DATA_INDEX_DHCP)] = (dhcp);
    ;
   
  } else {
    ;
    do { if (!(dhcp->p_out == 0)) { ; }} while(0);
    do { if (!(dhcp->msg_in == 0)) { ; }} while(0);

    if (dhcp->pcb_allocated != 0) {
      dhcp_dec_pcb_refcount();  
    }
     
  }

   
  memset(dhcp, 0, sizeof(struct dhcp));
   

  ;

  if (dhcp_inc_pcb_refcount() != ERR_OK) {  
    return ERR_MEM;
  }
  dhcp->pcb_allocated = 1;



   
  result = dhcp_discover(netif);
  if (result != ERR_OK) {
     
    dhcp_stop(netif);
    return ERR_MEM;
  }
  return result;
}










 
void
dhcp_inform(struct netif *netif)
{
  struct dhcp dhcp;
  err_t result = ERR_OK;

  do { if (!((netif != 0))) { ; return;;}} while(0);

  if (dhcp_inc_pcb_refcount() != ERR_OK) {  
    return;
  }

  memset(&dhcp, 0, sizeof(struct dhcp));
  dhcp_set_state(&dhcp, DHCP_STATE_INFORMING);

   
  result = dhcp_create_msg(netif, &dhcp, 8);
  if (result == ERR_OK) {
    dhcp_option(&dhcp, 57, 2);
    dhcp_option_short(&dhcp, (netif->mtu));

    dhcp_option_trailer(&dhcp);

    pbuf_realloc(dhcp.p_out, sizeof(struct dhcp_msg) - 68U + dhcp.options_out_len);

    ;

    udp_sendto_if(dhcp_pcb, dhcp.p_out, (&ip_addr_broadcast), 67, netif);

    dhcp_delete_msg(&dhcp);
  } else {
    ;
  }

  dhcp_dec_pcb_refcount();  
}





 
void
dhcp_network_changed(struct netif *netif)
{
  struct dhcp *dhcp = ((struct dhcp*)(netif)->client_data[(LWIP_NETIF_CLIENT_DATA_INDEX_DHCP)]);

  if (!dhcp)
    return;
  switch (dhcp->state) {
  case DHCP_STATE_REBINDING:
  case DHCP_STATE_RENEWING:
  case DHCP_STATE_BOUND:
  case DHCP_STATE_REBOOTING:
    dhcp->tries = 0;
    dhcp_reboot(netif);
    break;
  case DHCP_STATE_OFF:
     
    break;
  default:
    

 
     
    dhcp->tries = 0;
    dhcp_discover(netif);
    break;
  }
}







 
void
dhcp_arp_reply(struct netif *netif, const ip4_addr_t *addr)
{
  struct dhcp *dhcp;

  do { if (!((netif != 0))) { ; return;;}} while(0);
  dhcp = ((struct dhcp*)(netif)->client_data[(LWIP_NETIF_CLIENT_DATA_INDEX_DHCP)]);
  ;
   
  if ((dhcp != 0) && (dhcp->state == DHCP_STATE_CHECKING)) {
    ;
    
 
    if (((addr)->addr == (&dhcp->offered_ip_addr)->addr)) {
       
      ;
      dhcp_decline(netif);
    }
  }
}









 
static err_t
dhcp_decline(struct netif *netif)
{
  struct dhcp *dhcp = ((struct dhcp*)(netif)->client_data[(LWIP_NETIF_CLIENT_DATA_INDEX_DHCP)]);
  err_t result = ERR_OK;
  u16_t msecs;
  ;
  dhcp_set_state(dhcp, DHCP_STATE_BACKING_OFF);
   
  result = dhcp_create_msg(netif, dhcp, 4);
  if (result == ERR_OK) {
    dhcp_option(dhcp, 50, 4);
    dhcp_option_long(dhcp, lwip_htonl(((&dhcp->offered_ip_addr)->addr)));

    dhcp_option_trailer(dhcp);
     
    pbuf_realloc(dhcp->p_out, sizeof(struct dhcp_msg) - 68U + dhcp->options_out_len);

     
    udp_sendto_if_src(dhcp_pcb, dhcp->p_out, (&ip_addr_broadcast), 67, netif, (&ip_addr_any));
    dhcp_delete_msg(dhcp);
    ;
  } else {
    ;
  }
  if (dhcp->tries < 255) {
    dhcp->tries++;
  }
  msecs = 10*1000;
  dhcp->request_timeout = (msecs + 500 - 1) / 500;
  ;
  return result;
}






 
static err_t
dhcp_discover(struct netif *netif)
{
  struct dhcp *dhcp = ((struct dhcp*)(netif)->client_data[(LWIP_NETIF_CLIENT_DATA_INDEX_DHCP)]);
  err_t result = ERR_OK;
  u16_t msecs;
  u8_t i;
  ;
  ((&dhcp->offered_ip_addr)->addr = ((u32_t)0x00000000UL));
  dhcp_set_state(dhcp, DHCP_STATE_SELECTING);
   
  result = dhcp_create_msg(netif, dhcp, 1);
  if (result == ERR_OK) {
    ;

    dhcp_option(dhcp, 57, 2);
    dhcp_option_short(dhcp, (netif->mtu));

    dhcp_option(dhcp, 55, (sizeof(dhcp_discover_request_options)/sizeof((dhcp_discover_request_options)[0])));
    for (i = 0; i < (sizeof(dhcp_discover_request_options)/sizeof((dhcp_discover_request_options)[0])); i++) {
      dhcp_option_byte(dhcp, dhcp_discover_request_options[i]);
    }
    dhcp_option_trailer(dhcp);

    ;
    pbuf_realloc(dhcp->p_out, sizeof(struct dhcp_msg) - 68U + dhcp->options_out_len);

    ;
    udp_sendto_if_src(dhcp_pcb, dhcp->p_out, (&ip_addr_broadcast), 67, netif, (&ip_addr_any));
    ;
    dhcp_delete_msg(dhcp);
    ;
  } else {
    ;
  }
  if (dhcp->tries < 255) {
    dhcp->tries++;
  }
  msecs = (dhcp->tries < 6 ? 1 << dhcp->tries : 60) * 1000;
  dhcp->request_timeout = (msecs + 500 - 1) / 500;
  ;
  return result;
}






 
static void
dhcp_bind(struct netif *netif)
{
  u32_t timeout;
  struct dhcp *dhcp;
  ip4_addr_t sn_mask, gw_addr;
  do { if (!((netif != 0))) { ; return;;}} while(0);
  dhcp = ((struct dhcp*)(netif)->client_data[(LWIP_NETIF_CLIENT_DATA_INDEX_DHCP)]);
  do { if (!((dhcp != 0))) { ; return;;}} while(0);
  ;

   
  dhcp->lease_used = 0;

  if (dhcp->offered_t0_lease != 0xffffffffUL) {
      
     ;
     timeout = (dhcp->offered_t0_lease + 60 / 2) / 60;
     if (timeout > 0xffff) {
       timeout = 0xffff;
     }
     dhcp->t0_timeout = (u16_t)timeout;
     if (dhcp->t0_timeout == 0) {
       dhcp->t0_timeout = 1;
     }
     ;
  }

   
  if (dhcp->offered_t1_renew != 0xffffffffUL) {
     
    ;
    timeout = (dhcp->offered_t1_renew + 60 / 2) / 60;
    if (timeout > 0xffff) {
      timeout = 0xffff;
    }
    dhcp->t1_timeout = (u16_t)timeout;
    if (dhcp->t1_timeout == 0) {
      dhcp->t1_timeout = 1;
    }
    ;
    dhcp->t1_renew_time = dhcp->t1_timeout;
  }
   
  if (dhcp->offered_t2_rebind != 0xffffffffUL) {
    ;
    timeout = (dhcp->offered_t2_rebind + 60 / 2) / 60;
    if (timeout > 0xffff) {
      timeout = 0xffff;
    }
    dhcp->t2_timeout = (u16_t)timeout;
    if (dhcp->t2_timeout == 0) {
      dhcp->t2_timeout = 1;
    }
    ;
    dhcp->t2_rebind_time = dhcp->t2_timeout;
  }

   
  if ((dhcp->t1_timeout >= dhcp->t2_timeout) && (dhcp->t2_timeout > 0)) {
    dhcp->t1_timeout = 0;
  }

  if (dhcp->subnet_mask_given) {
     
    ((sn_mask). addr = (dhcp->offered_sn_mask). addr);
  } else {
     
    u8_t first_octet = (((const u8_t*)(&(&dhcp->offered_ip_addr)->addr))[0]);
    if (first_octet <= 127) {
      ((&sn_mask)->addr = (((((0xff000000UL) & 0xff) << 24) | (((0xff000000UL) & 0xff00) << 8) | (((0xff000000UL) & 0xff0000UL) >> 8) | (((0xff000000UL) & 0xff000000UL) >> 24))));
    } else if (first_octet >= 192) {
      ((&sn_mask)->addr = (((((0xffffff00UL) & 0xff) << 24) | (((0xffffff00UL) & 0xff00) << 8) | (((0xffffff00UL) & 0xff0000UL) >> 8) | (((0xffffff00UL) & 0xff000000UL) >> 24))));
    } else {
      ((&sn_mask)->addr = (((((0xffff0000UL) & 0xff) << 24) | (((0xffff0000UL) & 0xff00) << 8) | (((0xffff0000UL) & 0xff0000UL) >> 8) | (((0xffff0000UL) & 0xff000000UL) >> 24))));
    }
  }

  ((gw_addr). addr = (dhcp->offered_gw_addr). addr);
   
  if (((gw_addr). addr == ((u32_t)0x00000000UL))) {
     
    do { ((&gw_addr)->addr = ((&dhcp->offered_ip_addr)->addr) & ((&sn_mask)->addr)); } while(0);
     
    ((&gw_addr)->addr = (((&gw_addr)->addr) | ((((0x00000001UL) & 0xff) << 24) | (((0x00000001UL) & 0xff00) << 8) | (((0x00000001UL) & 0xff0000UL) >> 8) | (((0x00000001UL) & 0xff000000UL) >> 24))));
  }


  ;
  
 
  dhcp_set_state(dhcp, DHCP_STATE_BOUND);

  netif_set_addr(netif, &dhcp->offered_ip_addr, &sn_mask, &gw_addr);
   
}






 
err_t
dhcp_renew(struct netif *netif)
{
  struct dhcp *dhcp = ((struct dhcp*)(netif)->client_data[(LWIP_NETIF_CLIENT_DATA_INDEX_DHCP)]);
  err_t result;
  u16_t msecs;
  u8_t i;
  ;
  dhcp_set_state(dhcp, DHCP_STATE_RENEWING);

   
  result = dhcp_create_msg(netif, dhcp, 3);
  if (result == ERR_OK) {
    dhcp_option(dhcp, 57, 2);
    dhcp_option_short(dhcp, (netif->mtu));

    dhcp_option(dhcp, 55, (sizeof(dhcp_discover_request_options)/sizeof((dhcp_discover_request_options)[0])));
    for (i = 0; i < (sizeof(dhcp_discover_request_options)/sizeof((dhcp_discover_request_options)[0])); i++) {
      dhcp_option_byte(dhcp, dhcp_discover_request_options[i]);
    }


     
    dhcp_option_trailer(dhcp);

    pbuf_realloc(dhcp->p_out, sizeof(struct dhcp_msg) - 68U + dhcp->options_out_len);

    udp_sendto_if(dhcp_pcb, dhcp->p_out, &dhcp->server_ip_addr, 67, netif);
    dhcp_delete_msg(dhcp);

    ;
  } else {
    ;
  }
  if (dhcp->tries < 255) {
    dhcp->tries++;
  }
   
  msecs = dhcp->tries < 10 ? dhcp->tries * 2000 : 20 * 1000;
  dhcp->request_timeout = (msecs + 500 - 1) / 500;
  ;
  return result;
}





 
static err_t
dhcp_rebind(struct netif *netif)
{
  struct dhcp *dhcp = ((struct dhcp*)(netif)->client_data[(LWIP_NETIF_CLIENT_DATA_INDEX_DHCP)]);
  err_t result;
  u16_t msecs;
  u8_t i;
  ;
  dhcp_set_state(dhcp, DHCP_STATE_REBINDING);

   
  result = dhcp_create_msg(netif, dhcp, 3);
  if (result == ERR_OK) {
    dhcp_option(dhcp, 57, 2);
    dhcp_option_short(dhcp, (netif->mtu));

    dhcp_option(dhcp, 55, (sizeof(dhcp_discover_request_options)/sizeof((dhcp_discover_request_options)[0])));
    for (i = 0; i < (sizeof(dhcp_discover_request_options)/sizeof((dhcp_discover_request_options)[0])); i++) {
      dhcp_option_byte(dhcp, dhcp_discover_request_options[i]);
    }


    dhcp_option_trailer(dhcp);

    pbuf_realloc(dhcp->p_out, sizeof(struct dhcp_msg) - 68U + dhcp->options_out_len);

     
    udp_sendto_if(dhcp_pcb, dhcp->p_out, (&ip_addr_broadcast), 67, netif);
    dhcp_delete_msg(dhcp);
    ;
  } else {
    ;
  }
  if (dhcp->tries < 255) {
    dhcp->tries++;
  }
  msecs = dhcp->tries < 10 ? dhcp->tries * 1000 : 10 * 1000;
  dhcp->request_timeout = (msecs + 500 - 1) / 500;
  ;
  return result;
}





 
static err_t
dhcp_reboot(struct netif *netif)
{
  struct dhcp *dhcp = ((struct dhcp*)(netif)->client_data[(LWIP_NETIF_CLIENT_DATA_INDEX_DHCP)]);
  err_t result;
  u16_t msecs;
  u8_t i;
  ;
  dhcp_set_state(dhcp, DHCP_STATE_REBOOTING);

   
  result = dhcp_create_msg(netif, dhcp, 3);
  if (result == ERR_OK) {
    dhcp_option(dhcp, 57, 2);
    dhcp_option_short(dhcp, 576);

    dhcp_option(dhcp, 50, 4);
    dhcp_option_long(dhcp, lwip_htonl(((&dhcp->offered_ip_addr)->addr)));

    dhcp_option(dhcp, 55, (sizeof(dhcp_discover_request_options)/sizeof((dhcp_discover_request_options)[0])));
    for (i = 0; i < (sizeof(dhcp_discover_request_options)/sizeof((dhcp_discover_request_options)[0])); i++) {
      dhcp_option_byte(dhcp, dhcp_discover_request_options[i]);
    }

    dhcp_option_trailer(dhcp);

    pbuf_realloc(dhcp->p_out, sizeof(struct dhcp_msg) - 68U + dhcp->options_out_len);

     
    udp_sendto_if(dhcp_pcb, dhcp->p_out, (&ip_addr_broadcast), 67, netif);
    dhcp_delete_msg(dhcp);
    ;
  } else {
    ;
  }
  if (dhcp->tries < 255) {
    dhcp->tries++;
  }
  msecs = dhcp->tries < 10 ? dhcp->tries * 1000 : 10 * 1000;
  dhcp->request_timeout = (msecs + 500 - 1) / 500;
  ;
  return result;
}







 
err_t
dhcp_release(struct netif *netif)
{
  struct dhcp *dhcp = ((struct dhcp*)(netif)->client_data[(LWIP_NETIF_CLIENT_DATA_INDEX_DHCP)]);
  err_t result;
  ip_addr_t server_ip_addr;
  u8_t is_dhcp_supplied_address;

  ;
  if (dhcp == 0) {
    return ERR_ARG;
  }
  ((server_ip_addr). addr = (dhcp->server_ip_addr). addr);

  is_dhcp_supplied_address = dhcp_supplied_address(netif);

   
  dhcp_set_state(dhcp, DHCP_STATE_OFF);
   
  ((&dhcp->server_ip_addr)->addr = 0);
  ((&dhcp->offered_ip_addr)->addr = 0);
  ((&dhcp->offered_sn_mask)->addr = 0);
  ((&dhcp->offered_gw_addr)->addr = 0);
  dhcp->offered_t0_lease = dhcp->offered_t1_renew = dhcp->offered_t2_rebind = 0;
  dhcp->t1_renew_time = dhcp->t2_rebind_time = dhcp->lease_used = dhcp->t0_timeout = 0;

  if (!is_dhcp_supplied_address) {
     
    return ERR_OK;
  }

   
  result = dhcp_create_msg(netif, dhcp, 7);
  if (result == ERR_OK) {
    dhcp_option(dhcp, 54, 4);
    dhcp_option_long(dhcp, lwip_htonl((((&server_ip_addr))->addr)));

    dhcp_option_trailer(dhcp);

    pbuf_realloc(dhcp->p_out, sizeof(struct dhcp_msg) - 68U + dhcp->options_out_len);

    udp_sendto_if(dhcp_pcb, dhcp->p_out, &server_ip_addr, 67, netif);
    dhcp_delete_msg(dhcp);
    ;
  } else {
     
    ;
  }
   
  netif_set_addr(netif, ((&ip_addr_any)), ((&ip_addr_any)), ((&ip_addr_any)));

  return result;
}






 
void
dhcp_stop(struct netif *netif)
{
  struct dhcp *dhcp;
  do { if (!((netif != 0))) { ; return;;}} while(0);
  dhcp = ((struct dhcp*)(netif)->client_data[(LWIP_NETIF_CLIENT_DATA_INDEX_DHCP)]);

  ;
   
  if (dhcp != 0) {

    do { if (!(dhcp->msg_in == 0)) { ; }} while(0);
    dhcp_set_state(dhcp, DHCP_STATE_OFF);

    if (dhcp->pcb_allocated != 0) {
      dhcp_dec_pcb_refcount();  
      dhcp->pcb_allocated = 0;
    }
  }
}





 
static void
dhcp_set_state(struct dhcp *dhcp, u8_t new_state)
{
  if (new_state != dhcp->state) {
    dhcp->state = new_state;
    dhcp->tries = 0;
    dhcp->request_timeout = 0;
  }
}





 
static void
dhcp_option(struct dhcp *dhcp, u8_t option_type, u8_t option_len)
{
  do { if (!(dhcp->options_out_len + 2U + option_len <= 68U)) { ; }} while(0);
  dhcp->msg_out->options[dhcp->options_out_len++] = option_type;
  dhcp->msg_out->options[dhcp->options_out_len++] = option_len;
}



 
static void
dhcp_option_byte(struct dhcp *dhcp, u8_t value)
{
  do { if (!(dhcp->options_out_len < 68U)) { ; }} while(0);
  dhcp->msg_out->options[dhcp->options_out_len++] = value;
}

static void
dhcp_option_short(struct dhcp *dhcp, u16_t value)
{
  do { if (!(dhcp->options_out_len + 2U <= 68U)) { ; }} while(0);
  dhcp->msg_out->options[dhcp->options_out_len++] = (u8_t)((value & 0xff00U) >> 8);
  dhcp->msg_out->options[dhcp->options_out_len++] = (u8_t) (value & 0x00ffU);
}

static void
dhcp_option_long(struct dhcp *dhcp, u32_t value)
{
  do { if (!(dhcp->options_out_len + 4U <= 68U)) { ; }} while(0);
  dhcp->msg_out->options[dhcp->options_out_len++] = (u8_t)((value & 0xff000000UL) >> 24);
  dhcp->msg_out->options[dhcp->options_out_len++] = (u8_t)((value & 0x00ff0000UL) >> 16);
  dhcp->msg_out->options[dhcp->options_out_len++] = (u8_t)((value & 0x0000ff00UL) >> 8);
  dhcp->msg_out->options[dhcp->options_out_len++] = (u8_t)((value & 0x000000ffUL));
}











 
static err_t
dhcp_parse_reply(struct dhcp *dhcp, struct pbuf *p)
{
  u8_t *options;
  u16_t offset;
  u16_t offset_max;
  u16_t options_idx;
  u16_t options_idx_max;
  struct pbuf *q;
  int parse_file_as_options = 0;
  int parse_sname_as_options = 0;

   
  (memset(dhcp_rx_options_given, 0, sizeof(dhcp_rx_options_given)));
   
  if (p->len < 44U) {
    return ERR_BUF;
  }
  dhcp->msg_in = (struct dhcp_msg *)p->payload;

   

   
  options_idx = (236U + 4U);
   
  options_idx_max = p->tot_len;
again:
  q = p;
  while ((q != 0) && (options_idx >= q->len)) {
    options_idx -= q->len;
    options_idx_max -= q->len;
    q = q->next;
  }
  if (q == 0) {
    return ERR_BUF;
  }
  offset = options_idx;
  offset_max = options_idx_max;
  options = (u8_t*)q->payload;
   
  while ((q != 0) && (options[offset] != 255) && (offset < offset_max)) {
    u8_t op = options[offset];
    u8_t len;
    u8_t decode_len = 0;
    int decode_idx = -1;
    u16_t val_offset = offset + 2;
     
    if ((offset + 1) < q->len) {
      len = options[offset + 1];
    } else {
      len = (q->next != 0 ? ((u8_t*)q->next->payload)[0] : 0);
    }
     
    decode_len = len;
    switch(op) {
       
      case(0):
         
        decode_len = len = 0;
         
        offset--;
        break;
      case(1):
        do { if (!(len == 4)) { ; return ERR_VAL;;}} while(0);
        decode_idx = 6;
        break;
      case(3):
        decode_len = 4;  
        do { if (!(len >= decode_len)) { ; return ERR_VAL;;}} while(0);
        decode_idx = 7;
        break;
      case(6):
         
        do { if (!(len % 4 == 0)) { ; return ERR_VAL;;}} while(0);
         
        decode_len = (((len) < (4 * 2)) ? (len) : (4 * 2));
        do { if (!(len >= decode_len)) { ; return ERR_VAL;;}} while(0);
        decode_idx = 8;
        break;
      case(51):
        do { if (!(len == 4)) { ; return ERR_VAL;;}} while(0);
        decode_idx = 3;
        break;
      case(52):
        do { if (!(len == 1)) { ; return ERR_VAL;;}} while(0);
        decode_idx = 0;
        break;
      case(53):
        do { if (!(len == 1)) { ; return ERR_VAL;;}} while(0);
        decode_idx = 1;
        break;
      case(54):
        do { if (!(len == 4)) { ; return ERR_VAL;;}} while(0);
        decode_idx = 2;
        break;
      case(58):
        do { if (!(len == 4)) { ; return ERR_VAL;;}} while(0);
        decode_idx = 4;
        break;
      case(59):
        do { if (!(len == 4)) { ; return ERR_VAL;;}} while(0);
        decode_idx = 5;
        break;
      default:
        decode_len = 0;
        ;
        break;
    }
    offset += len + 2;
    if (decode_len > 0) {
      u32_t value = 0;
      u16_t copy_len;
decode_next:
      do { if (!(decode_idx >= 0 && decode_idx < (8 + 2))) { ; }} while(0);
      if (!(dhcp_rx_options_given[decode_idx] != 0)) {
        copy_len = (((decode_len) < (4)) ? (decode_len) : (4));
        if (pbuf_copy_partial(q, &value, copy_len, val_offset) != copy_len) {
          return ERR_BUF;
        }
        if (decode_len > 4) {
           
          do { if (!(decode_len % 4 == 0)) { ; return ERR_VAL;;}} while(0);
          (dhcp_rx_options_given[decode_idx] = 1);
          (dhcp_rx_options_val[decode_idx] = (lwip_htonl(value)));
          decode_len -= 4;
          val_offset += 4;
          decode_idx++;
          goto decode_next;
        } else if (decode_len == 4) {
          value = lwip_htonl(value);
        } else {
          do { if (!(decode_len == 1)) { ; return ERR_VAL;;}} while(0);
          value = ((u8_t*)&value)[0];
        }
        (dhcp_rx_options_given[decode_idx] = 1);
        (dhcp_rx_options_val[decode_idx] = (value));
      }
    }
    if (offset >= q->len) {
      offset -= q->len;
      offset_max -= q->len;
      if ((offset < offset_max) && offset_max) {
        q = q->next;
        do { if (!(q)) { ; }} while(0);
        options = (u8_t*)q->payload;
      } else {
         
        break;
      }
    }
  }
   
  if ((dhcp_rx_options_given[0] != 0)) {
    u32_t overload = (dhcp_rx_options_val[0]);
    (dhcp_rx_options_given[0] = 0);
    if (overload == 1) {
      parse_file_as_options = 1;
      ;
    } else if (overload == 2) {
      parse_sname_as_options = 1;
      ;
    } else if (overload == 3) {
      parse_sname_as_options = 1;
      parse_file_as_options = 1;
      ;
    } else {
      ;
    }
  }
  if (parse_file_as_options) {
     
    parse_file_as_options = 0;
    options_idx = 108U;
    options_idx_max = 108U + 128U;
    goto again;
  } else if (parse_sname_as_options) {
    parse_sname_as_options = 0;
    options_idx = 44U;
    options_idx_max = 44U + 64U;
    goto again;
  }
  return ERR_OK;
}



 
static void
dhcp_recv(void *arg, struct udp_pcb *pcb, struct pbuf *p, const ip_addr_t *addr, u16_t port)
{
  struct netif *netif = (ip_data . current_input_netif);
  struct dhcp *dhcp = ((struct dhcp*)(netif)->client_data[(LWIP_NETIF_CLIENT_DATA_INDEX_DHCP)]);
  struct dhcp_msg *reply_msg = (struct dhcp_msg *)p->payload;
  u8_t msg_type;
  u8_t i;

  (void)arg;

   
  if ((dhcp == 0) || (dhcp->pcb_allocated == 0)) {
    goto free_pbuf_and_return;
  }

  do { if (!(1)) { ; }} while(0);

  ;
  ;
  ;
   
  (void)pcb;
  (void)addr;
  (void)port;

  do { if (!(dhcp->msg_in == 0)) { ; }} while(0);

  if (p->len < 44) {
    ;
    goto free_pbuf_and_return;
  }

  if (reply_msg->op != 2) {
    ;
    goto free_pbuf_and_return;
  }
   
  for (i = 0; i < netif->hwaddr_len && i < 6U && i < 16U; i++) {
    if (netif->hwaddr[i] != reply_msg->chaddr[i]) {
      ;
      goto free_pbuf_and_return;
    }
  }
   
  if (lwip_htonl(reply_msg->xid) != dhcp->xid) {
    ;
    goto free_pbuf_and_return;
  }
   
  if (dhcp_parse_reply(dhcp, p) != ERR_OK) {
    ;
    goto free_pbuf_and_return;
  }

  ;
   
  if (!(dhcp_rx_options_given[1] != 0)) {
    ;
    goto free_pbuf_and_return;
  }

   
  msg_type = (u8_t)(dhcp_rx_options_val[1]);
   
  if (msg_type == 5) {
    ;
     
    if (dhcp->state == DHCP_STATE_REQUESTING) {
      dhcp_handle_ack(netif);
      if ((netif->flags & 0x08U) != 0) {
         
        dhcp_check(netif);
      } else {
         
        dhcp_bind(netif);
      }
    }
     
    else if ((dhcp->state == DHCP_STATE_REBOOTING) || (dhcp->state == DHCP_STATE_REBINDING) ||
             (dhcp->state == DHCP_STATE_RENEWING)) {
      dhcp_handle_ack(netif);
      dhcp_bind(netif);
    }
  }
   
  else if ((msg_type == 6) &&
    ((dhcp->state == DHCP_STATE_REBOOTING) || (dhcp->state == DHCP_STATE_REQUESTING) ||
     (dhcp->state == DHCP_STATE_REBINDING) || (dhcp->state == DHCP_STATE_RENEWING  ))) {
    ;
    dhcp_handle_nak(netif);
  }
   
  else if ((msg_type == 2) && (dhcp->state == DHCP_STATE_SELECTING)) {
    ;
    dhcp->request_timeout = 0;
     
    dhcp_handle_offer(netif);
  }

free_pbuf_and_return:
  if (dhcp != 0) {
    dhcp->msg_in = 0;
  }
  pbuf_free(p);
}







 
static err_t
dhcp_create_msg(struct netif *netif, struct dhcp *dhcp, u8_t message_type)
{
  u16_t i;
  


 
  static u32_t xid;
  do { if (!((netif != 0))) { ; return ERR_ARG;;}} while(0);
  do { if (!((dhcp != 0))) { ; return ERR_VAL;;}} while(0);
  do { if (!(dhcp->p_out == 0)) { ; }} while(0);
  do { if (!(dhcp->msg_out == 0)) { ; }} while(0);
  dhcp->p_out = pbuf_alloc(PBUF_TRANSPORT, sizeof(struct dhcp_msg), PBUF_RAM);
  if (dhcp->p_out == 0) {
    ;
    return ERR_MEM;
  }
  do { if (!((dhcp->p_out->len >= sizeof(struct dhcp_msg)))) { ; }} while(0);

   
  if (message_type != 3) {
     
    if (dhcp->tries == 0) {
      xid = ((u32_t)rand());
    }
    dhcp->xid = xid;
  }
  ;

  dhcp->msg_out = (struct dhcp_msg *)dhcp->p_out->payload;

  dhcp->msg_out->op = 1;
   
  dhcp->msg_out->htype = 1;
  dhcp->msg_out->hlen = netif->hwaddr_len;
  dhcp->msg_out->hops = 0;
  dhcp->msg_out->xid = lwip_htonl(dhcp->xid);
  dhcp->msg_out->secs = 0;
  
 
  dhcp->msg_out->flags = 0;
  ((&dhcp->msg_out->ciaddr)->addr = 0);
   
  if ((message_type == 8) || (message_type == 4) || (message_type == 7) ||
      ((message_type == 3) &&  
       ((dhcp->state== DHCP_STATE_RENEWING) || dhcp->state== DHCP_STATE_REBINDING))) {
    ((dhcp->msg_out->ciaddr). addr = (*((const ip4_addr_t*)(&((netif)->ip_addr)))). addr);
  }
  ((&dhcp->msg_out->yiaddr)->addr = 0);
  ((&dhcp->msg_out->siaddr)->addr = 0);
  ((&dhcp->msg_out->giaddr)->addr = 0);
  for (i = 0; i < 16U; i++) {
     
    dhcp->msg_out->chaddr[i] = (i < netif->hwaddr_len && i < 6U) ? netif->hwaddr[i] : 0 ;
  }
  for (i = 0; i < 64U; i++) {
    dhcp->msg_out->sname[i] = 0;
  }
  for (i = 0; i < 128U; i++) {
    dhcp->msg_out->file[i] = 0;
  }
  dhcp->msg_out->cookie = ((((0x63825363UL) & 0xff) << 24) | (((0x63825363UL) & 0xff00) << 8) | (((0x63825363UL) & 0xff0000UL) >> 8) | (((0x63825363UL) & 0xff000000UL) >> 24));
  dhcp->options_out_len = 0;
   
  for (i = 0; i < 68U; i++) {
    dhcp->msg_out->options[i] = (u8_t)i;  
  }
   
  dhcp_option(dhcp, 53, 1);
  dhcp_option_byte(dhcp, message_type);
  return ERR_OK;
}





 
static void
dhcp_delete_msg(struct dhcp *dhcp)
{
  do { if (!((dhcp != 0))) { ; return;;}} while(0);
  do { if (!(dhcp->p_out != 0)) { ; }} while(0);
  do { if (!(dhcp->msg_out != 0)) { ; }} while(0);
  if (dhcp->p_out != 0) {
    pbuf_free(dhcp->p_out);
  }
  dhcp->p_out = 0;
  dhcp->msg_out = 0;
}








 
static void
dhcp_option_trailer(struct dhcp *dhcp)
{
  do { if (!((dhcp != 0))) { ; return;;}} while(0);
  do { if (!(dhcp->msg_out != 0)) { ; }} while(0);
  do { if (!(dhcp->options_out_len < 68U)) { ; }} while(0);
  dhcp->msg_out->options[dhcp->options_out_len++] = 255;
   
  while (((dhcp->options_out_len < 68U) || (dhcp->options_out_len & 3)) &&
         (dhcp->options_out_len < 68U)) {
     
    dhcp->msg_out->options[dhcp->options_out_len++] = 0;
  }
}






 
u8_t
dhcp_supplied_address(const struct netif *netif)
{
  if ((netif != 0) && (((struct dhcp*)(netif)->client_data[(LWIP_NETIF_CLIENT_DATA_INDEX_DHCP)]) != 0)) {
    struct dhcp* dhcp = ((struct dhcp*)(netif)->client_data[(LWIP_NETIF_CLIENT_DATA_INDEX_DHCP)]);
    return (dhcp->state == DHCP_STATE_BOUND) || (dhcp->state == DHCP_STATE_RENEWING);
  }
  return 0;
}

