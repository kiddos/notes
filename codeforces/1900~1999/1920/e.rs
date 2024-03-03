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
    let inputs = read_vec::<usize>();
    let n = inputs[0];
    let k = inputs[1];

    let k_mod = 998244353;
    let mut dp: Vec<Vec<i64>> = vec![vec![0; k+1]; n+1];
    for last in 1..=k {
        dp[0][last] = 1; 
    }

    for sum in 1..=n {
        for last in 1..=k {
            let to = min(sum / last, k - last + 1);
            for p in 1..=to {
                dp[sum][last] += dp[sum - p * last][p];
                dp[sum][last] %= k_mod;
            }
        }
    }

    let mut ans: i64 = 0;
    for last in 0..=k {
        ans += dp[n][last];
        ans %= k_mod;
    }
    writeln!(writer, "{}", ans).ok();
}

fn main() {
    let n = read_int::<i32>();
    for _t in 0..n {
        solve();
    }
}
