#include <iostream>
#include <queue>
using namespace std;
int main() {
    int n;
    cin >> n;
    priority_queue<int> gifts;
    for(int i = 0;i<n;i++) {
        int a;
        cin >> a;
        if(a==0) {
            if(gifts.empty()) {
                cout << -1 << "\n";
            }
            else {
                cout << gifts.top() << "\n";
                gifts.pop();
            }
        }
        else {
            for(int j = 0;j<a;j++) {
                int value;
                cin >> value;
                gifts.push(value);
            }
        }
    }
    return 0;
}