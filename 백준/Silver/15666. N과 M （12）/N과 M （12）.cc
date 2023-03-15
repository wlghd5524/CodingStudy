#include <iostream>
#include <algorithm>
using namespace std;
int n, m;
int arr[9];
int result[9];
void dfs(int v, int cnt)
{
    if (cnt == m)
    {
        for (int i = 0; i < m; i++)
        {
            cout << result[i] << " ";
        }
        cout << "\n";
        return;
    }
    int tmp = 0;
    for (int i = v; i < n; i++)
    {
        if (tmp != arr[i])
        {
            tmp = arr[i];
            result[cnt] = arr[i];
            dfs(i, cnt + 1);
        }
    }
    return;
}
int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    sort(arr, arr + n);
    dfs(0, 0);
    return 0;
}