#include <iostream>
#include <map>
using namespace std;
int main() {
    int n,count = 0;
    cin >> n;
    bool enter = true;
    map<string, bool> m;
    for(int i = 0; i < n; i++) {
        string tmp;
        cin >> tmp;
        if(tmp == "ENTER") {
            count += m.size();
            m.clear();
        }
        else {
            m[tmp] = true;
            if(i + 1 == n) {
                count += m.size();
            }
        }
    }
    cout << count;
    return 0;
}