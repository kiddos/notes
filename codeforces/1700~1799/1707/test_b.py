import random

n = 250000
a = [random.randint(0, 500000) for i in range(n)]
a = sorted(a)
print(1)
print(n)
for x in a:
    print(x, end=' ')
print()
