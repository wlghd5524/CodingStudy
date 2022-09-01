#include <iostream>
#include <vector>
using namespace std;
vector<vector<int>> v;
vector<bool> is_visited;
int cnt = 0;
void dfs(int cur) {
    is_visited[cur] = true;
    cnt++;
    for (int i = 0; i < v[cur].size(); i++) {
        int nxt = v[cur][i];
        if (is_visited[nxt] == false) {
            dfs(nxt);
        }
    }
}
int main() {
    int n, m;
    cin >> n;
    v.assign(n + 1, vector<int>(0, 0));
    is_visited.assign(n + 1, false);
    cin >> m;
    int graph[n + 1][m + 1];
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        v[a].emplace_back(b);
        v[b].emplace_back(a);
    }
    dfs(1);
    cout << cnt - 1;
}