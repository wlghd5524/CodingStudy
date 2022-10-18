#include <iostream>

using namespace std;

int first_count = 0, second_count = 0;

int fib(int n) {
    first_count++;
    if(n==1 || n == 2) {
        return 1;
    }
    else {
        return fib(n-1) + fib(n-2);
    }
}
int main() {
    int n;
    cin >> n;
    fib(n);
    int f[n+1];
    f[1] = 1;
    f[2] = 1;
    for(int i = 3; i<=n; i++) {
        f[i] = f[i-1] + f[i-2];
        second_count++;
    }
    cout << (first_count+1)/2 << " " << second_count;
    return 0;
}