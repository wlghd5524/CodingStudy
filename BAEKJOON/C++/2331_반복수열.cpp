#include <iostream>
#include <set>
#include <cmath>
using namespace std;
int main() {
    int a, n, first = 0;
    cin >> a >> n;
    bool is_there = false;
    set<int> s;
    s.insert(a);
    while (1) {
        int tmp = 0;
        for (int i = 0; i < to_string(a).size(); i++) {
            tmp += pow(to_string(a)[i] - '0', n);
        }
        a = tmp;
        if (a == first && is_there) {
            break;
        }
        if (s.find(a) != s.end()) {
            if (!is_there) {
                is_there = true;
                first = a;
            }
            s.erase(a);
        }
        else {
            s.insert(a);
        }
    }
    cout << s.size();
    return 0;
}