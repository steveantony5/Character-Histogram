
//*****************************************************************************
// Name        : resize_CB
//
// Description : Function to resize the existing circular Buffer
//
// Author      : Steve and Swarupa
//
// Date        : Nov 06, 2018
//
// Arguments   : elements_to_add - No. of elements to the added to the circular buffer inorder to resize it
//
// return      : status
//				 SUCCESS on completion, otherwise ERROR
//
//****************************************************************************/


//***********************************************************************************
// Include files
//***********************************************************************************
#include "resize_CB.h"

//***********************************************************************************
// Function definition
//***********************************************************************************
status resize_CB(CB *buffer, int32_t elements_to_add)
{
	
	if(elements_to_add<=0)
		return ERROR;

	else if((buffer->flag_init) != 1)
	{
		PRINT("Buffer not initialized\r\n");
		return ERROR;
	}

	else
	{
		for(int i=1; i<=elements_to_add;i++)
		{
			insert_link(buffer);
        }
    }
	return SUCCESS;
}
