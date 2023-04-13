#include <iostream>
using namespace std;
int main() {
    string s;
    cin >> s;
    char tmp = s[0];
    int cnt = 1;
    for(int i = 1;i<s.size();i++) {
        if(s[i] != tmp) {
            break;
        }
        cnt++;
    }
    cout << cnt;
}