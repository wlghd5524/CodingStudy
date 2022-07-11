#include <iostream>
#include <queue>
using namespace std;
int main()
{
    int n, data;
    cin >> n;
    queue<int> q;
    for (int i = 1; i <= n; i++)
        q.push(i);
    while (q.size()!=1) {
        q.pop();
        data = q.front();
        q.pop();
        q.push(data);
    }
    cout << q.front();
    return 0;
}