#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(pair<int, pair<int, int>> a, pair<int, pair<int, int>> b){
    if (a.second.first == b.second.first) {
        return a.second.second < b.second.second;
    }
    return a.second.first > b.second.first;
}

int main(){
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, c;
    cin >> n >> c;
    map<int, pair<int, int>> m;
    for (int i = 0; i < n; i++) {
        int data;
        cin >> data;
        if (m.find(data) != m.end()) {
            m[data].first++;
        }
        else {
            m[data] = {1, i};
        }
    }
    vector<pair<int, pair<int, int>>> v(m.begin(), m.end());
    sort(v.begin(), v.end(), cmp);
    for (auto iter = v.begin(); iter != v.end(); iter++) {
        for (int i = 0; i < iter->second.first; i++) {
            cout << iter->first << " ";
        }
    }
}