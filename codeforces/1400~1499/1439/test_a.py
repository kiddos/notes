from subprocess import Popen, PIPE
import random

def main():
    n = 10
    m = 10
    s = [[random.randint(0, 1) for __ in range(m)] for _ in range(n)]
    p = Popen(['./a1'], stdin=PIPE, stdout=PIPE, text=True)

    def write(text: str):
        p.stdin.write(text + '\n')
        p.stdin.flush()

    def read() -> str:
        return p.stdout.readline()

    write(f'{1}')
    write(f'{n} {m}')
    print(s)
    for i in range(n):
        line = ''.join([str(e) for e in s[i]])
        write(line)
    count = int(read())
    for i in range(count):
        line = read()
        changes = [int(k)-1 for k in line.strip().split(' ')]
        for k in range(0, 6, 2):
            x = changes[k]
            y = changes[k+1]
            if s[x][y] == 1:
                s[x][y] = 0
            else:
                s[x][y] = 1
    print(s)


if __name__ == '__main__':
    main()
