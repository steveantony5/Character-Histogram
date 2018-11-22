


#ifndef _COMMON_VARIABLE_H_
#define  _COMMON_VARIABLE_H_

#include <stdint.h>

typedef enum status_t
{
	ERROR = -1,
	SUCCESS = 1,
}status;



struct node
{
	char data;
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

#endif
