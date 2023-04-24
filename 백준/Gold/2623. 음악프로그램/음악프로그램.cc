#include <iostream>
#include <queue>
#include <vector>
#define MAX 1001
using namespace std;
int main()
{
    vector<int> graph[MAX];
    vector<int> inDegree(MAX, 0);
    vector<int> result;
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int k;
        cin >> k;
        if (k == 0)
        {
            continue;
        }
        else if (k == 1)
        {
            int tmp;
            cin >> tmp;
            continue;
        }
        int from;
        cin >> from;
        for (int j = 0; j < k - 1; j++)
        {
            int to;
            cin >> to;
            graph[from].push_back(to);
            inDegree[to]++;
            from = to;
        }
    }
    queue<int> q;
    for (int i = 1; i <= n; i++)
    {
        if (inDegree[i] == 0)
        {
            q.push(i);
        }
    }
    while (!q.empty())
    {
        if (q.empty())
        {
            cout << 0;
            return 0;
        }
        int cur = q.front();
        q.pop();
        result.push_back(cur);
        for (int j = 0; j < graph[cur].size(); j++)
        {
            int next = graph[cur][j];
            if (--inDegree[next] == 0)
            {
                q.push(next);
            }
        }
    }
    if (result.size() != n)
    {
        cout << 0;
        return 0;
    }
    for (int i = 0; i < n; i++)
    {
        cout << result[i] << "\n";
    }
    return 0;
}