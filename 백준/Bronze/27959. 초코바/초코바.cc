#include <iostream>
using namespace std;
int main() {
    int a,b;
    cin >> a >> b;
    if(100*a >= b) {
        cout << "Yes";
    }
    else {
        cout << "No";
    }
    return 0;
}