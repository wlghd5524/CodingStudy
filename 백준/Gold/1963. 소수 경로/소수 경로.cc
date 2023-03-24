#include <iostream>
#include <queue>
using namespace std;
bool is_prime(int n)
{
    if (n < 2)
    {
        return false;
    }
    if (n == 2 || n == 3)
    {
        return true;
    }
    if (n % 2 == 0 || n % 3 == 0)
    {
        return false;
    }
    int i = 5;
    int w = 2;
    while (i * i <= n)
    {
        if (n % i == 0)
        {
            return false;
        }
        i += w;
        w = 6 - w;
    }
    return true;
}
void bfs(int a, int b)
{
    queue<pair<int, int>> q;
    bool visited[10000] = {false};
    q.push({a, 0});
    visited[a] = true;
    while (!q.empty())
    {
        string x = to_string(q.front().first);
        int cnt = q.front().second;
        q.pop();
        if (stoi(x) == b)
        {
            cout << cnt << "\n";
            q = queue<pair<int, int>>();
            return;
        }
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j <= 9; j++)
            {
                if (i == 0 && j == 0)
                {
                    continue;
                }
                string tmpX = x;
                tmpX[i] = j + '0';
                int tmpXInt = stoi(tmpX);
                if (is_prime(tmpXInt) && !visited[tmpXInt])
                {
                    q.push({tmpXInt, cnt + 1});
                    visited[tmpXInt] = true;
                }
            }
        }
    }
    cout << "Impossible\n";
    q = queue<pair<int, int>>();
}
int main()
{
    int T;
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        int a, b;
        cin >> a >> b;
        bfs(a, b);
    }
}