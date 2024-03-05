#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
int N, M, K, X;
vector<vector<int>> graph;
vector<bool> isVisited;
vector<int> result;

void bfs(int start)
{
    queue<pair<int, int>> q;
    q.push({start, 0});
    isVisited[start] = true;
    while (!q.empty())
    {
        int cur = q.front().first;
        int curDep = q.front().second;
        if (curDep == K)
        {
            result.push_back(cur);
        }
        q.pop();
        for (int i = 0; i < graph[cur].size(); i++)
        {
            int next = graph[cur][i];
            if (!isVisited[next])
            {
                q.push({next, curDep + 1});
                isVisited[next] = true;
            }
        }
    }
}
int main()
{
    cin >> N >> M >> K >> X;
    graph.resize(N + 1);
    isVisited.resize(N + 1);
    fill(isVisited.begin(), isVisited.end(), false);
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
    sort(result.begin(), result.end());
    if (result.empty())
    {
        cout << -1;
    }
    else
    {
        for (int i = 0; i < result.size(); i++)
        {
            cout << result[i] << "\n";
        }
    }
    return 0;
}