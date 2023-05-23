#include <iostream>
using namespace std;
int n, m, result = 0;
int graph[500][500];
int dp[500][500];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int dfs(int x, int y)
{
    if (x == n - 1 && y == m - 1)
    {
        return 1;
    }
    if (dp[x][y] != -1)
    {
        return dp[x][y];
    }
    dp[x][y] = 0;
    for (int i = 0; i < 4; i++)
    {
        int xx = x + dx[i];
        int yy = y + dy[i];
        if (xx >= 0 && xx < n && yy >= 0 && yy < m && graph[x][y] > graph[xx][yy])
        {
            dp[x][y] = dp[x][y] + dfs(xx, yy);
        }
    }
    return dp[x][y];
}
int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> graph[i][j];
            dp[i][j] = -1;
        }
    }
    cout << dfs(0, 0);
    return 0;
}