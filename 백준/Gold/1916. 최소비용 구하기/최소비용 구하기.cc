#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define INF 2000000000
using namespace std;
int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m, start, end;
    cin >> n >> m;
    vector<vector<pair<int, int>>> graph(n + 1);
    vector<int> cost(n + 1, INF);
    for (int i = 0; i < m; i++)
    {
        int from, to, dist;
        cin >> from >> to >> dist;
        graph[from].push_back(make_pair(to, dist));
    }
    for(int i = 0;i<n+1;i++) {
        sort(graph[i].begin(),graph[i].end());
    }
    cin >> start >> end;
    cost[start] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push(make_pair(0, start));
    while (!pq.empty())
    {
        int curCost = pq.top().first;
        int cur = pq.top().second;
        pq.pop();
        for (int i = 0; i < graph[cur].size(); i++)
        {
            int next = graph[cur][i].first;
            int nextCost = graph[cur][i].second + curCost;
            if (nextCost < cost[next])
            {
                cost[next] = nextCost;
                pq.push(make_pair(nextCost, next));
            }
        }
    }
    cout << cost[end];
    return 0;
}