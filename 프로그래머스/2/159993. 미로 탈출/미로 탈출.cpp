#include <string>
#include <vector>
#include <queue>

using namespace std;

struct Node {
    int x, y;
    bool lever_active;
    int cnt;
};

int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};

int solution(vector<string> maps) {
    int answer = -1;
    queue<Node> q;

    vector<vector<vector<bool>>> is_visited(
        maps.size(),
        vector<vector<bool>>(maps[0].size(), vector<bool>(2, false))
    );

    for (int i = 0; i < maps.size(); i++) {
        for (int j = 0; j < maps[i].size(); j++) {
            if (maps[i][j] == 'S') {
                q.push({i, j, false, 0});
                is_visited[i][j][0] = true;
            }
        }
    }

    while (!q.empty()) {
        int x = q.front().x;
        int y = q.front().y;
        bool lever_active = q.front().lever_active;
        int cnt = q.front().cnt;
        q.pop();

        if (lever_active && maps[x][y] == 'E') {
            answer = cnt;
            break;
        }

        for (int i = 0; i < 4; i++) {
            int xx = x + dx[i];
            int yy = y + dy[i];

            if (xx >= 0 && xx < maps.size() && yy >= 0 && yy < maps[0].size()) {
                if (!lever_active && maps[xx][yy] == 'L' && !is_visited[xx][yy][1]) {
                    q.push({xx, yy, true, cnt + 1});
                    is_visited[xx][yy][1] = true;
                }
                else if (maps[xx][yy] != 'X' && !is_visited[xx][yy][lever_active]) {
                    q.push({xx, yy, lever_active, cnt + 1});
                    is_visited[xx][yy][lever_active] = true;
                }
            }
        }
    }

    return answer;
}
