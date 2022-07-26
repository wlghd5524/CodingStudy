#include <iostream>
#include <cmath>
using namespace std;
bool sosu(int num) {
    if (num < 2)
        return false;
    int a = (int)sqrt(num);
    for (int i = 2; i <= a; i++) {
        if (num % i == 0)
            return false;
    }
    return true;
}
int main() {
    int m, n;
    cin >> m >> n;
    for (int i = m; i <= n; i++) {
        if (sosu(i) == true)
            cout << i << "\n";
    }
    return 0;
}