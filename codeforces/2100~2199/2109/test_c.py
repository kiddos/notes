from subprocess import Popen, PIPE
import random


def main():
    max_val = 1000000000000000000
    min_val = -1000000000000000000
    # n = 10000
    # x = random.randint(1, 1000000000)
    # n = random.randint(1, 1000000000)
    n = 5
    x = 1234
    # n = 100
    # x = 9
    # ans = 52
    p = Popen(['./c2'], stdin=PIPE, stdout=PIPE, text=True)

    def write(text: str):
        p.stdin.write(text + '\n')
        p.stdin.flush()

    def read() -> str:
        return p.stdout.readline()

    write('1')
    write(f'{n}')
    for t in range(5):
        commands = read().strip().split(' ')
        print(commands)
        if commands[0] == 'add':
            y = int(commands[1])
            s = x + y
            if s > max_val or s < min_val:
                write('0')
            else:
                x = s
                write('1')
        elif commands[0] == 'mul':
            y = int(commands[1])
            prod = x * y
            if prod > max_val or prod < min_val:
                write('0')
            else:
                x = prod
                write('1')
        elif commands[0] == 'div':
            y = int(commands[1])
            if x % y == 0:
                x /= y
                write('1')
            else:
                write('0')
        elif commands[0] == 'digit':
            d = sum(int(digit) for digit in str(x))
            x = d
            write('1')
        elif commands[0] == '!':
            if x == n:
                print('correct!')
                write('1')
            else:
                print('incorrect')
                write('0')
            return
        print('n=', n, ',x=', x)
    print('exceeded limit, x=', x)


if __name__ == '__main__':
    main()
