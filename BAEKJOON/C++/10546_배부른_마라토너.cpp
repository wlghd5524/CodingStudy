#include <iostream>
#include <set>
using namespace std;
int main() {
    int n;
    cin >> n;
    string name;
    multiset<string> ms;
    for (int i = 0; i < n; i++) {
        cin >> name;
        ms.insert(name);
    }
    for (int i = 0; i < n - 1; i++) {
        cin >> name;
        if (ms.find(name) != ms.end()) {
            ms.erase(ms.find(name));
        }
    }
    cout << *ms.begin();
    return 0;
}