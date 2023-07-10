

#ifndef __LCD_H__
#define __LCD_H__

void TextLCD_GPIO_Init(void);
void instruction_out(unsigned char b);
void display_out(unsigned char b);
void lcd_busuFlag(unsigned char b);
void lcd_gotoxy( char x,  char y);
void lcd_putstr( char x,  char y,  char *str);
void lcd_init(void);
void lcd_clear(void);
void lcd_Main(void);
void lcd_Timer(void);




#endif

