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

const MOD: i32 = 998244353;

fn solve() {
    let stdout = stdout();
    let mut writer = BufWriter::new(stdout.lock());

    let n = read_int::<usize>();
    let a = read_vec::<usize>();
    let max_a = *a.iter().max().unwrap() as usize;

    let mut divs = vec![Vec::new(); max_a + 1];
    let mut c = vec![1; max_a + 1];
    for i in 2..=max_a {
        for j in (i..=max_a).step_by(i) {
            divs[j].push(i);
            if i != j {
                c[j] -= c[i];
            }
        }
    }

    let mut dp = vec![0; n];
    let mut count = vec![0; max_a + 1];
    dp[0] = 1;
    for &d in divs[a[0]].iter() {
        count[d] = 1;
    }

    for i in 1..n {
        for &d in divs[a[i]].iter() {
            dp[i] += (c[d] * count[d]) % MOD;
            dp[i] %= MOD;
        }

        for &d in divs[a[i]].iter() {
            count[d] += dp[i];
            count[d] %= MOD;
        }
    }
    writeln!(writer, "{}", dp[n-1]).ok();
}

fn main() {
    solve();
}
