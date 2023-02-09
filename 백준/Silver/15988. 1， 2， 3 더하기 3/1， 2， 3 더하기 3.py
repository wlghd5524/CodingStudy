t = int(input())
l = []
mod = 1000000009
for i in range(t):
    l.append(int(input()))
dp = [0 for i in range(max(l)+1)]
dp[1] = 1
dp[2] = 2
dp[3] = 4
for i in range(4, max(l)+1):
    dp[i] = ((((dp[i-1] % mod) + (dp[i-2] % mod)) % mod) % mod + (dp[i-3] % mod)) % mod
for i in range(t):
    print(dp[l[i]])
