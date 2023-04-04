#include <iostream>
#include <queue>
using namespace std;
int F, S, G, U, D;
bool visited[1000001];
int cnt[1000001];
void bfs()
{
    queue<int> q;
    q.push(S);
    visited[S] = true;
    while (!q.empty())
    {
        int x = q.front();
        q.pop();
        if (x == G)
        {
            cout << cnt[x];
            return;
        }
        if (x + U <= F && !visited[x + U])
        {
            q.push(x + U);
            visited[x + U] = true;
            cnt[x + U] = cnt[x] + 1;
        }
        if (x - D >= 1 && !visited[x - D])
        {
            q.push(x - D);
            visited[x - D] = true;
            cnt[x - D] = cnt[x] + 1;
        }
    }
    cout << "use the stairs";
}
int main()
{
    cin >> F >> S >> G >> U >> D;
    bfs();
    return 0;
}