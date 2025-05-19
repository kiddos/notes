from subprocess import Popen, PIPE
import random


def main():
    p = 2
    n = p * 3
    k = random.randint(n // 3 + 1, n // 3 * 2 - 1)
    a = [0 for i in range(k)] + [1 for i in range(n-k)]
    a = [0, 1, 1, 0, 1, 1, 0, 1, 0]
    # random.shuffle(a)
    n = len(a)
    ans = []
    for i in range(n):
        if a[i] == 0:
            ans.append(i+1)
    print(a)
    print(ans)

    p = Popen(['./d1'], stdin=PIPE, stdout=PIPE, text=True)

    def write(text: str):
        p.stdin.write(text + '\n')
        p.stdin.flush()

    def read() -> str:
        return p.stdout.readline()

    write('1')
    write(f'{n}')

    max_ops = n * 2 + 1
    for op in range(max_ops+1):
        commands = read().strip().split(' ')
        print(commands)
        if commands[0] == '?':
            i = int(commands[1]) - 1
            j = int(commands[2]) - 1
            k = int(commands[3]) - 1
            s = a[i] + a[j] + a[k]
            result = 1 if s >= 2 else 0
            write(f'{result}')
        elif commands[0] == '!':
            imposter = [int(i) for i in commands[2:]]
            print('ans = ', imposter)
            if imposter == ans:
                print('correct!')
            else:
                print('incorrect')
            return

    print('exceeded limit, ans=', ans)


if __name__ == '__main__':
    main()
