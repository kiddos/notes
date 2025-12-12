import random

print(1)
n = 200000
print(n)
a = [random.randint(1, 1000000) for _ in range(n)]
b = [random.randint(1, 1000000) for _ in range(n)]
for i in range(n):
    if a[i] > b[i]:
        a[i], b[i] = b[i], a[i]
for i in range(n):
    print(a[i], end=' ')
print()
for i in range(n):
    print(b[i], end=' ')
print()
