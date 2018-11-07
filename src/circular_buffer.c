/**
* @file circular_buffer.c
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
#include "circular_buffer.h"

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
	
	if(length<=0)
		return ERROR;

	else
	{
		for(int i=1; i<=length;i++)
		{
			insert_link();
			/*if(i==length)
			{
				front_CB = head;
    			rear_CB = head;
			}*/
        }
    }
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
	if((rear_CB ->link) == front_CB)
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
	if((front_CB == NULL) && (front_CB == NULL))
		return 1;
	else
		return 0;
}

