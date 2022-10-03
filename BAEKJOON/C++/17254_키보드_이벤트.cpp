#include <iostream>
#include <set>
#include <algorithm>
using namespace std;
struct cmp {
    bool operator()(const pair<pair<int, int>, char> &a, const pair<pair<int, int>, char> &b) const {
        if (a.first.second == b.first.second) {
            return a.first.first < b.first.first;
        }
        return a.first.second < b.first.second;
    }
};
int main() {
    int keyboard, n;
    cin >> keyboard >> n;
    multiset<pair<pair<int, int>, char>, cmp> s;
    for (int i = 0; i < n; i++) {
        int a, b;
        char c;
        cin >> a >> b >> c;
        s.insert({{a, b}, c});
    }
    for (const auto &result : s) {
        cout << result.second;
    }
}