#include <iostream>
using namespace std;
int main() {
    int max = 0;
    int max_index = 0;
    for(int i = 0;i<9;i++) {
        int tmp;
        cin >> tmp;
        if(max<tmp) {
            max = tmp;
            max_index = i+1;
        }
    }
    cout << max << "\n" << max_index;
}