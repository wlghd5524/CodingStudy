#include <iostream>
#include <algorithm>
using namespace std;
string bigNumAdd(string x, string y) {
    if(x.size() < y.size()) {
        string tmp;
        tmp = x;
        x = y;
        y = tmp;
    }
    for(int i = y.size();i<x.size();i++) {
        y.insert(0,"0");
    }
    for(int i = x.size()-1; i >= 0; i--) {
        int tmp = (x[i]-'0') + (y[i]-'0');
        if(tmp >= 10) {
            tmp -= 10;
            if(i==0) {
                x.insert(0,"1");
                x[i+1] = tmp + '0';
                break;
            }
            else {
                x[i-1]++;
            }
        }
        x[i] = tmp + '0';
    }
    return x;
}
int main() {
    string a,b;
    cin >> a >> b;
    cout << bigNumAdd(a,b);
}