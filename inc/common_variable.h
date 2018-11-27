/**
* @file common_variable.h
* @brief contains the variables used across other files
*
*
* @author Steve and Swarupa
* @date Nov 7, 2018
*
*/
//***********************************************************************************
// Include files
//***********************************************************************************
#ifndef _COMMON_VARIABLE_H_
#define  _COMMON_VARIABLE_H_

//#define FRDM

#define LINUX

//#define DEBUG

#include <stdint.h>


#ifdef FRDM

	#define POLLING
	#define INTERRUPTS
	#define PRINT send_to_console_str
#endif

#ifdef LINUX
	#define PRINT printf
#endif

typedef enum status_t
{
	OVERFLOW = -4,
	EMPTY = -3,
	BUFFER_NOT_INITIALISED = -2,
	ERROR = -1,
	SUCCESS = 1,
}status;



struct node
{
	uint8_t data;
	struct node * link;
};



typedef struct
{
	struct node* front_CB;
	struct node* rear_CB;
	struct node *head;
	struct node *tail;
	int32_t length_CB;
	int32_t max_size;
	int8_t flag_init;
}CB;





CB RX_buffer ;

#endif
