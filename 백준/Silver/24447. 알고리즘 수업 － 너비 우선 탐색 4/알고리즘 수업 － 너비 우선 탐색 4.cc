#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
int N, M, R;
vector<vector<int>> graph;
vector<int> isVisited;
vector<long long int> depth;
vector<long long int> order;

void bfs(int start)
{
    queue<pair<int, int>> q;
    q.push({start, 0});
    isVisited[start] = true;
    depth[start] = 0;
    int count = 1;
    while (!q.empty())
    {
        int cur = q.front().first;
        int curDep = q.front().second;
        q.pop();
        order[cur] = count;
        count++;
        for (int i = 0; i < graph[cur].size(); i++)
        {
            int next = graph[cur][i];
            if (!isVisited[next])
            {
                depth[next] = curDep + 1;
                q.push({next, curDep + 1});
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
    depth.resize(N + 1);
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
        depth[i] = -1;
        order[i] = 0;
        sort(graph[i].begin(), graph[i].end());
    }
    bfs(R);
    long long int result = 0;
    for (int i = 1; i <= N; i++)
    {
        result += (depth[i] * order[i]);
    }
    cout << result;
    return 0;
}