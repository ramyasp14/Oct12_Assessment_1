

/* Including needed modules to compile this module/procedure */
#include "Cpu.h"
#include "Events.h"
#include "Bits1.h"
#include "BitsIoLdd1.h"
#include "Seg_CA.h"
#include "BitsIoLdd2.h"
#include "Seg_CC.h"
#include "BitsIoLdd3.h"
#include "LED_CA.h"
#include "BitsIoLdd4.h"
#include "LED_CC.h"
#include "BitsIoLdd5.h"
#include "FRTOS1.h"
#include "MCUC1.h"
#include "UTIL1.h"
#include "UTIL2.h"
/* Including shared modules, which are used for whole project */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"

/* User includes (#include below this line is not maintained by Processor Expert) */


seven_cc()
{
	while(1)
	{
		long int delay;
		int i,j = 0x01;
		for(i=0;i<=7;i++)
		{
			Seg_CC_PutVal(j);
			vTaskDelay(1000 / portTICK_PERIOD_MS);
			j = j<<1;
		}
	}
}

seven_ca()
{
	while(1)
	{
		long int delay;
		Bits1_PutVal(0xFE);
		int i,j = 0x01;
		for(i=0;i<=7;i++)
		{
			Seg_CA_PutVal(~j);
			vTaskDelay(1000 / portTICK_PERIOD_MS);
			j = j<<1;
		}
	}
}


led_anode()
{
	while(1)
	{
		long int delay;
		int i,j=0x08;
		for(i=0;i<=3;i++)
		{
			LED_CA_PutVal(~j^0xF0);
			j=j>>1;
			vTaskDelay(500 / portTICK_PERIOD_MS);
			LED_CA_PutVal(~0xF0);
		}
	}
}

led_cathode()
{
	while(1)
	{
		long int delay;
		int k,l=0x88;
		for(k=0;k<=3;k++)
		{
			LED_CC_PutVal(l);
			l = l>>1;
			vTaskDelay(500 / portTICK_PERIOD_MS);
			LED_CC_PutVal(0);
		}
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
  xTaskCreate(led_cathode, "led_cathode()", 100, NULL, 10, NULL);
  xTaskCreate(led_anode, "led_anode()", 100, NULL, 10, NULL);
  xTaskCreate(seven_ca, "seven_ca()", 100, NULL, 10, NULL);
  xTaskCreate(seven_cc, "seven_cc()", 100, NULL, 10, NULL);


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
