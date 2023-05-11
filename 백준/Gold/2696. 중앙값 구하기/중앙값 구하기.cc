#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main()
{
    priority_queue<int> minQ;
    priority_queue<int, vector<int>, greater<int>> maxQ;
    int T;
    cin >> T;
    int mid = 0;
    while (T--)
    {
        int cnt = 0;
        minQ = priority_queue<int>();
        maxQ = priority_queue<int, vector<int>, greater<int>>();
        int n;
        cin >> n;
        cout << (n + 1) / 2 << "\n";
        for (int i = 0; i < n; i++)
        {
            int num;
            cin >> num;
            if (i == 0)
            {
                mid = num;
            }
            else
            {
                if (mid > num)
                {
                    minQ.push(num);
                }
                else
                {
                    maxQ.push(num);
                }
            }
            if (i % 2 == 0)
            {
                while (minQ.size() > maxQ.size())
                {
                    maxQ.push(mid);
                    mid = minQ.top();
                    minQ.pop();
                }
                while (minQ.size() < maxQ.size())
                {
                    minQ.push(mid);
                    mid = maxQ.top();
                    maxQ.pop();
                }
                cout << mid << " ";
            }
            if (cnt % 10 == 0 && cnt != 0)
            {
                cout << "\n";
                cnt++;
            }
        }
        cout << "\n";
    }
}