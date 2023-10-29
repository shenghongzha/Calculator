/**
  ******************************************************************************
  * @file           : handler.c
  * @author         : sanmu
  * @brief          : Computer logic processing
  *                 @v1.1:Added delete and reset function
  * @email          : shenghongzha@gmail.com
  * @date           : 2023-10-29
  * @version        : v1.1
  ******************************************************************************
  */
// Copyright (c) 2023 Sanmu Dang. All rights reserved.

#include "handler.h"
#include "calculate.h"
#include "show.h"
#include "Error.h"
#include "MatrixKey.h"

/**
 * @brief Computer logic processing function
 * @param keyCode key code
 * @param position pointer to the current display location
 * @param handle mathematical expression
 */
void handler(uint8_t keyCode, uint8_t* position,uint8_t* handle){
    if(keyCode)
    {
        if(*position<48){
            if(keyCode=='d'){
                showDelete(handle,position);
            } else if(keyCode =='r'){
                showReset(handle,position);
            }
            else if(keyCode == '='){
                numbers res;
                if (calculate(handle, *position, &res))
                {
                    showResult(res.num);
                } else{
                    errorDiv0();
                }
            }
            else{
                handle[(*position)++] = keyCode;
                show(handle,*position);
            }
        }
        else{
            errorOfR();
            if(keyCode == '='){
                showReset(handle,  position);
            }
        }
        while(ScanKey()!=0)HAL_Delay(1);
    }
}
    

