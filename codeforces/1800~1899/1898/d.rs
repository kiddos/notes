use std::io::{stdin, stdout, BufWriter, Write};
use std::str::FromStr;
use std::fmt::Debug;
use std::cmp::{min, max};

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

fn solve() {
    let stdout = stdout();
    let mut writer = BufWriter::new(stdout.lock());

    let n = read_int::<usize>();
    let a = read_vec::<i64>();
    let b = read_vec::<i64>();
    let mut base: i64 = 0;
    for i in 0..n {
        base += (a[i] - b[i]).abs();
    }

    let mut p = Vec::new();
    for i in 0..n {
        let l = min(a[i], b[i]);
        let r = max(a[i], b[i]);
        p.push((l, r, i));
    }
    p.sort();

    let mut ans = base;
    let mut left: (i64, i64, usize) = p[0].clone();
    for i in 1..n {
        if left.1 < p[i].0 {
            let i1 = p[i].2;
            let i2 = left.2;
            ans = max(ans, base - (a[i1] - b[i1]).abs() - (a[i2] - b[i2]).abs() +
                (a[i1] - b[i2]).abs() + (a[i2] - b[i1]).abs());
        }
        if p[i].1 < left.1 {
            left = p[i].clone();
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
