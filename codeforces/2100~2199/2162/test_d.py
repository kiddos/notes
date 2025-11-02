from subprocess import Popen, PIPE
import random
import copy


def main():
    # perm = [2, 1, 3, 4]
    # l = 2
    # r = 4
    perm = []
    n = 10000
    for i in range(1, n+1):
        perm.append(i)
    random.shuffle(perm)
    l = random.randint(0, n-1)
    r = random.randint(l, n-1)

    a = copy.deepcopy(perm)
    for i in range(l-1, r):
        a[i] += 1
    p = Popen(['./d'], stdin=PIPE, stdout=PIPE, text=True)

    prefix1 = [0]
    for x in perm:
        prefix1.append(prefix1[-1] + x)
    prefix2 = [0]
    for x in a:
        prefix2.append(prefix2[-1] + x)
    print(prefix1)
    print(prefix2)

    def write(text: str):
        p.stdin.write(text + '\n')
        p.stdin.flush()

    def read() -> str:
        return p.stdout.readline()

    write('1')
    write(f'{len(perm)}')
    for t in range(42):
        commands = read().strip().split(' ')
        print(commands)
        if commands[0] == '1':
            left = int(commands[1])
            right = int(commands[2])
            sum = prefix1[right] - prefix1[left-1]
            print('sum=', sum)
            write(f'{sum}')
        if commands[0] == '2':
            left = int(commands[1])
            right = int(commands[2])
            sum = prefix2[right] - prefix2[left-1]
            print('sum=', sum)
            write(f'{sum}')
        elif commands[0] == '!':
            left = int(commands[1])
            right = int(commands[2])
            if left == l and right == r:
                print('correct')
            else:
                print('incorrect')
            return
    print('exceeded limit')


if __name__ == '__main__':
    main()
