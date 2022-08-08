#include <iostream>
#include <map>
#include <algorithm>
using namespace std;
int main() {
    string str, tmp, name, log;
    map<string, string, greater<string>> m;
    int n;
    cin >> n;
    cin.ignore();
    for (int i = 0; i < n; i++) {
        getline(cin, str);
        for (int j = 0; j < str.size(); j++) {
            if (str[j] != ' ') {
                tmp += str[j];
            }
            else {
                name = tmp;
                m[name] = "";
                tmp.clear();
            }
            if (j + 1 == str.size()) {
                log = tmp;
                m[name] = log;
                log.clear();
                tmp.clear();
            }
        }
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
