#include <iostream>
using namespace std;
int main()
{
    int dp[101][100001];
    int n, m;
    cin >> n >> m;
    int bytes[n + 1];
    int costs[n + 1];
    int sum = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> bytes[i];
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> costs[i];
        sum += costs[i];
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= sum; j++)
        {
            if (j >= costs[i])
            {
                dp[i][j] = max(dp[i][j], dp[i - 1][j - costs[i]] + bytes[i]);
            }
            dp[i][j] = max(dp[i][j], dp[i - 1][j]);
        }
    }
    for (int i = 0; i <= sum; i++)
    {
        if (dp[n][i] >= m)
        {
            cout << i;
            break;
        }
    }
    return 0;
}