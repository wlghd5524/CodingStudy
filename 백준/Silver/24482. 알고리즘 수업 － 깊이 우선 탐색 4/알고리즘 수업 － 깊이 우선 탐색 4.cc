#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M, start;
vector<vector<int>> graph;  
vector<int> depth;
vector<bool> isVisited;
void dfs(int cur, int dep)
{
    isVisited[cur] = true;
    depth[cur] = dep;
    for (int i = 0; i < graph[cur].size(); i++)
    {
        if (!isVisited[graph[cur][i]])
        {
            dfs(graph[cur][i], dep + 1);
        }
    }
}
int main()
{
    cin >> N >> M >> start;
    graph.resize(N + 1);
    for (int i = 0; i < N + 1; i++)
    {
        depth.push_back(-1);
        isVisited.push_back(false);
    }
    for (int i = 0; i < M; i++)
    {
        int from, to;
        cin >> from >> to;
        graph[from].push_back(to);
        graph[to].push_back(from);
    }
    for (int i = 0; i <= N; i++)
    {
        sort(graph[i].begin(), graph[i].end(), greater<>());
    }
    dfs(start, 0);
    for (int i = 1; i <= N; i++)
    {
        cout << depth[i] << "\n";
    }
    return 0;
}