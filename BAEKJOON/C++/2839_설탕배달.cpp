#include <iostream>
using namespace std;
int main() {
    int n, count = 0;
    cin >> n;
    while (n > 0) {
        if (n % 5 == 0) {
            count += n/5;
            break;
        }
        else {
            n -= 3;
            count++;
        }
    }
    if (n < 0) {
        cout << -1;
        return 0;
    }
    cout << count;
}