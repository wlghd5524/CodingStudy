#include <iostream>
#include <set>
using namespace std;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int graph[5][5];
set<int> s;
void dfs(int x, int y, int cnt, string path)
{
    if (cnt == 5)
    {
        s.insert(stoi(path));
        return;
    }
    for (int i = 0; i < 4; i++)
    {
        int xx = x + dx[i];
        int yy = y + dy[i];
        if (xx >= 0 && xx < 5 && yy >= 0 && yy < 5)
        {
            dfs(xx, yy, cnt + 1, path + to_string(graph[xx][yy]));
        }
    }
}
int main()
{
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            cin >> graph[i][j];
        }
    }
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            dfs(i, j, 0, to_string(graph[i][j]));
        }
    }
    cout << s.size();
}