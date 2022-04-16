/*
 * @Descripttion: 说明
 * @version: V1.0
 * @Author: LongChunxu
 * @Date: 2022-03-13 21:29:22
 * @LastEditors: LongChunxu
 * @LastEditTime: 2022-03-13 22:31:34
 */
#ifndef READER_H
#define READER_H
#include"book.h"
struct reader;
struct book;

typedef int (*P_BORROW)(struct reader*,struct book*);
typedef int (*P_RETURN)(struct reader*,struct book*);
typedef struct 
{
    char *peoplename;
    char *bookname;
    int num;
    int vip_id;
    P_BORROW p_borrow;
    P_RETURN p_return;

}reader,*p_reader;
void reader_ctor(reader *r,char *peoplename,int num, int vip_id);
int borrow_book(reader *r,book *b);
int return_book(reader *r,book *b);
#endif /* READER_H */