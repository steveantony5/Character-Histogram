
//*****************************************************************************
// Name        : delete_CB
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
#include "delete_CB.h"

//***********************************************************************************
// Function definition
//***********************************************************************************

status delete_CB(CB *buffer)
{
	//check if the buffer is initialised
	if((buffer->flag_init) != 1)
	{
		PRINT("Buffer not initialized\r\n");
		return BUFFER_NOT_INITIALISED;
	}

	//desroying the circular buffer
	else
	{
		free(buffer->head);
		free(buffer->tail);
		free(buffer->front_CB);
		free(buffer->rear_CB);
		(buffer->head) = NULL;
		(buffer->tail) = NULL;
		(buffer->front_CB) = NULL;
		(buffer->rear_CB) = NULL;
		PRINT("Deleted successfully\r\n");
		return SUCCESS;
	}
}