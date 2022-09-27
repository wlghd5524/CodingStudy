#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
int main() {
    int n;
    cin >> n;
    vector<long long int> v;
    for (int i = 0; i < n; i++) {
        string num;
        cin >> num;
        string tmp(num.rbegin(), num.rend());
        v.emplace_back(stoll(tmp));
    }
    sort(v.begin(), v.end());
    for (auto iter = v.begin(); iter != v.end(); iter++) {
        cout << *iter << "\n";
    }
    return 0;
}