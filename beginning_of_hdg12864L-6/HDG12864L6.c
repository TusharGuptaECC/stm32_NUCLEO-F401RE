#include"HDG12864L6.h"
#include<stm32f4xx.h>
#include<stdint.h>

void writeCmd(uint32_t cmd)
 {
    // A0 = 0 i.e instrurction and write mode is selected  
    GPIOB->ODR = 0x00000000;
    // sending the cmd
    GPIOA->ODR = cmd;
    // enable clock
    GPIOB->ODR |= GPIO_ODR_ODR_3;
    //delay();
    GPIOB->ODR &= ~(GPIO_ODR_ODR_3);
 }
 
  void writeData(uint32_t data)
 {
    // A0 = 1 i.e data and write mode is selected  
    GPIOB->ODR = 0x00000001;
    // sending the cmd
    GPIOA->ODR = data;
    // enable clock
    GPIOB->ODR |= GPIO_ODR_ODR_3;
    //delay();
    GPIOB->ODR &= ~(GPIO_ODR_ODR_3);
 }
 
  void allRecordZero(void)
 {
	unsigned char x,y;
	for(x=0;x<8;x++)
	{
		for(y = 0; y<132;y++)
		{
			record[x][y] = 0;
		}
	}
  }
 
void glcdInit(void)
  {
    // display ON
    writeCmd(display_on);
    // ADC select   adc_normal OR adc_reverse
    writeCmd(adc_reverse);
    // display direction ---- normal OR reverse
    writeCmd(display_normal);
    // display all points or display normal
    writeCmd(displayAP_normal);
    // LCD bias set sed1565 bias0 = 1/9 and bias1 = 1/7
    writeCmd(bias1);
    // common output mode select
    writeCmd(com_op_mode_nom);
    // all record array =0 so no random value
    allRecordZero();
  }
  
void setLocation(uint32_t st_line, uint32_t pg_adrs, uint32_t up_add, uint32_t low_add)
  {
    // start line 0x00004000 to 0x00007F00
    writeCmd(st_line);
    // page address 0x0000B000 to 0x0000BF00
    writeCmd(pg_adrs);
    // segment selection upper address 0x00001000 to 0x00001800
    writeCmd(up_add);
    // segment selection upper address 0x00000000 to 0x00000F00
    writeCmd(low_add);
  }
  
  void increment(void)
  {
    // increment column address by 1
    writeCmd(0x0000E000);
  }
  
void reset(void)
  {
    // internal reset
    writeCmd(0x0000EE00);
	  writeCmd(0x0000E200);
  }
  
void staticIndicator(void)
{
	  writeCmd(0x0000AD00);
}

void displayDot(uint32_t x, uint32_t y, int o)
{
	uint32_t temp,x1,r,m = 0x00001000,l = 0x00000000,page = 0x0000B000;
	temp = x;
	x1 = x;
	x = x & 0x000000F0;
	x = x << 4;
	x = x|m;
	temp = temp & 0x0000000F;
	temp = temp << 8;
	temp = temp|l;
	
	if( o == 'B')
	{
		r = 7 - y%8;
		y = 7 - y/8;
	}
	if( o == 'T')
	{
		r = y%8;
		y = y/8;
	}
	y = y << 8;
	page = page | y;
	y = y >> 8;
	if(r == 7)
	{
		record[y][x1] = record[y][x1] | 0x00008000;
	}
	if(r == 6)
	{
		record[y][x1] = record[y][x1] | 0x00004000;
	}
	if(r == 5)
	{
		record[y][x1] = record[y][x1] | 0x00002000;
	}
	if(r == 4)
	{
		record[y][x1] = record[y][x1] | 0x00001000;
	}
	if(r == 3)
	{
		record[y][x1] = record[y][x1] | 0x00000800;
	}
	if(r == 2)
	{
		record[y][x1] = record[y][x1] | 0x00000400;
	}
	if(r == 1)
	{
		record[y][x1] = record[y][x1] | 0x00000200;
	}
	if(r == 0)
	{
		record[y][x1] = record[y][x1] | 0x00000100;
	}
	setLocation(0x00004000, page, x, temp);
	writeData(record[y][x1]);
}
