/**
* @file init_CB.c
*
* This file contains function for checking if the circular buffer is empty, full 
* and initiating the circular buffer
*
* @author Steve and Swarupa
* @date Nov 6, 2018
*
*/

//***********************************************************************************
// Include files
//***********************************************************************************
#include "init_CB.h"

//***********************************************************************************
// Function definition
//***********************************************************************************

//*****************************************************************************
// Name        : init_CB
//
// Description : Function to initiate a circular buffer
//
// Arguments   : length - Length of the circular buffer to be created
//
// return      : SUCCESS if it is created successfully, otherwise ERROR
//
//****************************************************************************/


status init_CB(int32_t length)
{
	
	head = NULL;
	tail = NULL;
	CB.front_CB = NULL;
	CB.rear_CB = NULL;
	CB.length_CB = 0;
	CB.max_size = 0;

	if(length<=0)
		return ERROR;

	else
	{
		flag_init = 1;
		for(int i=1; i<=length;i++)
		{
			insert_link();
        }
    }
    (CB.front_CB) = head;
    (CB.rear_CB) = head;
	return SUCCESS;
}

//*****************************************************************************
// Name        : IsFULL
//
// Description : Function to check if the circular buffer is FULL
//
// Arguments   : No
//
// return      : 1 if it is Full, otherwise 0
//
//****************************************************************************/

int8_t IsFULL()
{
	if((CB.length_CB) == (CB.max_size))
		return 1;
	else
		return 0;
}


//*****************************************************************************
// Name        : IsEMPTY
//
// Description : Function to check if the circular buffer is Empty
//
// Arguments   : No
//
// return      : 1 if it is Empty, otherwise 0
//
//****************************************************************************/
int8_t IsEMPTY()
{
	if((CB.length_CB) == 0)
		return 1;
	else
		return 0;
}

