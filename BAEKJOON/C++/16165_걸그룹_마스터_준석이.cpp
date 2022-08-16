#include <iostream>
#include <map>
using namespace std;
int main() {
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m;
    cin >> n >> m;
    map<string, string> idol;
    for (int i = 0; i < n; i++) {
        string group_name, member_name;
        int mem;
        cin >> group_name;
        cin >> mem;
        for (int j = 0; j < mem; j++) {
            cin >> member_name;
            idol[member_name] = group_name;
        }
    }
    for (int i = 0; i < m; i++) {
        string tmp;
        int q;
        cin >> tmp;
        cin >> q;
        if (q == 0) {
            for (auto iter = idol.begin(); iter != idol.end(); iter++) {
                if (iter->second == tmp) {
                    cout << iter->first << "\n";
                }
            }
        }
        else if (q == 1) {
            cout << idol[tmp] << "\n";
        }
    }
}