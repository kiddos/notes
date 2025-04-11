import random

print('1')
n = 20
print(n)
for i in range(n):
    left = random.randint(1, 10000)
    right = random.randint(left+1, 12000)
    c = random.randint(1, n)
    print(f'{left} {right} {c}')
