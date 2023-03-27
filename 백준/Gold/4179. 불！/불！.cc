#include <iostream>
#include <queue>
using namespace std;
int N, M;
char graph[1000][1000];
bool visited[1000][1000] = {false};
int timeGraph[1000][1000] = {0};
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
void bfs()
{
    queue<pair<int, int>> jihoon_q;
    queue<pair<int, int>> fire_q;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (graph[i][j] == 'J')
            {
                jihoon_q.push({i, j});
                visited[i][j] = true;
            }
            if (graph[i][j] == 'F')
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
                if (xx >= 0 && xx < N && yy >= 0 && yy < M)
                {
                    if (graph[xx][yy] == '.')
                    {
                        fire_q.push({xx, yy});
                        graph[xx][yy] = 'F';
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
            if (graph[a][b] == 'D')
            {
                
                
            }
            for (int i = 0; i < 4; i++)
            {
                int ax = a + dx[i];
                int bx = b + dy[i];
                if (ax >= 0 && ax < N && bx >= 0 && bx < M)
                {
                    if (!visited[ax][bx] && graph[ax][bx] == '.')
                    {
                        jihoon_q.push({ax, bx});
                        timeGraph[ax][bx] = timeGraph[a][b] + 1;
                        visited[ax][bx] = true;
                    }
                }
                else {
                    cout << timeGraph[a][b]+1;
                    return;
                }
            }
        }
        
    }
    cout << "IMPOSSIBLE";
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