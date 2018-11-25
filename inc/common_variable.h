


#ifndef _COMMON_VARIABLE_H_
#define  _COMMON_VARIABLE_H_

//#define FRDM
#define LINUX

//#define DEBUG

#include <stdint.h>


#ifdef FRDM
	
	#define POLLING
	#define INTERRUPTS
#endif

typedef enum status_t
{
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

#ifdef FRDM
#define PRINT send_to_console_str
void send_to_console(uint8_t data);
void send_to_console_str(char []);

#else
#define PRINT printf
	
#endif



CB RX_buffer ;

#endif
