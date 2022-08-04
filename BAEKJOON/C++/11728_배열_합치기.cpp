#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m, data, max = 0;
    cin >> n >> m;
    vector<int> v;
    for (int i = 0; i < n; i++) {
        cin >> data;
        if (data > max)
            max = data;
        v.emplace_back(data);
    }
    for (int i = 0; i < m; i++) {
        cin >> data;
        if (data > max)
            max = data;
        v.emplace_back(data);
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < v.size(); i++) {
        cout << v[i];
        if (i != v.size() - 1) {
            cout << " ";
        }
    }
}