/**
* @file init_CB.h
* @brief An abstraction for init_CB.c
*
* This header file provides declarations of init_CB.c
*
* @author Steve and Swarupa
* @date Nov 6, 2018
*
*/
//***********************************************************************************
// Include files
//***********************************************************************************

#ifndef _CIRCULAR_BUFFER_H_
#define  _CIRCULAR_BUFFER_H_
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include "common_variable.h"

//***********************************************************************************
// function prototypes
//***********************************************************************************


status init_CB(int32_t);
int8_t IsFULL();
int8_t IsEMPTY();
void insert_link();

#endif
