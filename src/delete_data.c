
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
	if(flag_init == 0)
	{
		printf("Buffer not initialized\n");
		return ERROR;
	}
	else if(IsEMPTY())
	{
		printf("Nothing to delete: Buffer is empty\n");
		return ERROR;

	}
	else
	{
		(CB.front_CB) = ((CB.front_CB) -> link);
		(CB.length_CB)--;
		printf("Deleted successfully\n");
		return SUCCESS;
	}
}
