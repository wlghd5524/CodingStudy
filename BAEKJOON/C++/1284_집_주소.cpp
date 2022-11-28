#include <iostream>
using namespace std;
int main() {
    while(1) {
        int sum = 0;
        string n;
        cin >> n;
        if(n=="0") {
            break;
        }
        for(int i = 0;i<n.size();i++) {
            if(n[i]=='1') {
                sum += 2;
            }
            else if(n[i]=='0') {
                sum += 4;
            }
            else {
                sum += 3;
            }
        }
        sum += n.size()+1;
        cout << sum << "\n";
    }
    return 0;
}