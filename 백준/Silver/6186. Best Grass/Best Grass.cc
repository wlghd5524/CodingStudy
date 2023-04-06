#include <iostream>
using namespace std;
int r, c;
string graph[100];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
void dfs(int x, int y)
{
    graph[x][y] = '.';
    for (int i = 0; i < 4; i++)
    {
        int xx = x + dx[i];
        int yy = y + dy[i];
        if (xx >= 0 && xx < r && yy >= 0 && yy < c)
        {
            if (graph[xx][yy] == '#')
            {
                dfs(xx, yy);
            }
        }
    }
}
int main()
{
    cin >> r >> c;
    for (int i = 0; i < r; i++)
    {
        cin >> graph[i];
    }
    int cnt = 0;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (graph[i][j] == '#')
            {
                dfs(i, j);
                cnt++;
            }
        }
    }
    cout << cnt;
    return 0;
}