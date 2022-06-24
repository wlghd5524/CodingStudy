#include <iostream>
using namespace std;
int main() {
    int n;
    int a, b, c, d;
    int count = 0;
    cin >> n;
    d = n;
    while (1) {
        a = d / 10;
        b = d % 10;
        c = a + b;
        if (c >= 10)
            c = c % 10;
        d = (b * 10) + c;
        count++;
        if (d == n)
            break;
    }
    cout << count;
}