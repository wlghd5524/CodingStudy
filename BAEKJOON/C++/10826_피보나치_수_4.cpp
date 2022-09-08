#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
string bigNumAdd(string x, string y) {
    string result;
    int xleng = x.size();
    if(x.size()<y.size()) {
        string tmp;
        tmp = x;
        x = y;
        y = tmp;
    }
    for(int i = y.size();i<x.size();i++) {
        y.insert(0,"0");
    }
    reverse(x.begin(),x.end());
    reverse(y.begin(),y.end());
    for(int i = 0; i < xleng; i++) {
        int tmp = (x[i]-'0') + (y[i]-'0');
        if(tmp >= 10) {
            tmp -= 10;
            if(i+1==x.size()) {
                x.push_back('1');
            }
            else {
                x[i+1]++;
            }
        }
        x[i] = tmp + '0';
    }
    reverse(x.begin(),x.end());
    return x;
}
int main(){
    int n;
    cin >> n;
    string arr[n+1];
    arr[0] = "0";
    arr[1] = "1";
    for (int i = 2; i < n + 1; i++)
        arr[i] = bigNumAdd(arr[i - 1],arr[i - 2]);
    cout << arr[n];
    return 0;
}