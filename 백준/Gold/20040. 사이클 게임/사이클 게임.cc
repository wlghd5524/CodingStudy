#include <iostream>
using namespace std;
int parent[500001];
int find(int x)
{
    while (x != parent[x])
    {
        x = parent[x];
    }
    return x;
}
bool uni(int x, int y)
{
    x = find(x);
    y = find(y);
    if (x == y)
    {
        return true;
    }
    else
    {
        if (x > y)
        {
            parent[x] = y;
        }
        else
        {
            parent[y] = x;
        }
        return false;
    }
}
int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m;
    int result = 0;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        parent[i] = i;
    }
    for (int i = 1; i <= m; i++)
    {
        int a, b;
        cin >> a >> b;
        if (uni(a, b))
        {
            result = i;
            break;
        }
    }
    cout << result;
    return 0;
}