import random

n = 200000
print(1)

# generate a string with length n from a~z
s = ''.join(random.choice('abcdefghijklmnopqrstuvwxyz') for i in range(n))
print(s)
