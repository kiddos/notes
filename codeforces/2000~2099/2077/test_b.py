from subprocess import Popen, PIPE
import random


def main():
    # n = 10000
    x = 1
    y = 2
    x = random.randint(0, 100000)
    y = random.randint(0, 100000)
    m = 1
    m = random.randint(0, 100000)
    # ans = 52
    p = Popen(['./b'], stdin=PIPE, stdout=PIPE, text=True)

    ans = (m | x) + (m | y)

    def write(text: str):
        p.stdin.write(text + '\n')
        p.stdin.flush()

    def read() -> str:
        return p.stdout.readline()

    write('1')
    for t in range(3):
        commands = read().strip().split(' ')
        print(commands)
        if commands[0] == '!':
            write(f'{m}')
            result = int(read().strip())
            print(result)
            if result == ans:
                print('correct!')
            else:
                print('incorrect')
            return
        else:
            n = int(commands[0])
            q = (n | x) + (n | y)
            write(f'{q}')
    print('exceeded limit, ans=', ans)


if __name__ == '__main__':
    main()
