#include <iostream>
using namespace std;
int main() {
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    cin.ignore();
    string bit = "000000000000000000000";
    for (int i = 0; i < n; i++) {
        string cmd;
        int data;
        cin >> cmd;
        if (cmd == "add") {
            cin >> data;
            bit[data] = '1';
        }
        if (cmd == "remove") {
            cin >> data;
            bit[data] = '0';
        }
        if (cmd == "check") {
            cin >> data;
            if (bit[data] == '1') {
                cout << 1 << "\n";
            }
            else {
                cout << 0 << "\n";
            }
        }
        if (cmd == "toggle") {
            cin >> data;
            if (bit[data] == '1') {
                bit[data] = '0';
            }
            else {
                bit[data] = '1';
            }
        }
        if (cmd == "all") {
            bit = "011111111111111111111";
        }
        if (cmd == "empty") {
            bit = "000000000000000000000";
        }
    }
}