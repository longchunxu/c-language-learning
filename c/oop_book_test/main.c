/*
 * @Descripttion: 说明
 * @version: V1.0
 * @Author: LongChunxu
 * @Date: 2022-03-13 21:28:45
 * @LastEditors: LongChunxu
 * @LastEditTime: 2022-03-13 22:46:27
 */
#include"book.h"
#include"reader.h"
#include<stdio.h>

int main(void){
    printf("0000\n");
    book b1;
    printf("00 \n");
    book_ctor(&b1,"math",NULL);
    printf("11 b1.book_name = %s \n",b1.book_name);
    reader r1;
    reader_ctor(&r1,"longchunxu",1,1);
    printf("22\n");
    r1.p_borrow(&r1,&b1);
    printf("33");
    r1.p_return(&r1,&b1);
    return 0;

}