#include <iostream>
#include <string>
#include <cctype>
using namespace std;
int main() {
    int maxCount = 0;
    int maxIndex = 0;
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
        if (maxCount < count[i]) {
            maxIndex = i;
            maxCount = count[i];
        }
    }
    for (i = 0; i < 26; i++) {
        if (count[i] == maxCount && i != maxIndex) {
            cout << "?";
            return 0;
        }
    }
    cout << char(maxIndex + 65);
    return 0;
}