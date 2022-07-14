#include <iostream>
#include <string>
using namespace std;
int main() {
    int count = 0;
    string str, result;
    cin >> str;
    for (int i = 0; i < str.size() + 1; i++) {
        if (str[i] == 'X')
            count++;
        else {

            if (count % 4 == 0) {
                for (int j = 0; j < count / 4; j++)
                    result += "AAAA";
            }
            else if (count % 2 == 0) {
                for (int j = 0; j < count / 4; j++)
                    result += "AAAA";
                result += "BB";
            }
            else {
                cout << -1;
                return 0;
            }
            if (str[i] == '.')
                result += ".";

            count = 0;
        }
    }
    cout << result;
}