#include <iostream>
#include <queue>
using namespace std;
int bfs(int v, int k)
{
    bool visited[100001] = {
        false,
    };
    int path[100001] = {
        0,
    };
    queue<int> q;
    visited[v] = true;
    q.push(v);
    while (!q.empty())
    {
        int x = q.front();
        if (x == k)
        {
            break;
        }
        q.pop();
        if (visited[x + 1] == false && x + 1 >= 0 && x + 1 < 100001)
        {
            visited[x + 1] = true;
            q.push(x + 1);
            path[x + 1] = path[x] + 1;
        }
        if (visited[x - 1] == false && x - 1 >= 0 && x - 1 < 100001)
        {
            visited[x - 1] = true;
            q.push(x - 1);
            path[x - 1] = path[x] + 1;
        }
        if (visited[x * 2] == false && x * 2 >= 0 && x * 2 < 100001)
        {
            visited[x * 2] = true;
            q.push(x * 2);
            path[x * 2] = path[x] + 1;
        }
    }
    return path[k];
}
int main()
{
    int N, K;
    cin >> N >> K;
    cout << bfs(N, K);
    return 0;
}