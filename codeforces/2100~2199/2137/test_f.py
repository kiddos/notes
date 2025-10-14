import random

print(1)
n = 100
print(n)
a = []
for i in range(n):
    a.append(random.randint(1, 100))
b = []
for i in range(n):
    b.append(random.randint(1, 100))

same = random.randint(0, n // 10)
for i in range(same):
    idx = random.randint(0, n - 1)
    a[i] = b[i] = random.randint(1, 100)

for ai in a:
    print(ai, end=' ')
print()
for bi in b:
    print(bi, end=' ')
print()
