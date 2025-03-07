import random

print(1)
n = 1000000000
m = random.randint(1, n)
q = 200000
print(f'{n} {m} {q}')
for i in range(q):
    x = random.randint(1, n)
    print(x, end=' ')
print()
