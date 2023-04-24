#include <iostream>
#include <queue>
#include <vector>
#define MAX 10000
using namespace std;
vector<int> graph[MAX + 1];
int dp[MAX + 1];
int cost[MAX + 1];
int inDegree[MAX + 1];
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> cost[i];
        int num;
        cin >> num;
        for (int j = 0; j < num; j++)
        {
            int from;
            cin >> from;
            graph[from].push_back(i);
            inDegree[i]++;
        }
    }
    queue<int> q;
    for (int i = 1; i <= n; i++)
    {
        if (inDegree[i] == 0)
        {
            q.push(i);
            dp[i] = cost[i];
        }
    }
    int result = 0;
    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        for (int i = 0; i < graph[cur].size(); i++)
        {
            int next = graph[cur][i];
            if (--inDegree[next] == 0)
            {
                q.push(next);
            }
            dp[next] = max(dp[cur] + cost[next], dp[next]);
        }
    }
    for(int i = 1;i<=n;i++) {
        result = max(dp[i],result);
    }
    cout << result;
    return 0;
}