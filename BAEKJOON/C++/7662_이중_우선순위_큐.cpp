#include <iostream>
#include <algorithm>
#include <set>
using namespace std;
int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        multiset<int, greater<int>> ms;
        int k;
        cin >> k;
        for (int j = 0; j < k; j++) {
            char cmd;
            int data;
            cin >> cmd >> data;
            if (cmd == 'I') {
                ms.insert(data);
            }
            else {
                if (ms.empty() == 0) {
                    if (data == 1) {
                        ms.erase(ms.begin());
                    }
                    else {
                        auto iter = ms.find(*ms.rbegin());
                        ms.erase(iter);
                    }
                }
            }
        }
        if (ms.empty() == 1) {
            cout << "EMPTY";
        }
        else {
            cout << *ms.begin() << " " << *ms.rbegin();
        }
        cout << "\n";
    }
}