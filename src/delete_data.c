
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

status delete_data(CB *buffer)
{
	if((buffer->flag_init) != 1)
	{
		printf("Buffer not initialized\n");
		return ERROR;
	}
	else if(IsEMPTY(buffer))
	{
		printf("Nothing to delete: Buffer is empty\n");
		return ERROR;

	}
	else
	{
		(buffer->front_CB) = ((buffer->front_CB) -> link);
		(buffer->length_CB)--;
		printf("Deleted successfully\n");
		return SUCCESS;
	}
}
