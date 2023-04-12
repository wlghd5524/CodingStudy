#include <iostream>
#define MAX 50
using namespace std;
int n, m;
string graph[MAX];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int dp[MAX][MAX];
int result;
bool inf = false;
void dfs(int x, int y, int cnt)
{
    if (graph[x][y] == 'H')
    {
        result = max(result, cnt);
        return;
    }
    if (cnt > 1000000)
    {
        inf = true;
        return;
    }
    int num = graph[x][y] - '0';
    for (int i = 0; i < 4; i++)
    {
        int xx = x + (dx[i] * num);
        int yy = y + (dy[i] * num);
        if (xx >= 0 && xx < n && yy >= 0 && yy < m && graph[xx][yy] != 'H' && dp[xx][yy] < cnt + 1)
        {
            dp[xx][yy] = cnt + 1;
            dfs(xx, yy, cnt + 1);
        }
    }
    result = max(result, cnt);
    return;
}
int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> graph[i];
    }
    dfs(0, 0, 0);
    if (inf)
    {
        cout << -1;
    }
    else
    {
        cout << result + 1;
    }
    return 0;
}