/**
* @file main.c
*
* 
* @author Steve and Swarupa
* @date Nov 6, 2018
*
*/

//***********************************************************************************
// Include files
//***********************************************************************************

#include "main.h"

#ifdef FRDM
#include "MKL25Z4.h"
#define SYSTICK_CTRL (*((volatile unsigned long *) (0xE000E010)))
#define SYSTICK_LOAD (*((volatile unsigned long *) (0xE000E014)))
#define SYSTICK_VAL (*((volatile unsigned long *) (0xE000E018)))
#endif

uint32_t database[256] = {0};
uint8_t data_pop = 0;
char num[20];


//***********************************************************************************
// Function definition
//***********************************************************************************

//*****************************************************************************
// Name        : main
//
// Description : main function
//
// Arguments   : none
//
// return      : unused
//
//****************************************************************************/
int main(void)
{

#ifdef LINUX
	init_CB(&RX_buffer,5);
	insert_data(&RX_buffer,3);
	insert_data(&RX_buffer,10);



	report_data(&RX_buffer);

	delete_CB(&RX_buffer);
	report_data(&RX_buffer);

	CB TX_Buffer;
	init_CB(&TX_Buffer,1);
	insert_data(&TX_Buffer,9);
	insert_data(&TX_Buffer,2);
	report_data(&TX_Buffer);
#endif

#ifdef FRDM


	uartinit();
	RX_interrupt_init();

	send_to_console_str("Welcome to Character Histogram Application\r\n");

	//initiating the circular buffer
	init_CB(&RX_buffer, SIZE_OF_RX_CB);

	while(1)
	{

	}

#endif

}

#ifdef FRDM
//***********************************************************************************
// Function definition
//***********************************************************************************

//*****************************************************************************
// Name        : sys_reload
//
// Description : function to reload the systick timer
//
// Arguments   : none
//
// return      : unused
//
//****************************************************************************/
void sys_reload()
{
	SYSTICK_VAL = 0x0;    //clear current timer value
	SYSTICK_LOAD = 0xFFFFFFFF; //loading value
	SYSTICK_CTRL = 0x7; //enabling interrupt
}

//***********************************************************************************
// Systick ISR definition
//***********************************************************************************

//*****************************************************************************
// Name        : SysTick_Handler
//
// Description : ISR for systick timer which has the report generation part
//
// Arguments   : none
//
// return      : unused
//
//****************************************************************************/
void SysTick_Handler(void)
{
	PRINT("\r\n\r\n");
	PRINT("Report:\r\n");
	for(int i =0;i<256;i++)
	{
		if(database[i]!= 0)
		{
			sprintf(num," %c - %d \r\n",i,database[i]);
			PRINT(num);
		}
	}
	// disabling the systick interrupt
	SYSTICK_CTRL = 0x0;
}

#endif