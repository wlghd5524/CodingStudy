#include <iostream>
#include <stack>
using namespace std;
int main()
{
    int n;
    int h[100002];
    cin >> n;
    stack<int> s;
    for (int i = 1; i <= n; i++)
    {
        cin >> h[i];
    }
    s.push(0);
    int result = 0;
    for (int i = 1; i <= n+1; i++)
    {
        while (!s.empty() && h[s.top()] > h[i])
        {
            int x = s.top();
            s.pop();
            result = max(result, h[x] * (i - s.top() - 1));
        }
        s.push(i);
    }
    cout << result;
    return 0;
}