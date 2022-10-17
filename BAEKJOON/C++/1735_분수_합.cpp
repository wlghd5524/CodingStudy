#include <iostream>
using namespace std;
int gcd(int a, int b) {
    int tmp;
    while (b != 0) {
        tmp = a % b;
        a = b;
        b = tmp;
    }
    return a;
}
int lcm(int a, int b) {
    return a * b / gcd(a, b);
}
int main() {
    int a, b, c, d;
    int x, y;
    cin >> a >> b;
    cin >> c >> d;
    if (b == d) {
        x = a + c;
        y = b;
    }
    else {
        y = lcm(b, d);
        x = a * (y / b) + c * (y / d);
    }
    if (x == y) {
        x = 1;
        y = 1;
    }
    if (gcd(x, y) != 1) {
        int tmp = x;
        x /= gcd(x, y);
        y /= gcd(tmp, y);
    }
    cout << x << " " << y;
    return 0;
}