#include <iostream>
#include <algorithm>
using namespace std;
int main() {
    int n;
    cin >> n;
    cin.ignore();
    for (int i = 0; i < n; i++) {
        string str;
        getline(cin, str);
        string tmp;
        for (int j = 0; j < str.size(); j++) {
            if (str[j] != ' ') {
                tmp += str[j];
            }
            else {
                reverse(tmp.begin(), tmp.end());
                cout << tmp << " ";
                tmp.clear();
            }
            if (j + 1 == str.size()) {
                reverse(tmp.begin(), tmp.end());
                cout << tmp << " ";
            }
        }
    }
}