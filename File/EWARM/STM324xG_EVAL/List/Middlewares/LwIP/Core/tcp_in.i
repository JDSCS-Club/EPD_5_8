








 































 





 































 




 





 













































 




 





 

 


 


 



 

 

 

 

 

 



 

 


 

 

 


 


 
    
    
 
 

 

     
     

 


 


 


 

 


 





 





 


   
   
   
   
   
   
   






 


 





 


 


 



 































 






 































 

































 































 
  

 
 


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





 

struct icmp_echo_hdr {
  u8_t type;
  u8_t code;
  u16_t chksum;
  u16_t id;
  u16_t seqno;
} ;































 

#pragma pack()


 





 
enum icmp_dur_type {
   
  ICMP_DUR_NET   = 0,
   
  ICMP_DUR_HOST  = 1,
   
  ICMP_DUR_PROTO = 2,
   
  ICMP_DUR_PORT  = 3,
   
  ICMP_DUR_FRAG  = 4,
   
  ICMP_DUR_SR    = 5
};

 
enum icmp_te_type {
   
  ICMP_TE_TTL  = 0,
   
  ICMP_TE_FRAG = 1
};


void icmp_input(struct pbuf *p, struct netif *inp);
void icmp_dest_unreach(struct pbuf *p, enum icmp_dur_type t);
void icmp_time_exceeded(struct pbuf *p, enum icmp_te_type t);






struct tcp_pcb;









 
typedef err_t (*tcp_accept_fn)(void *arg, struct tcp_pcb *newpcb, err_t err);










 
typedef err_t (*tcp_recv_fn)(void *arg, struct tcp_pcb *tpcb,
                             struct pbuf *p, err_t err);











 
typedef err_t (*tcp_sent_fn)(void *arg, struct tcp_pcb *tpcb,
                              u16_t len);









 
typedef err_t (*tcp_poll_fn)(void *arg, struct tcp_pcb *tpcb);










 
typedef void  (*tcp_err_fn)(void *arg, err_t err);












 
typedef err_t (*tcp_connected_fn)(void *arg, struct tcp_pcb *tpcb, err_t err);

typedef u16_t tcpwnd_size_t;

typedef u8_t tcpflags_t;

enum tcp_state {
  CLOSED      = 0,
  LISTEN      = 1,
  SYN_SENT    = 2,
  SYN_RCVD    = 3,
  ESTABLISHED = 4,
  FIN_WAIT_1  = 5,
  FIN_WAIT_2  = 6,
  CLOSE_WAIT  = 7,
  CLOSING     = 8,
  LAST_ACK    = 9,
  TIME_WAIT   = 10
};



 


 
struct tcp_pcb_listen {
 
  ip_addr_t local_ip; ip_addr_t remote_ip; u8_t so_options; u8_t tos; u8_t ttl ;
 
  struct tcp_pcb_listen *next; void *callback_arg; enum tcp_state state; u8_t prio; u16_t local_port;

   
  tcp_accept_fn accept;

};


 
struct tcp_pcb {
 
  ip_addr_t local_ip; ip_addr_t remote_ip; u8_t so_options; u8_t tos; u8_t ttl ;
 
  struct tcp_pcb *next; void *callback_arg; enum tcp_state state; u8_t prio; u16_t local_port;

   
  u16_t remote_port;

  tcpflags_t flags;

  
 

   
  u8_t polltmr, pollinterval;
  u8_t last_timer;
  u32_t tmr;

   
  u32_t rcv_nxt;    
  tcpwnd_size_t rcv_wnd;    
  tcpwnd_size_t rcv_ann_wnd;  
  u32_t rcv_ann_right_edge;  

   
  s16_t rtime;

  u16_t mss;    

   
  u32_t rttest;  
  u32_t rtseq;   
  s16_t sa, sv;  

  s16_t rto;     
  u8_t nrtx;     

   
  u8_t dupacks;
  u32_t lastack;  

   
  tcpwnd_size_t cwnd;
  tcpwnd_size_t ssthresh;

   
  u32_t snd_nxt;    
  u32_t snd_wl1, snd_wl2; 
 
  u32_t snd_lbb;        
  tcpwnd_size_t snd_wnd;    
  tcpwnd_size_t snd_wnd_max;  

  tcpwnd_size_t snd_buf;    
  u16_t snd_queuelen;  

   
  u16_t unsent_oversize;

   
  struct tcp_seg *unsent;    
  struct tcp_seg *unacked;   

  struct pbuf *refused_data;  

  struct tcp_pcb_listen* listener;

   
  tcp_sent_fn sent;
   
  tcp_recv_fn recv;
   
  tcp_connected_fn connected;
   
  tcp_poll_fn poll;
   
  tcp_err_fn errf;


   
  u32_t keep_idle;

   
  u8_t persist_cnt;
   
  u8_t persist_backoff;

   
  u8_t keep_cnt_sent;

};


 
struct tcp_pcb * tcp_new     (void);
struct tcp_pcb * tcp_new_ip_type (u8_t type);

void             tcp_arg     (struct tcp_pcb *pcb, void *arg);
void             tcp_recv    (struct tcp_pcb *pcb, tcp_recv_fn recv);
void             tcp_sent    (struct tcp_pcb *pcb, tcp_sent_fn sent);
void             tcp_err     (struct tcp_pcb *pcb, tcp_err_fn err);
void             tcp_accept  (struct tcp_pcb *pcb, tcp_accept_fn accept);
void             tcp_poll    (struct tcp_pcb *pcb, tcp_poll_fn poll, u8_t interval);

 
 
 


void             tcp_recved  (struct tcp_pcb *pcb, u16_t len);
err_t            tcp_bind    (struct tcp_pcb *pcb, const ip_addr_t *ipaddr,
                              u16_t port);
err_t            tcp_connect (struct tcp_pcb *pcb, const ip_addr_t *ipaddr,
                              u16_t port, tcp_connected_fn connected);

struct tcp_pcb * tcp_listen_with_backlog(struct tcp_pcb *pcb, u8_t backlog);
 

void             tcp_abort (struct tcp_pcb *pcb);
err_t            tcp_close   (struct tcp_pcb *pcb);
err_t            tcp_shutdown(struct tcp_pcb *pcb, int shut_rx, int shut_tx);

 

err_t            tcp_write   (struct tcp_pcb *pcb, const void *dataptr, u16_t len,
                              u8_t apiflags);

void             tcp_setprio (struct tcp_pcb *pcb, u8_t prio);


err_t            tcp_output  (struct tcp_pcb *pcb);


const char* tcp_debug_state_str(enum tcp_state s);

 






 































 



 



 






























 

#pragma pack(1)


struct tcp_hdr {
  u16_t src;
  u16_t dest;
  u32_t seqno;
  u32_t ackno;
  u16_t _hdrlen_rsvd_flags;
  u16_t wnd;
  u16_t chksum;
  u16_t urgp;
} ;































 

#pragma pack()


 
 







 

 
void             tcp_init    (void);   
void             tcp_tmr     (void);  

 

 
void             tcp_slowtmr (void);
void             tcp_fasttmr (void);




 
void             tcp_txnow   (void);

 
void             tcp_input   (struct pbuf *p, struct netif *inp);
 
struct tcp_pcb * tcp_alloc   (u8_t prio);
void             tcp_abandon (struct tcp_pcb *pcb, int reset);
err_t            tcp_send_empty_ack(struct tcp_pcb *pcb);
void             tcp_rexmit  (struct tcp_pcb *pcb);
void             tcp_rexmit_rto  (struct tcp_pcb *pcb);
void             tcp_rexmit_fast (struct tcp_pcb *pcb);
u32_t            tcp_update_rcv_ann_wnd(struct tcp_pcb *pcb);
err_t            tcp_process_refused_data(struct tcp_pcb *pcb);









 


 







 






 











 

 

 
struct tcp_seg {
  struct tcp_seg *next;     
  struct pbuf *p;           
  u16_t len;                
  u8_t  flags;
  struct tcp_hdr *tcphdr;   
};




 


 
extern struct tcp_pcb *tcp_input_pcb;
extern u32_t tcp_ticks;
extern u8_t tcp_active_pcbs_changed;

 
union tcp_listen_pcbs_t {  
  struct tcp_pcb_listen *listen_pcbs;
  struct tcp_pcb *pcbs;
};
extern struct tcp_pcb *tcp_bound_pcbs;
extern union tcp_listen_pcbs_t tcp_listen_pcbs;
extern struct tcp_pcb *tcp_active_pcbs;  

 
extern struct tcp_pcb *tcp_tw_pcbs;       

extern struct tcp_pcb ** const tcp_pcb_lists[4];






 

 








 
struct tcp_pcb *tcp_pcb_copy(struct tcp_pcb *pcb);
void tcp_pcb_purge(struct tcp_pcb *pcb);
void tcp_pcb_remove(struct tcp_pcb **pcblist, struct tcp_pcb *pcb);

void tcp_segs_free(struct tcp_seg *seg);
void tcp_seg_free(struct tcp_seg *seg);
struct tcp_seg *tcp_seg_copy(struct tcp_seg *seg);



err_t tcp_send_fin(struct tcp_pcb *pcb);
err_t tcp_enqueue_flags(struct tcp_pcb *pcb, u8_t flags);

void tcp_rexmit_seg(struct tcp_pcb *pcb, struct tcp_seg *seg);

void tcp_rst(u32_t seqno, u32_t ackno,
       const ip_addr_t *local_ip, const ip_addr_t *remote_ip,
       u16_t local_port, u16_t remote_port);

u32_t tcp_next_iss(void);

err_t tcp_keepalive(struct tcp_pcb *pcb);
err_t tcp_zero_window_probe(struct tcp_pcb *pcb);
void  tcp_trigger_input_pcb_close(void);

u16_t tcp_eff_send_mss_impl(u16_t sendmss, const ip_addr_t *dest
                           );

err_t tcp_recv_null(void *arg, struct tcp_pcb *pcb, struct pbuf *p, err_t err);


	void tcp_debug_print(struct tcp_hdr *tcphdr);
	void tcp_debug_print_flags(u8_t flags);
	void tcp_debug_print_state(enum tcp_state s);
	void tcp_debug_print_pcbs(void);
	s16_t tcp_pcbs_sane(void);
















 


 
void tcp_timer_needed(void);

void tcp_netif_ip_addr_changed(const ip_addr_t* old_addr, const ip_addr_t* new_addr);






 































 





 































 




 



 

 



u16_t inet_chksum(const void *dataptr, u16_t len);
u16_t inet_chksum_pbuf(struct pbuf *p);

u16_t inet_chksum_pseudo(struct pbuf *p, u8_t proto, u16_t proto_len,
       const ip4_addr_t *src, const ip4_addr_t *dest);
u16_t inet_chksum_pseudo_partial(struct pbuf *p, u8_t proto,
       u16_t proto_len, u16_t chksum_len, const ip4_addr_t *src, const ip4_addr_t *dest);



u16_t ip_chksum_pseudo(struct pbuf *p, u8_t proto, u16_t proto_len,
       const ip_addr_t *src, const ip_addr_t *dest);
u16_t ip_chksum_pseudo_partial(struct pbuf *p, u8_t proto, u16_t proto_len,
       u16_t chksum_len, const ip_addr_t *src, const ip_addr_t *dest);









 


































 






 































 




 




 
 



 
static struct tcp_seg inseg;
static struct tcp_hdr *tcphdr;
static u16_t tcphdr_optlen;
static u16_t tcphdr_opt1len;
static u8_t* tcphdr_opt2;
static u16_t tcp_optidx;
static u32_t seqno, ackno;
static tcpwnd_size_t recv_acked;
static u16_t tcplen;
static u8_t flags;

static u8_t recv_flags;
static struct pbuf *recv_data;

struct tcp_pcb *tcp_input_pcb;

 
static err_t tcp_process(struct tcp_pcb *pcb);
static void tcp_receive(struct tcp_pcb *pcb);
static void tcp_parseopt(struct tcp_pcb *pcb);

static void tcp_listen_input(struct tcp_pcb_listen *pcb);
static void tcp_timewait_input(struct tcp_pcb *pcb);









 
void
tcp_input(struct pbuf *p, struct netif *inp)
{
  struct tcp_pcb *pcb, *prev;
  struct tcp_pcb_listen *lpcb;
  u8_t hdrlen_bytes;
  err_t err;

  (void)inp;

  ;

  ;
  ;

  tcphdr = (struct tcp_hdr *)p->payload;


  tcp_debug_print(tcphdr);


   
  if (p->len < 20) {
     
    ;
    ;
    goto dropped;
  }

   
  if (ip4_addr_isbroadcast_u32(((&ip_data . current_iphdr_dest))->addr, (ip_data . current_netif)) ||
      ((((&ip_data . current_iphdr_dest))->addr & ((((0xf0000000UL) & 0xff) << 24) | (((0xf0000000UL) & 0xff00) << 8) | (((0xf0000000UL) & 0xff0000UL) >> 8) | (((0xf0000000UL) & 0xff000000UL) >> 24))) == ((((0xe0000000UL) & 0xff) << 24) | (((0xe0000000UL) & 0xff00) << 8) | (((0xe0000000UL) & 0xff0000UL) >> 8) | (((0xe0000000UL) & 0xff000000UL) >> 24)))) {
    ;
    goto dropped;
  }


   
  hdrlen_bytes = ((u16_t)(lwip_htons((tcphdr)->_hdrlen_rsvd_flags) >> 12)) * 4;
  if ((hdrlen_bytes < 20) || (hdrlen_bytes > p->tot_len)) {
    ;
    ;
    goto dropped;
  }

  
 
  tcphdr_optlen = hdrlen_bytes - 20;
  tcphdr_opt2 = 0;
  if (p->len >= hdrlen_bytes) {
     
    tcphdr_opt1len = tcphdr_optlen;
    pbuf_header(p, -(s16_t)hdrlen_bytes);  
  } else {
    u16_t opt2len;
     
     
    do { if (!(p->next != 0)) { ; }} while(0);

     
    pbuf_header(p, -20);

     
    tcphdr_opt1len = p->len;
    opt2len = tcphdr_optlen - tcphdr_opt1len;

    
 
    pbuf_header(p, -(s16_t)tcphdr_opt1len);

     
    if (opt2len > p->next->len) {
       
      ;
      ;
      goto dropped;
    }

     
    tcphdr_opt2 = (u8_t*)p->next->payload;

    
 
    pbuf_header(p->next, -(s16_t)opt2len);
    p->tot_len -= opt2len;

    do { if (!(p->len == 0)) { ; }} while(0);
    do { if (!(p->tot_len == p->next->tot_len)) { ; }} while(0);
  }

   
  tcphdr->src = lwip_htons(tcphdr->src);
  tcphdr->dest = lwip_htons(tcphdr->dest);
  seqno = tcphdr->seqno = lwip_htonl(tcphdr->seqno);
  ackno = tcphdr->ackno = lwip_htonl(tcphdr->ackno);
  tcphdr->wnd = lwip_htons(tcphdr->wnd);

  flags = ((u16_t)(lwip_htons((tcphdr)->_hdrlen_rsvd_flags) & 0x3fU));
  tcplen = p->tot_len + ((flags & (0x01U | 0x02U)) ? 1 : 0);

  
 
  prev = 0;

  for (pcb = tcp_active_pcbs; pcb != 0; pcb = pcb->next) {
    do { if (!(pcb->state != CLOSED)) { ; }} while(0);
    do { if (!(pcb->state != TIME_WAIT)) { ; }} while(0);
    do { if (!(pcb->state != LISTEN)) { ; }} while(0);
    if (pcb->remote_port == tcphdr->src &&
        pcb->local_port == tcphdr->dest &&
        ((&pcb->remote_ip)->addr == ((&ip_data . current_iphdr_src))->addr) &&
        ((&pcb->local_ip)->addr == ((&ip_data . current_iphdr_dest))->addr)) {
      

 
      do { if (!(pcb->next != pcb)) { ; }} while(0);
      if (prev != 0) {
        prev->next = pcb->next;
        pcb->next = tcp_active_pcbs;
        tcp_active_pcbs = pcb;
      } else {
        ;
      }
      do { if (!(pcb->next != pcb)) { ; }} while(0);
      break;
    }
    prev = pcb;
  }

  if (pcb == 0) {
    
 
    for (pcb = tcp_tw_pcbs; pcb != 0; pcb = pcb->next) {
      do { if (!(pcb->state == TIME_WAIT)) { ; }} while(0);
      if (pcb->remote_port == tcphdr->src &&
          pcb->local_port == tcphdr->dest &&
          ((&pcb->remote_ip)->addr == ((&ip_data . current_iphdr_src))->addr) &&
          ((&pcb->local_ip)->addr == ((&ip_data . current_iphdr_dest))->addr)) {
        

 
        ;
        tcp_timewait_input(pcb);
        pbuf_free(p);
        return;
      }
    }

    
 
    prev = 0;
    for (lpcb = tcp_listen_pcbs.listen_pcbs; lpcb != 0; lpcb = lpcb->next) {
      if (lpcb->local_port == tcphdr->dest) {
        if (0) {
           
          break;
        } else if (1) {
          if (((&lpcb->local_ip)->addr == ((&ip_data . current_iphdr_dest))->addr)) {
             
            break;
          } else if (((&lpcb->local_ip) == 0 || ((*(&lpcb->local_ip)). addr == ((u32_t)0x00000000UL)))) {
             
            break;
          }
        }
      }
      prev = (struct tcp_pcb *)lpcb;
    }
    if (lpcb != 0) {
      

 
      if (prev != 0) {
        ((struct tcp_pcb_listen *)prev)->next = lpcb->next;
               
        lpcb->next = tcp_listen_pcbs.listen_pcbs;
               
        tcp_listen_pcbs.listen_pcbs = lpcb;
      } else {
        ;
      }

      ;
      tcp_listen_input(lpcb);
      pbuf_free(p);
      return;
    }
  }



  if (pcb != 0) {
     

     
    inseg.next = 0;
    inseg.len = p->tot_len;
    inseg.p = p;
    inseg.tcphdr = tcphdr;

    recv_data = 0;
    recv_flags = 0;
    recv_acked = 0;

    if (flags & 0x08U) {
      p->flags |= 0x01U;
    }

     
    if (pcb->refused_data != 0) {
      if ((tcp_process_refused_data(pcb) == ERR_ABRT) ||
        ((pcb->refused_data != 0) && (tcplen > 0))) {
        
 
        ;
        ;
        goto aborted;
      }
    }
    tcp_input_pcb = pcb;
    err = tcp_process(pcb);
    
 
    if (err != ERR_ABRT) {
      if (recv_flags & (u8_t)0x08U) {
        


 
        do { if((pcb->errf) != 0) (pcb->errf)((pcb->callback_arg),(ERR_RST)); } while (0);
        tcp_pcb_remove(&tcp_active_pcbs, pcb);
        memp_free(MEMP_TCP_PCB, pcb);
      } else {
        err = ERR_OK;
        

 
        if (recv_acked > 0) {
          u16_t acked16;
          {
            acked16 = recv_acked;
            do { if((pcb)->sent != 0) (err) = (pcb)->sent((pcb)->callback_arg,(pcb),((u16_t)acked16)); else (err) = ERR_OK; } while (0);
            if (err == ERR_ABRT) {
              goto aborted;
            }
          }
          recv_acked = 0;
        }
        if (recv_flags & (u8_t)0x10U) {
          
 
          if (!(pcb->flags & 0x10U)) {
            

 
            do { if((pcb->errf) != 0) (pcb->errf)((pcb->callback_arg),(ERR_CLSD)); } while (0);
          }
          tcp_pcb_remove(&tcp_active_pcbs, pcb);
          memp_free(MEMP_TCP_PCB, pcb);
          goto aborted;
        }
        if (recv_data != 0) {

          do { if (!(pcb->refused_data == 0)) { ; }} while(0);
          if (pcb->flags & 0x10U) {
            
 
            pbuf_free(recv_data);
            tcp_abort(pcb);
            goto aborted;
          }

           
          do { if((pcb)->recv != 0) { (err) = (pcb)->recv((pcb)->callback_arg,(pcb),(recv_data),(ERR_OK)); } else { (err) = tcp_recv_null(0, (pcb), (recv_data), (ERR_OK)); } } while (0);
          if (err == ERR_ABRT) {
            goto aborted;
          }

           
          if (err != ERR_OK) {
            pcb->refused_data = recv_data;
            ;
          }
        }

        
 
        if (recv_flags & (u8_t)0x20U) {
          if (pcb->refused_data != 0) {
             
            pcb->refused_data->flags |= 0x20U;
          } else {
            
 
            if (pcb->rcv_wnd != (2*(1500 - 40))) {
              pcb->rcv_wnd++;
            }
            do { if(((pcb)->recv != 0)) { (err) = (pcb)->recv((pcb)->callback_arg,(pcb),0,ERR_OK); } else { (err) = ERR_OK; } } while (0);
            if (err == ERR_ABRT) {
              goto aborted;
            }
          }
        }

        tcp_input_pcb = 0;
         
        tcp_output(pcb);
      }
    }
    
 
aborted:
    tcp_input_pcb = 0;
    recv_data = 0;

     
    if (inseg.p != 0)
    {
      pbuf_free(inseg.p);
      inseg.p = 0;
    }
  } else {

    
 
    ;
    if (!(((u16_t)(lwip_htons((tcphdr)->_hdrlen_rsvd_flags) & 0x3fU)) & 0x04U)) {
      ;
      ;
      tcp_rst(ackno, seqno + tcplen, (&ip_data . current_iphdr_dest),
        (&ip_data . current_iphdr_src), tcphdr->dest, tcphdr->src);
    }
    pbuf_free(p);
  }

  do { if (!(tcp_pcbs_sane())) { ; }} while(0);
  ;
  return;
dropped:
  ;
  ;
  pbuf_free(p);
}









 
static void
tcp_listen_input(struct tcp_pcb_listen *pcb)
{
  struct tcp_pcb *npcb;
  err_t rc;

  if (flags & 0x04U) {
     
    return;
  }

  
 
  if (flags & 0x10U) {
    
 
    ;
    tcp_rst(ackno, seqno + tcplen, (&ip_data . current_iphdr_dest),
      (&ip_data . current_iphdr_src), tcphdr->dest, tcphdr->src);
  } else if (flags & 0x02U) {
    ;
    npcb = tcp_alloc(pcb->prio);
    

 
    if (npcb == 0) {
      err_t err;
      ;
      ;
      do { if((pcb != 0) && ((pcb)->accept != 0)) (err) = (pcb)->accept((pcb->callback_arg),(0),(ERR_MEM)); else (err) = ERR_ARG; } while (0);
      (void)err;  
      return;
    }
     
    ((npcb->local_ip). addr = (*(&ip_data . current_iphdr_dest)). addr);
    ((npcb->remote_ip). addr = (*(&ip_data . current_iphdr_src)). addr);
    npcb->local_port = pcb->local_port;
    npcb->remote_port = tcphdr->src;
    npcb->state = SYN_RCVD;
    npcb->rcv_nxt = seqno + 1;
    npcb->rcv_ann_right_edge = npcb->rcv_nxt;
    npcb->snd_wl1 = seqno - 1; 
    npcb->callback_arg = pcb->callback_arg;
    npcb->listener = pcb;
     
    npcb->so_options = pcb->so_options & (0x04U|0x08U);
    
 
    do { do { (npcb)->next = * &tcp_active_pcbs; *(&tcp_active_pcbs) = (npcb); tcp_timer_needed(); } while (0); tcp_active_pcbs_changed = 1; } while (0);

     
    tcp_parseopt(npcb);
    npcb->snd_wnd = (tcphdr->wnd);
    npcb->snd_wnd_max = npcb->snd_wnd;
    npcb->ssthresh = ((npcb)->snd_wnd);

    npcb->mss = tcp_eff_send_mss_impl(npcb->mss, &npcb->remote_ip);

    ;

     
    rc = tcp_enqueue_flags(npcb, 0x02U | 0x10U);
    if (rc != ERR_OK) {
      tcp_abandon(npcb, 0);
      return;
    }
    tcp_output(npcb);
  }
  return;
}









 
static void
tcp_timewait_input(struct tcp_pcb *pcb)
{
   
  


 
  if (flags & 0x04U) {
    return;
  }
   
  if (flags & 0x02U) {
    
 
    if ((((s32_t)((u32_t)(seqno) - (u32_t)(pcb->rcv_nxt)) >= 0) && ((s32_t)((u32_t)(seqno) - (u32_t)(pcb->rcv_nxt + pcb->rcv_wnd)) <= 0))) {
       
      tcp_rst(ackno, seqno + tcplen, (&ip_data . current_iphdr_dest),
        (&ip_data . current_iphdr_src), tcphdr->dest, tcphdr->src);
      return;
    }
  } else if (flags & 0x01U) {
    
 
    pcb->tmr = tcp_ticks;
  }

  if ((tcplen > 0)) {
     
    pcb->flags |= 0x02U;
    tcp_output(pcb);
  }
  return;
}











 
static err_t
tcp_process(struct tcp_pcb *pcb)
{
  struct tcp_seg *rseg;
  u8_t acceptable = 0;
  err_t err;

  err = ERR_OK;

   
  if (flags & 0x04U) {
     
    if (pcb->state == SYN_SENT) {
      
 
      if (ackno == pcb->snd_nxt) {
        acceptable = 1;
      }
    } else {
      
 
      if (seqno == pcb->rcv_nxt) {
        acceptable = 1;
      } else  if ((((s32_t)((u32_t)(seqno) - (u32_t)(pcb->rcv_nxt)) >= 0) && ((s32_t)((u32_t)(seqno) - (u32_t)(pcb->rcv_nxt + pcb->rcv_wnd)) <= 0))) {
        


 
        do { (pcb)->flags |= 0x02U; } while (0);
      }
    }

    if (acceptable) {
      ;
      do { if (!(pcb->state != CLOSED)) { ; }} while(0);
      recv_flags |= (u8_t)0x08U;
      pcb->flags &= ~0x01U;
      return ERR_RST;
    } else {
      ;
      ;
      return ERR_OK;
    }
  }

  if ((flags & 0x02U) && (pcb->state != SYN_SENT && pcb->state != SYN_RCVD)) {
     
    do { (pcb)->flags |= 0x02U; } while (0);
    return ERR_OK;
  }

  if ((pcb->flags & 0x10U) == 0) {
     
    pcb->tmr = tcp_ticks;
  }
  pcb->keep_cnt_sent = 0;

  tcp_parseopt(pcb);

   
  switch (pcb->state) {
  case SYN_SENT:
    ;
     
    if ((flags & 0x10U) && (flags & 0x02U)
        && (ackno == pcb->lastack + 1)) {
      pcb->rcv_nxt = seqno + 1;
      pcb->rcv_ann_right_edge = pcb->rcv_nxt;
      pcb->lastack = ackno;
      pcb->snd_wnd = (tcphdr->wnd);
      pcb->snd_wnd_max = pcb->snd_wnd;
      pcb->snd_wl1 = seqno - 1;  
      pcb->state = ESTABLISHED;

      pcb->mss = tcp_eff_send_mss_impl(pcb->mss, &pcb->remote_ip);

       
      pcb->ssthresh = ((pcb)->snd_wnd);

      pcb->cwnd = ((((4U * (pcb->mss))) < (((((2U * (pcb->mss))) > (4380U)) ? ((2U * (pcb->mss))) : (4380U)))) ? ((4U * (pcb->mss))) : (((((2U * (pcb->mss))) > (4380U)) ? ((2U * (pcb->mss))) : (4380U))));;
      ;
      do { if (!((pcb->snd_queuelen > 0))) { ; }} while(0);
      --pcb->snd_queuelen;
      ;
      rseg = pcb->unacked;
      if (rseg == 0) {
        
 
        rseg = pcb->unsent;
        do { if (!(rseg != 0)) { ; }} while(0);
        pcb->unsent = rseg->next;
      } else {
        pcb->unacked = rseg->next;
      }
      tcp_seg_free(rseg);

      
 
      if (pcb->unacked == 0) {
        pcb->rtime = -1;
      } else {
        pcb->rtime = 0;
        pcb->nrtx = 0;
      }

      
 
      do { if((pcb)->connected != 0) (err) = (pcb)->connected((pcb)->callback_arg,(pcb),(ERR_OK)); else (err) = ERR_OK; } while (0);
      if (err == ERR_ABRT) {
        return ERR_ABRT;
      }
      do { (pcb)->flags |= 0x02U; } while (0);
    }
     
    else if (flags & 0x10U) {
       
      tcp_rst(ackno, seqno + tcplen, (&ip_data . current_iphdr_dest),
        (&ip_data . current_iphdr_src), tcphdr->dest, tcphdr->src);
      
 
      pcb->rtime = 0;
      tcp_rexmit_rto(pcb);
    }
    break;
  case SYN_RCVD:
    if (flags & 0x10U) {
       
      if ((((s32_t)((u32_t)(ackno) - (u32_t)(pcb->lastack+1)) >= 0) && ((s32_t)((u32_t)(ackno) - (u32_t)(pcb->snd_nxt)) <= 0))) {
        pcb->state = ESTABLISHED;
        ;
        do { if (!((pcb->listener == 0) || (pcb->listener->accept != 0))) { ; }} while(0);
        if (pcb->listener == 0) {
           
          err = ERR_VAL;
        } else
        {
          ;
           
          do { if((pcb->listener != 0) && ((pcb->listener)->accept != 0)) (err) = (pcb->listener)->accept((pcb->callback_arg),(pcb),(ERR_OK)); else (err) = ERR_ARG; } while (0);
        }
        if (err != ERR_OK) {
          
 
           
          if (err != ERR_ABRT) {
            tcp_abort(pcb);
          }
          return ERR_ABRT;
        }
        
 
        tcp_receive(pcb);

        

 
        pcb->ssthresh = ((pcb)->snd_wnd);

         
        if (recv_acked != 0) {
          recv_acked--;
        }

        pcb->cwnd = ((((4U * (pcb->mss))) < (((((2U * (pcb->mss))) > (4380U)) ? ((2U * (pcb->mss))) : (4380U)))) ? ((4U * (pcb->mss))) : (((((2U * (pcb->mss))) > (4380U)) ? ((2U * (pcb->mss))) : (4380U))));;
        ;

        if (recv_flags & (u8_t)0x20U) {
          do { (pcb)->flags |= 0x02U; } while (0);
          pcb->state = CLOSE_WAIT;
        }
      } else {
         
        tcp_rst(ackno, seqno + tcplen, (&ip_data . current_iphdr_dest),
          (&ip_data . current_iphdr_src), tcphdr->dest, tcphdr->src);
      }
    } else if ((flags & 0x02U) && (seqno == pcb->rcv_nxt - 1)) {
       
      tcp_rexmit(pcb);
    }
    break;
  case CLOSE_WAIT:
     
  case ESTABLISHED:
    tcp_receive(pcb);
    if (recv_flags & (u8_t)0x20U) {  
      do { (pcb)->flags |= 0x02U; } while (0);
      pcb->state = CLOSE_WAIT;
    }
    break;
  case FIN_WAIT_1:
    tcp_receive(pcb);
    if (recv_flags & (u8_t)0x20U) {
      if ((flags & 0x10U) && (ackno == pcb->snd_nxt) &&
          pcb->unsent == 0) {
        ;
        do { (pcb)->flags |= 0x02U; } while (0);
        tcp_pcb_purge(pcb);
        do { do { if(*(&tcp_active_pcbs) == (pcb)) { (*(&tcp_active_pcbs)) = (* &tcp_active_pcbs)->next; } else { struct tcp_pcb *tcp_tmp_pcb; for (tcp_tmp_pcb = * &tcp_active_pcbs; tcp_tmp_pcb != 0; tcp_tmp_pcb = tcp_tmp_pcb->next) { if(tcp_tmp_pcb->next == (pcb)) { tcp_tmp_pcb->next = (pcb)->next; break; } } } (pcb)->next = 0; } while(0); tcp_active_pcbs_changed = 1; } while (0);
        pcb->state = TIME_WAIT;
        do { (pcb)->next = * &tcp_tw_pcbs; *(&tcp_tw_pcbs) = (pcb); tcp_timer_needed(); } while (0);
      } else {
        do { (pcb)->flags |= 0x02U; } while (0);
        pcb->state = CLOSING;
      }
    } else if ((flags & 0x10U) && (ackno == pcb->snd_nxt) &&
               pcb->unsent == 0) {
      pcb->state = FIN_WAIT_2;
    }
    break;
  case FIN_WAIT_2:
    tcp_receive(pcb);
    if (recv_flags & (u8_t)0x20U) {
      ;
      do { (pcb)->flags |= 0x02U; } while (0);
      tcp_pcb_purge(pcb);
      do { do { if(*(&tcp_active_pcbs) == (pcb)) { (*(&tcp_active_pcbs)) = (* &tcp_active_pcbs)->next; } else { struct tcp_pcb *tcp_tmp_pcb; for (tcp_tmp_pcb = * &tcp_active_pcbs; tcp_tmp_pcb != 0; tcp_tmp_pcb = tcp_tmp_pcb->next) { if(tcp_tmp_pcb->next == (pcb)) { tcp_tmp_pcb->next = (pcb)->next; break; } } } (pcb)->next = 0; } while(0); tcp_active_pcbs_changed = 1; } while (0);
      pcb->state = TIME_WAIT;
      do { (pcb)->next = * &tcp_tw_pcbs; *(&tcp_tw_pcbs) = (pcb); tcp_timer_needed(); } while (0);
    }
    break;
  case CLOSING:
    tcp_receive(pcb);
    if (flags & 0x10U && ackno == pcb->snd_nxt && pcb->unsent == 0) {
      ;
      tcp_pcb_purge(pcb);
      do { do { if(*(&tcp_active_pcbs) == (pcb)) { (*(&tcp_active_pcbs)) = (* &tcp_active_pcbs)->next; } else { struct tcp_pcb *tcp_tmp_pcb; for (tcp_tmp_pcb = * &tcp_active_pcbs; tcp_tmp_pcb != 0; tcp_tmp_pcb = tcp_tmp_pcb->next) { if(tcp_tmp_pcb->next == (pcb)) { tcp_tmp_pcb->next = (pcb)->next; break; } } } (pcb)->next = 0; } while(0); tcp_active_pcbs_changed = 1; } while (0);
      pcb->state = TIME_WAIT;
      do { (pcb)->next = * &tcp_tw_pcbs; *(&tcp_tw_pcbs) = (pcb); tcp_timer_needed(); } while (0);
    }
    break;
  case LAST_ACK:
    tcp_receive(pcb);
    if (flags & 0x10U && ackno == pcb->snd_nxt && pcb->unsent == 0) {
      ;
       
      recv_flags |= (u8_t)0x10U;
    }
    break;
  default:
    break;
  }
  return ERR_OK;
}













 
static void
tcp_receive(struct tcp_pcb *pcb)
{
  struct tcp_seg *next;
  s32_t off;
  s16_t m;
  u32_t right_wnd_edge;
  u16_t new_tot_len;
  int found_dupack = 0;

  do { if (!(pcb->state >= ESTABLISHED)) { ; }} while(0);

  if (flags & 0x10U) {
    right_wnd_edge = pcb->snd_wnd + pcb->snd_wl2;

     
    if (((s32_t)((u32_t)(pcb->snd_wl1) - (u32_t)(seqno)) < 0) ||
       (pcb->snd_wl1 == seqno && ((s32_t)((u32_t)(pcb->snd_wl2) - (u32_t)(ackno)) < 0)) ||
       (pcb->snd_wl2 == ackno && (u32_t)(tcphdr->wnd) > pcb->snd_wnd)) {
      pcb->snd_wnd = (tcphdr->wnd);
      
 
      if (pcb->snd_wnd_max < pcb->snd_wnd) {
        pcb->snd_wnd_max = pcb->snd_wnd;
      }
      pcb->snd_wl1 = seqno;
      pcb->snd_wl2 = ackno;
      if (pcb->snd_wnd == 0) {
        if (pcb->persist_backoff == 0) {
           
          pcb->persist_cnt = 0;
          pcb->persist_backoff = 1;
        }
      } else if (pcb->persist_backoff > 0) {
         
          pcb->persist_backoff = 0;
      }
      ;
    }

    

















 

     
    if (((s32_t)((u32_t)(ackno) - (u32_t)(pcb->lastack)) <= 0)) {
       
      if (tcplen == 0) {
         
        if (pcb->snd_wl2 + pcb->snd_wnd == right_wnd_edge) {
           
          if (pcb->rtime >= 0) {
             
            if (pcb->lastack == ackno) {
              found_dupack = 1;
              if ((u8_t)(pcb->dupacks + 1) > pcb->dupacks) {
                ++pcb->dupacks;
              }
              if (pcb->dupacks > 3) {
                
 
                if ((tcpwnd_size_t)(pcb->cwnd + pcb->mss) > pcb->cwnd) {
                  pcb->cwnd += pcb->mss;
                }
              } else if (pcb->dupacks == 3) {
                 
                tcp_rexmit_fast(pcb);
              }
            }
          }
        }
      }
      
 
      if (!found_dupack) {
        pcb->dupacks = 0;
      }
    } else if ((((s32_t)((u32_t)(ackno) - (u32_t)(pcb->lastack+1)) >= 0) && ((s32_t)((u32_t)(ackno) - (u32_t)(pcb->snd_nxt)) <= 0))) {
       

      

 
      if (pcb->flags & 0x04U) {
        pcb->flags &= ~0x04U;
        pcb->cwnd = pcb->ssthresh;
      }

       
      pcb->nrtx = 0;

       
      pcb->rto = (pcb->sa >> 3) + pcb->sv;

       
      pcb->dupacks = 0;
      pcb->lastack = ackno;

      
 
      if (pcb->state >= ESTABLISHED) {
        if (pcb->cwnd < pcb->ssthresh) {
          if ((tcpwnd_size_t)(pcb->cwnd + pcb->mss) > pcb->cwnd) {
            pcb->cwnd += pcb->mss;
          }
          ;
        } else {
          tcpwnd_size_t new_cwnd = (pcb->cwnd + pcb->mss * pcb->mss / pcb->cwnd);
          if (new_cwnd > pcb->cwnd) {
            pcb->cwnd = new_cwnd;
          }
          ;
        }
      }
      ;

      
 
      while (pcb->unacked != 0 &&
             ((s32_t)((u32_t)(lwip_htonl(pcb->unacked->tcphdr->seqno) + ((pcb->unacked)->len + (((((u16_t)(lwip_htons(((pcb->unacked)->tcphdr)->_hdrlen_rsvd_flags) & 0x3fU)) & (0x01U | 0x02U)) != 0) ? 1U : 0U))) - (u32_t)(ackno)) <= 0)) {
        ;

        next = pcb->unacked;
        pcb->unacked = pcb->unacked->next;

        ;
        do { if (!((pcb->snd_queuelen >= pbuf_clen(next->p)))) { ; }} while(0);

        pcb->snd_queuelen -= pbuf_clen(next->p);
        recv_acked += next->len;
        tcp_seg_free(next);

        ;
        if (pcb->snd_queuelen != 0) {
          do { if (!(pcb->unacked != 0 || pcb->unsent != 0)) { ; }} while(0);
        }
      }

      
 
      if (pcb->unacked == 0) {
        pcb->rtime = -1;
      } else {
        pcb->rtime = 0;
      }

      pcb->polltmr = 0;

    } else {
       
      tcp_send_empty_ack(pcb);
    }

    




 
    while (pcb->unsent != 0 &&
           (((s32_t)((u32_t)(ackno) - (u32_t)(lwip_htonl(pcb->unsent->tcphdr->seqno) + ((pcb->unsent)->len + (((((u16_t)(lwip_htons(((pcb->unsent)->tcphdr)->_hdrlen_rsvd_flags) & 0x3fU)) & (0x01U | 0x02U)) != 0) ? 1U : 0U)))) >= 0) && ((s32_t)((u32_t)(ackno) - (u32_t)(pcb->snd_nxt)) <= 0))) {
      ;

      next = pcb->unsent;
      pcb->unsent = pcb->unsent->next;
      if (pcb->unsent == 0) {
        pcb->unsent_oversize = 0;
      }
      ;
      do { if (!((pcb->snd_queuelen >= pbuf_clen(next->p)))) { ; }} while(0);
       
      pcb->snd_queuelen -= pbuf_clen(next->p);
      recv_acked += next->len;
      tcp_seg_free(next);
      ;
      if (pcb->snd_queuelen != 0) {
        do { if (!(pcb->unacked != 0 || pcb->unsent != 0)) { ; }} while(0);
      }
    }
    pcb->snd_buf += recv_acked;
     

    ;

    

 
    if (pcb->rttest && ((s32_t)((u32_t)(pcb->rtseq) - (u32_t)(ackno)) < 0)) {
      
 
      m = (s16_t)(tcp_ticks - pcb->rttest);

      ;

       
      m = m - (pcb->sa >> 3);
      pcb->sa += m;
      if (m < 0) {
        m = -m;
      }
      m = m - (pcb->sv >> 2);
      pcb->sv += m;
      pcb->rto = (pcb->sa >> 3) + pcb->sv;

      ;

      pcb->rttest = 0;
    }
  }

  


 
  if ((tcplen > 0) && (pcb->state < CLOSE_WAIT)) {
    





















 

    


 
    
 
    if ((((s32_t)((u32_t)(pcb->rcv_nxt) - (u32_t)(seqno + 1)) >= 0) && ((s32_t)((u32_t)(pcb->rcv_nxt) - (u32_t)(seqno + tcplen - 1)) <= 0))) {
      

















 

      struct pbuf *p = inseg.p;
      off = pcb->rcv_nxt - seqno;
      do { if (!(inseg . p)) { ; }} while(0);
      do { if (!((off < 0x7fff))) { ; }} while(0);
      if (inseg.p->len < off) {
        do { if (!((((s32_t)inseg . p->tot_len) >= off))) { ; }} while(0);
        new_tot_len = (u16_t)(inseg.p->tot_len - off);
        while (p->len < off) {
          off -= p->len;
          

 
          p->tot_len = new_tot_len;
          p->len = 0;
          p = p->next;
        }
        if (pbuf_header(p, (s16_t)-off)) {
           
          do { if (!(0)) { ; }} while(0);
        }
      } else {
        if (pbuf_header(inseg.p, (s16_t)-off)) {
           
          do { if (!(0)) { ; }} while(0);
        }
      }
      inseg.len -= (u16_t)(pcb->rcv_nxt - seqno);
      inseg.tcphdr->seqno = seqno = pcb->rcv_nxt;
    }
    else {
      if (((s32_t)((u32_t)(seqno) - (u32_t)(pcb->rcv_nxt)) < 0)) {
         
         

        ;
        do { (pcb)->flags |= 0x02U; } while (0);
      }
    }

    

 
    if ((((s32_t)((u32_t)(seqno) - (u32_t)(pcb->rcv_nxt)) >= 0) && ((s32_t)((u32_t)(seqno) - (u32_t)(pcb->rcv_nxt + pcb->rcv_wnd - 1)) <= 0))) {
      if (pcb->rcv_nxt == seqno) {
        

 
        tcplen = ((&inseg)->len + (((((u16_t)(lwip_htons(((&inseg)->tcphdr)->_hdrlen_rsvd_flags) & 0x3fU)) & (0x01U | 0x02U)) != 0) ? 1U : 0U));

        if (tcplen > pcb->rcv_wnd) {
          ;
          if (((u16_t)(lwip_htons((inseg . tcphdr)->_hdrlen_rsvd_flags) & 0x3fU)) & 0x01U) {
            
 
            (inseg . tcphdr)->_hdrlen_rsvd_flags = (((inseg . tcphdr)->_hdrlen_rsvd_flags & ((((~0x3fU) & 0xff) << 8) | (((~0x3fU) & 0xff00) >> 8))) | lwip_htons(((u16_t)(lwip_htons((inseg . tcphdr)->_hdrlen_rsvd_flags) & 0x3fU)) & ~(unsigned int)0x01U));
          }
           
          ;
          inseg.len = (u16_t)pcb->rcv_wnd;
          if (((u16_t)(lwip_htons((inseg . tcphdr)->_hdrlen_rsvd_flags) & 0x3fU)) & 0x02U) {
            inseg.len -= 1;
          }
          pbuf_realloc(inseg.p, inseg.len);
          tcplen = ((&inseg)->len + (((((u16_t)(lwip_htons(((&inseg)->tcphdr)->_hdrlen_rsvd_flags) & 0x3fU)) & (0x01U | 0x02U)) != 0) ? 1U : 0U));
          do { if (!((seqno + tcplen) == (pcb->rcv_nxt + pcb->rcv_wnd))) { ; }} while(0);
        }

        pcb->rcv_nxt = seqno + tcplen;

         
        do { if (!(pcb->rcv_wnd >= tcplen)) { ; }} while(0);
        pcb->rcv_wnd -= tcplen;

        tcp_update_rcv_ann_wnd(pcb);

        







 
        if (inseg.p->tot_len > 0) {
          recv_data = inseg.p;
          

 
          inseg.p = 0;
        }
        if (((u16_t)(lwip_htons((inseg . tcphdr)->_hdrlen_rsvd_flags) & 0x3fU)) & 0x01U) {
          ;
          recv_flags |= (u8_t)0x20U;
        }



         
        do { if((pcb)->flags & 0x01U) { (pcb)->flags &= ~0x01U; (pcb)->flags |= 0x02U; } else { (pcb)->flags |= 0x01U; } } while (0);


      } else {
         
        tcp_send_empty_ack(pcb);
      }
    } else {
       
      tcp_send_empty_ack(pcb);
    }
  } else {
    
 
    if (!(((s32_t)((u32_t)(seqno) - (u32_t)(pcb->rcv_nxt)) >= 0) && ((s32_t)((u32_t)(seqno) - (u32_t)(pcb->rcv_nxt + pcb->rcv_wnd - 1)) <= 0))) {
      do { (pcb)->flags |= 0x02U; } while (0);
    }
  }
}

static u8_t
tcp_getoptbyte(void)
{
  if ((tcphdr_opt2 == 0) || (tcp_optidx < tcphdr_opt1len)) {
    u8_t* opts = (u8_t *)tcphdr + 20;
    return opts[tcp_optidx++];
  } else {
    u8_t idx = (u8_t)(tcp_optidx++ - tcphdr_opt1len);
    return tcphdr_opt2[idx];
  }
}








 
static void
tcp_parseopt(struct tcp_pcb *pcb)
{
  u8_t data;
  u16_t mss;

   
  if (tcphdr_optlen != 0) {
    for (tcp_optidx = 0; tcp_optidx < tcphdr_optlen; ) {
      u8_t opt = tcp_getoptbyte();
      switch (opt) {
      case 0:
         
        ;
        return;
      case 1:
         
        ;
        break;
      case 2:
        ;
        if (tcp_getoptbyte() != 4 || (tcp_optidx - 2 + 4) > tcphdr_optlen) {
           
          ;
          return;
        }
         
        mss = (tcp_getoptbyte() << 8);
        mss |= tcp_getoptbyte();
         
        pcb->mss = ((mss > (1500 - 40)) || (mss == 0)) ? (1500 - 40) : mss;
        break;
      default:
        ;
        data = tcp_getoptbyte();
        if (data < 2) {
          ;
          
 
          return;
        }
        
 
        tcp_optidx += data - 2;
      }
    }
  }
}

void
tcp_trigger_input_pcb_close(void)
{
  recv_flags |= (u8_t)0x10U;
}

