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

void insert_link()
{
	struct node *temp = (struct node *) malloc (sizeof(struct node));
    temp->data = '\0';
    temp->link = NULL;

    if(head!= NULL)
    {
    	temp->link = head;
        head = temp;
        tail->link = head;
    }
    else
    {
    	head = temp;
    	tail = temp;
		tail -> link = temp;
    }
    (CB.max_size)++;

}
