#include <iostream>
using namespace std;
int Gcd(int a, int b)
{
    int tmp;
    while (b != 0)
    {
        tmp = a % b;
        a = b;
        b = tmp;
    }
    return a;
}
int Lcm(int a, int b)
{
    return a * b / Gcd(a, b);
}

int main() {
    int t;
    cin >> t;
    for(int i = 0;i<t;i++) {
        int a, b;
        cin >> a >> b;
        cout << Lcm(a,b) << "\n";
    }
    return 0;
}