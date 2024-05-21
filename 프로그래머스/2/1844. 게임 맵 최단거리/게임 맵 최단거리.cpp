#include <vector>
#include <queue>
using namespace std;

int solution(vector<vector<int>> maps)
{
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};
    bool visited[100][100];
    int dist[100][100];
    int answer = 0;
    int n = maps.size();
    int m = maps[0].size();
    queue<pair<int, int>> q;
    q.push({0, 0});
    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int nextX = x + dx[i];
            int nextY = y + dy[i];
            if (nextX >= 0 && nextX < n && nextY >= 0 && nextY < m)
            {
                if (!visited[nextX][nextY] && maps[nextX][nextY] == 1)
                {
                    q.push({nextX, nextY});
                    dist[nextX][nextY] = dist[x][y] + 1;
                    visited[nextX][nextY] = true;
                }
            }
        }
    }
    if (dist[n - 1][m - 1] == 0)
        answer = -1;
    else
        answer = dist[n - 1][m - 1] + 1;
    return answer;
}