#include <iostream>
#include <queue>
using namespace std;
int main()
{
    int x;
    cin >> x;
    bool visited[1000001] = {
        false,
    };
    queue<pair<pair<int, int>, vector<int>>> q;
    vector<int> v;
    v.push_back(x);
    q.push({{0, x}, v});
    while (!q.empty())
    {
        int cnt = q.front().first.first;
        int cur = q.front().first.second;
        v = q.front().second;
        q.pop();
        if (cur == 1)
        {
            cout << cnt << "\n";
            for (int i = 0; i < v.size(); i++)
            {
                cout << v[i] << " ";
            }
            break;
        }
        if (cur % 3 == 0 && !visited[cur / 3])
        {
            vector<int> vv = v;
            vv.push_back(cur / 3);
            q.push({{cnt + 1, cur / 3}, vv});
            visited[cur / 3] = true;
        }
        if (cur % 2 == 0 && !visited[cur / 2])
        {
            vector<int> vv = v;
            vv.push_back(cur / 2);
            q.push({{cnt + 1, cur / 2}, vv});
            visited[cur / 2] = true;
        }
        if (!visited[cur - 1])
        {
            vector<int> vv = v;
            vv.push_back(cur - 1);
            q.push({{cnt + 1, cur - 1}, vv});
            visited[cur - 1] = true;
        }
    }
    return 0;
}