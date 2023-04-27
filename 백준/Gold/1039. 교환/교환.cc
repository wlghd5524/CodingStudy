#include <iostream>
#include <queue>
#include <set>
using namespace std;
string num;
int k;
int result = 0;

void bfs()
{
    set<pair<string, int>> s;
    queue<pair<string, int>> q;
    q.push({num, 0});
    while (!q.empty())
    {
        string cur = q.front().first;
        int cnt = q.front().second;
        q.pop();
        int length = cur.size();
        for (int i = 0; i < length; i++)
        {
            for (int j = i + 1; j < length; j++)
            {
                string next = cur;
                char tmp = next[i];
                next[i] = next[j];
                next[j] = tmp;
                if (next[0] != '0' && s.find({next, cnt + 1}) == s.end())
                {
                    if (cnt + 1 == k)
                    {
                        result = max(result, stoi(next));
                        continue;
                    }
                    s.insert({next, cnt + 1});
                    q.push({next, cnt + 1});
                }
            }
        }
    }
    if (result == 0)
    {
        cout << -1;
    }
    else
    {
        cout << result;
    }
}
int main()
{
    cin >> num >> k;
    bfs();
    return 0;
}