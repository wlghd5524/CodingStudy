#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
bool cmp(pair<pair<int, string>, int> a, pair<pair<int, string>, int> b) {
    if (a.first.first == b.first.first)
        return a.second < b.second;
    return a.first.first < b.first.first;
}
int main() {
    string name;
    int n, age;
    cin >> n;
    vector<pair<pair<int, string>, int>> mem(n);
    for (int i = 0; i < n; i++) {
        cin >> mem[i].first.first >> mem[i].first.second;
        mem[i].second = i;
    }
    sort(mem.begin(), mem.end(), cmp);
    for (int i = 0; i < n; i++)
        cout << mem[i].first.first << " " << mem[i].first.second << "\n";
}