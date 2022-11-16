#include <iostream>
#include <deque>
#include <vector>
using namespace std;
int main() {
    deque<pair<int,int>> dq;
    vector<int> result;
    int n;
    cin >> n;
    for(int i=0;i<n;i++) {
        pair<int,int> tmp;
        cin >> tmp.first;
        dq.push_back({tmp.first,i+1});
    }
    int cur = dq.front().first;
    result.emplace_back(dq.front().second);
    dq.pop_front();
    while(!dq.empty()) {
        //int dq_front = dq.front().first;
        //int dq_back = dq.back().first;
        
        for(int i=0;i<abs(cur)-1;i++) {
            
            if(cur > 0) {
                dq.push_back(dq.front());
                dq.pop_front();
                
            }
            else {
                dq.push_front(dq.back());
                dq.pop_back();
            }
        }
        if(cur > 0) {
            cur = dq.front().first;
            result.emplace_back(dq.front().second);
            dq.pop_front();
        }
        else {
            cur = dq.back().first;
            result.emplace_back(dq.back().second);
            dq.pop_back();
        }

    }
    for(int i=0;i<result.size();i++) {
        cout << result[i] << " ";
    }
    return 0;
}