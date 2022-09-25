#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
bool compare(pair<pair<string, int>, pair<int, int>> a, pair<pair<string, int>, pair<int, int>> b) {
    if (a.first.second == b.first.second) {
        if (a.second.first == b.second.first) {
            if (a.second.second == b.second.second) {
                return a.first.first < b.first.first;
            }
            return a.second.second > b.second.second;
        }
        return a.second.first < b.second.first;
    }
    return a.first.second > b.first.second;
}

int main() {
    int n;
    cin >> n;
    vector<pair<pair<string, int>, pair<int, int>>> v;
    for (int i = 0; i < n; i++) {
        string name;
        int korean, english, math;
        cin >> name >> korean >> english >> math;
        v.push_back({{name, korean}, {english, math}});
    }
    sort(v.begin(), v.end(), compare);
    for (int i = 0; i < n; i++) {
        cout << v[i].first.first << "\n";
    }
}