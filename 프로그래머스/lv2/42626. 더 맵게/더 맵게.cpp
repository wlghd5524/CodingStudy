#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(vector<int> scoville, int K) {
    priority_queue<int,vector<int>,greater<int>> pq;
    int answer = 0;
    for(int i = 0;i<scoville.size();i++) {
        pq.push(scoville[i]);
    }
    while(pq.size() >= 2) {
        if(pq.top() < K) {
            int a = pq.top();
            pq.pop();
            int b = pq.top();
            pq.pop();
            a = a+(b*2);
            pq.push(a);
            answer++;
        }
        else {
            break;
        }
    }
    if(pq.size() < 2 && pq.top() < K) {
        answer = -1;
    } 
    return answer;
}