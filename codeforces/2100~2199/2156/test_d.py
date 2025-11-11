from subprocess import Popen, PIPE
import random


def main():
    # n = 128
    n = 128
    a = [x + 1 for x in range(n)]
    random.shuffle(a)
    # a = [9, 1, 10, 3, 7, 8, 2, 5, 6, 4]
    print(a)
    p = Popen(['./d'], stdin=PIPE, stdout=PIPE, text=True)

    def write(text: str):
        p.stdin.write(text + '\n')
        p.stdin.flush()

    def read() -> str:
        return p.stdout.readline()

    write('1')
    write(f'{n}')
    for t in range(n * 2 + 1):
        commands = read().strip().split(' ')
        print(t, commands)
        if commands[0] == '?':
            idx = int(commands[1]) - 1
            x = int(commands[2])
            and_result = x & a[idx]
            if and_result == 0:
                write('0')
            else:
                write('1')
        elif commands[0] == '!':
            last_element = int(commands[1])
            if last_element == a[-1]:
                print('correct!')
            else:
                print('incorrect')
            return
    print('exceeded limit')


if __name__ == '__main__':
    main()
