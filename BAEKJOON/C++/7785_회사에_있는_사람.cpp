#include <iostream>
#include <map>
#include <algorithm>
using namespace std;
int main() {
    string str, tmp, name, log;
    map<string, string, greater<string>> m;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> name >> log;
        m[name] = log;
    }
    int j = 0;
    for (auto iter = m.begin(); iter != m.end(); iter++) {
        if (iter->second == "enter") {
            cout << iter->first;
            if (j + 1 != m.size()) {
                cout << "\n";
            }
        }
        j++;
    }
}
