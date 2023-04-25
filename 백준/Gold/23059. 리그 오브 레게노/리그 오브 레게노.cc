#include <iostream>
#include <unordered_map>
#include <queue>
#include <vector>
#define MAX 400001
using namespace std;
int n;
vector<int> graph[MAX];
int inDegree[MAX];
unordered_map<string, int> str_m;
unordered_map<int, string> int_m;
struct cmp
{
    bool operator()(pair<string, int> a, pair<string, int> b)
    {
        if (a.second == b.second)
        {
            return a > b;
        }
        return a.second > b.second;
    }
};
int main()
{
    cin >> n;

    int index = 1;
    for (int i = 0; i < n; i++)
    {
        string from, to;
        cin >> from >> to;
        if (str_m.find(from) == str_m.end())
        {
            str_m[from] = index;
            int_m[index] = from;
            index++;
        }
        if (str_m.find(to) == str_m.end())
        {
            str_m[to] = index;
            int_m[index] = to;
            index++;
        }
        graph[str_m[from]].push_back(str_m[to]);
        inDegree[str_m[to]]++;
    }
    priority_queue<pair<string, int>, vector<pair<string, int>>, cmp> pq;
    vector<string> result;
    int length = str_m.size();
    for (int i = 1; i <= length; i++)
    {
        if (inDegree[i] == 0)
        {
            pq.push({int_m[i], 0});
        }
    }
    while (!pq.empty())
    {
        int cur = str_m[pq.top().first];
        int cnt = pq.top().second;
        pq.pop();
        result.push_back(int_m[cur]);
        for (int j = 0; j < graph[cur].size(); j++)
        {
            int next = graph[cur][j];
            if (--inDegree[next] == 0)
            {
                pq.push({int_m[next], cnt + 1});
            }
        }
    }
    if (result.size() == length)
    {
        for (int i = 0; i < result.size(); i++)
        {
            cout << result[i] << "\n";
        }
    }
    else
    {
        cout << -1;
    }
    return 0;
}