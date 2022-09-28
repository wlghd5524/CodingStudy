#include <iostream>
#include <vector>
#include <map>
using namespace std;
int main() {
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, data;
    cin >> n;
    vector<int> v;
    map<int, int> m;
    for (int i = 0; i < n; i++) {
        cin >> data;
        v.emplace_back(data);
        m[data] = 0;
    }
    int cnt = 0;
    for (auto iter = m.begin(); iter != m.end(); iter++) {
        iter->second = cnt;
        cnt++;
    }
    for (int i = 0; i < v.size(); i++) {
        cout << m[v[i]] << " ";
    }
    return 0;
}