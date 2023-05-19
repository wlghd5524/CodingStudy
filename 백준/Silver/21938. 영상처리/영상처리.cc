#include <iostream>
#include <queue>
#include <string.h>
#define MAX 1000
using namespace std;

int picture[MAX][MAX][3];
int graph[MAX][MAX];
bool visited[MAX][MAX];
int n, m, T;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
void dfs(int x, int y)
{
    visited[x][y] = true;
    for (int i = 0; i < 4; i++)
    {
        int xx = x + dx[i];
        int yy = y + dy[i];
        if (xx >= 0 && xx < n && yy >= 0 && yy < m && !visited[xx][yy] && graph[xx][yy] == 1)
        {
            dfs(xx, yy);
        }
    }
}

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            for (int p = 0; p < 3; p++)
            {
                cin >> picture[i][j][p];
            }
        }
    }
    cin >> T;
    memset(visited, false, sizeof(visited));
    int result = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if ((picture[i][j][0] + picture[i][j][1] + picture[i][j][2]) / 3 >= T)
            {
                graph[i][j] = 1;
            }
            else
            {
                graph[i][j] = 0;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (!visited[i][j] && graph[i][j] == 1)
            {
                dfs(i, j);
                result++;
            }
        }
    }
    cout << result;
    return 0;
}