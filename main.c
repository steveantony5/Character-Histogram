

#include "main.h"

#ifdef FRDM
#include "MKL25Z4.h"

#define SYSTICK_CTRL (*((volatile unsigned long *) (0xE000E010)))
#define SYSTICK_LOAD (*((volatile unsigned long *) (0xE000E014)))
#define SYSTICK_VAL (*((volatile unsigned long *) (0xE000E018)))
#endif

uint32_t database[256] = {0};
uint8_t data_pop = 0;
int8_t flag_report = 0;
char num[20];
int8_t RX_received = 0;
int count = 0;
int main(void)
{
#ifdef LINUX
	init_CB(&RX_Buffer,5);
	insert_data(&RX_Buffer,3);
	insert_data(&RX_Buffer,10);



	report_data(&RX_Buffer);

	delete_data(&RX_Buffer);
	report_data(&RX_Buffer);

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

	init_CB(&RX_buffer, SIZE_OF_RX_CB);

	while(1)
	{

	}

#endif

}


void sys_reload()
{
	SYSTICK_VAL = 0x0;    //clear current timer value
	SYSTICK_LOAD = 0xFFFFFFFF;
	SYSTICK_CTRL = 0x7;
}

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
	SYSTICK_CTRL = 0x0;
}
