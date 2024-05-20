#include <string>
#include <vector>

using namespace std;

vector<vector<int>> graph;
bool isVisited[200] = {false};

void dfs(int cur) {
    isVisited[cur] = true;
    for(int i = 0;i<graph[cur].size();i++) {
        int next = graph[cur][i];
        if(!isVisited[next]) {
            dfs(next);
        }
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    graph.resize(n);
    for(int i = 0;i<computers.size();i++) {
        for(int j = 0;j<computers[i].size();j++) {
            if(computers[i][j] == 1) {
                graph[i].push_back(j);
            }
        }
    }
    for(int i = 0;i<n;i++) {
        if(!isVisited[i]) {
            dfs(i);
            answer++;
        }
    }
    return answer;
}