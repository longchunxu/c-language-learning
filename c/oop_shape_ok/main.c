/*
 * @Descripttion: 说明
 * @version: V1.0
 * @Author: LongChunxu
 * @Date: 2022-03-12 17:04:58
 * @LastEditors: LongChunxu
 * @LastEditTime: 2022-03-12 17:57:20
 */
#include <stdio.h>
#include "Shape.h"
int main(int argc,char *argv[]){
    Shape s1 ;
    Shape_ctor(&s1,100,200);
    Shape_moveBy(&s1,-10,10);
    Shape_getX(&s1);
    Shape_getY(&s1);
	return 0;
}
