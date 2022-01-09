#ifndef INTERFICE_H
#define INTERFICE_H
typedef struct{
    int age;
    int (*eat)(int);
    void (*play)(char *);
}com,*p_com;

p_com getPointInit()
{
    return (p_com)malloc(sizeof(com));
}

int eat(int a)
{
    return printf("eat %d\n",a);
}

void play(char *thing)
{
    printf("paly %s\n",thing);
}

p_com registerModule(p_com p,int age,int (*_eat)(int),void (*_play)(char *))
{
    p->age = age;
    p->eat = _eat;
    p->play = _play;

    return p;
}
#endif /* INTERFICE_H */


