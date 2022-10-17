#include <iostream>
#include <map>
#include <set>
using namespace std;
int main() {
    map<int, int> m;
    for (int i = 1; i <= 8; i++) {
        int tmp;
        cin >> tmp;
        m[tmp] = i;
    }
    int cnt = 0;
    int sum = 0;
    set<int> result;
    for (auto iter = m.rbegin(); iter != m.rend(); iter++) {
        sum += iter->first;
        result.insert(iter->second);
        cnt++;
        if (cnt == 5) {
            break;
        }
    }
    cout << sum << "\n";
    for (auto iter = result.begin(); iter != result.end(); iter++) {
        cout << *iter << " ";
    }
}