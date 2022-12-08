#include <iostream>
#include <set>
using namespace std;
int main() {
    int n;
    cin >> n;
    set<int> arr;
    for(int i = 0;i<n;i++) {
        int tmp;
        cin >> tmp;
        arr.insert(tmp);
    }
    for(auto iter = arr.begin();iter!=arr.end();iter++) {
        cout << *iter << " ";
    }
    return 0;
}