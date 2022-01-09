#include<stdio.h>
#include<stdlib.h>
#include"interface.h"

int main(void)
{
    p_com p = getPointInit();
    p = registerModule(p,24,eat,play);
    p->eat(5);
    p->play("game");
    printf("age = %d\n",p->age);
    return 0;
}
