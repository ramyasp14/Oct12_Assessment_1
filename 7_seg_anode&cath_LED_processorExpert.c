/* ###################################################################
**     Filename    : ProcessorExpert.c
**     Project     : ProcessorExpert
**     Processor   : MKL25Z128VLK4
**     Version     : Driver 01.01
**     Compiler    : GNU C Compiler
**     Date/Time   : 2022-10-28, 14:40, # CodeGen: 0
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
#include "EInt1.h"
#include "ExtIntLdd1.h"
#include "EInt2.h"
#include "ExtIntLdd2.h"
#include "Seg_CC.h"
#include "BitsIoLdd1.h"
#include "Seg_CA.h"
#include "BitsIoLdd2.h"
#include "Bits3.h"
#include "BitsIoLdd3.h"
#include "LED_CA.h"
#include "BitsIoLdd4.h"
#include "LED_CC.h"
#include "BitsIoLdd5.h"
/* Including shared modules, which are used for whole project */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"

/* User includes (#include below this line is not maintained by Processor Expert) */
void delay()
{
	long int i;
	for(i=0;i<0x7ffff;i++);
}



void led_anode()
{
	int i,j=0x08;
	for(i=0;i<=3;i++)
	{
		LED_CA_PutVal(~j^0xF0);
		j=j>>1;
		delay();
		LED_CA_PutVal(~0xF0);
	}
}

void led_cathode()
{
	int k,l=0x88;
	for(k=0;k<=3;k++)
	{
		LED_CC_PutVal(l);
		l = l>>1;
		delay();
		LED_CC_PutVal(0);
	}
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
  
  while(1)
  {
	  //seven_cc();
	  //seven_ca();
	  led_cathode();
	  led_anode();
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
