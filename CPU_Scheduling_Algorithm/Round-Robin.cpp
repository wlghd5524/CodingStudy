#include "Process.h"
#include "ProcessUtil.cpp"
#include <iostream>
#include <queue>
#include <fstream>
#define TIME_QUANTUM 2
using namespace std;
int main()
{
    vector<int> timeHistory; // 간트 차트를 그리기 위한 타임 라인
    Process *p;
    vector<Process *> process;
    queue<Process *> q; // Ready queue
    ifstream fin("RandomProcesses.txt");
    if (!fin.is_open())
    {
        cout << "File open failed...\n";
        return 1;
    }
    while (!fin.eof())
    {
        int id = 0;
        int arrivalTime = 0;
        int executionTime = 0;
        int priority = 0;
        fin >> id >> arrivalTime >> executionTime >> priority;
        p = new Process(id, arrivalTime, executionTime);
        process.push_back(p);
    }
    int currentTime = 0;            // 현재 시간
    int processCount = 0;           // 프로세스가 도착한 순서대로 큐에 들어갈 때 인덱스
    Process *runningProcess = NULL; // 실행 중인 프로세스
    bool isRunningExists = false;   // 실행중인 프로세스가 있는지
    int TimeQuantumCount = 0;
    cout << "\n";
    while (1)
    {
        if (process.size() > processCount && currentTime == process[processCount]->arrivalTime) // 현재 시간이 다음 프로세스 도착 시간일 때
        {
            // cout << "Time=" << currentTime << " PID " << process[processCount]->id << " Arrive\n";   // 프로세스 도착 로그
            q.push(process[processCount]);
            process[processCount++]->status = 0;
        }
        if (!isRunningExists) // 현재 실행중인 프로세스가 없을 때
        {
            runningProcess = q.front();         // 다음 프로세스 선택
            q.pop();                            // 다음 프로세스 꺼내기
            runningProcess->start(currentTime); // 프로세스 실행
            isRunningExists = true;
            timeHistory.push_back(currentTime); // 타임 라인 찍기
            cout << "|P" << runningProcess->id;
        }
        if (runningProcess->runningTime == runningProcess->executionTime) // 프로세스가 작업을 완료하고 종료될 때
        {
            cout << "|";
            timeHistory.push_back(currentTime);  // 타임 라인 찍기
            runningProcess->finish(currentTime); // 프로세스 종료
            isRunningExists = false;
            if (q.empty()) // 모든 프로세스 종료 시
            {
                break;
            }
            runningProcess = q.front();         // 다음 프로세스 선택
            q.pop();                            // 다음 프로세스 꺼내기
            runningProcess->start(currentTime); // 프로세스 실행
            isRunningExists = true;
            TimeQuantumCount = 0;
            cout << "P" << runningProcess->id;
        }
        if (TimeQuantumCount == TIME_QUANTUM) // 타임 아웃
        {
            cout << "|";
            timeHistory.push_back(currentTime); // 타임 라인 찍기
            runningProcess->pause(currentTime); // 실행 중인 프로세스 중지
            isRunningExists = false;
            q.push(runningProcess);             // 큐에 다시 넣기
            runningProcess = q.front();         // 다음 프로세스 선택
            q.pop();                            // 다음 프로세스 꺼내기
            runningProcess->start(currentTime); // 프로세스 실행
            isRunningExists = true;
            TimeQuantumCount = 0;
            cout << "P" << runningProcess->id;
        }
        cout << "-";
        TimeQuantumCount++;
        runningProcess->runningTime++;
        currentTime++; // 시간 진행
        update_waitingTime(process);
    }

    // 타임 라인 출력
    cout << "\n";
    int historyCount = 0;
    for (int i = 0; i <= currentTime; i++)
    {
        if (i == timeHistory[historyCount])
        {
            if (i != 0)
            {
                if (i < 10)
                {
                    cout << " ";
                }
                cout << "  ";
            }
            cout << timeHistory[historyCount++];
        }
        else
        {
            cout << " ";
        }
    }
    cout << "\n\n";

    double sumWaitingTime = 0;
    double sumReturnTime = 0;
    for (int i = 0; i < process.size(); i++)
    {
        cout << "PID " << process[i]->id << " Waiting Time = " << process[i]->waitingTime << " Return Time = " << process[i]->returnTime << "\n";
        sumWaitingTime += process[i]->waitingTime;
        sumReturnTime += process[i]->returnTime;
    }
    cout << "Average Waiting Time = " << sumWaitingTime / process.size() << "\n";
    cout << "Average Return Time = " << sumReturnTime / process.size() << "\n";
    delete[] p;
    fin.close();
    return 0;
}