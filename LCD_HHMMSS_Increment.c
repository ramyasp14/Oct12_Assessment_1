/* ###################################################################
**     Filename    : ProcessorExpert.c
**     Project     : ProcessorExpert
**     Processor   : MKL25Z128VLK4
**     Version     : Driver 01.01
**     Compiler    : GNU C Compiler
**     Date/Time   : 2022-10-21, 12:19, # CodeGen: 0
**     Abstract    :
**         Main module.
**         This module contains user's application code.
**     Settings    :
**     Contents    :
**         No public methods
**
** ###################################################################*/
/*!
** @file ProcessorExpert.c
** @version 01.01
** @brief
**         Main module.
**         This module contains user's application code.
*/         
/*!
**  @addtogroup ProcessorExpert_module ProcessorExpert module documentation
**  @{
*/         
/* MODULE ProcessorExpert */


/* Including needed modules to compile this module/procedure */
#include "Cpu.h"
#include "Events.h"
#include "Bits1.h"
#include "BitsIoLdd1.h"
#include "LCD_RS.h"
#include "BitIoLdd1.h"
#include "LCD_RW.h"
#include "BitIoLdd2.h"
#include "LCD_EN.h"
#include "BitIoLdd3.h"
#include "SW5.h"
#include "BitIoLdd4.h"
/* Including shared modules, which are used for whole project */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"

/* User includes (#include below this line is not maintained by Processor Expert) */

void LCD_init()
{
	LCD_Command(0x01);
	LCD_Command(0x38);
	LCD_Command(0x0F);
	LCD_Command(0x80);
	LCD_Command(0x06);
	LCD_delay();
}

void LCD_Command(unsigned char cmd)
{
	Bits1_PutVal(cmd);
	LCD_RS_PutVal(0);
	LCD_RW_PutVal(0);
	LCD_EN_PutVal(1);
	LCD_delay();
	LCD_EN_PutVal(0);
}

void LCD_Data(unsigned char c)
{
	Bits1_PutVal(c);
	LCD_RS_PutVal(1);
	LCD_RW_PutVal(0);
	LCD_EN_PutVal(1);
	LCD_delay();
	LCD_EN_PutVal(0);
}

/* void LCD_Data_string(unsigned char *lcd_string)
{
	while(*lcd_string)
	{
		LCD_Data(*lcd_string++);
	}
	LCD_Delay();
}*/


void LCD_delay()
{
	long int i;
	for(i=0;i<0x7fff;i++);
}

void hour(int hr)
{
	int hr1, hr2;
	
	LCD_Command(0x80);
	hr1 = hr/10;
	LCD_Data(hr1+48);
	
	LCD_Command(0x81);
	hr2 = hr%10;
	LCD_Data(hr2+48);
	
	/*hr2++;
	hr1++;
	if(hr1 == 2 && hr2 == 4)
	{
		hr1 = 0;
		hr2 = 0;
		LCD_delay();
	}*/
	
	LCD_Data(':');
	LCD_Command(0x82);
	LCD_delay();


}

void minute(int min)
{
	int min1, min2;
	
	LCD_Command(0x83);
	min1 = min/10;
	LCD_Data(min1+48);
	
	LCD_Command(0x84);
	min2 = min%10;
	LCD_Data(min2+48);
	

	/*min2++;
	min1++;
	if(min1 == 6 && min2 == 0)
	{
		min1 = 0;
		min2 = 0;
		LCD_delay();
	}*/
	
	LCD_Data(':');
	LCD_Command(0x85);
	LCD_delay();

}

void second(int sec)
{
	int sec1, sec2;

	LCD_Command(0x86);
	sec1 = sec/10;
	LCD_Data(sec1+48);
	
	LCD_Command(0x87);
	sec2 = sec%10;
	LCD_Data(sec2+48);
	
	/*sec2++;
	sec1++;
	if(sec1 == 6 && sec2 == 0)
	{
		sec1 = 0;
		sec2 = 0;
		LCD_delay();
	}*/

}

/*lint -save  -e970 Disable MISRA rule (6.3) checking. */
int main(void)
/*lint -restore Enable MISRA rule (6.3) checking. */
{
  /* Write your local variable definition here */
	long int i;
	

  /*** Processor Expert internal initialization. DON'T REMOVE THIS CODE!!! ***/
  PE_low_level_init();
  /*** End of Processor Expert internal initialization.                    ***/

  /* Write your code here */
  LCD_init();
  int hr = 2;
  int min = 30;
  int sec = 20;
  while(1)
  {
	  //LCD_Data_string("00:00:00");

	  hour(hr++);
	  minute(min++);
	  second(sec++);
	  for(i=0;i<=0x7ffff;i++);
	  //LCD_Delay();
  }
  /* For example: for(;;) { } */

  /*** Don't write any code pass this line, or it will be deleted during code generation. ***/
  /*** RTOS startup code. Macro PEX_RTOS_START is defined by the RTOS component. DON'T MODIFY THIS CODE!!! ***/
  #ifdef PEX_RTOS_START
    PEX_RTOS_START();                  /* Startup of the selected RTOS. Macro is defined by the RTOS component. */
  #endif
  /*** End of RTOS startup code.  ***/
  /*** Processor Expert end of main routine. DON'T MODIFY THIS CODE!!! ***/
  for(;;){}
  /*** Processor Expert end of main routine. DON'T WRITE CODE BELOW!!! ***/
} /*** End of main routine. DO NOT MODIFY THIS TEXT!!! ***/

/* END ProcessorExpert */
/*!
** @}
*/
/*
** ###################################################################
**
**     This file was created by Processor Expert 10.3 [05.08]
**     for the Freescale Kinetis series of microcontrollers.
**
** ###################################################################
*/
