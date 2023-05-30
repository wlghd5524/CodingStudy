#include <iostream>
#define MAX 2000000000
using namespace std;
int main()
{
    int n;
    cin >> n;
    int house[n + 1][3];
    int dp[n + 1][3];
    int result = MAX;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> house[i][j];
        }
    }
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (i == j)
            {
                dp[1][i] = house[0][i];
            }
            else
            {
                dp[1][j] = MAX;
            }
        }
        for (int j = 2; j <= n; j++)
        {
            dp[j][0] = house[j - 1][0] + min(dp[j - 1][1], dp[j - 1][2]);
            dp[j][1] = house[j - 1][1] + min(dp[j - 1][0], dp[j - 1][2]);
            dp[j][2] = house[j - 1][2] + min(dp[j - 1][0], dp[j - 1][1]);
        }
        for (int j = 0; j <= 2; j++)
        {
            if (j == i)
            {
                continue;
            }
            result = min(result, dp[n][j]);
        }
    }
    cout << result;
    return 0;
}