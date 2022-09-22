#include <iostream>
using namespace std;
int main() {
    int n, result = 1;
    cin >> n;
    int r = 6;
    int i = 1;
    while (1) {
        if (i >= n || n == 1) {
            break;
        }
        i += r;
        r += 6;
        result++;
    }
    cout << result;
}