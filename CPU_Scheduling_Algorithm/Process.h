#ifndef PROCESS_H
#define PROCESS_H
#include <iostream>
#include <queue>
using namespace std;
class Process
{
public:
    int id;
    int arrivalTime;    //도착 시간
    int executionTime;  //실행 시간
    int waitingTime;    //대기 시간
    int returnTime;     //반환 시간
    double priority;    //우선 순위
    int startTime;      //시작 시간
    int runningTime;    //현재 실행 시간(진행도)
    int status;         // 프로세스의 상태(-1이면 생성, 0이면 대기, 1이면 실행중, 2이면 완료)
    Process(int id, int arrivalTime, int executionTime)
    {
        this->id = id;
        this->arrivalTime = arrivalTime;
        this->executionTime = executionTime;
        this->priority = 0.0;
        this->status = -1;
    }
    Process(int id, int arrivalTime, int executionTime, int priority)
    {
        this->id = id;
        this->arrivalTime = arrivalTime;
        this->executionTime = executionTime;
        this->priority = priority;
        this->status = -1;
    }
    void start(int currentTime) // 프로세스 시작
    {
        //cout << "Time=" << currentTime << " PID " << id << " Start\n";  //프로세스 실행 로그
        status = 1;
    }
    void pause(int currentTime) // 프로세스 중지(Context Switch)
    {
        status = 0;
    }
    void finish(int currentTime) // 프로세스 종료
    {
        //cout << "Time=" << currentTime << " PID " << id << " Finish\n";   //프로세스 종료 로그
        status = 2;
        returnTime = waitingTime + executionTime; // 반환 시간 = 대기 시간 + 실행 시간
    }
};
#endif