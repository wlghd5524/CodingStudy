#include <string>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    set<string> s(phone_book.begin(), phone_book.end());
    int cnt = 0;
    for (auto iter = s.begin(); iter != s.end(); iter++) {
        if (cnt <= s.size() - 2) {
            auto iter_tmp = ++iter;
            iter--;
            if (iter_tmp->find(*iter) == 0) {
                answer = false;
                break;
            }
        }
        cnt++;
    }
    return answer;
}