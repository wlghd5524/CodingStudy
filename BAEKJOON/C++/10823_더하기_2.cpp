#include <iostream>
using namespace std;
int main() {
    int sum = 0;
    string tmp;
    while (!cin.eof()) {
        string str;
        cin >> str;
        if (str == "") {
            sum += stoi(tmp);
            break;
        }
        for (int i = 0; i < str.size(); i++) {
            if (isdigit(str[i])) {
                tmp += str[i];
            }
            if (!isdigit(str[i]) || cin.eof()) {
                sum += stoi(tmp);
                tmp.clear();
            }
        }
    }
    cout << sum;
}