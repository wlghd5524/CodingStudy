#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    int n, m;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cin >> m;
    unordered_map<int, int> um;
    int data[m];
    for (int i = 0; i < m; i++) {
        cin >> data[i];
        um.insert({data[i], 0});
    }
    for (int i = 0; i < n; i++) {
        if (um.find(arr[i]) != um.end())
            um[arr[i]] += 1;
    }
    vector<int> result(m);
    for (int i = 0; i < m; i++) {
        auto iterator = um.find(data[i]);
        result[i] = iterator->second;
    }
    for (int i = 0; i < result.size(); i++) {
        cout << result[i];
        if (i != result.size() - 1)
            cout << " ";
    }
    return 0;
}