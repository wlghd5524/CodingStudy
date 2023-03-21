#include <iostream>
#include <vector>
using namespace std;
vector<int> graph[100001];
int visited[100001];
int result[100001];
void dfs(int v)
{
    visited[v] = true;
    for (int i = 0; i < graph[v].size(); i++)
    {
        if (!visited[graph[v][i]])
        {
            result[graph[v][i]] = v;
            dfs(graph[v][i]);
        }
    }
}
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        graph[a].emplace_back(b);
        graph[b].emplace_back(a);
    }
    dfs(1);
    for (int i = 2; i <= n; i++)
    {
        cout << result[i] << "\n";
    }
}