from subprocess import Popen, PIPE


def shift(s, row, col):
    n = len(s)
    row_shift = row % n
    col_shift = col % n

    shifted_grid = []
    for r in range(n):
        orig_r = (r - row_shift) % n
        new_row = "".join(
            s[orig_r][(c - col_shift) % n] for c in range(n)
        )
        shifted_grid.append(new_row)
    return shifted_grid


def rotate90(s):
    n = len(s)
    rotated_grid = []
    for c in range(n):
        new_row = "".join(s[r][c] for r in range(n - 1, -1, -1))
        rotated_grid.append(new_row)

    return rotated_grid


def flip_vertical(s):
    return s[::-1]


def flip_horizontal(s):
    return [row[::-1] for row in s]


def find_x(s):
    n = len(s)
    for i in range(n):
        for j in range(n):
            if s[i][j] == '@':
                return (i + 1, j + 1)
    return None


def debug(s):
    for row in s:
        print(''.join(row))


def main():
    s0 = [
        '#....',
        '.#...',
        '.....',
        '.....',
        '.....',
    ]
    s0 = [
        '.....',
        '####.',
        '.....',
        '#####',
        '.....',
    ]
    s1 = []
    s2 = []
    for i, row in enumerate(s0):
        s1.append([c for c in row])
        s2.append([c for c in row])

    n = len(s0)
    x = [3, 4]
    p = Popen(['./c'], stdin=PIPE, stdout=PIPE, text=True)

    def write(text: str):
        p.stdin.write(text + '\n')
        p.stdin.flush()

    def read() -> str:
        return p.stdout.readline()

    write('first')
    write('1')
    write(f'{n}')
    for row in s1:
        write(''.join(row))
    write(f'{x[0]} {x[1]}')

    line = read().strip().split(' ')
    print(line)
    r1 = int(line[0]) - 1
    c1 = int(line[1]) - 1
    r2 = int(line[2]) - 1
    c2 = int(line[3]) - 1

    s1[r1][c1], s1[r2][c2] = (s1[r2][c2], s1[r1][c1])
    s2[r1][c1], s2[r2][c2] = (s2[r2][c2], s2[r1][c1])

    s2[x[0] - 1][x[1] - 1] = '@'

    s1 = shift(s1, 1, 2)
    s1 = rotate90(s1)
    s1 = flip_horizontal(s1)

    s2 = shift(s2, 1, 2)
    s2 = rotate90(s2)
    s2 = flip_horizontal(s2)

    debug(s2)

    p = Popen(['./c'], stdin=PIPE, stdout=PIPE, text=True)
    write('second')
    write('1')
    write(f'{n}')
    for row in s1:
        write(''.join(row))

    new_x = find_x(s2)
    ans = read().strip().split(' ')
    user_x = (int(ans[0]), int(ans[1]))
    print(new_x, user_x)
    if new_x == user_x:
        print('correct')
    else:
        print('wrong')


if __name__ == '__main__':
    main()
