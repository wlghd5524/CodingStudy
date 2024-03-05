#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
int N, M, K, X;
vector<vector<int>> graph;
vector<int> depth;

void bfs(int start)
{
    queue<pair<int, int>> q;
    q.push({start, 0});
    depth[start] = 0;
    while (!q.empty())
    {
        int cur = q.front().first;
        int curDep = q.front().second;
        q.pop();
        for (int i = 0; i < graph[cur].size(); i++)
        {
            int next = graph[cur][i];
            if (depth[next] == -1)
            {
                q.push({next, curDep + 1});
                depth[next] = curDep + 1;
            }
        }
    }
}
int main()
{
    cin >> N >> M >> K >> X;
    graph.resize(N + 1);
    depth.resize(N + 1);
    fill(depth.begin(), depth.end(), -1);
    for (int i = 0; i < M; i++)
    {
        int from, to;
        cin >> from >> to;
        graph[from].push_back(to);
    }
    for (int i = 1; i <= N; i++)
    {
        sort(graph[i].begin(), graph[i].end());
    }
    bfs(X);
    if (find(depth.begin(), depth.end(), K) == depth.end())
    {
        cout << -1;
        return 0;
    }
    for (int i = 1; i <= N; i++)
    {
        if (depth[i] == K)
        {
            cout << i << "\n";
        }
    }
}