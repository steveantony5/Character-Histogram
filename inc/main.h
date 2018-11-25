/**
* @file main.h
* @brief An abstraction for main.c
*
* This header file provides declarations of main.c
*
* @author Steve and Swarupa
* @date Nov 6, 2018
*
*/

//***********************************************************************************
// Include files
//***********************************************************************************

#ifndef _MAIN_H_
#define _MAIN_H_

#include <stdint.h>
#include <stdio.h>
#include "common_variable.h"

#define SIZE_OF_RX_CB (30)

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

#ifdef FRDM
void uartinit();
void RX_interrupt_init();
#endif

#endif
