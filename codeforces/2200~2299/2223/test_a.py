import random

n = 100000
n *= 2
s1 = []
s2 = []
print(1)
print(n)
for i in range(n):
    r = random.randint(0, 1)
    if r == 1:
        s1.append("(")
    else:
        s1.append(")")
    r = random.randint(0, 1)
    if r == 1:
        s2.append("(")
    else:
        s2.append(")")
s1[0] = '('
s2[0] = '('
s1 = "".join(s1)
s2 = "".join(s2)
print(s1)
print(s2)
