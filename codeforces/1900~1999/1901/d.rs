use std::io::{stdin, stdout, BufWriter, Write};
use std::str::FromStr;
use std::fmt::Debug;
use std::cmp::{max, min};

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
    let mut a = read_vec::<i64>();
    a.insert(0, 0);

    let mut prefix = vec![0; n+2];
    let mut suffix = vec![0; n+2];
    for i in 1..=n {
        prefix[i] = max(prefix[i-1], a[i] + (n-i) as i64);
    }
    for i in (1..=n).rev() {
        suffix[i] = max(suffix[i+1], a[i] + (i-1) as i64);
    }
    let mut ans = i64::MAX;
    for i in 1..=n {
        let start = max(max(suffix[i+1], prefix[i-1]), a[i]);
        ans = min(ans, start);
    }
    writeln!(writer, "{}", ans).ok();
}

fn main() {
    solve();
}
