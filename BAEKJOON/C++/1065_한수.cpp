#include <iostream>
using namespace std;
int main()
{
    int n, count;
    cin >> n;
    if (n > 99)
    {
        count = 99;
        for (int i = 100; i <= n; i++)
        {
            for (int j = -9; j < 10; j++)
            {
                if ((i / 100) + j == (i % 100) / 10 && ((i % 100) / 10) + j == i % 10)
                    count++;
            }
        }
    }
    else
        count = n;
    cout << count;
    return 0;
}