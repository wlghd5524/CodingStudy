#include <iostream>
using namespace std;
int max(double a, double b, double c)
{
    int result = a;
    if (b > result)
    {
        result = b;
    }
    if (c > result)
    {
        result = c;
    }
    return result;
}
int main()
{
    int money = 0;
    int year = 0;
    cin >> money >> year;
    int dp[11] = {
        0,
    };
    dp[0] = money;
    dp[1] = dp[0] * 1.05;
    dp[2] = dp[1] * 1.05;
    dp[3] = dp[0] * 1.2;
    dp[4] = dp[1] * 1.2;
    dp[5] = dp[0] * 1.35;
    for (int i = 6; i <= year; i++)
    {
        dp[i] = max(dp[i - 1] * 1.05, dp[i - 3] * 1.2, dp[i - 5] * 1.35);
    }
    cout << dp[year];
}