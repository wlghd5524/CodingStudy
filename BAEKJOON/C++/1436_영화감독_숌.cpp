#include <iostream>
#include <string>
using namespace std;
int main() {
    int n, count = 0;
    string tmp;
    cin >> n;
    for (int i = 666;; i++) {
        tmp = to_string(i);
        if (tmp.find("666") != string::npos)
            count++;
        if (count == n) {
            cout << i;
            break;
        }
    }
}