#include<iostream>
#include<vector>
using namespace std;
int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i=0;i<n;i++) {
        arr[i] = i+1;
    }
    while(true) {
        if(arr.size()==1) {
            cout << arr[0];
            break;
        }
        cout << arr[0] << " ";
        arr.erase(arr.begin());
        arr.emplace_back(arr.front());
        arr.erase(arr.begin());
    }
    return 0;
}