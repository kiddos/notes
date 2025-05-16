from subprocess import Popen, PIPE
import random


def main():
    # a = [1, 2, 0, 3]
    # a = [3, 0, 1, 2]
    # a = [0, 3, 1, 2]
    # a = [0, 1, 3, 6]
    a = []
    for i in range(999):
        a.append(random.randint(1, 1000000000))
    n = len(a)
    a[random.randint(0, n-1)] = 0

    ans = a.index(0) + 1
    p = Popen(['./d'], stdin=PIPE, stdout=PIPE, text=True)

    def write(text: str):
        p.stdin.write(text + '\n')
        p.stdin.flush()

    def read() -> str:
        return p.stdout.readline()

    write('1')
    write(f'{n}')

    max_ops = n * 2 - 2
    for op in range(max_ops+1):
        commands = read().strip().split(' ')
        print(commands)
        if commands[0] == '?':
            i = int(commands[1]) - 1
            j = int(commands[2]) - 1
            k = int(commands[3]) - 1
            result = max(a[i], a[j], a[k]) - min(a[i], a[j], a[k])
            write(f'{result}')
        elif commands[0] == '!':
            i = int(commands[1])
            j = int(commands[2])
            if i == ans or j == ans:
                print('correct!')
            else:
                print('incorrect')
            return

    print('exceeded limit, ans=', ans)


if __name__ == '__main__':
    main()
