#include <iostream>
#include <vector>
using namespace std;
int main() {
    int n,t;
    cin >> t;
    for(int j = 0;j<t;j++) {
        cin >> n;
        if(n<2) {
            cout << 1 << "\n";
            continue;
        }
        if(n==2) {
            cout << 2 << "\n";
            continue;
        }
        if(n==3) {
            cout << 4 << "\n";
            continue;
        }
        vector<long long int> dp(n+1);
        dp[0] = 1;
        dp[1] = 1;
        dp[2] = 2;
        dp[3] = 4;
        for(int i = 4;i<=n;i++) {
            dp[i] = dp[i-1] + dp[i-2] + dp[i-3] + dp[i-4];
        }
        cout << dp[n] << "\n";
    }
    return 0;
}