#include <iostream>
using namespace std;
int main()
{
    int a, b, c;
    cin >> a >> b >> c;
    if (a == b && b == c && a == c)
    {
        cout << 10000 + (a * 1000);
    }
    else if (a == b || a == c)
    {
        cout << 1000 + (a * 100);
    }
    else if (b == c)
    {
        cout << 1000 + (b * 100);
    }
    else
    {
        int max_num = a;
        if (b > max_num)
        {
            max_num = b;
        }
        if (c > max_num)
        {
            max_num = c;
        }
        cout << max_num * 100;
    }
    return 0;
}