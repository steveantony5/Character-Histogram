


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
	int32_t data;
	struct node * link;
};

struct node* front_CB;
struct node* rear_CB;

struct node *head;
struct node *tail;
int flag;

#endif
