#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
int N, M, R;
vector<vector<int>> graph;
vector<int> isVisited;
vector<int> order;

void bfs(int start)
{
    queue<int> q;
    q.push(start);
    isVisited[start] = true;
    int count = 1;
    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        order[cur] = count;
        count++;
        for (int i = 0; i < graph[cur].size(); i++)
        {
            int next = graph[cur][i];
            if (!isVisited[next])
            {
                q.push(next);
                isVisited[next] = true;
            }
        }
    }
}

int main()
{
    cin >> N >> M >> R;
    graph.resize(N + 1);
    isVisited.resize(N + 1);
    order.resize(N + 1);
    for (int i = 0; i < M; i++)
    {
        int from, to;
        cin >> from >> to;
        graph[from].push_back(to);
        graph[to].push_back(from);
    }
    for (int i = 1; i <= N; i++)
    {
        sort(graph[i].begin(), graph[i].end(), greater<>());
    }
    bfs(R);
    for (int i = 1; i <= N; i++)
    {
        cout << order[i] << "\n";
    }
    return 0;
}