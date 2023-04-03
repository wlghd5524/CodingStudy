#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int MAX = 100001;
vector<int> graph[MAX];
bool visited[MAX] = {false};
int order[MAX];
vector<int> result;
vector<int> question;
int cnt = 0;
bool cmp(int a, int b)
{
    return order[a] < order[b];
}
void dfs(int v)
{
    visited[v] = true;
    result.push_back(v);
    for (int i = 0; i < graph[v].size(); i++)
    {
        if (!visited[graph[v][i]])
        {
            dfs(graph[v][i]);
        }
    }
}
int main()
{
    int N;
    cin >> N;
    for (int i = 0; i < N - 1; i++)
    {
        int from, to;
        cin >> from >> to;
        graph[from].push_back(to);
        graph[to].push_back(from);
    }
    for (int i = 0; i < N; i++)
    {
        int tmp;
        cin >> tmp;
        question.push_back(tmp);
        order[tmp] = i;
    }
    for (int i = 1; i <= N; i++)
    {
        sort(graph[i].begin(), graph[i].end(), cmp);
    }
    dfs(1);
    if (result == question)
    {
        cout << 1;
    }
    else
    {
        cout << 0;
    }
    return 0;
}