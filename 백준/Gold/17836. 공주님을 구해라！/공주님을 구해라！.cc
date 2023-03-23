#include <iostream>
#include <queue>
using namespace std;
int N, M, T;
int graph[100][100];
bool visited[100][100][2] = {false};
int dir[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
void bfs()
{
    queue<pair<pair<int, int>, pair<bool, int>>> q;
    q.push(make_pair(make_pair(0, 0), make_pair(false, 0)));
    visited[0][0][0] = true;
    int cnt = 0;
    while (!q.empty())
    {
        int a = q.front().first.first;
        int b = q.front().first.second;
        int gram = q.front().second.first;
        int t = q.front().second.second;
        q.pop();
        if (t > T)
        {
            cout << "Fail";
            return;
        }
        if (a == N - 1 && b == M - 1)
        {
            cout << t;
            return;
        }
        for (int i = 0; i < 4; i++)
        {
            int na = a + dir[i][0];
            int nb = b + dir[i][1];
            int nt = t + 1;
            if (na >= 0 && na < N && nb >= 0 && nb < M)
            {
                if (gram)
                {
                    if (!visited[na][nb][1])
                    {
                        q.push({{na, nb}, {true, nt}});
                        visited[na][nb][1] = true;
                    }
                }
                else
                {
                    if (graph[na][nb] == 0 && !visited[na][nb][0])
                    {
                        q.push({{na, nb}, {false, nt}});
                        visited[na][nb][0] = true;
                    }
                    else if (graph[na][nb] == 2 && !visited[na][nb][0])
                    {
                        q.push({{na, nb}, {true, nt}});
                        visited[na][nb][1] = true;
                    }
                }
            }
        }
    }
    cout << "Fail";
    return;
}
int main()
{
    cin >> N >> M >> T;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> graph[i][j];
        }
    }
    bfs();
    return 0;
}