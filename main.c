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
	resize_CB(2);
	delete_data();
	init_CB(3);
	insert_data('1');
	insert_data('a');
	insert_data(',');
	insert_data('f');
	insert_data('o');
	report_data();

	init_CB(1);

	insert_data('1');	
	report_data();
	
	/*printf("max %d",(CB.max_size));
	printf("leng %d\n",(CB.length_CB));
	insert_data('1');
		printf("max %d",(CB.max_size));
	printf("leng %d\n",(CB.length_CB));
	
	report_data();
	printf("\nclear\n");
	clear_buffer();
	printf("max %d",(CB.max_size));
	printf("leng %d\n",(CB.length_CB));
	insert_data('A');
	printf("max %d",(CB.max_size));
	printf("leng %d\n",(CB.length_CB));
	insert_data('B');
	report_data();*/
	//printf("%d %p\n",(front_CB->data),(front_CB->link));
	//printf("%d %p\n",(rear_CB->data),(rear_CB->link));





}
