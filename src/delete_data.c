
//*****************************************************************************
// Name        : delete_data
//
// Description : Function to delete data from the circular Buffer
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
#include "delete_data.h"

//***********************************************************************************
// Function definition
//***********************************************************************************

status delete_data()
{
	if((IsEMPTY())&& flag ==0)
	{
		printf("Buffer is empty\n");
		return ERROR;

	}
	else if((IsEMPTY())&& flag ==1)
	{
		flag = 0;
		return SUCCESS;
	}
	else
	{
		front_CB = (front_CB -> link);
		return SUCCESS;
	}
}
