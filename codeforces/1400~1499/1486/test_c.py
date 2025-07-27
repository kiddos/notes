from subprocess import Popen, PIPE
import random


def bit_count(n: int) -> str:
    return str(n.bit_count())


def largest_index(a):
    p = [(val, i) for i, val in enumerate(a)]
    p = sorted(p)
    return p[-1][1]


def second_largest(a, left, right):
    p = []
    for i in range(left, right + 1):
        p.append((a[i], i))
    p = sorted(p)
    # print(p[-10:])
    return p[-2][1]


def main():
    n = 100000
    a = [i for i in range(1, n + 1)]
    random.shuffle(a)
    p = Popen(['./c'], stdin=PIPE, stdout=PIPE, text=True)
    # print(a)
    ans = largest_index(a)
    print(f'ans = {ans}')

    def write(text: str):
        p.stdin.write(text + '\n')
        p.stdin.flush()

    def read() -> str:
        return p.stdout.readline()

    write(f'{n}')
    for k in range(21):
        output = read()
        command = output.split(' ')
        print(command)
        if command[0] == '?':
            left = int(command[1]) - 1
            right = int(command[2]) - 1
            index = second_largest(a, left, right) + 1
            print(f'query result {left}~{right} = {index}')
            write(f'{index}')
        elif output[0] == '!':
            a = int(command[1]) - 1
            if a == ans:
                print('correct')
            else:
                print('incorrect')
            return
    print('exceeded limit')


if __name__ == '__main__':
    main()
