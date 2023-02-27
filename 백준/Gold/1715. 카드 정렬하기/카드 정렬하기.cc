#include <iostream>
#include <queue>
using namespace std;
int main() {
    priority_queue<int,vector<int>,greater<int>> pq;
    int n;
    cin >> n;
    if(n==1) {
        cout << 0;
        return 0;
    }
    for(int i = 0;i<n;i++) {
        int tmp;
        cin >> tmp;
        pq.push(tmp);
    }
    int result = 0;
    while(!pq.empty()) {
        int sum = pq.top();
        pq.pop();
        sum += pq.top();
        pq.pop();
        if(!pq.empty()){
            pq.push(sum);
        }
        result += sum;
    }
    cout << result;
}