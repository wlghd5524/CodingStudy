#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    vector<int> v;
    int sum = 0;
    for (int i = 0; i < 9; i++) {
        int tmp;
        cin >> tmp;
        sum += tmp;
        v.push_back(tmp);
    }
    bool is_find = false;
    for (int i = 0; i < v.size(); i++) {
        for (int j = i + 1; j < v.size(); j++) {
            if (sum - v[i] - v[j] == 100) {
                v.erase(v.begin() + i);
                v.erase(v.begin() + j - 1);
                is_find = true;
                break;
            }
        }
        if (is_find) {
            break;
        }
    }
    sort(v.begin(), v.end());
    for (auto iter = v.begin(); iter != v.end(); iter++) {
        cout << *iter << "\n";
    }
}