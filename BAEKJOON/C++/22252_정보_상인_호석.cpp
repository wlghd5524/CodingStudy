#include <iostream>
#include <set>
#include <map>
using namespace std;
int main() {
    int n;
    long long int sum = 0;
    cin >> n;
    map<string, multiset<int>> m;
    for (int i = 0; i < n; i++) {
        string name;
        int cmd, data;
        cin >> cmd >> name >> data;
        if (cmd == 1) {
            for (int j = 0; j < data; j++) {
                int tmp;
                cin >> tmp;
                m[name].insert(tmp);
            }
        }
        else {
            if (m.find(name) != m.end()) {
                if (m[name].size() > data) {
                    for (int j = 0; j < data; j++) {
                        sum += *m[name].rbegin();
                        m[name].erase(--m[name].end());
                    }
                }
                else {
                    while (!m[name].empty()) {
                        sum += *m[name].rbegin();
                        m[name].erase(--m[name].end());
                    }
                }
            }
        }
    }
    cout << sum;
    return 0;
}