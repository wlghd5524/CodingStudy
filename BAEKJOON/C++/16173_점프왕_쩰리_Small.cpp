#include <iostream>
#include <queue>
#include <vector>
using namespace std;

string bfs(int n, vector<vector<int>> graph) {
    queue<pair<int,int>> q;
    q.push({0,0});
    while (!q.empty()) {
        auto j = q.front();
        q.pop();
        int x = j.first;
        int y = j.second;
        int cur = graph[x][y];
        if(cur == -1) {
            return "HaruHaru";
        }
        if(cur == 0) {
            continue;
        }
        if(x+cur < n) {
            q.push({x+cur, y});
        }
        if(y+cur < n) {
            q.push({x,y+cur});
        }
    }
    return "Hing";
}

int main() {
    int n;
    cin >> n;
    vector<vector<int>> graph(n);
    for(int j = 0;j<n;j++) {
        for(int i = 0;i<n;i++) {
            int tmp;
            cin >> tmp;
            graph[j].push_back(tmp);
        }
    }
    cout << bfs(n,graph);
}