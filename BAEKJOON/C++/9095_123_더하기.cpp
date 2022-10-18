#include <iostream>
using namespace std;
int main() {
    int t,n;
    cin >> t;
    for(int i=0;i<t;i++) {
        cin >> n;
        int dp[n+1];
        dp[1] = 1;
        dp[2] = 2;
        dp[3] = 4;
        dp[4] = 7;
        for(int j = 5;j<=n;j++) {
            dp[j] = dp[j-1] + dp[j-2] + dp[j-3];
        }
        cout << dp[n] << "\n";
    }
    return 0;
}