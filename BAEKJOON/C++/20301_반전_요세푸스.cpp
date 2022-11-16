#include <iostream>
#include <deque>
#include <vector>
using namespace std;
int main()
{
    int n, k, m;
    cin >> n >> k >> m;
    deque<int> dq;
    vector<int> result;
    for (int i = 1; i <= n; i++)
    {
        dq.push_back(i);
    }
    int cnt = 0;
    int direction = 1;
    while (!dq.empty())
    {
        if (cnt % m == 0 && cnt != 0)
        {
            direction = -direction;
        }
        if (direction == 1)
        {
            for (int i = 0; i < k - 1; i++)
            {
                dq.push_back(dq.front());
                dq.pop_front();
            }
            result.emplace_back(dq.front());
            dq.pop_front();
        }
        else
        {
            for (int i = 0; i < k - 1; i++)
            {
                dq.push_front(dq.back());
                dq.pop_back();
            }
            result.emplace_back(dq.back());
            dq.pop_back();
        }
        cnt++;
    }
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << "\n";
    }
    return 0;
}