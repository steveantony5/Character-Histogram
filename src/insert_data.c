
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

status insert_data(int32_t val)
{
	static int32_t initial = 0;
	if(initial == 0)
	{
		front_CB = head;
    	rear_CB = head;
	}	
	if(IsFULL())
	{
		printf("The Buffer is FULL");
		return ERROR;
	}
	else if((IsEMPTY()) && (flag ==0))
	{
		(rear_CB -> data) = val;
		flag =1;
		return SUCCESS;
	}
	else
	{
		rear_CB = (rear_CB -> link);                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                               
		rear_CB -> data = val;
		return SUCCESS;
	}
}
