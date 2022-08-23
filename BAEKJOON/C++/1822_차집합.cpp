#include <iostream>
#include <set>
using namespace std;
int main() {
    int n, m;
    cin >> n >> m;
    set<int> s1;
    set<int> s2;
    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        s1.insert(tmp);
    }
    for (int i = 0; i < m; i++) {
        int tmp;
        cin >> tmp;
        s2.insert(tmp);
    }
    for (auto iter = s2.begin(); iter != s2.end(); iter++) {
        if (s1.find(*iter) != s1.end()) {
            s1.erase(*iter);
        }
    }
    cout << s1.size() << "\n";
    for (auto iter = s1.begin(); iter != s1.end(); iter++) {
        cout << *iter << " ";
    }
}