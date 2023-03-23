#include <iostream>
#include <queue>
#include <set>
using namespace std;
long long int s, t;
string bfs()
{
    set<long long int> S;
    queue<pair<long long int, string>> q;
    q.push({s, ""});
    S.insert(s);
    while (!q.empty())
    {
        long long int x = q.front().first;
        string path = q.front().second;
        if (path.size() >= 50)
        {
            break;
        }
        q.pop();
        if (x == t)
        {
            return path;
        }
        if (S.find(x * x) == S.end())
        {
            S.insert(x * x);
            q.push({x * x, path + "*"});
        }
        if (S.find(x + x) == S.end())
        {
            S.insert(x + x);
            q.push({x + x, path + "+"});
        }
        if (S.find(x - x) == S.end())
        {
            S.insert(x - x);
            q.push({x - x, path + "-"});
        }
        if (S.find(x / x) == S.end() && x != 0)
        {
            S.insert(x / x);
            q.push({x / x, path + "/"});
        }
    }
    return "-1";
}
int main()
{
    cin >> s >> t;
    if (s == t)
    {
        cout << 0;
        return 0;
    }
    cout << bfs();
}