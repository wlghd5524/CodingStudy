#include <iostream>
using namespace std;
int main() {
    int k, a_count = 1, b_count = 0, tmp;
    cin >> k;
    for (int i = 0; i < k; i++) {
        tmp = b_count;
        b_count += a_count;
        a_count = tmp;
    }
    cout << a_count << " " << b_count;
}