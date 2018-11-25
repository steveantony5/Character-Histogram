//*****************************************************************************
// Name        : report_data
//
// Description : Function to report the data present in circular buffer
//
// Author      : Steve and Swarupa
//
// Date        : Nov 06, 2018
//
// Arguments   : No
//
// return      : status
//				 SUCCESS on completion, otherwise ERROR
//
//****************************************************************************/


//***********************************************************************************
// Include files
//***********************************************************************************
#include "report_data.h"

//***********************************************************************************
// Function definition
//***********************************************************************************

status report_data(CB *buffer)
{
	if((buffer->flag_init) != 1)
	{
		PRINT("Buffer not initialized\r\n");
		return ERROR;
	}
	else if(IsEMPTY(buffer))
	{
		PRINT("No data to display: Buffer is empty\r\n");
		return ERROR;
	}

	else
	{
		struct node* temp;
		
		PRINT("\nElements in the circular buffer:\r\n");
		for((temp = (buffer->front_CB)); (temp!=(buffer->rear_CB));(temp= (temp->link)))
		{
			#ifdef FRDM
			send_to_console((temp->data));
			#else
			printf("%d", temp->data);
			#endif
			PRINT("\r\n");
		}


		#ifdef FRDM
		send_to_console(((buffer->rear_CB)->data));
		#else
		printf("%d",((buffer->rear_CB)->data));
		#endif

		PRINT("\r\n");

		return SUCCESS;
	}
}
