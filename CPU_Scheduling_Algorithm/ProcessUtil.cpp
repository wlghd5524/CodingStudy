#include <queue>
#include "Process.h"

struct BurstTimeComparator // 실행 시간 우선 순위 큐 정렬
{
    bool operator()(const Process *a, const Process *b)
    {
        return a->executionTime > b->executionTime; // 실행 시간이 짧은 프로세스부터 정렬
    }
};
struct PriorityComparator // 우선 순위 큐 정렬
{
    bool operator()(const Process *a, const Process *b)
    {
        if (a->priority == b->priority) // 우선순위가 같을 때
        {
            return a->arrivalTime > b->arrivalTime; // 먼저 도착한 프로세스가 앞으로 정렬(FIFO)
        }
        return a->priority > b->priority; // 우선순위 높은(숫자가 작은) 순서로 정렬
    }
};
struct RemainTimeComparator // 남은 실행 시간 우선 순위 큐 정렬
{
    bool operator()(const Process *a, const Process *b)
    {
        if (a->executionTime - a->runningTime == b->priority - b->runningTime) // 우선순위가 같을 때
        {
            return a->arrivalTime > b->arrivalTime; // 먼저 도착한 프로세스가 앞으로 정렬(FIFO)
        }
        return a->executionTime - a->runningTime > b->executionTime - b->runningTime; // 남은 실행시간이 작은 순서로 정렬
    }
};

void update_waitingTime(vector<Process *> &process)
{
    for(int i = 0;i<process.size();i++) {
        if(process[i]->status == 0) {
            process[i]->waitingTime++;
        }
    }
}
template <typename T>
void update_queue(priority_queue<Process *, vector<Process *>, T> &pq)
{
    int len = pq.size();
    while (len--)
    {
        Process *temp = pq.top();
        temp->priority = double(temp->executionTime) / (temp->waitingTime + temp->executionTime);
        pq.push(temp);
        pq.pop();
    }
}