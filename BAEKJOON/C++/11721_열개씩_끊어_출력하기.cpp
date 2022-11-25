#include <iostream>
#include <vector>
using namespace std;
int main() {
    string str;
    vector<string> arr;
    cin >> str;
    int cnt = 0;
    string tmp;
    for(int i = 0;i<str.size();i++) {
        tmp += str[i];
        cnt++;
        if(cnt==10 || i == str.size()-1) {
            arr.push_back(tmp);
            cnt = 0;
            tmp.clear();
        }
    }
    for(int i = 0;i<arr.size();i++) {
        cout << arr[i] << "\n";
    }
    return 0;
}