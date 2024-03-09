#include <iostream>
#include <queue>
#include <vector>
using namespace std;
vector<vector<int>> graph;
vector<int> depth;
void bfs(int start, int end) {
	queue<int> q;
	q.push(start);
	depth[start] = 0;
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		if (cur == end) {
			cout <<	depth[cur];
			return;
		}
		for (int i = 0; i < graph[cur].size(); i++) {
			int next = graph[cur][i];
			if (depth[next] == -1) {
				q.push(next);
				depth[next] = depth[cur] + 1;
			}
		}
	}
	cout << -1;
}
int main() {
	int n, start, end;
	cin >> n;
	graph.resize(n + 1);
	depth.resize(n + 1);
	fill(depth.begin(), depth.end(), -1);
	for (int i = 1; i <= n; i++) {
		int tmp;
		cin >> tmp;
		for (int j = i + tmp; j <= n; j += tmp) {
			graph[i].push_back(j);
		}
		for (int j = i - tmp; j >= 1; j -= tmp) {
			graph[i].push_back(j);
		}
	}
	cin >> start >> end;
	bfs(start, end);
	return 0;
}