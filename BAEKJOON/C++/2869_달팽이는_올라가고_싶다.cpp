#include <iostream>
using namespace std;
int main() {
    int a,b,v,day;
    int now = 0;
    cin >> a >> b >> v;
    for(day=1;;day++) {
        now += a;
        if(now >= v) {
            break; 
        }
        now -= b;
    }
    cout << day;
    return 0;
}