#include <iostream>
using namespace std;
int main() {
    int n,m;
    int x = 0, y = 0;
    int direction = 1;
    bool is_correct = true;
    cin >> n >> m;
    for(int i=0;i<m;i++) {
        string cmd;
        int data;
        cin >> cmd >> data;
        if(cmd[0] == 'M') {
            if(direction == 0) {
                y += data;
            }
            else if(direction == 1) {
                x += data;
            }
            else if(direction == 2) {
                y -= data;
            }
            else if(direction == 3) {
                x -= data;
            }
        }
        else if(cmd[0] == 'T') {
            if(data == 0) {
                direction--;
            }
            if(data == 1) {
                direction++;
            }
            if(direction > 3) {
                direction -= 4;
            }
            else if(direction < 0) {
                direction += 4;
            }
        }
        if(x < 0 || y < 0 || x > n || y > n) {
            is_correct = false;
        }
    }
    if(is_correct) {
        cout << x << " " << y;
    }
    else {
        cout << -1;
    }
    return 0;
}