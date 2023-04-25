#include <iostream>
#include <queue>
#include <vector>
#define MAX 1001
using namespace std;
vector<pair<int, int>> graph[MAX];
int indegree[MAX];
int dp[MAX];
vector<int> result[MAX];
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int p, q, r;
        cin >> p >> q >> r;
        graph[p].push_back({q, r});
        indegree[q]++;
    }
    queue<int> q;
    q.push(1);
    result[1].push_back(1);
    int cnt = 0;
    while (!q.empty())
    {
        int cur = q.front();
        q.pop();

        if (cur == 1 && cnt != 0)
        {
            cout << dp[1] << "\n";
            for (int i = 0; i < result[1].size(); i++)
            {
                cout << result[1][i] << " ";
            }
        }
        for (int i = 0; i < graph[cur].size(); i++)
        {
            int next = graph[cur][i].first;
            int next_score = graph[cur][i].second;
            if (--indegree[next] == 0)
            {
                q.push(next);
            }
            if (dp[next] < dp[cur] + next_score)
            {
                dp[next] = dp[cur] + next_score;
                result[next] = result[cur];
                result[next].push_back(next);
            }
        }
        cnt++;
    }
    return 0;
}