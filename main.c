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
	CB RX_Buffer;
	init_CB(&RX_Buffer,5);
	insert_data(&RX_Buffer,3);
	insert_data(&RX_Buffer,10);



	report_data(&RX_Buffer);

	delete_data(&RX_Buffer);
	report_data(&RX_Buffer);

	CB TX_Buffer;
	init_CB(&TX_Buffer,1);
	insert_data(&TX_Buffer,9);
	insert_data(&TX_Buffer,2);
	report_data(&TX_Buffer);

}
