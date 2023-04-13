#include <string>
#include <queue>
#include <vector>

using namespace std;

int solution(vector<int> numbers, int target) {
    int answer = 0;
    int size = numbers.size();
    queue<pair<int,int>> q;
    q.push({0,numbers[0]});
    q.push({0,-numbers[0]});
    
    while(!q.empty()) {
        int index = q.front().first;
        int sum = q.front().second;
        q.pop();
        if(index == size-1 && target == sum) {
            answer++;
            continue;
        }
        if(index < size-1) {
            q.push({index+1,sum+numbers[index+1]});
            q.push({index+1,sum-numbers[index+1]});
        }
        
    }
    return answer;
}