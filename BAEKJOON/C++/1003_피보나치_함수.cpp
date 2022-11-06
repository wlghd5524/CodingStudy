#include <iostream>
using namespace std;
int main()
{
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        int n;
        cin >> n;
        pair<int, int> dp[n + 1];
        dp[0] = {1, 0};
        dp[1] = {0, 1};
        for (int i = 2; i <= n; i++)
        {
            dp[i].first = dp[i - 1].first + dp[i - 2].first;
            dp[i].second = dp[i - 1].second + dp[i - 2].second;
        }
        cout << dp[n].first << " " << dp[n].second << "\n";
    }
    return 0;
}