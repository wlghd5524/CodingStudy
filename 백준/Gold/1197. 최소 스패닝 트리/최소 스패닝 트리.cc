#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> parent(10001);
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
    parent[y] = x;
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
    int v, e;
    cin >> v >> e;
    parent.resize(v + 1);
    vector<pair<int, pair<int, int>>> graph;
    for (int i = 0; i < e; i++)
    {
        int from, to, cost;
        cin >> from >> to >> cost;
        graph.push_back({cost, {from, to}});
    }
    sort(graph.begin(), graph.end());
    for (int i = 1; i <= v; i++)
    {
        parent[i] = i;
    }
    int result = 0;
    for (int i = 0; i < graph.size(); i++)
    {
        if (!sameParent(graph[i].second.first, graph[i].second.second))
        {
            uni(graph[i].second.first, graph[i].second.second);
            result += graph[i].first;
        }
    }
    cout << result;
    return 0;
}