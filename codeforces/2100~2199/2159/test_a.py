from subprocess import Popen, PIPE
import random
from collections import Counter


def main():
    n = 300
    a = [i + 1 for i in range(n)] + [i + 1 for i in range(n)]
    random.shuffle(a)
    print(a)
    p = Popen(['./a'], stdin=PIPE, stdout=PIPE, text=True)

    def write(text: str):
        p.stdin.write(text + '\n')
        p.stdin.flush()

    def read() -> str:
        return p.stdout.readline()

    write('1')
    write(f'{n}')
    for t in range(n * 3 + 1):
        commands = read().strip().split(' ')
        print(commands)
        if commands[0] == '?':
            collected = [a[int(c)-1] for c in commands[2:]]
            counter = Counter(collected)
            x = 0
            for k, c in counter.most_common():
                if c >= 2:
                    x = max(x, k)
            write(f'{x}')
        elif commands[0] == '!':
            answer = [int(c) for c in commands[1:]]
            if answer == a:
                print('correct!')
                write('1')
            else:
                print('incorrect')
                write('0')
            return
    print('exceeded limit')


if __name__ == '__main__':
    main()
