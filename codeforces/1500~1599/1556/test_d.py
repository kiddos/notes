from subprocess import Popen, PIPE


def bit_count(n: int) -> str:
    return str(n.bit_count())


def main():
    a = [1, 6, 4, 2, 3, 5, 4, 30, 120, 239, 12]
    # a = [1, 6, 4, 2, 3, 5, 4]
    k = 6
    b = sorted([x for x in a])
    # k = 10
    p = Popen(['./d'], stdin=PIPE, stdout=PIPE, text=True)

    def write(text: str):
        p.stdin.write(text + '\n')
        p.stdin.flush()

    def read() -> str:
        return p.stdout.readline()

    n = len(a)
    write(f'{n} {k}')
    for i in range(2 * n + 2):
        output = read()
        command = output.split(' ')
        print(command)
        if command[0] == 'and':
            i1 = int(command[1])-1
            i2 = int(command[2])-1
            result = a[i1] & a[i2]
            write(str(result))
        elif command[0] == 'or':
            i1 = int(command[1])-1
            i2 = int(command[2])-1
            result = a[i1] | a[i2]
            write(str(result))
        elif command[0] == 'finish':
            res = int(command[1])
            print(res, b[k-1])
            if res == a[k-1]:
                print('correct')
            else:
                print('incorrect')
            return
    print('exceeded limit')


if __name__ == '__main__':
    main()
