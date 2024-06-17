#include <string>
#include <vector>
#include <map>
#include <queue>

using namespace std;

int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    map<string,int> m;
    for(int i = 0; i<words.size();i++) {
        m[words[i]] = 0;
    }
    queue<pair<string,int>> q;
    q.push({begin,0});
    while(!q.empty()) {
        string cur = q.front().first;
        int dis = q.front().second;
        q.pop();
        if(cur == target) {
            answer = dis;
            break;
        }
        for(int i = 0;i<cur.size();i++) {
            string temp = cur;
            for(int j = 'a';j<'z';j++) {
                temp[i] = j;
                if(m.find(temp) != m.end() && m[temp] == 0) {
                    q.push({temp,dis+1});
                    m[temp] = dis + 1;
                }
            }
        }
        
    }
    return answer;
}