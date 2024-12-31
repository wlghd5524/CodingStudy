#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(vector<string> name, vector<int> yearning, vector<vector<string>> photo) {
    vector<int> answer;
    map<string,int> yearning_map;
    for(int i = 0;i<name.size();i++) {
        yearning_map[name[i]] = yearning[i];
    }
    for(int i = 0;i<photo.size();i++) {
        int sum = 0;
        for(int j = 0;j<photo[i].size();j++) {
            sum += yearning_map[photo[i][j]];
        }
        answer.emplace_back(sum);
    }
    
    return answer;
}