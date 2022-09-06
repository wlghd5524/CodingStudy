#include <iostream>
using namespace std;
int main(){
    int n = 1;
    while(1) {
        int count = 0;
        cin >> n;
        if(n == 0) {
            break;
        }
        for (int i = n + 1; i <= 2 * n; i++) {
            bool is_prime = true;
            for (int j = 2; j * j <= i; j++) {
                if (i % j == 0) {
                    is_prime = false;
                    break;
                }
            }
            if (!is_prime || i == 1) {
                continue;
            }
            count++;
        }
        cout << count << "\n";
    }
    return 0;
}