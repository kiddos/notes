from subprocess import Popen, PIPE


def main():
    # n = 10000
    a = [1, 0, 1, 1, 0, 1]
    ks = [2, 1]
    # a = [1, 0, 1, 1, 0, 1, 0, 0, 0, 1, 0, 1]
    # ks = [2, 3, 2, 3]
    # a = [0, 0, 0, 0, 0]
    # ks = [3, 2, 3, 1, 1]
    n = len(a)
    # ans = 52
    p = Popen(['./f2'], stdin=PIPE, stdout=PIPE, text=True)

    def write(text: str):
        p.stdin.write(text + '\n')
        p.stdin.flush()

    def read() -> str:
        return p.stdout.readline()

    write(f'{n} {len(ks)}')
    total = 0
    for k in ks:
        zeros = 0
        ans = 0
        for i in range(n):
            if a[i] == 0:
                zeros += 1
                if zeros == k:
                    ans = i+1

        print(a, k)
        write(f'{k}')
        for t in range(20):
            commands = read().strip().split(' ')
            print(commands)
            if commands[0] == '?':
                left = int(commands[1])-1
                right = int(commands[2])
                s = sum(a[left:right])
                write(f'{s}')
                total += 1
            elif commands[0] == '!':
                x = int(commands[1])
                if x == ans:
                    print('correct!')
                else:
                    print('incorrect')

                a[ans-1] = 1
                break

    if total >= k * 6:
        print('exceeded limit, ans=', ans)


if __name__ == '__main__':
    main()
