import random

n = 1
m = 1
len1 = 600000
len2 = 600000
letters = ['a', 'b', 'c']
print(n, m)
a = [''.join(random.choices(letters, k=len1)) for i in range(n)]
b = [''.join(random.choices(letters, k=len2)) for i in range(m)]
for s in a:
    print(s)
for s in b:
    print(s)
