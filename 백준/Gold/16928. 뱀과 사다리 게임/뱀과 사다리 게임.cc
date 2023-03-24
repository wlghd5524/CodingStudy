#include <iostream>
#include <queue>
#include <vector>
#include <map>
using namespace std;

int N, M;
vector<pair<int, int>> ladders;
vector<pair<int, int>> snakes;
map<int,int> m;
void bfs() {
    bool visited[101] = {false};
    int num_cnt[101] = {0};
    queue<int> q;
    q.push(1);
    visited[1] = true;
    while(!q.empty()) {
        int x = q.front();
        q.pop();
        if(x == 100) {
            break;
        }
        for(int i = 1;i<=6;i++) {
            if(m.find(x+i)!=m.end()) {
                if(!visited[m[x+i]]) {
                    q.push(m[x+i]);
                    num_cnt[m[x+i]] = num_cnt[x]+1;
                    num_cnt[x+i] = num_cnt[x] + 1;
                    visited[m[x+i]] = true;
                    visited[x+i] = true;
                }
            }
            else if(1<=x+i && x+i<=100 && !visited[x+i]) {
                q.push(x+i);
                num_cnt[x+i] = num_cnt[x]+1;
                visited[x+i] = true;
            }
        }
    }
    cout << num_cnt[100];
}
int main()
{
    cin >> N >> M;
    ladders.reserve(N);
    snakes.reserve(M);
    for (int i = 0; i < N+M; i++)
    {
        int x, y;
        cin >> x >> y;
        m[x] = y;
    }
    bfs();
    return 0;
}