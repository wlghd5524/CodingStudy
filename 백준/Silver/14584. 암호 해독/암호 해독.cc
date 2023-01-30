#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main() {
    string str;
    cin >> str;
    int n;
    cin >> n;
    vector<string> word(n);
    for(int i=0; i<n; i++) {
        cin >> word[i];
    }
    while(1) {
        for(int i = 0; i < str.size(); i++) {
            str[i]++;
            if(str[i] > 122) {
                str[i] -= 26;
            }
        }
        for(int i = 0; i < word.size(); i++) {
            if(str.find(word[i]) != string::npos) {
                cout << str;
                return 0;
            }
        }
    }
    return 0;
}