#include <iostream>
#include <stack>
using namespace std;
int main() {
    string str;
    cin >> str;
    stack<int> st;
    for(int i = 0;i<str.size();i++) {
        if(isdigit(str[i])) {
            st.push(str[i]-'0');
        }
        else {
            int b = st.top();
            st.pop();
            int a = st.top();
            st.pop();
            if(str[i] == '+') {
                st.push(a+b);
            }
            else if(str[i] == '-') {
                st.push(a-b);
            }
            else if(str[i]=='*') {
                st.push(a*b);
            }
            else if(str[i]=='/') {
                st.push(a/b);
            }
        }
    }
    cout << st.top();
    return 0;
}