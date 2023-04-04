#include <iostream>
#include <queue>
#define MAX 100000
using namespace std;
int A, B, N, M;
bool visited[MAX + 1];
void bfs()
{
    queue<pair<int, int>> q;
    q.push({N, 0});
    visited[N] = true;
    while (!q.empty())
    {
        int x = q.front().first;
        int cnt = q.front().second;
        q.pop();
        if (x == M)
        {
            cout << cnt;
            return;
        }
        if (x + 1 <= MAX && !visited[x + 1])
        {
            q.push({x + 1, cnt + 1});
            visited[x + 1] = true;
        }
        if (x - 1 >= 0 && !visited[x - 1])
        {
            q.push({x - 1, cnt + 1});
            visited[x - 1] = true;
        }
        if (x + A <= MAX && !visited[x + A])
        {
            q.push({x + A, cnt + 1});
            visited[x + A] = true;
        }
        if (x - A >= 0 && !visited[x - A])
        {
            q.push({x - A, cnt + 1});
            visited[x - A] = true;
        }
        if (x + B <= MAX && !visited[x + B])
        {
            q.push({x + B, cnt + 1});
            visited[x + B] = true;
        }
        if (x - B >= 0 && !visited[x - B])
        {
            q.push({x - B, cnt + 1});
            visited[x - B] = true;
        }
        if (x * A <= MAX && !visited[x * A])
        {
            q.push({x * A, cnt + 1});
            visited[x * A] = true;
        }
        if (x * B <= MAX && !visited[x * B])
        {
            q.push({x * B, cnt + 1});
            visited[x * B] = true;
        }
    }
}
int main()
{
    cin >> A >> B >> N >> M;
    bfs();
    return 0;
}