
//*****************************************************************************
// Name        : insert_data
//
// Description : Function to insert data to the circular Buffer
//
// Author      : Steve and Swarupa
//
// Date        : Nov 06, 2018
//
// Arguments   : val - Data to be added
//
// return      : status
//				 SUCCESS on completion, otherwise ERROR
//
//****************************************************************************/


//***********************************************************************************
// Include files
//***********************************************************************************
#include "insert_data.h"

//***********************************************************************************
// Function definition
//***********************************************************************************

status insert_data(CB *buffer,char val)
{
	if((buffer->flag_init) != 0)
	{
		printf("Buffer not initialized\n");
		return ERROR;
	}
	else if(IsFULL(buffer))
	{
		printf("\nThe Buffer is FULL\n");
		printf("Adding %c failed\n",val);
		return ERROR;
	}
	else if(((buffer->front_CB) == (buffer->rear_CB))&& (IsEMPTY(buffer)))
	{
		((buffer->rear_CB) -> data) = val;
		(buffer->length_CB)++;
		printf("Added %c to the buffer\n",val);
		return SUCCESS;
	}
	else
	{
		(buffer->rear_CB) = ((buffer->rear_CB) -> link);                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                               
		((buffer->rear_CB) -> data) = val;
		(buffer->length_CB)++;
		printf("Added %c to the buffer\n",val);
		return SUCCESS;
	}
}
