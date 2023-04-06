#include <iostream>
#include <queue>
using namespace std;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
string graph[10];
int cow[10][10];
bool visited[10][10];
void bfs(int a, int b)
{
    queue<pair<int, int>> q;
    q.push({a, b});
    visited[a][b] = true;
    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int xx = x + dx[i];
            int yy = y + dy[i];
            if (xx >= 0 && xx < 10 && yy >= 0 && yy < 10)
            {
                if (!visited[xx][yy])
                {
                    if (graph[xx][yy] == '.')
                    {
                        q.push({xx, yy});
                        cow[xx][yy] = cow[x][y] + 1;
                        visited[xx][yy] = true;
                    }
                    if (graph[xx][yy] == 'L')
                    {
                        cout << cow[x][y];
                        return;
                    }
                }
            }
        }
    }
}
int main()
{
    for (int i = 0; i < 10; i++)
    {
        cin >> graph[i];
    }
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (graph[i][j] == 'B')
            {
                bfs(i, j);
            }
        }
    }
}