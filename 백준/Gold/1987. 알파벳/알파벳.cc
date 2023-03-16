#include <iostream>
using namespace std;
int r, c;
string graph[20];
int result = 0;

void dfs(int a, int b, int cnt, string bt)
{
    bt[graph[a][b] - 'A'] = '1';
    if (b - 1 >= 0 && bt[graph[a][b - 1] - 'A'] == '0')
    {
        dfs(a, b - 1, cnt + 1, bt);
    }
    if (b + 1 < c && bt[graph[a][b + 1] - 'A'] == '0')
    {
        dfs(a, b + 1, cnt + 1, bt);
    }
    if (a - 1 >= 0 && bt[graph[a - 1][b] - 'A'] == '0')
    {
        dfs(a - 1, b, cnt + 1, bt);
    }
    if (a + 1 < r && bt[graph[a + 1][b] - 'A'] == '0')
    {
        dfs(a + 1, b, cnt + 1, bt);
    }
    else
    {
        result = max(cnt, result);
    }
}

int main()
{
    string bit = "00000000000000000000000000";
    cin >> r >> c;
    for (int i = 0; i < r; i++)
    {
        cin >> graph[i];
    }
    dfs(0, 0, 1, bit);
    cout << result;
    return 0;
}