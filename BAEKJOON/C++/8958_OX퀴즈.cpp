#include <iostream>
using namespace std;
int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int sum = 0;
        int count = 0;
        string str;
        cin >> str;
        for (int j = 0; j < str.size(); j++) {
            if (str[j] == 'O') {
                count++;
                sum += count;
            }
            if (str[j] == 'X') {
                count = 0;
            }
        }
        cout << sum << "\n";
    }
}