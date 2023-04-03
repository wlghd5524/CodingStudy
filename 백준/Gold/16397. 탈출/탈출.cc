#include <iostream>
#include <queue>
using namespace std;
int N, T, G;
bool visited[100000];
void bfs()
{
    queue<pair<int, int>> q;
    q.push({N, 0});
    visited[N] = true;
    while (!q.empty())
    {
        int x = q.front().first;
        int time = q.front().second;
        q.pop();
        if (T < time || x > 99999)
        {
            cout << "ANG";
            return;
        }
        if (x == G)
        {
            cout << time;
            return;
        }
        if (!visited[x + 1])
        {
            q.push({x + 1, time + 1});
            visited[x + 1] = true;
        }
        if (x > 0 && x * 2 <= 99999)
        {
            string tmp = to_string(x * 2);
            tmp[0] -= 1;
            if (!visited[stoi(tmp)])
            {
                q.push({stoi(tmp), time + 1});
                visited[stoi(tmp)] = true;
            }
        }
    }
    cout << "ANG";
}
int main()
{
    cin >> N >> T >> G;
    bfs();
    return 0;
}