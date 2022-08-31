#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
int main() {
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    int num;
    cin >> n;
    priority_queue<int, vector<int>, greater<int>> q;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> num;
            if (q.size() == n) {
                if (q.top() < num) {
                    q.pop();
                    q.push(num);
                }
            }
            else {
                q.push(num);
            }
        }
    }
    cout << q.top();
}