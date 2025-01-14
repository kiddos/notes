from subprocess import Popen, PIPE


def bit_count(n: int) -> str:
    return str(n.bit_count())


def main():
    n = 12309839
    ans = n
    p = Popen(['./d'], stdin=PIPE, stdout=PIPE, text=True)

    def write(text: str):
        p.stdin.write(text + '\n')
        p.stdin.flush()

    def read() -> str:
        return p.stdout.readline()

    write('1')
    write(bit_count(n))
    for k in range(30):
        output = read()
        if output[0] == '-':
            x = int(output[2:])
            if n >= x:
                n -= x
                write(bit_count(n))
            else:
                write('-1')
                break
        elif output[0] == '!':
            a = int(output[2:])
            if a == ans:
                print('correct')
            else:
                print('incorrect')
                write('-1')
            return
    print('exceeded limit')


if __name__ == '__main__':
    main()
