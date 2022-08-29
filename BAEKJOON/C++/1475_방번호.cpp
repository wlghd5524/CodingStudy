#include <iostream>
using namespace std;
int main() {
    int max = 0;
    int digit[9] = {0, };
    string n;
    cin >> n;
    for(int i = 0; i<n.size(); i++) {
        if(n[i]=='9') {
            digit[6]++;
        }
        else {
            digit[n[i] - '0']++;
        }
    }
    if(digit[6] % 2 == 0) {
        digit[6] /= 2;
    }
    else {
        digit[6] = (digit[6] / 2) + 1;
    }
    for(int i=0; i<9; i++) {
        if(max < digit[i]) {
            max = digit[i];
        }
    }
    cout << max;
}