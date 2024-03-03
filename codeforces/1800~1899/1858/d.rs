use std::io::{stdin, stdout, BufWriter, Write};
use std::str::FromStr;
use std::fmt::Debug;
use std::cmp::*;

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

fn read_str() -> String {
    let mut s = String::new();
    stdin().read_line(&mut s).unwrap();
    s.trim().to_string()
}

fn solve() {
    let stdout = stdout();
    let mut writer = BufWriter::new(stdout.lock());
    let inputs = read_vec::<usize>();
    let n = inputs[0];
    let k = inputs[1];
    let s = read_str();
    let s = s.as_bytes();

    let mut prefix: Vec<Vec<i32>> = vec![vec![0; k+1]; n];
    for i in 0..n {
        let c = s[i] - b'0';
        for j in 0..=k {
            if c == 0 {
                if i > 0 {
                    prefix[i][j] = prefix[i-1][j] + 1;
                } else {
                    prefix[i][j] = 1;
                }
            } else {
                if j > 0 {
                    if i > 0 {
                        prefix[i][j] = prefix[i-1][j-1] + 1;
                    } else {
                        prefix[i][j] = 1;
                    }
                }
            }
        }
    }

    for i in 0..n {
        for j in 0..=k {
            if i > 0 {
                prefix[i][j] = max(prefix[i][j], prefix[i-1][j]);
            }
            if j > 0 {
                prefix[i][j] = max(prefix[i][j], prefix[i][j-1]);
            }
        }
    }

    let mut suffix: Vec<Vec<i32>> = vec![vec![0; k+1]; n];
    for i in (0..n).rev() {
        let c = s[i] - b'0';
        for j in 0..=k {
            if c == 0 {
                if i+1 < n {
                    suffix[i][j] = suffix[i+1][j] + 1;
                } else {
                    suffix[i][j] = 1;
                }
            } else {
                if j > 0 {
                    if i+1 < n {
                        suffix[i][j] = suffix[i+1][j-1] + 1;
                    } else {
                        suffix[i][j] = 1;
                    }
                }
            }
        }
    }

    for i in (0..n).rev() {
        for j in 0..=k {
            if i+1 < n {
                suffix[i][j] = max(suffix[i][j], suffix[i+1][j]);
            }
            if j > 0 {
                suffix[i][j] = max(suffix[i][j], suffix[i][j-1]);
            }
        }
    }

    let mut dp = vec![-1; n+1];
    dp[prefix[n-1][k] as usize] = max(dp[prefix[n-1][k] as usize], prefix[n-1][k]);
    for l in 0..n {
        let mut require = 0;
        for r in l..n {
            if s[r] == b'0' {
                require += 1;
            }
            if require > k {
                break;
            }

            let mut zeros = 0;
            if l > 0 {
                zeros = max(zeros, prefix[l-1][k-require]);
            }
            if r+1 < n {
                zeros = max(zeros, suffix[r+1][k-require]);
            }
            let ones = (r - l + 1) as i32;
            let total = zeros + ones;
            dp[total as usize] = max(dp[total as usize], zeros);
        }
    }

    let mut ans = vec![0; n+1];
    for a in 1..=n {
        for len in 0..=n {
            let l0 = dp[len];
            if l0 >= 0 {
                let l1 = len as i32 - l0;
                ans[a] = max(ans[a], l0 * a as i32 + l1);
            }
        }
    }

    for i in 1..=n {
        write!(writer, "{} ", ans[i]).ok();
    }
    writeln!(writer).ok();
}

fn main() {
    let n = read_int::<i32>();
    for _t in 0..n {
        solve();
    }
}
