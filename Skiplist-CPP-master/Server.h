#ifndef SERVER_H
#define SERVER_H
#include <string>
#include <stdio.h>
#include <sys/time.h>
#include <signal.h>
#include "skiplist.h"
using namespace std;
class Server
{
private:
    /* data */
    SkipList<int, string> skipList;
    static void serverCron(int num);
public:
    Server(/* args */);
    ~Server();
    int start();
};

Server::Server(/* args */):skipList(6)
{
    
}
int Server::start(){
    //注册信号捕捉函数
    struct sigaction act;
    act.sa_flags=0;
    act.sa_handler=serverCron;
    sigemptyset(&act.sa_mask);  //清空临时阻塞信号集
    sigaction(SIGALRM, &act, NULL);

    struct itimerval myTime;
    myTime.it_interval.tv_sec=1;
    myTime.it_interval.tv_usec=0;
    myTime.it_value.tv_sec=3;
    myTime.it_value.tv_usec=0;
    int ret=setitimer(ITIMER_REAL, &myTime, NULL);
    string str;
    while(1){
        
    }
    return 0;
}

Server::~Server()
{
}

void Server::serverCron(int num){
    cout<<"time1:"<<num<<endl;
}

#endif