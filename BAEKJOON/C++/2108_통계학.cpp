#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
bool cmp(pair<int, int> a, pair<int, int> b) {
    if (a.second == b.second) {
        return a.first < b.first;
    }
    return a.second > b.second;
}
int main() {
    int n, count = 0;
    double avg;
    cin >> n;
    multiset<int> ms;
    map<int, int> m;
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        if (m.find(num) != m.end()) {
            m[num]++;
        }
        else {
            m[num] = 0;
        }
        ms.insert(num);
        avg += num;
    }
    vector<int> v(ms.begin(), ms.end());
    if (round(avg / n) == -0) {
        cout << 0 << "\n";
    }
    else {
        cout << round(avg / n) << "\n";
    }
    cout << v[n / 2] << "\n";
    vector<pair<int, int>> v2(m.begin(), m.end());
    sort(v2.begin(), v2.end(), cmp);
    if (v2.size() == 1) {
        cout << v2[0].first << "\n";
    }
    else {
        if (v2[0].second == v2[1].second) {
            cout << v2[1].first << "\n";
        }
        else {
            cout << v2[0].first << "\n";
        }
    }
    cout << *ms.rbegin() - *ms.begin() << "\n";
}