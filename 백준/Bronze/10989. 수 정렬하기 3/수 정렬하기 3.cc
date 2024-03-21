#include <iostream>
#include <map>
#include <algorithm>
using namespace std;
int main() {
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    map<short,int> m;
    for(int i=0;i<n;i++) {
        int tmp;
        cin >> tmp;
        if(m.find(tmp)==m.end()) {
            m[tmp] = 1;
        }
        else {
            m[tmp]++;
        }
    }
    
    for(auto iter = m.begin();iter!=m.end();iter++) {
        for(int i=0;i<iter->second;i++) {
            cout << iter->first << "\n";
        }
        
    }
}