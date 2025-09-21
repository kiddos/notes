import random

print(1)
n = 1000
print(n)
for i in range(n):
    size = random.randint(100, n)
    ai = [random.randint(1, 200000) for _ in range(size)]
    print(size, end=' ')
    for x in ai:
        print(x, end=' ')
    print()
