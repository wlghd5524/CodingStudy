#include <iostream>
#include <queue>
#include <vector>
#define MAX 32000
using namespace std;
vector<int> graph[MAX + 1];
vector<int> inDegree(MAX + 1, 0);
int n, m;
int main()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int from, to;
        cin >> from >> to;
        graph[from].push_back(to);
        inDegree[to]++;
    }
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 1; i <= n; i++)
    {
        if (inDegree[i] == 0)
        {
            pq.push(i);
        }
    }
    while (!pq.empty())
    {
        int x = pq.top();
        pq.pop();
        cout << x << " ";
        for (int i = 0; i < graph[x].size(); i++)
        {
            int next = graph[x][i];
            if (--inDegree[next] == 0)
            {
                pq.push(next);
            }
        }
    }
}