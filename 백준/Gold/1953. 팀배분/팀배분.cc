#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int n;
vector<int> graph[101];
int visited[101];
void bfs(int start)
{
    queue<int> q;
    q.push(start);
    visited[start] = 1;
    while (!q.empty())
    {
        int x = q.front();
        q.pop();
        int color = visited[x];
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
                if (color == 2)
                {
                    visited[next] = 1;
                }
            }
        }
    }
}
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int num;
        cin >> num;
        for (int j = 0; j < num; j++)
        {
            int to;
            cin >> to;
            graph[i].push_back(to);
            graph[to].push_back(i);
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (visited[i] == 0)
        {
            bfs(i);
        }
    }
    vector<int> blue;
    vector<int> white;
    for (int i = 1; i <= n; i++)
    {
        if (visited[i] == 1)
        {
            blue.push_back(i);
        }
        if (visited[i] == 2)
        {
            white.push_back(i);
        }
    }
    cout << blue.size() << "\n";
    for (int i = 0; i < blue.size(); i++)
    {
        cout << blue[i] << " ";
    }
    cout << "\n";
    cout << white.size() << "\n";
    for (int i = 0; i < white.size(); i++)
    {
        cout << white[i] << " ";
    }
}