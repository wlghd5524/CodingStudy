#include <iostream>
#include <vector>
#include <queue>
#define INF 2000000000
using namespace std;
int main()
{
    int N, M, start;
    cin >> N >> M;
    start = 1;
    vector<int> dist(N + 1, INF);
    vector<vector<pair<int, int>>> graph(N + 1);
    dist[start] = 0;
    for (int i = 0; i < M; i++)
    {
        int from, to, dis;
        cin >> from >> to >> dis;
        graph[from].emplace_back(make_pair(to, dis));
        graph[to].push_back({from, dis});
    }
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push(make_pair(0, start));
    while (!pq.empty())
    {
        int cost = pq.top().first;
        int cur = pq.top().second;
        pq.pop();
        for (int i = 0; i < graph[cur].size(); i++)
        {
            int next = graph[cur][i].first;
            int nextCost = cost + graph[cur][i].second;
            if (nextCost < dist[next])
            {
                dist[next] = nextCost;
                pq.push(make_pair(nextCost, next));
            }
        }
    }
    cout << dist[N];
    return 0;
}