#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int parent[100001];
int n;
int find(int x)
{
    if (parent[x] == x)
    {
        return x;
    }
    return parent[x] = find(parent[x]);
}
void uni(int x, int y)
{
    x = find(x);
    y = find(y);
    if (x == y)
    {
        return;
    }
    parent[y] = x;
    n--;
}
bool sameParent(int x, int y)
{
    x = find(x);
    y = find(y);
    if (x == y)
    {
        return true;
    }
    return false;
}
int main()
{
    int m;
    cin >> n >> m;
    vector<pair<int, pair<int, int>>> v;
    vector<int> result;
    int answer = 0;
    for (int i = 0; i < m; i++)
    {
        int from, to, cost;
        cin >> from >> to >> cost;
        v.push_back({cost, {from, to}});
    }
    sort(v.begin(), v.end());
    for (int i = 1; i <= n; i++)
    {
        parent[i] = i;
    }
    for (int i = 0; i < v.size(); i++)
    {
        if (!sameParent(v[i].second.first, v[i].second.second))
        {
            uni(v[i].second.first, v[i].second.second);
            result.push_back(v[i].first);
        }
    }
    for (int i = 0; i < result.size() - 1; i++)
    {
        answer += result[i];
    }
    cout << answer;
    return 0;
}