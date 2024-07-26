use std::io::{stdin, stdout, BufWriter, Write};
use std::str::FromStr;
use std::fmt::Debug;

fn read_vec<T: FromStr>() -> Vec<T> where <T as FromStr>::Err: Debug {
    let mut s = String::new();
    stdin().read_line(&mut s).unwrap();
    if s.is_empty() {
        return Vec::new();
    }
    s.split(" ").map(|x| x.trim().parse().expect("invalid input")).collect()
}

const MOD: i32 = 998244353;

fn solve() {
    let stdout = stdout();
    let mut writer = BufWriter::new(stdout.lock());
    let inputs = read_vec::<usize>();
    let n = inputs[0];
    let k = inputs[1];


    let mut dp = vec![vec![0; k+1]; n+1];
    let mut p = vec![0; k+1];
    dp[0][0] = 1;
    p[0] = 1;
    for i in 0..n {
        for j in 0..=k {
            dp[i+1][(j+1).min(k)] += p[j];
            dp[i+1][(j+1).min(k)] %= MOD;

            if i >= 2 && i < n-1 {
                dp[i+1][(j+1).min(k)] -= dp[i-1][j];
                dp[i+1][(j+1).min(k)] %= MOD;
                dp[i+1][(j+1).min(k)] += MOD;
                dp[i+1][(j+1).min(k)] %= MOD;
            }

            p[j] += dp[i+1][j];
            p[j] %= MOD;
        }
    }

    writeln!(writer, "{}", dp[n][k]).ok();
}

fn main() {
    solve();
}
