#include <iostream>
#include <queue>
#include <math.h>
using namespace std;
int T, A, B;
bool visited[2][5000001];
void bfs()
{
    queue<pair<int, bool>> q;
    q.push({0, false});
    visited[0][0] = true;
    int MAX = 0;
    while (!q.empty())
    {
        int cur = q.front().first;
        bool water = q.front().second;
        q.pop();
        MAX = max(cur, MAX);
        if (cur == T)
        {
            break;
        }
        if (!visited[water][cur + A] && cur + A <= T)
        {
            q.push({cur + A, water});
            visited[water][cur + A] = true;
        }
        if (!visited[water][cur + B] && cur + B <= T)
        {
            q.push({cur + B, water});
            visited[water][cur + B] = true;
        }
        double tmp = cur;
        tmp = floor(tmp / 2);
        if (!visited[water][(int)tmp] && !water && tmp + A <= T)
        {
            q.push({(int)tmp + A, true});
            visited[water][(int)tmp + A] = true;
        }
        if (!visited[water][(int)tmp] && !water && tmp + B <= T)
        {
            q.push({(int)tmp + B, true});
            visited[water][(int)tmp + B] = true;
        }
    }
    std::cout << MAX;
    return;
}
int main()
{
    cin >> T >> A >> B;
    bfs();
}