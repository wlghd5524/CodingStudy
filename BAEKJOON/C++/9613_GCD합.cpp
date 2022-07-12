#include <iostream>
using namespace std;

int gcd(int a, int b) {
    int c;
    while (b != 0) {
        c = a % b;
        a = b;
        b = c;
    }
    return a;
}

int main() {
    int t, n, arr[100];
    long long int sum = 0;
    cin >> t;
    for (int i = 0; i < t; i++) {
        sum = 0;
        cin >> n;
        for (int j = 0; j < n; j++)
            cin >> arr[j];
        for (int j = 0; j < n; j++) {
            for (int p = j + 1; p < n; p++)
                sum += gcd(arr[j], arr[p]);
        }
        cout << sum << "\n";
    }
}