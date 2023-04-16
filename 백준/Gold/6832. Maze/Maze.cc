#include <iostream>
#include <string.h>
#include <queue>
using namespace std;
int n, m;
string graph[20];
bool visited[20][20];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int result = 0;
int dist[20][20];
void dfs(int x, int y, int cnt)
{
    visited[x][y] = true;
    if (x == n - 1 && y == m - 1)
    {
        result = cnt;
        return;
    }
    if (graph[x][y] == '+')
    {
        for (int i = 0; i < 4; i++)
        {
            int xx = x + dx[i];
            int yy = y + dy[i];
            if (xx >= 0 && xx < n && yy >= 0 && yy < m)
            {
                if (!visited[xx][yy] && graph[xx][yy] != '*')
                {
                    dfs(xx, yy, cnt + 1);
                }
            }
        }
    }
    if (graph[x][y] == '-')
    {
        if (y - 1 >= 0)
        {
            if (!visited[x][y - 1] && graph[x][y - 1] != '*')
            {
                dfs(x, y - 1, cnt + 1);
            }
        }
        if (y + 1 < m)
        {
            if (!visited[x][y + 1] && graph[x][y + 1] != '*')
            {
                dfs(x, y + 1, cnt + 1);
            }
        }
    }
    if (graph[x][y] == '|')
    {
        if (x - 1 >= 0)
        {
            if (!visited[x - 1][y] && graph[x - 1][y] != '*')
            {
                dfs(x - 1, y, cnt + 1);
            }
        }
        if (x + 1 < n)
        {
            if (!visited[x + 1][y] && graph[x + 1][y] != '*')
            {
                dfs(x + 1, y, cnt + 1);
            }
        }
    }
}
void bfs() {
    queue<pair<int,int>> q;
    q.push({0,0});
    while(!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        if (x == n - 1 && y == m - 1)
        {
            result = dist[x][y]+1;
            return;
        }
        if (graph[x][y] == '+')
        {
            for (int i = 0; i < 4; i++)
            {
                int xx = x + dx[i];
                int yy = y + dy[i];
                if (xx >= 0 && xx < n && yy >= 0 && yy < m)
                {
                    if (!visited[xx][yy] && graph[xx][yy] != '*')
                    {
                        q.push({xx,yy});
                        visited[xx][yy] = true;
                        dist[xx][yy] = dist[x][y]+1;
                    }
                }
            }
        }
        if (graph[x][y] == '-')
        {
            if (y - 1 >= 0)
            {
                if (!visited[x][y - 1] && graph[x][y - 1] != '*')
                {
                    q.push({x,y-1});
                    visited[x][y-1] = true;
                    dist[x][y-1] = dist[x][y]+1;
                }
            }
            if (y + 1 < m)
            {
                if (!visited[x][y + 1] && graph[x][y + 1] != '*')
                {
                    q.push({x,y+1});
                    visited[x][y+1] = true;
                    dist[x][y+1] = dist[x][y]+1;
                }
            }
        }
        if (graph[x][y] == '|')
        {
            if (x - 1 >= 0)
            {
                if (!visited[x - 1][y] && graph[x - 1][y] != '*')
                {
                    q.push({x-1,y});
                    visited[x-1][y] = true;
                    dist[x-1][y] = dist[x][y]+1;
                }
            }
            if (x + 1 < n)
            {
                if (!visited[x + 1][y] && graph[x + 1][y] != '*')
                {
                    q.push({x+1,y});
                    visited[x+1][y] = true;
                    dist[x+1][y] = dist[x][y]+1;
                }
            }
        }
    }
}
int main()
{
    int T;
    cin >> T;
    for (int t = 0; t < T; t++)
    {
        cin >> n >> m;
        for (int i = 0; i < n; i++)
        {
            cin >> graph[i];
        }
        bfs();
        if (result == 0)
        {
            cout << -1 << "\n";
        }
        else
        {
            cout << result << "\n";
        }
        result = 0;
        memset(visited, false, sizeof(visited));
        memset(dist,0,sizeof(dist));
    }
    return 0;
}