import random

n = 200000
print(1)
print(n)
arr = []
for i in range(n):
    x = random.randint(0, 1)
    if x == 0:
        arr.append(-1)
    else:
        y = random.randint(1, 1000000000)
        arr.append(y)
arr = sorted(arr)
for val in arr:
    print(val, end=' ')
print()
