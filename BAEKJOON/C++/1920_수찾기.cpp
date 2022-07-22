#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;
int main() {
    int n, m;
    cin >> n;
    int arr[n];
    unordered_map<int, int> um;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cin >> m;
    int data[m];
    vector<int> result(m);
    for (int i = 0; i < m; i++) {
        cin >> data[i];
        um.insert({data[i], 0});
    }
    for (int i = 0; i < n; i++) {
        if (um.find(arr[i]) != um.end())
            um[arr[i]] = 1;
    }
    for (int i = 0; i < m; i++) {
        auto iterator = um.find(data[i]);
        result[i] = iterator->second;
    }
    for (int i = 0; i < result.size(); i++)
        cout << result[i] << "\n";
    return 0;
}