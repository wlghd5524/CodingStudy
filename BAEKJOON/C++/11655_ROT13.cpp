#include <iostream>
using namespace std;
int main() {
    string str;
    getline(cin, str);
    for (int i = 0; i < str.size(); i++) {
        if (isalpha(str[i])) {
            if (str[i] < 123 && str[i] > 96) {
                if (str[i] + 13 > 122) {
                    str[i] -= 13;
                }
                else {
                    str[i] += 13;
                }
            }
            else if (str[i] < 91 && str[i] > 64) {
                if (str[i] + 13 > 90) {
                    str[i] -= 13;
                }
                else {
                    str[i] += 13;
                }
            }
        }
    }
    cout << str;
}