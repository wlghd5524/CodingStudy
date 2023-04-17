#include <iostream>
#include <queue>
using namespace std;
struct cmp
{
    bool operator()(pair<int, int> a, pair<int, int> b)
    {
        if (a.first == b.first)
        {
            return a.second < b.second;
        }
        return a.first < b.first;
    }
};
int main()
{
    bool visited[10001] = {false};
    int result = 0;
    int n;
    cin >> n;
    priority_queue<pair<int, int>> pq;
    for (int i = 0; i < n; i++)
    {
        int d, p;
        cin >> d >> p;
        pq.push({d, p});
    }
    while (!pq.empty())
    {
        int money = pq.top().first;
        int time = pq.top().second;
        pq.pop();
        for (int i = time; i >= 1; i--)
        {
            if (!visited[i])
            {
                result += money;
                visited[i] = true;
                break;
            }
        }
    }
    cout << result;
    return 0;
}