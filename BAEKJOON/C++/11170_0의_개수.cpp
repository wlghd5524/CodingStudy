#include <iostream>
using namespace std;
int main() {
    int t;
    cin >> t;
    for(int i = 0;i<t;i++) {
        int cnt = 0;
        int a, b;
        cin >> a >> b;
        for(int j = a;j<=b;j++) {
            for(int p = 0;p<to_string(j).size();p++) {
                if(to_string(j)[p]=='0') {
                    cnt++;
                }
            }
        }
        cout << cnt << "\n";
    }
    return 0;
}