#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    bool is_tag = false;
    int count = 0;
    string str, tmp;
    vector<string> word;
    vector<string> tag;
    getline(cin, str);
    for (int i = 0; i < str.size(); i++) {
        if ((str[i] != ' ' && is_tag == false) && str[i] != '<') {
            if (i == str.size() - 1) {
                count--;
            }
            count++;
        }
        if (str[i] == ' ' || i == str.size() - 1 || str[i] == '<') {
            if (is_tag == false) {
                if (i == str.size() - 1) {
                    reverse(str.begin() + i - count, str.end());
                }
                else{
                    reverse(str.begin() + i - count, str.begin() + i);
                }
                count = 0;
            }
        }
        if (str[i] == '<') {
            is_tag = true;
        }
        else if (str[i] == '>') {
            is_tag = false;
        }
    }
    cout << str;
}