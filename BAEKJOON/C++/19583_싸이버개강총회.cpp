#include <iostream>
#include <map>
#include <vector>
using namespace std;
int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string s,e,q;
    int start_time,end_time,streaming_end_time;
    string time, name;
    map<string,int> m;
    cin >> s >> e >> q;
    start_time = ((s[0]-'0')*1000)+((s[1]-'0')*100)+((s[3]-'0')*10)+(s[4]-'0');
    end_time = ((e[0]-'0')*1000)+((e[1]-'0')*100)+((e[3]-'0')*10)+(e[4]-'0');
    streaming_end_time = ((q[0]-'0')*1000)+((q[1]-'0')*100)+((q[3]-'0')*10)+(q[4]-'0');
    while(!cin.eof()) {
        cin >> time >> name;
        int t = ((time[0]-'0')*1000)+((time[1]-'0')*100)+((time[3]-'0')*10)+(time[4]-'0');
        if(m.find(name)!=m.end()) {
            if(t>=end_time&&t<=streaming_end_time) {        //총회 끝나고 스트리밍 종료 전에 채팅쳤을때
                m[name] = 1;
            }
            else if((t<end_time||t>streaming_end_time)&&m[name]!=1) {   //끝나기 전이나 스트리밍 종료 후 채팅쳤을때
                m[name] = 0;
            }
        }
        else if(t<=start_time) {
            m[name] = 0;
        }
        
        
    }
    for(auto iter = m.begin();iter!=m.end();iter++) {
        if(iter->second == 0) {
            m.erase(iter);
            iter--;
        }
    }
    cout << m.size();
}