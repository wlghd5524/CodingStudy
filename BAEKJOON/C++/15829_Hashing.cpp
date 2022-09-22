#include <iostream>
using namespace std;
int main() {
    int n = 0;
    long long int sum = 0;
    long long int pow_sum = 1;
    cin >> n;
    for(int i=0;i<n;i++) {
        char tmp;
        cin >> tmp;
        sum = (sum + (tmp-'a'+1) * pow_sum) % 1234567891;
        pow_sum = (pow_sum * 31) % 1234567891;
    }
    cout << sum;
}