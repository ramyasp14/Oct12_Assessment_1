/* ###################################################################
**     Filename    : ProcessorExpert.c
**     Project     : ProcessorExpert
**     Processor   : MKL25Z128VLK4
**     Version     : Driver 01.01
**     Compiler    : GNU C Compiler
**     Date/Time   : 2022-10-31, 15:17, # CodeGen: 0
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
#include "TI1.h"
#include "TimerIntLdd1.h"
#include "TU1.h"
#include "LCD_RS.h"
#include "BitIoLdd1.h"
#include "LCD_RW.h"
#include "BitIoLdd2.h"
#include "LCD_EN.h"
#include "BitIoLdd3.h"
/* Including shared modules, which are used for whole project */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"

/* User includes (#include below this line is not maintained by Processor Expert) */
int hr, min, sec;
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


void LCD_delay()
{
	long int i;
	for(i=0;i<0x7fff;i++);
}

void hour(int hrs)
{
	int hr1, hr2;
	
	LCD_Command(0x80);
	hr1 = hrs/10;
	LCD_Data(hr1+48);
	
	LCD_Command(0x81);
	hr2 = hrs%10;
	LCD_Data(hr2+48);
	
	LCD_Data(':');
	LCD_Command(0x82);
	LCD_delay();


}

void minute(int mins)
{
	int min1, min2;
	
	LCD_Command(0x83);
	min1 = mins/10;
	LCD_Data(min1+48);
	
	LCD_Command(0x84);
	min2 = mins%10;
	LCD_Data(min2+48);
	
	LCD_Data(':');
	LCD_Command(0x85);
	LCD_delay();

}

void second(int secs)
{
	int sec1, sec2;

	LCD_Command(0x86);
	sec1 = secs/10;
	LCD_Data(sec1+48);
	
	LCD_Command(0x87);
	sec2 = secs%10;
	LCD_Data(sec2+48);

	LCD_delay();
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
	 hour(hr);
	 minute(min);
	 second(sec);
	 
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
