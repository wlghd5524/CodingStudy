#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector< vector<int> > commands) {
    vector<int> answer;
    for(int i = 0;i<commands.size();i++) {
        int a = commands[i][0];
        int b = commands[i][1];
        int c = commands[i][2];
        vector<int> sliced_v;
        sliced_v.insert(sliced_v.begin(),array.begin() + a - 1, array.begin() + b);
        sort(sliced_v.begin(),sliced_v.end());
        answer.push_back(sliced_v[c-1]);
    }
    return answer;
}