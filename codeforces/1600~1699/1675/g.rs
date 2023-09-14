use std::io::{stdin, stdout, BufWriter, Write};
use std::str::FromStr;
use std::fmt::Debug;
use std::cmp::min;

fn read_vec<T: FromStr>() -> Vec<T> where <T as FromStr>::Err: Debug {
    let mut s = String::new();
    stdin().read_line(&mut s).unwrap();
    s.split(" ").map(|x| x.trim().parse().expect("invalid input")).collect()
}

fn solve() {
    let stdout = stdout();
    let mut writer = BufWriter::new(stdout.lock());

    let inputs = read_vec::<i32>();
    let n = inputs[0] as usize;
    let m = inputs[1];

    let mut a: Vec<i32> = read_vec::<i32>().into_iter().rev().collect();
    a.insert(0, 0);
    let p = a.iter().scan(0, |sum, i| {
        *sum += i;
        Some(*sum)
    }).collect::<Vec<_>>();

    const INF: i32 = 100000000;
    let mut dp: Vec<Vec<Vec<i32>>> = vec![vec![vec![INF; (m+1) as usize]; (m+1) as usize]; n+1];
    dp[0][0][0] = 0;
    for i in 1..=n {
        for sum in 0..=m {
            let mut min_val = INF;
            for last in 0..=m {
                if last + sum <= m {
                    min_val = min(min_val, dp[i-1][last as usize][sum as usize]);
                    dp[i][last as usize][(sum+last) as usize] = min(dp[i][last as usize][(sum+last) as usize], (p[i] - sum - last).abs() + min_val);
                }
            }
        }
    }

    let mut ans = INF;
    for last in 0..=m {
        ans = min(ans, dp[n][last as usize][m as usize]);
    }

    writeln!(writer, "{}", ans).ok();
}

fn main() {
    solve();
}
