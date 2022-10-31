/* ###################################################################
**     Filename    : ProcessorExpert.c
**     Project     : ProcessorExpert
**     Processor   : MKL25Z128VLK4
**     Version     : Driver 01.01
**     Compiler    : GNU C Compiler
**     Date/Time   : 2022-10-20, 09:40, # CodeGen: 0
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
#include "Bit1.h"
#include "BitIoLdd1.h"
#include "Bit2.h"
#include "BitIoLdd2.h"
#include "Bit3.h"
#include "BitIoLdd3.h"
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
	LCD_Command(0x1C);
	LCD_Command(0x06);
	LCD_delay();
}

void LCD_Command(unsigned char cmd)
{
	Bits1_PutVal(cmd);
	Bit1_PutVal(0);
	Bit2_PutVal(0);
	Bit3_PutVal(1);
	LCD_delay();
	Bit3_PutVal(0);
	LCD_delay();
}

void LCD_Data_1(unsigned char ascii)
{
	Bits1_PutVal(ascii);
	Bit1_PutVal(1);
	Bit2_PutVal(0);
	Bit3_PutVal(1);
	LCD_delay();
	Bit3_PutVal(0);
	LCD_delay();
}

void LCD_delay()
{
	long int i;
	for(i=0;i<0x7ffff;i++);
}

void LCD_Puts(unsigned char *lcd_string)
{
	while(*lcd_string)
	{
		LCD_Data_1(*lcd_string++);
	}
}

void LCD_display1_line()
{
	
}

void right_shift()
{
	Bit1_PutVal(0);
	Bit2_PutVal(0);
	LCD_Command(0x1C);
}


/*lint -save  -e970 Disable MISRA rule (6.3) checking. */
int main(void)
/*lint -restore Enable MISRA rule (6.3) checking. */
{
  /* Write your local variable definition here */

  /*** Processor Expert internal initialization. DON'T REMOVE THIS CODE!!! ***/
  PE_low_level_init();
  /*** End of Processor Expert internal initialization.                    ***/

  /* Write your code here */
  LCD_init();

  while(1)
  {
	  LCD_Puts("Hello");
	  
	  int i, p;
	  LCD_display1_line();
	  while(i>0)
	  {
		  right_shift();
		  for(p=0;p<0x7ffff;p++);
		  i++;
	  }
	  while(1);
	  LCD_delay();

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
