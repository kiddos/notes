use std::io::{stdin, stdout, BufWriter, Write};
use std::str::FromStr;
use std::fmt::Debug;

fn read_int<T: FromStr>() -> T where <T as FromStr>::Err: Debug {
    let mut s = String::new();
    stdin().read_line(&mut s).unwrap();
    s.trim().parse::<T>().expect("invalid input")
}

fn read_vec<T: FromStr>() -> Vec<T> where <T as FromStr>::Err: Debug {
    let mut s = String::new();
    stdin().read_line(&mut s).unwrap();
    s.split(" ").map(|x| x.trim().parse().expect("invalid input")).collect()
}

fn read_str() -> String {
    let mut s = String::new();
    stdin().read_line(&mut s).unwrap();
    s.trim().to_string()
}

fn opposite(ch: char) -> char {
    if ch == 'W' { 'B' } else { 'W' }
}

fn solve() {
    let stdout = stdout();
    let mut writer = BufWriter::new(stdout.lock());

    let inputs = read_vec::<usize>();
    let (n, m) = (inputs[0], inputs[1]);
    let mut s: Vec<Vec<char>> = Vec::new();
    for _ in 0..n {
        s.push(read_str().chars().collect::<Vec<_>>());
    }

    let mut ans: Vec<Vec<char>> = vec![vec!['.'; m]; n];
    let mut ch = 'W';
    for i in 0..n {
        for j in 0..m {
            if ans[i][j] != '.' {
                continue;
            }

            if s[i][j] == 'U' {
                ans[i][j] = ch;
                ans[i+1][j] = opposite(ch);
                ch = opposite(ch);
            } else if s[i][j] == 'D' {
                ans[i][j] = ch;
                ans[i-1][j] = opposite(ch);
                ch = opposite(ch);
            }
        }
    }

    for j in 0..m {
        for i in 0..n {
            if ans[i][j] != '.' {
                continue;
            }

            if s[i][j] == 'L' {
                ans[i][j] = ch;
                ans[i][j+1] = opposite(ch);
                ch = opposite(ch);
            } else if s[i][j] == 'R' {
                ans[i][j] = ch;
                ans[i][j-1] = opposite(ch);
                ch = opposite(ch);
            }
        }
    }

    for i in 0..n {
        let mut color = 0;
        for j in 0..m {
            if ans[i][j] == 'W' {
                color += 1;
            } else if ans[i][j] == 'B' {
                color -= 1;
            }
        }

        if color != 0 {
            writeln!(writer, "-1").ok();
            return;
        }
    }

    for j in 0..m {
        let mut color = 0;
        for i in 0..n {
            if ans[i][j] == 'W' {
                color += 1;
            } else if ans[i][j] == 'B' {
                color -= 1;
            }
        }

        if color != 0 {
            writeln!(writer, "-1").ok();
            return;
        }
    }

    for i in 0..n {
        let row: String = ans[i].iter().collect();
        writeln!(writer, "{}", row).ok();
    }
}

fn main() {
    let n = read_int::<i32>();
    for _t in 0..n {
        solve();
    }
}
