#include <stm32f4xx.h>

// cmds
#define display_on 0x0000AF00
#define display_off 0x0000AE00
#define adc_normal 0x0000A000
#define adc_reverse 0x0000A100
#define display_normal 0x0000A600
#define display_reverse 0x0000A700
#define display_all_points 0x0000A500
#define displayAP_normal 0x0000A400
#define bias0 0x0000A200
#define bias1 0x0000A300

void provideClock(void)
{
    // by default 16MHz HSI is selected
    // providing clk to port A,B,C 
    RCC->AHB1ENR = 0x00000007
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
 
 void writeCmd(unsigned char cmd)
 {
    // A0 = 0 i.e instrurction and write mode is selected  
    GPIOB->ODR = 0x00000000;
    // sending the cmd
    GPIOA->ODR = cmd;
    // enable clock
    GPIOB->ODR = GPIO_ODR_ODR_2;
    delay();
    GPIOB->ODR &= ~(GPIO_ODR_ODR_2);
 }
 
 void writeData(unsigned char data)
 {
    // A0 = 1 i.e data and write mode is selected  
    GPIOB->ODR = 0x00000001;
    // sending the cmd
    GPIOA->ODR = data;
    // enable clock
    GPIOB->ODR = GPIO_ODR_ODR_2;
    delay();
    GPIOB->ODR &= ~(GPIO_ODR_ODR_2);
 }
  
  void setLocation(unsigned char st_line, unsigned char pg_adrs, unsigned char up_add, unsigned char low_add)
  {
    /*unsigned char up_add,low_add;
    up_add = col_adrs;
    up_add |= ( 0 >> 4 );
    low_add = col_adrs;
    low_add &= 0x00000001;*/
    
    // start line 0x00004000 to 0x00007F00
    writeCmd(st_line);
    // page address 0x0000B000 to 0x0000BF00
    writeCmd(pg_adrs);
    // segment selection upper address 0x00001000 to 0x00001800
    writeCmd(up_add);
    // segment selection upper address 0x00000000 to 0x00000F00
    writeCmd(low_add);
  }

  void glcdInit(void)
  {
    // display ON
    writeCmd(display_on);
    // ADC select   adc_normal OR adc_reverse
    writeCmd(adc_normal);
    // display direction ---- normal OR reverse
    writeCmd(display_normal);
    // display all points or display normal
    writeCmd(displayAP_normal);
    // LCD bias set sed1565 bias0 = 1/9 and bias1 = 1/7
    writeCmd(bias0);
    // common output mode select
    writeCmd(0x0000C000);
  }
  void increment(void)
  {
    // increment column address by 1
    writeCmd(0x0000E000);
  }

  void reset(void)
  {
    // internal reset
    writeCmd(0x0000E200);
  }

int main (void)
 { 
   // Write your code here
    
     provideClock();
    
      // setting gpioa(pin - 0,1,2,3,4,5,6,7) as output
      GPIOA->MODER = 0x55550000;
      GPIOA->OTYPER = 0x00000000;		// setting as push-pull
      GPIOA->OSPEEDR = 0x00000000;		// setting at low speed
      GPIOA->PUPDR = 0x00000000;		// no use because setted as output
      
       // setting gpiob( pin - 0,1,2) as output
      GPIOB->MODER = 0x00000015;
      GPIOB->OTYPER = 0x00000000;		// setting as push-pull
      GPIOB->OSPEEDR = 0x00000000;		// setting at low speed
      GPIOB->PUPDR = 0x00000000;		// no use because setted as output
    
      glcdInit();
      //sendData(0x00000065);
      setLocation(0x00004000, 0x0000B100, 0x00000000, 0x00000000);
      writeData(0x00002600);
      increment();
      writeData(0x00004900);
      increment();
      writeData(0x00004900);
      increment();
      writeData(0x00004900);
      increment();
      writeData(0x00003200);
      increment();
      //writeData(0x000000);
    
   while (1)
   {
 
   }
   return 0;
 }   
