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

fn gcd(a: i64, b: i64) -> i64 {
    if a == 0 {
        return b;
    }
    gcd(b % a, a)
}

fn solve() {
    let stdout = stdout();
    let mut writer = BufWriter::new(stdout.lock());

    let inputs = read_vec::<i64>();
    let mut n = inputs[0];
    let m = inputs[1];
    n %= m;

    let g = gcd(n, m);
    if m % g != 0 {
        writeln!(writer, "-1").ok();
        return;
    }

    let p = m / g;
    if i64::count_ones(p) != 1 {
        writeln!(writer, "-1").ok();
        return;
    }

    let q = n / g;
    let bits = i64::count_ones(q) as i64;
    let ans = bits * m - n;
    writeln!(writer, "{}", ans).ok();
}

fn main() {
    let n = read_int::<i32>();
    for _t in 0..n {
        solve();
    }
}
