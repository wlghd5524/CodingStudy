#include <iostream>
#define MAX 750
using namespace std;
int n, m;
string graph[MAX];
bool visited[MAX][MAX];
int dx[8] = {-1, 1, 0, 0, -1, -1, 1, 1};
int dy[8] = {0, 0, -1, 1, -1, 1, -1, 1};
int result = 0;
int cnt = 0;
void dfs(int x, int y)
{
    cnt++;
    visited[x][y] = true;
    for (int i = 0; i < 8; i++)
    {
        int xx = x + dx[i];
        int yy = y + dy[i];
        if (xx >= 0 && xx < n && yy >= 0 && yy < m)
        {
            if (!visited[xx][yy] && graph[xx][yy] == '.')
            {
                dfs(xx, yy);
            }
        }
    }
}
int main()
{
    cin >> m >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> graph[i];
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (!visited[i][j] && graph[i][j] == '.')
            {
                dfs(i, j);
                result = max(result, cnt);
                cnt = 0;
            }
        }
    }
    cout << result;
    return 0;
}