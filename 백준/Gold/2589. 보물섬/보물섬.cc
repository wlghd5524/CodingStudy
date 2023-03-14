#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
int n, m;
string graph[50];

int bfs(int x, int y, int timeGraph[50][50], bool visited[50][50])
{
    queue<pair<int, int>> q;
    q.push({x, y});
    int mx = 0;
    while (!q.empty())
    {
        int a = q.front().first;
        int b = q.front().second;
        q.pop();
        visited[a][b] = true;
        if (b - 1 >= 0 && graph[a][b - 1] == 'L' && !visited[a][b - 1])
        {
            q.push({a, b - 1});
            timeGraph[a][b - 1] = timeGraph[a][b] + 1;
            visited[a][b - 1] = true;
        }
        if (b + 1 < m && graph[a][b + 1] == 'L' && !visited[a][b + 1])
        {
            q.push({a, b + 1});
            timeGraph[a][b + 1] = timeGraph[a][b] + 1;
            visited[a][b + 1] = true;
        }
        if (a - 1 >= 0 && graph[a - 1][b] == 'L' && !visited[a - 1][b])
        {
            q.push({a - 1, b});
            timeGraph[a - 1][b] = timeGraph[a][b] + 1;
            visited[a - 1][b] = true;
        }
        if (a + 1 < n && graph[a + 1][b] == 'L' && !visited[a + 1][b])
        {
            q.push({a + 1, b});
            timeGraph[a + 1][b] = timeGraph[a][b] + 1;
            visited[a + 1][b] = true;
        }
        mx = max(mx, timeGraph[a][b]);
    }
    return mx;
}
int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int timeGraph[50][50] = {0};
    bool visited[50][50] = {false};
    int result = 0;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> graph[i];
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (graph[i][j] == 'L')
            {
                int bfs_result = bfs(i, j, timeGraph, visited);
                result = max(result, bfs_result);
                memset(timeGraph, 0, sizeof(timeGraph));
                memset(visited, false, sizeof(visited));
            }
        }
    }
    cout << result;
    return 0;
}