/*
 * @Descripttion: 说明
 * @version: V1.0
 * @Author: LongChunxu
 * @Date: 2022-10-02 19:41:51
 * @LastEditors: LongChunxu
 * @LastEditTime: 2022-10-02 21:03:28
 */
#include <stdio.h>

typedef struct  State {
    int state;
    void (*stop)();
    void (*playOrPause)();
}State;

//定义当前的状态
State *pCurrentStaus = NULL;

enum c_state {
    INIT = 0,
    CLOSE,
    OPEN,
    RESUME,
    PAUSE,
};

void init_stop_music();
void init_play_music();
void open_stop_music();
void open_play_music();
void pause_stop_music();
void pause_play_music();
void close_stop_music();
void close_play_music();
void resume_stop_music();
void resume_play_music();
void sys_play_music();
void sys_stop_music();


State open = {
    .state = OPEN,
    .stop = open_stop_music,
    .playOrPause = open_play_music,
};

State init = {
    .state = INIT,
    .stop = init_stop_music,
    .playOrPause = init_play_music,
};

State close = {
    .state = CLOSE,
    .stop = close_stop_music,
    .playOrPause = close_play_music,
};

State pause = {
    .state = PAUSE,
    .stop = pause_stop_music,
    .playOrPause = pause_play_music,
};
State resume = {
    .state = RESUME,
    .stop = resume_stop_music,
    .playOrPause = resume_play_music,
};
State currentContext = {
    .stop = sys_stop_music,
    .playOrPause = sys_play_music,
};

void init_stop_music()
{
   // printf("init state\n");
    //pCurrentStaus = &init;
}
void init_play_music()
{
    printf("%s enter %d\n",__FUNCTION__,__LINE__);

    pCurrentStaus = &open;
}
void open_stop_music()
{
    printf("%s enter %d\n",__FUNCTION__,__LINE__);
    pCurrentStaus = &close;
}
void open_play_music()
{
    printf("%s enter %d\n",__FUNCTION__,__LINE__);
    pCurrentStaus = &pause;
}
void close_stop_music()
{
    printf("%s enter %d\n",__FUNCTION__,__LINE__);
    pCurrentStaus = &close;
}
void close_play_music()
{
  //  printf("%s enter %d\n",__FUNCTION__,__LINE__);
  //  pCurrentStaus = &close;
}
void pause_stop_music()
{
    printf("%s enter %d\n",__FUNCTION__,__LINE__);
    pCurrentStaus = &close;
}
void pause_play_music()
{
    printf("%s enter %d\n",__FUNCTION__,__LINE__);
    pCurrentStaus = &open;
}
void resume_stop_music()
{
   // printf("%s enter %d\n",__FUNCTION__,__LINE__);
  //  pCurrentStaus = &open;
}
void resume_play_music()
{
    printf("%s enter %d\n",__FUNCTION__,__LINE__);
    pCurrentStaus = &close;
}

void sys_stop_music()
{
    //printf("%s enter %d\n",__FUNCTION__,__LINE__);
    pCurrentStaus->stop();
}
void sys_play_music()
{
   // printf("%s enter %d\n",__FUNCTION__,__LINE__);
    pCurrentStaus->playOrPause();
    //printf("%s pCurrentStaus %d\n",__FUNCTION__,pCurrentStaus->state);

}

void init_state()
{
    pCurrentStaus = &init;
}

int main(void)
{   
    init_state();
    currentContext.playOrPause();
    currentContext.playOrPause();
    currentContext.playOrPause();
    currentContext.playOrPause();
    currentContext.playOrPause();
    currentContext.stop();
    //currentContext.stop();


//currentContext.stop();
    return 0;
}
