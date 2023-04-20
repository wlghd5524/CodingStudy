#include <iostream>
using namespace std;
int main() {
    int hamburger = 10000;
    int bever = 10000;
    for(int i = 0;i<3;i++) {
        int price;
        cin >> price;
        hamburger = min(price,hamburger);
    }
    for(int i = 0;i<2;i++) {
        int price;
        cin >> price;
        bever = min(price,bever);
    }
    cout << hamburger+bever-50;
    return 0;
}