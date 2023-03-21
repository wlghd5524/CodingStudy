#include <iostream>
#include <vector>
#include <queue>
#define INF 2000000000
using namespace std;
int main()
{
    int t = 1;
    while (1)
    {
        int n;
        cin >> n;
        if (n == 0)
        {
            break;
        }
        int m[n][n];
        int dist[n][n];
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> m[i][j];
                dist[i][j] = INF;
            }
        }
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        pq.push(make_pair(m[0][0], make_pair(0, 0)));
        while (!pq.empty())
        {
            int cost = pq.top().first;
            int a = pq.top().second.first;
            int b = pq.top().second.second;
            pq.pop();
            if (a + 1 < n)
            {
                int nextCost = cost + m[a + 1][b];
                if (dist[a + 1][b] > nextCost)
                {
                    dist[a + 1][b] = nextCost;
                    pq.push(make_pair(dist[a + 1][b], make_pair(a + 1, b)));
                }
            }
            if (a - 1 >= 0)
            {
                int nextCost = cost + m[a - 1][b];
                if (dist[a - 1][b] > nextCost)
                {
                    dist[a - 1][b] = nextCost;
                    pq.push(make_pair(dist[a - 1][b], make_pair(a - 1, b)));
                }
            }
            if (b + 1 < n)
            {
                int nextCost = cost + m[a][b + 1];
                if (dist[a][b + 1] > nextCost)
                {
                    dist[a][b + 1] = nextCost;
                    pq.push(make_pair(dist[a][b + 1], make_pair(a, b + 1)));
                }
            }
            if (b - 1 >= 0)
            {
                int nextCost = cost + m[a][b - 1];
                if (dist[a][b - 1] > nextCost)
                {
                    dist[a][b - 1] = nextCost;
                    pq.push(make_pair(dist[a][b - 1], make_pair(a, b - 1)));
                }
            }
        }
        cout << "Problem " << t << ": " << dist[n - 1][n - 1] << "\n";
        t++;
    }
}