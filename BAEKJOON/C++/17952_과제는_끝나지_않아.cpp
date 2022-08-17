#include <iostream>
#include <stack>
using namespace std;
int main() {
    int n, one, score, t, result = 0;
    cin >> n;
    stack<pair<int, int>> s;
    for (int i = 0; i < n; i++) {
        cin >> one;
        if (one == 0) {
            if (s.empty() == 0) {
                if (s.top().second != 0) {
                    auto tmp = make_pair(s.top().first, (s.top().second) - 1);
                    s.pop();
                    s.push(tmp);
                }
                if (s.top().second == 0) {
                    result += s.top().first;
                    s.pop();
                }
                continue;
            }
        }
        else {
            cin >> score >> t;
            if (t == 1) {
                result += score;
                continue;
            }
            s.push({score, t - 1});
        }
    }
    cout << result;
    return 0;
}