#include <iostream>
using namespace std;
int main() {
    int n, result = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int j = 1; j < i; j *= 10) {
            sum += (i % (j * 10)) / j;
        }
        sum += i;
        if (sum == n) {
            result = i;
            break;
        }
    }
    cout << result;
    return 0;
}