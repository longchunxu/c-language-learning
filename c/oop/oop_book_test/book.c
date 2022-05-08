/*
 * @Descripttion: 说明
 * @version: V1.0
 * @Author: LongChunxu
 * @Date: 2022-03-13 21:29:10
 * @LastEditors: LongChunxu
 * @LastEditTime: 2022-03-13 21:49:48
 */
#include"book.h"
void book_ctor(book *b,char *book_name,char *people_name){
    b->book_name = book_name;
    b->people_name = people_name;
}
void set_book_name(book *b,char *book_name){
    b->book_name = book_name;
}
void set_people_name(book *b,char *people_name){
    b->people_name = people_name;
}
void get_book_name(book b){
    printf("bookname: %s \n",b.book_name);
}
void get_people_name(book b){
    printf("bookname: %s \n",b.people_name);
}