#include <iostream>
#include <queue>
#include <vector>
using namespace std;
vector<int> graph[32001];
vector<int> degree(32001, 0);
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int from, to;
        cin >> from >> to;
        graph[from].push_back(to);
        degree[to]++;
    }
    queue<int> q;
    for (int i = 1; i <= n; i++)
    {
        if (degree[i] == 0)
        {
            q.push(i);
        }
    }
    for (int i = 0; i < n; i++)
    {
        int cur = q.front();
        q.pop();
        cout << cur << " ";
        for (int i = 0; i < graph[cur].size(); i++)
        {
            int next = graph[cur][i];
            if (--degree[next] == 0)
            {
                q.push(next);
            }
        }
    }
    return 0;
}