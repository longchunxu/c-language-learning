/*
 * @Descripttion: 说明
 * @version: V1.0
 * @Author: LongChunxu
 * @Date: 2022-03-13 21:29:37
 * @LastEditors: LongChunxu
 * @LastEditTime: 2022-03-13 22:25:22
 */
#ifndef BOOK_H
#define BOOK_H


typedef struct{
    char *book_name;
    char *people_name;

}book,*p_book;

void book_ctor(book *b,char *book_name,char *people_name);
void set_book_name(book *b,char *book_name);
void set_people_name(book *b,char *people_name);
void get_book_name(book b);
void get_people_name(book b);

#endif /* BOOK_H */