/**
* @file resize_CB.h
* @brief An abstraction for resize_CB.c
*
* This header file provides declarations of resize_CB.c
*
* @author Steve and Swarupa
* @date Nov 6, 2018
*
*/
//***********************************************************************************
// Include files
//***********************************************************************************

#ifndef _RESIZE_CB_H_
#define _RESIZE_CB_H_

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include "common_variable.h"

//***********************************************************************************
// function prototypes
//***********************************************************************************
status resize_CB(CB *,int32_t );
void insert_link(CB *);

#endif
