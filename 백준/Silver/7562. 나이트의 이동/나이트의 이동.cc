#include <iostream>
#include <queue>
#include <string.h>
using namespace std;
int dx[8] = {-1, -1, 1, 1, -2, -2, 2, 2};
int dy[8] = {2, -2, 2, -2, 1, -1, 1, -1};
int graph[300][300] = {0};
int N;
pair<int, int> start, endPoint;
void bfs()
{
    queue<pair<int, int>> q;
    q.push(start);
    while (!q.empty())
    {
        int a = q.front().first;
        int b = q.front().second;
        q.pop();
        if (a == endPoint.first && b == endPoint.second)
        {
            cout << graph[a][b] << "\n";
            q = queue<pair<int, int>>();
            return;
        }
        for (int i = 0; i < 8; i++)
        {
            int aa = a + dy[i];
            int bb = b + dx[i];
            if (aa >= 0 && aa < N && bb >= 0 && bb < N)
            {
                if (graph[aa][bb] == 0)
                {
                    q.push({aa, bb});
                    graph[aa][bb] = graph[a][b] + 1;
                }
            }
        }
    }
}
int main()
{
    int T;
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        cin >> N;
        cin >> start.first >> start.second;
        cin >> endPoint.first >> endPoint.second;
        bfs();
        memset(graph, 0, sizeof(graph));
    }
}