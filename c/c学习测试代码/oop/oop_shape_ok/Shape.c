/*
 * @Descripttion: 说明
 * @version: V1.0
 * @Author: LongChunxu
 * @Date: 2022-03-12 17:41:02
 * @LastEditors: LongChunxu
 * @LastEditTime: 2022-03-12 18:16:28
 */
#include "log.h"
#include "Shape.h"
void Shape_ctor(Shape *const me,int16_t x,int16_t y){
    me->x = x;
    me->y = y;
}

void Shape_moveBy(Shape *const me,int16_t dx,int16_t dy){
    me->x += dx;
    me->y += dy;
}

int16_t Shape_getX(Shape *const me){
    log("Shape_getX :%d \n",me->x);
    return me->x;
}

int16_t Shape_getY(Shape *const me){
    log("Shape_getY :%d \n",me->y);
    return me->y;
}
