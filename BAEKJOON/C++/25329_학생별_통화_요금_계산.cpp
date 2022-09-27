#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
bool cmp(pair<string, int> a, pair<string, int> b) {
    if (a.second == b.second) {
        return a.first < b.first;
    }
    return a.second > b.second;
}
int main() {
    int n;
    cin >> n;
    map<string, int> m;
    for (int i = 0; i < n; i++) {
        int sum = 0;
        string time, name, tmp;
        cin >> time >> name;
        sum += (time[0] - '0') * 600;
        sum += (time[1] - '0') * 60;
        sum += (time[3] - '0') * 10;
        sum += (time[4] - '0');
        if (m.find(name) != m.end()) {
            m[name] += sum;
        }
        else {
            m[name] = sum;
        }
    }
    vector<pair<string, int>> v(m.begin(), m.end());
    for (auto iter = v.begin(); iter != v.end(); iter++) {
        if (iter->second <= 100) {
            iter->second = 10;
        }
        else {
            if ((iter->second - 100) % 50 == 0) {
                iter->second = 10 + (iter->second - 100) / 50 * 3;
            }
            else {
                iter->second = 10 + ((iter->second - 100) / 50 + 1) * 3;
            }
        }
    }
    sort(v.begin(), v.end(), cmp);
    for (auto iter = v.begin(); iter != v.end(); iter++) {
        cout << iter->first << " " << iter->second << "\n";
    }
}