#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
#define MAX 1001
using namespace std;
vector<int> cost(MAX, 0);
vector<int> graph[MAX];
vector<int> indegree(MAX, 0);
vector<int> dp(MAX, 0);
int main()
{
    int T;
    cin >> T;
    for (int t = 0; t < T; t++)
    {
        int n, k;
        cin >> n >> k;
        for (int i = 1; i <= n; i++)
        {
            cin >> cost[i];
            indegree[i] = 0;
            dp[i] = 0;
            memset(graph, 0, sizeof(graph));
        }
        for (int i = 1; i <= k; i++)
        {
            int from, to;
            cin >> from >> to;
            graph[from].push_back(to);
            indegree[to]++;
        }
        queue<int> q;
        q = queue<int>();
        for (int i = 1; i <= n; i++)
        {
            if (indegree[i] == 0)
            {
                q.push(i);
                dp[i] = cost[i];
            }
        }
        int w;
        cin >> w;
        while (!q.empty())
        {
            int cur = q.front();
            q.pop();
            if (w == cur)
            {
                cout << dp[cur] << "\n";
                break;
            }
            for (int i = 0; i < graph[cur].size(); i++)
            {
                int next = graph[cur][i];
                if (--indegree[next] == 0)
                {
                    q.push(next);
                }
                dp[next] = max(dp[next], dp[cur] + cost[next]);
            }
        }
    }
    return 0;
}