#include <iostream>
#include <queue>
using namespace std;
int N, M;
char graph[50][50];
bool visited[50][50] = {false};
int timeGraph[50][50] = {0};
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
void bfs()
{
    queue<pair<int, int>> hedgehog_q;
    queue<pair<int, int>> water_q;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (graph[i][j] == 'S')
            {
                hedgehog_q.push({i, j});
                visited[i][j] = true;
            }
            if (graph[i][j] == '*')
            {
                water_q.push({i, j});
                visited[i][j] = true;
            }
        }
    }
    while (!hedgehog_q.empty())
    {
        int water_cnt = water_q.size();
        for (int j = 0; j < water_cnt; j++)
        {
            int x = water_q.front().first;
            int y = water_q.front().second;
            water_q.pop();
            for (int i = 0; i < 4; i++)
            {
                int xx = x + dx[i];
                int yy = y + dy[i];
                if (xx >= 0 && xx < N && yy >= 0 && yy < M)
                {
                    if (graph[xx][yy] == '.')
                    {
                        water_q.push({xx, yy});
                        graph[xx][yy] = '*';
                    }
                }
            }
        }
        int hedgehog_cnt = hedgehog_q.size();
        for (int j = 0; j < hedgehog_cnt; j++)
        {
            int a = hedgehog_q.front().first;
            int b = hedgehog_q.front().second;
            hedgehog_q.pop();
            if (graph[a][b] == 'D')
            {
                cout << timeGraph[a][b];
                return;
            }
            for (int i = 0; i < 4; i++)
            {
                int ax = a + dx[i];
                int bx = b + dy[i];
                if (ax >= 0 && ax < N && bx >= 0 && bx < M)
                {
                    if (!visited[ax][bx] && (graph[ax][bx] == '.' || graph[ax][bx] == 'D'))
                    {
                        hedgehog_q.push({ax, bx});
                        timeGraph[ax][bx] = timeGraph[a][b] + 1;
                        visited[ax][bx] = true;
                    }
                }
            }
        }
    }
    cout << "KAKTUS";
}

int main()
{
    cin >> N >> M;
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