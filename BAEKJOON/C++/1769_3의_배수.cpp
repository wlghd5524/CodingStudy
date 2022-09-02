#include <iostream>
using namespace std;
int main() {
    int cnt = 0;
    string str;
    cin >> str;
    while (str.size() != 1) {
        int sum = 0;
        for (int i = 0; i < str.size(); i++) {
            sum += str[i] - '0';
        }
        str = to_string(sum);
        cnt++;
    }
    cout << cnt << "\n";
    if (stoi(str) % 3 == 0) {
        cout << "YES";
    }
    else {
        cout << "NO";
    }
}