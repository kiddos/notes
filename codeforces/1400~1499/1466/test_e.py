import random

n = 100
ans = 0
x = [random.randint(1 << 50, 1 << 60 - 1) for i in range(n)]
print(n)
for i in range(n):
    print(x[i], end=' ')
print()

MOD = 1000000007
for i in range(n):
    for j in range(n):
        for k in range(n):
            a = (x[i] & x[j]) % MOD
            b = (x[j] | x[k]) % MOD
            ans += (a * b) % MOD
            ans %= MOD
print(ans)
