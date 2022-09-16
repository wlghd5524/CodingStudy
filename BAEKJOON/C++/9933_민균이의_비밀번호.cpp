#include <iostream>
#include <set>
#include <algorithm>
using namespace std;
int main() {
    int n;
    cin >> n;
    set<string> s;
    string result;
    for(int i = 0; i < n; i++) {
        string str;
        cin >> str;
        s.insert(str);
        reverse(str.begin(),str.end());
        if(s.find(str) != s.end()) {
            result = str;
        }
    }
    cout << result.size() << " " << result[result.size() / 2];
    return 0;
}