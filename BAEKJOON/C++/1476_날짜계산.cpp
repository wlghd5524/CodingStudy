#include <iostream>
using namespace std;
int main() {
    int e, s, m, count = 1, i = 0;
    int countE = 1, countS = 1, countM = 1;
    cin >> e >> s >> m;
    while (1) {
        if (e == countE && s == countS && m == countM)
            break;
        countE++;
        countS++;
        countM++;
        if (countE == 16)
            countE = 1;
        if (countS == 29)
            countS = 1;
        if (countM == 20)
            countM = 1;
        count++;
    }
    cout << count;
    return 0;
}