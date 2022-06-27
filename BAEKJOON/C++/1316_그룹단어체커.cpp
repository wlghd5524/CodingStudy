#include <iostream>

using namespace std;

int main() {
    int n = 0;
    int count = 0;
    bool cut = false;
    string str;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cut = false;
        cin >> str;
        for (int j = 0; j < str.length(); j++) {
            if (str.length() == 1)
                break;
            if (str[j] == str[j + 1])
                continue;
            for (int p = j + 2; p < str.length(); p++) {
                if (str[p] == str[j]) {
                    cut = true;
                    break;
                }
            }
        }
        if (cut == true)
            continue;
        count++;
    }
    cout << count;
    return 0;
}