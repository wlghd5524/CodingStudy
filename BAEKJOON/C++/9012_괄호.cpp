#include <iostream>
using namespace std;

int main() {
    int t, left_count = 0, right_count = 0;
    cin >> t;
    string str;
    for (int i = 0; i < t; i++) {
        cin >> str;
        left_count = 0;
        right_count = 0;
        if (str.size() % 2 == 1) {
            cout << "NO\n";
            continue;
        }
        for (int j = 0; j < str.size(); j++) {
            if (str[j] == '(')
                left_count++;
            else if (str[j] == ')') {
                right_count++;
                if (left_count < right_count)
                    break;
            }
        }
        if (left_count != right_count)
            cout << "NO\n";
        else {
            cout << "YES\n";
        }
    }
    return 0;
}