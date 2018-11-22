/**
* @file insert_data.h
* @brief An abstraction for insert_data.c
*
* This header file provides declarations of insert_data.c
*
* @author Steve and Swarupa
* @date Nov 6, 2018
*
*/

//***********************************************************************************
// Include files
//***********************************************************************************

#ifndef _INSERT_DATA_H_
#define _INSERT_DATA_H_

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include "common_variable.h"

//***********************************************************************************
// function prototypes
//***********************************************************************************
status insert_data(CB *, char);
int8_t IsEMPTY(CB *);
int8_t IsFULL(CB *);

#endif
