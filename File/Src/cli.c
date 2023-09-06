/*------------------------------------------------------------------------------------------
	Project			: RFM
	Description		: console과 관련된 함수들 및 command line 처리

	Writer			: $Author: zlkit $
	Revision		: $Rev: 1891 $
	Date			: 2020. 08.
	Copyright		: Piranti Corp. ( zlkit@piranti.co.kr )
	 
	Revision History 
	1. 2020. 08.	: Created
-------------------------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <ctype.h>
#include <string.h>
#include <stdarg.h>

//=============================================================================
#if defined(_WIN32)
//=============================================================================

#include "x86_hal_driver.h"

//=============================================================================
#else	//	stm32f207
//=============================================================================

#if defined(USE_FREERTOS)
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"
#include "semphr.h"
#include "list.h"
#endif

#if defined(STM32F407xx)
#include "stm32f4xx.h"
#elif defined(STM32F207xx)
#include "stm32f2xx.h"
#endif

//=============================================================================
#endif
//=============================================================================
#include "main.h"
#include "cli.h"
#include "USRAT.h"
#include "QBuf.h"

//#include "version.h"		//	APP_VER / APP_BUILD_DATE

//#include "rs485.h"			//	cmd_sd()

#include "occpa.h"			//	cmd_occ()

//#include "nvram.h"			//	cmd_nvram[Read/Write/Dump]()

//#include "ymodem.h"			//	cmd_ymodem()

//#include "flash_if.h"		//	cmd_fl[Read/Write/Erase]()

#define		NELEMENTS(array)	(sizeof(array) / sizeof((array)[0]))
#define		MAX_COMMAND_LENGTH	64

#if			defined(USE_BOOTLOADER)
#define		PROMPT_STRING	"bootloader> "
#else	//	LED
#define		PROMPT_STRING	"RFB> "		//	RF - Board
#endif

#define		CLEAR_VT_SCREEN()	MyPrintf_USART1("\033[2J")
#define		GOTO_VT_XY()		MyPrintf_USART1("\033[1;1H")

int			input_check		( void );

char		prompt_string[0x10];

int			data_option = 1;

int	        debug_level;

//=============================================================================

/*
 * command tables
 */
user_command_t	user_command_table[] = {
	/*
	 * {"xxxx",		명령
	 * 	abc			help string1
	 * 	def			help string2
	 * 	func,},		실제 처리 함수
	 */
	{"help",
		"help		-	display commands \n\r",
		(char *)0,
		cmd_help,},
	{"uptime",
		"uptime	-   display uptime \n\r",
		(char *)0,
		cmd_uptime,},
	{"ver",
		"ver		-	display version.\n\r",
		(char *)0,
		cmd_ver,},
	{"reset",
		"reset		-	restart system\n\r",
		(char *)0,
		cmd_reset,},
	{"rfm",
		"rfm		-	To rfm command\n\r",
		(char *)0,
		cmd_rfm},
	{"wdtstoff",
		"wdtstoff	-	Watchdog Status Signal Off\n\r",
		(char *)0,
		cmd_WDGStOff,},
	{"bat",
		"bat		-	Battery Charge Rate\n\r",
		(char *)0,
		cmd_battery,},
	{"RF_POWER",
		"RF_POWER	-	RF Modual Power ON(1)/OFF(2) \n\r",
		(char *)0,
		cmd_RF_POWN_ON,},
     {"debug",
		"debug		-	set debug level.\n\r",
		"			1 - Ethernet , 2 - Amp , 3 - Current , 4 - Run Debug ,   5 - Run Time ON \n\r",
		//(char *)0,
		cmd_debug, },   
		//cmd_battery
#if defined(_RS485_H_)
	{"sd",
		"sd			-	Send SD ( Status Data )\n\r",
		(char *)0,
		cmd_sd,},
	{"sd2",
		"sd2		-	Send SD2 ( Status Data )\n\r",
		(char *)0,
		cmd_sd2,},
#endif

#if defined(OCC_PA_H)
	{"occ",
		"occ		-	OCC PA ( RFMBase -> RFM )\n\r",
		"occ [1(Start)/0(Stop)]\n\r",
		cmd_occ},
#endif

#if defined(NVRAM_I2C_H)
	{"nvmw",
		"nvmw			-	write byte to address\n\r",
		"nvmw [addr] [data]\n\r",
		cmd_nvramWrite,},
	{"nvmr",
		"nvmr			-	read byte from address\n\r",
		"nvmr [addr]\n\r",
		cmd_nvramRead,},
	{"nvmdump",
		"nvmdump		-	nvram dump\n\r",
		"nvmdump [addr] [size]\n\r",
		cmd_nvramDump,},
#endif	//	defined(EEPROM_I2C_H)

#if defined(__YMODEM_H_)
	{"ymodem",
		"ymodem		-	ymodem ( S/W Upgrade )\n\r",
		"ymodem [down/up] [app/boot]\n\r",
		cmd_ymodem},
#endif

#if defined(__FLASH_IF_H)
	{"flrd",
		"flrd			-	[Flash] Read byte from address\n\r",
		"flrd [addr(hex)]\n\r",
		cmd_flRead,},
	{"flwr",
		"flwr			-	[Flash] Write byte to address\n\r",
		"flwr [addr(hex)] [data]\n\r",
		cmd_flWrite,},
	{"fler",
		"fler			-	[Flash] Erase Flash Start Address to End Address\n\r",
		"fler [start addr(hex)]\n\r",
		cmd_flErase,},
#endif

};

char	old_cmd[MAX_COMMAND_LENGTH];

//=============================================================================

//========================================================================
void dump( uint8_t *a, int delta, int width )
//========================================================================
{
	int		i, j, k;
	uint8_t	*b;
	uint8_t	c;
	int		disp_unit = 16 / width;

	char	*format[] = {
							"",
							"   ",			/* width 1 */
							"     ",		/* width 2 */
							"",
							"         ",	/* width 4 */
						};

	for ( i = 0; i < delta; )
	{
		b = a;
		j = i;
		MyPrintf_USART1( "%08p  ", a );

		for ( k = 0; k < disp_unit && i < delta; k++, i += width )
		{
			if ( k == 8 )				MyPrintf_USART1( " " );

			if ( width == 1 )			MyPrintf_USART1( "%02x ", *a );
			else if ( width == 2 )		MyPrintf_USART1( "%04x ", *(uint16_t *)a );
			else if ( width == 4 )		MyPrintf_USART1( "%08x ", *(uint32_t *)a );
			a += width;
		}
		for ( ; k < disp_unit; k++ )
		{
			if ( k == 8 )				MyPrintf_USART1( " " );

			MyPrintf_USART1( format[width] );
		}
		MyPrintf_USART1( "|" );
		for ( k = 0; k < 16 && j < delta; k++, j++ )
		{
			if ( k == 8 )				MyPrintf_USART1( " " );

			c = *b++ & 0x7f;
			if ( c < ' ' || c == 0x7f )	MyPrintf_USART1( "%c", '.' );
			else						MyPrintf_USART1( "%c", c );
		}
		for ( ; k < 16; k++ )
		{
			if ( k == 8 )				MyPrintf_USART1( " " );

			MyPrintf_USART1( " " );
		}
		MyPrintf_USART1( "|\n" );
	}
}

//========================================================================
int 	a2hex(char *pv)
//========================================================================
{
	char **pos=NULL;

	return strtol(pv, pos, 16 );
}

//=============================================================================
#if defined(_WIN32)
//=============================================================================

char *
strtok_r ( char *s, const char *delim, char **save_ptr )
{
	char *end;

	if ( s == NULL )
		s = *save_ptr;

	if ( *s == '\0' )
	{
		*save_ptr = s;
		return NULL;
	}

	/* Scan leading delimiters.  */
	s += strspn ( s, delim );
	if ( *s == '\0' )
	{
		*save_ptr = s;
		return NULL;
	}

	/* Find the end of the token.  */
	end = s + strcspn ( s, delim );
	if ( *end == '\0' )
	{
		*save_ptr = end;
		return s;
	}

	/* Terminate the token and make *SAVE_PTR point past it.  */
	*end = '\0';
	*save_ptr = end + 1;
	return s;
}

//========================================================================
#endif
//========================================================================


/*****************************************************************************
* @brief - 
* @param -
* @retval- 			1 - Ethernet , 2 - Amp , 3 - Current , 4 - Run Debug , 5 - Run Time ON
******************************************************************************/
//========================================================================
int cmd_debug(int argc, char *argv[])
//========================================================================
{
	if (argc == 1)
	{
		MyPrintf_USART1("current debug level = 0x%x\r\n", debug_level);
	}
	else
	{
		debug_level = a2hex(argv[1]);
		MyPrintf_USART1("debug level = 0x%x\r\n", debug_level);
	}

	return 0;
}


int GetDbg(void )
{
	return debug_level;
}

/*****************************************************************************
* @brief - 
* @param -
* @retval-
******************************************************************************/
int cmd_RF_POWN_ON(int argc , char *argv[])
{
	int sNum = 0;

	if (argc == 1)
	{
		MyPrintf_USART1("RF_POWER MODE SELECT \n\r" );
	}
	else
	{
		sNum =  a2hex(argv[1]);

		if(sNum == 1)
		{
			RF_POWN_ON();	
			MyPrintf_USART1("RF POWN_ON \n\r ");
		
		}else if(sNum == 2)
		{
			RF_POWN_OFF();    	
			MyPrintf_USART1("RF POWN_OFF \n\r ");
		}

		
	}
}

/*
 * parse cmd & argument, return argc
 */
//========================================================================
int getarg(char *buffer, char *argv[])
//========================================================================
{
	int		argc;
	char	*p;
	char	*sepchr = " \t";
	char	*saveptr;

#define	MAXP	20

	p = (char *)strtok_r(buffer, sepchr, &saveptr);

	for ( argc = 0; argc < MAXP && p != NULL; p = (char *)strtok_r( NULL, sepchr, &saveptr ) )
	{
//		printf( "%s(%d) - %s\n", __func__, __LINE__, p );
		argv[argc++] = p;
	}

	return argc;
}

//========================================================================
int ProcessCommand( char *cmd )
//========================================================================
{
	char	*argv[MAXP];
	int		argc;
	char	*p;
	int		v = 0;
	int		i;
	char	temp[80];
	char	upstr[4] = { 0x1b, '[', 'A', 0 };

	if ( strcmp( "!!", cmd ) == 0 || strcmp( cmd, upstr ) == 0 )
	{
		strcpy( temp, old_cmd );
		strcpy( cmd, old_cmd );
	}
	else
	{
		strcpy( temp, cmd );
	}

	memset( argv, 0, sizeof( argv ) );

	// ignore after # char
	p = (char *)strchr( cmd, '#' );
	if ( p )
	{
		*p = (char)NULL;
	}

	// 명령라인을 arg,argv 로 분해
	argc = getarg( cmd, argv );

//	printf( "%s(%d) - argc(%d) / argv(%s)\n", __func__, __LINE__, argc, argv[0] );

	if ( argc != 0 )
	{

		// md/mm 등에 따르는 "[.b|.w|.l]에 대한 처리
		p = strchr( argv[0], '.' );
		if ( p != NULL )
		{
			if ( p[1] == 'b' )
			{
				data_option = 1;
			}
			else if ( p[1] == 'w' )
			{
				data_option = 2;
			}
			else if ( p[1] == 'l' )
			{
				data_option = 4;
			}
			*p = (char)NULL;
		}
		else
		{
			//	default
			data_option = 1;
		}

		// 명령을 table에서 찾아서 
		for ( i = 0; i < NELEMENTS( user_command_table ); i++ )
		{
			if ( strcmp( argv[0], user_command_table[i].command_name ) == 0 )
			{
				if ( argc >= 2 )
				{
					if ( (strcmp( argv[1], "help" ) == 0) || (strcmp( argv[1], "-h" ) == 0) )
					{
						MyPrintf_USART1( "%s\n", user_command_table[i].command_help1 );
						if ( user_command_table[i].command_help2 != NULL )
						{
							MyPrintf_USART1( "%s\n", user_command_table[i].command_help2 );
						}
						v = 1;
						break;
					}
				}
				// 처리함수를 호출
				if ( user_command_table[i].func( argc, argv ) < 0 )
				{
					MyPrintf_USART1( "%s\n", user_command_table[i].command_help1 );
					if ( user_command_table[i].command_help2 != NULL )
					{
						MyPrintf_USART1( "%s\n", user_command_table[i].command_help2 );
					}
				}
				v = 1;	// 명령을 찾아서 처리했음을 표시
				break;
			}

		}
		if ( v == 0 )
		{
			// 엉뚱하게 입력한 경우
			MyPrintf_USART1( "%s: command not found\n\r", argv[0] );
		}
		else
		{
			// !! 처리를 위해서 old_cmd로 명령 복사
			strcpy( old_cmd, temp );
		}
	}

	return 1;
}

static char		command_buf[MAX_COMMAND_LENGTH];
static int		command_index = 0;

//========================================================================
int readline( char *bufp )
//========================================================================
{
	//	printf( "%s\n", __func__ );

	char	ch;
	char	*command_buf = bufp;	//[MAX_COMMAND_LENGTH];

	int		ret = 0;

	for ( ;; )
	{
		ch = getchar();

#if defined(USE_FREERTOS)
#else
		if ( ch == (char)-1 )
		{
			//	Input Data가 없는 경우 ( Non-Blocking - OS less )
			return -1;
		}
#endif

		if ( ch == 0x08 || ch == 0x7F )	// Backspace
		{
			if ( command_index > 0 )
			{
				MyPrintf_USART1( "%c %c", 8, 8 );
				command_index--;
			}
		}
		else if ( ch == 0x15 )			// control-u, all input clear
		{
			while ( 0 < command_index )
			{
				MyPrintf_USART1( "%c %c", 8, 8 );
				command_index--;
			}
		}
		else if ( ch == 0x17 )			// control-w, erase one word
		{
			/* erase space */
			while ( (0 < command_index) && (command_buf[command_index] == ' ') ) {
				MyPrintf_USART1( "%c %c", 8, 8 );
				command_index--;
			}
			/* erase char not space */
			while ( (0 < command_index) && (command_buf[command_index] != ' ') ) {
				MyPrintf_USART1( "%c %c", 8, 8 );
				command_index--;
			}
		}
		else if ( (ch == 0x0D) || (ch == 0x0A) )
		{
			MyPrintf_USART1( "\n\r" );
			command_buf[command_index] = 0; // Null terminate the input command

			ret = command_index;
			command_index = 0;		//	입력후 index 초기화.

			return ret;
		}
		else if ( (0x20 <= ch) && (ch <= 0x7E) )
		{
			//	ANSI 입력.
			if ( command_index < (MAX_COMMAND_LENGTH - 2) )
			{
				command_buf[command_index++] = ch;
			}
			MyPrintf_USART1( "%c", ch );    // Echo the character
//			printf( "[%02X]", ch );    // Echo the character
		}
		else 
		{
			//	한글입력.
			if ( command_index < ( MAX_COMMAND_LENGTH - 2 ) )
			{
				command_buf[command_index++] = ch;
			}
			MyPrintf_USART1( "%c", ch );    // Echo the character
//			printf( "[%02X]", ch );    // Echo the character
		}

#if defined(USE_FREERTOS)
		//	FreeRTOS - Task Switching
		taskYIELD();
#else
//		HAL_Delay( 0 );
#endif
	}

	return 0;
}

//========================================================================
void	CLIPrompt( void )
//========================================================================
{
	MyPrintf_USART1( "%s", PROMPT_STRING );
}

void	( *g_fnCLIPrompt )( void ) = CLIPrompt;
int		( *g_fnCLIProc )( char * ) = ProcessCommand;

//========================================================================
void	SetCLIPrompt( void ( *fnPrompt )( void ) )
//========================================================================
{
	g_fnCLIPrompt = fnPrompt;
}

//========================================================================
void	SetCLIProc( int ( *fnProc )( char *cmd ) )
//========================================================================
{
	g_fnCLIProc = fnProc;
}


//========================================================================
void	LoopProcCLI ( void )
//========================================================================
{
	int len;
	if ( input_check() )
	{
		len = readline( command_buf );
		if ( len >= 0 )
		{
//			printf( "%s(%d) : %s\n", __func__, __LINE__, command_buf );
			//	Process Command
//			ProcessCommand( command_buf );
			g_fnCLIProc( command_buf );

			//	Print Prompt
//			printf( "%s", PROMPT_STRING );
			g_fnCLIPrompt();
		}
	}
}


//========================================================================
#if defined(_WIN32)
DWORD	vCLITask	( void *pvParameters )
#else	//	RTOS
void	vCLITask	( void *pvParameters )
#endif
//========================================================================
{
	/* The parameters are not used. */
	( void ) pvParameters;

	/*
	 * print Logo & version
	 */
//	CLEAR_VT_SCREEN();
//	GOTO_VT_XY();

//	user_commands = NELEMENTS(user_command_table);

	for(;;)
	{
		LoopProcCLI();

#if defined(USE_FREERTOS)
		taskYIELD();
#else
		HAL_Delay( 0 );
#endif
	}
}

//========================================================================
int cmd_help( int argc, char *argv[] )
//========================================================================
{
	int	i;
	int	ok = 0;

//	printf( "%s(%d)\n", __func__, __LINE__ );

	for ( i = 1; i < NELEMENTS( user_command_table ); i++ )
	{
		if ( 1 < argc )
		{
			if ( strcmp( argv[1], user_command_table[i].command_name ) == 0 )
			{
				if ( user_command_table[i].command_help1 != NULL )
				{
					MyPrintf_USART1( "%s", user_command_table[i].command_help1 );
				}
                
				if ( user_command_table[i].command_help2 != NULL )
				{
					MyPrintf_USART1( "%s", user_command_table[i].command_help2 );
				}
				ok = 1;
			}
		}
		else
		{
			if ( user_command_table[i].command_help1 != NULL )
			{
				MyPrintf_USART1( "%s", user_command_table[i].command_help1 );
			}
            
            
            if ( user_command_table[i].command_help2 != NULL )
            {
                MyPrintf_USART1( "%s", user_command_table[i].command_help2 );
            }
            
			ok = 1;
		}
	}
	if ( ok == 0 )
	{
		MyPrintf_USART1( "unknown command %s\n", argv[1] );
	}
	return 0;
}

//========================================================================
int cmd_uptime(int argc, char *argv[])
//========================================================================
{

//=============================================================================
#if defined(_WIN32)
//=============================================================================

//=============================================================================
#else	//	stm32f207
//=============================================================================

#if defined( USE_FREERTOS )
	unsigned long	tmp = xTaskGetTickCount() / configTICK_RATE_HZ;
#else
	unsigned long	tmp = HAL_GetTick() / 1000;
#endif

	int	sec, min, hour;
	int	day;

	day = (tmp / 3600 / 24);
	tmp = tmp % (3600 * 24);

	hour = tmp / 3600;
	tmp = tmp % 3600;

	min = tmp / 60;
	sec = tmp % 60;

	if (0 < day)
	{
		MyPrintf_USART1("%d day(s) %d:%02d:%02d up.\n", day, hour, min, sec);
	}
	else
	{
		MyPrintf_USART1("%d:%02d:%02d up.\n", hour, min, sec);
	}

//=============================================================================
#endif
//=============================================================================

	return 0;
}

//========================================================================
int cmd_ver(int argc, char *argv[])
//========================================================================
{
	MyPrintf_USART1("Version = %s(%s)\n", completeVersion , completeVersionBuild );

	return 0;
}


//========================================================================
int cmd_reset(int argc, char *argv[])
//========================================================================
{
  	NVIC_SystemReset();
	return 0;
}


//========================================================================
//extern int g_bEnIWDGStat;	//	WatchDog Stat Enable
int	cmd_WDGStOff(int argc, char *argv[])
{
	//g_bEnIWDGStat = 0;
}
//========================================================================


//========================================================================
int	cmd_battery(int argc, char *argv[])
{
	//	배터리 잔량 출력.
	MyPrintf_USART1("[Battery] Charge Rate : %d %%\n", getChargeRate() );
}
//========================================================================


//========================================================================
int cmd_wr( int argc, char *argv[] )
//========================================================================
{
	unsigned int	addr = 0;
	unsigned int	v;

	int	index = 1;
	int	option_loop = 0;

	if ( (index <= argc) && (strcmp( argv[index], "-l" ) == 0) )
	{
		option_loop = 1;
		index++;
	}
	if ( index < argc )
	{
		addr = a2hex( argv[index] );
		index++;
	}
	if ( index < argc )
	{
		v = a2hex( argv[index] );
	}
	else
	{
		return -1;
	}
	do
	{
		if ( data_option == 1 )
		{
			*(unsigned char *)addr	=	(unsigned char)v;
		}
		else if ( data_option == 2 )
		{
			*(unsigned short *)addr	=	(unsigned short)v;
		}
		else if ( data_option == 4 )
		{
			*(unsigned int *)addr	=	(unsigned int)v;
		}

#if defined(USE_FREERTOS)
		vTaskDelay( 100 / portTICK_RATE_MS );
#else
		HAL_Delay( 0 );
#endif

	} while ( option_loop == 1 && input_check() == 0 );

	MyPrintf_USART1( "\n" );

	return 0;
}

//========================================================================
int cmd_rd( int argc, char *argv[] )
//========================================================================
{
	unsigned int	addr;
	unsigned int	v;

	int		index = 1;
	int		option_loop = 0;

	if ( (index <= argc) && (strcmp( argv[index], "-l" ) == 0) )
	{
		option_loop = 1;
		index++;
	}
	if ( index < argc )
	{
		addr = a2hex( argv[index] );
	}
	else
	{
		return -1;
	}

	do
	{
		if ( data_option == 1 )
		{
			v = *(unsigned char *)addr;
			MyPrintf_USART1( "addr 0x%08x, value 0x%02x\r", addr, v );
		}
		else if ( data_option == 2 )
		{
			v = *(unsigned short *)addr;
			MyPrintf_USART1( "addr 0x%08x, value 0x%04x\r", addr, v );
		}
		else if ( data_option == 4 )
		{
			v = *(unsigned int *)addr;
			MyPrintf_USART1( "addr 0x%08x, value 0x%08x\r", addr, v );
		}

#if defined(USE_FREERTOS)
		vTaskDelay( 10 / portTICK_RATE_MS );
#else
		HAL_Delay( 0 );
#endif

	} while ( option_loop == 1 && input_check() == 0 );

	MyPrintf_USART1( "\n" );

	return 0;
}


//========================================================================
int cmd_rfm(int argc, char *argv[])
//========================================================================
{
	//	RFM 명령 전송.
	MyPrintf_USART1("%s(%d)\n", __func__, __LINE__ );

	return 0;
}

