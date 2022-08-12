#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;
bool cmp(pair<long long int,int> a, pair<long long int,int> b) {
    if(a.second == b.second) {
        return a.first < b.first;
    }
    return a.second > b.second;
}
int main() {
    int n;
    cin >> n;
    unordered_map<long long int,int> um;
    for(int i = 0; i < n; i++) {
        long long int num;
        cin >> num;
        if(um.find(num) != um.end()) {
            um[num]++;
        }
        else {
            um[num] = 0;
        }
    }
    vector<pair<long long int,int>> v(um.begin(), um.end());
    sort(v.begin(), v.end(), cmp);
    cout << v.front().first;
}
