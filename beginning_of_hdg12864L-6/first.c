#include <stm32f4xx.h>
#include<stdint.h>
#include"HDG12864L6.h"
#include<stdio.h>
//#include<inttypes.h>

#include<math.h>

void displayChar(uint32_t , uint32_t , int , unsigned char );

void provideClock(void)
{
    // by default clock frequency is 1 MHz
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
void displayLine(uint32_t, uint32_t, uint32_t, uint32_t);
void DDA(uint32_t, uint32_t, uint32_t, uint32_t);
void DrawLine3(uint32_t, uint32_t, uint32_t, uint32_t);
int main()
{
  //int i,j,r;

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
  //displayDot(55,55,OB);

  //displayLine(44,44,11,11);
  //displayLine(11,11,22,10);
  //displayLine(44,44,88,11);
  //displayChar(55, 55, 'S', 15);
  //displayDot(0,0,OT);
  //displayDot(1,1,OT);
  //displayDot(126,62,OT);
  //displayDot(127,63,OT);
  //displayDot(129,60,OT);
  //displayLine(11,11,22,10);
  //DDA(22,22,44,44);
  //DDA(22,11,44,44);
  //DDA(88,11,44,44);
  //DDA(44,44,22,22);
  //displayDot(44,44,OT);
  //displayDot(88,11,OT);
  //displayLine(44,44,11,11);
  //displayLine(44,44,88,11);
  //DrawLine3(22,11,23,14);
  //DDA(22,11,24,12);
  displayLine(22,11,23,14);
  //DrawLine3(22,22,44,44);
  return 0;
}
// beshmann fails
void displayLine(uint32_t x0, uint32_t y0, uint32_t x1, uint32_t y1)
{
  uint32_t dx, dy, p, x, y, temp;  
  if(x0 > x1)
  {
    temp = x0;
    x0 = x1;
    x1 = temp;
    temp = y0;
    y0 = y1;
    y1 = temp;
  }
  dx = x1 - x0;  
  dy = y1 - y0;  
  x = x0;  
  y = y0;  
  p = 2*dy - dx;  
  while(x < x1)  
  {  
    if(p >= 0)  
    {  
      //putpixel(x,y,7);
      displayDot(x,y,OT);
      y = y + 1;  
      p = p + 2*dy - 2*dx;  
    }  
    else  
    {  
      //putpixel(x,y,7);
      displayDot(x,y,OT);
      p = p + 2*dy;
    }  
    
    x = x + 1;  
  }  
}
void DDA(uint32_t x0, uint32_t y0, uint32_t x1, uint32_t y1)
{
	  uint32_t dx, dy, steps, i, x, y; 
	  dx = (float)(x1 - x0);  
	  dy = (float)(y1 - y0);  
	  if(dx>=dy)  
			  {  
		  steps = dx;  
	  }  
	  else  
			  {  
		  steps = dy;  
	  }  
	  dx = dx/steps;  
	  dy = dy/steps;  
	  x = x0;  
	  y = y0;  
	  i = 1;  
	  while(i<= steps)  
	  {  
		 displayDot(x,y,OT);  
		  x += dx;  
		  y += dy;  
		  i=i+1;  
	  }  
}

/*void displayChar(uint32_t x, uint32_t y, int c, unsigned char area)
{
	//unsigned char sheet[row][col];
	if(area==15)
	{
		if(area=='S')
		{
			displayDot(x,y,OT);
			displayDot(x,y-1,OT);
			displayDot(x,y-2,OT);
			displayDot(x,y-4,OT);
			displayDot(x+1,y,OT);
			displayDot(x+1,y-2,OT);
			displayDot(x+1,y-4,OT);
			displayDot(x+2,y,OT);
			displayDot(x,y-2,OT);
			displayDot(x,y-3,OT);
			displayDot(x,y-4,OT);
			//displayDot(x,y,T);
		}
	}
}*/

//void displayString(uint32_t x, uint32_t y, int c, int area)

void DrawLine3(uint32_t x1, uint32_t y1, uint32_t x2, uint32_t y2)
{
  uint32_t i, deltax, deltay, numpixels;
  uint32_t d, dinc1, dinc2;
  uint32_t x, xinc1, xinc2;
  uint32_t y, yinc1, yinc2;

  //calculate deltaX and deltaY
  deltax = abs(x2 - x1);
  deltay = abs(y2 - y1);
  
  //initialize
  if(deltax >= deltay)
  {
    //If x is independent variable
    numpixels = deltax + 1;
    d = (2 * deltay) - deltax;
    dinc1 = deltay << 1;
    dinc2 = (deltay - deltax) << 1;
    xinc1 = 1;
    xinc2 = 1;
    yinc1 = 0;
    yinc2 = 1;
  }
  else
  {
    //if y is independent variable
    numpixels = deltay + 1;
    d = (2 * deltax) - deltay;
    dinc1 = deltax << 1;
    dinc2 = (deltax - deltay) << 1;
    xinc1 = 0;
    xinc2 = 1;
    yinc1 = 1;
    yinc2 = 1;
  }

  //move the right direction
  if(x1 > x2)
  {
    xinc1 = -xinc1;
    xinc2 = -xinc2;
  }
  if(y1 > y2)
  {
    yinc1 = -yinc1;
    yinc2 = -yinc2;
  }

  x = x1;
  y = y1;
  
  //draw the pixels
  for(i = 1; i < numpixels; i++)
  {
    displayDot(x, y, OT);
    if(d < 0)
    {
      d = d + dinc1;
      x = x + xinc1;
      y = y + yinc1;
    }
    else
    {
      d = d + dinc2;
      x = x + xinc2;
      y = y + yinc2;
    }
  }
}


