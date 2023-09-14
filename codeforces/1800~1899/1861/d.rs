use std::io::{stdin, stdout, BufWriter, Write};
use std::str::FromStr;
use std::fmt::Debug;
use std::cmp::min;

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
    let a = read_vec::<i32>();
    let mut suffix: Vec<i32> = vec![0; n];
    for i in (0..(n-1)).rev() {
        suffix[i] = suffix[i+1];
        if a[i] >= a[i+1] {
            suffix[i] += 1;
        }
    }
    let mut prefix: Vec<i32> = vec![1; n];
    for i in 1..n {
        prefix[i] = prefix[i-1];
        if a[i] >= a[i-1] {
            prefix[i] += 1;
        }
    }

    let mut ans = min(prefix[n-1], suffix[0]);
    for i in 1..n {
        let op = prefix[i-1] + suffix[i];
        ans = min(ans, op);
    }

    writeln!(writer, "{}", ans).ok();
}

fn main() {
    let n = read_int::<i32>();
    for _t in 0..n {
        solve();
    }
}
