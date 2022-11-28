#include <iostream>
#include <map>
using namespace std;
int main() {
    map<int,int> x;
    map<int,int> y;
    for(int i = 0;i<3;i++) {
        int a, b;
        cin >> a >> b;
        if(x.find(a)!=x.end()) {
            x[a]++;
        }
        else {
            x[a] = 0;
        }
        if(y.find(b)!=y.end()) {
            y[b]++;
        }
        else {
            y[b] = 0;
        }
    }
    for(auto iter = x.begin();iter!=x.end();iter++) {
        if(iter->second==0) {
            cout << iter->first << " ";
        }
    }
    for(auto iter = y.begin();iter!=y.end();iter++) {
        if(iter->second==0) {
            cout << iter->first;
        }
    }
    return 0;
}