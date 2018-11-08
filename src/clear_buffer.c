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

status clear_buffer()
{
	
	if(flag_init == 0)
	{
		printf("Buffer not initialized\n");
		return ERROR;
	}
	else if(IsEMPTY())
	{
		printf("Nothing to clear: Buffer is empty\n");
		return ERROR;
	}
	
	else
	{
		(CB.front_CB) = head;
		(CB.rear_CB) = head;
		CB.length_CB = 0;
		printf("Cleared the buffer\n");
		return SUCCESS;
	}
}
