#include <iostream>
#include <algorithm>
using namespace std;
int main() {
    string n;
    int sum = 0;
    cin >> n;
    for (int i = 0; i < n.size(); i++) {
        sum += n[i] - '0';
    }
    if (sum % 3 == 0 && n.find("0") != string::npos) {
        sort(n.begin(), n.end(), greater<>());
        cout << n;
    }
    else {
        cout << -1;
    }
    return 0;
}