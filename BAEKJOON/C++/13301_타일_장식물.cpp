#include <iostream>
#include <vector>
using namespace std;
int main() {
    int n;
    cin >> n;
    vector<long long int> dp(n+1);
    dp[1] = 4;
    dp[2] = 6;
    for(int i = 3;i<=n;i++) {
        dp[i] = dp[i-1] + dp[i-2];
    }
    cout << dp[n];
    return 0;
}