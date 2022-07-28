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
    int resultA;
    int resultB;
    int tmp;
    string str;
    cin >> str;
    for (i = 0; str[i] != ':'; i++)
        a += str[i];
    for (i += 1; i < str.size(); i++)
        b += str[i];
    resultA = stoi(a);
    resultB = stoi(b);
    while (1) {
        if (gcd(resultA, resultB) == 1)
            break;
        tmp = resultA;
        resultA = resultA / gcd(resultA, resultB);
        resultB = resultB / gcd(tmp, resultB);
    }
    cout << resultA << ":" << resultB;
}