#include <iostream>
using namespace std;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
bool visited[50][50];
string graph[50];
int n, m;
bool cycle = false;
pair<int, int> first_point;
bool first = true;
void dfs(int x, int y, int cnt)
{
    visited[x][y] = true;
    first = false;
    for (int i = 0; i < 4; i++)
    {
        int xx = x + dx[i];
        int yy = y + dy[i];
        if (xx >= 0 && xx < n && yy >= 0 && yy < m)
        {
            if (!visited[xx][yy] && graph[xx][yy] == graph[x][y])
            {
                dfs(xx, yy, cnt + 1);
            }
        }
        if (xx == first_point.first && yy == first_point.second && cnt >= 4)
        {
            cycle = true;
            return;
        }
    }
    visited[x][y] = false;
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
            if (!visited[i][j])
            {
                first_point = {i, j};

                dfs(i, j, 1);
                visited[i][j] = true;
            }
        }
    }
    if (cycle)
    {
        cout << "Yes";
    }
    else
    {
        cout << "No";
    }
    return 0;
}