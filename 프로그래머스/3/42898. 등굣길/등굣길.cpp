#include <string>
#include <vector>
#define MOD 1000000007

using namespace std;

int solution(int m, int n, vector<vector<int>> puddles) {
    vector<vector<int>> dp(n+1,vector<int>(m+1));
    vector<vector<bool>> is_puddle(n+1,vector<bool>(m+1));
    for(int i = 0;i<puddles.size();i++) {
        is_puddle[puddles[i][1]][puddles[i][0]] = true;
    }
    dp[0][1] = 1;
    for(int i = 1 ;i<=n;i++) {
        for(int j = 1;j<=m;j++) {
            if(is_puddle[i][j]) {
                dp[i][j] = 0;
            }
            else {
                dp[i][j] = ((dp[i-1][j] % MOD) + (dp[i][j-1] % MOD)) % MOD;
            }
        }
    }
    return dp[n][m];
}