#include <iostream>
#include <queue>
using namespace std;
int A, B;
bool visited[10000] = {false};
int shift_left(int num)
{
    int first = num / 1000;
    num = (num % 1000) * 10 + first;
    return num;
}
int shift_right(int num)
{
    int last = num % 10;
    num = last * 1000 + num / 10;
    return num;
}
void bfs()
{
    queue<pair<int, string>> q;
    q = queue<pair<int, string>>();
    q.push({A, ""});
    visited[A] = true;
    while (!q.empty())
    {
        int x = q.front().first;
        string path = q.front().second;
        q.pop();
        if (x == B)
        {
            cout << path << "\n";
            return;
        }
        if (x * 2 > 9999 && !visited[x * 2 % 10000])
        {
            q.push({x * 2 % 10000, path + "D"});
            visited[x * 2 % 10000] = true;
        }
        else if (x * 2 < 10000 && !visited[x * 2])
        {
            q.push({x * 2, path + "D"});
            visited[x * 2] = true;
        }
        if (x == 0 && !visited[9999])
        {
            q.push({9999, path + "S"});
            visited[9999] = true;
        }
        else if (x != 0 && !visited[x - 1])
        {
            q.push({x - 1, path + "S"});
            visited[x - 1] = true;
        }
        int tmp = shift_left(x);
        if (!visited[tmp])
        {
            q.push({tmp, path + "L"});
            visited[tmp] = true;
        }
        tmp = shift_right(x);
        if (!visited[tmp])
        {
            q.push({tmp, path + "R"});
            visited[tmp] = true;
        }
    }
}
int main()
{
    int T;
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        cin >> A >> B;
        bfs();
        fill(visited, visited + 10000, false);
    }
    return 0;
}