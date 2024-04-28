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

const MAX_P: usize = 200;

fn precompute() -> Vec<Vec<Vec<i32>>> {
    let mut dp = vec![vec![vec![0; MAX_P+1]; MAX_P+1]; MAX_P+1];
    for a in 0..=MAX_P {
        for b in 0..=MAX_P {
            for c in 0..=MAX_P {
                let mut x = 0;
                if a % 2 == 1 {
                    x ^= 1;
                }
                if b % 2 == 1 {
                    x ^= 2;
                }
                if c % 2 == 1 {
                    x ^= 3;
                }

                if a == 0 && b == 0 && c == 0 {
                    continue;
                }

                let add = if x == 0 { 1 } else { 0 };
                dp[a][b][c] = add;
                if a > 0 {
                    dp[a][b][c] = dp[a][b][c].max(dp[a-1][b][c] + add);
                }
                if b > 0 {
                    dp[a][b][c] = dp[a][b][c].max(dp[a][b-1][c] + add);
                }
                if c > 0 {
                    dp[a][b][c] = dp[a][b][c].max(dp[a][b][c-1] + add);
                }
            }
        }
    }

    dp
}

fn solve(dp: &Vec<Vec<Vec<i32>>>) {
    let stdout = stdout();
    let mut writer = BufWriter::new(stdout.lock());
    let p = read_vec::<usize>();

    let ans = dp[p[0]][p[1]][p[2]] + (p[3] / 2) as i32;
    writeln!(writer, "{}", ans).ok();
}

fn main() {
    let n = read_int::<i32>();
    let dp = precompute();
    for _t in 0..n {
        solve(&dp);
    }
}
