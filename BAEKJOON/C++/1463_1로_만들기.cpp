#include <iostream>
#include <vector>
using namespace std;
int main() {
    int n, cnt = 0;
    cin >> n;
    vector<int> v(n + 1);
    v[1] = 0;
    for (int i = 2; i <= n; i++) {
        v[i] = v[i - 1] + 1;
        if (i % 3 == 0) {
            if (v[i] > v[i / 3] + 1) {
                v[i] = v[i / 3] + 1;
            }
        }
        if (i % 2 == 0) {
            if (v[i] > v[i / 2] + 1) {
                v[i] = v[i / 2] + 1;
            }
        }
    }
    cout << v[n];
}