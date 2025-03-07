import random

print(1)
q = 500000
print(q)
size = 1
for i in range(q):
    t = random.randint(1, 2)
    if t == 1:
        v = random.randint(1, size)
        size += 1
        print(f'{t} {v}')
    elif t == 2:
        v = random.randint(1, size)
        x = random.randint(-1000000000, 1000000000)
        print(f'{t} {v} {x}')
