import random

t = 10
n = 200000
# y = 1000000000
y = random.randint(1, 1000000000)
print(t)
for _ in range(t):
    print(f'{n} {y}')
    for i in range(n):
        print(random.randint(1, 200000), end=' ')
    print()
