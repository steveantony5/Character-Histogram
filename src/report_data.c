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
	int32_t count=0;
	if(IsEMPTY())
	{
		printf("Buffer is empty\n");
		return ERROR;
	}
	else
	{
		struct node* temp;
		

		for(temp = front_CB; (temp!=rear_CB);(temp= (temp->link)))
		{
			count++;
			printf("data %d\n",(temp->data));
		}
		printf("data %d\n",(rear_CB->data));

		return SUCCESS;
	}
}
