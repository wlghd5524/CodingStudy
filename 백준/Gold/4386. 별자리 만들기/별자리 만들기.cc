#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
int parent[101];
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
bool sameparent(int x, int y)
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
    int n;
    cin >> n;
    vector<pair<float, float>> stars(n);
    vector<pair<float, pair<int, int>>> graph;
    for (int i = 0; i < n; i++)
    {
        cin >> stars[i].first >> stars[i].second;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            float cost = sqrt(pow(stars[j].first - stars[i].first, 2) + pow(stars[j].second - stars[i].second, 2));
            graph.push_back({cost, {i, j}});
        }
    }
    sort(graph.begin(), graph.end());
    float result = 0.0;
    for (int i = 1; i <= n; i++)
    {
        parent[i] = i;
    }
    for (int i = 0; i < graph.size(); i++)
    {
        if (!sameparent(graph[i].second.first, graph[i].second.second))
        {
            uni(graph[i].second.first, graph[i].second.second);
            result += graph[i].first;
        }
    }
    cout << result;
    return 0;
}