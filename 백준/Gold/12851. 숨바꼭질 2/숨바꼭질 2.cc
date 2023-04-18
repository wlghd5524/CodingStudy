#include <iostream>
#include <queue>
#include <map>
using namespace std;
int n, k;
bool visited[200001];
int MIN = 200000000;
void bfs()
{
    queue<pair<int, int>> q;
    q.push({n, 0});
    visited[n] = true;
    int result = 0;
    map<int, int> m;
    while (!q.empty())
    {
        int x = q.front().first;
        int cnt = q.front().second;
        q.pop();
        visited[x] = true;
        if (x == k)
        {
            m[cnt]++;
        }
        if (x + 1 <= k)
        {
            if (!visited[x + 1])
            {
                q.push({x + 1, cnt + 1});
            }
        }
        if (x - 1 >= 0)
        {
            if (!visited[x - 1])
            {
                q.push({x - 1, cnt + 1});
            }
        }
        if (x < k)
        {
            if (!visited[x * 2])
            {
                q.push({x * 2, cnt + 1});
            }
        }
    }
    cout << m.begin()->first << "\n"
         << m.begin()->second;
}
int main()
{
    cin >> n >> k;
    bfs();
}