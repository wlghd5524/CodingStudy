#include <iostream>
#include <string>
#include <cctype>
using namespace std;
int main() {
    int max_count = 0;
    int max_index = 0;
    int i;
    string str;
    cin >> str;
    int count[26] = {0, };
    for (i = 0; i < str.size(); i++) {
        if (isupper(str[i]) != 0)
            count[str[i] - 65]++;
        else
            count[str[i] - 97]++;
    }
    for (i = 0; i < 26; i++) {
        if (max_count < count[i]) {
            max_index = i;
            max_count = count[i];
        }
    }
    for (i = 0; i < 26; i++) {
        if (count[i] == max_count && i != max_index) {
            cout << "?";
            return 0;
        }
    }
    cout << char(max_index + 65);
    return 0;
}