from subprocess import Popen, PIPE
import random


def main():
    n = 10
    a = 4
    batteries = [0 for i in range(n)]
    indices = [i for i in range(n)]
    random.shuffle(indices)
    for i in range(a):
        batteries[indices[i]] = 1

    p = Popen(['./d'], stdin=PIPE, stdout=PIPE, text=True)

    def write(text: str):
        p.stdin.write(text + '\n')
        p.stdin.flush()

    def read() -> str:
        return p.stdout.readline()

    write('1')
    write(f'{n}')
    limit = n * n // 2
    for t in range(limit):
        commands = read().strip().split(' ')
        print(commands)
        u = int(commands[0]) - 1
        v = int(commands[1]) - 1
        if batteries[u] and batteries[v]:
            write('1')
            print('done')
            return
        else:
            write('0')
    print('exceeded limit')


if __name__ == '__main__':
    main()
