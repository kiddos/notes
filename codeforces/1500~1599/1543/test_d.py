from subprocess import Popen, PIPE
import random


def main():
    # n = 10000
    n = 5
    # ans = 52
    ans = random.randint(0, n-1)
    p = Popen(['./d1'], stdin=PIPE, stdout=PIPE, text=True)

    def write(text: str):
        p.stdin.write(text + '\n')
        p.stdin.flush()

    def read() -> str:
        return p.stdout.readline()

    write('1')
    write(f'{n} 2')
    current = ans
    for k in range(n):
        inputs = read()
        output = int(inputs)
        if output == current:
            print('found! ans=', ans, current)
            write('1')
            return
        else:
            current ^= output
            write('0')
        # print(k, 'user input=', output, 'current=', current)
    print('exceeded limit, ans=', ans)


if __name__ == '__main__':
    main()
