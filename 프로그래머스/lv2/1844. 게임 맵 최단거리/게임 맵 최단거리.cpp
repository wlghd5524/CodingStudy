#include<vector>
#include <queue>
using namespace std;

int solution(vector<vector<int> > maps)
{
    int dx[4] = {-1,1,0,0};
    int dy[4] = {0,0,-1,1};
    bool visited[100][100];
    int dist[100][100];
    int answer = 0;
    int n = maps.size();
    int m = maps[0].size();
    queue<pair<int,int>> q;
    q.push({0,0});
    while(!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int i = 0;i<4;i++) {
            int xx = x+dx[i];
            int yy = y+dy[i];
            if(xx>=0 && xx<n && yy>=0 && yy<m) {
                if(!visited[xx][yy] && maps[xx][yy] == 1) {
                    q.push({xx,yy});
                    dist[xx][yy] = dist[x][y] + 1;
                    visited[xx][yy] = true;
                }
            }
        }
    }
    if(dist[n-1][m-1] == 0) {
        answer = -1;
    }
    else {
        answer = dist[n-1][m-1]+1;
    }
    return answer;
}