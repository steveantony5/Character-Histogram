//*****************************************************************************
// Name        : clear_buffer
//
// Description : Function to clear the data present in circular buffer
//
// Author      : Steve and Swarupa
//
// Date        : Nov 07, 2018
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
#include "clear_buffer.h"

//***********************************************************************************
// Function definition
//***********************************************************************************

status clear_buffer(CB *buffer)
{
	
	if((buffer->flag_init) != 1)
	{
		printf("Buffer not initialized\n");
		return ERROR;
	}
	else if(IsEMPTY(buffer))
	{
		printf("Nothing to clear: Buffer is empty\n");
		return ERROR;
	}
	
	else
	{
		(buffer->front_CB) = (buffer->head);
		(buffer->rear_CB) = (buffer->head);
		(buffer->length_CB) = 0;
		printf("Cleared the buffer\n");
		return SUCCESS;
	}
}
