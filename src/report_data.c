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

status report_data()
{
	if(flag_init == 0)
	{
		printf("Buffer not initialized\n");
		return ERROR;
	}
	else if(IsEMPTY())
	{
		printf("No data to display: Buffer is empty\n");
		return ERROR;
	}

	else
	{
		struct node* temp;
		
		printf("\nElements in the circular buffer:\n");
		for((temp = CB.front_CB); (temp!=(CB.rear_CB));(temp= (temp->link)))
		{
			printf("Data: %c\n",(temp->data));
		}
		printf("Data: %c\n",((CB.rear_CB)->data));

		return SUCCESS;
	}
}
