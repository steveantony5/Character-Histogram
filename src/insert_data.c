
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

status insert_data(char val)
{
	if(flag_init == 0)
	{
		printf("Buffer not initialized\n");
		return ERROR;
	}
	else if(IsFULL())
	{
		printf("\nThe Buffer is FULL\n");
		printf("Adding %c failed\n",val);
		return ERROR;
	}
	else if(((CB.front_CB) == (CB.rear_CB))&& (IsEMPTY()))
	{
		((CB.rear_CB) -> data) = val;
		(CB.length_CB)++;
		printf("Added %c to the buffer\n",val);
		return SUCCESS;
	}
	else
	{
		(CB.rear_CB) = ((CB.rear_CB) -> link);                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                               
		((CB.rear_CB) -> data) = val;
		(CB.length_CB)++;
		printf("Added %c to the buffer\n",val);
		return SUCCESS;
	}
}
