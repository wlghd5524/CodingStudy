#include <iostream>
#include <vector>
#include <map>
#include <string.h>
using namespace std;
int n,m;
string start,arrive;
bool visited[100001];
map<int,string> mp_int;
map<string,int> mp_str;
vector<vector<int>> graph;
void dfs(int x, string path) {
    if(mp_int[x] == arrive) {
        cout << path << "\n";
        return;
    }
    visited[x] = true;
    for(int i = 0;i<graph[x].size();i++) {
        if(!visited[graph[x][i]]) {
            dfs(graph[x][i],path+mp_int[graph[x][i]][0]);
        }
    }
}
int main() {
    cin >> n >> m;
    int cities = 0;
    graph.resize(n+1);
    for(int i = 0;i<n;i++) {
        string from,to;
        cin >> from >> to;
        if(mp_str.find(from)==mp_str.end()) {
            mp_str[from] = cities;
            mp_int[cities] = from;
            visited[cities] = false;
            cities++;
        }
        if(mp_str.find(to)==mp_str.end()) {
            mp_str[to] = cities;
            mp_int[cities] = to;
            visited[cities] = false;
            cities++;
        }
        graph[mp_str[from]].push_back(mp_str[to]);
        graph[mp_str[to]].push_back(mp_str[from]);
    }
    for(int i = 0;i<m;i++) {
        cin >> start >> arrive;
        string tmp(1,start[0]);
        dfs(mp_str[start],tmp);
        memset(visited,false,cities);
    }
    return 0;
}