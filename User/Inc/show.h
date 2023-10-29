/**
  ******************************************************************************
  * @file           : show.h
  * @author         : sanmu
  * @brief          : Display rendering
  *                 @v1.1:Added delete and reset function
  * @email          : shenghongzha@gmail.com
  * @date           : 2023-10-29
  * @version        : v1.1
  ******************************************************************************
  */
// Copyright (c) 2023 Sanmu Dang. All rights reserved.

#ifndef __PROCESS_H
#define __PROCESS_H
#ifdef __cplusplus
extern "C" {
#endif
#include "main.h"

void showInit();

void show(uint8_t* handle, int point);

void showDelete(uint8_t* handle, uint8_t* ppoint);

void showReset(uint8_t* handle,uint8_t* ppoint);

void showResult(double res);

#endif //__PROCESS_H
