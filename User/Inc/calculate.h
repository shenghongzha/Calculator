/**
  ******************************************************************************
  * @file           : calculate.h
  * @author         : sanmu
  * @brief          : Complex addition, subtraction, multiplication and division
  *                 @v1.1:Improvement of accuracy
  *                 @v1.2:Added delete and reset functions
  * @email          : shenghongzha@gmail.com
  * @date           : 2023-10-28
  * @version        : v1.2
  ******************************************************************************
  */
// Copyright (c) 2023 Sanmu Dang. All rights reserved.

#ifndef __CALCULATE_H
#define __CALCULATE_H
#ifdef __cplusplus
extern "C" {
#endif
#include "main.h"
typedef struct Numbers{
    double num;
    struct Numbers* next;
}numbers;

typedef struct Symbols{
    uint8_t sym;
    struct Symbols* next;
}symbols;

void process(uint8_t* handle,uint8_t size,numbers* numHead, symbols* symHead);

uint8_t calculate(uint8_t * handle,uint8_t size,numbers* numHead);

#endif //__CALCULATE_H
