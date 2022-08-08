#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;
int main() {
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        unordered_map<int, int> um;
        int n, m, tmp;
        cin >> n;
        for (int j = 0; j < n; j++) {
            cin >> tmp;
            um[tmp] = 0;
        }
        cin >> m;
        for (int j = 0; j < m; j++) {
            cin >> tmp;
            if (um.find(tmp) != um.end()) {
                cout << "1\n";
            }
            else {
                cout << "0\n";
            }
        }
    }
}