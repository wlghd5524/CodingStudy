#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M, start;
vector<vector<int>> graph;
vector<long long int> depth;
vector<long long int> order;
int cnt = 1;
void dfs(int cur, int dep)
{
    order[cur] = cnt;
    cnt++;
    depth[cur] = dep;
    for (int i = 0; i < graph[cur].size(); i++)
    {
        int next = graph[cur][i];
        if (depth[next] == -1)
        {
            dfs(graph[cur][i], dep + 1);
        }
    }
}
int main()
{
    cin >> N >> M >> start;
    graph.resize(N + 1);
    order.resize(N + 1);
    depth.resize(N + 1);
    fill(order.begin(), order.end(), 0);
    fill(depth.begin(), depth.end(), -1);
    for (int i = 0; i < M; i++)
    {
        int from, to;
        cin >> from >> to;
        graph[from].push_back(to);
        graph[to].push_back(from);
    }
    for (int i = 0; i <= N; i++)
    {
        sort(graph[i].begin(), graph[i].end());
    }
    dfs(start, 0);
    long long int result = 0;
    for (int i = 1; i <= N; i++)
    {
        if (depth[i] == -1)
        {
            continue;
        }
        result += depth[i] * order[i];
    }
    cout << result;
    return 0;
}