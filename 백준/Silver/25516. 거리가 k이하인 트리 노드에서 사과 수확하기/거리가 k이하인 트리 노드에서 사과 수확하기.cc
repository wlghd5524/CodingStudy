#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, k;
vector<vector<int>> tree;
vector<bool> isVisited;
vector<int> apple;
int result;
void dfs(int cur, int depth)
{
    isVisited[cur] = true;
    for (int i = 0; i < tree[cur].size(); i++)
    {
        if (!isVisited[tree[cur][i]])
        {
            dfs(tree[cur][i], depth + 1);
        }
    }
    if (depth <= k && apple[cur] == 1)
    {
        result++;
    }
}
int main()
{
    cin >> n >> k;
    tree.resize(n);
    isVisited.resize(n);
    apple.resize(n);
    for (int i = 0; i < n - 1; i++)
    {
        int from, to;
        cin >> from >> to;
        tree[from].push_back(to);
    }
    for (int i = 0; i < n; i++)
    {
        cin >> apple[i];
    }
    dfs(0, 0);
    cout << result;
    return 0;
}