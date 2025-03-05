import random

print("1")
n = 100000
m = 10
k = n * m
print(f'{n} {m} {k}')
for i in range(n):
    print(random.randint(0, pow(2, 30)-1), end=' ')
print()
for i in range(m):
    print(random.randint(0, pow(2, 30)-1), end=' ')
print()
