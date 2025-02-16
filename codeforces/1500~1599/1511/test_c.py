import random

n = 300000
q = 300000
print(f'{n} {q}')
for i in range(n):
    print(random.randint(1, 50), end=' ')
print()
for i in range(q):
    print(random.randint(1, 50), end=' ')
print()
