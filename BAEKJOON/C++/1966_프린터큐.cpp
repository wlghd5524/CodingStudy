#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int data, docu, m, cnt = 0;
        cin >> docu >> m;
        queue<pair<int, int>> q;
        vector<int> priority(docu);
        for (int j = 0; j < docu; j++) {
            cin >> data;
            q.push({j, data});
            priority[j] = data;
        }
        sort(priority.begin(), priority.end(), greater<>());
        while (1) {
            auto tmp = q.front();
            if (priority[0] == tmp.second) {
                priority.erase(priority.begin());
                q.pop();
                cnt++;
                if (m == tmp.first) {
                    break;
                }
            }
            else {
                q.pop();
                q.push(tmp);
            }
        }
        cout << cnt << "\n";
    }
}