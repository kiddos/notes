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

fn prefix_sum(p: &mut Vec<Vec<i64>>, n: usize) {
    for i in 1..=n {
        for j in 1..=n {
            p[i][j] = p[i][j] + p[i-1][j] + p[i][j-1] - p[i-1][j-1];
        }
    }
}

fn sum(p: &Vec<Vec<i64>>, r1: usize, c1: usize, r2: usize, c2: usize) -> i64 {
    p[r2][c2] - p[r1-1][c2] - p[r2][c1-1] + p[r1-1][c1-1]
}

fn solve() {
    let stdout = stdout();
    let mut writer = BufWriter::new(stdout.lock());
    let inputs = read_vec::<usize>();
    let (n, q) = (inputs[0], inputs[1]);

    let mut m = Vec::new();
    for _i in 0..n {
        let row = read_vec::<i32>();
        m.push(row);
    }

    let mut p1 = vec![vec![0; n+1]; n+1];
    let mut p2 = vec![vec![0; n+1]; n+1];
    let mut p3 = vec![vec![0; n+1]; n+1];
    for i in 0..n {
        for j in 0..n {
            let k = (i * n + j + 1) as i64;
            p1[i+1][j+1] = m[i][j] as i64 * k;
            p2[i+1][j+1] = m[i][j] as i64;
            p3[i+1][j+1] = m[i][j] as i64 * (i+1) as i64;
        }
    }

    prefix_sum(&mut p1, n);
    prefix_sum(&mut p2, n);
    prefix_sum(&mut p3, n);

    for _i in 0..q {
        let query = read_vec::<usize>();
        let (r1, c1, r2, c2) = (query[0], query[1], query[2], query[3]);

        let k = ((r1-1) * n + c1) as i64;
        let coef3 = (n - (c2 - c1 + 1)) as i64;
        let coef2 = k - coef3 * r1 as i64 - 1;
        let ans = sum(&p1, r1, c1, r2, c2)
            - coef2 * sum(&p2, r1, c1, r2, c2)
            - coef3 * sum(&p3, r1, c1, r2, c2);
        // println!("k={}, coef2={}, coef3={}", k, coef2, coef3);
        write!(writer, "{} ", ans).ok();
    }
    writeln!(writer).ok();
}

fn main() {
    let n = read_int::<i32>();
    for _t in 0..n {
        solve();
    }
}
