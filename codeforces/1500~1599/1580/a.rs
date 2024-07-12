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
    if s.is_empty() {
        return Vec::new();
    }
    s.split(" ").map(|x| x.trim().parse().expect("invalid input")).collect()
}

fn read_str() -> String {
    let mut s = String::new();
    stdin().read_line(&mut s).unwrap();
    s.trim().to_string()
}

fn area(p: &Vec<Vec<i32>>, x1: usize, y1: usize, x2: usize, y2: usize) -> i32 {
    p[x2+1][y2+1] - p[x2+1][y1] - p[x1][y2+1] + p[x1][y1]
}

fn solve() {
    let stdout = stdout();
    let mut writer = BufWriter::new(stdout.lock());

    let inputs = read_vec::<usize>();
    let n = inputs[0];
    let m = inputs[1];
    let mut s: Vec<Vec<char>> = Vec::new();
    for _i in 0..n {
        let row: Vec<char> = read_str().chars().collect();
        s.push(row);
    }

    let mut p = vec![vec![0; m+1]; n+1];
    for i in 1..=n {
        for j in 1..=m {
            let mut x = 0;
            if s[i-1][j-1] == '1' {
                x = 1;
            }
            p[i][j] = p[i-1][j] + p[i][j-1] - p[i-1][j-1] + x;
        }
    }

    let min_row = 5;
    let min_col = 4;
    let inf = 100000000;
    let mut suffix: Vec<i32> = vec![inf; m];
    let mut ans = inf;
    for r1 in 0..=(n-min_row) {
        for r2 in r1+min_row-1..n {
            for c in 0..m {
                suffix[c] = inf;
            }

            for c in min_col-1..m {
                let top = c as i32 - area(&p, r1, 0, r1, c-1);
                let bot = c as i32 - area(&p, r2, 0, r2, c-1);
                let middle = area(&p, r1+1, 0, r2-1, c-1);
                let right = (r2 - r1 - 1) as i32 - area(&p, r1+1, c, r2-1, c);
                suffix[c] = top + bot + middle + right;
            }

            for c in (min_col-1..m-1).rev() {
                suffix[c] = suffix[c].min(suffix[c+1]);
            }

            for c in 0..=m-min_col {
                let left = (r2 - r1 - 1) as i32 - area(&p, r1+1, c, r2-1, c);
                let suf = suffix[c + min_col - 1];
                let top = c as i32 + 1 - area(&p, r1, 0, r1, c);
                let bot = c as i32 + 1 - area(&p, r2, 0, r2, c);
                let middle = area(&p, r1 + 1, 0, r2-1, c);
                let prefix = top + bot + middle;
                let x = suf - prefix + left;
                ans = ans.min(x);
            }
        }
    }

    writeln!(writer, "{}", ans).ok();
}

fn main() {
    let n = read_int::<i32>();
    for _t in 0..n {
        solve();
    }
}
