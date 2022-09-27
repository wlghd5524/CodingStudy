#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    int n, score, list_max;
    cin >> n >> score >> list_max;
    vector<int> v;
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        v.emplace_back(num);
    }
    if (list_max == n) {
        if (*v.rbegin() < score) {
            v.pop_back();
            v.emplace_back(score);
        }
        else {
            cout << -1;
            return 0;
        }
    }
    else {
        v.emplace_back(score);
    }
    sort(v.begin(), v.end(), greater<>());
    cout << find(v.begin(), v.end(), score) - v.begin() + 1;
    return 0;
}