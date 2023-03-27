#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int x, y, result;
vector<pair<int, int>> graph[1001];
int dist[1001] = {0};
bool visited[1001] = {false};

int bfs()
{
    fill(dist, dist + 1001, -1);
    queue<int> q;
    q.push(x);
    visited[x] = true;
    dist[x] = 0;
    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        for (auto next : graph[cur])
        {
            if (dist[next.first] == -1)
            {
                dist[next.first] = dist[cur] + next.second;
                q.push(next.first);
            }
        }
    }
    return dist[y];
}
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n - 1; i++)
    {
        int a, b, dis;
        cin >> a >> b >> dis;
        graph[a].push_back({b, dis});
        graph[b].push_back({a, dis});
    }
    for (int i = 0; i < m; i++)
    {
        cin >> x >> y;
        int result = bfs();
        cout << result << "\n";
        result = 0;
        fill(visited, visited + 1001, false);
    }
    return 0;
}