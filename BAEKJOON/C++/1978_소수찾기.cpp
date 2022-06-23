#include <iostream>
#include <vector>

using namespace std;

bool isPrime(int n) {
    if (n < 2)
        return false;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0)
            return false;
    }
    return true;
}

int main() {
    int n;
    int count = 0;
    bool ip;
    int num;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> num;
        ip = isPrime(num);
        if (ip == true)
            count++;
    }
    cout << count;
}
