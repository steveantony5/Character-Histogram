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
	init_CB(&RX_buffer,1);
	insert_data(&RX_buffer,3);
	report_data(&RX_buffer);

insert:
	if(insert_data(&RX_buffer,3)== OVERFLOW )
	{
		resize_CB(&RX_buffer,((RX_buffer.max_size)*2));
		goto insert;
	}

	report_data(&RX_buffer);




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
