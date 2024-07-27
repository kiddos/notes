use std::io::{stdin, stdout, BufWriter, Write};
use std::str::FromStr;
use std::fmt::Debug;
use std::cmp::Ordering;

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

fn solve() {
    let stdout = stdout();
    let mut writer = BufWriter::new(stdout.lock());
    let inputs = read_vec::<i64>();
    let n = inputs[0] as usize;
    let x = inputs[1];
    let a = read_vec::<i64>();

    let mut p = vec![0];
    for i in 0..n {
        let size = p.len();
        p.push(p[size-1] + a[i]);
    }

    let mut dp = vec![0; n+2];
    for i in (0..n).rev() {
        let sum = p[i] + x;
        let result = p.binary_search_by(|y| {
            match y.cmp(&sum) {
                Ordering::Equal => Ordering::Less,
                ord => ord,
            }
        });

        let mut handle = |j: usize| {
            dp[i] = dp[j] + (j - i - 1) as i64;
        };

        match result {
            Ok(j) => handle(j),
            Err(j) => handle(j),
        }
    }

    let mut ans = 0;
    for i in 0..n {
        ans += dp[i];
    }

    writeln!(writer, "{}", ans).ok();
}

fn main() {
    let n = read_int::<i32>();
    for _t in 0..n {
        solve();
    }
}
