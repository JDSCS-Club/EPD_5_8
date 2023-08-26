


 









































































 































 





 































 




 





 













































 




 





 

 


 


 



 

 

 

 

 

 



 

 


 

 

 


 


 
    
    
 
 

 

     
     

 


 


 


 

 


 





 





 


   
   
   
   
   
   
   






 


 





 


 


 



 































 






 































 

































 































 
  

 
 


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






















 





 































 

 




 































 




 




 


 

u16_t lwip_htons(u16_t x);

u32_t lwip_htonl(u32_t x);

 



 






 

 
void  lwip_itoa(char* result, size_t bufsize, int number);
 
int   lwip_strnicmp(const char* str1, const char* str2, size_t len);
 
int   lwip_stricmp(const char* str1, const char* str2);
 
char* lwip_strnstr(const char* buffer, const char* token, size_t n);





 































 






 































 




 




 






























 





 































 




 







 


 
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





 






























 





































 






 































 




 





 
typedef u8_t sys_sem_t;
typedef u8_t sys_mutex_t;
typedef u8_t sys_mbox_t;





 
void sys_init(void);



 
u32_t sys_jiffies(void);





 
u32_t sys_now(void);

 



 




 







 








 
 

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






 


 

































 
struct pbuf *
pbuf_alloc(pbuf_layer layer, u16_t length, pbuf_type type)
{
  struct pbuf *p, *q, *r;
  u16_t offset;
  s32_t rem_len;  
  ;

   
  switch (layer) {
  case PBUF_TRANSPORT:
     
    offset = 0 + (14 + 0) + 20 + 20;
    break;
  case PBUF_IP:
     
    offset = 0 + (14 + 0) + 20;
    break;
  case PBUF_LINK:
     
    offset = 0 + (14 + 0);
    break;
  case PBUF_RAW_TX:
     
    offset = 0;
    break;
  case PBUF_RAW:
     
    offset = 0;
    break;
  default:
    do { if (!(0)) { ; }} while(0);
    return 0;
  }

  switch (type) {
  case PBUF_POOL:
     
    p = (struct pbuf *)memp_malloc(MEMP_PBUF_POOL);
    ;
    if (p == 0) {
      ;
      return 0;
    }
    p->type = type;
    p->next = 0;

     
    p->payload = ((void *)(((mem_ptr_t)((void *)((u8_t *)p + ((((sizeof(struct pbuf)) + 4 - 1U) & ~(4-1U)) + offset))) + 4 - 1) & ~(mem_ptr_t)(4-1)));
    do { if (!(((mem_ptr_t)p->payload % 4) == 0)) { ; }} while(0);
     
    p->tot_len = length;
     
    p->len = (((length) < (((((1500 - 40)) + 4 - 1U) & ~(4-1U)) - (((offset) + 4 - 1U) & ~(4-1U)))) ? (length) : (((((1500 - 40)) + 4 - 1U) & ~(4-1U)) - (((offset) + 4 - 1U) & ~(4-1U))));
    do { if (!(((u8_t*)p->payload + p->len <= (u8_t*)p + (((sizeof(struct pbuf)) + 4 - 1U) & ~(4-1U)) + ((((1500 - 40)) + 4 - 1U) & ~(4-1U))))) { ; }} while(0);
    do { if (!((((((1500 - 40)) + 4 - 1U) & ~(4-1U)) - (((offset) + 4 - 1U) & ~(4-1U))) > 0)) { ; }} while(0);
     
    p->ref = 1;

     

     
    r = p;
     
    rem_len = length - p->len;
     
    while (rem_len > 0) {
      q = (struct pbuf *)memp_malloc(MEMP_PBUF_POOL);
      if (q == 0) {
        ;
         
        pbuf_free(p);
         
        return 0;
      }
      q->type = type;
      q->flags = 0;
      q->next = 0;
       
      r->next = q;
       
      do { if (!(rem_len < 0xffff)) { ; }} while(0);
      q->tot_len = (u16_t)rem_len;
       
      q->len = ((((u16_t)rem_len) < (((((1500 - 40)) + 4 - 1U) & ~(4-1U)))) ? ((u16_t)rem_len) : (((((1500 - 40)) + 4 - 1U) & ~(4-1U))));
      q->payload = (void *)((u8_t *)q + (((sizeof(struct pbuf)) + 4 - 1U) & ~(4-1U)));
      do { if (!(((mem_ptr_t)q->payload % 4) == 0)) { ; }} while(0);
      do { if (!(((u8_t*)p->payload + p->len <= (u8_t*)p + (((sizeof(struct pbuf)) + 4 - 1U) & ~(4-1U)) + ((((1500 - 40)) + 4 - 1U) & ~(4-1U))))) { ; }} while(0);
      q->ref = 1;
       
      rem_len -= q->len;
       
      r = q;
    }
     
     

    break;
  case PBUF_RAM:
     
    p = (struct pbuf*)mem_malloc(((((((sizeof(struct pbuf)) + 4 - 1U) & ~(4-1U)) + offset) + 4 - 1U) & ~(4-1U)) + (((length) + 4 - 1U) & ~(4-1U)));
    if (p == 0) {
      return 0;
    }
     
    p->payload = ((void *)(((mem_ptr_t)((void *)((u8_t *)p + (((sizeof(struct pbuf)) + 4 - 1U) & ~(4-1U)) + offset)) + 4 - 1) & ~(mem_ptr_t)(4-1)));
    p->len = p->tot_len = length;
    p->next = 0;
    p->type = type;

    do { if (!(((mem_ptr_t)p->payload % 4) == 0)) { ; }} while(0);
    break;
   
  case PBUF_ROM:
   
  case PBUF_REF:
     
    p = (struct pbuf *)memp_malloc(MEMP_PBUF);
    if (p == 0) {
      ;
      return 0;
    }
     
    p->payload = 0;
    p->len = p->tot_len = length;
    p->next = 0;
    p->type = type;
    break;
  default:
    do { if (!(0)) { ; }} while(0);
    return 0;
  }
   
  p->ref = 1;
   
  p->flags = 0;
  ;
  return p;
}
















 
struct pbuf*
pbuf_alloced_custom(pbuf_layer l, u16_t length, pbuf_type type, struct pbuf_custom *p,
                    void *payload_mem, u16_t payload_mem_len)
{
  u16_t offset;
  ;

   
  switch (l) {
  case PBUF_TRANSPORT:
     
    offset = 0 + (14 + 0) + 20 + 20;
    break;
  case PBUF_IP:
     
    offset = 0 + (14 + 0) + 20;
    break;
  case PBUF_LINK:
     
    offset = 0 + (14 + 0);
    break;
  case PBUF_RAW_TX:
     
    offset = 0;
    break;
  case PBUF_RAW:
    offset = 0;
    break;
  default:
    do { if (!(0)) { ; }} while(0);
    return 0;
  }

  if ((((offset) + 4 - 1U) & ~(4-1U)) + length > payload_mem_len) {
    ;
    return 0;
  }

  p->pbuf.next = 0;
  if (payload_mem != 0) {
    p->pbuf.payload = (u8_t *)payload_mem + (((offset) + 4 - 1U) & ~(4-1U));
  } else {
    p->pbuf.payload = 0;
  }
  p->pbuf.flags = 0x02U;
  p->pbuf.len = p->pbuf.tot_len = length;
  p->pbuf.type = type;
  p->pbuf.ref = 1;
  return &p->pbuf;
}
















 
void
pbuf_realloc(struct pbuf *p, u16_t new_len)
{
  struct pbuf *q;
  u16_t rem_len;  
  s32_t grow;

  do { if (!(p != 0)) { ; }} while(0);
  do { if (!(p->type == PBUF_POOL || p->type == PBUF_ROM || p->type == PBUF_RAM || p->type == PBUF_REF)) { ; }} while(0);

   
  if (new_len >= p->tot_len) {
     
    return;
  }

  
 
  grow = new_len - p->tot_len;

   
  rem_len = new_len;
  q = p;
   
  while (rem_len > q->len) {
     
    rem_len -= q->len;
     
    do { if (!(grow < 0xffff)) { ; }} while(0);
    q->tot_len += (u16_t)grow;
     
    q = q->next;
    do { if (!(q != 0)) { ; }} while(0);
  }
   
   

   
   
  if ((q->type == PBUF_RAM) && (rem_len != q->len)
      && ((q->flags & 0x02U) == 0)
     ) {
     
    q = (struct pbuf *)mem_trim(q, (u16_t)((u8_t *)q->payload - (u8_t *)q) + rem_len);
    do { if (!(q != 0)) { ; }} while(0);
  }
   
  q->len = rem_len;
  q->tot_len = q->len;

   
  if (q->next != 0) {
     
    pbuf_free(q->next);
  }
   
  q->next = 0;

}











 
static u8_t
pbuf_header_impl(struct pbuf *p, s16_t header_size_increment, u8_t force)
{
  u16_t type;
  void *payload;
  u16_t increment_magnitude;

  do { if (!(p != 0)) { ; }} while(0);
  if ((header_size_increment == 0) || (p == 0)) {
    return 0;
  }

  if (header_size_increment < 0) {
    increment_magnitude = -header_size_increment;
     
    do { if (!((increment_magnitude <= p->len))) { ; return 1;;}} while(0);
  } else {
    increment_magnitude = header_size_increment;
  }

  type = p->type;
   
  payload = p->payload;

   
  if (type == PBUF_RAM || type == PBUF_POOL) {
     
    p->payload = (u8_t *)p->payload - header_size_increment;
     
    if ((u8_t *)p->payload < (u8_t *)p + (((sizeof(struct pbuf)) + 4 - 1U) & ~(4-1U))) {
      ;
       
      p->payload = payload;
       
      return 1;
    }
   
  } else if (type == PBUF_REF || type == PBUF_ROM) {
     
    if ((header_size_increment < 0) && (increment_magnitude <= p->len)) {
       
      p->payload = (u8_t *)p->payload - header_size_increment;
    } else if ((header_size_increment > 0) && force) {
      p->payload = (u8_t *)p->payload - header_size_increment;
    } else {
      
 
      return 1;
    }
  } else {
     
    do { if (!(0)) { ; }} while(0);
    return 1;
  }
   
  p->len += header_size_increment;
  p->tot_len += header_size_increment;

  ;

  return 0;
}




















 
u8_t
pbuf_header(struct pbuf *p, s16_t header_size_increment)
{
   return pbuf_header_impl(p, header_size_increment, 0);
}




 
u8_t
pbuf_header_force(struct pbuf *p, s16_t header_size_increment)
{
   return pbuf_header_impl(p, header_size_increment, 1);
}


































 
u8_t
pbuf_free(struct pbuf *p)
{
  u16_t type;
  struct pbuf *q;
  u8_t count;

  if (p == 0) {
    do { if (!(p != 0)) { ; }} while(0);
     
    ;
    return 0;
  }
  ;

  ;

  do { if (!(p->type == PBUF_RAM || p->type == PBUF_ROM || p->type == PBUF_REF || p->type == PBUF_POOL)) { ; }} while(0);

  count = 0;
  
 
  while (p != 0) {
    u16_t ref;
    ;
    

 
    ;
     
    do { if (!(p->ref > 0)) { ; }} while(0);
     
    ref = --(p->ref);
    ;
     
    if (ref == 0) {
       
      q = p->next;
      ;
      type = p->type;
       
      if ((p->flags & 0x02U) != 0) {
        struct pbuf_custom *pc = (struct pbuf_custom*)p;
        do { if (!(pc->custom_free_function != 0)) { ; }} while(0);
        pc->custom_free_function(p);
      } else
      {
         
        if (type == PBUF_POOL) {
          memp_free(MEMP_PBUF_POOL, p);
         
        } else if (type == PBUF_ROM || type == PBUF_REF) {
          memp_free(MEMP_PBUF, p);
         
        } else {
          mem_free(p);
        }
      }
      count++;
       
      p = q;
     
     
    } else {
      ;
       
      p = 0;
    }
  }
  ;
   
  return count;
}






 
u16_t
pbuf_clen(const struct pbuf *p)
{
  u16_t len;

  len = 0;
  while (p != 0) {
    ++len;
    p = p->next;
  }
  return len;
}







 
void
pbuf_ref(struct pbuf *p)
{
   
  if (p != 0) {
    do { ; ; p->ref += 1; ; } while(0);
  }
}










 
void
pbuf_cat(struct pbuf *h, struct pbuf *t)
{
  struct pbuf *p;

  do { if (!(((h != 0) && (t != 0)))) { ; return;;}} while(0);

   
  for (p = h; p->next != 0; p = p->next) {
     
    p->tot_len += t->tot_len;
  }
   
  do { if (!(p->tot_len == p->len)) { ; }} while(0);
  do { if (!(p->next == 0)) { ; }} while(0);
   
  p->tot_len += t->tot_len;
   
  p->next = t;
  

 
}

















 
void
pbuf_chain(struct pbuf *h, struct pbuf *t)
{
  pbuf_cat(h, t);
   
  pbuf_ref(t);
  ;
}








 
struct pbuf *
pbuf_dechain(struct pbuf *p)
{
  struct pbuf *q;
  u8_t tail_gone = 1;
   
  q = p->next;
   
  if (q != 0) {
     
    do { if (!(q->tot_len == p->tot_len - p->len)) { ; }} while(0);
     
    q->tot_len = p->tot_len - p->len;
     
    p->next = 0;
     
    p->tot_len = p->len;
     
    ;
    tail_gone = pbuf_free(q);
    if (tail_gone > 0) {
      ;
    }
     
  }
   
  do { if (!(p->tot_len == p->len)) { ; }} while(0);
  return ((tail_gone > 0) ? 0 : q);
}


















 
err_t
pbuf_copy(struct pbuf *p_to, const struct pbuf *p_from)
{
  u16_t offset_to=0, offset_from=0, len;

  ;

   
  do { if (!(((p_to != 0) && (p_from != 0) && (p_to->tot_len >= p_from->tot_len)))) { ; return ERR_ARG;;}} while(0);

   
  do
  {
     
    if ((p_to->len - offset_to) >= (p_from->len - offset_from)) {
       
      len = p_from->len - offset_from;
    } else {
       
      len = p_to->len - offset_to;
    }
    memcpy((u8_t*)p_to->payload + offset_to,(u8_t*)p_from->payload + offset_from,len);
    offset_to += len;
    offset_from += len;
    do { if (!(offset_to <= p_to->len)) { ; }} while(0);
    do { if (!(offset_from <= p_from->len)) { ; }} while(0);
    if (offset_from >= p_from->len) {
       
      offset_from = 0;
      p_from = p_from->next;
    }
    if (offset_to == p_to->len) {
       
      offset_to = 0;
      p_to = p_to->next;
      do { if (!((p_to != 0) || (p_from == 0))) { ; return ERR_ARG;;}} while(0);
    }

    if ((p_from != 0) && (p_from->len == p_from->tot_len)) {
       
      do { if (!((p_from->next == 0))) { ; return ERR_VAL;;}} while(0);
    }
    if ((p_to != 0) && (p_to->len == p_to->tot_len)) {
       
      do { if (!((p_to->next == 0))) { ; return ERR_VAL;;}} while(0);
    }
  } while (p_from);
  ;
  return ERR_OK;
}












 
u16_t
pbuf_copy_partial(const struct pbuf *buf, void *dataptr, u16_t len, u16_t offset)
{
  const struct pbuf *p;
  u16_t left;
  u16_t buf_copy_len;
  u16_t copied_total = 0;

  do { if (!((buf != 0))) { ; return 0;;}} while(0);
  do { if (!((dataptr != 0))) { ; return 0;;}} while(0);

  left = 0;

  if ((buf == 0) || (dataptr == 0)) {
    return 0;
  }

   
  for (p = buf; len != 0 && p != 0; p = p->next) {
    if ((offset != 0) && (offset >= p->len)) {
       
      offset -= p->len;
    } else {
       
      buf_copy_len = p->len - offset;
      if (buf_copy_len > len) {
        buf_copy_len = len;
      }
       
      memcpy(&((char*)dataptr)[left],&((char*)p->payload)[offset],buf_copy_len);
      copied_total += buf_copy_len;
      left += buf_copy_len;
      len -= buf_copy_len;
      offset = 0;
    }
  }
  return copied_total;
}


 
static const struct pbuf*
pbuf_skip_const(const struct pbuf* in, u16_t in_offset, u16_t* out_offset)
{
  u16_t offset_left = in_offset;
  const struct pbuf* q = in;

   
  while ((q != 0) && (q->len <= offset_left)) {
    offset_left -= q->len;
    q = q->next;
  }
  if (out_offset != 0) {
    *out_offset = offset_left;
  }
  return q;
}









 
struct pbuf*
pbuf_skip(struct pbuf* in, u16_t in_offset, u16_t* out_offset)
{
  return (struct pbuf*)(size_t)pbuf_skip_const(in, in_offset, out_offset);
}











 
err_t
pbuf_take(struct pbuf *buf, const void *dataptr, u16_t len)
{
  struct pbuf *p;
  u16_t buf_copy_len;
  u16_t total_copy_len = len;
  u16_t copied_total = 0;

  do { if (!((buf != 0))) { ; return ERR_ARG;;}} while(0);
  do { if (!((dataptr != 0))) { ; return ERR_ARG;;}} while(0);
  do { if (!((buf->tot_len >= len))) { ; return ERR_MEM;;}} while(0);

  if ((buf == 0) || (dataptr == 0) || (buf->tot_len < len)) {
    return ERR_ARG;
  }

   
  for (p = buf; total_copy_len != 0; p = p->next) {
    do { if (!(p != 0)) { ; }} while(0);
    buf_copy_len = total_copy_len;
    if (buf_copy_len > p->len) {
       
      buf_copy_len = p->len;
    }
     
    memcpy(p->payload,&((const char*)dataptr)[copied_total],buf_copy_len);
    total_copy_len -= buf_copy_len;
    copied_total += buf_copy_len;
  }
  do { if (!(total_copy_len == 0 && copied_total == len)) { ; }} while(0);
  return ERR_OK;
}











 
err_t
pbuf_take_at(struct pbuf *buf, const void *dataptr, u16_t len, u16_t offset)
{
  u16_t target_offset;
  struct pbuf* q = pbuf_skip(buf, offset, &target_offset);

   
  if ((q != 0) && (q->tot_len >= target_offset + len)) {
    u16_t remaining_len = len;
    const u8_t* src_ptr = (const u8_t*)dataptr;
     
    u16_t first_copy_len = (((q->len - target_offset) < (len)) ? (q->len - target_offset) : (len));
    memcpy(((u8_t*)q->payload) + target_offset,dataptr,first_copy_len);
    remaining_len -= first_copy_len;
    src_ptr += first_copy_len;
    if (remaining_len > 0) {
      return pbuf_take(q->next, src_ptr, remaining_len);
    }
    return ERR_OK;
  }
  return ERR_MEM;
}













 
struct pbuf*
pbuf_coalesce(struct pbuf *p, pbuf_layer layer)
{
  struct pbuf *q;
  err_t err;
  if (p->next == 0) {
    return p;
  }
  q = pbuf_alloc(layer, p->tot_len, PBUF_RAM);
  if (q == 0) {
     
    return p;
  }
  err = pbuf_copy(q, p);
  do { if (!(err == ERR_OK)) { ; }} while(0);
  pbuf_free(p);
  return q;
}










 
u8_t
pbuf_get_at(const struct pbuf* p, u16_t offset)
{
  int ret = pbuf_try_get_at(p, offset);
  if (ret >= 0) {
    return (u8_t)ret;
  }
  return 0;
}








 
int
pbuf_try_get_at(const struct pbuf* p, u16_t offset)
{
  u16_t q_idx;
  const struct pbuf* q = pbuf_skip_const(p, offset, &q_idx);

   
  if ((q != 0) && (q->len > q_idx)) {
    return ((u8_t*)q->payload)[q_idx];
  }
  return -1;
}









 
void
pbuf_put_at(struct pbuf* p, u16_t offset, u8_t data)
{
  u16_t q_idx;
  struct pbuf* q = pbuf_skip(p, offset, &q_idx);

   
  if ((q != 0) && (q->len > q_idx)) {
    ((u8_t*)q->payload)[q_idx] = data;
  }
}











 
u16_t
pbuf_memcmp(const struct pbuf* p, u16_t offset, const void* s2, u16_t n)
{
  u16_t start = offset;
  const struct pbuf* q = p;
  u16_t i;
 
   
  if(p->tot_len < (offset + n)) {
    return 0xffff;
  }
 
   
  while ((q != 0) && (q->len <= start)) {
    start -= q->len;
    q = q->next;
  }
 
   
  for (i = 0; i < n; i++) {
     
    u8_t a = pbuf_get_at(q, start + i);
    u8_t b = ((const u8_t*)s2)[i];
    if (a != b) {
      return i+1;
    }
  }
  return 0;
}












 
u16_t
pbuf_memfind(const struct pbuf* p, const void* mem, u16_t mem_len, u16_t start_offset)
{
  u16_t i;
  u16_t max = p->tot_len - mem_len;
  if (p->tot_len >= mem_len + start_offset) {
    for (i = start_offset; i <= max; i++) {
      u16_t plus = pbuf_memcmp(p, i, mem, mem_len);
      if (plus == 0) {
        return i;
      }
    }
  }
  return 0xFFFF;
}











 
u16_t
pbuf_strstr(const struct pbuf* p, const char* substr)
{
  size_t substr_len;
  if ((substr == 0) || (substr[0] == 0) || (p->tot_len == 0xFFFF)) {
    return 0xFFFF;
  }
  substr_len = strlen(substr);
  if (substr_len >= 0xFFFF) {
    return 0xFFFF;
  }
  return pbuf_memfind(p, substr, (u16_t)substr_len, 0);
}
