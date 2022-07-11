#include <iostream>
using namespace std;

int main() {
    int t, leftCount = 0, rightCount = 0;
    cin >> t;
    string str;
    for (int i = 0; i < t; i++) {
        cin >> str;
        leftCount = 0;
        rightCount = 0;
        if (str.size() % 2 == 1) {
            cout << "NO\n";
            continue;
        }
        for (int j = 0; j < str.size(); j++) {
            if (str[j] == '(')
                leftCount++;
            else if (str[j] == ')') {
                rightCount++;
                if (leftCount < rightCount)
                    break;
            }
        }
        if (leftCount != rightCount)
            cout << "NO\n";
        else {
            cout << "YES\n";
        }
    }
}