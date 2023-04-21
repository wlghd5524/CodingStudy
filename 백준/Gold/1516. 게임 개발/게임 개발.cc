#include <iostream>
#include <queue>
#include <vector>
using namespace std;
vector<int> graph[501];
vector<int> degree(501, 0);
vector<int> costs(501, 0);
vector<int> dp(501, 0);
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int cost;
        cin >> cost;
        costs[i] = cost;
        while (1)
        {
            int post;
            cin >> post;
            if (post == -1)
            {
                break;
            }
            else
            {
                graph[post].push_back(i);
                degree[i]++;
            }
        }
    }
    queue<int> q;
    for (int i = 1; i <= n; i++)
    {
        if (degree[i] == 0)
        {
            q.push(i);
            dp[i] = costs[i];
        }
    }
    while(!q.empty())
    {
        int cur = q.front();
        q.pop();
        for (int i = 0; i < graph[cur].size(); i++)
        {
            int next = graph[cur][i];
            if (--degree[next] == 0)
            {
                q.push(next);
            }
            dp[next] = max(dp[cur] + costs[next], dp[next]);
        }
    }
    for (int i = 1; i <= n; i++)
    {
        cout << dp[i] << "\n";
    }
    return 0;
}