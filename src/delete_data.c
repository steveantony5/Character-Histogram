
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
		PRINT("Buffer not initialized\r\n");
		return ERROR;
	}
	else if(IsEMPTY(buffer))
	{
		PRINT("Nothing to delete: Buffer is empty\r\n");
		return ERROR;

	}
	else
	{
		(buffer->front_CB) = ((buffer->front_CB) -> link);
		(buffer->length_CB)--;
		PRINT("Deleted successfully\r\n");
		return SUCCESS;
	}
}
