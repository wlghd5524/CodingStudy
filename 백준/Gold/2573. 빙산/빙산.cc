#include <iostream>
#include <queue>
#include <vector>
#include <string.h>
using namespace std;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
const int MAX = 300;
int n, m;
int graph[MAX][MAX];
bool visited[MAX][MAX];
bool first = true;
void dfs(int a, int b)
{
    for (int i = 0; i < 4; i++)
    {
        int aa = a + dx[i];
        int bb = b + dy[i];
        if (!visited[aa][bb] && graph[aa][bb] != 0)
        {
            visited[aa][bb] = true;
            dfs(aa, bb);
        }
    }
}
void bfs()
{
    queue<pair<int, int>> q;
    int result = 0;
    while (1)
    {
        int cnt[MAX][MAX] = {
            0,
        };
        q = queue<pair<int, int>>();
        for (int i = 1; i < n; i++)
        {
            for (int j = 1; j < m; j++)
            {
                if (graph[i][j] != 0)
                {
                    q.push({i, j});
                }
            }
        }
        while (!q.empty())
        {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            for (int i = 0; i < 4; i++)
            {
                int xx = x + dx[i];
                int yy = y + dy[i];
                if (xx >= 0 && xx < n && yy >= 0 && yy < m)
                {
                    if (graph[xx][yy] == 0)
                    {
                        cnt[x][y]++;
                    }
                }
            }
        }
        result++;
        for (int i = 1; i < n; i++)
        {
            for (int j = 1; j < m; j++)
            {
                if (graph[i][j] >= cnt[i][j])
                {
                    graph[i][j] -= cnt[i][j];
                }
                else
                {
                    graph[i][j] = 0;
                }
            }
        }
        int dfs_cnt = 0;
        for (int i = 1; i < n; i++)
        {
            for (int j = 1; j < m; j++)
            {
                if (graph[i][j] != 0 && !visited[i][j])
                {
                    dfs(i, j);
                    dfs_cnt++;
                }
            }
        }
        if (dfs_cnt >= 2)
        {
            if (first)
            {
                cout << 0;
                return;
            }
            cout << result;
            return;
        }
        else if (dfs_cnt == 0)
        {
            cout << 0;
            return;
        }
        first = false;
        memset(visited, false, sizeof(visited));
    }
}
int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> graph[i][j];
        }
    }
    bfs();
    return 0;
}