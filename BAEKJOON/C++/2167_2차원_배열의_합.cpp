#include <iostream>
using namespace std;
int main() {
    int n, m;
    cin >> n >> m;
    int arr[n][m];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }
    int k;
    cin >> k;
    for (int i = 0; i < k; i++) {
        int sum = 0;
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        for (int j = a - 1; j < c; j++) {
            for (int p = b - 1; p < d; p++) {
                sum += arr[j][p];
            }
        }
        cout << sum << "\n";
    }
}