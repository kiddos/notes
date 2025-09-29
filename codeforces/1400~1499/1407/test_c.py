from subprocess import Popen, PIPE
import random


def main():
    # ans = [1, 3, 2]
    ans = [i for i in range(1, 101)]
    random.shuffle(ans)
    n = len(ans)
    p = Popen(['./c'], stdin=PIPE, stdout=PIPE, text=True)

    def write(text: str):
        p.stdin.write(text + '\n')
        p.stdin.flush()

    def read() -> str:
        return p.stdout.readline()

    write(f'{n}')
    for k in range(n * 2 + 1):
        output = read()
        command = output.split(' ')
        print(command)
        if command[0] == '?':
            x = int(command[1]) - 1
            y = int(command[2]) - 1
            result = ans[x] % ans[y]
            print(f'result = {result}')
            write(f'{result}')
        elif output[0] == '!':
            a = [int(item) for item in command[1:] if len(item.strip())]
            print(f'a = {a}')
            print(f'ans = {ans}')
            if all(x == ans[i] for i, x in enumerate(a)):
                print('correct')
            else:
                print('incorrect')
            return
    print('exceeded limit')


if __name__ == '__main__':
    main()
