#include <iostream>
#include <map>
using namespace std;
int timeToInt(string s)
{
    return ((s[0] - '0') * 1000) + ((s[1] - '0') * 100) + ((s[3] - '0') * 10) + (s[4] - '0'); //시간을 int 형태로 변환 ex)06:00 -> 600
}
int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int start_time, end_time, streaming_end_time;
    map<string, int> m;
    string s, e, q;
    cin >> s >> e >> q;
    start_time = timeToInt(s);
    end_time = timeToInt(e);
    streaming_end_time = timeToInt(q);
    while (1)
    {
        string time, name;
        cin >> time >> name;
        if (cin.eof())
        {
            break;
        }
        int t = timeToInt(time);
        if (t <= start_time) //개강총회 시작하기 전에 채팅쳤을 때 map에 저장
        { 
            m[name] = 0;
        }
        else if (m.find(name) != m.end())
        {
            if (t >= end_time && t <= streaming_end_time) //출석 명단에 있는 학회원이 총회 끝나고 스트리밍 종료 전에 채팅쳤을때
            { 
                m[name] = 1;
            }
        }
    }
    int result = 0;
    for (auto iter = m.begin(); iter != m.end(); iter++) //출석이 인정된 학회원 카운트
    { 
        if (iter->second == 1)
        {
            result++;
        }
    }
    cout << result;
    return 0;
}