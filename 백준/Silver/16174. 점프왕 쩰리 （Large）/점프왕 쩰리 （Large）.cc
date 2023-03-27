#include <iostream>
#include <queue>
using namespace std;
int N;
int graph[64][64];
bool visited[64][64];
void bfs()
{
    queue<pair<int, int>> q;
    q.push({0, 0});
    visited[0][0] = true;
    while (!q.empty())
    {
        int a = q.front().first;
        int b = q.front().second;
        q.pop();
        if (graph[a][b] == -1)
        {
            cout << "HaruHaru";
            return;
        }
        if (a + graph[a][b] < N && !visited[a+graph[a][b]][b])
        {
            q.push({a + graph[a][b], b});
            visited[a + graph[a][b]][b] = true;
        }
        if (b + graph[a][b] < N && !visited[a][b+graph[a][b]])
        {
            q.push({a, b + graph[a][b]});
            visited[a][b + graph[a][b]] = true;
        }
    }
    cout << "Hing";
}
int main()
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> graph[i][j];
        }
    }
    bfs();
    return 0;
}