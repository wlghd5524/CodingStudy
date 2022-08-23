#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
bool cmp(pair<string, int> a, pair<string, int> b) {
    if (a.second == b.second) {
        if (a.first.size() == b.first.size()) {
            return a.first < b.first;
        }
        return a.first.size() > b.first.size();
    }
    return a.second > b.second;
}
int main() {
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m;
    cin >> n >> m;
    map<string, int> word;
    for (int i = 0; i < n; i++) {
        string tmp;
        cin >> tmp;
        if (tmp.size() >= m) {
            if (word.find(tmp) != word.end()) {
                word[tmp]++;
            }
            else {
                word[tmp] = 0;
            }
        }
    }
    vector<pair<string, int>> v(word.begin(), word.end());
    sort(v.begin(), v.end(), cmp);
    for (auto iter = v.begin(); iter != v.end(); iter++) {
        cout << iter->first << "\n";
    }
    return 0;
}