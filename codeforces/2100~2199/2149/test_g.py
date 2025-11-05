import random

n = 200000
q = 200000
print(1)
print(f'{n} {q}')
for i in range(n):
    print(random.randint(1, 1000000000), end=' ')
print()
for i in range(q):
    l = random.randint(1, n)
    r = random.randint(l, n)
    print(f'{l} {r}')
