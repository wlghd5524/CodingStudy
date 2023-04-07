#include <iostream>
#define MAX 600
using namespace std;
int n, m;
string graph[MAX];
bool visited[MAX][MAX];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int result = 0;
void dfs(int x, int y)
{
    visited[x][y] = true;
    for (int i = 0; i < 4; i++)
    {
        int xx = x + dx[i];
        int yy = y + dy[i];
        if (xx >= 0 && xx < n && yy >= 0 && yy < m)
        {
            if (!visited[xx][yy] && graph[xx][yy] != 'X')
            {
                if (graph[xx][yy] == 'P')
                {
                    result++;
                }
                dfs(xx, yy);
            }
        }
    }
}
int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> graph[i];
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (graph[i][j] == 'I')
            {
                dfs(i, j);
            }
        }
    }
    if(result == 0) {
        cout << "TT";
    }
    else {
        cout << result;
    }
    return 0;
}