#include <iostream>
#include <vector>
#include <string.h>
#define MAX 10001
using namespace std;
int n;
vector<pair<int, int>> graph[MAX];
bool visited[MAX];
int endPoint = 0;
int result = 0;
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
        auto next = graph[x][i];
        if (!visited[next.first])
        {
            dfs(next.first, dis + next.second);
        }
    }
}
int main()
{
    cin >> n;
    for (int i = 0; i < n - 1; i++)
    {
        int from, to, dis;
        cin >> from >> to >> dis;
        graph[from].push_back({to, dis});
        graph[to].push_back({from, dis});
    }
    dfs(1, 0);
    memset(visited, false, sizeof(visited));
    result = 0;
    dfs(endPoint, 0);
    cout << result;
    return 0;
}