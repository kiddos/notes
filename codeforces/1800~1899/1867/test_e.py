from subprocess import Popen, PIPE
import random

m = random.randint(10, 25)
n = m * 2
k = 6
a = [random.randint(1, 200) for i in range(n)]
x = 0
for i in range(n):
    x ^= a[i]
print(f'answer={x}')


p = Popen(['./e1'], stdin=PIPE, stdout=PIPE, text=True)


def write(text: str):
    p.stdin.write(text + '\n')
    p.stdin.flush()


def read() -> str:
    return p.stdout.readline()


print(f'n={n}, k={k}')
write('1')
write(f'{n} {k}')
for t in range(100):
    commands = read().strip().split(' ')
    print(commands)
    if commands[0] == '?':
        i = int(commands[1])
        result = 0
        for j in range(i-1, i+k-1):
            result ^= a[j]
        a[i-1:i+k-1] = a[i-1:i+k-1][::-1]
        write(f'{result}')
    elif commands[0] == '!':
        user_answer = int(commands[1])
        if user_answer == x:
            print('correct!')
        else:
            print('incorrect')
        break
