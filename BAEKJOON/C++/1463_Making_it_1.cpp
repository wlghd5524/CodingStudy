#include <iostream>

using namespace std;

int main()
{
    int n;
    int count = 0;
    cin >> n;
    while (1) {
        if (n % 3 == 0) {
            n /= 3;
            count++;
        }
        else if (n % 2 == 0 && (n - 1) % 3 != 0) {
            n /= 2;
            count++;
        }
        else {
            n -= 1;
            count++;
        }
        if (n == 1) {
            break;
        }
    }
    cout << count;
    return 0;
}