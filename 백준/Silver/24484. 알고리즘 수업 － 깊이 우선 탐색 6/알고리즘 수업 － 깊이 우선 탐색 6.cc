#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M, start;
vector<vector<int>> graph;  
vector<long long int> depth;
vector<long long int> ord;
int cnt = 1;
void dfs(int cur, int dep)
{
    ord[cur] = cnt;
    cnt++;
    depth[cur] = dep;
    for (int i = 0; i < graph[cur].size(); i++)
    {
        if (depth[graph[cur][i]] == -1)
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
        ord.push_back(0);
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
    long long int result = 0;
    for (int i = 1; i <= N; i++)
    {
        result += depth[i] * ord[i];
    }
    cout << result;
    return 0;
}