/**
* @file delete_data.h
* @brief An abstraction for delete_data.c
*
* This header file provides declarations of delete_data.c
*
* @author Steve and Swarupa
* @date Nov 6, 2018
*
*/
//***********************************************************************************
// Include files
//***********************************************************************************

#ifndef _DELETE_DATA_H_
#define _DELETE_DATA_H_


#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include "common_variable.h"

//***********************************************************************************
// function prototypes
//***********************************************************************************
status delete_data();
int8_t IsEMPTY();

#endif