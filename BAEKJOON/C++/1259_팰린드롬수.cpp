#include <iostream>
#include <string>
using namespace std;
void printYes() {
    cout << "yes\n";
}
void printNo() {
    cout << "no\n";
}
int main() {
    string str;
    while (1) {
        cin >> str;
        if (str == "0")
            break;
        if (str.size() == 1)
            printYes();
        else if (str.size() == 2) {
            if (str[0] == str[1])
                printYes();
            else
                printNo();
        }
        else if (str.size() == 3) {
            if (str[0] == str[2])
                printYes();
            else
                printNo();
        }
        else if (str.size() == 4) {
            if (str[0] == str[3] && str[1] == str[2])
                printYes();
            else
                printNo();
        }
        else if (str.size() == 5) {
            if (str[0] == str[4] && str[1] == str[3])
                printYes();
            else
                printNo();
        }
    }
    return 0;
}