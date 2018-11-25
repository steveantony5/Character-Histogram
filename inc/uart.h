/*
 * uart.h
 *
 *  Created on: Nov 7, 2018
 *      Author: Swarupa De
 */

#ifdef FRDM

#ifndef INCLUDE_UART_H_
#define INCLUDE_UART_H_

#include "common_variable.h"

#ifdef FRDM
void uartinit();
status receive_from_console();

#endif

status resize_CB(CB *, int32_t );
void insert_link(CB *);
status insert_data(CB *,uint8_t);
int8_t IsEMPTY(CB *);
int8_t IsFULL(CB *);
status delete_data(CB *);
status init_CB(CB *,int32_t);
status report_data(CB *);
status clear_buffer(CB *);
status pop_data(CB *,uint8_t *);






#endif /* INCLUDE_UART_H_ */


#endif