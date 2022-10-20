#include <string>
#include <vector>
#include <set>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    multiset<string> p;
    multiset<string> c;
    for (int i = 0; i < participant.size(); i++) {
        p.insert(participant[i]);
    }
    for (int i = 0; i < completion.size(); i++) {
        c.insert(completion[i]);
    }
    for (auto iter = c.begin(); iter != c.end(); iter++) {
        auto find_iter = p.find(*iter);
        if (find_iter != p.end()) {
            p.erase(find_iter);
        }
    }
    answer = *p.begin();
    return answer;
}