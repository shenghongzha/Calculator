/**
  ******************************************************************************
  * @file           : handler.h
  * @author         : sanmu
  * @brief          : Computer logic processing
  *                 @v1.1:Added delete and reset function
  * @email          : shenghongzha@gmail.com
  * @date           : 2023-10-29
  * @version        : v1.1
  ******************************************************************************
  */
// Copyright (c) 2023 Sanmu Dang. All rights reserved.

#ifndef __HANDLER_H
#define __HANDLER_H
#ifdef __cplusplus
extern "C" {
#endif
#include "main.h"

void handler(uint8_t keyCode, uint8_t* position,uint8_t* handle);

#endif //__HANDLER_H
