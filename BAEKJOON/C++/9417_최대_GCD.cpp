#include <iostream>
#include <vector>

using namespace std;
int gcd(int a, int b) {
    int tmp;
    while (b != 0) {
        tmp = a % b;
        a = b;
        b = tmp;
    }
    return a;
}

int main() {
    int n;
    cin >> n;
    cin.ignore();
    for (int i = 0; i < n; i++) {
        int max = 0;
        vector<int> v;
        string str;
        getline(cin, str);
        string tmp;
        for (int j = 0; j < str.size(); j++) {
            if (str[j] != ' ') {
                tmp += str[j];
            }
            if (str[j] == ' ' || j + 1 == str.size()) {
                v.push_back(stoi(tmp));
                tmp.clear();
            }
        }
        for (int j = 0; j < v.size(); j++) {
            for (int p = j + 1; p < v.size(); p++) {
                if (gcd(v[j], v[p]) > max) {
                    max = gcd(v[j], v[p]);
                }
            }
        }
        cout << max << "\n";
    }
}