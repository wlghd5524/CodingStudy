#include <iostream>
using namespace std;
int main() {
    int x, y, w, h, min = 10000;
    cin >> x >> y >> w >> h;
    if(w-x < min) {
        min = w-x;
    }
    if(x < min) {
        min = x;
    }
    if(h-y < min) {
        min = h-y;
    }
    if(y < min) {
        min = y;
    }
    cout << min;
}
