#include <iostream>
using namespace std;
int main()
{
    int n, k;
    cin >> n >> k;
    int cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        if (n % i == 0)
        {
            cnt++;
        }
        if (cnt == k)
        {
            cout << i;
            return 0;
        }
    }
    if (cnt < k)
    {
        cout << 0;
    }
    return 0;
}