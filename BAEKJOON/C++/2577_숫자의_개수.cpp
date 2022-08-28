#include <iostream>
#include <string>
using namespace std;
int main() {
    int bit[10] = {0, };
    int a, b, c;
    string sum;
    cin >> a;
    cin >> b;
    cin >> c;
    sum = to_string(a * b * c);
    for (int i = 0; i < sum.size(); i++) {
        bit[sum[i] - '0']++;
    }
    for (int i = 0; i < 10; i++) {
        cout << bit[i] << "\n";
    }
    return 0;
}