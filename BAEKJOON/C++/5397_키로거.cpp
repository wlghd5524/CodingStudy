#include <iostream>
#include <stack>
using namespace std;
int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int index = 0;
        string str;
        cin >> str;
        stack<char> s1;
        stack<char> s2;
        for (int j = 0; j < str.size(); j++) {
            if (isalpha(str[j]) != 0 || isdigit(str[j]) != 0) {
                s1.push(str[j]);
                index++;
            }
            if (str[j] == '<') {
                if (index != 0) {
                    s2.push(s1.top());
                    s1.pop();
                    index--;
                }
            }
            if (str[j] == '>') {
                if (s2.empty() == 0) {
                    s1.push(s2.top());
                    s2.pop();
                    index++;
                }
            }
            if (str[j] == '-') {
                if (index != 0) {
                    s1.pop();
                    index--;
                }
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
        cout << "\n";
    }
}