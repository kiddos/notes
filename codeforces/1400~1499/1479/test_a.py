from subprocess import Popen, PIPE
import random


def main():
    # n = 10000
    # a = [3, 2, 1, 4, 5]
    a = [i for i in range(1, 100001)]
    random.shuffle(a)
    n = len(a)
    p = Popen(['./a'], stdin=PIPE, stdout=PIPE, text=True)

    def write(text: str):
        p.stdin.write(text + '\n')
        p.stdin.flush()

    def read() -> str:
        return p.stdout.readline()

    write(f'{n}')
    for k in range(101):
        inputs = read()
        commands = inputs.split(' ')
        if commands[0] == '?':
            idx = int(commands[1]) - 1
            write(f'{a[idx]}')
        elif commands[0] == '!':
            idx = int(commands[1]) - 1
            prev_a = a[idx - 1] if idx > 0 else 100000000
            next_a = a[idx + 1] if idx + 1 < n else 100000000
            result = a[idx] < prev_a and a[idx] < next_a
            if result:
                print('found correct: ', idx + 1)
            else:
                print('incorrect', a[max(idx - 1, 0):min(idx + 1, n)])
            return
        # print(k, 'user input=', output, 'current=', current)
    print('exceeded limit')


if __name__ == '__main__':
    main()
