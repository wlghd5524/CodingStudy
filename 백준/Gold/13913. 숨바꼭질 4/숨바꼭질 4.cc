#include <iostream>
#include <queue>
#include <vector>
using namespace std;
#define MAX 100001
int N, K;
int graph[MAX];
bool visited[MAX];
void bfs()
{
    queue<pair<int, vector<int>>> q;
    q.push({N, {N}});
    visited[N] = true;
    graph[N] = 0;
    while (!q.empty())
    {
        int x = q.front().first;
        vector<int> path = q.front().second;
        q.pop();
        if (x == K)
        {
            cout << graph[x] << "\n";
            for (int i = 0; i < path.size(); i++)
            {
                cout << path[i] << " ";
            }
            return;
        }
        if (x - 1 >= 0 && !visited[x - 1])
        {
            vector<int> tmp_path = path;
            tmp_path.push_back(x - 1);
            q.push({x - 1, tmp_path});
            graph[x - 1] = graph[x] + 1;
            visited[x - 1] = true;
        }
        if (x + 1 < MAX && !visited[x + 1])
        {
            vector<int> tmp_path = path;
            tmp_path.push_back(x + 1);
            q.push({x + 1, tmp_path});
            graph[x + 1] = graph[x] + 1;
            visited[x + 1] = true;
        }
        if (x * 2 < MAX && !visited[x * 2])
        {
            vector<int> tmp_path = path;
            tmp_path.push_back(x * 2);
            q.push({x * 2, tmp_path});
            graph[x * 2] = graph[x] + 1;
            visited[x * 2] = true;
        }
    }
}
int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> K;
    if (N <= K)
    {
        bfs();
    }
    else
    {
        cout << N - K << "\n";
        for (int i = N; i >= K; i--)
        {
            cout << i << " ";
        }
    }
    return 0;
}