#include <iostream>
#include <vector>
using namespace std;
int main() {
    int t, k, n, result;
    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> k;
        cin >> n;
        vector<vector<int>> v(k + 1, vector<int>(n + 1, 0));
        for (int j = 1; j <= n; j++) {
            v[0][j] = j;
        }
        for (int j = 1; j <= k; j++) {
            for (int p = 1; p <= n; p++) {
                for (int r = 1; r <= p; r++) {
                    v[j][p] += v[j - 1][r];
                }
            }
        }
        cout << v[k][n] << "\n";
    }
}