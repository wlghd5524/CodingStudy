#include <iostream>
#include <vector>
#include <queue>
#define INF 2000000000
using namespace std;
int main()
{
    int V, E, start;
    cin >> V >> E;
    cin >> start;
    vector<int> dist(V + 1, INF);
    vector<vector<pair<int, int>>> graph(V + 1);
    dist[start] = 0;
    for (int i = 0; i < E; i++)
    {
        int from, to, dis;
        cin >> from >> to >> dis;
        graph[from].emplace_back(make_pair(to, dis));
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
    for (int i = 1; i <= V; i++)
    {
        if (dist[i] == INF)
        {
            cout << "INF" << "\n";
            continue;
        }
        cout << dist[i] << "\n";
    }
    return 0;
}