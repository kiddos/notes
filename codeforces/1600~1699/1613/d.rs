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

const MOD: i64 = 998244353;

fn power(mut x: i64, mut n: i64) -> i64 {
    let mut ans = 1;
    while n > 0 {
        if n % 2 == 1 {
            ans *= x;
            ans %= MOD;
        }

        n >>= 1;
        x = x * x;
        x %= MOD;
    }
    ans
}

fn solve() {
    let stdout = stdout();
    let mut writer = BufWriter::new(stdout.lock());
    let n = read_int::<usize>();
    let a = read_vec::<usize>();

    let mut counts: Vec<i64> = vec![0; n+1];
    for i in 0..n {
        counts[a[i]] += 1;
    }

    let mut ans: i64 = 0;
    let mut dp = vec![0; n+1];
    let mut zero_count = 0;
    for i in 0..n {
        counts[a[i]] -= 1;
        if a[i] == 0 {
            ans += power(2, counts[a[i]]);
            ans %= MOD;
        } else if a[i] == 1 {
            ans += power(2, counts[a[i]]);
            ans %= MOD;

            ans += dp[a[i]-1] * power(2, counts[a[i]]);
            ans %= MOD;
        } else {
            ans += dp[a[i]-1] * power(2, counts[a[i]]);
            ans %= MOD;

            ans += dp[a[i]-2] * power(2, counts[a[i]] + counts[a[i]-2]);
            ans %= MOD;
        }

        if a[i] == 0 {
            dp[a[i]] += power(2, zero_count);
            dp[a[i]] %= MOD;
            zero_count += 1;
        } else {
            dp[a[i]] = dp[a[i]-1] + dp[a[i]] * 2;
            dp[a[i]] %= MOD;
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
