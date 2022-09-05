#include <iostream>
using namespace std;
int main(){
    int m, n, sum = 0, min = 10000;
    cin >> m >> n;
    for (int i = m; i <= n; i++) {
        bool is_prime = true;
        for (int j = 2; j * j <= i; j++) {
            if (i % j == 0) {
                is_prime = false;
                break;
            }
        }
        if (!is_prime || i == 1) {
            continue;
        }
        sum += i;
        if (min > i) {
            min = i;
        }
    }
    if (sum == 0) {
        cout << -1;
        return 0;
    }
    cout << sum << "\n" << min;
}