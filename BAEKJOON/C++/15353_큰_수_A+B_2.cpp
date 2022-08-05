#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main() {
    string a, b, tmp;
    cin >> a >> b;
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    int min, j = 0;
    if (a.size() < b.size()) {
        tmp = b;
        b = a;
        a = tmp;
    }
    a.append("0");
    for (int i = 0; i < b.size(); i++) {
        int x = a[i] - '0';
        int y = b[i] - '0';
        int z = a[i + 1] - '0';

        if (x >= 10) {
            x %= 10;
            a[i + 1] = (z + (x / 10)) + '0';
        }
        if (x + y >= 10) {
            a[i] = ((x + y) % 10) + '0';
            if (i + 1 == a.size()) {
                a.append(to_string((x + y) / 10));
            }
            else {
                a[i + 1] = (z + ((x + y) / 10)) + '0';
                j = i;
                while (a[j + 1] >= 10 + '0') {
                    int p = a[j + 1] - '0';
                    a[j + 1] = ((a[j + 1] - '0') % 10) + '0';
                    a[j + 2] = (a[j + 2] - '0' + (p / 10)) + '0';
                    j++;
                }
            }
        }
        else {
            a[i] = x + y + '0';
        }
    }
    reverse(a.begin(), a.end());
    if (a.front() == '0') {
        a.erase(0, 1);
    }
    cout << a;
}