#include <iostream>
#include <stack>
using namespace std;
int main() {
    string str,bombstr;
    cin >> str;
    cin >> bombstr;
    stack<char> str_stack;
    stack<char> str_tmp;
    stack<char> bomb_tmp;
    stack<char> bomb;
    for(int i=0;i<str.size();i++) {
        str_stack.push(str[i]);
    }
    for(int i=0;i<bombstr.size();i++) {
        bomb.push(bombstr[i]);
    }
    bomb_tmp = bomb;
    while(1) {
        if(str_stack.top() == bomb_tmp.top()) {
            str_tmp.push(str_stack.top());
            str_stack.pop();
            bomb_tmp.pop();
        }
        else {
            if(bomb != bomb_tmp) {
                bomb_tmp = bomb;
            }
            else {
                str_tmp.push(str_stack.top());
                str_stack.pop();
            }
        }
        
        if(bomb_tmp.empty()) {
            for(int i=0;i<bomb.size();i++) {
                str_tmp.pop();
            }
            //while(!str_tmp.empty()) {
            for(int i=0;i<bomb.size() && !str_tmp.empty();i++) {
                str_stack.push(str_tmp.top());
                str_tmp.pop();
            }
            bomb_tmp = bomb;
        }
        if(str_stack.empty()) {
            break;
        }
    }
    if(str_tmp.empty()) {
        cout << "FRULA";
    }
    while (!str_tmp.empty()) {
        cout << str_tmp.top();
        str_tmp.pop();
    }
    return 0;
}