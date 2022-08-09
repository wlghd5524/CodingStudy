#include <iostream>
#include <stack>
using namespace std;
int main() {
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    string data, command;
    char ch;
    cin >> data;
    cin.ignore();
    stack<char> s1;
    stack<char> s2;
    for (int i = 0; i < data.size(); i++) {
        s1.push(data[i]);
    }
    cin >> n;
    cin.ignore();
    for (int i = 0; i < n; i++) {
        getline(cin, command);
        if (command == "L") {
            if (s1.empty() == 0) {
                s2.push(s1.top());
                s1.pop();
            }
        }
        else if (command == "D") {
            if (s2.empty() == 0) {
                s1.push(s2.top());
                s2.pop();
            }
        }
        else if (command == "B") {
            if (s1.empty() == 0) {
                s1.pop();
            }
        }
        else if (command[0] == 'P') {
            ch = command[2];
            s1.push(ch);
        }
    }
    while (s1.empty() == 0) {
        s2.push(s1.top());
        s1.pop();
    }
    while (s2.empty() == 0) {
        cout << s2.top();
        s2.pop();
    }
    return 0;
}