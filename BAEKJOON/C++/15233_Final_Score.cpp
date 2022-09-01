#include <iostream>
#include <map>
using namespace std;
int main() {
    map<string, char> m;
    int a, b, g, a_count = 0, b_count = 0;
    string name;
    cin >> a >> b >> g;
    for (int i = 0; i < a; i++) {
        cin >> name;
        m[name] = 'A';
    }
    for (int i = 0; i < b; i++) {
        cin >> name;
        m[name] = 'B';
    }
    for (int i = 0; i < g; i++) {
        cin >> name;
        if (m[name] == 'A') {
            a_count++;
        }
        else {
            b_count++;
        }
    }
    if (a_count > b_count) {
        cout << "A";
    }
    else if (a_count < b_count) {
        cout << "B";
    }
    else {
        cout << "TIE";
    }
}