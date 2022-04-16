/*
 * @Descripttion: 打印log
 * @version: V1.0
 * @Author: LongChunxu
 * @Date: 2022-03-12 17:44:51
 * @LastEditors: LongChunxu
 * @LastEditTime: 2022-03-12 18:06:58
 */
#ifndef DEBUG
#define DEBUG
#define log(frm, argc...) { \
    printf("longchunxu %s[%s : %d] ", __FILE__, __func__, __LINE__);\
    printf(frm, ##argc); \
    printf("\n"); \
}
#else
#define log(frm, argc...) //什么都不做
#endif /* LOG_H */