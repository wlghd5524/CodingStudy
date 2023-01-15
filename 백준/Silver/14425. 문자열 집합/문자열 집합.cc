#include <iostream>
#include <set>
using namespace std;
int main() {
    int n, m, count = 0;
    cin >> n >> m;
    set<string> s;
    for (int i = 0; i < n; i++) {
        string tmp;
        cin >> tmp;
        s.insert(tmp);
    }
    for (int i = 0; i < m; i++) {
        string tmp;
        cin >> tmp;
        if (s.find(tmp) != s.end()) {
            count++;
            continue;
        }
    }
    cout << count;
    return 0;
}