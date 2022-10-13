#include <iostream>
#include <set>
using namespace std;
int main() {
    int n, count = 0;
    cin >> n;
    string num[n];
    for (int i = 0; i < n; i++) {
        cin >> num[i];
    }
    for (int i = 0; i < num[0].size(); i++) {
        set<string> s;
        for (int j = 0; j < n; j++) {
            string tmp;
            for (int p = num[0].size() - 1; p >= num[0].size() - i - 1 && p >= 0; p--) {
                tmp += num[j][p];
            }
            s.insert(tmp);
        }
        if (s.size() == n) {
            cout << i + 1;
            break;
        }
    }
    return 0;
}