from subprocess import Popen, PIPE
import copy


def main():
    ans = [100, 99]
    # ans = [0, 0]
    # ans = [-1, 0]
    current = copy.deepcopy(ans)
    anchors = [[0, 0]]
    # anchors = [[0, 0], [1, 0]]
    # anchors = [[1, 1], [2, 2], [3, 3]]
    n = len(anchors)
    p = Popen(['./b'], stdin=PIPE, stdout=PIPE, text=True)

    def write(text: str):
        p.stdin.write(text + '\n')
        p.stdin.flush()

    def read() -> str:
        return p.stdout.readline()

    write('1')
    write(f'{n}')
    for anch in anchors:
        write(f'{anch[0]} {anch[1]}')
    for t in range(11):
        commands = read().strip().split(' ')
        print(commands)
        if commands[0] == '?':
            d = commands[1]
            k = int(commands[2])
            if d == 'U':
                current[1] += k
            elif d == 'D':
                current[1] -= k
            elif d == 'R':
                current[0] += k
            elif d == 'L':
                current[0] -= k

            d = min([abs(anch[0] - current[0]) + abs(anch[1] - current[1]) for anch in anchors])
            print(d)
            write(f'{d}')
        elif commands[0] == '!':
            x = int(commands[1])
            y = int(commands[2])
            if x == ans[0] and y == ans[1]:
                print('correct')
            else:
                print('incorrect')
            return
    print('exceeded limit, x=', x)


if __name__ == '__main__':
    main()
