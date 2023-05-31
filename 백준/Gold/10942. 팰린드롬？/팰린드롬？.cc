#include <iostream>
using namespace std;
int arr[2001];
int dp[2001][2001];
int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }
    for (int i = 1; i <= n; i++)
    {
        if (arr[i] == arr[i + 1])
        {
            dp[i][i + 1] = true;
        }
        dp[i][i] = 1;
    }
    for (int i = n; i >= 1; i--)
    {
        for (int j = n; j >= 1; j--)
        {
            if (arr[i] == arr[j] && dp[i + 1][j - 1] == 1)
            {
                dp[i][j] = 1;
            }
        }
    }
    int m;
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        cout << dp[a][b] << "\n";
    }
    return 0;
}