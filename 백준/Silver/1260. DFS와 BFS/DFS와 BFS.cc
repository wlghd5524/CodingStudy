#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
vector<vector<int>> graph;
vector<bool> is_visited;

void dfs(int cur) {
    is_visited[cur] = true;
    cout << cur << " ";
    for (int i = 0; i < graph[cur].size(); i++) {
        int j = graph[cur][i];
        if (is_visited[j] == false) {
            dfs(j);
        }
    }
}
void bfs(int cur) {
    queue<int> q;
    q.push(cur);
    is_visited[cur] = true;
    while (q.empty() == false) {
        int j = q.front();
        q.pop();
        cout << j << ' ';
        for (int i = 0; i < graph[j].size(); i++) {
            int p = graph[j][i];
            if (is_visited[p] == false) {
                q.push(p);
                is_visited[p] = true;
            }
        }
    }
}
int main() {
    int n, m, v;
    cin >> n >> m >> v;
    graph.assign(n + 1, vector<int>(0, 0));
    is_visited.assign(n + 1, false);
    for (int i = 0; i < m; i++) {
        int s, e;
        cin >> s >> e;
        graph[s].emplace_back(e);
        graph[e].emplace_back(s);
    }
    for(int i=1;i<n+1;i++) {
        sort(graph[i].begin(),graph[i].end());
    }
    dfs(v);
    is_visited.assign(n + 1, false);
    cout << "\n";
    bfs(v);

    return 0;
}