from subprocess import Popen, PIPE
import math


def main():
    # n = 10000
    # x = 4
    # x = 2376
    x = 1000000000
    # ans = 52
    p = Popen(['./d'], stdin=PIPE, stdout=PIPE, text=True)

    def write(text: str):
        p.stdin.write(text + '\n')
        p.stdin.flush()

    def read() -> str:
        return p.stdout.readline()

    write('1')
    for t in range(60):
        commands = read().strip().split(' ')
        print(commands)
        if commands[0] == '?':
            a = int(commands[1])
            b = int(commands[2])
            g = math.gcd(x + a, x + b)
            print('g=', g)
            write(f'{g}')
        elif commands[0] == '!':
            ans = int(commands[1])
            if x == ans:
                print('correct!')
            else:
                print('incorrect')
            return


if __name__ == '__main__':
    main()
