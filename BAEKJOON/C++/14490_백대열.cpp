#include <iostream>
#include <string>
using namespace std;
int gcd(int a, int b) {
    int c;
    while (b != 0) {
        c = a % b;
        a = b;
        b = c;
    }
    return a;
}
int main() {
    int i = 0;
    string a, b;
    int reuslt_a;
    int reuslt_b;
    int tmp;
    string str;
    cin >> str;
    for (i = 0; str[i] != ':'; i++)
        a += str[i];
    for (i += 1; i < str.size(); i++)
        b += str[i];
    reuslt_a = stoi(a);
    reuslt_b = stoi(b);
    while (1) {
        if (gcd(reuslt_a, reuslt_b) == 1)
            break;
        tmp = reuslt_a;
        reuslt_a = reuslt_a / gcd(reuslt_a, reuslt_b);
        reuslt_b = reuslt_b / gcd(tmp, reuslt_b);
    }
    cout << reuslt_a << ":" << reuslt_b;
    return 0;
}