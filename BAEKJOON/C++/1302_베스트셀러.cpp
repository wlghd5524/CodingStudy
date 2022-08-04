#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
bool cmp(pair<string, int> a, pair<string, int> b) {
    if (a.second == b.second)
        return a.first < b.first;
    return a.second > b.second;
}
int main() {
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    string book;
    unordered_map<string, int> m;
    for (int i = 0; i < n; i++) {
        cin >> book;
        if (m.find(book) == m.end()) {
            m[book] = 1;
        }
        else {
            m[book] += 1;
        }
    }
    vector<pair<string, int>> v(m.begin(), m.end());
    sort(v.begin(), v.end(), cmp);
    cout << v.begin()->first;
}