#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
bool cmp(pair<string, int> a, pair<string, int> b) {
    return a.second < b.second;
}
int main() {
    int k, l;
    cin >> k >> l;
    string str;
    map<string, int> um;
    for (int i = 0; i < l; i++) {
        cin >> str;
        if (um.find(str) == um.end()) {
            um[str] = i;
        }
        else {
            um.erase(str);
            um[str] = i;
        }
    }
    vector<pair<string, int>> v(um.begin(), um.end());
    sort(v.begin(), v.end(), cmp);
    for (int i = 0; i < v.size(); i++) {
        if (i == k) {
            break;
        }
        cout << v[i].first;
        if (i + 1 != k) {
            cout << "\n";
        }
    }
    return 0;
}