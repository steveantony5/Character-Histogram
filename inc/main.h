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



status resize_CB(int32_t );
void insert_link();
status insert_data(char);
int8_t IsEMPTY();
int8_t IsFULL();
status delete_data();
status init_CB(int32_t);
status report_data();
status clear_buffer();
#endif
