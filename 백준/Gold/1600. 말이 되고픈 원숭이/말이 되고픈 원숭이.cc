#include <iostream>
#include <queue>
#define MAX 200
using namespace std;
int horse_dx[8] = {-1, -1, 1, 1, -2, -2, 2, 2};
int horse_dy[8] = {2, -2, 2, -2, 1, -1, 1, -1};
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int mov[MAX][MAX];
int graph[MAX][MAX];
int k, w, h;
bool visited[31][MAX][MAX];
void bfs()
{
    queue<pair<pair<int, int>, int>> q;
    q.push({{0, 0}, 0});
    visited[0][0][0] = true;
    while (!q.empty())
    {
        int x = q.front().first.first;
        int y = q.front().first.second;
        int horseMove = q.front().second;
        q.pop();
        if (x == h - 1 && y == w - 1)
        {
            cout << mov[x][y];
            return;
        }
        int xx;
        int yy;
        if (horseMove < k)
        {
            for (int i = 0; i < 8; i++)
            {
                xx = x + horse_dx[i];
                yy = y + horse_dy[i];
                if (xx >= 0 && xx < h && yy >= 0 && yy < w)
                {
                    if (!visited[horseMove + 1][xx][yy] && graph[xx][yy] == 0)
                    {
                        q.push({{xx, yy}, horseMove + 1});
                        mov[xx][yy] = mov[x][y] + 1;
                        visited[horseMove + 1][xx][yy] = true;
                    }
                }
            }
        }
        for (int i = 0; i < 4; i++)
        {
            xx = x + dx[i];
            yy = y + dy[i];
            if (xx >= 0 && xx < h && yy >= 0 && yy < w)
            {
                if (!visited[horseMove][xx][yy] && graph[xx][yy] == 0)
                {
                    q.push({{xx, yy}, horseMove});
                    mov[xx][yy] = mov[x][y] + 1;
                    visited[horseMove][xx][yy] = true;
                }
            }
        }
    }
    cout << -1;
    return;
}
int main()
{
    cin >> k >> w >> h;
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            cin >> graph[i][j];
        }
    }
    bfs();
    return 0;
}