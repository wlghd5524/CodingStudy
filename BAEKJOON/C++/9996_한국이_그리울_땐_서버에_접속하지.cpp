#include <iostream>
#include <string>
#include <regex>
using namespace std;
int main() {
    int n;
    cin >> n;
    string pattern, name;
    cin >> pattern;
    for (int i = 0; i < pattern.size(); i++) {
        if (pattern[i] == '*') {
            pattern.insert(i, "\\w");
            break;
        }
    }
    regex re(pattern);
    for (int i = 0; i < n; i++) {
        cin >> name;
        bool yes = false;
        bool pattern_on = false;
        if (regex_match(name, re) == true) {
            cout << "DA\n";
        }
        else {
            cout << "NE\n";
        }
    }
}