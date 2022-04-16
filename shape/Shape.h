/*
 * @Descripttion: 说明
 * @version: V1.0
 * @Author: LongChunxu 
 * @Date: 2022-03-12 17:04:39
 * @LastEditors: LongChunxu
 * @LastEditTime: 2022-03-12 17:49:32
 */
#ifndef SHAPE_H
#define SHAPE_H
#include<stdint.h>
typedef struct {
    int16_t x;
    int16_t y;

}Shape;
//shape
void Shape_ctor(Shape *const me,int16_t x,int16_t y);
void Shape_moveBy(Shape *const me,int16_t dx,int16_t dy);
int16_t Shape_getX(Shape *const me);
int16_t Shape_getY(Shape *const me);
#endif /* SHAPE_H */