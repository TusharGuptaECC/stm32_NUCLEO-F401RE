#include <stm32f4xx.h>
#include<stdint.h>
#include"HDG12864L6.h"

void provideClock(void)
{
    // by default 16MHz HSI is selected
    // providing clk to port A,B,C 
    RCC->AHB1ENR = 0x00000007;
}

void delay(void)
{
	unsigned char i,j;  
	for(i=0;i<=100;i++)
	{
		for(j=0;j<=100;j++)
		{
			{};
		}
	}
 }   
 


int main()
{//int i;
  provideClock();
  // setting gpioa(pin - 0,1,2,3,4,5,6,7) as output
  GPIOA->MODER = 0x55550000;
  GPIOA->OTYPER = 0x00000000;		// setting as push-pull
  GPIOA->OSPEEDR = 0x00000000;		// setting at low speed
  GPIOA->PUPDR = 0x00000000;		// no use because setted as output
      
   // setting gpiob( pin - 0,1,2,3) as output
  GPIOB->MODER = 0x00000055;
  GPIOB->OTYPER = 0x00000000;		// setting as push-pull
  GPIOB->OSPEEDR = 0x00000000;		// setting at low speed
  GPIOB->PUPDR = 0x00000000;		// no use because setted as output

  glcdInit();
  //tLocation(0x00004000, 0x0000B200, 0x00001000, 0x00000000);
  //for(i=0;i<20;i++){
  //setLocation(0x00004800, 0x0000B100, 0x00001000, 0x00000200);
  //iteData(0x00000100);//}
  //writeData(0x0000FF00);
  setLocation(0x00004000, 0x0000B000,0x00001000, 0x00000300);
writeData(0x00002600);
writeData(0x00004900);
writeData(0x00004900);
writeData(0x00004900);
writeData(0x00003200);
  return 0;
}


