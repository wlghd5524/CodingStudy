#include <iostream>
#include <string>
using namespace std;
int main() {
    string str;
    while (1) {
        cin >> str;
        if (str == "0")
            break;
        if (str.size() == 1)
            cout << "yes\n";
        else if (str.size() == 2) {
            if (str[0] == str[1])
                cout << "yes\n";
            else
                cout << "no\n";
        }
        else if (str.size() == 3) {
            if (str[0] == str[2])
                cout << "yes\n";
            else
                cout << "no\n";
        }
        else if (str.size() == 4) {
            if (str[0] == str[3] && str[1] == str[2])
                cout << "yes\n";
            else
                cout << "no\n";
        }
        else if (str.size() == 5) {
            if (str[0] == str[4] && str[1] == str[3])
                cout << "yes\n";
            else
                cout << "no\n";
        }
    }
    return 0;
}