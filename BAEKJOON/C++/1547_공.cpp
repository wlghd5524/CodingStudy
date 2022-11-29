#include <iostream>
using namespace std;
int main() {
    int n;
    cin >> n;
    int ball_position = 1;
    for(int i = 0;i<n;i++) {
        int a, b;
        cin >> a >> b;
        if(a == ball_position) {
            ball_position = b;
        }
        else if(b == ball_position) {
            ball_position = a;
        }

    }
    cout << ball_position;
    return 0;
}