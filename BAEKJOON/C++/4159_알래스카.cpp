#include <iostream>
#include <set>
#include <vector>
using namespace std;
int main() {
    while (1) {
        bool is_possible = true;
        int n;
        cin >> n;
        set<int> s;
        if (n == 0) {
            break;
        }
        for (int i = 0; i < n; i++) {
            int tmp;
            cin >> tmp;
            s.insert(tmp);
        }
        int cur = 0;
        int distance = 200;
        vector<int> v;
        v.assign(s.begin(), s.end());
        while (cur <= 1422) {
            if (distance < 0) {
                is_possible = false;
                break;
            }
            if (v[0] == cur) {
                distance = 200;
                v.erase(v.begin());
            }
            cur++;
            distance--;
        }
        cur = 1422;
        v.assign(s.rbegin(), s.rend());
        while (cur >= 0) {
            if (distance < 0) {
                is_possible = false;
                break;
            }
            if (v[0] == cur) {
                distance = 200;
                v.erase(v.begin());
            }
            cur--;
            distance--;
        }
        if (is_possible) {
            cout << "POSSIBLE\n";
        }
        else {
            cout << "IMPOSSIBLE\n";
        }
    }
    return 0;
}