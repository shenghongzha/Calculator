/**
  ******************************************************************************
  * @file           : show.c
  * @author         : sanmu
  * @brief          : Display rendering
  *                 @v1.1:Added delete and reset function
  * @email          : shenghongzha@gmail.com
  * @date           : 2023-10-29
  * @version        : v1.1
  ******************************************************************************
  */
// Copyright (c) 2023 Sanmu Dang. All rights reserved.

#include "show.h"
#include "OLED.h"
#include <string.h>
#include "stdio.h"

/**
 * @brief Initialize the rendering function
 */
void showInit(){
    OLED_Init();
}

/**
 * @brief Renders the currently updated character
 * @param handle mathematical expression
 * @param point the current display location
 */
void show(uint8_t * handle, int point){
    switch ((point - 1) / 16){
        case 1:
            OLED_ShowChar(2,((point - 1) % 16) + 1 ,handle[point-1]);
            break;
        case 2:
            OLED_ShowChar(3,((point - 1) % 16) + 1,handle[point-1]);
            break;
        case 3:
            break;
        default:
            OLED_ShowChar(1,((point - 1) % 16) + 1,handle[point-1]);
    }
}

/**
 * @brief Render deleted characters
 * @param handle mathematical expression
 * @param ppoint pointer to the current display location
 */
void showDelete(uint8_t* handle, uint8_t* ppoint){
    handle[--(*ppoint)]=0;
    OLED_ShowChar(*ppoint  / 16 + 1,(*ppoint  % 16) + 1,' ');
}

/**
 * @brief Reset the math expression and screen
 * @param handle mathematical expression
 * @param ppoint pointer to the current display location
 */
void showReset(uint8_t* handle, uint8_t* ppoint){
    memset(handle,0,sizeof(handle));
    *ppoint = 0;
    OLED_Clear();
}

/**
 * @brief Render result
 * @param res result
 */
void showResult(double res)
{
    char resStr[20];
    sprintf(resStr,"%.4lf",res);
    OLED_ShowString(4, 1, resStr);
}
