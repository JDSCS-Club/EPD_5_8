





 































 





 































 




 





 













































 




 





 

 


 


 



 

 

 

 

 

 



 

 


 

 

 


 


 
    
    
 
 

 

     
     

 


 


 


 

 


 





 





 


   
   
   
   
   
   
   






 


 





 


 


 



 































 






 































 

































 































 
  

 
 


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






 


 


 
 

 

 
static err_t tcp_output_segment(struct tcp_seg *seg, struct tcp_pcb *pcb, struct netif *netif);










 
static struct pbuf *
tcp_output_alloc_header(struct tcp_pcb *pcb, u16_t optlen, u16_t datalen,
                      u32_t seqno_be  )
{
  struct tcp_hdr *tcphdr;
  struct pbuf *p = pbuf_alloc(PBUF_IP, 20 + optlen + datalen, PBUF_RAM);
  if (p != 0) {
    do { if (!((p->len >= 20 + optlen))) { ; }} while(0);
    tcphdr = (struct tcp_hdr *)p->payload;
    tcphdr->src = lwip_htons(pcb->local_port);
    tcphdr->dest = lwip_htons(pcb->remote_port);
    tcphdr->seqno = seqno_be;
    tcphdr->ackno = lwip_htonl(pcb->rcv_nxt);
    (tcphdr)->_hdrlen_rsvd_flags = lwip_htons((((5 + optlen / 4)) << 12) | (0x10U));
    tcphdr->wnd = lwip_htons((pcb->rcv_ann_wnd));
    tcphdr->chksum = 0;
    tcphdr->urgp = 0;

     
    pcb->rcv_ann_right_edge = pcb->rcv_nxt + pcb->rcv_ann_wnd;
  }
  return p;
}






 
err_t
tcp_send_fin(struct tcp_pcb *pcb)
{
   
  if (pcb->unsent != 0) {
    struct tcp_seg *last_unsent;
    for (last_unsent = pcb->unsent; last_unsent->next != 0;
         last_unsent = last_unsent->next);

    if ((((u16_t)(lwip_htons((last_unsent->tcphdr)->_hdrlen_rsvd_flags) & 0x3fU)) & (0x02U | 0x01U | 0x04U)) == 0) {
       
      (last_unsent->tcphdr)->_hdrlen_rsvd_flags = ((last_unsent->tcphdr)->_hdrlen_rsvd_flags | lwip_htons(0x01U));
      pcb->flags |= 0x20U;
      return ERR_OK;
    }
  }
   
  return tcp_enqueue_flags(pcb, 0x01U);
}














 
static struct tcp_seg *
tcp_create_segment(struct tcp_pcb *pcb, struct pbuf *p, u8_t flags, u32_t seqno, u8_t optflags)
{
  struct tcp_seg *seg;
  u8_t optlen = (optflags & (u8_t)0x01U ? 4 : 0) + (optflags & (u8_t)0x02U ? 0 : 0) + (optflags & (u8_t)0x08U ? 0 : 0);

  if ((seg = (struct tcp_seg *)memp_malloc(MEMP_TCP_SEG)) == 0) {
    ;
    pbuf_free(p);
    return 0;
  }
  seg->flags = optflags;
  seg->next = 0;
  seg->p = p;
  do { if (!(p->tot_len >= optlen)) { ; }} while(0);
  seg->len = p->tot_len - optlen;

   
  if (pbuf_header(p, 20)) {
    ;
    ;
    tcp_seg_free(seg);
    return 0;
  }
  seg->tcphdr = (struct tcp_hdr *)seg->p->payload;
  seg->tcphdr->src = lwip_htons(pcb->local_port);
  seg->tcphdr->dest = lwip_htons(pcb->remote_port);
  seg->tcphdr->seqno = lwip_htonl(seqno);
   
  (seg->tcphdr)->_hdrlen_rsvd_flags = lwip_htons((((5 + optlen / 4)) << 12) | (flags));
   
  seg->tcphdr->urgp = 0;
  return seg;
}














 
static struct pbuf *
tcp_pbuf_prealloc(pbuf_layer layer, u16_t length, u16_t max_length,
                  u16_t *oversize, struct tcp_pcb *pcb, u8_t apiflags,
                  u8_t first_seg)
{
  struct pbuf *p;
  u16_t alloc = length;

  if (length < max_length) {
    









 
    if ((apiflags & 0x02) ||
        (!(pcb->flags & 0x40U) &&
         (!first_seg ||
          pcb->unsent != 0 ||
          pcb->unacked != 0))) {
      alloc = (((max_length) < ((((((length) + (1500 - 40))) + 4 - 1U) & ~(4-1U)))) ? (max_length) : ((((((length) + (1500 - 40))) + 4 - 1U) & ~(4-1U))));
    }
  }
  p = pbuf_alloc(layer, alloc, PBUF_RAM);
  if (p == 0) {
    return 0;
  }
  do { if (!(p->next == 0)) { ; }} while(0);
  *oversize = p->len - length;
   
  p->len = p->tot_len = length;
  return p;
}







 
static err_t
tcp_write_checks(struct tcp_pcb *pcb, u16_t len)
{
   
  if ((pcb->state != ESTABLISHED) &&
      (pcb->state != CLOSE_WAIT) &&
      (pcb->state != SYN_SENT) &&
      (pcb->state != SYN_RCVD)) {
    ;
    return ERR_CONN;
  } else if (len == 0) {
    return ERR_OK;
  }

   
  if (len > pcb->snd_buf) {
    ;
    pcb->flags |= 0x80U;
    return ERR_MEM;
  }

  ;

  
 
   
  if ((pcb->snd_queuelen >= (2* (4*(1500 - 40))/(1500 - 40))) || (pcb->snd_queuelen > (0xffffU-3))) {
    ;
    ;
    pcb->flags |= 0x80U;
    return ERR_MEM;
  }
  if (pcb->snd_queuelen != 0) {
    do { if (!(pcb->unacked != 0 || pcb->unsent != 0)) { ; }} while(0);
  } else {
    do { if (!(pcb->unacked == 0 && pcb->unsent == 0)) { ; }} while(0);
  }
  return ERR_OK;
}

















 
err_t
tcp_write(struct tcp_pcb *pcb, const void *arg, u16_t len, u8_t apiflags)
{
  struct pbuf *concat_p = 0;
  struct tcp_seg *last_unsent = 0, *seg = 0, *prev_seg = 0, *queue = 0;
  u16_t pos = 0;  
  u16_t queuelen;
  u8_t optlen = 0;
  u8_t optflags = 0;
  u16_t oversize = 0;
  u16_t oversize_used = 0;
  err_t err;
   
  u16_t mss_local = (((pcb->mss) < (pcb->snd_wnd_max/2)) ? (pcb->mss) : (pcb->snd_wnd_max/2));
  mss_local = mss_local ? mss_local : pcb->mss;


  ;
  do { if (!(arg != 0)) { ; return ERR_ARG;;}} while(0);

  err = tcp_write_checks(pcb, len);
  if (err != ERR_OK) {
    return err;
  }
  queuelen = pcb->snd_queuelen;



  



















 

   
  if (pcb->unsent != 0) {
    u16_t space;
    u16_t unsent_optlen;

     
    for (last_unsent = pcb->unsent; last_unsent->next != 0;
         last_unsent = last_unsent->next);

     
    unsent_optlen = (last_unsent->flags & (u8_t)0x01U ? 4 : 0) + (last_unsent->flags & (u8_t)0x02U ? 0 : 0) + (last_unsent->flags & (u8_t)0x08U ? 0 : 0);
    do { if (!(mss_local >= last_unsent->len + unsent_optlen)) { ; }} while(0);
    space = mss_local - (last_unsent->len + unsent_optlen);

    





 
    oversize = pcb->unsent_oversize;
    if (oversize > 0) {
      do { if (!(oversize_used <= space)) { ; }} while(0);
      seg = last_unsent;
      oversize_used = (((space) < ((((oversize) < (len)) ? (oversize) : (len)))) ? (space) : ((((oversize) < (len)) ? (oversize) : (len))));
      pos += oversize_used;
      oversize -= oversize_used;
      space -= oversize_used;
    }
     
    do { if (!((oversize == 0) || (pos == len))) { ; }} while(0);

    





 
    if ((pos < len) && (space > 0) && (last_unsent->len > 0)) {
      u16_t seglen = space < len - pos ? space : len - pos;
      seg = last_unsent;

      

 
      if (apiflags & 0x01) {
         
        if ((concat_p = tcp_pbuf_prealloc(PBUF_RAW, seglen, space, &oversize, pcb, apiflags, 1)) == 0) {
          ;
          goto memerr;
        }
        memcpy(concat_p->payload,(const u8_t*)arg + pos,seglen);
      } else {
         
        if ((concat_p = pbuf_alloc(PBUF_RAW, seglen, PBUF_ROM)) == 0) {
          ;
          goto memerr;
        }
         
        ((struct pbuf_rom*)concat_p)->payload = (const u8_t*)arg + pos;
      }

      pos += seglen;
      queuelen += pbuf_clen(concat_p);
    }
  } else {
    do { if (!(pcb->unsent_oversize == 0)) { ; }} while(0);
  }

  




 
  while (pos < len) {
    struct pbuf *p;
    u16_t left = len - pos;
    u16_t max_len = mss_local - optlen;
    u16_t seglen = left > max_len ? max_len : left;

    if (apiflags & 0x01) {
      
 
      if ((p = tcp_pbuf_prealloc(PBUF_TRANSPORT, seglen + optlen, mss_local, &oversize, pcb, apiflags, queue == 0)) == 0) {
        ;
        goto memerr;
      }
      do { if (!((p->len >= seglen))) { ; }} while(0);
      memcpy((char *)p->payload + optlen,(const u8_t*)arg + pos,seglen);
    } else {
      



 
      struct pbuf *p2;
      do { if (!(oversize == 0)) { ; }} while(0);
      if ((p2 = pbuf_alloc(PBUF_TRANSPORT, seglen, PBUF_ROM)) == 0) {
        ;
        goto memerr;
      }
       
      ((struct pbuf_rom*)p2)->payload = (const u8_t*)arg + pos;

       
      if ((p = pbuf_alloc(PBUF_TRANSPORT, optlen, PBUF_RAM)) == 0) {
        
 
        pbuf_free(p2);
        ;
        goto memerr;
      }
       
      pbuf_cat(p , p2 );
    }

    queuelen += pbuf_clen(p);

    

 
    if ((queuelen > (2* (4*(1500 - 40))/(1500 - 40))) || (queuelen > (0xffffU-3))) {
      ;
      pbuf_free(p);
      goto memerr;
    }

    if ((seg = tcp_create_segment(pcb, p, 0, pcb->snd_lbb + pos, optflags)) == 0) {
      goto memerr;
    }

     
    if (queue == 0) {
      queue = seg;
    } else {
       
      do { if (!(prev_seg != 0)) { ; }} while(0);
      prev_seg->next = seg;
    }
     
    prev_seg = seg;

    ;

    pos += seglen;
  }

  


 

  


 
  if (oversize_used > 0) {
    struct pbuf *p;
     
    for (p = last_unsent->p; p; p = p->next) {
      p->tot_len += oversize_used;
      if (p->next == 0) {
        memcpy((char *)p->payload + p->len,arg,oversize_used);
        p->len += oversize_used;
      }
    }
    last_unsent->len += oversize_used;
  }
  pcb->unsent_oversize = oversize;

  

 
  if (concat_p != 0) {
    do { if (!((last_unsent != 0))) { ; }} while(0);
    pbuf_cat(last_unsent->p, concat_p);
    last_unsent->len += concat_p->tot_len;
  }

  


 
  if (last_unsent == 0) {
    pcb->unsent = queue;
  } else {
    last_unsent->next = queue;
  }

  

 
  pcb->snd_lbb += len;
  pcb->snd_buf -= len;
  pcb->snd_queuelen = queuelen;

  ;
  if (pcb->snd_queuelen != 0) {
    do { if (!(pcb->unacked != 0 || pcb->unsent != 0)) { ; }} while(0);
  }

   
  if (seg != 0 && seg->tcphdr != 0 && ((apiflags & 0x02)==0)) {
    (seg->tcphdr)->_hdrlen_rsvd_flags = ((seg->tcphdr)->_hdrlen_rsvd_flags | lwip_htons(0x08U));
  }

  return ERR_OK;
memerr:
  pcb->flags |= 0x80U;
  ;

  if (concat_p != 0) {
    pbuf_free(concat_p);
  }
  if (queue != 0) {
    tcp_segs_free(queue);
  }
  if (pcb->snd_queuelen != 0) {
    do { if (!(pcb->unacked != 0 || pcb->unsent != 0)) { ; }} while(0);
  }
  ;
  return ERR_MEM;
}








 
err_t
tcp_enqueue_flags(struct tcp_pcb *pcb, u8_t flags)
{
  struct pbuf *p;
  struct tcp_seg *seg;
  u8_t optflags = 0;
  u8_t optlen = 0;

  ;

  do { if (!((flags & (0x02U | 0x01U)) != 0)) { ; }} while(0);

   
  if (((pcb->snd_queuelen >= (2* (4*(1500 - 40))/(1500 - 40))) || (pcb->snd_queuelen > (0xffffU-3))) &&
      ((flags & 0x01U) == 0)) {
    ;
    ;
    pcb->flags |= 0x80U;
    return ERR_MEM;
  }

  if (flags & 0x02U) {
    optflags = (u8_t)0x01U;
  }
  optlen = (optflags & (u8_t)0x01U ? 4 : 0) + (optflags & (u8_t)0x02U ? 0 : 0) + (optflags & (u8_t)0x08U ? 0 : 0);

   
  if ((p = pbuf_alloc(PBUF_TRANSPORT, optlen, PBUF_RAM)) == 0) {
    pcb->flags |= 0x80U;
    ;
    return ERR_MEM;
  }
  do { if (!((p->len >= optlen))) { ; }} while(0);

   
  if ((seg = tcp_create_segment(pcb, p, flags, pcb->snd_lbb, optflags)) == 0) {
    pcb->flags |= 0x80U;
    ;
    return ERR_MEM;
  }
  do { if (!(((mem_ptr_t)seg->tcphdr % (((4) < (4)) ? (4) : (4))) == 0)) { ; }} while(0);
  do { if (!(seg->len == 0)) { ; }} while(0);

  ;

   
  if (pcb->unsent == 0) {
    pcb->unsent = seg;
  } else {
    struct tcp_seg *useg;
    for (useg = pcb->unsent; useg->next != 0; useg = useg->next);
    useg->next = seg;
  }
   
  pcb->unsent_oversize = 0;

   
  if ((flags & 0x02U) || (flags & 0x01U)) {
    pcb->snd_lbb++;
     
  }
  if (flags & 0x01U) {
    pcb->flags |= 0x20U;
  }

   
  pcb->snd_queuelen += pbuf_clen(seg->p);
  ;
  if (pcb->snd_queuelen != 0) {
    do { if (!(pcb->unacked != 0 || pcb->unsent != 0)) { ; }} while(0);
  }

  return ERR_OK;
}







 
err_t
tcp_send_empty_ack(struct tcp_pcb *pcb)
{
  err_t err;
  struct pbuf *p;
  u8_t optlen = 0;
  struct netif *netif;


  p = tcp_output_alloc_header(pcb, optlen, 0, lwip_htonl(pcb->snd_nxt));
  if (p == 0) {
     
    pcb->flags |= (0x01U | 0x02U);
    ;
    return ERR_BUF;
  }
  ;

   

  netif = ip4_route(&pcb->remote_ip);
  if (netif == 0) {
    err = ERR_RTE;
  } else {
    ;
    err = ip4_output_if(p, &pcb->local_ip, &pcb->remote_ip, pcb->ttl, pcb->tos, 6, netif);
    ;
  }
  pbuf_free(p);

  if (err != ERR_OK) {
     
    pcb->flags |= (0x01U | 0x02U);
  } else {
     
    pcb->flags &= ~(0x01U | 0x02U);
  }

  return err;
}








 
err_t
tcp_output(struct tcp_pcb *pcb)
{
  struct tcp_seg *seg, *useg;
  u32_t wnd, snd_nxt;
  err_t err;
  struct netif *netif;

   
  do { if (!(pcb->state != LISTEN)) { ; }} while(0);

  


 
  if (tcp_input_pcb == pcb) {
    return ERR_OK;
  }

  wnd = (((pcb->snd_wnd) < (pcb->cwnd)) ? (pcb->snd_wnd) : (pcb->cwnd));

  seg = pcb->unsent;

  




 
  if (pcb->flags & 0x02U &&
     (seg == 0 ||
      lwip_htonl(seg->tcphdr->seqno) - pcb->lastack + seg->len > wnd)) {
     return tcp_send_empty_ack(pcb);
  }

   
  useg = pcb->unacked;
  if (useg != 0) {
    for (; useg->next != 0; useg = useg->next);
  }

  netif = ip4_route(&pcb->remote_ip);
  if (netif == 0) {
    return ERR_RTE;
  }

   
  if (((&pcb->local_ip) == 0 || ((*(&pcb->local_ip)). addr == ((u32_t)0x00000000UL)))) {
    const ip_addr_t *local_ip = (((netif) != 0) ? ((const ip_addr_t*)&((netif)->ip_addr)) : 0);
    if (local_ip == 0) {
      return ERR_RTE;
    }
    ((pcb->local_ip). addr = (*local_ip). addr);
  }

   
  while (seg != 0 &&
         lwip_htonl(seg->tcphdr->seqno) - pcb->lastack + seg->len <= wnd) {
    do { if (!((((u16_t)(lwip_htons((seg->tcphdr)->_hdrlen_rsvd_flags) & 0x3fU)) & 0x04U) == 0)) { ; }} while(0);
    





 
    if ((((((pcb)->unacked == 0) || ((pcb)->flags & (0x40U | 0x04U)) || (((pcb)->unsent != 0) && (((pcb)->unsent->next != 0) || ((pcb)->unsent->len >= (pcb)->mss))) || (((((pcb)->snd_buf)) == 0) || (((pcb)->snd_queuelen) >= (2* (4*(1500 - 40))/(1500 - 40)))) ) ? 1 : 0) == 0) &&
      ((pcb->flags & (0x80U | 0x20U)) == 0)) {
      break;
    }

    if (pcb->state != SYN_SENT) {
      (seg->tcphdr)->_hdrlen_rsvd_flags = ((seg->tcphdr)->_hdrlen_rsvd_flags | lwip_htons(0x10U));
    }

    err = tcp_output_segment(seg, pcb, netif);
    if (err != ERR_OK) {
       
      pcb->flags |= 0x80U;
      return err;
    }
    pcb->unsent = seg->next;
    if (pcb->state != SYN_SENT) {
      pcb->flags &= ~(0x01U | 0x02U);
    }
    snd_nxt = lwip_htonl(seg->tcphdr->seqno) + ((seg)->len + (((((u16_t)(lwip_htons(((seg)->tcphdr)->_hdrlen_rsvd_flags) & 0x3fU)) & (0x01U | 0x02U)) != 0) ? 1U : 0U));
    if (((s32_t)((u32_t)(pcb->snd_nxt) - (u32_t)(snd_nxt)) < 0)) {
      pcb->snd_nxt = snd_nxt;
    }
     
    if (((seg)->len + (((((u16_t)(lwip_htons(((seg)->tcphdr)->_hdrlen_rsvd_flags) & 0x3fU)) & (0x01U | 0x02U)) != 0) ? 1U : 0U)) > 0) {
      seg->next = 0;
       
      if (pcb->unacked == 0) {
        pcb->unacked = seg;
        useg = seg;
       
      } else {
        

 
        if (((s32_t)((u32_t)(lwip_htonl(seg->tcphdr->seqno)) - (u32_t)(lwip_htonl(useg->tcphdr->seqno))) < 0)) {
           
          struct tcp_seg **cur_seg = &(pcb->unacked);
          while (*cur_seg &&
            ((s32_t)((u32_t)(lwip_htonl((*cur_seg)->tcphdr->seqno)) - (u32_t)(lwip_htonl(seg->tcphdr->seqno))) < 0)) {
              cur_seg = &((*cur_seg)->next );
          }
          seg->next = (*cur_seg);
          (*cur_seg) = seg;
        } else {
           
          useg->next = seg;
          useg = useg->next;
        }
      }
     
    } else {
      tcp_seg_free(seg);
    }
    seg = pcb->unsent;
  }
  if (pcb->unsent == 0) {
     
    pcb->unsent_oversize = 0;
  }

  pcb->flags &= ~0x80U;
  return ERR_OK;
}







 
static err_t
tcp_output_segment(struct tcp_seg *seg, struct tcp_pcb *pcb, struct netif *netif)
{
  err_t err;
  u16_t len;
  u32_t *opts;

  if (seg->p->ref != 1) {
    

 
    return ERR_OK;
  }

  
 
  seg->tcphdr->ackno = lwip_htonl(pcb->rcv_nxt);

   
  {
    seg->tcphdr->wnd = lwip_htons((pcb->rcv_ann_wnd));
  }

  pcb->rcv_ann_right_edge = pcb->rcv_nxt + pcb->rcv_ann_wnd;

  
 
   
  opts = (u32_t *)(void *)(seg->tcphdr + 1);
  if (seg->flags & (u8_t)0x01U) {
    u16_t mss;
    mss = tcp_eff_send_mss_impl((1500 - 40), &pcb->remote_ip);
    *opts = lwip_htonl(0x02040000 | ((mss) & 0xFFFF));
    opts += 1;
  }

  
 
  if (pcb->rtime < 0) {
    pcb->rtime = 0;
  }

  if (pcb->rttest == 0) {
    pcb->rttest = tcp_ticks;
    pcb->rtseq = lwip_htonl(seg->tcphdr->seqno);

    ;
  }
  ;

  len = (u16_t)((u8_t *)seg->tcphdr - (u8_t *)seg->p->payload);
  if (len == 0) {
     
    ;
  }

  seg->p->len -= len;
  seg->p->tot_len -= len;

  seg->p->payload = seg->tcphdr;

  seg->tcphdr->chksum = 0;
  ;

  ;
  err = ip4_output_if(seg->p, &pcb->local_ip, &pcb->remote_ip, pcb->ttl, pcb->tos, 6, netif);
  ;
  return err;
}




















 
void
tcp_rst(u32_t seqno, u32_t ackno,
  const ip_addr_t *local_ip, const ip_addr_t *remote_ip,
  u16_t local_port, u16_t remote_port)
{
  struct pbuf *p;
  struct tcp_hdr *tcphdr;
  struct netif *netif;
  p = pbuf_alloc(PBUF_IP, 20, PBUF_RAM);
  if (p == 0) {
    ;
    return;
  }
  do { if (!((p->len >= sizeof(struct tcp_hdr)))) { ; }} while(0);

  tcphdr = (struct tcp_hdr *)p->payload;
  tcphdr->src = lwip_htons(local_port);
  tcphdr->dest = lwip_htons(remote_port);
  tcphdr->seqno = lwip_htonl(seqno);
  tcphdr->ackno = lwip_htonl(ackno);
  (tcphdr)->_hdrlen_rsvd_flags = lwip_htons(((20/4) << 12) | (0x04U | 0x10U));
  tcphdr->wnd = (((((2*(1500 - 40))) & 0xff) << 8) | ((((2*(1500 - 40))) & 0xff00) >> 8));
  tcphdr->chksum = 0;
  tcphdr->urgp = 0;

  ;
  ;

  netif = ip4_route(remote_ip);
  if (netif != 0) {
     
    ip4_output_if(p, local_ip, remote_ip, 255, 0, 6, netif);
  }
  pbuf_free(p);
  ;
}







 
void
tcp_rexmit_rto(struct tcp_pcb *pcb)
{
  struct tcp_seg *seg;

  if (pcb->unacked == 0) {
    return;
  }

   
  for (seg = pcb->unacked; seg->next != 0; seg = seg->next);
   
  seg->next = pcb->unsent;
   
  pcb->unsent = pcb->unacked;
   
  pcb->unacked = 0;

   
  ++pcb->nrtx;

   
  pcb->rttest = 0;

   
  tcp_output(pcb);
}







 
void
tcp_rexmit(struct tcp_pcb *pcb)
{
  struct tcp_seg *seg;
  struct tcp_seg **cur_seg;

  if (pcb->unacked == 0) {
    return;
  }

   
   
  seg = pcb->unacked;
  pcb->unacked = seg->next;

  cur_seg = &(pcb->unsent);
  while (*cur_seg &&
    ((s32_t)((u32_t)(lwip_htonl((*cur_seg)->tcphdr->seqno)) - (u32_t)(lwip_htonl(seg->tcphdr->seqno))) < 0)) {
      cur_seg = &((*cur_seg)->next );
  }
  seg->next = *cur_seg;
  *cur_seg = seg;
  if (seg->next == 0) {
     
    pcb->unsent_oversize = 0;
  }

  ++pcb->nrtx;

   
  pcb->rttest = 0;

   
  ;
  
 
}






 
void
tcp_rexmit_fast(struct tcp_pcb *pcb)
{
  if (pcb->unacked != 0 && !(pcb->flags & 0x04U)) {
     
    ;
    tcp_rexmit(pcb);

    
 
    if (pcb->cwnd > pcb->snd_wnd) {
      pcb->ssthresh = pcb->snd_wnd / 2;
    } else {
      pcb->ssthresh = pcb->cwnd / 2;
    }

     
    if (pcb->ssthresh < (2U * pcb->mss)) {
      ;
      pcb->ssthresh = 2*pcb->mss;
    }

    pcb->cwnd = pcb->ssthresh + 3 * pcb->mss;
    pcb->flags |= 0x04U;

     
    pcb->rtime = 0;
  }
}









 
err_t
tcp_keepalive(struct tcp_pcb *pcb)
{
  err_t err;
  struct pbuf *p;
  struct netif *netif;

  ;
  ;
  ;

  ;

  p = tcp_output_alloc_header(pcb, 0, 0, lwip_htonl(pcb->snd_nxt - 1));
  if (p == 0) {
    ;
    return ERR_MEM;
  }
  netif = ip4_route(&pcb->remote_ip);
  if (netif == 0) {
    err = ERR_RTE;
  } else {
    ;

     
    ;
    err = ip4_output_if(p, &pcb->local_ip, &pcb->remote_ip, pcb->ttl, 0, 6, netif);
    ;
  }
  pbuf_free(p);

  ;
  return err;
}









 
err_t
tcp_zero_window_probe(struct tcp_pcb *pcb)
{
  err_t err;
  struct pbuf *p;
  struct tcp_hdr *tcphdr;
  struct tcp_seg *seg;
  u16_t len;
  u8_t is_fin;
  u32_t snd_nxt;
  struct netif *netif;

  ;
  ;
  ;

  ;

  seg = pcb->unacked;

  if (seg == 0) {
    seg = pcb->unsent;
  }
  if (seg == 0) {
     
    return ERR_OK;
  }

  is_fin = ((((u16_t)(lwip_htons((seg->tcphdr)->_hdrlen_rsvd_flags) & 0x3fU)) & 0x01U) != 0) && (seg->len == 0);
   
  len = is_fin ? 0 : 1;

  p = tcp_output_alloc_header(pcb, 0, len, seg->tcphdr->seqno);
  if (p == 0) {
    ;
    return ERR_MEM;
  }
  tcphdr = (struct tcp_hdr *)p->payload;

  if (is_fin) {
     
    (tcphdr)->_hdrlen_rsvd_flags = (((tcphdr)->_hdrlen_rsvd_flags & ((((~0x3fU) & 0xff) << 8) | (((~0x3fU) & 0xff00) >> 8))) | lwip_htons(0x10U | 0x01U));
  } else {
     
    char *d = ((char *)p->payload + 20);
    

 
    pbuf_copy_partial(seg->p, d, 1, seg->p->tot_len - seg->len);
  }

   
  snd_nxt = lwip_htonl(seg->tcphdr->seqno) + 1;
  if (((s32_t)((u32_t)(pcb->snd_nxt) - (u32_t)(snd_nxt)) < 0)) {
    pcb->snd_nxt = snd_nxt;
  }

  netif = ip4_route(&pcb->remote_ip);
  if (netif == 0) {
    err = ERR_RTE;
  } else {
    ;

     
    ;
    err = ip4_output_if(p, &pcb->local_ip, &pcb->remote_ip, pcb->ttl, 0, 6, netif);
    ;
  }

  pbuf_free(p);

  ;
  return err;
}
