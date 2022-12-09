#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    vector<int> arr;
    for(int i = 0;i<n;i++) {
        int tmp;
        cin >> tmp;
        arr.emplace_back(tmp);
    }
    sort(arr.begin(),arr.end());
    for(int i = 0;i<n;i++) {
        cout << arr[i] << "\n";
    }
}