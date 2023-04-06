#include <iostream>
#include <queue>
using namespace std;
int graph[1000][1000];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int dist[1000][1000];
bool visited[1000][1000];
int n, m;
void bfs(int a, int b)
{
    queue<pair<int, int>> q;
    q.push({a, b});
    visited[a][b] = true;
    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int xx = x + dx[i];
            int yy = y + dy[i];
            if (!visited[xx][yy] && graph[xx][yy] == 1)
            {
                visited[xx][yy] = true;
                dist[xx][yy] = dist[x][y] + 1;
                q.push({xx, yy});
            }
        }
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
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (graph[i][j] == 2)
            {
                bfs(i, j);
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if(graph[i][j] == 1 && dist[i][j] == 0) {
                dist[i][j] = -1;
            }
            cout << dist[i][j] << " ";
        }
        cout << "\n";
    }
}