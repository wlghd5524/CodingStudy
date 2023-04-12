#include <iostream>
#include <vector>
#include <string.h>
#define MAX 100001
using namespace std;
int n, result, endPoint;
vector<pair<int, int>> graph[MAX];
bool visited[MAX];
void dfs(int x, int dis)
{
    visited[x] = true;
    if (result < dis)
    {
        result = dis;
        endPoint = x;
    }
    for (int i = 0; i < graph[x].size(); i++)
    {
        int next = graph[x][i].first;
        int nextDis = graph[x][i].second;
        if (!visited[next])
        {
            dfs(next, dis + nextDis);
        }
    }
}
int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int from, to, dis;
        cin >> from;
        while (1)
        {
            cin >> to;
            if (to == -1)
            {
                break;
            }
            cin >> dis;
            graph[from].push_back({to, dis});
            graph[to].push_back({from, dis});
        }
    }
    dfs(1, 0);
    memset(visited, false, sizeof(visited));
    result = 0;
    dfs(endPoint, 0);
    cout << result;
}