
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
		/*CB *tmp = NULL;
		//freeing the circular linked list
		while((buffer->max_size)>0)
		{
			printf("max size %d\n",(buffer->max_size));
			(tmp->head) = (buffer->head);
			(buffer->head) = ((buffer->head) -> link);
			free((tmp->head));
			(buffer->max_size)--;
		}*/

		(buffer->head) = NULL;
		(buffer->tail) = NULL;
		(buffer->front_CB) = NULL;
		(buffer->rear_CB) = NULL;
		(buffer->length_CB) = 0;
		(buffer->max_size) = 0;
		(buffer->flag_init) = 0;
		PRINT("Deleted successfully\r\n");
		return SUCCESS;
	}
}
