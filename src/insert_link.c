//*****************************************************************************
// Name        : insert_link.c
//
// Description : Function to insert a link to the circular linked list
//
// Author      : Steve and Swarupa
//
// Date        : Nov 06, 2018
//
// Arguments   : No
//
// return      : unused
//
//****************************************************************************/

//***********************************************************************************
// Include files
//***********************************************************************************
#include "insert_link.h"

//***********************************************************************************
// Function definition
//***********************************************************************************

void insert_link(CB *buffer)
{
	struct node *temp = (struct node *) malloc (sizeof(struct node));
    temp->data = '\0';
    temp->link = NULL;

    if((buffer->head)!= NULL)
    {
    	(temp->link) = (buffer->head);
        (buffer->head) = temp;
        ((buffer->tail)->link) = (buffer->head);
    }
    else
    {
    	(buffer->head) = temp;
    	(buffer->tail) = temp;
		((buffer->tail) -> link) = temp;
    }
    (buffer->max_size)++;

}
