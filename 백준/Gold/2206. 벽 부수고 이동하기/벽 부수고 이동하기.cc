#include <iostream>
#include <queue>
using namespace std;
const int MAX = 1000;
int N, M;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
string graph[MAX];
int dist[MAX][MAX];
bool visited[MAX][MAX][2];
void bfs()
{
    queue<pair<pair<int, int>, int>> q;
    q.push({{0, 0}, 0});
    visited[0][0][0] = true;
    while (!q.empty())
    {
        int x = q.front().first.first;
        int y = q.front().first.second;
        int block = q.front().second;
        if (x == N - 1 && y == M - 1)
        {
            cout << dist[N - 1][M - 1] + 1;
            return;
        }
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int xx = x + dx[i];
            int yy = y + dy[i];
            if (xx >= 0 && xx < N && yy >= 0 && yy < M)
            {
                if (graph[xx][yy] == '1' && block == 0)
                {
                    q.push({{xx, yy}, 1});
                    visited[xx][yy][block + 1] = true;
                }
                else if (graph[xx][yy] == '0' && !visited[xx][yy][block])
                {
                    q.push({{xx, yy}, block});
                    visited[xx][yy][block] = true;
                }
                dist[xx][yy] = dist[x][y] + 1;
            }
        }
    }
    cout << -1;
}
int main()
{
    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        cin >> graph[i];
    }
    bfs();
    return 0;
}