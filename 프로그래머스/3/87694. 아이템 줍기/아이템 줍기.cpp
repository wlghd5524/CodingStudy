#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int solution(vector<vector<int>> rectangle, int characterX, int characterY, int itemX, int itemY)
{
    vector<vector<int>> graph(102, vector<int>(102, 0));
    queue<pair<int, int>> q;

    int dx[4] = { 1, -1, 0, 0 };
    int dy[4] = { 0, 0, 1, -1 };

    // 사각형 내부와 테두리 구분
    for (int i = 0; i < rectangle.size(); i++)
    {
        int x1 = rectangle[i][0] * 2;
        int y1 = rectangle[i][1] * 2;
        int x2 = rectangle[i][2] * 2;
        int y2 = rectangle[i][3] * 2;
        for (int j = x1; j <= x2; j++) {
            for (int k = y1; k <= y2; k++) {
                if ((j == x1 || j == x2 || k == y1 || k == y2) && graph[j][k] != 2) {
                    graph[j][k] = 1;  // 테두리
                }
                else {
                    graph[j][k] = 2;  // 도형 안쪽
                }
            }
        }
    }

    // BFS 시작
    characterX *= 2;
    characterY *= 2;
    itemX *= 2;
    itemY *= 2;

    q.push({ characterX, characterY });
    graph[characterX][characterY] = 0; // 방문 표시 및 거리 초기화

    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nextX = x + dx[i];
            int nextY = y + dy[i];

            if (nextX >= 0 && nextX <= 101 && nextY >= 0 && nextY <= 101)
            {
                if (graph[nextX][nextY] == 1) // 테두리만 이동 가능
                {
                    q.push({ nextX, nextY });
                    graph[nextX][nextY] = graph[x][y] + 1;
                }
            }
        }
    }

    return graph[itemX][itemY] / 2; // 원래 거리로 환산
}