#include <iostream>
#include <stack>
using namespace std;
int main() {
    string str;
    while (1) {
        bool no = false;
        stack<char> st;
        getline(cin, str);
        if (str == ".") {
            break;
        }
        for (int i = 0; i < str.size(); i++) {
            if (str[i] == '(') {
                st.push('(');
            }
            else if (str[i] == '[') {
                st.push('[');
            }
            else if (str[i] == ')') {
                if (st.empty() == 1) {
                    no = true;
                }
                else if (st.top() == '(') {
                    st.pop();
                }
                else {
                    no = true;
                }
            }
            else if (str[i] == ']') {
                if (st.empty() == 1) {
                    no = true;
                }
                else if (st.top() == '[') {
                    st.pop();
                }
                else {
                    no = true;
                }
            }
        }
        if (st.empty() == 1 && no == false) {
            cout << "yes\n";
        }
        else {
            cout << "no\n";
        }
    }
}