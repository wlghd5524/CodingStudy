#include <iostream>
using namespace std;
int main() {
    int e, s, m, count = 1, i = 0;
    int count_e = 1, count_s = 1, count_m = 1;
    cin >> e >> s >> m;
    while (1) {
        if (e == count_e && s == count_s && m == count_m)
            break;
        count_e++;
        count_s++;
        count_m++;
        if (count_e == 16)
            count_e = 1;
        if (count_s == 29)
            count_s = 1;
        if (count_m == 20)
            count_m = 1;
        count++;
    }
    cout << count;
    return 0;
}