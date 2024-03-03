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
    let n = read_int::<i32>();
    let a = read_vec::<i32>();

    let inf = 1000000;
    let mut dp = vec![vec![inf; (n+1) as usize]; (n+1) as usize];
    dp[0][0] = 0;

    for i in 0..(n as usize) {
        let mut dp2 = vec![vec![inf; (n+1) as usize]; (n+1) as usize];
        for l in 0..n {
            for r in 0..=n {
                let d = dp[l as usize][r as usize];
                let mut l2 = (if l > 0 { l+1 } else if r == 0 { 1 } else { 0 }) as usize;
                let mut r2 = max(r-1, 0) as usize;
                dp2[l2][r2] = min(dp2[l2][r2], d);

                l2 = (if l > 0 { l+1 } else { 0 }) as usize;
                if a[i] as usize >= l2 {
                    l2 = 0;
                }
                dp2[l2][r2] = min(dp2[l2][r2], d+1);

                l2 = (if l > 0 { l+1 } else { 0 }) as usize;
                r2 = max(r-1, a[i]-1) as usize;
                dp2[l2][r2] = min(dp2[l2][r2], d+1);
            }
        }

        dp = dp2;
    }

    let mut ans = inf;
    for i in 0..=(n as usize) {
        ans = min(ans, dp[0][i]);
    }

    writeln!(writer, "{}", ans).ok();
}

fn main() {
    let n = read_int::<i32>();
    for _t in 0..n {
        solve();
    }
}
