#include <iostream>
#include <queue>
using namespace std;
int n;
int graph[100001];
bool visited[100001];
int result = 0;
void dfs(int x)
{
    visited[x] = true;
    result++;
    if (x + graph[x] <= n)
    {
        if (!visited[x + graph[x]])
        {
            dfs(x + graph[x]);
        }
    }
    if (x - graph[x] > 0)
    {
        if (!visited[x - graph[x]])
        {
            dfs(x - graph[x]);
        }
    }
}
int main()
{
    int start;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> graph[i];
    }
    cin >> start;
    dfs(start);
    cout << result;
    return 0;
}