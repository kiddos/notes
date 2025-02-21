import random

n = 500000
max_x = 36
print(n)
# answer = []
for i in range(n):
    t = random.randint(1, 2)
    if t == 1:
        x = random.randint(1, max_x)
        print(f'{t} {x}')
        # answer.append(x)
    elif t == 2:
        x = random.randint(1, max_x)
        y = random.randint(1, max_x)
        # for i in range(len(answer)):
        #     if answer[i] == x:
        #         answer[i] = y
        print(f'{t} {x} {y}')
