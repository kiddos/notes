from subprocess import Popen, PIPE


def main():
    # n = 10000
    a = [1, 0, 1, 1, 0, 1]
    n = len(a)
    k = 1
    # ans = 52
    p = Popen(['./f1'], stdin=PIPE, stdout=PIPE, text=True)

    zeros = 0
    ans = 0
    for i in range(n):
        if a[i] == 0:
            zeros += 1
            if zeros == k:
                ans = i+1

    def write(text: str):
        p.stdin.write(text + '\n')
        p.stdin.flush()

    def read() -> str:
        return p.stdout.readline()

    write(f'{n} 1')
    write(f'{k}')
    for t in range(20):
        commands = read().strip().split(' ')
        print(commands)
        if commands[0] == '?':
            left = int(commands[1])-1
            right = int(commands[2])
            s = sum(a[left:right])
            write(f'{s}')
        elif commands[0] == '!':
            x = int(commands[1])
            if x == ans:
                print('correct!')
            else:
                print('incorrect')
            return
    print('exceeded limit, ans=', ans)


if __name__ == '__main__':
    main()
