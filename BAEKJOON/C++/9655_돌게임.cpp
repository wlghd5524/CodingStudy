#include <iostream>
using namespace std;
int main() {
    int n;
    cin >> n;
    int dp[n + 1];
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 1;
    for (int i = 4; i <= n; i++) {
        if (dp[i - 1] + 1 < dp[i - 3] + 1) {
            dp[i] = dp[i - 1] + 1;
        }
        else {
            dp[i] = dp[i - 3] + 1; 
        }
    }
    if (dp[n] % 2 == 0) {
        cout << "CY";
    }
    else {
        cout << "SK";
    }
    return 0;
}