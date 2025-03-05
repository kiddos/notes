import random

print(1)
n = 300
print(n)
added = [1]
for node in range(2, n+1):
    idx = random.randint(0, len(added)-1)
    print(added[idx], end=' ')
    added.append(node)
print()
