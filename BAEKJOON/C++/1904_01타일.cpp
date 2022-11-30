#include <iostream>
#include <vector>
using namespace std;
int ModuloAdd(int a, int b, int mod)
{
    return ((a % mod) + (b % mod)) % mod;
}
int main() {
    int n;
    cin >> n;
    vector<int> dp(n+1);
    dp[1] = 1;
    dp[2] = 2;
    for(int i = 3;i<=n;i++) {
        dp[i] = ModuloAdd(dp[i-1],dp[i-2],15746);
    }
    cout << dp[n];
    return 0;
}