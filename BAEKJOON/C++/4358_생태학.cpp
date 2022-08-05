#include <iostream>
#include <map>
using namespace std;

int main() {
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int i = 0;
    map<string, double> m;
    string s;
    while (1) {
        getline(cin, s);
        if (cin.eof())  break;
        if (m.find(s) != m.end()) {
            m[s]++;
        }
        else {
            m[s] = 1;
        }
        i++;
    }
    int j = 0;
    for (auto iter = m.begin(); iter != m.end(); iter++) {
        iter->second = iter->second / i * 100;
        cout << fixed;
        cout.precision(4);
        cout << iter->first << " " << iter->second;
        if (i != m.size() - 1) {
            cout << "\n";
        }
        j++;
    }
}