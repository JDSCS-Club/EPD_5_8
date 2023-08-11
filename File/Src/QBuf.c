/*------------------------------------------------------------------------------------------
	Project			: It Library
	Description		: Queue

	Writer			: $Author: zlkit $
	Revision		: $Rev: 1891 $
	Date			: 2019. 10.
	Copyright		: Piranti Corp.	( zlkit@piranti.co.kr )
	 
	Revision History 
	1. 2019. 10.	: Created
-------------------------------------------------------------------------------------------*/

//========================================================================
// Header

#include <stdio.h>			//	printf()
#include <string.h>			//	memcpy()

#include "QBuf.h"
#include "USRAT.h"





#ifdef __GNUC__
  /* With GCC/RAISONANCE, small printf (option LD Linker->Libraries->Small printf
     set to 'Yes') calls __io_putchar() */
  #define PUTCHAR_PROTOTYPE int __io_putchar(int ch)
  #define GETCHAR_PROTOTYPE int __io_getchar(void)
#else
  #define PUTCHAR_PROTOTYPE int fputc(int ch, FILE *f)
  #define GETCHAR_PROTOTYPE int fgetc(FILE *f)
#endif /* __GNUC__ */



Queue_t		g_qUart1;

//========================================================================
// Define
/**
  * @brief  Retargets the C library printf function to the USART.
  * @param  None
  * @retval None
  */
////===========================================================================
//int putchar(int ch)
////===========================================================================
//{
//	/* Place your implementation of fputc here */
//	/* e.g. write a character to the EVAL_COM1 and Loop until the end of transmission */
//
//	//========================================================================
//	//	Console
//
//		HAL_UART_Transmit_IT( &UartHandle1, (uint8_t *)&ch, 1 );
//		if ( ch == '\n' )
//		{
//			HAL_UART_Transmit_IT( &UartHandle1, (uint8_t *)"\r", 1 );
//		}
//
//
//	return ch;
//}

//===========================================================================
GETCHAR_PROTOTYPE
//===========================================================================
{
	char	c;

	while( !qcount( &g_qUart1 ) )
	{
//		osDelay(0);
#if defined( USE_FREERTOS )
		taskYIELD();
#else
		return -1;		//	Non-Blocking ( OS less )
//		HAL_Delay( 0 );
#endif
	}
	c = qget( &g_qUart1 );

	return c;
}


//========================================================================
// Function

//------------------------------------------------------------------------------
//         serial queue functions
//------------------------------------------------------------------------------



//===========================================================================
void init_queue( Queue_t *q )
//===========================================================================
{
	q->front = q->rear = 0;
}

//===========================================================================
void clear_queue( Queue_t *q )
//===========================================================================
{
	q->front = q->rear;
}

//===========================================================================
int qcount( Queue_t *q )
//===========================================================================
{
	return ( ( ( q->rear + QMAX ) - q->front ) % QMAX);
}

//===========================================================================
int qput( Queue_t *q, unsigned char k )
//===========================================================================
{
	if ( (q->rear + 1) % QMAX == q->front )
	{
//		printf( "\n\tCircular Queue Overflow." );
//		printf( "\n\tQOver" );
		return -1;
	}
	q->queue[q->rear] = k;
	q->rear = (q->rear + 1) % QMAX;
	return k;
}

//===========================================================================
unsigned char qget( Queue_t *q )
//===========================================================================
{
	unsigned char i;
	/*
	if(front == rear){
		printf("\n\tCircular Queue Underflow.");
		return -1;
	}
	*/
	i = q->queue[q->front];
	q->front = (q->front + 1) % QMAX;

	return i;
}
//------------------------------------------------------------------------------


//===========================================================================
void qBufInit( QBuf_t *q, uint8_t *_qBuf, int _size )
//===========================================================================
{
	q->front = q->rear = 0;

	q->qBuf = _qBuf;
	q->size = _size;

    
//	printf( "%s(%d) - q(%p) / _qBuf(%p) / _size(%d)\n", __func__, __LINE__,
//		q, _qBuf, _size);
}

//===========================================================================
void qBufClear( QBuf_t *q )
//===========================================================================
{
	q->front = q->rear;
}

//===========================================================================
int qBufCnt( QBuf_t *q )
//===========================================================================
{
	return ( ( ( q->rear + q->size ) - q->front ) % q->size );
}

//===========================================================================
int qBufPut( QBuf_t *q, uint8_t *pBuf, int size )
//===========================================================================
{
	if ( ( q->rear + size ) % q->size == q->front )
	{
//		printf( "\n\tCircular Queue Overflow." );
		return -1;
	}

	memcpy( &q->qBuf[q->rear], pBuf, size );
//	q->qBuf[q->rear] = k;
	q->rear = ( q->rear + size ) % q->size;

//	printf( "%s(%d) - q(%p) / q->rear(%d) / q->front(%d)\n", __func__, __LINE__,
//		q, q->rear, q->front );

	return size;
}

//===========================================================================
int qBufGet( QBuf_t *q, uint8_t *pBuf, int size )
//===========================================================================
{
	//*
	if ( q->front == q->rear )
	{
//		printf( "\n\tCircular Queue Underflow." );
		return -1;
	}
	//	*/

	memcpy( pBuf, &q->qBuf[q->front], size );

	q->front = ( q->front + size ) % q->size;

//	printf( "%s(%d) - q(%p) / q->rear(%d) / q->front(%d)\n", __func__, __LINE__,
//		q, q->rear, q->front );

	return size;
}


//===========================================================================
void	QBufTest	( QBuf_t *q, int blkSize )
//===========================================================================
{
	int i, j;
	int idx;

	uint8_t	bufPut[128];
	uint8_t	bufGet[128];


	for ( i = 0, idx = 0; i < 20; i++, idx++ )
	{
		//===========================================================================
		memset( bufPut, idx, blkSize );

		MyPrintf_USART1( "Put : " );
		for ( j = 0; j < blkSize; j++ )
		{
			MyPrintf_USART1( "%02X ", bufPut[j] );
		}
		MyPrintf_USART1( "\n" );

		qBufPut( q, bufPut, blkSize );

		//===========================================================================
		qBufGet( q, bufGet, blkSize );

		MyPrintf_USART1( "Get : " );
		for ( j = 0; j < blkSize; j++ )
		{
			MyPrintf_USART1( "%02X ", bufGet[j] );
		}
		MyPrintf_USART1( "\n" );

		//===========================================================================
	}
}


//===========================================================================
int input_check( void )
//===========================================================================
{
	return qcount( &g_qUart1 );
}


//========================================================================
