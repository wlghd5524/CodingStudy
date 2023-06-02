#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int a = n * 78 / 100;
    int b = (n * 20 / 100) * 22 / 100;
    cout << a << " " << n - b;
    return 0;
}