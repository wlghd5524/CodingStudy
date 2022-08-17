#include <iostream>
#include <string>
using namespace std;
int main() {
    int count = 0;
    string str;
    getline(cin, str);
    bool is_u = false;
    bool is_c1 = false;
    bool is_p = false;
    bool is_c2 = false;
    for (int i = 0; i < str.size(); i++) {
        if (str[i] == 'U') {
            is_u = true;
        }
        if (str[i] == 'C' && is_u == true) {
            is_c1 = true;
        }
        if (str[i] == 'P' && is_u == true && is_c1 == true) {
            is_p = true;
        }
        if (str[i] == 'C' && is_u == true && is_c1 == true && is_p == true) {
            is_c2 = true;
        }
    }
    if (is_c2 == true) {
        cout << "I love UCPC";
    }
    else {
        cout << "I hate UCPC";
    }
    return 0;
}