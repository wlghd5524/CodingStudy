#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int n, k;
    cin >> n >> k;
    int dp[n + 1][n + 1];
    dp[1][1] = 1;
    dp[2][1] = 1;
    dp[2][2] = 1;
    for (int i = 3; i <= n; i++)
    {
        dp[i][1] = 1;
        dp[i][i] = 1;
        for (int j = 2; j < i; j++)
        {
            dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
        }
    }
    cout << dp[n][k];
}