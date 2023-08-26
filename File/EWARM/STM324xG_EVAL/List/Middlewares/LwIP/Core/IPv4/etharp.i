










 































 





 































 




 





 













































 




 





 

 


 


 



 

 

 

 

 

 



 

 


 

 

 


 


 
    
    
 
 

 

     
     

 


 


 


 

 


 





 





 


   
   
   
   
   
   
   






 


 





 


 


 



 































 






 































 

































 































 
  

 
 


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






 































 





 































 




 



struct udp_pcb;
struct netif;




 

 

 
 
 

 

 

 

 

 





 
































 





 































 




 







 































 





 































 




 






 































 





 































 




 






 


































 





 































 




 






 































 



 





 


 





 

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








 

































 






 































 




 







 

































 






 































 




 










 

err_t ethernet_input(struct pbuf *p, struct netif *netif);
err_t ethernet_output(struct netif* netif, struct pbuf* p, const struct eth_addr* src, const struct eth_addr* dst, u16_t eth_type);

extern const struct eth_addr ethbroadcast, ethzero;




 
 

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






 



 







 

 
enum etharp_state {
  ETHARP_STATE_EMPTY = 0,
  ETHARP_STATE_PENDING,
  ETHARP_STATE_STABLE,
  ETHARP_STATE_STABLE_REREQUESTING_1,
  ETHARP_STATE_STABLE_REREQUESTING_2
};

struct etharp_entry {
   
  struct pbuf *q;
  ip4_addr_t ipaddr;
  struct netif *netif;
  struct eth_addr ethaddr;
  u16_t ctime;
  u8_t state;
};

static struct etharp_entry arp_table[10];

static u8_t etharp_cached_entry;


 



 


static err_t etharp_request_dst(struct netif *netif, const ip4_addr_t *ipaddr, const struct eth_addr* hw_dst_addr);



 


 
static void
etharp_free_entry(int i)
{
   
  ;
   
  if (arp_table[i].q != 0) {
     
    ;
    pbuf_free(arp_table[i]. q);
    arp_table[i].q = 0;
  }
   
  arp_table[i].state = ETHARP_STATE_EMPTY;
}






 
void
etharp_tmr(void)
{
  u8_t i;

  ;
   
  for (i = 0; i < 10; ++i) {
    u8_t state = arp_table[i].state;
    if (state != ETHARP_STATE_EMPTY
      ) {
      arp_table[i].ctime++;
      if ((arp_table[i].ctime >= 300) ||
          ((arp_table[i].state == ETHARP_STATE_PENDING)  &&
           (arp_table[i].ctime >= 5))) {
         
        ;
         
        etharp_free_entry(i);
      } else if (arp_table[i].state == ETHARP_STATE_STABLE_REREQUESTING_1) {
         
        arp_table[i].state = ETHARP_STATE_STABLE_REREQUESTING_2;
      } else if (arp_table[i].state == ETHARP_STATE_STABLE_REREQUESTING_2) {
        
 
        arp_table[i].state = ETHARP_STATE_STABLE;
      } else if (arp_table[i].state == ETHARP_STATE_PENDING) {
         
        etharp_request(arp_table[i].netif, &arp_table[i].ipaddr);
      }
    }
  }
}





















 
static s8_t
etharp_find_entry(const ip4_addr_t *ipaddr, u8_t flags, struct netif* netif)
{
  s8_t old_pending = 10, old_stable = 10;
  s8_t empty = 10;
  u8_t i = 0;
   
  s8_t old_queue = 10;
   
  u16_t age_queue = 0, age_pending = 0, age_stable = 0;

  (void)netif;

  



 

  






 

  for (i = 0; i < 10; ++i) {
    u8_t state = arp_table[i].state;
     
    if ((empty == 10) && (state == ETHARP_STATE_EMPTY)) {
      ;
       
      empty = i;
    } else if (state != ETHARP_STATE_EMPTY) {
      do { if (!(state == ETHARP_STATE_PENDING || state >= ETHARP_STATE_STABLE)) { ; }} while(0);
       
      if (ipaddr && ((ipaddr)->addr == (&arp_table[i]. ipaddr)->addr)
        ) {
        ;
         
        return i;
      }
       
      if (state == ETHARP_STATE_PENDING) {
         
        if (arp_table[i].q != 0) {
          if (arp_table[i].ctime >= age_queue) {
            old_queue = i;
            age_queue = arp_table[i].ctime;
          }
        } else
         
        {
          if (arp_table[i].ctime >= age_pending) {
            old_pending = i;
            age_pending = arp_table[i].ctime;
          }
        }
       
      } else if (state >= ETHARP_STATE_STABLE) {
        {
           
          if (arp_table[i].ctime >= age_stable) {
            old_stable = i;
            age_stable = arp_table[i].ctime;
          }
        }
      }
    }
  }
   

   
  if (((flags & 2) != 0) ||
       
      ((empty == 10) && ((flags & 1) == 0))) {
    ;
    return (s8_t)ERR_MEM;
  }

  






 

   
  if (empty < 10) {
    i = empty;
    ;
  } else {
     
    if (old_stable < 10) {
       
      i = old_stable;
      ;
       
      do { if (!(arp_table[i]. q == 0)) { ; }} while(0);
     
    } else if (old_pending < 10) {
       
      i = old_pending;
      ;
     
    } else if (old_queue < 10) {
       
      i = old_queue;
      ;
       
    } else {
      ;
      return (s8_t)ERR_MEM;
    }

     
    do { if (!(i < 10)) { ; }} while(0);
    etharp_free_entry(i);
  }

  do { if (!(i < 10)) { ; }} while(0);
  do { if (!(arp_table[i]. state == ETHARP_STATE_EMPTY)) { ; }} while(0);

   
  if (ipaddr != 0) {
     
    ((arp_table[i]. ipaddr). addr = (*ipaddr). addr);
  }
  arp_table[i].ctime = 0;
  return (err_t)i;
}


















 
static err_t
etharp_update_arp_entry(struct netif *netif, const ip4_addr_t *ipaddr, struct eth_addr *ethaddr, u8_t flags)
{
  s8_t i;
  do { if (!(netif->hwaddr_len == 6)) { ; }} while(0);
  ;
   
  if (((ipaddr) == 0 || ((*(ipaddr)). addr == ((u32_t)0x00000000UL))) ||
      ip4_addr_isbroadcast_u32((ipaddr)->addr, netif) ||
      (((ipaddr)->addr & ((((0xf0000000UL) & 0xff) << 24) | (((0xf0000000UL) & 0xff00) << 8) | (((0xf0000000UL) & 0xff0000UL) >> 8) | (((0xf0000000UL) & 0xff000000UL) >> 24))) == ((((0xe0000000UL) & 0xff) << 24) | (((0xe0000000UL) & 0xff00) << 8) | (((0xe0000000UL) & 0xff0000UL) >> 8) | (((0xe0000000UL) & 0xff000000UL) >> 24)))) {
    ;
    return ERR_ARG;
  }
   
  i = etharp_find_entry(ipaddr, flags, netif);
   
  if (i < 0) {
    return (err_t)i;
  }

  {
     
    arp_table[i].state = ETHARP_STATE_STABLE;
  }

   
  arp_table[i].netif = netif;
   
  ;

  ;
   
  memcpy(&arp_table[i]. ethaddr,ethaddr,6);
   
  arp_table[i].ctime = 0;
   
  if (arp_table[i].q != 0) {
    struct pbuf *p = arp_table[i].q;
    arp_table[i].q = 0;
     
    ethernet_output(netif, p, (struct eth_addr*)(netif->hwaddr), ethaddr, ETHTYPE_IP);
     
    pbuf_free(p);
  }
  return ERR_OK;
}






 
void
etharp_cleanup_netif(struct netif *netif)
{
  u8_t i;

  for (i = 0; i < 10; ++i) {
    u8_t state = arp_table[i].state;
    if ((state != ETHARP_STATE_EMPTY) && (arp_table[i].netif == netif)) {
      etharp_free_entry(i);
    }
  }
}











 
s8_t
etharp_find_addr(struct netif *netif, const ip4_addr_t *ipaddr,
         struct eth_addr **eth_ret, const ip4_addr_t **ip_ret)
{
  s8_t i;

  do { if (!(eth_ret != 0 && ip_ret != 0)) { ; }} while(0);

  (void)netif;

  i = etharp_find_entry(ipaddr, 2, netif);
  if ((i >= 0) && (arp_table[i].state >= ETHARP_STATE_STABLE)) {
      *eth_ret = &arp_table[i].ethaddr;
      *ip_ret = &arp_table[i].ipaddr;
      return i;
  }
  return -1;
}









 
u8_t
etharp_get_entry(u8_t i, ip4_addr_t **ipaddr, struct netif **netif, struct eth_addr **eth_ret)
{
  do { if (!(ipaddr != 0)) { ; }} while(0);
  do { if (!(netif != 0)) { ; }} while(0);
  do { if (!(eth_ret != 0)) { ; }} while(0);

  if((i < 10) && (arp_table[i].state >= ETHARP_STATE_STABLE)) {
    *ipaddr  = &arp_table[i].ipaddr;
    *netif   = arp_table[i].netif;
    *eth_ret = &arp_table[i].ethaddr;
    return 1;
  } else {
    return 0;
  }
}












 
void
etharp_input(struct pbuf *p, struct netif *netif)
{
  struct etharp_hdr *hdr;
   
  ip4_addr_t sipaddr, dipaddr;
  u8_t for_us;

  do { if (!((netif != 0))) { ; return;;}} while(0);

  hdr = (struct etharp_hdr *)p->payload;

   
  if ((hdr->hwtype != ((((HWTYPE_ETHERNET) & 0xff) << 8) | (((HWTYPE_ETHERNET) & 0xff00) >> 8))) ||
      (hdr->hwlen != 6) ||
      (hdr->protolen != sizeof(ip4_addr_t)) ||
      (hdr->proto != ((((ETHTYPE_IP) & 0xff) << 8) | (((ETHTYPE_IP) & 0xff00) >> 8))))  {
    ;
    ;
    ;
    pbuf_free(p);
    return;
  }
  ;


  
 
  memcpy(&sipaddr,&hdr->sipaddr,sizeof(ip4_addr_t));
  memcpy(&dipaddr,&hdr->dipaddr,sizeof(ip4_addr_t));

   
  if (((*((const ip4_addr_t*)(&((netif)->ip_addr)))). addr == ((u32_t)0x00000000UL))) {
    for_us = 0;
  } else {
     
    for_us = (u8_t)((&dipaddr)->addr == (((const ip4_addr_t*)(&((netif)->ip_addr))))->addr);
  }

  



 
  etharp_update_arp_entry(netif, &sipaddr, &(hdr->shwaddr),
                   for_us ? 1 : 2);

   
  switch (hdr->opcode) {
   
  case ((((ARP_REQUEST) & 0xff) << 8) | (((ARP_REQUEST) & 0xff00) >> 8)):
    

 

    ;
     
    if (for_us) {

      ;
      

 
      hdr->opcode = lwip_htons(ARP_REPLY);

      memcpy(&hdr->dipaddr,&hdr->sipaddr,sizeof(ip4_addr_t));
      memcpy(&hdr->sipaddr,((const ip4_addr_t*)(&((netif)->ip_addr))),sizeof(ip4_addr_t));

      do { if (!((netif->hwaddr_len == 6))) { ; }} while(0);

      
 

      memcpy(&hdr->dhwaddr,&hdr->shwaddr,6);
      memcpy(&hdr->shwaddr,netif->hwaddr,6);

       
      {
        ethernet_output(netif, p, &hdr->shwaddr, &hdr->dhwaddr, ETHTYPE_ARP);
      }

     
    } else if (((*((const ip4_addr_t*)(&((netif)->ip_addr)))). addr == ((u32_t)0x00000000UL))) {
       
      ;
     
    } else {
       
      ;
    }
    break;
  case ((((ARP_REPLY) & 0xff) << 8) | (((ARP_REPLY) & 0xff00) >> 8)):
     
    ;
    


 
    dhcp_arp_reply(netif, &sipaddr);
    break;
  default:
    ;
    ;
    break;
  }
   
  pbuf_free(p);
}



 
static err_t
etharp_output_to_arp_index(struct netif *netif, struct pbuf *q, u8_t arp_idx)
{
  do { if (!(arp_table[arp_idx]. state >= ETHARP_STATE_STABLE)) { ; }} while(0);
  

 
  if (arp_table[arp_idx].state == ETHARP_STATE_STABLE) {
    if (arp_table[arp_idx].ctime >= (300 - 15)) {
       
      if (etharp_request(netif, &arp_table[arp_idx].ipaddr) == ERR_OK) {
        arp_table[arp_idx].state = ETHARP_STATE_STABLE_REREQUESTING_1;
      }
    } else if (arp_table[arp_idx].ctime >= (300 - 30)) {
       
      if (etharp_request_dst(netif, &arp_table[arp_idx].ipaddr, &arp_table[arp_idx].ethaddr) == ERR_OK) {
        arp_table[arp_idx].state = ETHARP_STATE_STABLE_REREQUESTING_1;
      }
    }
  }

  return ethernet_output(netif, q, (struct eth_addr*)(netif->hwaddr), &arp_table[arp_idx].ethaddr, ETHTYPE_IP);
}


















 
err_t
etharp_output(struct netif *netif, struct pbuf *q, const ip4_addr_t *ipaddr)
{
  const struct eth_addr *dest;
  struct eth_addr mcastaddr;
  const ip4_addr_t *dst_addr = ipaddr;

  do { if (!(netif != 0)) { ; }} while(0);
  do { if (!(q != 0)) { ; }} while(0);
  do { if (!(ipaddr != 0)) { ; }} while(0);

  
 

   
  if (ip4_addr_isbroadcast_u32((ipaddr)->addr, netif)) {
     
    dest = (const struct eth_addr *)&ethbroadcast;
   
  } else if ((((ipaddr)->addr & ((((0xf0000000UL) & 0xff) << 24) | (((0xf0000000UL) & 0xff00) << 8) | (((0xf0000000UL) & 0xff0000UL) >> 8) | (((0xf0000000UL) & 0xff000000UL) >> 24))) == ((((0xe0000000UL) & 0xff) << 24) | (((0xe0000000UL) & 0xff00) << 8) | (((0xe0000000UL) & 0xff0000UL) >> 8) | (((0xe0000000UL) & 0xff000000UL) >> 24)))) {
     
    mcastaddr.addr[0] = 0x01;
    mcastaddr.addr[1] = 0x00;
    mcastaddr.addr[2] = 0x5e;
    mcastaddr.addr[3] = (((const u8_t*)(&(ipaddr)->addr))[1]) & 0x7f;
    mcastaddr.addr[4] = (((const u8_t*)(&(ipaddr)->addr))[2]);
    mcastaddr.addr[5] = (((const u8_t*)(&(ipaddr)->addr))[3]);
     
    dest = &mcastaddr;
   
  } else {
    s8_t i;
    
 
    if (!(((ipaddr)->addr & (((const ip4_addr_t*)(&((netif)->netmask))))->addr) == ((((const ip4_addr_t*)(&((netif)->ip_addr))))->addr & (((const ip4_addr_t*)(&((netif)->netmask))))->addr)) &&
        !(((ipaddr)->addr & ((((0xffff0000UL) & 0xff) << 24) | (((0xffff0000UL) & 0xff00) << 8) | (((0xffff0000UL) & 0xff0000UL) >> 8) | (((0xffff0000UL) & 0xff000000UL) >> 24))) == ((((0xa9fe0000UL) & 0xff) << 24) | (((0xa9fe0000UL) & 0xff00) << 8) | (((0xa9fe0000UL) & 0xff0000UL) >> 8) | (((0xa9fe0000UL) & 0xff000000UL) >> 24)))) {
      {
        {
           
          if (!((*((const ip4_addr_t*)(&((netif)->gw)))). addr == ((u32_t)0x00000000UL))) {
             
            dst_addr = ((const ip4_addr_t*)(&((netif)->gw)));
           
          } else {
             
            return ERR_RTE;
          }
        }
      }
    }
        if ((arp_table[etharp_cached_entry].state >= ETHARP_STATE_STABLE) &&
            (((dst_addr)->addr == (&arp_table[etharp_cached_entry]. ipaddr)->addr))) {
           
          ;
          return etharp_output_to_arp_index(netif, q, etharp_cached_entry);
        }

    
 
    for (i = 0; i < 10; i++) {
      if ((arp_table[i].state >= ETHARP_STATE_STABLE) &&
          (((dst_addr)->addr == (&arp_table[i]. ipaddr)->addr))) {
         
        (etharp_cached_entry = (i));
        return etharp_output_to_arp_index(netif, q, i);
      }
    }
    
 
    return etharp_query(netif, dst_addr, q);
  }

   
   
   
  return ethernet_output(netif, q, (struct eth_addr*)(netif->hwaddr), dest, ETHTYPE_IP);
}

































 
err_t
etharp_query(struct netif *netif, const ip4_addr_t *ipaddr, struct pbuf *q)
{
  struct eth_addr * srcaddr = (struct eth_addr *)netif->hwaddr;
  err_t result = ERR_MEM;
  int is_new_entry = 0;
  s8_t i;  

   
  if (ip4_addr_isbroadcast_u32((ipaddr)->addr, netif) ||
      (((ipaddr)->addr & ((((0xf0000000UL) & 0xff) << 24) | (((0xf0000000UL) & 0xff00) << 8) | (((0xf0000000UL) & 0xff0000UL) >> 8) | (((0xf0000000UL) & 0xff000000UL) >> 24))) == ((((0xe0000000UL) & 0xff) << 24) | (((0xe0000000UL) & 0xff00) << 8) | (((0xe0000000UL) & 0xff0000UL) >> 8) | (((0xe0000000UL) & 0xff000000UL) >> 24))) ||
      ((ipaddr) == 0 || ((*(ipaddr)). addr == ((u32_t)0x00000000UL)))) {
    ;
    return ERR_ARG;
  }

   
  i = etharp_find_entry(ipaddr, 1, netif);

   
  if (i < 0) {
    ;
    if (q) {
      ;
      ;
    }
    return (err_t)i;
  }

   
  if (arp_table[i].state == ETHARP_STATE_EMPTY) {
    is_new_entry = 1;
    arp_table[i].state = ETHARP_STATE_PENDING;
     
    arp_table[i].netif = netif;
  }

   
  do { if (!(((arp_table[i]. state == ETHARP_STATE_PENDING) || (arp_table[i]. state >= ETHARP_STATE_STABLE)))) { ; }} while(0);

   
  if (is_new_entry || (q == 0)) {
     
    result = etharp_request(netif, ipaddr);
    if (result != ERR_OK) {
       
      

 
    }
    if (q == 0) {
      return result;
    }
  }

   
  do { if (!(q != 0)) { ; }} while(0);
   
  if (arp_table[i].state >= ETHARP_STATE_STABLE) {
     
    (etharp_cached_entry = (i));
     
    result = ethernet_output(netif, q, srcaddr, &(arp_table[i].ethaddr), ETHTYPE_IP);
   
  } else if (arp_table[i].state == ETHARP_STATE_PENDING) {
     
    struct pbuf *p;
    int copy_needed = 0;
    

 
    p = q;
    while (p) {
      do { if (!((p->len != p->tot_len) || (p->next == 0))) { ; }} while(0);
      if (p->type != PBUF_ROM) {
        copy_needed = 1;
        break;
      }
      p = p->next;
    }
    if (copy_needed) {
       
      p = pbuf_alloc(PBUF_LINK, p->tot_len, PBUF_RAM);
      if (p != 0) {
        if (pbuf_copy(p, q) != ERR_OK) {
          pbuf_free(p);
          p = 0;
        }
      }
    } else {
       
      p = q;
      pbuf_ref(p);
    }
     
    if (p != 0) {
       
       
      if (arp_table[i].q != 0) {
        ;
        pbuf_free(arp_table[i].q);
      }
      arp_table[i].q = p;
      result = ERR_OK;
      ;
    } else {
      ;
      ;
      result = ERR_MEM;
    }
  }
  return result;
}















 
static err_t
etharp_raw(struct netif *netif, const struct eth_addr *ethsrc_addr,
           const struct eth_addr *ethdst_addr,
           const struct eth_addr *hwsrc_addr, const ip4_addr_t *ipsrc_addr,
           const struct eth_addr *hwdst_addr, const ip4_addr_t *ipdst_addr,
           const u16_t opcode)
{
  struct pbuf *p;
  err_t result = ERR_OK;
  struct etharp_hdr *hdr;

  do { if (!(netif != 0)) { ; }} while(0);

   
  p = pbuf_alloc(PBUF_LINK, 28, PBUF_RAM);
   
  if (p == 0) {
    ;
    ;
    return ERR_MEM;
  }
  do { if (!((p->len >= 28))) { ; }} while(0);

  hdr = (struct etharp_hdr *)p->payload;
  ;
  hdr->opcode = lwip_htons(opcode);

  do { if (!((netif->hwaddr_len == 6))) { ; }} while(0);

   
  memcpy(&hdr->shwaddr,hwsrc_addr,6);
  memcpy(&hdr->dhwaddr,hwdst_addr,6);
  
 
  memcpy(&hdr->sipaddr,ipsrc_addr,sizeof(ip4_addr_t));
  memcpy(&hdr->dipaddr,ipdst_addr,sizeof(ip4_addr_t));

  hdr->hwtype = ((((HWTYPE_ETHERNET) & 0xff) << 8) | (((HWTYPE_ETHERNET) & 0xff00) >> 8));
  hdr->proto = ((((ETHTYPE_IP) & 0xff) << 8) | (((ETHTYPE_IP) & 0xff00) >> 8));
   
  hdr->hwlen = 6;
  hdr->protolen = sizeof(ip4_addr_t);

   
  {
    ethernet_output(netif, p, ethsrc_addr, ethdst_addr, ETHTYPE_ARP);
  }

  ;
   
  pbuf_free(p);
  p = 0;
   

  return result;
}












 
static err_t
etharp_request_dst(struct netif *netif, const ip4_addr_t *ipaddr, const struct eth_addr* hw_dst_addr)
{
  return etharp_raw(netif, (struct eth_addr *)netif->hwaddr, hw_dst_addr,
                    (struct eth_addr *)netif->hwaddr, ((const ip4_addr_t*)(&((netif)->ip_addr))), &ethzero,
                    ipaddr, ARP_REQUEST);
}









 
err_t
etharp_request(struct netif *netif, const ip4_addr_t *ipaddr)
{
  ;
  return etharp_request_dst(netif, ipaddr, &ethbroadcast);
}

