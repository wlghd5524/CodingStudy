#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int main() {
    
    int t;
    cin >> t;
    for(int i = 0;i<t;i++) {
        int n;
        cin >> n;
        deque<char> dq;
        queue<char> cards;
        for(int j = 0;j<n;j++) {
            char tmp;
            cin >> tmp;
            cards.push(tmp);
        }
        dq.push_back(cards.front());
        cards.pop();
        while(!cards.empty()) {
            if(dq.front() < cards.front()) {
                dq.push_back(cards.front());
                cards.pop();
            }
            else {
                dq.push_front(cards.front());
                cards.pop();
            }
        }
        while(!dq.empty()) {
            cout << dq.front();
            dq.pop_front();
        }
        cout << "\n";
    }
    return 0;
}