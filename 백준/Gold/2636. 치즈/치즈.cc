#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m;
vector<vector<int>> graph;
vector<vector<bool>> isVisited;
int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { 1, -1, 0, 0 };
int result, times;

bool bfs() {
	isVisited[0][0] = true;
	int cnt = 0;
	queue<pair<int, int>> q;
	q.push({ 0,0 });
	times++;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nextX = x + dx[i];
			int nextY = y + dy[i];
			if (nextX >= 0 && nextX < n && nextY >= 0 && nextY < m) {
				if (!isVisited[nextX][nextY]) {
					if (graph[nextX][nextY] == 0) {
						q.push({ nextX,nextY });
					}
					else {
						graph[nextX][nextY] = 0;
						cnt++;
					}
					isVisited[nextX][nextY] = true;
				}
			}
		}
	}
	if (cnt == 0) {
		cout << --times << "\n" << result;
		return true;
	}
	else {
		result = cnt;
		return false;
	}
}

int main() {
	cin >> n >> m;
	graph.assign(n, vector<int>(m, 0));
	isVisited.assign(n, vector<bool>(m, false));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> graph[i][j];
		}
	}
	while (!bfs()) {
		isVisited.assign(n, vector<bool>(m, false));
	}
	return 0;
}