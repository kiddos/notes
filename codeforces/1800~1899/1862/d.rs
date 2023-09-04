use std::io::{stdin, stdout, BufWriter, Write};
use std::str::FromStr;
use std::fmt::Debug;

fn read_int<T: FromStr>() -> T where <T as FromStr>::Err: Debug {
    let mut s = String::new();
    stdin().read_line(&mut s).unwrap();
    s.trim().parse::<T>().expect("invalid input")
}

fn find_balls(n: i64) -> i64 {
    let mut l = 2;
    let mut r = 2000000000;
    let mut ans = l;
    while l <= r {
        let mid = l + (r-l) / 2;
        if mid * (mid-1) / 2 <= n {
            ans = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    ans
}

fn solve() {
    let stdout = stdout();
    let mut writer = BufWriter::new(stdout.lock());

    let n = read_int::<i64>();

    if n == 2 {
        writeln!(writer, "3").ok();
        return;
    }

    let balls = find_balls(n);
    let types = balls * (balls - 1) / 2;
    let num = n / types;
    let ans = num * balls + (n % types);

    writeln!(writer, "{}", ans).ok();
}

fn main() {
    let n = read_int::<i32>();
    for _t in 0..n {
        solve();
    }
}
