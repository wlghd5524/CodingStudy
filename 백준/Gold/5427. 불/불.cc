#include <iostream>
#include <queue>
#include <string.h>
using namespace std;
int R, C;
const int MAX = 1000;
char graph[MAX][MAX];
bool visited[MAX][MAX] = {false};
int timeGraph[MAX][MAX] = {0};
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
void bfs()
{
    queue<pair<int, int>> jihoon_q;
    queue<pair<int, int>> fire_q;
    jihoon_q = queue<pair<int,int>>();
    fire_q = queue<pair<int,int>>();
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            if (graph[i][j] == '@')
            {
                jihoon_q.push({i, j});
                visited[i][j] = true;
            }
            if (graph[i][j] == '*')
            {
                fire_q.push({i, j});
                visited[i][j] = true;
            }
        }
    }
    while (!jihoon_q.empty())
    {
        int fire_cnt = fire_q.size();
        for (int j = 0; j < fire_cnt; j++)
        {
            int x = fire_q.front().first;
            int y = fire_q.front().second;
            fire_q.pop();
            for (int i = 0; i < 4; i++)
            {
                int xx = x + dx[i];
                int yy = y + dy[i];
                if (xx >= 0 && xx < R && yy >= 0 && yy < C)
                {
                    if (graph[xx][yy] == '.')
                    {
                        fire_q.push({xx, yy});
                        graph[xx][yy] = '*';
                    }
                }
            }
        }
        int jihoon_cnt = jihoon_q.size();
        for (int j = 0; j < jihoon_cnt; j++)
        {
            int a = jihoon_q.front().first;
            int b = jihoon_q.front().second;
            jihoon_q.pop();
            for (int i = 0; i < 4; i++)
            {
                int ax = a + dx[i];
                int bx = b + dy[i];
                if (ax >= 0 && ax < R && bx >= 0 && bx < C)
                {
                    if (!visited[ax][bx] && graph[ax][bx] == '.')
                    {
                        jihoon_q.push({ax, bx});
                        timeGraph[ax][bx] = timeGraph[a][b] + 1;
                        visited[ax][bx] = true;
                    }
                }
                else
                {
                    std::cout << timeGraph[a][b] + 1 << "\n";
                    return;
                }
            }
        }
    }
    std::cout << "IMPOSSIBLE\n";
}

int main()
{
    int T;
    cin >> T;
    for (int t = 0; t < T; t++)
    {
        cin >> C >> R;
        for (int i = 0; i < R; i++)
        {
            for (int j = 0; j < C; j++)
            {
                cin >> graph[i][j];
            }
        }
        bfs();
        memset(graph,'.',sizeof(graph));
        memset(visited,false,sizeof(visited));
        memset(timeGraph,0,sizeof(timeGraph));
    }

    return 0;
}