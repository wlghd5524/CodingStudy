#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<vector<pair<int, int>>> graph;
vector<bool> isVisited;
long long int result = 0;
void dfs(int cur, long long int dis)
{
    if (result < dis)
    {
        result = dis;
    }
    isVisited[cur] = true;
    for (int i = 0; i < graph[cur].size(); i++)
    {
        int next = graph[cur][i].first;
        int cost = graph[cur][i].second;

        if (!isVisited[next])
        {
            dfs(next, dis + cost);
        }
    }
}
int main()
{
    int n;
    cin >> n;
    graph.resize(n + 1);
    isVisited.resize(n + 1);
    for (int i = 0; i < n - 1; i++)
    {
        int from, to, dis;
        cin >> from >> to >> dis;
        graph[from].push_back({to, dis});
        graph[to].push_back({from, dis});
    }
    dfs(1, 0);
    cout << result;
    return 0;
}