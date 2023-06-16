#include <iostream>
#include <vector>
#include <string.h>
#define MAX 100001
using namespace std;
int arr[MAX];
bool visited[MAX];
bool team[MAX];
int cnt;
void dfs(int node)
{
    visited[node] = true;
    int next = arr[node];
    if (!visited[next])
    {
        dfs(next);
    }
    else if (!team[next])
    {
        for (int i = next; i != node; i = arr[i])
        {
            cnt++;
        }
        cnt++;
    }
    team[node] = true;
}
int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T;
    cin >> T;
    while (T--)
    {
        memset(arr, 0, sizeof(arr));
        memset(visited, false, sizeof(visited));
        memset(team, false, sizeof(team));
        int n;
        cin >> n;
        cnt = 0;
        for (int i = 1; i <= n; i++)
        {
            cin >> arr[i];
        }
        for (int i = 1; i <= n; i++)
        {
            if (!visited[i])
            {
                dfs(i);
            }
        }
        cout << n - cnt << "\n";
    }
    return 0;
}