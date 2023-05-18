#include <iostream>
#define MAX 500
using namespace std;
int n;
int graph[MAX][MAX];
int dp[MAX][MAX];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int result = 0;
int dfs(int x, int y)
{
    if(dp[x][y] != 0) {
        return dp[x][y];
    }
    dp[x][y] = 1;
    for (int i = 0; i < 4; i++)
    {
        int xx = x + dx[i];
        int yy = y + dy[i];
        if (xx >= 0 && xx < n && yy >= 0 && yy < n)
        {
            if (graph[x][y] < graph[xx][yy])
            {
                dp[x][y] = max(dp[x][y],dfs(xx,yy)+1);
            }
        }
    }
    return dp[x][y];
}
int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> graph[i][j];
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (dp[i][j] == 0)
            {
                result = max(result, dfs(i, j));
            }
        }
    }
    cout << result;
}