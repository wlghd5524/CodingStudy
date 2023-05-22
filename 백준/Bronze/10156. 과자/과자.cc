#include <iostream>
using namespace std;
int main()
{
    int a, b, c;
    cin >> a >> b >> c;
    int result = (a * b) - c;
    if (result < 0)
    {
        result = 0;
    }
    cout << result;
    return 0;
}