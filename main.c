//*****************************************************************************
// Name        : main
//
// Description : Function to call other functions
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
#include "main.h"
#include "common_variable.h"
//***********************************************************************************
// Function definition
//***********************************************************************************
int main()
{
	init_CB(3);
	report_data();
	insert_data(1);
	printf("%d %p\n",(front_CB->data),(front_CB->link));
	printf("%d %p\n",(rear_CB->data),(rear_CB->link));
	report_data();
}
