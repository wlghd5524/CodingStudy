#include <iostream>
#include <vector>
using namespace std;

#define MOD 1000000000

int main()
{
    int n;
    cin >> n;
    vector<int> dp(abs(n) + 1);
    dp[0] = 0;
    dp[1] = 1;
    if (n == 0)
    {
        cout << "0\n0";
    }
    else if (n > 0)
    {
        for (int i = 2; i <= n; i++)
        {
            dp[i] = ((dp[i - 1] % MOD) + (dp[i - 2] % MOD)) % MOD;
        }
        cout << "1\n" << dp[n];
    }
    else
    {
        dp[2] = -1;
        for (int i = 3; i <= abs(n); i++)
        {
            dp[i] = ((dp[i - 2] % MOD) - (dp[i - 1] % MOD)) % MOD;
        }
        if (dp[abs(n)] > 0)
        {
            cout << "1\n" << dp[abs(n)];
        }
        else if (dp[abs(n)] < 0)
        {
            cout << "-1\n" << abs(dp[abs(n)]);
        }
        else
        {
            cout << "0\n0";
        }
    }
    return 0;
}