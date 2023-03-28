#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N, K, S, X, Y;
int da[4] = {-1, 1, 0, 0};
int db[4] = {0, 0, -1, 1};
int graph[200][200];
struct Virus
{
    int virus;
    int x;
    int y;
};
vector<Virus> vec;
bool cmp(Virus a, Virus b)
{
    return a.virus < b.virus;
}
void bfs()
{
    sort(vec.begin(), vec.end(), cmp);
    int sec = 0;
    while (S > sec)
    {
        int virus_cnt = vec.size();
        for (int j = 0; j < virus_cnt; j++)
        {
            Virus v = vec[j];
            for (int p = 0; p < 4; p++)
            {
                int aa = v.x + da[p];
                int bb = v.y + db[p];
                if (aa >= 0 && aa < N && bb >= 0 && bb < N)
                {
                    if (graph[aa][bb] == 0)
                    {
                        graph[aa][bb] = v.virus;
                        vec.push_back({graph[aa][bb], aa, bb});
                    }
                }
            }
        }
        if(graph[X-1][Y-1]!=0) {
            break;
        }
        sec++;
    }
    cout << graph[X - 1][Y - 1];
}
int main()
{
    cin >> N >> K;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> graph[i][j];
            if(graph[i][j]!=0) {
                vec.push_back({graph[i][j], i, j});
            }
            
        }
    }
    cin >> S >> X >> Y;
    bfs();
}