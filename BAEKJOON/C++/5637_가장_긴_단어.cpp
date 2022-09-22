#include <iostream>
using namespace std;
int main() {
    int max_size = 0;
    string result;
    while (1) {
        string str;
        getline(cin, str);
        string tmp;
        for (int i = 0; i < str.size(); i++) {
            if (isalpha(str[i]) || str[i] == '-') {
                tmp += tolower(str[i]);
            }
            else {
                if (max_size < tmp.size() && tmp != "E-N-D") {
                    max_size = tmp.size();
                    result = tmp;
                }
                tmp.clear();
            }
        }
        if (str.find("E-N-D") != string::npos) {
            break;
        }
    }
    cout << result;
    return 0;
}