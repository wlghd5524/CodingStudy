#include <iostream>
#include <queue>
using namespace std;
string graph[31][31];
int minute[31][31][31] = {0};
int L, R, C;
int bfs()
{
    queue<pair<int, pair<int, int>>> q;
    for (int i = 0; i < L; i++)
    {
        for (int j = 0; j < R; j++)
        {
            for (int p = 0; p < C; p++)
            {
                if (graph[i][j][p] == 'S')
                {
                    q.push({i, {j, p}});
                }
            }
        }
    }
    while (!q.empty())
    {
        int x, y, z;
        x = q.front().first;
        y = q.front().second.first;
        z = q.front().second.second;
        q.pop();
        if (graph[x][y][z] == 'E')
        {
            while (!q.empty())
            {
                q.pop();
            }
            return minute[x][y][z];
        }
        if (x + 1 < L && graph[x + 1][y][z] != '#' && minute[x + 1][y][z] == 0)
        {
            q.push({x + 1, {y, z}});
            minute[x + 1][y][z] = minute[x][y][z] + 1;
        }
        if (x - 1 >= 0 && graph[x - 1][y][z] != '#' && minute[x - 1][y][z] == 0)
        {
            q.push({x - 1, {y, z}});
            minute[x - 1][y][z] = minute[x][y][z] + 1;
        }
        if (y + 1 < R && graph[x][y + 1][z] != '#' && minute[x][y + 1][z] == 0)
        {
            q.push({x, {y + 1, z}});
            minute[x][y + 1][z] = minute[x][y][z] + 1;
        }
        if (y - 1 >= 0 && graph[x][y - 1][z] != '#' && minute[x][y - 1][z] == 0)
        {
            q.push({x, {y - 1, z}});
            minute[x][y - 1][z] = minute[x][y][z] + 1;
        }
        if (z + 1 < C && graph[x][y][z + 1] != '#' && minute[x][y][z + 1] == 0)
        {
            q.push({x, {y, z + 1}});
            minute[x][y][z + 1] = minute[x][y][z] + 1;
        }
        if (z - 1 >= 0 && graph[x][y][z - 1] != '#' && minute[x][y][z - 1] == 0)
        {
            q.push({x, {y, z - 1}});
            minute[x][y][z - 1] = minute[x][y][z] + 1;
        }
    }
    while (!q.empty())
    {
        q.pop();
    }
    return -1;
}
int main()
{
    while (1)
    {
        fill(&graph[0][0], &graph[30][31], "");
        fill(&minute[0][0][0], &minute[30][30][31], 0);
        cin >> L >> R >> C;
        if (L == 0 && R == 0 && C == 0)
        {
            break;
        }
        for (int i = 0; i < L; i++)
        {
            for (int j = 0; j < R; j++)
            {
                cin >> graph[i][j];
            }
        }
        int result = bfs();
        if (result == -1)
        {
            cout << "Trapped!\n";
        }
        else
        {
            cout << "Escaped in " << result << " minute(s).\n";
        }
    }
}