/*
 * @Descripttion: 说明
 * @version: V1.0
 * @Author: LongChunxu
 * @Date: 2022-03-13 21:28:55
 * @LastEditors: LongChunxu
 * @LastEditTime: 2022-03-13 22:48:04
 */
#include "reader.h"
#include <string.h>
void reader_ctor(reader *r,char *peoplename,int num, int vip_id){
    r->peoplename = peoplename;
    r->vip_id = vip_id;
    r->p_borrow = borrow_book;
    r->p_return = return_book;
}

int borrow_book(reader *r,book *b){
    printf("borrow book come here \n");
    r->bookname = b->book_name;
  //  strcpy(r->bookname,b->book_name);
    printf("borrow book name: %s \n",r->bookname);
    return 0;
}
int return_book(reader *r,book *b){
    r->bookname = NULL;
    if (r->bookname ==NULL) 
    printf("return ok\n");
    else
    printf("return nonnok\n");
    return 0;
}