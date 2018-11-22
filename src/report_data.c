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
		printf("Buffer not initialized\n");
		return ERROR;
	}
	else if(IsEMPTY(buffer))
	{
		printf("No data to display: Buffer is empty\n");
		return ERROR;
	}

	else
	{
		struct node* temp;
		
		printf("\nElements in the circular buffer:\n");
		for((temp = (buffer->front_CB)); (temp!=(buffer->rear_CB));(temp= (temp->link)))
		{
			printf("Data: %c\n",(temp->data));
		}
		printf("Data: %c\n",((buffer->rear_CB)->data));

		return SUCCESS;
	}
}
