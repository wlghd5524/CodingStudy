#include <iostream>
using namespace std;
int main() {
    string a, b, result;
    cin >> a >> b;
    for (int i = 0; i < a.size(); i++) {
        result += a[i];
        result += b[i];
    }
    while (1) {
        string str;
        for (int i = 0; i < result.size(); i++) {
            if (i != result.size() - 1) {
                char tmp = result[i] + result[i + 1] - '0';
                if (tmp - '0' >= 10) {
                    tmp -= 10;
                }
                str += tmp;
            }
        }
        result = str;
        if (result.size() == 2) {
            break;
        }
    }
    cout << result;
    return 0;
}