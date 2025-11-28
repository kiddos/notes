from subprocess import Popen, PIPE
import math


def main():
    p = Popen(['./e'], stdin=PIPE, stdout=PIPE, text=True)

    def write(text: str):
        p.stdin.write(text + '\n')
        p.stdin.flush()

    def read() -> str:
        return p.stdout.readline()

    min_n = 6
    max_n = 100
    n = max_n - min_n + 1
    write(f'{n}')
    for t in range(min_n, max_n + 1):
        write(f'{t}')
        line = read()
        # print(t, line)
        ans = [int(pi) for pi in line.strip().split(' ')]
        bad = 0
        for i in range(len(ans) - 2):
            g1 = math.gcd(ans[i], ans[i + 1])
            g2 = math.gcd(ans[i + 1], ans[i + 2])
            g3 = math.gcd(ans[i], ans[i + 2])
            if g1 == 1 and g2 == 1 and g3 == 1:
                bad += 1
        if bad > 6:
            print('invalid')
        # else:
        #     print('pass')


if __name__ == '__main__':
    main()
