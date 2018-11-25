//*****************************************************************************
// Name        : main
//
// Description : Function to call other functions
//
// Author      : Steve and Swarupa
//
// Date        : Nov 06, 2018
//
// Arguments   : No
//
// return      : unused
//
//****************************************************************************/


#include "main.h"

#ifdef FRDM
#include "MKL25Z4.h"
#endif


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

	int16_t database[256] = {0};
	uartinit();
	RX_interrupt_init();
	send_to_console_str("Welcome to Character Histogram Application\r\n");

	init_CB(&RX_buffer, SIZE_OF_RX_CB);

	while(1)
	{
		while(!(IsEMPTY(&RX_buffer)))
		{
			uint8_t data = 0;
			char num[4];

			pop_data(&RX_buffer,&data);

			database[data] = database[data] + 1;

			if(data == 13)
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
			}
		}

	}
#endif

}
