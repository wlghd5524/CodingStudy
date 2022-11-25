#include <iostream>
using namespace std;
int main() {
    int n;
    cin >> n;
    int max = -10000000;
    int min = 10000000;
    for(int i = 0;i<n;i++) {
        int tmp;
        cin >> tmp;
        if(max < tmp) {
            max = tmp;
        }
        if(min > tmp) {
            min = tmp;
        }
    }
    cout << min << " " << max; 
    return 0;
    
}