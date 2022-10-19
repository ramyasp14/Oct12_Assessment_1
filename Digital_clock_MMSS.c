/* ###################################################################
**     Filename    : ProcessorExpert.c
**     Project     : ProcessorExpert
**     Processor   : MKL25Z128VLK4
**     Version     : Driver 01.01
**     Compiler    : GNU C Compiler
**     Date/Time   : 2022-10-19, 09:37, # CodeGen: 0
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
#include "Bits2.h"
#include "BitsIoLdd2.h"
/* Including shared modules, which are used for whole project */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"

/* User includes (#include below this line is not maintained by Processor Expert) */

int arr[11] = {0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f};
//long int i;

void Mux(minTemp,minNum,secTemp,secNum)
{
	int i,j;
	  for(j=0;j<100;j++)
	  {
		  Bits1_PutVal(~arr[minTemp]);
		  Bits2_PutVal(0xF7);
		  for(i=0;i<0x7ff;i++);
		  
		  Bits1_PutVal(~arr[minNum]);
		  Bits2_PutVal(0xFB);
		  for(i=0;i<0x7ff;i++);
		  
		  Bits1_PutVal(~arr[secTemp]);
		  Bits2_PutVal(0xFD);
		  for(i=0;i<0x7ff;i++);
		  
		  Bits1_PutVal(~arr[secNum]);
		  Bits2_PutVal(0xFE);
		  for(i=0;i<0x7ff;i++);

	  }
}


/*lint -save  -e970 Disable MISRA rule (6.3) checking. */
int main(void)
/*lint -restore Enable MISRA rule (6.3) checking. */
{
  /* Write your local variable definition here */
	unsigned char k1[2]={0xFE,0xFD};
	unsigned char k2[2]={0xFB,0xF7};
	int minNum = 0x6D;
	int minTemp = 0x66;
	int secNum = 0x06;
	int secTemp = 0x4f;
	int minCnt=0;
	int seccnt=0;;

  /*** Processor Expert internal initialization. DON'T REMOVE THIS CODE!!! ***/
  PE_low_level_init();
  /*** End of Processor Expert internal initialization.                    ***/

  /* Write your code here */
  
  while(1)
  {
	  
		secNum = seccnt;
		secTemp = secNum/10;
		secNum = secNum%10;
		
		
		
		if (secNum == 10)
		{
			secTemp++;
			secNum=0;
		}
			
	   if (secTemp == 6 && secNum == 0)
	   {
				minNum = minCnt;
				minTemp = minNum/10;
				minNum = minNum%10;
	
				
				
				if (minNum == 10)
				{
					minTemp++;
					minNum=0;
				}
				minCnt++;
				seccnt=0;
	   }

	  Mux(minTemp,minNum,secTemp,secNum);
	  seccnt++;
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
