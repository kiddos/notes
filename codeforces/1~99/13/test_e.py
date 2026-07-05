import random

n = 100000
m = 100000

print(n, m)
for i in range(n):
    print(random.randint(1, 3), end=' ')
print()

for i in range(m):
    t = random.randint(0, 1)
    print(t, end=' ')
    if t == 0:
        node = random.randint(1, n)
        power = random.randint(1, n)
        print(node, power)
    elif t == 1:
        node = random.randint(1, n)
        print(node)
