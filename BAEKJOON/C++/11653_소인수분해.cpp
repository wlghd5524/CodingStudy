#include <iostream>
using namespace std;
int main() {
    int n,i = 2;
    cin >> n;
    while(1) {
        if(n%i==0) {
            n /= i;
            cout << i << "\n";
            i = 2;
            continue;
        }
        if(n == 1)  
            break;
        i++;
    }
    return 0;
}