#include <iostream>
#include <queue>
#include <vector>
#include <string.h>
using namespace std;
int V, E;
bool no = false;
vector<int> graph[20001];
int visited[20001];
void bfs(int a)
{
    queue<int> q;
    q = queue<int>();
    q.push(a);
    visited[a] = 1;
    while (!q.empty())
    {
        int x = q.front();
        int color = visited[x];
        q.pop();
        for (int i = 0; i < graph[x].size(); i++)
        {
            int next = graph[x][i];
            if (visited[next] == 0)
            {
                q.push(next);
                if (color == 1)
                {
                    visited[next] = 2;
                }
                else
                {
                    visited[next] = 1;
                }
            }
        }
    }
}
int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T;
    cin >> T;
    for (int t = 0; t < T; t++)
    {
        cin >> V >> E;
        for (int i = 0; i < E; i++)
        {
            int from, to;
            cin >> from >> to;
            graph[from].push_back(to);
            graph[to].push_back(from);
        }
        for (int i = 1; i <= V; i++)
        {
            if (visited[i] == 0)
            {
                bfs(i);
            }
        }
        for (int i = 1; i <= V; i++)
        {
            for (int j = 0; j < graph[i].size(); j++)
            {
                int next = graph[i][j];
                if (visited[i] == visited[next])
                {
                    no = true;
                }
            }
        }
        if (no)
        {
            cout << "NO\n";
        }
        else
        {
            cout << "YES\n";
        }
        no = false;
        for (int i = 0; i <= V; i++)
        {
            graph[i].clear();
        }
        memset(visited, 0, sizeof(visited));
    }
    return 0;
}