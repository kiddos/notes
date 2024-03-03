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

fn solve() {
    let stdout = stdout();
    let mut writer = BufWriter::new(stdout.lock());

    let n = read_int::<usize>();
    let a = read_vec::<i32>();
    let max_val = *a.iter().max().unwrap() as usize;
    let mut counts: Vec<i64> = vec![0; max_val+1];
    for i in 0..n {
        counts[a[i] as usize] += 1;
    }

    let mut dp = vec![0; max_val+1];
    for g in (1..=max_val).rev() {
        let mut total: i64 = 0;
        let mut x = g;
        while x <= max_val {
            total += counts[x];
            x += g;
        }
        dp[g] = total * (total - 1) / 2;
    }
    for g in (1..=max_val).rev() {
        for j in (g*2..=max_val).step_by(g) {
            dp[g] -= dp[j];
        }
    }

    let mut cannot_use: Vec<bool> = vec![false; max_val+1];
    for g in 1..=max_val {
        if counts[g] > 0 {
            for j in (g..=max_val).step_by(g) {
                cannot_use[j] = true;
            }
        }
    }

    let mut ans: i64 = 0;
    for g in 1..=max_val {
        if !cannot_use[g] {
            ans += dp[g];
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
