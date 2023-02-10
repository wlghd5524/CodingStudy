n = int(input())
n_len = len(str(n))
result = 0
for i in range(n_len):
    result += (9 * (10 ** (i-1))) * i
result += ((n - (10 ** (n_len-1))) + 1) * n_len
print(int(result))