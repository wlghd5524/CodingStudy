#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int r, c, w;
    cin >> r >> c >> w;
    int dp[r + w + 1][r + w + 1];
    dp[1][1] = 1;
    dp[2][1] = 1;
    dp[2][2] = 1;
    for (int i = 3; i <= r + w; i++)
    {
        dp[i][1] = 1;
        dp[i][i] = 1;
        for (int j = 2; j < i; j++)
        {
            dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
        }
    }
    int cnt = 1;
    int result = 0;
    for (int i = r; i < r + w; i++)
    {
        for (int j = c; j < c + cnt; j++)
        {
            result += dp[i][j];
        }
        cnt++;
    }
    cout << result;
}