
//*****************************************************************************
// Name        : pop_data
//
// Description : Function to pop data out of circular Buffer
//
// Author      : Steve and Swarupa
//
// Date        : Nov 18, 2018
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
#include "pop_data.h"

//***********************************************************************************
// Function definition
//***********************************************************************************

status pop_data(CB *buffer,char *data)
{
	if((buffer->flag_init) != 1)
	{
		printf("Buffer not initialized\n");
		return ERROR;
	}
	else if(IsEMPTY(buffer))
	{
		printf("Nothing to pop: Buffer is empty\n");
		return ERROR;

	}
	else
	{
		(*data) = '\0';
		(*data) = ((buffer->front_CB) -> data);
		(buffer->front_CB) = ((buffer->front_CB) -> link);
		(buffer->length_CB)--;
		return SUCCESS;
	}
}
