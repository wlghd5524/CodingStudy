#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#define INF 999999999999999
#define MAX 100001
using namespace std;

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N, M;
    cin >> N >> M;
    int sight[MAX];
    vector<pair<int, int>> graph[MAX];
    long long int dist[MAX];
    for (int i = 0; i < N; i++)
    {
        cin >> sight[i];
        dist[i] = INF;
    }
    for (int i = 0; i < M; i++)
    {
        int from, to, cost;
        cin >> from >> to >> cost;
        graph[from].push_back({to, cost});
        graph[to].push_back({from, cost});
    }
    for (int i = 0; i < N; i++)
    {
        sort(graph[i].begin(), graph[i].end());
    }
    priority_queue<pair<long long int, int>, vector<pair<long long int, int>>, greater<pair<long long int, int>>> pq;
    pq.push({0, 0});
    dist[0] = 0;
    while (!pq.empty())
    {
        int cur = pq.top().second;
        long long int cur_cost = pq.top().first;
        pq.pop();
        if(cur_cost > dist[cur]) {
            continue;
        }
        if (cur == N - 1)
        {
            if (dist[cur] == INF)
            {
                cout << -1;
                return 0;
            }
            cout << dist[cur];
            return 0;
        }
        for (int i = 0; i < graph[cur].size(); i++)
        {
            int next = graph[cur][i].first;
            long long int next_cost = graph[cur][i].second + cur_cost;
            if (next_cost < dist[next] && (sight[next] == 0 || next == N - 1))
            {
                pq.push({next_cost, next});
                dist[next] = next_cost;
            }
        }
    }
    cout << -1;
    return 0;
}