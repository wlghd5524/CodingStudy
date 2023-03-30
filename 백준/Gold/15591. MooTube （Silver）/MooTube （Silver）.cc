#include <iostream>
#include <queue>
#include <vector>
#include <string.h>
using namespace std;
int N, Q, k, v;
bool visited[5001];
vector<pair<int, long long int>> graph[5001];
void bfs()
{
    queue<pair<int, long long int>> q;
    q.push({v, k});
    visited[v] = true;
    int cnt = 0;
    while (!q.empty())
    {
        int cur = q.front().first;
        q.pop();
        for (int i = 0; i < graph[cur].size(); i++)
        {
            int next = graph[cur][i].first;
            long long int next_cost = graph[cur][i].second;
            if (!visited[next] && next_cost >= k)
            {
                visited[next] = true;
                q.push({next, next_cost});
                cnt++;
            }
        }
    }
    cout << cnt << "\n";
    q = queue<pair<int, long long int>>();
}
int main()
{
    cin >> N >> Q;
    for (int i = 0; i < N - 1; i++)
    {
        int from, to;
        long long int cost;
        cin >> from >> to >> cost;
        graph[from].push_back({to, cost});
        graph[to].push_back({from, cost});
    }
    for (int i = 0; i < Q; i++)
    {
        cin >> k >> v;
        bfs();
        memset(visited, false, sizeof(visited));
    }
    return 0;
}