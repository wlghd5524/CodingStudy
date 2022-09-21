#include <iostream>
#include <set>
using namespace std;
int main() {
    multiset<pair<int, int>> s;
    int n = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        s.insert({a, b});
    }
    int cur = s.begin()->first;
    for (auto iter = s.begin(); iter != s.end(); iter++) {
        if (cur < iter->first) {
            cur = iter->first;
        }
        cur += iter->second;
    }
    cout << cur;
}