#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 100001
using namespace std;
vector<int> graph[MAX];
int result[MAX];
bool visited[MAX];
int n, m, r;
void dfs(int v,int cnt)
{
    visited[v] = true;
    result[v] = cnt;
    for (int i = 0; i < graph[v].size(); i++)
    {
        int next = graph[v][i];
        if (!visited[next])
        {
            dfs(next,cnt+1);
        }
    }
}
int main()
{
    cin >> n >> m >> r;
    for (int i = 0; i < m; i++)
    {
        int from, to;
        cin >> from >> to;
        graph[from].push_back(to);
        graph[to].push_back(from);
    }
    for (int i = 1; i <= n; i++)
    {
        sort(graph[i].begin(), graph[i].end());
        result[i] = -1;
    }
    dfs(r,0);
    for (int i = 1; i <= n; i++)
    {
        cout << result[i] << "\n";
    }
}