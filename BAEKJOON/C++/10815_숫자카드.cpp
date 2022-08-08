#include <iostream>
#include <unordered_map>
using namespace std;
int main() {
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m, tmp;
    unordered_map<int, int> um;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> tmp;
        um[tmp] = 0;
    }
    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> tmp;
        if (um.find(tmp) != um.end()) {
            cout << 1;
        }
        else {
            cout << 0;
        }
        if (i + 1 != m) {
            cout << " ";
        }
    }
}