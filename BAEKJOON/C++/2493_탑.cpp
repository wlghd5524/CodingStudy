#include <iostream>
#include <stack>
using namespace std;
int main() {
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, tmp;
    cin >> n;
    stack<pair<int, int>> s;
    for (int i = 0; i < n; i++) {
        cin >> tmp;
        while (s.empty() == 0) {
            if (s.top().second > tmp) {
                cout << s.top().first << " ";
                break;
            }
            s.pop();
        }
        if (s.empty() == 1) {
            cout << 0 << " ";
        }
        s.push({i + 1, tmp});
    }
    return 0;
}