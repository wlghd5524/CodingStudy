#include <iostream>
#include <vector>
using namespace std;
int main() {
    int c;
    cin >> c;
    for (int i = 0; i < c; i++) {
        double n, sum = 0, cnt = 0, avg;
        cin >> n;
        vector<int> v(n);
        for (int j = 0; j < n; j++) {
            cin >> v[j];
            sum += v[j];
        }
        avg = sum / n;
        for (int j = 0; j < n; j++) {
            if (v[j] > avg) {
                cnt++;
            }
        }
        cout << fixed;
        cout.precision(3);
        cout << cnt / n * 100 << "%\n";
    }
}