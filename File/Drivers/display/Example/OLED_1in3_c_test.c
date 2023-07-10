/*****************************************************************************
* | File      	:   OLED_1in3_c_test.c
* | Author      :   Waveshare team
* | Function    :   1.3inch OLED Module (C) test demo
* | Info        :
*----------------
* |	This version:   V1.0
* | Date        :   2020-06-17
* | Info        :
* -----------------------------------------------------------------------------
#
# Permission is hereby granted, free of charge, to any person obtaining a copy
# of this software and associated documnetation files (the "Software"), to deal
# in the Software without restriction, including without limitation the rights
# to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
# copies of the Software, and to permit persons to  whom the Software is
# furished to do so, subject to the following conditions:
#
# The above copyright notice and this permission notice shall be included in
# all copies or substantial portions of the Software.
#
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
# IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
# FITNESS OR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
# AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
# LIABILITY WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
# OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
# THE SOFTWARE.
#
******************************************************************************/
#include "test.h"
#include "OLED_1in3_c.h"
#include "stdlib.h"
#include "AmpGpio.h"



int nTestCnt = 0;

UBYTE m_PisplayMemo[1100];

UBYTE *BlackImage;



int OLED_1in3_c_test(void)
{

    
  
	MyPrintf_USART1("1.3inch OLED (C) test demo\r\n");
        
        
	if(System_Init() != 0) {
		return -1;
	}
	  
	MyPrintf_USART1("OLED Init...\r\n");
	OLED_1in3_C_Init();
	Driver_Delay_ms(500);
	
	//OLED_1in3_C_Clear();
	
	// 0.Create a new image cache
	
	UWORD Imagesize = ((OLED_1in3_C_WIDTH%8==0)? (OLED_1in3_C_WIDTH/8): (OLED_1in3_C_WIDTH/8+1)) * OLED_1in3_C_HEIGHT;
        
     BlackImage = ((UBYTE *)m_PisplayMemo);
       
        
	MyPrintf_USART1("Paint_NewImage\r\n");
	Paint_NewImage(BlackImage, OLED_1in3_C_WIDTH, OLED_1in3_C_HEIGHT, 180, BLACK);	
	
	MyPrintf_USART1("Drawing\r\n");
	//1.Select Image
	Paint_SelectImage(BlackImage);
	Driver_Delay_ms(50);
	Paint_Clear(BLACK);
       
         
}


void OLED_Print(void)
{
    static int sPrintCnt = 0;
    
    nTestCnt++;
    
     // Drawing on the image
    
        if(!(nTestCnt%10))
        {
            MyPrintf_USART1("____OLED Print \r\n");
            
            
        }
		
        Paint_DrawString_EN(10, 0, "PA-PAMP", &Font16, WHITE, WHITE);
       
        
        if(!(nTestCnt%3))
        {
            sPrintCnt++;
        }
        
        if((sPrintCnt&0x01))
        {
            Paint_DrawString_EN(10, 17, &mLCDPrintBuf[0][0], &Font8, WHITE, WHITE);  // IP주소.
            Paint_DrawString_EN(10, 27, &mLCDPrintBuf[1][0], &Font8, WHITE, WHITE);  // 버전.
        }
        else
        {
            Paint_DrawString_EN(10, 17, &mLCDPrintBuf_2[0][0], &Font8, WHITE, WHITE);  // ANSM 상태
            Paint_DrawString_EN(10, 27, &mLCDPrintBuf_2[1][0], &Font8, WHITE, WHITE);  // AMP VOL 상태.
            
        }
        

        
        
        Paint_DrawString_EN(10, 37, &mLCDPrintBuf[2][0], &Font8, WHITE, WHITE); //AMP 고장 상태.
        //Paint_DrawNum(10, 37, 123.456789, &Font12, 4, WHITE, WHITE);
        

        
            
        Paint_DrawString_EN(10, 50, &mLCDPrintBuf[3][0], &Font12, WHITE, WHITE); // timer
        
        //Paint_DrawNum(10, 50, nTestCnt, &Font12, 0, WHITE, WHITE);
        
        
        // 입력 접점 상태.
        Paint_DrawNum(10 + 60, 50, (getSW_RS() ? 1 : 0), &Font12, 0, WHITE, WHITE);  
        Paint_DrawNum(10 + 70, 50, (getSW_AR() ? 2 : 0), &Font12, 0, WHITE, WHITE);
        Paint_DrawNum(10 + 80, 50, (getSW_SL() ? 3 : 0), &Font12, 0, WHITE, WHITE);
        Paint_DrawNum(10 + 90, 50, (getSW_SR() ? 4 : 0), &Font12, 0, WHITE, WHITE);
        
        // Show image on page2
        OLED_1in3_C_Display(BlackImage);
        //Driver_Delay_ms(2000);	
        memset(m_PisplayMemo,0x00,sizeof(m_PisplayMemo));
        
        //Paint_Clear(BLACK);		
}


















